/*
 * Copyright 2019 Rafael Agundo
 *
 * This file is part of dwarfexplorer plugin for DFHack
 * The code is based on Clement Vuchener qtlabors plugin for DFHack
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "node.h"
#include "offsets_cache.h"
#include <Console.h>
#include <Core.h>
#include <DataDefs.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteClient.h>
#include <RemoteServer.h>
#include <VersionInfo.h>
#include <chrono>
#include <cstdint>
#include <tinythread.h>

#include "DataDefs.h"
#include <df/global_objects.h>

#include "MainWindow.h"
#include "QHexView/document/buffer/qmemorybuffer.h"
#include "QtModel/df_proxy_model.h"
#include "dfstructure_window.h"
#include "hexviewer_window.h"
#include "ui_MainWindow.h"
#include "ui_dfstructure_window.h"

#include <Core.h>

#include "EventProxy.h"
#include <QDirModel>
#include <QSettings>

#include <QDebug>

#include <df/building.h>
#include <modules/Gui.h>
#include <modules/World.h>

static constexpr struct in_place_t
{
} in_place;

extern void        fill_globals(rdf::Node* p_node_parent);
extern std::string to_hex(uint64_t p_dec);

//
//---------------------------------------------------------------------------------------
//
MainWindow::MainWindow(std::shared_ptr<EventProxy>&& proxy, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), event_proxy(std::move(proxy)), m_core_suspender(nullptr), m_suspended(false)
{
    ui->setupUi(this);

    //    connect(ui->treeView, &QTreeView::expanded,
    //            this, &MainWindow::updateUnitModel);

    //    connect(ui->filter_edit, &QLineEdit::textChanged,
    //            this, &MainWindow::on_filter_textChanged);

    setWindowTitle("DwarfExplorer - df.global");

    //    connect(event_proxy.get(), &EventProxy::mapLoaded,
    //            this, &MainWindow::updateUnitModel);
    //    connect(event_proxy.get(), &EventProxy::mapUnloaded,
    //            this, &MainWindow::clearUnitModel);
    //    connect(event_proxy.get(), &EventProxy::embarkScreenOpened,
    //            this, &MainWindow::updateUnitModel);
    //    connect(event_proxy.get(), &EventProxy::embarkScreenClosed,
    //            this, &MainWindow::updateUnitModel);
    connect(ui->actionLocate_in_fortress, SIGNAL(triggered()), this, SLOT(on_actionLocate_in_fortress()));
    connect(ui->actionLocate_building_in_fortress, SIGNAL(triggered()), this, SLOT(on_actionLocate_building_in_fortress()));
}

//
//---------------------------------------------------------------------------------------
//
MainWindow::~MainWindow()
{
    if (m_core_suspender)
    {
        m_core_suspender->unlock();
        delete m_core_suspender;
    }
}

//
//---------------------------------------------------------------------------------------
//
void MainWindow::on_suspend_action_triggered()
{
    if (m_core_suspender == nullptr)
        m_core_suspender = new DFHack::CoreSuspender;
    else
        m_core_suspender->lock();

    m_suspended = true;

    ui->stackedWidget->setCurrentIndex(1);
    ui->suspend_action->setEnabled(false);
    ui->resume_action->setEnabled(true);

    if (m_model == nullptr)
    {
        // Model
        std::unique_ptr<DF_Model> ptr_model(new DF_Model(this));
        m_model = std::move(ptr_model);

        // ProxyModel for filtering and sorting
        //std::unique_ptr<QSortFilterProxyModel> ptr_proxy_model(new QSortFilterProxyModel(this));
        //m_proxy_model = std::move(ptr_proxy_model);
        //m_proxy_model->setSourceModel(m_model.get());
        //m_proxy_model->setRecursiveFilteringEnabled(true);

        auto node    = new rdf::NodeRoot;
        node->m_path = "df.global";
        fill_globals(node);
        m_model->set_root(node);
        ui->treeView->setModel(m_model.get());
    }
    else
    {
        auto new_node    = new rdf::NodeRoot;
        new_node->m_path = "df.global";
        fill_globals(new_node);
        m_model->reset(new_node);
    }
}

//
//---------------------------------------------------------------------------------------
//
void MainWindow::on_resume_action_triggered()
{
    //    for (DFStructure_Window* child_window: m_child_window_list)
    //        if (child_window != nullptr)
    //            child_window->set_outdated();
    emit resumed_signal();

    ui->stackedWidget->setCurrentIndex(0);
    ui->resume_action->setEnabled(false);
    ui->suspend_action->setEnabled(true);
    if (m_core_suspender != nullptr)
    {
        m_core_suspender->unlock();
        delete m_core_suspender;
        m_core_suspender = nullptr;
    }
    m_suspended = false;
}

//
//---------------------------------------------------------------------------------------
//
void MainWindow::on_treeView_expanded(const QModelIndex& p_index)
{
    using namespace rdf;
    this->setCursor(Qt::WaitCursor);

    auto      l_model        = ui->treeView->model();
    DF_Model* l_global_model = static_cast<DF_Model*>(l_model);
    NodeBase* l_node_base    = l_global_model->nodeFromIndex(p_index);
    Node*     l_node         = dynamic_cast<Node*>(l_node_base);
    if (l_node != nullptr)
        if ((l_node->m_children.size() == 0) ||
            (l_node->m_node_type == rdf::NodeType::Vector) ||
            (l_node->m_node_type == rdf::NodeType::Array) ||
            (l_node->m_node_type == rdf::NodeType::Pointer))
            l_global_model->insert_child_nodes(l_node_base, p_index);
    this->setCursor(Qt::ArrowCursor);
}

//
//---------------------------------------------------------------------------------------
//
void MainWindow::on_actionOpen_in_new_window_triggered()
{
    if (!m_suspended)
        return;

    using namespace rdf;

    // Create the child window
    DFStructure_Window* new_window = new DFStructure_Window(this);

    // Get the selected node index
    QTreeView*      treeview       = ui->treeView;
    QModelIndexList selected_nodes = treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the model
    DF_Model* model = dynamic_cast<DF_Model*>(treeview->model());

    // Get the selected node
    Node* node = dynamic_cast<Node*>(model->nodeFromIndex(selected_node));

    // Clone the node
    auto cloned_node = dynamic_cast<Node*>(node->clone());

    // Create the new model only for this subtree
    DF_Model* new_model = new DF_Model(new_window);

    // Create the root node for this subtree
    NodeRoot* n_root = new NodeRoot;
    // This is not "the real root"
    n_root->m_parent      = nullptr;
    std::string path_name = node->path();
    path_name.append(".");
    path_name.append(node->m_field_name);
    n_root->m_path       = path_name;
    n_root->m_field_name = node->m_field_name;
    n_root->m_rdf_type   = node->m_rdf_type;
    n_root->m_df_type    = node->m_df_type;
    n_root->m_node_type  = NodeType::Root;

    // Connect the root and the cloned node
    n_root->m_children.push_back(cloned_node);
    cloned_node->m_parent = n_root;

    // Set it in the model
    new_model->set_root(n_root);

    // Assign the model to the TreeView
    new_window->get_treeview()->setModel(new_model);

    // Set the window title to match the element to open
    std::string new_window_name = "Dwarf Explorer - ";
    new_window_name.append(n_root->m_path);

    // Add the window to the list of child windows
    //m_child_window_list.push_back(new_window);

    // Show the window
    new_window->setWindowTitle(QString::fromStdString(new_window_name));
    new_window->show();
}

//
//---------------------------------------------------------------------------------------
//
void MainWindow::on_actionOpen_in_hex_viewer_triggered()
{
    if (!m_suspended)
        return;

    // Get the selected node index
    QTreeView*      treeview       = ui->treeView;
    QModelIndexList selected_nodes = treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the model
    DF_Model* model = dynamic_cast<DF_Model*>(treeview->model());

    // Get the selected node
    rdf::NodeBase* node = dynamic_cast<rdf::NodeBase*>(model->nodeFromIndex(selected_node));

    uint64_t the_address = node->m_address;
    auto     the_data    = reinterpret_cast<char*>(node->m_address);
    auto     the_size    = std::min(std::size_t(4096), size_of_DF_Type(node->m_df_type));
    the_size             = std::max(std::size_t(4096), the_size);

    // Create the window and show it
    auto hexview = new QHexViewer_Window(this, the_address, the_data, the_size);
    hexview->show();
}

//
//---------------------------------------------------------------------------------------
//
void MainWindow::on_actionOpenPointer_in_hex_viewer_triggered()
{
    if (!m_suspended)
        return;

    // Get the selected node index
    QTreeView*      treeview       = ui->treeView;
    QModelIndexList selected_nodes = treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the model
    DF_Model* model = dynamic_cast<DF_Model*>(treeview->model());

    // Get the selected node
    rdf::NodeBase* node_base = model->nodeFromIndex(selected_node);

    uint64_t* pointer_address = reinterpret_cast<uint64_t*>(node_base->m_address);
    uint64_t  the_address     = *pointer_address;

    auto the_data = reinterpret_cast<char*>(the_address);
    auto the_size = std::min(std::size_t(4096), size_of_DF_Type(node_base->m_df_type));
    the_size      = std::max(std::size_t(4096), the_size);

    // Create the window and show it
    auto hexview = new QHexViewer_Window(this, the_address, the_data, the_size);
    hexview->show();
}

void MainWindow::on_filter_textChanged(const QString& arg1)
{
    //m_proxy_model->setFilterFixedString(arg1);
}

void MainWindow::on_actionLocate_in_fortress()
{
    if (!m_suspended)
        return;
    revealCoordInMap(ui->treeView);
}

void MainWindow::revealCoordInMap(QTreeView* p_treeview)
{
    using namespace rdf;
    QModelIndexList selected_nodes = p_treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the model
    DF_Model* model = dynamic_cast<DF_Model*>(p_treeview->model());

    // Get the selected node
    Node* node = dynamic_cast<Node*>(model->nodeFromIndex(selected_node));

    if (node->m_df_type == rdf::DF_Type::coord)
    {
        df::coord* l_coord = (df::coord*)(node->m_address);
        this->revealInMap(l_coord->x,
                          l_coord->y,
                          l_coord->z);
    }
}

void MainWindow::closeEvent(QCloseEvent* p_event)
{
    // Do the thing
    p_event->accept();
}

//void MainWindow::resumed_signal()
//{
//}

bool is_building_subtype(rdf::DF_Type p_df_type)
{
    using namespace rdf;

    switch (p_df_type)
    {
        case DF_Type::building:
        case DF_Type::building_actual:
        case DF_Type::building_stockpilest:
        case DF_Type::building_civzonest:
        case DF_Type::building_furnacest:
        case DF_Type::building_workshopst:
        case DF_Type::building_animaltrapst:
        case DF_Type::building_archerytargetst:
        case DF_Type::building_armorstandst:
        case DF_Type::building_bars_verticalst:
        case DF_Type::building_bars_floorst:
        case DF_Type::building_bedst:
        case DF_Type::building_bookcasest:
        case DF_Type::building_boxst:
        case DF_Type::building_bridgest:
        case DF_Type::building_cabinetst:
        case DF_Type::building_cagest:
        case DF_Type::building_chainst:
        case DF_Type::building_chairst:
        case DF_Type::building_coffinst:
        case DF_Type::building_constructionst:
        case DF_Type::building_display_furniturest:
        case DF_Type::building_doorst:
        case DF_Type::building_farmplotst:
        case DF_Type::building_floodgatest:
        case DF_Type::building_grate_floorst:
        case DF_Type::building_grate_wallst:
        case DF_Type::building_hatchst:
        case DF_Type::building_hivest:
        case DF_Type::building_instrumentst:
        case DF_Type::building_nestst:
        case DF_Type::building_nest_boxst:
        case DF_Type::building_roadst:
        case DF_Type::building_road_dirtst:
        case DF_Type::building_road_pavedst:
        case DF_Type::building_shopst:
        case DF_Type::building_siegeenginest:
        case DF_Type::building_slabst:
        case DF_Type::building_statuest:
        case DF_Type::building_supportst:
        case DF_Type::building_tablest:
        case DF_Type::building_traction_benchst:
        case DF_Type::building_tradedepotst:
        case DF_Type::building_trapst:
        case DF_Type::building_wagonst:
        case DF_Type::building_weaponst:
        case DF_Type::building_weaponrackst:
        case DF_Type::building_wellst:
        case DF_Type::building_windowst:
        case DF_Type::building_window_glassst:
        case DF_Type::building_window_gemst:
        case DF_Type::building_axle_horizontalst:
        case DF_Type::building_axle_verticalst:
        case DF_Type::building_gear_assemblyst:
        case DF_Type::building_windmillst:
        case DF_Type::building_water_wheelst:
        case DF_Type::building_screw_pumpst:
        case DF_Type::building_rollersst:
            return true;
        default:
            break;
    }
    return false;
}

void MainWindow::on_actionLocate_building_in_fortress()
{
    if (!m_suspended)
        return;

    // Zoom the DF window if the selected node in the tree is a building.
    // If not, do nothing
    revealBuildingInMap(ui->treeView);
}

void MainWindow::revealBuildingInMap(QTreeView* p_treeview)
{
    using namespace rdf;

    // Get the model
    DF_Model* model = dynamic_cast<DF_Model*>(p_treeview->model());

    QModelIndexList selected_nodes = p_treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the selected node
    Node* node = dynamic_cast<Node*>(model->nodeFromIndex(selected_node));

    if (is_building_subtype(node->m_df_type))
    {
        df::building* l_building = nullptr;
        if (node->m_address != 0)
        {
            if (node->m_rdf_type == rdf::RDF_Type::Pointer)
            {
                uint64_t* l_ptr       = (uint64_t*)(node->m_address);
                uint64_t  l_ptr_value = *l_ptr;
                void*     l_void      = (void*)(l_ptr_value);
                l_building            = static_cast<df::building*>(l_void);
            }
            else
            {
                void* l_void = (void*)(node->m_address);
                l_building   = static_cast<df::building*>(l_void);
            }
            if (l_building)
            {
                revealInMap(l_building->centerx,
                            l_building->centery,
                            l_building->z);
            }
        }
    }
}

void MainWindow::revealInMap(int32_t p_x, int32_t p_y, int32_t p_z)
{
    if ((p_x != -3000) && (p_y != -3000) && (p_z != -3000))
    {
        DFHack::World::SetPauseState(true);
        m_core_suspender->unlock();

        // Center window and cursor
        df::coord l_coord(p_x,
                          p_y,
                          p_z);
        DFHack::Gui::revealInDwarfmodeMap(l_coord, true);

        DFHack::Gui::setCursorCoords(p_x, p_y, p_z);
        tthread::this_thread::sleep_for(tthread::chrono::milliseconds(100));
        m_core_suspender->lock();
    }
}

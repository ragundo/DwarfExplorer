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
#include <cstdint>

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

//#include "df_all.h"
#include <df/building.h>
#include <modules/Gui.h>

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

    using namespace rdf;

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

    if (node->m_df_type == rdf::DF_Type::coord)
    {
        df::coord* l_coord = (df::coord*)(node->m_address);
        if (l_coord)
        {
            if ((l_coord->x != -3000) && (l_coord->y != -3000) && (l_coord->z != -3000))
            {
                // Center window and cursor
                DFHack::Gui::revealInDwarfmodeMap(*l_coord, true);

                DFHack::Gui::setCursorCoords(l_coord->x,
                                             l_coord->y,
                                             l_coord->z);
            }
        }
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

// TODO cambiar esto a switch
bool is_building_subtype(rdf::DF_Type p_df_type)
{
    using namespace rdf;

    if (p_df_type == DF_Type::building_stockpilest)
        return true;
    if (p_df_type == DF_Type::building_civzonest)
        return true;
    if (p_df_type == DF_Type::building_actual)
        return true;
    if (p_df_type == DF_Type::building_furnacest)
        return true;
    if (p_df_type == DF_Type::building_workshopst)
        return true;
    if (p_df_type == DF_Type::building_animaltrapst)
        return true;
    if (p_df_type == DF_Type::building_archerytargetst)
        return true;
    if (p_df_type == DF_Type::building_armorstandst)
        return true;
    if (p_df_type == DF_Type::building_bars_verticalst)
        return true;
    if (p_df_type == DF_Type::building_bars_floorst)
        return true;
    if (p_df_type == DF_Type::building_bedst)
        return true;
    if (p_df_type == DF_Type::building_bookcasest)
        return true;
    if (p_df_type == DF_Type::building_boxst)
        return true;
    if (p_df_type == DF_Type::building_bridgest)
        return true;
    if (p_df_type == DF_Type::building_cabinetst)
        return true;
    if (p_df_type == DF_Type::building_cagest)
        return true;
    if (p_df_type == DF_Type::building_chainst)
        return true;
    if (p_df_type == DF_Type::building_chairst)
        return true;
    if (p_df_type == DF_Type::building_coffinst)
        return true;
    if (p_df_type == DF_Type::building_constructionst)
        return true;
    if (p_df_type == DF_Type::building_display_furniturest)
        return true;
    if (p_df_type == DF_Type::building_doorst)
        return true;
    if (p_df_type == DF_Type::building_farmplotst)
        return true;
    if (p_df_type == DF_Type::building_floodgatest)
        return true;
    if (p_df_type == DF_Type::building_grate_floorst)
        return true;
    if (p_df_type == DF_Type::building_grate_wallst)
        return true;
    if (p_df_type == DF_Type::building_hatchst)
        return true;
    if (p_df_type == DF_Type::building_hivest)
        return true;
    if (p_df_type == DF_Type::building_instrumentst)
        return true;
    if (p_df_type == DF_Type::building_nestst)
        return true;
    if (p_df_type == DF_Type::building_nest_boxst)
        return true;
    if (p_df_type == DF_Type::building_roadst)
        return true;
    if (p_df_type == DF_Type::building_road_dirtst)
        return true;
    if (p_df_type == DF_Type::building_road_pavedst)
        return true;
    if (p_df_type == DF_Type::building_shopst)
        return true;
    if (p_df_type == DF_Type::building_siegeenginest)
        return true;
    if (p_df_type == DF_Type::building_slabst)
        return true;
    if (p_df_type == DF_Type::building_statuest)
        return true;
    if (p_df_type == DF_Type::building_supportst)
        return true;
    if (p_df_type == DF_Type::building_tablest)
        return true;
    if (p_df_type == DF_Type::building_traction_benchst)
        return true;
    if (p_df_type == DF_Type::building_tradedepotst)
        return true;
    if (p_df_type == DF_Type::building_trapst)
        return true;
    if (p_df_type == DF_Type::building_wagonst)
        return true;
    if (p_df_type == DF_Type::building_weaponst)
        return true;
    if (p_df_type == DF_Type::building_weaponrackst)
        return true;
    if (p_df_type == DF_Type::building_wellst)
        return true;
    if (p_df_type == DF_Type::building_windowst)
        return true;
    if (p_df_type == DF_Type::building_window_glassst)
        return true;
    if (p_df_type == DF_Type::building_window_gemst)
        return true;
    if (p_df_type == DF_Type::building_axle_horizontalst)
        return true;
    if (p_df_type == DF_Type::building_axle_verticalst)
        return true;
    if (p_df_type == DF_Type::building_gear_assemblyst)
        return true;
    if (p_df_type == DF_Type::building_windmillst)
        return true;
    if (p_df_type == DF_Type::building_water_wheelst)
        return true;
    if (p_df_type == DF_Type::building_screw_pumpst)
        return true;
    if (p_df_type == DF_Type::building_rollersst)
        return true;

    return false;
}

void MainWindow::on_actionLocate_building_in_fortress()
{
    if (!m_suspended)
        return;

    using namespace rdf;

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
                df::coord l_building_position;
                l_building_position.x = l_building->centerx;
                l_building_position.y = l_building->centery;
                l_building_position.z = l_building->z;

                // Center window and cursor
                DFHack::Gui::revealInDwarfmodeMap(l_building_position, true);

                DFHack::Gui::setCursorCoords(l_building_position.x,
                                             l_building_position.y,
                                             l_building_position.z);
            }
        }
    }
}

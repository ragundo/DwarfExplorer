/*
 * Copyright 2019 Clement Vuchener
 *
 * This file is part of qtlabors plugin for DFHack
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


#include <cstdint>
#include <DataDefs.h>
#include <Core.h>
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteServer.h>
#include <RemoteClient.h>
#include <VersionInfo.h>
#include "df_all.h"
#include "node.h"
#include "offsets_cache.h"




#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "dfstructure_window.h"
#include "ui_dfstructure_window.h"
#include "hexviewer_window.h"

#include <Core.h>

#include <QSettings>
#include <QDirModel>
#include "EventProxy.h"

#include <QDebug>



static constexpr struct in_place_t {} in_place;

extern void        fill_globals(rdf::Node* p_node_parent);
extern std::string to_hex(uint64_t p_dec);


MainWindow::MainWindow(std::shared_ptr<EventProxy> &&proxy, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , event_proxy(std::move(proxy))
{
    ui->setupUi(this);

    connect(ui->treeView, &QTreeView::expanded,
            this, &MainWindow::updateUnitModel);

    auto node = new rdf::NodeRoot;
    node->m_path = "df.global";

    fill_globals(node);

    model = new DF_Model(this);
    model->set_root(node);
    ui->treeView->setModel(model);

    setWindowTitle("DwarfExplorer - df.global");

//    connect(event_proxy.get(), &EventProxy::mapLoaded,
//            this, &MainWindow::updateUnitModel);
//    connect(event_proxy.get(), &EventProxy::mapUnloaded,
//            this, &MainWindow::clearUnitModel);
//    connect(event_proxy.get(), &EventProxy::embarkScreenOpened,
//            this, &MainWindow::updateUnitModel);
//    connect(event_proxy.get(), &EventProxy::embarkScreenClosed,
//            this, &MainWindow::updateUnitModel);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_suspend_action_triggered()
{
    //ui->suspend_action->setEnabled(false);
    //model.beginDataAccess();
    //ui->resume_action->setEnabled(true);
}

void MainWindow::on_resume_action_triggered()
{
    //ui->resume_action->setEnabled(false);
    //model.endDataAccess();
    //ui->suspend_action->setEnabled(true);
}

void MainWindow::updateUnitModel()
{

}

void MainWindow::clearUnitModel()
{
}


void MainWindow::on_treeView_expanded(const QModelIndex& p_index)
{
    using namespace rdf;
    this->setCursor(Qt::WaitCursor);

    auto l_model =  ui->treeView->model();
    DF_Model* l_global_model = static_cast<DF_Model*>(l_model);
    NodeBase* l_node_base = l_global_model->nodeFromIndex(p_index);
    Node* l_node = dynamic_cast<Node*>(l_node_base);
    if (l_node != nullptr)
        if ((l_node->m_children.size() == 0) ||
                (l_node->m_node_type == rdf::NodeType::Vector) ||
                (l_node->m_node_type == rdf::NodeType::Array) ||
                (l_node->m_node_type == rdf::NodeType::Pointer))
                    l_global_model->insert_child_nodes(l_node_base, p_index);
    this->setCursor(Qt::ArrowCursor);
}

void MainWindow::on_actionOpen_in_new_window_triggered()
{
    using namespace rdf;
    // Create the child window
    DFStructure_Window* l_new_window = new DFStructure_Window(this);

    // Get the selected node index
    QTreeView* l_treeview = ui->treeView;
    QModelIndexList l_selected_nodes = l_treeview->selectionModel()->selectedIndexes();
    if (l_selected_nodes.size() == 0)
        return;
    QModelIndex l_selected_node = l_selected_nodes.first();

    // Get the model
    DF_Model* l_model = dynamic_cast<DF_Model*>(l_treeview->model());

    // Get the selected node
    Node* l_node = dynamic_cast<Node*>(l_model->nodeFromIndex(l_selected_node));

    // Clone the node
    auto l_cloned_node = dynamic_cast<Node*>(l_node->clone());

    // Create the new model only for this subtree
    DF_Model* l_new_model = new DF_Model(l_new_window);

    // Create the root node for this subtree
    NodeRoot* n_root         = new NodeRoot;
    // This is not "the real root"
    n_root->m_parent     = nullptr;
    std::string path_name = l_node->path();
    path_name.append(".");
    path_name.append(l_node->m_field_name);
    n_root->m_path      =  path_name;
    n_root->m_field_name = l_node->m_field_name;
    n_root->m_rdf_type = l_node->m_rdf_type;
    n_root->m_df_type = l_node->m_df_type;
    n_root->m_node_type = NodeType::Root;

    //l_cloned_node->m_field_name = n_root->m_path;

    // Connect the root and the cloned node
    n_root->m_children.append(l_cloned_node);
    l_cloned_node->m_parent = n_root;

    // Set it in the model
    l_new_model->set_root(n_root);

    // Assign the model to the TreeView
    l_new_window->get_treeview()->setModel(l_new_model);

    // Set the window title to match the element to open
    std::string new_window_name = "Dwarf Explorer - ";
    new_window_name.append(n_root->m_path);

    // Show the window
    l_new_window->setWindowTitle(QString::fromStdString(new_window_name));
    l_new_window->show();
}


void MainWindow::on_actionOpen_in_hex_viewer_triggered()
{
    // Get the selected node index
    QTreeView* treeview = ui->treeView;
    QModelIndexList selected_nodes = treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the model
    DF_Model* model = dynamic_cast<DF_Model*>(treeview->model());

    // Get the selected node
    rdf::Node* node = dynamic_cast<rdf::Node*>(model->nodeFromIndex(selected_node));

    auto the_data = reinterpret_cast<const char*>(node->m_address);
    QByteArray data(the_data, 1024);
    QHexViewer_Window* hex_window = new QHexViewer_Window(this);
    QHexView* hex_view = hex_window->get_hexview();
    hex_view->set_base_address(node->m_address);
    hex_view->setData(new QHexView::DataStorageArray(data));

    // window title
    auto the_number = QString::fromStdString(to_hex(node->m_address));
    hex_window->setWindowTitle("Memory viewer - " + the_number);
    hex_window->show();
}

void MainWindow::on_actionOpenPointer_in_hex_viewer_triggered()
{
    // Get the selected node index
    QTreeView* treeview = ui->treeView;
    QModelIndexList selected_nodes = treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the model
    DF_Model* model = dynamic_cast<DF_Model*>(treeview->model());

    // Get the selected node
    rdf::Node* node = dynamic_cast<rdf::Node*>(model->nodeFromIndex(selected_node));

    auto pointer_address = reinterpret_cast<uint64_t*>(node->m_address);
    auto item_address    = reinterpret_cast<uint64_t>(*pointer_address);

    auto the_data = reinterpret_cast<const char*>(item_address);
    QByteArray data(the_data, 1024);
    QHexViewer_Window* hex_window = new QHexViewer_Window(this);
    QHexView* hex_view = hex_window->get_hexview();
    hex_view->set_base_address(item_address);
    hex_view->setData(new QHexView::DataStorageArray(data));

    // Window tittle
    auto the_number = QString::fromStdString(to_hex(item_address));
    hex_window->setWindowTitle("Memory viewer - " + the_number);
    hex_window->show();
}
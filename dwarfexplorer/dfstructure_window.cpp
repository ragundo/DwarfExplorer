/*
 * Copyright 2019 Rafael Agundo
 *
 * This file is part of dearfexplorer plugin for DFHack
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

#include "dfstructure_window.h"
#include "ui_dfstructure_window.h"
#include "df_model.h"
#include "node.h"
#include "hexviewer_window.h"
#include "QHexView/document/buffer/qmemorybuffer.h"
#include "MainWindow.h"
#include <QDebug>

using namespace rdf;

extern void        fill_globals(rdf::Node* p_node_parent);
extern std::string to_hex(uint64_t p_dec);



//
//---------------------------------------------------------------------------------------
//
DFStructure_Window::DFStructure_Window(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::DFStructure_Window)
    , m_outdated(false)
{
    ui->setupUi(this);

    MainWindow *mw = dynamic_cast<MainWindow*>(parent);
    bool ok = QObject::connect(mw, &MainWindow::resumed_signal, this, &DFStructure_Window::on_MainWindow_resumed);
}


//
//---------------------------------------------------------------------------------------
//
DFStructure_Window::~DFStructure_Window()
{
    delete ui;
}


//
//---------------------------------------------------------------------------------------
//
QTreeView* DFStructure_Window::get_treeview()
{
    return ui->treeView;
}

//
//---------------------------------------------------------------------------------------
//
void DFStructure_Window::set_outdated()
{
    m_outdated = true;

    // Get the model
    QTreeView* treeview = ui->treeView;
    DF_Model* model = dynamic_cast<DF_Model*>(treeview->model());
    model->set_outdated();
}

//
//---------------------------------------------------------------------------------------
//
void DFStructure_Window::on_actionOpen_in_new_window_triggered()
{
    if (m_outdated)
        return;

    using namespace rdf;

    MainWindow* main_window = reinterpret_cast<MainWindow*>(parent());

    // Create the child window
    DFStructure_Window* new_window = new DFStructure_Window(main_window);

    // Add the window to the list of child windows
    //main_window->add_child_window(new_window);

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
    DF_Model* l_new_model = new DF_Model(new_window);

    // Create the root node for this subtree
    NodeRoot* n_root         = new NodeRoot;

    // This is not "the real root"
    std::string path_name = l_node->get_root_node()->m_path;
    path_name.append(".");
    path_name.append(l_node->m_field_name);
    n_root->m_parent     = nullptr;
    n_root->m_path       = path_name;
    n_root->m_field_name = l_node->m_field_name;
    n_root->m_rdf_type   = l_node->m_rdf_type;
    n_root->m_df_type    = l_node->m_df_type;
    n_root->m_node_type  = NodeType::Root;

    //l_cloned_node->m_field_name = n_root->m_path;

    // Connect the root and the cloned node
    n_root->m_children.push_back(l_cloned_node);
    l_cloned_node->m_parent = n_root;

    // Set it in the model
    l_new_model->set_root(n_root);

    // Assign the model to the TreeView
    new_window->get_treeview()->setModel(l_new_model);

    // Set the window title to match the element to open
    std::string l_new_window_name = "Dwarf Explorer - ";
    l_new_window_name.append(n_root->m_path);

    // Show the window
    new_window->setWindowTitle(QString::fromStdString(l_new_window_name));
    new_window->show();
}

//
//---------------------------------------------------------------------------------------
//
void DFStructure_Window::on_treeView_expanded(const QModelIndex &p_index)
{
    if (m_outdated)
        return;

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

//
//---------------------------------------------------------------------------------------
//
void DFStructure_Window::on_actionOpen_in_hex_viewer_triggered()
{
    if (m_outdated)
        return;

    // Get the selected node index
    QTreeView* treeview = ui->treeView;
    QModelIndexList selected_nodes = treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the model
    DF_Model* model = dynamic_cast<DF_Model*>(treeview->model());

    // Get the selected node
    rdf::NodeBase* node = dynamic_cast<rdf::NodeBase*>(model->nodeFromIndex(selected_node));

    uint64_t the_address = node->m_address;
    char*    the_data    = reinterpret_cast<char*>(node->m_address);
    std::size_t the_size = std::min(std::size_t(4096), size_of_DF_Type(node->m_df_type));
    the_size = std::max(std::size_t(4096), the_size);

    // Create the window and show it
    MainWindow *mw = dynamic_cast<MainWindow *>(parent());
    auto hexview = new QHexViewer_Window(mw, the_address, the_data, the_size);
    hexview->show();
}

//
//---------------------------------------------------------------------------------------
//
void DFStructure_Window::on_actionOpenPointer_in_hex_viewer_triggered()
{
    if (m_outdated)
        return;

    // Get the selected node index
    QTreeView *treeview = ui->treeView;
    QModelIndexList selected_nodes = treeview->selectionModel()->selectedIndexes();
    if (selected_nodes.size() == 0)
        return;
    QModelIndex selected_node = selected_nodes.first();

    // Get the model
    DF_Model *model = dynamic_cast<DF_Model *>(treeview->model());

    // Get the selected node
    rdf::NodeBase *node_base = model->nodeFromIndex(selected_node);

    // Get the address and the size of the data to be visualized
    uint64_t *pointer_address = reinterpret_cast<uint64_t *>(node_base->m_address);
    uint64_t the_address = *pointer_address;
    char *the_data = reinterpret_cast<char *>(the_address);
    std::size_t the_size = std::min(std::size_t(4096), size_of_DF_Type(node_base->m_df_type));
    the_size = std::max(std::size_t(4096), the_size);

    // Create the window and show it
    MainWindow* mw = dynamic_cast<MainWindow*>(parent());
    auto hexview = new QHexViewer_Window(mw, the_address, the_data, the_size);
    hexview->show();
}

void DFStructure_Window::closeEvent (QCloseEvent* p_event)
{
    // Do the thing
    p_event->accept();
}

void DFStructure_Window::on_MainWindow_resumed()
{
    QString new_name = "OUTDATED -";
    auto name = this->windowTitle();
    new_name.append(name);
    this->setWindowTitle(new_name);

    set_outdated();
}

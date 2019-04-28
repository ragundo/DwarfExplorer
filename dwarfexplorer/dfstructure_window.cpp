#include "dfstructure_window.h"
#include "ui_dfstructure_window.h"
#include "df_model.h"
#include "node.h"

using namespace rdf;

DFStructure_Window::DFStructure_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DFStructure_Window)
{
    ui->setupUi(this);
}

DFStructure_Window::~DFStructure_Window()
{
    delete ui;
}

QTreeView* DFStructure_Window::get_treeview()
{
    return ui->treeView;
}

void DFStructure_Window::on_actionOpen_in_new_Window_triggered()
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
    std::string path_name = l_node->get_root_node()->m_path;
    path_name.append(".");
    path_name.append(l_node->m_field_name);
    n_root->m_parent     = nullptr;
    n_root->m_path       = path_name;
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
    std::string l_new_window_name = "Dwarf Explorer - ";
    l_new_window_name.append(n_root->m_path);

    // Show the window
    l_new_window->setWindowTitle(QString::fromStdString(l_new_window_name));
    l_new_window->show();
}

void DFStructure_Window::on_treeView_expanded(const QModelIndex &p_index)
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

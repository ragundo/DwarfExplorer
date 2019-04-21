#include "node.h"

using namespace rdf;

std::string NodeBase::path()
{
    std::string result = "";
    QVector<NodeBase*> path;

    NodeBase* node_iterator = this;
         while (node_iterator->m_parent->m_node_type != NodeType::NodeRoot)
     {
         node_iterator = node_iterator->m_parent;
                 path.append(node_iterator);
         }

         result.append(dynamic_cast<NodeRoot*>(node_iterator->m_parent)->m_path);
         for (auto i = path.size() - 1; i >= 0; i--)
         {
                 result.append(".");
                 result.append(path[i]->node_path_name());
         }
         return result;

}


NodeRoot* NodeBase::get_root_node()
{
     NodeBase* iterator = this;
    while ((iterator != nullptr) && (!iterator->is_root_node()))
        iterator = iterator->m_parent;
    return dynamic_cast<NodeRoot*>(iterator);
}

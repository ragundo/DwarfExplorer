#include "node.h"

using namespace rdf;

std::string NodeBase::path()
{
    std::string result = "";
    std::vector<NodeBase*> path;

    NodeBase* node_iterator = this;
    while (node_iterator->m_parent->m_node_type != NodeType::Root)
    {
        node_iterator = node_iterator->m_parent;
        path.push_back(node_iterator);
    }

    result.append(dynamic_cast<NodeRoot*>(node_iterator->m_parent)->m_path);
    if (path.size() == 0)
    {
        result.append(".");
        result.append(this->node_path_name());
    }
    else
    {
        int i = path.size() - 1;
        while (i >= 0)
        {
            result.append(".");
            NodeBase* node = path[i--];
            if (node != nullptr)
                result.append(node->node_path_name());
        }
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

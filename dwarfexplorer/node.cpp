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

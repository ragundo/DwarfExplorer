/*
 * Copyright 2019 Rafael Agundo
 *
 * This file is part of dwarfexplorer plugin for DFHack
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

#include "../df_model.h"
#include "node.h"
#include <locale>
#include <cctype>

using namespace rdf;

extern unsigned short get_df_array_size(const NodeDFArray* p_node);
extern void           decode_addornements(std::string& p_addornments, std::string& p_result);

namespace
{
    bool is_vector(const NodeBase* l_node)
    {
        if (l_node->m_rdf_type == rdf::RDF_Type::Vector)
            return true;
        return false;
    }

    bool is_array(const NodeBase* l_node)
    {
        if (l_node->m_rdf_type == rdf::RDF_Type::Array)
            return true;
        return false;
    }

    bool is_pointer(const NodeBase* l_node)
    {
        if (l_node->m_rdf_type == rdf::RDF_Type::Pointer)
            return true;
        return false;
    }
}


std::string rec_array_type(std::string p_addornements)
{
    std::string result;
    if (p_addornements[0] == '*')
    {
        result.append("*");
        return result.append(rec_array_type(p_addornements.substr(1,512)));
    }
    if (p_addornements[0] == 'v')
    {
        result.append("Vector");
        return result.append(rec_array_type(p_addornements.substr(1,512)));
    }
    if (p_addornements[0] == '[')
    {
        std::size_t index = 1;
        while (std::isdigit(p_addornements[index++]));
        std::string array_size = p_addornements.substr(1, index-2);
        result.append("[").append(array_size).append("]");
        if (index >= p_addornements.size())
            return result;
        std::string rest = p_addornements.substr(index-1,512);
        return result.append(rec_array_type(rest));
    }
    return "";
}

std::string get_array_expresion(const NodeBase* p_node)
{
    std::string result       = "Array";
    auto        node_array   = dynamic_cast<const NodeArray*>(p_node);
    std::string addornements = node_array->m_addornements;
//    auto        size         = rec_array_type(addornements);
//    return result + size;
    decode_addornements(addornements, result);
    return result;
}

QString DF_Model::data_from_Structure(const NodeBase* p_node) const
{
    if (is_vector(p_node))
        return "Vector";

    if (is_array(p_node))
        return QString::fromStdString(get_array_expresion(p_node));

    if (p_node->m_node_type == NodeType::Void)
        return "Pointer";

    if (is_pointer(p_node))
        return "Pointer";

    if (p_node->m_rdf_type == rdf::RDF_Type::Compound)
        return "Compound";

    if (p_node->m_rdf_type == rdf::RDF_Type::DFLinkedList)
        return "Linked list";

    if (p_node->m_rdf_type == rdf::RDF_Type::Class)
        return "Class";

    if (p_node->m_rdf_type == rdf::RDF_Type::Struct)
        return "Struct";

    if (p_node->m_rdf_type == rdf::RDF_Type::AnonymousCompound)
        return "Anonymous Struct";

    if (p_node->m_rdf_type == rdf::RDF_Type::Enum)
        return "Enum";

    if (p_node->m_rdf_type == rdf::RDF_Type::Bitfield)
        return "Bitfield";

    if (p_node->m_rdf_type == rdf::RDF_Type::DFFlagArray)
        return "DFFlagArray";

    if (p_node->m_rdf_type == rdf::RDF_Type::Union)
        return "Union";

    if (p_node->m_rdf_type == rdf::RDF_Type::AnonymousUnion)
        return "Anonymous Union";

    if (is_string(p_node))
        return "String";

    if (p_node->m_rdf_type == rdf::RDF_Type::Padding)
        return "Padding";

    if (p_node->m_rdf_type == rdf::RDF_Type::Static_string)
        return "Static String";

    if (p_node->m_rdf_type == rdf::RDF_Type::DFArray)
    {
        const NodeDFArray* node_df_array = dynamic_cast<const NodeDFArray*>(p_node);
        QString result = "DFArray[";
        result.append(QString::number(get_df_array_size(node_df_array)));
        result.append("]");
        return result;
    }

    if (is_simple_type(p_node))
        return "";


    return  "Unknown";
}

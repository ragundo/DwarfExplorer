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

#include "../df_model.h"
#include <cctype>

using namespace rdf;


std::string& replace_string(std::string& s, const std::string& from, const std::string& to)
{
    if(!from.empty())
        for(size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
            s.replace(pos, from.size(), to);
    return s;
}


void decode_addornements(std::string& p_addornments, std::string& p_result)
{
    if (p_addornments.empty())
        return ;

    auto first_char = p_addornments[0];
    auto rest       = p_addornments.substr(1,5000);

    if (first_char == 'v')
    {
        p_result.append("Vector ");
    }
    else if (first_char == '*')
    {
        p_result.append("*");
    }
    else if (first_char == '[')
    {
        size_t iterator = 0;
        while ((iterator < rest.length()) && (std::isdigit(rest[iterator])))
            iterator++;
        std::string array_size = rest.substr(0, iterator);
        p_result.append("[").append(array_size).append("]");
        rest = rest.substr(array_size.length(), 500);
    }
    decode_addornements(rest, p_result);
}

QString DF_Model::data_from_Type(const NodeBase* p_node) const
{

    if (p_node->m_rdf_type == rdf::RDF_Type::AnonymousCompound)
        return "";

    if (p_node->m_rdf_type == rdf::RDF_Type::AnonymousUnion)
        return "";

    if (p_node->m_df_type == rdf::DF_Type::Padding)
        return "";

    if (p_node->m_df_type == rdf::DF_Type::Static_string)
        return "char*";

    if (p_node->m_df_type == rdf::DF_Type::Stl_string)
        return "std::string";

    // Get df_type translated to string
    std::string type = DF_Type_to_string(p_node->m_df_type);

    if (type.find("__") != std::string::npos)
        return QString::fromStdString(replace_string(type, "__", "::"));

    if (type == "Void")
       type = "void*";

    if (p_node->m_rdf_type == rdf::RDF_Type::Enum)
    {
        auto node_enum = dynamic_cast<const NodeEnum*>(p_node);
        return QString::fromStdString(node_enum->m_enum_type);
    }

    if (p_node->m_node_type == NodeType::Vector)
    {
        std::string raw_addornements;
        std::string addornements_decoded;

        auto node        = dynamic_cast<const NodeVector*>(p_node);
        raw_addornements = node->m_addornements;
        raw_addornements = raw_addornements.substr(1, 500);

        decode_addornements(raw_addornements, addornements_decoded);
        return QString::fromStdString(addornements_decoded.append(type));
    }

    if (p_node->m_node_type == NodeType::Pointer)
    {
        std::string raw_addornements;
        std::string addornements_decoded;

        auto node        = dynamic_cast<const NodePointer*>(p_node);
        raw_addornements = node->m_addornements;
        raw_addornements = raw_addornements.substr(1, 500);

        decode_addornements(raw_addornements, addornements_decoded);
        return QString::fromStdString(addornements_decoded.append(type));
    }

    return QString::fromStdString(type);
}

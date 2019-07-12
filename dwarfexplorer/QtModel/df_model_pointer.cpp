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

#include <algorithm>
#include <cctype>
#include <QPixmap>
#include <QListIterator>
#include "../df_model.h"
#include "node.h"

using namespace rdf;

extern void     fill_node(uint64_t p_df_structure, rdf::Node* p_node_parent);
extern void     fill_simple_entry(NodeBase* p_pve, Node* p_node, size_t p_size, uint64_t p_address, DF_Type p_df_type, RDF_Type p_rdf_type);
extern DF_Type  get_df_subtype(DF_Type p_base_type, uint64_t p_address);
extern RDF_Type df_2_rdf(DF_Type p_df_type);
extern void     fill_compound_vector_entry(Node* p_parent_node, uint64_t p_address, std::string p_field_name, RDF_Type p_rdf_type);

//
//------------------------------------------------------------------------------------//
//
bool DF_Model::insertRowsPointer(const QModelIndex& p_parent)
{
    auto node = dynamic_cast<NodePointer*>(nodeFromIndex(p_parent));

    if (node->m_df_type == rdf::DF_Type::Void)
        return false;

    if ((node->m_children.size() > 0) && (node->m_children[0]->m_node_type != NodeType::Dummy))
        return false;

    // Remove the dummy node if exists
    if ((node->m_children.size() == 1) && (node->m_children[0]->m_df_type == DF_Type::None))
    {
        beginRemoveRows(p_parent, 0, 1);
        node->m_children.erase(node->m_children.begin());
        endRemoveRows();
    }

    uint64_t* pointer_address = reinterpret_cast<uint64_t*>(node->m_address);
    uint64_t  item_address    = *pointer_address;

    if (node->m_addornements == "*")
    {
        switch(node->m_df_type)
        {
            case rdf::DF_Type::uint8_t:
            {
                auto n_pve = new NodeSimple<uint8_t>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(uint8_t), item_address, node->m_df_type, RDF_Type::uint8_t);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::uint16_t:
            {
                auto n_pve = new NodeSimple<uint16_t>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(uint16_t), item_address, node->m_df_type, RDF_Type::uint16_t);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::uint32_t:
            {
                auto n_pve = new NodeSimple<uint32_t>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(uint32_t), item_address, node->m_df_type, RDF_Type::uint32_t);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::uint64_t:
            {
                auto n_pve = new NodeSimple<uint64_t>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(uint64_t), item_address, node->m_df_type, RDF_Type::uint64_t);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::int8_t:
            {
                auto n_pve = new NodeSimple<int8_t>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(int8_t), item_address, node->m_df_type, RDF_Type::int8_t);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::int16_t:
            {
                auto n_pve = new NodeSimple<int16_t>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(int16_t), item_address, node->m_df_type, RDF_Type::int16_t);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::int32_t:
            {
                auto n_pve = new NodeSimple<int32_t>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(int32_t), item_address, node->m_df_type, RDF_Type::int32_t);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::int64_t:
            {
                auto n_pve = new NodeSimple<int64_t>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(int64_t), item_address, node->m_df_type, RDF_Type::int64_t);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::Long:
            {
                auto n_pve = new NodeSimple<long>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(long), item_address, node->m_df_type, RDF_Type::Long);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::S_float:
            {
                auto n_pve = new NodeSimple<float>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(float), item_address, node->m_df_type, RDF_Type::S_float);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::Bool:
            {
                auto n_pve = new NodeSimple<bool>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(bool), item_address, node->m_df_type, RDF_Type::Bool);
                endInsertRows();
                return true;
            }
            case rdf::DF_Type::Stl_string:
            {
                auto n_pve = new NodeSimple<std::string>;
                beginInsertRows(p_parent, 0, 1);
                fill_simple_entry(n_pve, node, sizeof(std::string), item_address, node->m_df_type, RDF_Type::Stl_string);
                endInsertRows();
                return true;
            }
            default:
                break;
        }

        // Check if it's a base class
        DF_Type real_df_type = get_df_subtype(node->m_df_type, item_address);
        if (real_df_type != DF_Type::None)
            node->m_df_type = real_df_type;

        // Check the type
        // We need to know if the DF_Type is a
        // DF structure enum or bitfield
        RDF_Type rdf_type = RDF_Type::Void;

        if (node->m_df_type != DF_Type::Void)
            rdf_type = df_2_rdf(node->m_df_type);


        if (rdf_type == RDF_Type::Enum)
        {
            beginInsertRows(p_parent, 0, 1);
            auto n_pve = new NodeEnum;

            if (node->m_enum_base == DF_Type::None)
            {
                fill_simple_entry(n_pve, node, size_of_DF_Type(node->m_df_type), item_address, node->m_df_type, rdf_type);
                n_pve->m_node_type = NodeType::Enum;
            }
            else
            {
                fill_simple_entry(n_pve, node, size_of_DF_Type(node->m_enum_base), item_address, node->m_df_type, rdf_type);
                n_pve->m_node_type = NodeType::Enum;
                n_pve->m_base_type = node->m_enum_base;
            }
            n_pve->m_enum_type  = DF_Type_to_string(node->m_df_type);
            n_pve->m_field_name = "N/A";
            endInsertRows();
            return true;
        }
        if (rdf_type == RDF_Type::Bitfield)
        {
            beginInsertRows(p_parent, 0, 1);
            auto n_pve = new NodeBitfield;
            fill_simple_entry(n_pve, node, size_of_DF_Type(node->m_df_type), item_address, node->m_df_type, rdf_type);
            n_pve->m_field_name = "N/A";
            n_pve->m_node_type  = NodeType::Bitfield;
            endInsertRows();
            return true;
        }

        std::string field_name = "N/A";
        switch (rdf_type)
        {
            case RDF_Type::Struct :
                beginInsertRows(p_parent, 0, 1);
                fill_compound_vector_entry(node, item_address, field_name, RDF_Type::Struct);
                endInsertRows();
                break;
            case RDF_Type::Compound :
                beginInsertRows(p_parent, 0, 1);
                fill_compound_vector_entry(node, item_address, field_name, RDF_Type::Compound);
                endInsertRows();
                break;
            case RDF_Type::Class:
                beginInsertRows(p_parent, 0, 1);
                fill_compound_vector_entry(node, item_address, field_name, RDF_Type::Class);
                endInsertRows();
                break;
            case RDF_Type::Union:
                beginInsertRows(p_parent, 0, 1);
                fill_compound_vector_entry(node, item_address, field_name, RDF_Type::Union);
                endInsertRows();
                break;
            default:
                break;
        }
        return true;
    }

    // Remove "*"
    std::string addornements = node->m_addornements;
    addornements             = addornements.substr(1, 512);
    if (addornements[0] == '*')
    {
        // Pointer to pointer
        beginInsertRows(p_parent, 0, 1);
        NodePointer* n_ptr    = new NodePointer;
        n_ptr->m_df_type      = node->m_df_type;
        n_ptr->m_rdf_type     = RDF_Type::Pointer;
        n_ptr->m_addornements = addornements;
        n_ptr->m_address      = item_address;
        n_ptr->m_field_name   = "N/A";
        n_ptr->m_parent       = node;
        n_ptr->m_enum_base    = node->m_enum_base;
        node->m_children.push_back(n_ptr);
        endInsertRows();
        return true;
    }
    if (addornements[0] == 'v')
    {
        // Pointer to vector
        beginInsertRows(p_parent, 0, 1);
        NodeVector* n_vec = new NodeVector;
        n_vec->m_df_type      = node->m_df_type;
        n_vec->m_rdf_type     = RDF_Type::Vector;
        n_vec->m_addornements = addornements;
        n_vec->m_field_name   = "N/A";
        n_vec->m_address      = item_address;
        n_vec->m_enum_base    = node->m_enum_base;
        n_vec->m_parent       = node;
        node->m_children.push_back(n_vec);
        endInsertRows();
        return true;
    }
    if (addornements[0] == '[')
    {
        // Pointer to array
        auto array_addornements = addornements.substr(1, 500);

        // Get the array size from the addornements
        size_t iterator = 0;
        while ((iterator < array_addornements.length()) && (std::isdigit(array_addornements[iterator])))
            iterator++;
        std::string array_size = array_addornements.substr(0, iterator);

        beginInsertRows(p_parent, 0, 1);
        NodeArray* n_array    = new NodeArray;
        n_array->m_df_type      = node->m_df_type;
        n_array->m_rdf_type     = RDF_Type::Array;
        n_array->m_addornements = addornements;
        n_array->m_field_name   = "N/A";
        n_array->m_address      = item_address;
        n_array->m_enum_base    = node->m_enum_base;
        n_array->m_array_size   = std::stoi(array_size);
        n_array->m_parent       = node;
        node->m_children.push_back(n_array);
        endInsertRows();
        return true;
    }

    return false;
}

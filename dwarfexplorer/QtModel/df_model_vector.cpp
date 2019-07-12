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
#include <QListIterator>
#include <sstream>
#include <iomanip>
#include "../df_model.h"
#include "node.h"

using namespace rdf;

extern void                                          fill_node(uint64_t p_df_structure, rdf::Node* p_node_parent);
extern RDF_Type                                      df_2_rdf(DF_Type p_df_type);
extern std::tuple<int64_t, std::string, std::string> get_enum_decoded(const NodeEnum* p_node);
extern DF_Type                                       get_df_subtype(DF_Type p_base_type, uint64_t p_address);
extern std::pair<int,int>                            enum_min_max(DF_Type p_enum);
extern DF_Type                                       enum_base_type(DF_Type p_enum);


//
//------------------------------------------------------------------------------------//
//
std::string format_vector_index(int p_value, int p_vector_size)
{
    // Node name [index]
    std::stringstream ss;
    auto max_length        = std::to_string(p_vector_size).length();
    std::string field_name = "[";
    std::string value      = std::to_string(p_value);
    ss << std::right << std::setw(max_length) << value;
    auto value_padded      = ss.str();
    field_name.append(value_padded).append("]");
    return field_name;
}


//
//------------------------------------------------------------------------------------//
//
void fill_simple_entry(NodeBase* p_pve, Node* p_node, size_t p_size, uint64_t p_address, DF_Type p_df_type, RDF_Type p_rdf_type)
{
    p_pve->m_address       = p_address;
    p_pve->m_df_type       = p_df_type;
    p_pve->m_rdf_type      = p_rdf_type;
    p_pve->m_parent        = p_node;
    //p_pve->m_used_type     = p_node->m_used_type;
    p_pve->m_field_name    = "N/A";
    p_pve->m_comment       = "";
    p_pve->m_node_type     = NodeType::Simple;
    p_pve->m_parent        = p_node;

    p_node->m_children.push_back(p_pve);
}

//
//------------------------------------------------------------------------------------//
//
void fill_void_vector_entry(Node* p_parent_node, int p_index, uint64_t p_address, int p_vector_size)
{
    // Node name [index]
    std::string field_name = format_vector_index(p_index, p_vector_size);

    auto n_void          = new NodeVoid;
    n_void->m_parent     = p_parent_node;
    n_void->m_field_name = field_name;
    n_void->m_address    = p_address;
    p_parent_node->m_children.push_back(n_void);
}

//
//------------------------------------------------------------------------------------//
//
std::size_t DF_Model::get_vector_size(const NodeVector* p_node) const
{
    auto vector_start_address = reinterpret_cast<uint64_t*>(p_node->m_address);
    auto end                  = p_node->m_address + sizeof(void*);
    auto vector_end_address   = reinterpret_cast<uint64_t*>(end);

    if (*vector_start_address == 0)
        return 0;

    auto diff = *vector_end_address - *vector_start_address;

    if ((p_node->m_addornements == "v") && (p_node->m_df_type != DF_Type::Void))
    {
        // Vector of DF_Types
        if (p_node->m_enum_base == DF_Type::None)
        {
            auto size = rdf::size_of_DF_Type(p_node->m_df_type);
            return diff / size;
        }
        else
        {
            auto size = rdf::size_of_DF_Type(p_node->m_enum_base);
            return diff / size;
        }
    }
    else
    {
        // Vector of something of DF_Types
        auto rest = p_node->m_addornements;
        rest = rest.substr(1, 500);

        if ((rest[0] == '*') || (p_node->m_df_type == DF_Type::Void))
        {
            // Vector of pointers
            return diff / sizeof(void*);
        }
        if (rest[0] == '[')
        {
            // Vector of arrays
            return 0;
        }
    }
    return 0;
}


void fill_compound_vector_entry(Node* p_parent_node, uint64_t p_address, std::string p_field_name, RDF_Type p_rdf_type)
{
    auto n_pve = new NodeCompound;
    n_pve->m_df_type = p_parent_node->m_df_type;

    uint64_t pointee = *(reinterpret_cast<uint64_t*>(p_address));
    if (pointee != 0)
    {
        DF_Type real_type = get_df_subtype(p_parent_node->m_df_type, pointee);
        if (real_type != DF_Type::None)
            n_pve->m_df_type = real_type;
    }

    n_pve->m_rdf_type   = p_rdf_type;
    n_pve->m_field_name = p_field_name;
    n_pve->m_address    = p_address;
    n_pve->m_parent     = p_parent_node;
    fill_node(p_address, p_parent_node);
}

//
//------------------------------------------------------------------------------------//
//
void fill_vector_entry(NodeVector* p_parent_node, size_t p_index, uint64_t p_address, int p_vector_size)
{
    std::string field_name;
    std::string field_comment;
    field_name = format_vector_index(p_index, p_vector_size);

    if (p_parent_node->m_index_enum != DF_Type::None)
    {
        // The name is one enum
        // TODO this is a hack
        NodeEnum dummy;
        auto first_value   = enum_min_max(p_parent_node->m_df_type).first;
        int  real_index    = p_index;
        dummy.m_address    = reinterpret_cast<uint64_t>(&real_index);
        dummy.m_base_type  = (p_parent_node->m_enum_base != DF_Type::None ? p_parent_node->m_enum_base : enum_base_type(p_parent_node->m_index_enum));
        dummy.m_df_type    = p_parent_node->m_index_enum;
        auto enum_decoded  = get_enum_decoded(&dummy);
        auto value_decoded = std::get<1>(enum_decoded);
        field_name.append("=");
        field_name.append(value_decoded);
        field_comment = std::get<2>(enum_decoded);
    }


    switch(p_parent_node->m_df_type)
    {
        case rdf::DF_Type::uint8_t :
        {
            auto n_pve = new NodeSimple<uint8_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(uint8_t), p_address, DF_Type::uint8_t, RDF_Type::uint8_t);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::uint16_t :
        {
            auto n_pve = new NodeSimple<uint16_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(uint16_t), p_address, DF_Type::uint16_t, RDF_Type::uint16_t);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::uint32_t :
        {
            auto n_pve = new NodeSimple<uint32_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(uint32_t), p_address, DF_Type::uint32_t, RDF_Type::uint32_t);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::uint64_t :
        {
            auto n_pve = new NodeSimple<uint64_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(uint64_t), p_address, DF_Type::uint64_t, RDF_Type::uint64_t);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::int8_t :
        {
            auto n_pve = new NodeSimple<int8_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(int8_t), p_address, DF_Type::int8_t, RDF_Type::int8_t);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::int16_t :
        {
            auto n_pve = new NodeSimple<int16_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(int16_t), p_address, DF_Type::int16_t, RDF_Type::int16_t);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::int32_t :
        {
            auto n_pve = new NodeSimple<int32_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(int32_t), p_address, DF_Type::int32_t, RDF_Type::int32_t);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::int64_t :
        {
            auto n_pve = new NodeSimple<int64_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(int64_t), p_address, DF_Type::int64_t, RDF_Type::int64_t);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::S_float :
        {
            auto n_pve = new NodeSimple<float>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(float), p_address, DF_Type::S_float, RDF_Type::S_float);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::Long :
        {
            auto n_pve = new NodeSimple<long>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(long), p_address, DF_Type::Long, RDF_Type::Long);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::Bool :
        {
            auto n_pve = new NodeSimple<bool>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(bool), p_address, DF_Type::Bool, RDF_Type::Bool);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        case rdf::DF_Type::Stl_string :
        {
            auto n_pve = new NodeSimple<std::string>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(std::string), p_address, DF_Type::Stl_string, RDF_Type::Stl_string);
            n_pve->m_field_name = field_name;
            n_pve->m_comment    = field_comment;
            n_pve->m_address    = p_address;
            n_pve->m_parent     = p_parent_node;
            return;
        }
        default:
            break;
    }

    // We need to know if the DF_Type is a
    // DF structure enum or bitfield
    RDF_Type rdf_type = RDF_Type::Void;

    if (p_parent_node->m_df_type != DF_Type::Void)
        rdf_type = df_2_rdf(p_parent_node->m_df_type);


    if (rdf_type == RDF_Type::Enum)
    {
        auto n_pve = new NodeEnum;

        if (p_parent_node->m_enum_base == DF_Type::None)
        {
            fill_simple_entry(n_pve, p_parent_node, size_of_DF_Type(p_parent_node->m_df_type), p_address, p_parent_node->m_df_type, rdf_type);
            n_pve->m_node_type = NodeType::Enum;
            //n_pve->m_base_type = p_parent_node->m_df_type;
        }
        else
        {
            fill_simple_entry(n_pve, p_parent_node, size_of_DF_Type(p_parent_node->m_enum_base), p_address, p_parent_node->m_df_type, rdf_type);
            n_pve->m_node_type = NodeType::Enum;
            n_pve->m_base_type = p_parent_node->m_enum_base;
        }
        n_pve->m_enum_type = DF_Type_to_string(p_parent_node->m_df_type);
        n_pve->m_field_name = field_name;
        return;
    }
    if (rdf_type == RDF_Type::Bitfield)
    {
        auto n_pve = new NodeBitfield;
        fill_simple_entry(n_pve, p_parent_node, size_of_DF_Type(p_parent_node->m_df_type), p_address, p_parent_node->m_df_type, rdf_type);
        n_pve->m_field_name = field_name;
        n_pve->m_node_type  = NodeType::Bitfield;
        return;
    }


    switch (rdf_type)
    {
        case RDF_Type::Struct :
            fill_compound_vector_entry(p_parent_node, p_address, field_name, RDF_Type::Struct);
            break;
        case RDF_Type::Compound :
            fill_compound_vector_entry(p_parent_node, p_address, field_name, RDF_Type::Compound);
            break;
        case RDF_Type::Class:
            fill_compound_vector_entry(p_parent_node, p_address, field_name, RDF_Type::Class);
            break;
        case RDF_Type::Union:
            fill_compound_vector_entry(p_parent_node, p_address, field_name, RDF_Type::Union);
            break;
        case RDF_Type::Void:
            fill_void_vector_entry(p_parent_node, p_index, p_address, p_vector_size);
            break;
        default:
            break;
    }
}

//
//------------------------------------------------------------------------------------//
//
bool DF_Model::insertRowsBoolVector(NodeVector* p_node_vector, const QModelIndex& p_parent)
{
    auto vector_size = get_vector_size(p_node_vector);
    if ( vector_size == 0)
        return false;

    beginInsertRows(p_parent, 0, (int)vector_size);
    auto vector_address = p_node_vector->m_address;

    std::string field_name;
    for (unsigned int i = 0; i < vector_size; i++)
    {
        field_name = format_vector_index(i, vector_size);

        auto n_pve          = new NodeSimple<bool>;
        n_pve->m_df_type    = DF_Type::Bool;
        n_pve->m_rdf_type   = RDF_Type::Bool;
        n_pve->m_parent     = p_node_vector;
        n_pve->m_comment    = "";
        n_pve->m_node_type  = NodeType::Simple;
        n_pve->m_field_name = field_name;
        n_pve->m_address    = vector_address;
        n_pve->m_parent     = p_node_vector;
        p_node_vector->m_children.push_back(n_pve);
    }

    endInsertRows();
    return true;
}

//
//------------------------------------------------------------------------------------//
//
bool DF_Model::insertRowsVector(const QModelIndex& p_parent)
{
    auto node = dynamic_cast<NodeVector*>(nodeFromIndex(p_parent));

    if ((node->m_children.size() > 0) && (node->m_children[0]->m_node_type != NodeType::Dummy))
        return false;


    // Remove the dummy node if any
    if (node->m_children.size() > 0)
    {
        beginRemoveRows(p_parent, 0, 1);
        node->m_children.erase(node->m_children.begin());
        endRemoveRows();
    }

    // vector<bool> is a special case
    if (node->m_df_type == DF_Type::Bool)
        return insertRowsBoolVector(node, p_parent);

    auto vector_size = get_vector_size(node);
    if ( vector_size == 0)
        return false;

    beginInsertRows(p_parent, 0, (int)vector_size);
    auto vector_address = node->m_address;
    uint64_t* pointer = reinterpret_cast<uint64_t*>(vector_address);
    uint64_t  item_address = *pointer;

    // Remove vector qualifier
    auto addornements = node->m_addornements.substr(1, 500);

    // First process vector of simple types and vector of DF structures, bitfields or enums
    if (addornements.length() == 0)
    {
        for (unsigned int i = 0; i < vector_size; i++)
        {
            fill_vector_entry(node, i, item_address, vector_size);
            switch(node->m_df_type)
            {
                case rdf::DF_Type::uint8_t:
                    item_address += sizeof(uint8_t);
                    break;
                case rdf::DF_Type::uint16_t:
                    item_address += sizeof(uint16_t);
                    break;
                case rdf::DF_Type::uint32_t:
                    item_address += sizeof(uint32_t);
                    break;
                case rdf::DF_Type::uint64_t:
                    item_address += sizeof(uint64_t);
                    break;
                case rdf::DF_Type::int8_t:
                    item_address += sizeof(int8_t);
                    break;
                case rdf::DF_Type::int16_t:
                    item_address += sizeof(int16_t);
                    break;
                case rdf::DF_Type::int32_t:
                    item_address += sizeof(int32_t);
                    break;
                case rdf::DF_Type::int64_t:
                    item_address += sizeof(int64_t);
                    break;
                case rdf::DF_Type::S_float:
                    item_address += sizeof(float);
                    break;
                case rdf::DF_Type::Bool:
                    item_address += sizeof(bool);
                    break;
                case rdf::DF_Type::Stl_string:
                    item_address += sizeof(std::string);
                    break;
                case rdf::DF_Type::Void:
                    item_address += sizeof(void*);
                    break;
                default: // DF structure, enum or bitfield
                    if (node->m_enum_base == DF_Type::None)
                        item_address += size_of_DF_Type(node->m_df_type);
                    else
                        item_address += size_of_DF_Type(node->m_enum_base);
            }
        }
        endInsertRows();
        return true;
    }

    if (addornements[0] == '*')
    {
        // Vector of pointers
        for (unsigned int i = 0; i < vector_size; i++)
        {
            NodePointer* node_pointer = new NodePointer;
            fill_simple_entry(node_pointer, node, sizeof(void*), item_address, node->m_df_type, RDF_Type::Pointer);

            uint64_t pointee = *(reinterpret_cast<uint64_t*>(item_address));
            if (pointee != 0)
            {
                DF_Type real_type = get_df_subtype(node->m_df_type, pointee);
                if (real_type != DF_Type::None)
                    node_pointer->m_df_type = real_type;
            }

            node_pointer->m_addornements = addornements;
            node_pointer->m_node_type = NodeType::Pointer;
            node_pointer->m_children.push_back(dummy());
            // Node name [index]
            std::string field_name = format_vector_index(i, vector_size);
            node_pointer->m_field_name = field_name;
            item_address += sizeof(void*);
        }
        endInsertRows();
        return true;
    }
    return false;
}

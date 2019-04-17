#include <cstdint>
#include <DataDefs.h>
#include <Core.h>
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteServer.h>
#include <RemoteClient.h>
#include <VersionInfo.h>
#include "modules/Translation.h"
#include "df_all.h"
#include "df_model.h"

using namespace rdf;
using namespace DFHack;

extern std::map<DF_Type,size_t> DF_types_size_table;
extern std::string get_enum_value_as_string(DF_Type p_df_type, uint64_t p_address);

std::string to_hex(uint64_t p_dec)
{
    if (p_dec == 0)
        return "0x0";
    std::string l_answer = "";
    uint64_t l_rem;
    while (p_dec > 0)
    {
        l_rem = p_dec % 16;
        switch (l_rem)
        {
            case 0:
                l_answer = "0" + l_answer;
                break;
            case 1:
                l_answer = "1" + l_answer;
                break;
            case 2:
                l_answer = "2" + l_answer;
                break;
            case 3:
                l_answer = "3" + l_answer;
                break;
            case 4:
                l_answer = "4" + l_answer;
                break;
            case 5:
                l_answer = "5" + l_answer;
                break;
            case 6:
                l_answer = "6" + l_answer;
                break;
            case 7:
                l_answer = "7" + l_answer;
                break;
            case 8:
                l_answer = "8" + l_answer;
                break;
            case 9:
                l_answer = "9" + l_answer;
                break;
            case 10:
                l_answer = "A" + l_answer;
                break;
            case 11:
                l_answer = "B" + l_answer;
                break;
            case 12:
                l_answer = "C" + l_answer;
                break;
            case 13:
                l_answer = "D" + l_answer;
                break;
            case 14:
                l_answer = "E" + l_answer;
                break;
            case 15:
                l_answer = "F" + l_answer;
                break;
        }
        p_dec = p_dec / 16;

    }
    return "0x" + l_answer;
}


bool is_node_bitfield_entry(NodeBase* p_node)
{
    //return ( p_node->m_rdf_type == rdf::RDF_Type::Bool) && ( p_node->m_parent->m_rdf_type == rdf::RDF_Type::Bitfield);
    return false;
}

QString process_node_bitfield_entry(NodeBase* p_node)
{
//    NodeBitfieldEntry* l_bitfield_entry = dynamic_cast<NodeBitfieldEntry*>(p_node);
//    return l_bitfield_entry->m_value;
    return "";
}

bool is_node_simple(const NodeBase* p_node)
{
    switch (p_node->m_df_type)
    {
        case rdf::DF_Type::int64_t:  return true;
        case rdf::DF_Type::uint64_t: return true;
        case rdf::DF_Type::int32_t:  return true;
        case rdf::DF_Type::uint32_t: return true;
        case rdf::DF_Type::int16_t:  return true;
        case rdf::DF_Type::uint16_t: return true;
        case rdf::DF_Type::int8_t:   return true;
        case rdf::DF_Type::uint8_t:  return true;
        case rdf::DF_Type::Bool:     return true;
        case rdf::DF_Type::Void:     return true;
        default: break;
    }
    return false;
}

QString process_node_simple(const NodeBase* p_node)
{
    switch (p_node->m_df_type)
    {
        case rdf::DF_Type::int64_t:
            return QString::fromStdString(std::to_string(*(reinterpret_cast<int64_t*>(p_node->m_address))));
        case rdf::DF_Type::uint64_t:
            return QString::fromStdString(std::to_string(*(reinterpret_cast<uint64_t*>(p_node->m_address))));
        case rdf::DF_Type::int32_t:
            return QString::fromStdString(std::to_string(*(reinterpret_cast<int32_t*>(p_node->m_address))));
        case rdf::DF_Type::uint32_t:
            return QString::fromStdString(std::to_string(*(reinterpret_cast<uint32_t*>(p_node->m_address))));
        case rdf::DF_Type::int16_t:
            return QString::fromStdString(std::to_string(*(reinterpret_cast<int16_t*>(p_node->m_address))));
        case rdf::DF_Type::uint16_t:
            return QString::fromStdString(std::to_string(*(reinterpret_cast<uint16_t*>(p_node->m_address))));
        case rdf::DF_Type::int8_t:
            return QString::fromStdString(std::to_string(*(reinterpret_cast<int8_t*>(p_node->m_address))));
        case rdf::DF_Type::uint8_t:
            return QString::fromStdString(std::to_string(*(reinterpret_cast<uint8_t*>(p_node->m_address))));
        case rdf::DF_Type::Bool:
            return QString::fromStdString(*(reinterpret_cast<int64_t*>(p_node->m_address)) ? "True" : "False");
        case rdf::DF_Type::Void:
            return "";
        default: break;
    }
    return "Unknown1";
}

bool is_node_void_pointer(const NodeBase* p_node)
{
    if ((p_node->m_rdf_type == rdf::RDF_Type::Pointer)
            && (p_node->m_used_type == "void*"))
        return true;
    return false;
}

QString process_node_void_pointer(const NodeBase* p_node)
{
    return "";
}


bool is_node_stl_string(const NodeBase*p_node)
{
    if (p_node->m_rdf_type == rdf::RDF_Type::Stl_string)
        return true;
    return false;
}

QString process_node_stl_string(const NodeBase*p_node)
{
    auto string_address = reinterpret_cast<std::string*>(p_node->m_address);
    std::string object = *string_address;
    if (object.empty())
        return "''";
    return QString::fromStdString(object);
}

QString process_node_simple_pointer(NodeBase*p_node)
{
    return "";
}

bool is_node_df_pointer(NodeBase* p_node)
{
    return false;
}

QString process_node_df_pointer(NodeBase* p_node)
{
    return "";
}

bool is_node_df_pointer_vector_entry(NodeBase* p_node)
{
    return false;
}

QString process_node_df_pointer_vector_entry(NodeBase* p_node)
{
    return "";
}

QString process_pointer(const NodeBase* p_node)
{
    auto pointer_address = reinterpret_cast<uint64_t*>(p_node->m_address);
    auto item_address = reinterpret_cast<uint64_t>(*pointer_address);
    std::string address_hex = to_hex(item_address);
    return QString::fromStdString(address_hex);
}

QString Enum_data_from_Value(const NodeBase* p_node)
{
        std::string enum_value_as_string;
        if (p_node->m_used_type == "int8_t")
        {
            auto pointer_enum = reinterpret_cast<int8_t*>(p_node->m_address);
            auto enum_value = *pointer_enum;
            enum_value_as_string = std::to_string(enum_value);
        }
        if (p_node->m_used_type == "int16_t")
        {
            auto pointer_enum = reinterpret_cast<int16_t*>(p_node->m_address);
            auto enum_value = *pointer_enum;
            enum_value_as_string = std::to_string(enum_value);
        }
        else if (p_node->m_used_type == "int32_t")
        {
            auto pointer_enum = reinterpret_cast<int32_t*>(p_node->m_address);
            auto enum_value = *pointer_enum;
            enum_value_as_string = std::to_string(enum_value);
        }
        QString l_result = "[";
        l_result.append(QString::fromStdString(enum_value_as_string));
        l_result.append("] = ");
        l_result.append(QString::fromStdString(get_enum_value_as_string(p_node->m_df_type, p_node->m_address)));
        return l_result;
}

QString Bitfield_data_from_Value(const NodeBase* p_node)
{
        auto pointer_bitfield = reinterpret_cast<uint32_t*>(p_node->m_address);
        auto bitfield_value = *pointer_bitfield;
        auto bitfield_value_as_string = to_hex(bitfield_value);
        return QString::fromStdString(bitfield_value_as_string);
}


QString DF_Model::Vector_data_from_Value(const NodeBase* p_node) const
{
       auto node_vector = dynamic_cast<const NodeVector*>(p_node);
        auto vector_size = get_vector_size(node_vector);
        std::string l_size = "[";
        if (vector_size == 0)
        {
            l_size.append("empty]");
            return QString::fromStdString(l_size);
        }
        l_size.append(std::to_string(vector_size));
        if (vector_size == 1)
            l_size.append(" item]");
        else
            l_size.append(" items]");
        return QString::fromStdString(l_size);
 }


QString DF_Model::data_from_Value(const NodeBase* p_node) const
{
    uint64_t l_address = p_node->m_address;

    // Not implemented in this OS
    if (l_address == 0)
        return "N/A";

    if (p_node->m_rdf_type == RDF_Type::Pointer)
        return process_pointer(p_node);

    if (p_node->m_rdf_type == rdf::RDF_Type::Enum)
        return Enum_data_from_Value(p_node);

    if (p_node->m_rdf_type == rdf::RDF_Type::Bitfield)
        return Bitfield_data_from_Value(p_node);

    if (p_node->m_node_type == rdf::NodeType::NodeBitfieldEntry)
    {
        auto node = dynamic_cast<const NodeBitfieldEntry*>(p_node);
        return QString::fromStdString(node->m_value ? "True" : "False");
    }

    if (p_node->m_rdf_type == rdf::RDF_Type::Vector)
        return Vector_data_from_Value(p_node);

    if (p_node->m_rdf_type == rdf::RDF_Type::Array)
        return "";

    if (is_node_void_pointer(p_node))
        return process_node_void_pointer(p_node);

   if (is_node_stl_string(p_node))
        return process_node_stl_string(p_node);

    if (p_node->m_df_type == rdf::DF_Type::language_name)
    {
        // Translate the name
        df::language_name* lang = reinterpret_cast<df::language_name*>(p_node->m_address);
        std::string result = Translation::TranslateName(lang, false, false);
       return QString::fromStdString(DF2UTF(result));
    }

    if (p_node->m_df_type == rdf::DF_Type::coord)
    {
        df::coord* coord = reinterpret_cast<df::coord*>(p_node->m_address);
        return "[X=" + QString::number(coord->x) + ",Y=" + QString::number(coord->y) + ",Z=" + QString::number(coord->z) + "]";
    }

    if (p_node->m_df_type == rdf::DF_Type::coord2d)
    {
        df::coord2d* coord = reinterpret_cast<df::coord2d*>(p_node->m_address);
        return "[X=" + QString::number(coord->x) + ",Y=" + QString::number(coord->y) + "]";
    }

    if (is_node_simple(p_node))
        return process_node_simple(p_node);
    return "";
}

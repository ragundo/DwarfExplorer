#include <algorithm>
#include <QListIterator>
#include "../df_model.h"
#include "node.h"

using namespace rdf;

extern void                            fill_simple_entry(NodeBase* p_pve, Node* p_node, size_t p_size, uint64_t p_address, DF_Type p_df_type, RDF_Type p_rdf_type);
extern std::pair<int64_t, std::string> get_enum_decoded(const NodeEnum* p_node);
extern DF_Type                         get_df_subtype(DF_Type p_base_type, uint64_t p_address);
extern void                            fill_node(uint64_t p_address, Node* p_node_parent);
extern RDF_Type                        df_2_rdf(DF_Type p_df_type);
extern std::pair<int, int>              enum_min_max(DF_Type p_enum);
extern DF_Type                         enum_base_type(DF_Type p_enum);



//
//------------------------------------------------------------------------------------//
//
void fill_df_array_entry(NodeDFArray* p_parent_node, size_t p_index, uint64_t p_address)
{
    std::string field_name;
    field_name = "[";
    field_name.append(std::to_string(p_index)).append("]");

    switch(p_parent_node->m_df_type)
    {
        case rdf::DF_Type::uint8_t :
        {
            auto n_pve = new NodeSimple<uint8_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(uint8_t), p_address, DF_Type::uint8_t, RDF_Type::uint8_t);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::uint16_t :
        {
            auto n_pve = new NodeSimple<uint16_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(uint16_t), p_address, DF_Type::uint16_t, RDF_Type::uint16_t);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::uint32_t :
        {
            auto n_pve = new NodeSimple<uint32_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(uint32_t), p_address, DF_Type::uint32_t, RDF_Type::uint32_t);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::uint64_t :
        {
            auto n_pve = new NodeSimple<uint64_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(uint64_t), p_address, DF_Type::uint64_t, RDF_Type::uint64_t);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::int8_t :
        {
            auto n_pve = new NodeSimple<int8_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(int8_t), p_address, DF_Type::int8_t, RDF_Type::int8_t);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::int16_t :
        {
            auto n_pve = new NodeSimple<int16_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(int16_t), p_address, DF_Type::int16_t, RDF_Type::int16_t);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::int32_t :
        {
            auto n_pve = new NodeSimple<int32_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(int32_t), p_address, DF_Type::int32_t, RDF_Type::int32_t);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::int64_t :
        {
            auto n_pve = new NodeSimple<int64_t>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(int64_t), p_address, DF_Type::int64_t, RDF_Type::int64_t);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::Bool :
        {
            auto n_pve = new NodeSimple<bool>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(bool), p_address, DF_Type::Bool, RDF_Type::Bool);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        case rdf::DF_Type::Stl_string :
        {
            auto n_pve = new NodeSimple<std::string>;
            fill_simple_entry(n_pve, p_parent_node, sizeof(std::string), p_address, DF_Type::Stl_string, RDF_Type::Stl_string);
            n_pve->m_field_name = field_name;
            n_pve->m_address = p_address;
            n_pve->m_parent = p_parent_node;
            return;
        }
        default:
            break;
    }
}

unsigned short get_df_array_size(const NodeDFArray* p_node)
{
    auto offset = p_node->m_address + sizeof(void*);
    unsigned short*  pointer_df_flag_array = reinterpret_cast<unsigned short*>(offset);
    return *pointer_df_flag_array;
}

//
//------------------------------------------------------------------------------------//
//
bool DF_Model::insertRowsDFArray(const QModelIndex& p_parent)
{
    auto node = dynamic_cast<NodeDFArray*>(nodeFromIndex(p_parent));

    if (node->m_children.size() > 0)
        return false;

    unsigned short array_size = get_df_array_size(node);
    node->m_array_size = array_size;

    beginInsertRows(p_parent, 0, array_size);
    uint64_t* item_address_pointer = reinterpret_cast<uint64_t*>(node->m_address);
    uint64_t  item_address         = *item_address_pointer;

    for (unsigned int i = 0; i < array_size; i++)
    {
        fill_df_array_entry(node, i, item_address);
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
            case rdf::DF_Type::Bool:
                item_address += sizeof(bool);
                break;
            case rdf::DF_Type::Stl_string:
                item_address += sizeof(std::string);
                break;
            default:
                break;
        }
    }

    endInsertRows();
    return true;
}

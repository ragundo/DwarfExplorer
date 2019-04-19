#include <algorithm>
#include <QPixmap>
#include <QListIterator>
#include "../df_model.h"
#include "node.h"

using namespace rdf;

extern void fill_node(uint64_t p_df_structure, rdf::Node* p_node_parent);
extern void fill_simple_entry(NodeBase* p_pve, Node* p_node, size_t p_size, uint64_t p_address, DF_Type p_df_type, RDF_Type p_rdf_type);
extern DF_Type get_df_subtype(DF_Type p_base_type, uint64_t p_address);


//
//------------------------------------------------------------------------------------//
//
bool DF_Model::insertRowsPointer(const QModelIndex& p_parent)
{
    auto node = dynamic_cast<NodePointer*>(nodeFromIndex(p_parent));

    if (node->m_df_type == rdf::DF_Type::Void)
        return false;

    if ((node->m_children.size() > 0) && (node->m_children[0]->m_node_type != NodeType::NodeDummy))
        return false;

    // Remove the dummy node if exists
    if ((node->m_children.size() == 1) && (node->m_children[0]->m_df_type == DF_Type::None))
    {
        beginRemoveRows(p_parent, 0, 1);
        node->m_children.remove(0);
        endRemoveRows();
    }

    auto pointer_address = reinterpret_cast<uint64_t*>(node->m_address);
    auto item_address = reinterpret_cast<uint64_t>(*pointer_address);

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

    // Pure pointer to DF structure
    if (node->m_addornements == "*")
    {
        // Check if it's a base class
        DF_Type real_df_type = get_df_subtype(node->m_df_type, item_address);
        if (real_df_type != DF_Type::None)
            node->m_df_type = real_df_type;
        beginInsertRows(p_parent, 0, 5);
        fill_node(item_address, node);
        endInsertRows();
        return true;
    }
    return false;
}

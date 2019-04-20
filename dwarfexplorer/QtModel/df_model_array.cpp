#include <algorithm>
#include <QListIterator>
#include "../df_model.h"
#include "node.h"

using namespace rdf;

extern void fill_simple_entry(NodeBase* p_pve, Node* p_node, size_t p_size, uint64_t p_address, DF_Type p_df_type, RDF_Type p_rdf_type);
extern DF_Type get_df_subtype(DF_Type p_base_type, uint64_t p_address);
extern void fill_node(uint64_t p_address, Node* p_node_parent);
extern RDF_Type df_2_rdf(DF_Type p_df_type);


std::size_t array_size_recursive(std::string p_addornements)
{
    if (!p_addornements.empty())
    {
        if (p_addornements[0] == '[')
        {
            std::string addornements = p_addornements.substr(1,500);
            int index = 0;
            while (std::isdigit(addornements[index++]));
            int array_size = std::stoi(addornements.substr(0,index-1));
            std::string rest = addornements.substr(index, 512);
            if (rest.empty())
                return array_size;
            return array_size*array_size_recursive(rest);
        }
        if (p_addornements[0] == '*')
            return sizeof(void*);
        if (p_addornements[0] == 'v')
            return sizeof(std::vector<void*>);
    }
    return 1;
}

std::size_t get_array_element_size(NodeArray* p_node_array)
{
    std::string addornements = p_node_array->m_addornements;
    // Remove you own addornements
    addornements = addornements.substr(1,500);
    std::size_t index = 0;
    while (std::isdigit(addornements[index++]));
    int array_size = std::stoi(addornements.substr(0,index-1));
    if (index >= addornements.length())
        return array_size*size_of_DF_Type(p_node_array->m_df_type);
    std::string rest = addornements.substr(index, 512);
    return array_size*array_size_recursive(rest)*size_of_DF_Type(p_node_array->m_df_type);
}


void fill_compound_array_entry(Node* p_parent_node, uint64_t p_address, QString p_field_name, RDF_Type p_rdf_type)
{
    auto n_pve = new NodeCompound;
    n_pve->m_df_type = p_parent_node->m_df_type;
    n_pve->m_rdf_type = p_rdf_type;
    n_pve->m_field_name = p_field_name;
    n_pve->m_address = p_address;
    n_pve->m_parent = p_parent_node;
    fill_node(p_address, p_parent_node);
}

//
//------------------------------------------------------------------------------------//
//
void fill_array_entry(NodeArray* p_parent_node, size_t p_index, uint64_t p_address)
{
    // Node name [index]
    QString field_name = "[";
    field_name.append(QString::fromStdString(std::to_string(p_index))).append("]");

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
    // We need to know if the DF_Type is a
    // DF structure enum or bitfield
    RDF_Type rdf_type = df_2_rdf(p_parent_node->m_df_type);

    if (rdf_type == RDF_Type::Enum)
    {
        auto n_pve = new NodeEnum;
        n_pve->m_base_type = p_parent_node->m_enum_base;
        if (p_parent_node->m_enum_base == DF_Type::None)
        {
            //n_pve->m_base_type = p_parent_node->m_df_type;
            n_pve->m_base_type = DF_Type::int32_t;
            fill_simple_entry(n_pve, p_parent_node, size_of_DF_Type(p_parent_node->m_df_type), p_address, p_parent_node->m_df_type, rdf_type);
        }
        else
        {
            n_pve->m_base_type = p_parent_node->m_enum_base;
            fill_simple_entry(n_pve, p_parent_node, size_of_DF_Type(p_parent_node->m_enum_base), p_address, p_parent_node->m_df_type, rdf_type);
        }
        n_pve->m_enum_type = QString::fromStdString(DF_Type_to_string(p_parent_node->m_df_type));
        n_pve->m_field_name = field_name;
        return;
    }
    if (rdf_type == RDF_Type::Bitfield)
    {
        auto n_pve = new NodeBitfield;
        fill_simple_entry(n_pve, p_parent_node, size_of_DF_Type(p_parent_node->m_df_type), p_address, p_parent_node->m_df_type, rdf_type);
        n_pve->m_field_name = field_name;
        n_pve->m_node_type = NodeType::NodeBitfield;
        return;
    }
    switch (rdf_type)
    {
        case RDF_Type::Struct :
            fill_compound_array_entry(p_parent_node, p_address, field_name,RDF_Type::Struct);
            break;
        case RDF_Type::Compound :
            fill_compound_array_entry(p_parent_node, p_address, field_name,RDF_Type::Compound);
            break;
        case RDF_Type::Class:
            fill_compound_array_entry(p_parent_node, p_address, field_name,RDF_Type::Class);
            break;
        case RDF_Type::Union:
            fill_compound_array_entry(p_parent_node, p_address, field_name,RDF_Type::Union);
            break;
        default: break;
    }
}



//
//------------------------------------------------------------------------------------//
//
bool DF_Model::insertRowsArray(const QModelIndex& p_parent)
{
    auto node = dynamic_cast<NodeArray*>(nodeFromIndex(p_parent));

    if (node->m_children.size() > 0)
        return false;

    beginInsertRows(p_parent, 0, node->m_array_size);
    auto item_address = reinterpret_cast<uint64_t>(node->m_address);

    // Remove array qualifier
    auto addornements = node->m_addornements.substr(1, 500);
    while (std::isdigit(addornements[0]))
        addornements = addornements.substr(1,500);

    // First process arrays of simple types and vector of DF structures, bitfields or enums
    if (addornements.length() == 0)
    {
        for (unsigned int i = 0; i < node->m_array_size; i++)
        {
            fill_array_entry(node, i, item_address);
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
        for (unsigned int i = 0; i < node->m_array_size; i++)
        {
            NodePointer* node_pointer = new NodePointer;
            fill_simple_entry(node_pointer, node, sizeof(void*),item_address, node->m_df_type, RDF_Type::Pointer);

            uint64_t pointee = *(reinterpret_cast<uint64_t*>(item_address));
            if (pointee != 0)
            {
                DF_Type real_type = get_df_subtype(node->m_df_type, pointee);
                if (real_type != DF_Type::None)
                    node_pointer->m_df_type = real_type;
            }

            node_pointer->m_addornements = addornements;
            node_pointer->m_node_type = NodeType::NodePointer;
            node_pointer->m_children.push_back(dummy());
            QString field_name = "[";
            field_name.append(QString::fromStdString(std::to_string(i))).append("]");
            node_pointer->m_field_name = field_name;
            item_address += sizeof(void*);
        }
        endInsertRows();
        return true;
    }

    if (addornements[0] == 'v')
    {
        // Array of vectors
        for (unsigned int i = 0; i < node->m_array_size; i++)
        {
            NodeVector* node_vector = new NodeVector;
            fill_simple_entry(node_vector, node, sizeof(void*),item_address, node->m_df_type, RDF_Type::Vector);
            node_vector->m_addornements = addornements;
            node_vector->m_node_type = NodeType::NodeVector;
            node_vector->m_children.push_back(dummy());
            QString field_name = "[";
            field_name.append(QString::fromStdString(std::to_string(i))).append("]");
            node_vector->m_field_name = field_name;
            item_address += sizeof(std::vector<void*>);
        }
        endInsertRows();
        return true;
    }

    if (addornements[0] == '[')
    {
        // Array of arrays
        for (unsigned int i = 0; i < node->m_array_size; i++)
        {
            NodeArray* node_array = new NodeArray;
            node_array->m_addornements = addornements;
            node_array->m_enum_base = node->m_enum_base;
            auto size = addornements.substr(1,512);
            auto index = 0;
            while (std::isdigit(size[index++]));
            auto new_array_size = size.substr(0, index-1 );
            node_array->m_array_size = std::stoi(new_array_size);
            fill_simple_entry(node_array, node, sizeof(void*),item_address, node->m_df_type, RDF_Type::Array);
            node_array->m_node_type = NodeType::NodeArray;
            QString field_name = "[";
            field_name.append(QString::fromStdString(std::to_string(i))).append("]");
            node_array->m_field_name = field_name;
            item_address += get_array_element_size(node_array);
        }
        endInsertRows();
        return true;
    }
    return false;
}

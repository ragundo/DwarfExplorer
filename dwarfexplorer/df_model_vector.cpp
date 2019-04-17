#include <algorithm>
#include <QListIterator>
#include "df_model.h"
#include "node.h"

using namespace rdf;

extern void fill_node(uint64_t p_df_structure, rdf::Node* p_node_parent);
extern RDF_Type df_2_rdf(DF_Type p_df_type);

//
//------------------------------------------------------------------------------------//
//
void fill_simple_entry(NodeBase* p_pve, Node* p_node, size_t p_size, uint64_t p_address, DF_Type p_df_type, RDF_Type p_rdf_type)
{
    p_pve->m_address       = p_address;
    p_pve->m_df_type       = p_df_type;
    p_pve->m_rdf_type      = p_rdf_type;
    p_pve->m_parent        = p_node;
    p_pve->m_used_type     = p_node->m_used_type;
    p_pve->m_field_name    = "";
    p_pve->m_comment       = "";
    p_pve->m_node_type     = NodeType::NodeSimple;
    p_pve->m_parent        = p_node;
    p_pve->m_used_type     = p_node->m_used_type;

    p_node->m_children.append(p_pve);
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
        auto size = rdf::size_of_DF_Type(p_node->m_df_type);
        return diff/size;
    }
    else
    {
        // Vector of something of DF_Types
        auto rest = p_node->m_addornements;
        rest = rest.substr(1,500);

        if ((rest[0] == '*') || (p_node->m_df_type == DF_Type::Void))
        {
            // Vector of pointers
            return diff / sizeof(void*);
        }
        if (rest[0] == '[')
        {
            // Vector of arrays
        }
    }
}


//
//------------------------------------------------------------------------------------//
//
bool DF_Model::insertRowsSimple(const QModelIndex& p_parent)
{
    auto l_node = dynamic_cast<NodeVector*>(nodeFromIndex(p_parent));

    if ((l_node->m_children.size() > 0) && (l_node->m_children[0]->m_node_type != NodeType::NodeDummy))
        return false;

}

void fill_compound_vector_entry(Node* p_parent_node, uint64_t p_address, QString p_field_name, RDF_Type p_rdf_type)
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
void fill_vector_entry(Node* p_parent_node, size_t p_index, uint64_t p_address)
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
        fill_simple_entry(n_pve, p_parent_node, size_of_DF_Type(p_parent_node->m_df_type), p_address, p_parent_node->m_df_type, rdf_type);
        n_pve->m_enum_type = QString::fromStdString(DF_Type_to_string(p_parent_node->m_df_type));
        n_pve->m_field_name = field_name;
        return;        
    }
    if (rdf_type == RDF_Type::Bitfield)
    {
        auto n_pve = new NodeBitfield;
        fill_simple_entry(n_pve, p_parent_node, size_of_DF_Type(p_parent_node->m_df_type), p_address, p_parent_node->m_df_type, rdf_type);
        n_pve->m_field_name = field_name;
        return;                
    }   
    switch (rdf_type)
    {
        case RDF_Type::Struct :
            fill_compound_vector_entry(p_parent_node, p_address, field_name,RDF_Type::Struct); 
            break;        
        case RDF_Type::Compound :
            fill_compound_vector_entry(p_parent_node, p_address, field_name,RDF_Type::Compound);         
            break;        
        case RDF_Type::Class:
            fill_compound_vector_entry(p_parent_node, p_address, field_name,RDF_Type::Class);                 
            break;        
        case RDF_Type::Union:
            fill_compound_vector_entry(p_parent_node, p_address, field_name,RDF_Type::Union);                         
            break;
        default: break;
    }
}

//
//------------------------------------------------------------------------------------//
//
bool DF_Model::insertRowsVector(const QModelIndex& p_parent)
{
    auto l_node = dynamic_cast<NodeVector*>(nodeFromIndex(p_parent));

    if ((l_node->m_children.size() > 0) && (l_node->m_children[0]->m_node_type != NodeType::NodeDummy))
        return false;


    // Remove the dummy node
    beginRemoveRows(p_parent, 0, 1);
    l_node->m_children.remove(0);
    endRemoveRows();


    auto l_vector_size = get_vector_size(l_node);
    if ( l_vector_size == 0)
        return false;

    beginInsertRows(p_parent, 0, (int)l_vector_size);
    auto vector_address = l_node->m_address;
    uint64_t* pointer = reinterpret_cast<uint64_t*>(vector_address);
    auto item_address = reinterpret_cast<uint64_t>(*pointer);

    // Remove vector qualifier
    auto addornements = l_node->m_addornements.substr(1, 500);

    // First process vector of simple types and vector of DF structures, bitfields or enums
    if (addornements.length() == 0)
    {
        for (unsigned int i = 0; i < l_vector_size; i++)
        {
            fill_vector_entry(l_node, i, item_address);
            switch(l_node->m_df_type)
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
                default: // DF structure, enum or bitfield
                    item_address += size_of_DF_Type(l_node->m_df_type);
                    break;
            }
        }
        endInsertRows();
        return true;
    }

    if (addornements[0] == '*')
    {
        // Vector of pointers
        for (unsigned int i = 0; i < l_vector_size; i++)
        {
            NodePointer* node_pointer = new NodePointer;
            fill_simple_entry(node_pointer, l_node, sizeof(void*),item_address, l_node->m_df_type, RDF_Type::Pointer);
            node_pointer->m_addornements = addornements;
            node_pointer->m_node_type = NodeType::NodePointer;
            node_pointer->m_children.push_back(dummy());
            // Node name [index]
            QString field_name = "[";
            field_name.append(QString::fromStdString(std::to_string(i))).append("]");
            node_pointer->m_field_name = field_name;
            item_address += sizeof(void*);
        }
        return true;
    }
return false;
}

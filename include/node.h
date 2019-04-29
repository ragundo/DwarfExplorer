#ifndef NODE_H
#define NODE_H

#include <functional>
#include <string>
#include <QtAlgorithms>
#include <QList>
#include <QVector>
#include "DF_Types.h"
#include "RDF_Types.h"

namespace rdf
{
    enum class NodeType
    {
        Simple,
        Compound,
        AnonymousCompound,
        Vector,
        Array,
        Union,
        AnonymousUnion,
        Range,
        Root,
        Enum,
        Bitfield,
        BitfieldEntry,
        Pointer,
        Void,
        Padding,
        StaticString,
        Dummy,
        DFFlagArray,
        DFArray
    };

    class NodeRoot;

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeBase
    {
    public:
        std::string      m_field_name {""};
        DF_Type          m_df_type    {rdf::DF_Type::None};
        RDF_Type         m_rdf_type   {rdf::RDF_Type::None};
        NodeBase*        m_parent     {nullptr};
        std::string      m_comment    {""};
        std::string      m_refers_to  {""};        
        uint64_t         m_address;
        NodeType         m_node_type;
        //QList<NodeBase*> m_path;

        virtual ~NodeBase() {}
        virtual NodeBase* clone() = 0;
        virtual std::string node_path_name() = 0;
        virtual bool is_root_node() const
        {
            return false;
        }

        NodeRoot* get_root_node();


        std::string path();

    protected:
        void init(NodeBase* p_dest)
        {
            p_dest->m_field_name = this->m_field_name;
            p_dest->m_df_type = this->m_df_type;
            p_dest->m_rdf_type = this->m_rdf_type;
            p_dest->m_parent = nullptr;
            p_dest->m_comment = this->m_comment;
            p_dest->m_node_type = this->m_node_type;
            p_dest->m_address = this->m_address;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeDummy : public NodeBase
    {
        NodeDummy()
        {
            m_node_type = NodeType::Dummy;
        }

        NodeBase* clone() override
        {
            auto clone = new NodeDummy;
            init(clone);
            return clone;
        }

        std::string node_path_name()
        {
            return "";
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodePadding : public NodeBase
    {
        unsigned int m_size;

        NodePadding()
        {
            m_node_type = NodeType::Padding;
        }

        NodeBase* clone() override
        {
            auto clone = new NodePadding;
            clone->m_size = m_size;
            init(clone);
            return clone;
        }

        std::string node_path_name()
        {
            return "";
        }
    };

//
    //------------------------------------------------------------------------------------//
    //
    struct NodeStaticString : public NodeBase
    {
        unsigned int m_size;

        NodeStaticString()
        {
            m_node_type = NodeType::StaticString;
        }

        NodeBase* clone() override
        {
            auto clone = new NodePadding;
            clone->m_size = m_size;
            init(clone);
            return clone;
        }

        std::string node_path_name()
        {
            return "";
        }
    };    

    //
    //------------------------------------------------------------------------------------//
    //
    struct Node : public NodeBase
    {
        QVector<NodeBase*> m_children;

        NodeBase* clone() override
        {
            auto clon = new Node;
            init(clon);
            return clon;
        }

        std::string node_path_name()
        {
            return m_field_name;
        }

        ~Node()
        {
            for(int i = 0; i < m_children.size(); i++)
                delete m_children.takeAt(i);
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    template<typename T>
    struct NodeSimple : public Node
    {
        NodeBase* clone() override
        {
            auto clon = new NodeSimple<T>;
            init(clon);
            return clon;
        }

        std::string node_path_name()
        {
            return m_field_name;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeVoid : public NodeBase
    {
        NodeVoid() : NodeBase()
        {
            m_df_type   = DF_Type::Void;
            m_rdf_type  = RDF_Type::Void;
            m_node_type = NodeType::Void;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeVoid;
            return clon;
        }

        std::string node_path_name()
        {
            return m_field_name;
        }        
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeRoot : public Node
    {
        std::string m_path;

        NodeRoot()
        {
            m_node_type = NodeType::Root;
        }

        bool is_root_node() const override
        {
            return true;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeRoot;
            init(clon);
            clon->m_path = m_path;
            return clon;
        }

        std::string node_path_name()
        {
            return m_field_name;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeCompound : public Node
    {
        NodeCompound()
        {
            m_node_type = NodeType::Compound;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeCompound;
            init(clon);
            return clon;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeUnion : public Node
    {
        NodeUnion()
        {
            m_node_type = NodeType::Union;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeUnion;
            init(clon);
            return clon;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeAnonymous : public Node
    {
        NodeBase* clone() override
        {
            auto clon = new NodeAnonymous;
            init(clon);
            return clon;
        }

        std::string node_path_name()
        {
            return "";
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeEnum : public Node
    {
        DF_Type     m_base_type{DF_Type::int32_t};
        std::string m_enum_type{""};
        int         m_first_value{999999};
        int         m_last_value{0};  

        NodeEnum()
        {
            m_node_type = NodeType::Enum;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeEnum;
            init(clon);
            clon->m_enum_type = m_enum_type;
            clon->m_base_type = m_base_type;            
            return clon;
        }        
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeBitfieldEntry : public NodeSimple<bool>
    {
        int m_index;
        bool m_value;

        NodeBitfieldEntry()
        {
            m_node_type = NodeType::BitfieldEntry;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeBitfieldEntry;
            init(clon);
            clon->m_index = m_index;
            clon->m_value = m_value;
            return clon;
        }
    };    

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeBitfield : public Node
    {
        DF_Type m_index_enum{DF_Type::None};
        NodeBitfield()
        {
            m_node_type = NodeType::Bitfield;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeBitfield;
            init(clon);
            clon->m_index_enum = m_index_enum;
            return clon;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeDFFlagArray : public Node
    {
        DF_Type     m_index_enum{DF_Type::None};
        std::size_t m_size;
        
        NodeDFFlagArray()
        {
            m_node_type = NodeType::DFFlagArray;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeDFFlagArray;
            init(clon);
            clon->m_index_enum = m_index_enum;
            clon->m_size       = m_size;
            return clon;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodePointer : public Node
    {
        std::string m_addornements{""};
        DF_Type m_enum_base{DF_Type::int32_t};
        NodePointer()
        {
            m_node_type = NodeType::Pointer;
        }


        NodeBase* clone() override
        {
            auto clon = new NodePointer;
            init(clon);
            clon->m_addornements = m_addornements;
            clon->m_enum_base    = m_enum_base;            
            return clon;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeVector : public Node
    {
        std::string  m_addornements{""};
        DF_Type m_enum_base{DF_Type::None};
        DF_Type     m_index_enum{DF_Type::None};        

        NodeVector()
        {
            m_node_type = NodeType::Vector;
            m_enum_base = DF_Type::None;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeVector;
            init(clon);
            clon->m_addornements = m_addornements;
            clon->m_enum_base = m_enum_base;
            return clon;
        }
    };


    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeArray : public Node
    {
    public:
        std::string m_addornements{""};
        std::size_t m_array_size{0};
        DF_Type     m_enum_base{DF_Type::None};
        DF_Type     m_index_enum{DF_Type::None};

        NodeArray()
        {
            m_node_type = NodeType::Array;
        }


        NodeBase* clone() override
        {
            auto clon = new NodeArray;
            init(clon);
            clon->m_addornements = m_addornements;
            clon->m_array_size   = m_array_size;
            clon->m_enum_base    = m_enum_base;
            clon->m_index_enum   = m_index_enum;
            return clon;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeDFArray : public Node
    {
    public:
        std::string m_addornements{""};
        std::size_t m_array_size{0};

        NodeDFArray()
        {
            m_node_type = NodeType::DFArray;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeDFArray;
            init(clon);
            clon->m_addornements = m_addornements;
            clon->m_array_size   = m_array_size;
            return clon;
        }
    };

    NodeDummy*  dummy();
}
#endif // NODE_H

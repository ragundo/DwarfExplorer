#ifndef NODE_H
#define NODE_H

#include <functional>
#include <QString>
#include <QtAlgorithms>
#include <QList>
#include <QVector>
#include "DF_Types.h"
#include "RDF_Types.h"

namespace rdf
{
    enum class NodeType
    {
        NodeSimple,
        NodeCompound,
        NodeAnonymousCompound,
        NodeVector,
        NodeArray,
        NodeUnion,
        NodeAnonymousUnion,
        NodeRange,
        NodeRoot,
        NodeEnum,
        NodeBitfield,
        NodeBitfieldEntry,
        NodePointer,
        NodeDummy
    };

    class NodeRoot;

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeBase
    {
    public:
        QString          m_field_name {""};
        DF_Type          m_df_type    {rdf::DF_Type::None};
        RDF_Type         m_rdf_type   {rdf::RDF_Type::None};
        NodeBase*        m_parent     {nullptr};
        QString          m_comment    {""};
        uint64_t         m_address;
        NodeType         m_node_type;
        //QList<NodeBase*> m_path;

        virtual ~NodeBase() {}
        virtual NodeBase* clone() = 0;
        virtual QString node_path_name() = 0;
        virtual bool is_root_node() const
        {
            return false;
        }

        NodeRoot* get_root_node();


        QString path();

//        QString get_string_path() const
//        {
//            QString result;
//            if (m_parent)
//                result = m_parent->get_string_path();
//            result.append(".").append(m_field_name);
//            return result;
//        }

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
            m_node_type = NodeType::NodeDummy;
        }

        NodeBase* clone() override
        {
            auto clone = new NodeDummy;
            init(clone);
            return clone;
        }

        QString node_path_name()
        {
            return "";
        }
    };

    template<typename T>
    struct NodeSimple : public NodeBase
    {
        NodeBase* clone() override
        {
            auto clon = new NodeSimple<T>;
            init(clon);
            return clon;
        }

        QString node_path_name()
        {
            return m_field_name;
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

        QString node_path_name()
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
    struct NodeRoot : public Node
    {
        QString m_path;

        NodeRoot()
        {
            m_node_type = NodeType::NodeRoot;
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

        QString node_path_name()
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
            m_node_type = NodeType::NodeCompound;
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
            m_node_type = NodeType::NodeUnion;
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

        QString node_path_name()
        {
            return "";
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeEnum : public Node
    {
        DF_Type m_base_type;
        QString m_enum_type;

        NodeEnum()
        {
            m_node_type = NodeType::NodeEnum;
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
            m_node_type = NodeType::NodeBitfieldEntry;
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
        NodeBitfield()
        {
            m_node_type = NodeType::NodeBitfield;
        }

        NodeBase* clone() override
        {
            auto clon = new NodeBitfield;
            init(clon);
            return clon;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodePointer : public Node
    {
        std::string m_addornements;

        NodePointer()
        {
            m_node_type = NodeType::NodePointer;
        }


        NodeBase* clone() override
        {
            auto clon = new NodePointer;
            init(clon);
            clon->m_addornements = m_addornements;
            return clon;
        }
    };

    //
    //------------------------------------------------------------------------------------//
    //
    struct NodeVector : public Node
    {
        std::string m_addornements;
        DF_Type      m_enum_base;

        NodeVector()
        {
            m_node_type = NodeType::NodeVector;
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
        DF_Type      m_enum_base{DF_Type::None};

        NodeArray()
        {
            m_node_type = NodeType::NodeArray;
        }


        NodeBase* clone() override
        {
            auto clon = new NodeArray;
            init(clon);
            clon->m_addornements = m_addornements;
            clon->m_array_size   = m_array_size;
            clon->m_enum_base    = m_enum_base;
            return clon;
        }
    };


    NodeDummy*  dummy();
}
#endif // NODE_H

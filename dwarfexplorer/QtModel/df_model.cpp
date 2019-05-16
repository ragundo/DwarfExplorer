#include <algorithm>
#include <QPixmap>
#include <QListIterator>
#include <QDebug>
#include "../df_model.h"
#include "node.h"

using namespace rdf;

extern void                                          fill_node(uint64_t p_df_structure, rdf::Node* p_node_parent);
extern std::array<std::array<std::string, 3>, 32>&   get_bitfield_bits(DF_Type);
extern std::string                                   to_hex(uint64_t p_dec);
extern std::tuple<int64_t, std::string, std::string> get_enum_decoded(const NodeEnum* p_node);

void DF_Model::set_root(NodeBase* p_node)
{
    beginResetModel();
    m_rootNode = p_node;
    endResetModel();
}


QModelIndex DF_Model::index(int p_row, int p_column, const QModelIndex& p_parent) const
{
    if (!m_rootNode || p_row < 0 || p_column < 0)
        return QModelIndex();
    NodeBase* parentNode = nodeFromIndex(p_parent);
    if (parentNode->m_node_type == NodeType::Simple)
        return QModelIndex();
    NodeBase* childNode = (static_cast<Node*>(parentNode))->m_children.at(p_row);

    return createIndex(p_row, p_column, childNode);
}

QModelIndex DF_Model::parent(const QModelIndex& p_child_index) const
{
    NodeBase* node = nodeFromIndex(p_child_index);
    if (!node)
        return QModelIndex();
    NodeBase* parentNode = node->m_parent;
    if (!parentNode)
        return QModelIndex();
    NodeBase* grandparentNode = parentNode->m_parent;
    if (!grandparentNode)
        return QModelIndex();
    if (grandparentNode->m_node_type == NodeType::Simple)
        return QModelIndex();
    Node* l_gp_node = static_cast<Node*>(grandparentNode);
    int row = l_gp_node->m_children.indexOf(parentNode);
    return createIndex(row, 0, parentNode);
}

int DF_Model::rowCount(const QModelIndex& p_parent) const
{
    if (p_parent.column() > 0)
        return 0;
    NodeBase* parentNode = nodeFromIndex(p_parent);
    if (!parentNode)
        return 0;
    if (parentNode->m_node_type == NodeType::Simple)
        return 0;
    auto l_parent = static_cast<Node*>(parentNode);
    return l_parent->m_children.count();
}


NodeBase* DF_Model::nodeFromIndex(const QModelIndex& p_index) const
{
    if (p_index.isValid())
    {
        return static_cast<NodeBase*>(p_index.internalPointer());
    }
    else
    {
        return m_rootNode;
    }
}

QString data_from_Name(const NodeBase* p_node)
{
    return QString::fromStdString(p_node->m_field_name);
}

QString data_from_Address(const rdf::NodeBase* p_node)
{
    const NodeBase* base    = dynamic_cast<const NodeBase*>(p_node);
    uint64_t        address = base->m_address;
    if (address == 0)
        return "N/A";
    std::string address_hex = to_hex(address);
    return QString::fromStdString(address_hex);
}

QString data_from_Comment(const NodeBase* p_node)
{
    if (p_node->m_rdf_type == RDF_Type::Enum)
    {
        auto enum_node    = dynamic_cast<const NodeEnum*>(p_node);
        auto enum_decoded = get_enum_decoded(enum_node);
        return QString::fromStdString(std::get<2>(enum_decoded));
    }
    return QString::fromStdString(p_node->m_comment);
}

QString data_from_Refers_to(const NodeBase* p_node)
{
    const NodeBase* base = dynamic_cast<const NodeBase*>(p_node);
    return QString::fromStdString(base->m_refers_to);
}

QVariant DF_Model::data(const QModelIndex& p_index, int p_role) const
{
    const NodeBase* node = nodeFromIndex(p_index);

    if ((p_index.column() == 0) && (p_role == Qt::DecorationRole))
    {
        if ((node->m_rdf_type == rdf::RDF_Type::uint8_t)
                || (node->m_rdf_type == rdf::RDF_Type::uint16_t)
                || (node->m_rdf_type == rdf::RDF_Type::uint32_t)
                || (node->m_rdf_type == rdf::RDF_Type::uint64_t)
                || (node->m_rdf_type == rdf::RDF_Type::int8_t)
                || (node->m_rdf_type == rdf::RDF_Type::int16_t)
                || (node->m_rdf_type == rdf::RDF_Type::int32_t)
                || (node->m_rdf_type == rdf::RDF_Type::int64_t)
                || (node->m_rdf_type == rdf::RDF_Type::Bool))
            return QPixmap(":/circle.png");

        if ((node->m_rdf_type == rdf::RDF_Type::Stl_string) ||
                (node->m_rdf_type == rdf::RDF_Type::Static_string) ||
                (node->m_rdf_type == rdf::RDF_Type::Ptr_string))
            return QPixmap(":/t2_small.png");

        if ((node->m_rdf_type == rdf::RDF_Type::Compound))
            return QPixmap(":/group.png");

        if (node->m_rdf_type == rdf::RDF_Type::Pointer)
            return QPixmap(":/cube.png");

        if (node->m_rdf_type == rdf::RDF_Type::Vector)
            return QPixmap(":/folder.png");

        if ((node->m_rdf_type == rdf::RDF_Type::Enum))
            return QPixmap(":/square.png");

        if ((node->m_rdf_type == rdf::RDF_Type::Bitfield))
            return QPixmap(":/stripes.png");
    }

    if (p_role != Qt::DisplayRole)
        return QVariant();

    if (!node)
        return QVariant();

    switch (p_index.column())
    {
        case 0 :
            return data_from_Name(node);      // Name
        case 1 :
            return data_from_Structure(node); // Structure type
        case 2 :
            return data_from_Type(node);      // Type
        case 3 :
            return data_from_Value(node);     // Value
        case 4 :
            return data_from_Address(node);   // Address
        case 5 :
            return QString::fromStdString(node->m_defined_in);  // refers-to
        case 6 :
            return data_from_Comment(node);   // Comment
        case 7 :
            return data_from_Refers_to(node); // refers-to            
        default:
            return QVariant();
    }
    return QVariant();
}

QVariant DF_Model::headerData(int p_section, Qt::Orientation p_orientation, int p_role) const
{
    if (p_orientation == Qt::Horizontal && p_role == Qt::DisplayRole)
    {
        switch (p_section)
        {
            case 0 :
                return tr("Name");
            case 1 :
                return tr("Structure");
            case 2 :
                return tr("Type");
            case 3 :
                return tr("Value");
            case 4 :
                return tr("Address");
            case 5 :
                return tr("Defined in");            
            case 6 :
                return tr("Comment");                
            case 7 :
                return tr("Refers-to");

            default:
                return QVariant();
        }
    }
    return QVariant();
}

int DF_Model::columnCount(const QModelIndex& /*p_parent*/) const
{
    return 8;
}

bool DF_Model::removeRows(int p_row, int p_count, const QModelIndex& /*p_parent*/)
{
    return false;
}

bool DF_Model::insertColumns(int p_column, int p_count, const QModelIndex& /*p_parent*/)
{
    return false;
}

bool DF_Model::removeColumns(int p_column, int p_count, const QModelIndex& /*p_parent*/)
{
    return false;
}

void DF_Model::update_node_path(NodeBase* p_source, NodeBase* p_dest)
{
//    QListIterator<NodeBase*> l_iterator(p_source->m_path);
//    while(l_iterator.hasNext())
//        p_dest->m_path.append(l_iterator.next());
}


bool DF_Model::insertRowsBitfield(const QModelIndex& p_parent)
{
    auto bitfield_node = dynamic_cast<NodeBitfield*>(nodeFromIndex(p_parent));
    if (bitfield_node->m_children.size() > 0)
        return false;

    auto pointer_bitfield = reinterpret_cast<int32_t*>(bitfield_node->m_address);
    auto bitfield_value   = *pointer_bitfield;
    if (bitfield_node->m_index_enum == DF_Type::None)
    {
        auto bitfield_data = get_bitfield_bits(bitfield_node->m_df_type);
        beginInsertRows(p_parent, 0, bitfield_data.size());
        unsigned int mask = 1;
        for (unsigned int i = 0; i < bitfield_data.size() ; i++)
        {
            std::string field_name = bitfield_data[i][1];
            if ((bitfield_value & mask) || (field_name.length() > 0))
            {
                auto* n_pve          = new NodeBitfieldEntry();
                n_pve->m_field_name  = field_name;
                if (field_name.length() == 0)
                {
                    if (i < 10)
                        n_pve->m_field_name = "[0" + std::to_string(i) + "]";
                    else
                        n_pve->m_field_name = "[" + std::to_string(i) + "]";
                }
                else
                {
                    if (i < 10)
                        n_pve->m_field_name = "[0" + std::to_string(i) + "] " +  field_name;
                    else
                        n_pve->m_field_name = "[" + std::to_string(i) + "] " +  field_name;
                }
                n_pve->m_rdf_type    = rdf::RDF_Type::Bool;
                n_pve->m_df_type     = rdf::DF_Type::Bool;
                n_pve->m_parent      = bitfield_node;
                n_pve->m_index       = i;
                n_pve->m_comment     = bitfield_data[i][2];
                n_pve->m_value       = bitfield_value & mask;
                n_pve->m_address     = bitfield_node->m_address;
                bitfield_node->m_children.append(n_pve);
            }
            mask = mask << 1;
        }
    }
//        // Update this node path
//        update_node_path(l_bitfield_node, n_pve);
    endInsertRows();
    return true;
}


bool DF_Model::insertRowsDFFlagArray(const QModelIndex& p_parent)
{
    auto df_flag_array_node = dynamic_cast<NodeDFFlagArray*>(nodeFromIndex(p_parent));
    if (df_flag_array_node->m_children.size() > 0)
        return false;

    uint8_t**  a                     = reinterpret_cast<uint8_t**>(df_flag_array_node->m_address);
    uint8_t*   pointer_df_flag_array = *a;
    // This is a hack
    NodeEnum ne;
    ne.m_base_type = DF_Type::int8_t;
    ne.m_df_type   = df_flag_array_node->m_index_enum;

    beginInsertRows(p_parent, 0, df_flag_array_node->m_size);

    unsigned int mask = 1;
    uint8_t bitfield_value = 0;
    for (unsigned int i = 0; i < df_flag_array_node->m_size ; i++)
    {
        ne.m_address   = reinterpret_cast<uint64_t>(&i);
        auto enum_data = get_enum_decoded(&ne);
        std::string field_name = std::get<1>(enum_data);
        if (i % 8 == 0)
            bitfield_value = *pointer_df_flag_array;
        if ((bitfield_value & mask) || (field_name.length() > 0))
        {
            auto* n_pve          = new NodeBitfieldEntry();
            n_pve->m_field_name  = field_name;
            if (field_name.length() == 0)
            {
                if (i < 10)
                    n_pve->m_field_name = "[0" + std::to_string(i) + "]";
                else
                    n_pve->m_field_name = "[" + std::to_string(i) + "]";
            }
            else
            {
                if (i < 10)
                    n_pve->m_field_name = "[0" + std::to_string(i) + "] " +  field_name;
                else
                    n_pve->m_field_name = "[" + std::to_string(i) + "] " +  field_name;
            }
            n_pve->m_rdf_type    = rdf::RDF_Type::Bool;
            n_pve->m_df_type     = rdf::DF_Type::Bool;
            n_pve->m_parent      = df_flag_array_node;
            n_pve->m_index       = i;
            n_pve->m_comment     = "";
            n_pve->m_value       = bitfield_value & mask;
            n_pve->m_address     = reinterpret_cast<uint64_t>(pointer_df_flag_array);
            df_flag_array_node->m_children.append(n_pve);
        }
        mask = mask << 1;
        if ((i+1) % 8 == 0)
        {
            pointer_df_flag_array++;
            mask = 1;
        }
    }
    endInsertRows();
    return true;
}


bool DF_Model::insertRowsCompound(const QModelIndex& p_parent, int p_num_rows)
{
    Node* l_node = dynamic_cast<Node*>(nodeFromIndex(p_parent));
    if (l_node->m_children.size() > 0)
        return false;

    beginInsertRows(p_parent, 0, p_num_rows);
    fill_node(l_node->m_address, l_node);
    endInsertRows();
    return true;
}

bool DF_Model::has_children_from_type( NodeBase* p_node) const
{
    if (p_node->is_root_node())
        return true;

    if (p_node->m_node_type == NodeType::BitfieldEntry)
        return true;

    switch (p_node->m_rdf_type)
    {
        case rdf::RDF_Type::None:
            return false;
        case rdf::RDF_Type::int64_t:
        case rdf::RDF_Type::uint64_t:
        case rdf::RDF_Type::int32_t:
        case rdf::RDF_Type::int16_t:
        case rdf::RDF_Type::uint32_t:
        case rdf::RDF_Type::uint16_t:
        case rdf::RDF_Type::uint8_t:
        case rdf::RDF_Type::int8_t:
            return !(p_node->m_refers_to.empty());
        case rdf::RDF_Type::Void:
            return false;
        case rdf::RDF_Type::Char:
            return false;
        case rdf::RDF_Type::Long:
            return false;
        case rdf::RDF_Type::Bool:
            return false;
        case rdf::RDF_Type::Stl_string:
            return false;
        case rdf::RDF_Type::Static_string:
            return false;
        case rdf::RDF_Type::Ptr_string:
            return false;
        case rdf::RDF_Type::Padding:
            return false;
        case rdf::RDF_Type::S_float:
            return false;
        case rdf::RDF_Type::D_float:
            return false;
        case rdf::RDF_Type::S_double:
            return false;
        case rdf::RDF_Type::Pointer:
            break;
        case rdf::RDF_Type::Array:
            return true;
        case rdf::RDF_Type::DFArray:
            return true;            
        case rdf::RDF_Type::Vector:
            break;
        case rdf::RDF_Type::Bitfield:
            return true;
        case rdf::RDF_Type::Enum:
            return false;
        case rdf::RDF_Type::Compound:
            return true;
        case rdf::RDF_Type::Struct:
            return true;
        case rdf::RDF_Type::AnonymousCompound:
            return true;
        case rdf::RDF_Type::Class:
            return true;
        case rdf::RDF_Type::Union:
            return true;
        case rdf::RDF_Type::AnonymousUnion:
            return true;
        case rdf::RDF_Type::DFLinkedList:
            return true;
        case rdf::RDF_Type::DFFlagArray:
            return true;

        default:
            break;
    }

    if (p_node->m_rdf_type == rdf::RDF_Type::Pointer)
    {
        NodePointer* l_pointer = dynamic_cast<NodePointer*>(p_node);
        if (l_pointer->m_df_type == rdf::DF_Type::Void)
            return false;
        if (l_pointer->m_address == 0)
            return false;
        auto address = reinterpret_cast<uint64_t*>(l_pointer->m_address);
        if (*address != 0)
            return true;
        return false;
    }

    if (p_node->m_rdf_type == rdf::RDF_Type::Vector)
    {
        NodeVector* l_node = dynamic_cast<NodeVector*>(p_node);
        if (get_vector_size(l_node) > 0)
            return true;
        if ((l_node->m_children.size() > 1) && (l_node->m_children[0]->m_node_type != NodeType::Dummy))
            return true;
    }
    return false;
}

bool DF_Model::hasChildren(const QModelIndex& p_parent) const
{
    NodeBase* node = nodeFromIndex(p_parent);
    return has_children_from_type(node);
}

//NodeBase* locate_aux(rdf::RDFBase* p_object, Node* p_node)
//{
//    // Simple objects can't be opened in new windows
//    if (is_simple_type(p_node))
//        return nullptr;
//    if (is_string(p_node))
//        return nullptr;

//    // Check if the node is the one
//    if (p_node->m_rdf_object == p_object)
//        return p_node;

//    // If not, check its children
//    QListIterator<NodeBase*> l_iterator(p_node->m_children);
//    while (l_iterator.hasNext())
//    {
//        auto& l_child = l_iterator.next();
//        if (is_simple_type(l_child))
//            continue;
//        if (is_string(l_child))
//            continue;
//        NodeBase* l_result = locate_aux(p_object, dynamic_cast<Node*>(l_child));
//        if (l_result != nullptr)
//            return l_result;
//    }
//    // Not found in the children
//return nullptr;
//}


//NodeBase* DF_Model::locate(rdf::RDFBase* p_object)
//{
//    return locate_aux(p_object, m_rootNode);
//}



void DF_Model::insert_child_nodes(NodeBase* p_node, const QModelIndex& p_index)
{
    switch (p_node->m_rdf_type)
    {
        case rdf::RDF_Type::Vector:
            insertRowsVector(p_index);
            break;
        case rdf::RDF_Type::Pointer:
            insertRowsPointer(p_index);
            break;
        case rdf::RDF_Type::Array:
            insertRowsArray(p_index);
            break;
        case rdf::RDF_Type::DFArray:
            insertRowsDFArray(p_index);
            break;
        case rdf::RDF_Type::Class:
        case rdf::RDF_Type::Struct:
        case rdf::RDF_Type::Compound:
        case rdf::RDF_Type::Union:
        case rdf::RDF_Type::AnonymousUnion:
        case rdf::RDF_Type::DFLinkedList:
            insertRowsCompound(p_index, 5);
            break;
        case rdf::RDF_Type::Bitfield:
            insertRowsBitfield(p_index);
            break;
        case rdf::RDF_Type::DFFlagArray:
            insertRowsDFFlagArray(p_index);
        default:
            break;
    }
}

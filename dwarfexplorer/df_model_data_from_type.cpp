#include "df_model.h"

using namespace rdf;


QString DF_Model::data_from_Type(const NodeBase* p_node) const
{
    auto type = p_node->m_used_type;

    if (p_node->m_rdf_type == rdf::RDF_Type::Enum)
    {
        auto node_enum = dynamic_cast<const NodeEnum*>(p_node);
        type = node_enum->m_enum_type;
    }

    if (p_node->m_df_type == rdf::DF_Type::Void)
        return type;

    if (p_node->m_df_type == rdf::DF_Type::Stl_string)
        type = "std::string";

    if (p_node->m_node_type == NodeType::NodeVector)
    {
        auto node_vector = dynamic_cast<const NodeVector*>(p_node);
        auto addornements = node_vector->m_addornements;
        auto qaddornements = QString::fromStdString(addornements.substr(1,100));
        type.append(qaddornements);
    }
    return type;
}

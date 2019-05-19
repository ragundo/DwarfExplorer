#include "../df_model.h"

using namespace rdf;


std::string& replace_string(std::string& s, const std::string& from, const std::string& to)
{
    if(!from.empty())
        for(size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
            s.replace(pos, from.size(), to);
    return s;
}

QString DF_Model::data_from_Type(const NodeBase* p_node) const
{
    //auto type = p_node->m_used_type;
    // Get df_type translated to string
    std::string type = DF_Type_to_string(p_node->m_df_type);

    if (type == "Void")
       type = "void*";

    if (p_node->m_rdf_type == rdf::RDF_Type::Enum)
    {
        auto node_enum = dynamic_cast<const NodeEnum*>(p_node);
        return QString::fromStdString(node_enum->m_enum_type);
    }


    if (p_node->m_df_type == rdf::DF_Type::Padding)
        return "";

    if (p_node->m_df_type == rdf::DF_Type::Static_string)
        return "";

    if (p_node->m_df_type == rdf::DF_Type::Stl_string)
        return "std::string";

    if (p_node->m_node_type == NodeType::Vector)
    {
        auto node_vector   = dynamic_cast<const NodeVector*>(p_node);
        auto addornements  = node_vector->m_addornements;
        auto qaddornements = addornements.substr(1,100);
        return QString::fromStdString(type.append(qaddornements));
    }

    if (p_node->m_rdf_type == rdf::RDF_Type::AnonymousCompound)
        return "";

    if (p_node->m_rdf_type == rdf::RDF_Type::AnonymousUnion)
        return "";

    if (type.find("__") != std::string::npos)
        return QString::fromStdString(replace_string(type, "__", "::"));
    return QString::fromStdString(type);
}

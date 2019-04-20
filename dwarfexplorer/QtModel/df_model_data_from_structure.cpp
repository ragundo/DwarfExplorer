#include "../df_model.h"

using namespace rdf;
namespace
{
    bool is_vector(const NodeBase* l_node)
    {
        if (l_node->m_rdf_type == rdf::RDF_Type::Vector)
            return true;
        return false;
    }

    bool is_array(const NodeBase* l_node)
    {
        if (l_node->m_rdf_type == rdf::RDF_Type::Array)
            return true;
        return false;
    }

    bool is_pointer(const NodeBase* l_node)
    {
        if (l_node->m_rdf_type == rdf::RDF_Type::Pointer)
            return true;
        return false;
    }
}


std::string rec_array_type(std::string p_addornements)
{
    std::string result;
    if (p_addornements[0] == '*')
    {
        result.append("*");
        return result.append(rec_array_type(p_addornements.substr(1,512)));
    }
    if (p_addornements[0] == 'v')
    {
        result.append("Vector");
        return result.append(rec_array_type(p_addornements.substr(1,512)));
    }
    if (p_addornements[0] == '[')
    {
        std::size_t index = 1;
        while (std::isdigit(p_addornements[index++]));
        std::string array_size = p_addornements.substr(1, index-2);
        result.append("[").append(array_size).append("]");
        if (index >= p_addornements.size())
            return result;
        std::string rest = p_addornements.substr(index-1,512);
        return result.append(rec_array_type(rest));
    }
    return "";
}

QString get_array_expresion(const NodeBase* p_node)
{
    QString result = "Array";
    auto node_array = dynamic_cast<const NodeArray*>(p_node);
    std::string addornements = node_array->m_addornements;
    auto size = QString::fromStdString(rec_array_type(addornements));
    return result + size;
}

QString DF_Model::data_from_Structure(const NodeBase* p_node) const
{
    if (is_vector(p_node))
        return "Vector";

    if (is_array(p_node))
        return get_array_expresion(p_node);

    if (is_pointer(p_node))
        return "Pointer";

    if (p_node->m_rdf_type == rdf::RDF_Type::Compound)
        return "Compound";

    if (p_node->m_rdf_type == rdf::RDF_Type::Class)
        return "Class";

    if (p_node->m_rdf_type == rdf::RDF_Type::Struct)
        return "Struct";

    if (p_node->m_rdf_type == rdf::RDF_Type::AnonymousCompound)
        return "Anonymous Struct";

    if (p_node->m_rdf_type == rdf::RDF_Type::Enum)
        return "Enum";

    if (p_node->m_rdf_type == rdf::RDF_Type::Bitfield)
        return "Bitfield";

    if (p_node->m_rdf_type == rdf::RDF_Type::Union)
        return "Union";

    if (p_node->m_rdf_type == rdf::RDF_Type::AnonymousUnion)
        return "Anonymous Union";

    if (is_string(p_node))
        return "String";

    if (p_node->m_rdf_type == rdf::RDF_Type::Padding)
        return "Padding";

//    if (p_node->m_rdf_type == rdf::RDF_Type::DFArray)
//        return "DFArray";

    if (is_simple_type(p_node))
        return "";


    return  "Unknown";
}

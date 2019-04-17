#include "df_model.h"
#include "node.h"

using namespace rdf;



    bool DF_Model::is_simple_type(const NodeBase* l_node) const
    {
        if ((l_node->m_rdf_type == rdf::RDF_Type::Bool) ||
                (l_node->m_rdf_type == rdf::RDF_Type::int8_t) ||
                (l_node->m_rdf_type == rdf::RDF_Type::int16_t) ||
                (l_node->m_rdf_type == rdf::RDF_Type::int32_t) ||
                (l_node->m_rdf_type == rdf::RDF_Type::int64_t) ||
                (l_node->m_rdf_type == rdf::RDF_Type::uint8_t) ||
                (l_node->m_rdf_type == rdf::RDF_Type::uint16_t) ||
                (l_node->m_rdf_type == rdf::RDF_Type::uint32_t) ||
                (l_node->m_rdf_type == rdf::RDF_Type::uint64_t) ||
                (l_node->m_rdf_type == rdf::RDF_Type::Long) ||
                (l_node->m_rdf_type == rdf::RDF_Type::Char) ||
                (l_node->m_rdf_type == rdf::RDF_Type::S_float) ||
                (l_node->m_rdf_type == rdf::RDF_Type::D_float) ||
                (l_node->m_rdf_type == rdf::RDF_Type::Void))
            return true;
        return false;
    }

    bool DF_Model::is_simple_type(rdf::RDF_Type p_type) const
    {
        if ((p_type == rdf::RDF_Type::Bool) ||
                (p_type == rdf::RDF_Type::int8_t) ||
                (p_type == rdf::RDF_Type::int16_t) ||
                (p_type == rdf::RDF_Type::int32_t) ||
                (p_type == rdf::RDF_Type::int64_t) ||
                (p_type == rdf::RDF_Type::uint8_t) ||
                (p_type == rdf::RDF_Type::uint16_t) ||
                (p_type == rdf::RDF_Type::uint32_t) ||
                (p_type == rdf::RDF_Type::uint64_t) ||
                (p_type == rdf::RDF_Type::Long) ||
                (p_type == rdf::RDF_Type::Char) ||
                (p_type == rdf::RDF_Type::S_float) ||
                (p_type == rdf::RDF_Type::D_float) ||
                (p_type == rdf::RDF_Type::Void))
            return true;
        return false;
    }


    bool DF_Model::is_simple_type(rdf::DF_Type p_type) const
    {
        if ((p_type == rdf::DF_Type::Bool) ||
                (p_type == rdf::DF_Type::int8_t) ||
                (p_type == rdf::DF_Type::int16_t) ||
                (p_type == rdf::DF_Type::int32_t) ||
                (p_type == rdf::DF_Type::int64_t) ||
                (p_type == rdf::DF_Type::uint8_t) ||
                (p_type == rdf::DF_Type::uint16_t) ||
                (p_type == rdf::DF_Type::uint32_t) ||
                (p_type == rdf::DF_Type::uint64_t) ||
                (p_type == rdf::DF_Type::Long) ||
                (p_type == rdf::DF_Type::Char) ||
                (p_type == rdf::DF_Type::S_float) ||
                (p_type == rdf::DF_Type::D_float) ||
                (p_type == rdf::DF_Type::Void))
            return true;
        return false;
    }


    bool DF_Model::is_string(const NodeBase* l_node) const
    {
        if ((l_node->m_rdf_type == rdf::RDF_Type::Stl_string) ||
                (l_node->m_rdf_type == rdf::RDF_Type::Static_string) ||
                (l_node->m_rdf_type == rdf::RDF_Type::Ptr_string))
            return true;
        return false;
    }


std::string DF_Model::to_hex(uint64_t p_dec) const
{
    if (p_dec == 0)
        return "0x0";
    std::string l_answer = "";
    uint64_t l_rem;
    while (p_dec > 0)
    {
        l_rem = p_dec % 16;
        switch (l_rem)
        {
            case 0:
                l_answer = "0" + l_answer;
                break;
            case 1:
                l_answer = "1" + l_answer;
                break;
            case 2:
                l_answer = "2" + l_answer;
                break;
            case 3:
                l_answer = "3" + l_answer;
                break;
            case 4:
                l_answer = "4" + l_answer;
                break;
            case 5:
                l_answer = "5" + l_answer;
                break;
            case 6:
                l_answer = "6" + l_answer;
                break;
            case 7:
                l_answer = "7" + l_answer;
                break;
            case 8:
                l_answer = "8" + l_answer;
                break;
            case 9:
                l_answer = "9" + l_answer;
                break;
            case 10:
                l_answer = "A" + l_answer;
                break;
            case 11:
                l_answer = "B" + l_answer;
                break;
            case 12:
                l_answer = "C" + l_answer;
                break;
            case 13:
                l_answer = "D" + l_answer;
                break;
            case 14:
                l_answer = "E" + l_answer;
                break;
            case 15:
                l_answer = "F" + l_answer;
                break;
        }
        p_dec = p_dec / 16;

    }
    return "0x" + l_answer;
}

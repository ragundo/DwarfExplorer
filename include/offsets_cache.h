#ifndef OFFSETS_CACHE_H
#define OFFSETS_CACHE_H
#include <cstdint>
#include <string>
#include <map>
#include "DF_Types.h"
#include <memory>


namespace rdf
{
    struct OffsetTable
    {
        std::map<std::string, std::size_t> m_offsets;
    };

    class OffsetsCache
    {
    protected:
        static std::map<DF_Type, OffsetTable> m_df_types_offset_table;
    public:
        uint64_t static get_offset(DF_Type, const std::string& p_field);
    };
}
#endif // OFFSETS_CACHE_H

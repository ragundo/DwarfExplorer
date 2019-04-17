#ifndef OFFSETS_CACHE_H
#define OFFSETS_CACHE_H
#include <cstdint>
#include <string>
#include <unordered_map>
#include "DF_Types.h"
#include <memory>


namespace rdf
{
    struct OffsetTable
    {
        std::unordered_map<std::string, std::size_t> m_offsets;
    };

    class OffsetsCache
    {
    protected:
        static std::unordered_map<DF_Type, OffsetTable> m_df_types_offset_table;
    public:
        uint64_t static get_offset(DF_Type, std::string& p_field);
    };
}
#endif // OFFSETS_CACHE_H

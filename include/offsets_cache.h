#ifndef OFFSETS_CACHE_H
#define OFFSETS_CACHE_H
#include "DF_Types.h"
#include <cstdint>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>

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
    uint64_t static get_offset(DF_Type, const std::string& p_field);
};
} // namespace rdf
#endif // OFFSETS_CACHE_H

#ifndef RDF_TYPES_H
#define RDF_TYPES_H

#include <string>
namespace rdf
{
        enum class RDF_Type
        {
                None = 0,
                int64_t,
                uint64_t,
                int32_t,
                int16_t,
                uint32_t,
                uint16_t,
                uint8_t,
                int8_t,
                Void,
                Char,
                Long,
                Bool,
                Stl_string,
                Static_string,
                Ptr_string,
                Ptr_char,
                S_float,
                D_float,
                S_double,
                Padding,
                Stl_fstream,
                Compound,
                Class,
                Struct,
                AnonymousCompound,
                Union,
                AnonymousUnion,
                Bitfield,
                Enum,
                Array,
                Vector,
                Pointer,
                DFLinkedList,
                DFFlagArray,
                DFArray
        };

}
#endif // RDF_TYPES_H

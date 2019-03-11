#pragma once

#include "daScript/simulate/simulate.h"

namespace das
{
    #define HASH_EMPTY32    0
    #define HASH_KILLED32    1

    // ideas from http://isthe.com/chongo/tech/comp/fnv/

    __forceinline uint32_t hash_block32(const uint8_t * block, uint32_t size) {
        const uint32_t fnv_prime = 16777619;
        const uint32_t fnv_bias = 2166136261;
        uint32_t offset_basis = fnv_bias;
        for ( ; size >=4; size-=4 ) {
            offset_basis = ( offset_basis ^ *block++ ) * fnv_prime;
            offset_basis = ( offset_basis ^ *block++ ) * fnv_prime;
            offset_basis = ( offset_basis ^ *block++ ) * fnv_prime;
            offset_basis = ( offset_basis ^ *block++ ) * fnv_prime;
        }
        if (size & 2u) {
            offset_basis = (offset_basis ^ *block++) * fnv_prime;
            offset_basis = (offset_basis ^ *block++) * fnv_prime;
        }
        if (size & 1u) {
            offset_basis = (offset_basis ^ *block++) * fnv_prime;
        }
        if (offset_basis <= HASH_KILLED32) {
            return fnv_prime;
        }
        return offset_basis;
    }

    __forceinline uint32_t hash_blockz32(const uint8_t * block) {
        const uint32_t fnv_prime = 16777619;
        const uint32_t fnv_bias = 2166136261;
        uint32_t offset_basis = fnv_bias;
        for (; *block; block++) {
            offset_basis = ( offset_basis ^ *block ) * fnv_prime;
        }
        if (offset_basis <= HASH_KILLED32) {
            return fnv_prime;
        }
        return offset_basis;
    }

    class HashBlock {
        const uint32_t fnv_prime = 16777619;
        uint32_t offset_basis = 2166136261;
    public:
        __forceinline void write ( const void * pb, uint32_t size ) {
            const uint8_t * block = (const uint8_t *) pb;
            while ( size-- ) {
                offset_basis = ( offset_basis ^ *block++ ) * fnv_prime;
            }
        }
        __forceinline void write ( const void * pb ) {
            const uint8_t * block = (const uint8_t *) pb;
            for (; *block; block++) {
                offset_basis = ( offset_basis ^ *block ) * fnv_prime;
            }
        }
        __forceinline uint32_t getHash() const  {
            return (offset_basis <= HASH_KILLED32) ? fnv_prime : offset_basis;
        }
    };

    __forceinline uint32_t hash_function ( const void * x, size_t size ) {
        return hash_block32((uint8_t *)x, uint32_t(size));
    }

    __forceinline uint32_t stringLength ( const char * str ) {//should be non-null
        if ( __context__->heap.isFastHeapPtr(str) ) {
            auto header = (StringHeader *) ( str - sizeof(StringHeader) );
            return header->length;
        } else {
            return uint32_t(strlen(str));
        }
    }
    __forceinline uint32_t stringLengthSafe ( const char * str ) {//accepts nullptr
        if ( __context__->heap.isFastHeapPtr(str) ) {
            auto header = (StringHeader *) ( str - sizeof(StringHeader) );
            return header->length;
        } else {
            return str ? uint32_t(strlen(str)) : 0;
        }
    }

    template <typename TT>
    __forceinline uint32_t hash_function ( const TT x ) {
        uint32_t res = hash_block32((const uint8_t *)&x, sizeof(x));
        if (res <= HASH_KILLED32) {
            return 16777619;
        }
        return res;
    }

    template <>
    __forceinline uint32_t hash_function ( char * str ) {
        if ( __context__->heap.isFastHeapPtr(str) ) {
            auto header = (StringHeader *) ( str - sizeof(StringHeader) );
            auto hh = header->hash;
            if ( !hh ) {
                header->hash = hh = hash_block32((uint8_t *)str, header->length);
            }
            return hh;
        } else {
            return hash_blockz32((uint8_t *)str);
        }
    }

    uint32_t hash_value ( void * pX, TypeInfo * info );
    uint32_t hash_value ( vec4f value, TypeInfo * info );
    uint32_t hash_value ( TypeInfo * info );
    uint32_t hash_value ( StructInfo * info );
    uint32_t hash_value ( EnumInfo * info );
}


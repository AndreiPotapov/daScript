#include "daScript/misc/platform.h"


#include "daScript/ast/ast.h"
#include "daScript/simulate/hash.h"
#include "daScript/simulate/runtime_string.h"
#include "daScript/simulate/data_walker.h"

namespace das
{
    struct HashDataWalker : DataWalker {
        const uint32_t fnv_prime = 16777619;
        uint32_t fnv_bias = 2166136261;
        template <typename TT>
        __forceinline void update ( TT & data ) {
            uint32_t size = sizeof(TT);
            uint8_t * block = (uint8_t *) & data;
            while ( size-- ) {
                fnv_bias = ( fnv_bias ^ *block++ ) * fnv_prime;
            }
        }
        __forceinline void updateString ( char * & str ) {
            uint8_t * block = (uint8_t *) str;
            while ( *block ) {
                fnv_bias = ( fnv_bias ^ *block++ ) * fnv_prime;
            }
        }
        __forceinline uint32_t getHash ( void ) const {
            if (fnv_bias <= HASH_KILLED32) {
                return fnv_prime;
            }
            return fnv_bias;
        }
    // data types
        virtual void Bool ( bool & t )          { update(t); }
        virtual void Int64 ( int64_t & t )      { update(t); }
        virtual void UInt64 ( uint64_t & t )    { update(t); }
        virtual void Float ( float & t )        { update(t); }
        virtual void Int ( int32_t & t )        { update(t); }
        virtual void UInt ( uint32_t & t )      { update(t); }
        virtual void Int2 ( int2 & t )          { update(t); }
        virtual void Int3 ( int3 & t )          { update(t); }
        virtual void Int4 ( int4 & t )          { update(t); }
        virtual void UInt2 ( uint2 & t )        { update(t); }
        virtual void UInt3 ( uint3 & t )        { update(t); }
        virtual void UInt4 ( uint4 & t )        { update(t); }
        virtual void Float2 ( float2 & t )      { update(t); }
        virtual void Float3 ( float3 & t )      { update(t); }
        virtual void Float4 ( float4 & t )      { update(t); }
        virtual void Range ( range & t )        { update(t); }
        virtual void URange ( urange & t )      { update(t); }
        virtual void String ( char * & t )      { updateString(t); }
    // unsupported
        virtual void WalkIterator ( struct Iterator * ) { error("HASH, not expecting iterator"); }
        virtual void WalkBlock ( Block * )              { error("HASH, not expecting block"); }
    };

    uint32_t hash_value ( void * pX, TypeInfo * info ) {
        HashDataWalker walker;
        walker.walk((char*)pX,info);
        return walker.getHash();
    }

    uint32_t hash_value ( vec4f value, TypeInfo * info ) {
        HashDataWalker walker;
        walker.walk(value,info);
        return walker.getHash();
    }

    void hash_value ( HashBlock & block, TypeInfo * info );

    void hash_value ( HashBlock & block, StructInfo * si ) {
        block.write(si->name);
        for ( uint32_t i=0; i!=si->fieldsSize; ++i ) {
            auto vi = si->fields[i];
            block.write(vi->name);
            block.write(&vi->offset, sizeof(uint32_t));
        }
        block.write(&si->fieldsSize, sizeof(uint32_t));
        block.write(&si->size, sizeof(uint32_t));
    }

    void hash_value ( HashBlock & block, EnumInfo * ei ) {
        block.write(ei->name);
        for ( uint32_t i=0; i!=ei->totalValues; ++i ) {
            auto ev = ei->values[i];
            block.write(ev->name);
            block.write(&ev->value, sizeof(int32_t));
        }
        block.write(&ei->totalValues, sizeof(uint32_t));
    }

    void hash_value ( HashBlock & block, TypeInfo * info ) {
        block.write(&info->type, sizeof(Type));
        if ( info->structType ) {
            hash_value(block, info->structType);
        }
        if ( info->enumType ) {
            hash_value(block, info->enumType);
        }
        if ( info->annotation ) {
            auto mangledName = info->annotation->getMangledName();
            block.write(mangledName.c_str());
        }
        if ( info->firstType ) {
            hash_value(block, info->firstType);
        }
        if ( info->secondType ) {
            hash_value(block, info->secondType);
        }
        block.write(&info->dimSize, sizeof(uint32_t));
        block.write(info->dim, info->dimSize*sizeof(uint32_t));
        block.write(&info->flags, sizeof(uint32_t));
    }

    uint32_t hash_value ( TypeInfo * info ) {
        HashBlock block;
        hash_value(block, info);
        return block.getHash();
    }

    uint32_t hash_value ( StructInfo * info ) {
        HashBlock block;
        hash_value(block, info);
        return block.getHash();
    }

    uint32_t hash_value ( EnumInfo * info ) {
        HashBlock block;
        hash_value(block, info);
        return block.getHash();
    }
}


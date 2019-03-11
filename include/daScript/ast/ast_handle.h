#pragma once

#include "daScript/ast/ast.h"

namespace das
{
    #define DAS_BIND_MANAGED_FIELD(FIELDNAME)   DAS_BIND_FIELD(ManagedType,FIELDNAME)
    #define DAS_BIND_MANAGED_PROP(FIELDNAME)    DAS_BIND_PROP(ManagedType,FIELDNAME)

    struct DasStringTypeAnnotation : TypeAnnotation {
        DasStringTypeAnnotation() : TypeAnnotation("das_string") {}
        virtual bool rtti_isHandledTypeAnnotation() const override { return true; }
        virtual bool isRefType() const override { return true; }
        virtual bool isLocal() const override { return false; }
        virtual void walk ( DataWalker & dw, void * p ) override {
            auto pstr = (string *)p;
            if (dw.reading) {
                char * pss = nullptr;
                dw.String(pss);
                *pstr = pss;
            } else {
                char * pss = (char *) pstr->c_str();
                dw.String(pss);
            }
        }
    };

    template <typename OT>
    struct ManagedStructureAlignof {static constexpr size_t alignment = alignof(OT); } ;//we use due to MSVC inability to work with abstarct classes

    template <typename OT, bool canNewAndDelete = true>
    struct ManagedStructureAnnotation ;

    template <typename OT>
    struct ManagedStructureAnnotation<OT,false>  : TypeAnnotation {
        typedef OT ManagedType;
        enum class FactoryNodeType {
            getField
        ,   getFieldR2V
        ,   safeGetField
        ,   safeGetFieldPtr
        };
        struct StructureField {
            string      name;
            TypeDeclPtr decl;
            uint32_t    offset;
            function<SimNode * (FactoryNodeType,const LineInfo &, const ExpressionPtr &)>   factory;
        };
        ManagedStructureAnnotation (const string & n, ModuleLibrary & ml )
            : TypeAnnotation(n), mlib(&ml) { }
        virtual void seal( Module * m ) override {
            TypeAnnotation::seal(m);
            mlib = nullptr;
        }
        virtual bool rtti_isHandledTypeAnnotation() const override { return true; }
        virtual size_t getSizeOf() const override { return sizeof(ManagedType); }
        virtual size_t getAlignOf() const override { return ManagedStructureAlignof<ManagedType>::alignment; }
        virtual bool isRefType() const override { return true; }
        virtual bool isLocal() const override { return true; }
        virtual TypeDeclPtr makeFieldType ( const string & na ) const override {
            auto it = fields.find(na);
            if ( it!=fields.end() ) {
                auto t = make_shared<TypeDecl>(*it->second.decl);
                if ( it->second.offset != -1U ) {
                    t->ref = true;
                }
                return t;
            } else {
                return nullptr;
            }
        }
        virtual TypeDeclPtr makeSafeFieldType ( const string & na ) const override {
            auto it = fields.find(na);
            if ( it!=fields.end() && it->second.offset!=-1U ) {
                return make_shared<TypeDecl>(*it->second.decl);
            } else {
                return nullptr;
            }
        }
        virtual SimNode * simulateGetField ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            auto it = fields.find(na);
            if ( it!=fields.end() ) {
                return it->second.factory(FactoryNodeType::getField,at,value);
            } else {
                return nullptr;
            }
        }
        virtual SimNode * simulateGetFieldR2V ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            auto it = fields.find(na);
            if ( it!=fields.end() ) {
                auto itT = it->second.decl;
                return it->second.factory(FactoryNodeType::getFieldR2V,at,value);
            } else {
                return nullptr;
            }
        }
        virtual SimNode * simulateSafeGetField ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            auto it = fields.find(na);
            if ( it!=fields.end() ) {
                return it->second.factory(FactoryNodeType::safeGetField,at,value);
            } else {
                return nullptr;
            }
        };
        virtual SimNode * simulateSafeGetFieldPtr ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            auto it = fields.find(na);
            if ( it!=fields.end() ) {
                return it->second.factory(FactoryNodeType::safeGetFieldPtr,at,value);
            } else {
                return nullptr;
            }
        };
        template <typename FunT, FunT PROP>
        void addProperty ( const string & na ) {
            auto & field = fields[na];
            if ( field.decl ) {
                DAS_FATAL_LOG("structure field %s already exist in structure %s\n", na.c_str(), name.c_str() );
                DAS_FATAL_ERROR;
            }
            using resultType = decltype((((ManagedType *)0)->*PROP)());
            field.decl = makeType<resultType>(*mlib);
            field.offset = -1U;
            field.factory = [](FactoryNodeType nt, const LineInfo & at, const ExpressionPtr & value) -> SimNode * {
                switch ( nt ) {
                    case FactoryNodeType::getField:
                        return __context__->code->makeNode<SimNode_Property<ManagedType,FunT,PROP,false>>(at, value->simulate());
                    case FactoryNodeType::safeGetField:
                    case FactoryNodeType::safeGetFieldPtr:
                    case FactoryNodeType::getFieldR2V:
                        DAS_ASSERTF(0, "property requested property type, which is meaningless for the non-ref"
                                    "we should not be here, since property can't have ref type"
                                    "daScript compiler will later report missing node error");
                    default:
                        return nullptr;
                }
            };
        }
        void addFieldEx ( const string & na, off_t offset, TypeDeclPtr pT ) {
            auto & field = fields[na];
            if ( field.decl ) {
                DAS_FATAL_LOG("structure field %s already exist in structure %s\n", na.c_str(), name.c_str() );
                DAS_FATAL_ERROR;
            }
            field.decl = pT;
            field.offset = offset;
            auto baseType = field.decl->baseType;
            field.factory = [offset,baseType](FactoryNodeType nt,const LineInfo & at, const ExpressionPtr & value) -> SimNode * {
                if ( !value->type->isPointer() ) {
                    if ( nt==FactoryNodeType::getField || nt==FactoryNodeType::getFieldR2V ) {
                        auto r2vType = (nt==FactoryNodeType::getField) ? Type::none : baseType;
                        auto tnode = value->trySimulate(offset, r2vType);
                        if ( tnode ) {
                            return tnode;
                        }
                    }
                }
                auto simV = value->simulate();
                switch ( nt ) {
                    case FactoryNodeType::getField:
                        return __context__->code->makeNode<SimNode_FieldDeref>(at,simV,offset);
                    case FactoryNodeType::getFieldR2V:
                        return __context__->code->makeValueNode<SimNode_FieldDerefR2V>(baseType,at,simV,offset);
                    case FactoryNodeType::safeGetField:
                        return __context__->code->makeNode<SimNode_SafeFieldDeref>(at,simV,offset);
                    case FactoryNodeType::safeGetFieldPtr:
                        return __context__->code->makeNode<SimNode_SafeFieldDerefPtr>(at,simV,offset);
                    default:
                        return nullptr;
                }
            };
        }
        template <typename TT, off_t off>
        __forceinline void addField ( const string & na ) {
            addFieldEx ( na, off, makeType<TT>(*mlib) );
        }
        virtual void walk ( DataWalker & walker, void * data ) override {
            if ( !sti ) {
                auto debugInfo = helpA.debugInfo;
                sti = debugInfo->template makeNode<StructInfo>();
                sti->name = debugInfo->allocateName(name);
                // count fields
                sti->fieldsSize = 0;
                for ( auto & fi : fields ) {
                    auto & var = fi.second;
                    if ( var.offset != -1U ) {
                        sti->fieldsSize ++;
                    }
                }
                // and allocate
                sti->size = (uint32_t) getSizeOf();
                sti->fields = (VarInfo **) debugInfo->allocate( sizeof(VarInfo *) * sti->fieldsSize );
                int i = 0;
                for ( auto & fi : fields ) {
                    auto & var = fi.second;
                    if ( var.offset != -1U ) {
                        VarInfo * vi = debugInfo->template makeNode<VarInfo>();
                        helpA.makeTypeInfo(vi, var.decl);
                        vi->name = debugInfo->allocateName(fi.first);
                        vi->offset = var.offset;
                        sti->fields[i++] = vi;
                    }
                }
            }
            walker.walk_struct((char *)data, sti);
        }
        map<string,StructureField> fields;
        DebugInfoHelper            helpA;
        StructInfo *               sti = nullptr;
        ModuleLibrary *            mlib = nullptr;
    };

    template <typename OT>
    struct ManagedStructureAnnotation<OT,true> : ManagedStructureAnnotation<OT,false> {
        typedef OT ManagedType;
        ManagedStructureAnnotation (const string & n, ModuleLibrary & ml )
            : ManagedStructureAnnotation<OT,false>(n,ml) { }
        virtual bool canNew() const override { return true; }
        virtual bool canDeletePtr() const override { return true; }
        virtual SimNode * simulateGetNew ( const LineInfo & at ) const override {
            return __context__->code->makeNode<SimNode_NewHandle<ManagedType>>(at);
        }
        virtual SimNode * simulateDeletePtr ( const LineInfo & at, SimNode * sube, uint32_t count ) const override {
            return __context__->code->makeNode<SimNode_DeleteHandlePtr<ManagedType>>(at,sube,count);
        }
    };

    template <typename OT, bool r2v=false>
    struct ManagedVectorAnnotation;

    template <typename OT>
    struct ManagedVectorAnnotation<OT,false> : TypeAnnotation {
        typedef vector<OT> VectorType;
        struct SimNode_VectorLength : SimNode {
            DAS_INT_NODE;
            SimNode_VectorLength ( const LineInfo & at, SimNode * rv )
                : SimNode(at), value(rv) {}
            __forceinline int32_t compute ( ) {
                auto pValue = (VectorType *) value->evalPtr();
                return int32_t(pValue->size());
            }
            SimNode * value;
        };
        struct SimNode_AtStdVector : SimNode_At {
            DAS_PTR_NODE;
            SimNode_AtStdVector ( const LineInfo & at, SimNode * rv, SimNode * idx, uint32_t ofs )
                : SimNode_At(at, rv, idx, 0, ofs, 0) {}
            __forceinline char * compute ( ) {
                auto pValue = (VectorType *) value->evalPtr();
                uint32_t idx = cast<uint32_t>::to(index->eval());
                if ( idx >= pValue->size() ) {
                    __context__->throw_error_at(debugInfo,"std::vector index out of range");
                    return nullptr;
                } else {
                    return ((char *)(pValue->data() + idx)) + offset;
                }
            }
        };
        struct VectorIterator : Iterator {
            virtual bool first ( IteratorContext & itc ) override {
                vec4f ll = source->eval();
                VectorType * pArray = cast<VectorType *>::to(ll);
                char * data    = (char *) pArray->data();
                uint32_t size = (uint32_t) pArray->size();
                itc.value      = cast<char *>::from(data);
                itc.array_end  = data + size * sizeof(OT);
                itc.array      = nullptr;
                return (bool) size;
            }
            virtual bool next  ( IteratorContext & itc ) override {
                char * data = cast<char *>::to(itc.value) + sizeof(OT);
                itc.value = cast<char *>::from(data);
                return data != itc.array_end;
            }
            virtual void close ( IteratorContext & ) override {
            }
            SimNode *   source;
        };
        struct SimNode_VectorIterator : SimNode, VectorIterator {
            SimNode_VectorIterator ( const LineInfo & at, SimNode * s )
                : SimNode(at) { VectorIterator::source = s;}
            virtual vec4f eval ( ) override {
                return cast<Iterator *>::from(static_cast<VectorIterator *>(this));
            }
        };
        ManagedVectorAnnotation(const string & n, ModuleLibrary & lib)
            : TypeAnnotation(n) {
                vecType = makeType<OT>(lib);
                vecType->ref = true;
        }
        virtual bool rtti_isHandledTypeAnnotation() const override { return true; }
        virtual size_t getSizeOf() const override { return sizeof(VectorType); }
        virtual size_t getAlignOf() const override { return alignof(VectorType); }
        virtual bool isRefType() const override { return true; }
        virtual bool isIndexable ( const TypeDeclPtr & indexType ) const override { return indexType->isIndex(); }
        virtual bool isIterable ( ) const override { return true; }
        virtual TypeDeclPtr makeFieldType ( const string & na ) const override {
            if ( na=="length" ) return make_shared<TypeDecl>(Type::tInt);
            return nullptr;
        }
        virtual TypeDeclPtr makeIndexType ( TypeDeclPtr & ) const override { return make_shared<TypeDecl>(*vecType); }
        virtual TypeDeclPtr makeIteratorType () const override { return make_shared<TypeDecl>(*vecType); }
        virtual SimNode * simulateGetAt ( const LineInfo & at, const TypeDeclPtr &,
                                         const ExpressionPtr & rv, const ExpressionPtr & idx, uint32_t ofs ) const override {
            return __context__->code->makeNode<SimNode_AtStdVector>(at,
                                                               rv->simulate(),
                                                               idx->simulate(),
                                                               ofs);
        }
        virtual SimNode * simulateGetIterator ( const LineInfo & at, SimNode * rv ) const override {
            return __context__->code->makeNode<SimNode_VectorIterator>(at, rv);
        }
        virtual SimNode * simulateGetField ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            if ( na=="length" ) return __context__->code->makeNode<SimNode_VectorLength>(at,value->simulate());
            return nullptr;
        }
        TypeDeclPtr vecType;
    };

    template <typename OT>
    struct ManagedVectorAnnotation<OT,true> : ManagedVectorAnnotation<OT,false> {
        struct SimNode_AtStdVectorR2V : ManagedVectorAnnotation<OT,false>::SimNode_AtStdVector {
            SimNode_AtStdVectorR2V ( const LineInfo & at, SimNode * rv, SimNode * idx, uint32_t ofs )
                : ManagedVectorAnnotation<OT,false>::SimNode_AtStdVector(at, rv, idx, ofs) {}
            virtual vec4f eval ( ) override {
                OT * pR = (OT *) ManagedVectorAnnotation<OT,false>::SimNode_AtStdVector::compute();
                return cast<OT>::from(*pR);
            }
#define EVAL_NODE(TYPE,CTYPE)                                           \
            virtual CTYPE eval##TYPE ( ) override {   \
                return *(CTYPE *)ManagedVectorAnnotation<OT,false>::SimNode_AtStdVector::compute();    \
            }
            DAS_EVAL_NODE
#undef EVAL_NODE
        };
        virtual SimNode * simulateGetAtR2V ( const LineInfo & at, const TypeDeclPtr &,
                                            const ExpressionPtr & rv, const ExpressionPtr & idx, uint32_t ofs ) const override {
            return __context__->code->makeNode<SimNode_AtStdVectorR2V>(at,
                                                                  rv->simulate(),
                                                                  idx->simulate(),
                                                                  ofs);
        }
    };

    template <typename OT>
    struct ManagedValueAnnotation : TypeAnnotation {
        static_assert(sizeof(OT)<=sizeof(vec4f), "value types have to fit in ABI");
        ManagedValueAnnotation(const string & n) : TypeAnnotation(n) {}
        virtual bool rtti_isHandledTypeAnnotation() const override { return true; }
        virtual bool isLocal() const override { return true; }
        virtual size_t getSizeOf() const override { return sizeof(OT); }
        virtual bool isRefType() const override { return false; }
        virtual SimNode * simulateCopy ( const LineInfo & at, SimNode * l, SimNode * r ) const override {
            return __context__->code->makeNode<SimNode_CopyValue<OT>>(at, l, r);
        }
        virtual SimNode * simulateRef2Value ( const LineInfo & at, SimNode * l ) const override {
            return __context__->code->makeNode<SimNode_Ref2Value<OT>>(at, l);
        }
    };
}

MAKE_TYPE_FACTORY(das_string, das::string);

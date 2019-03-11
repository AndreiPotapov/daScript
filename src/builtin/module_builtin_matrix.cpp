#include "daScript/misc/platform.h"

#include "module_builtin.h"

#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_policy_types.h"
#include "daScript/simulate/runtime_matrices.h"

#include "daScript/simulate/simulate_visit_op.h"

namespace das {
    template <typename VecT, int RowC>
    class MatrixAnnotation : public TypeAnnotation {
        enum { ColC = sizeof(VecT) / sizeof(float) };
        typedef MatrixAnnotation<VecT,RowC> ThisAnnotation;
        typedef Matrix<VecT,RowC> ThisMatrix;
    protected:
        DebugInfoHelper            helpA;
        TypeInfo *                 matrixTypeInfo;
    protected:
        int GetField ( const string & na ) const {
            if ( na.length()!=1 )
                return -1;
            int field = TypeDecl::getMaskFieldIndex(na[0]);
            if ( field<0 || field>=RowC )
                return -1;
            return field;
        }
    public:
        MatrixAnnotation() : TypeAnnotation( "float" + to_string(ColC) + "x" + to_string(RowC) ) {
            matrixTypeInfo = helpA.debugInfo->makeNode<TypeInfo>();
            auto bt = ToBasicType<VecT>::type;
            auto tt = make_shared<TypeDecl>(Type(bt));
            tt->dim.push_back(RowC);
            helpA.makeTypeInfo(matrixTypeInfo, tt);
        }
        virtual TypeAnnotationPtr clone ( const TypeAnnotationPtr & p = nullptr ) const override {
            shared_ptr<ThisAnnotation> cp =  p ? static_pointer_cast<ThisAnnotation>(p) : make_shared<ThisAnnotation>();
            return TypeAnnotation::clone(cp);
        }
        virtual bool rtti_isHandledTypeAnnotation() const override {
            return true;
        }
        virtual bool isRefType() const override {
            return true;
        }
        virtual bool isLocal() const override {
            return true;
        }
        virtual bool canNew() const override {
            return true;
        }
        virtual bool isIndexable ( const TypeDeclPtr & decl ) const override {
            return decl->isIndex();
        }
        virtual size_t getAlignOf() const override {
            return alignof(vec4f);
        }
        virtual size_t getSizeOf() const override {
            return sizeof(ThisMatrix);
        }
        virtual TypeDeclPtr makeFieldType ( const string & na ) const override {
            if ( auto ft = makeSafeFieldType(na) ) {
                ft->ref = true;
                return ft;
            } else {
                return nullptr;
            }
        }
        virtual TypeDeclPtr makeSafeFieldType ( const string & na ) const override {
            int field = GetField(na);
            if ( field<0  )
                return nullptr;
            auto bt = TypeDecl::getVectorType(Type::tFloat, ColC);
            return make_shared<TypeDecl>(bt);
        }
        virtual TypeDeclPtr makeIndexType ( TypeDeclPtr & decl ) const override {
            if ( !decl->isIndex() ) return nullptr;
            auto bt = TypeDecl::getVectorType(Type::tFloat, ColC);
            auto pt = make_shared<TypeDecl>(bt);
            pt->ref = true;
            return pt;
        }
        virtual SimNode * simulateCopy ( const LineInfo & at, SimNode * l, SimNode * r ) const override {
            return __context__->code->makeNode<SimNode_CopyValue<ThisMatrix>>(at, l, r);
        }
        virtual SimNode * simulateGetField ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            int field = GetField(na);
            if ( field!=-1 ) {
                if ( !value->type->isPointer() ) {
                    auto tnode = value->trySimulate(field*sizeof(VecT), Type::none);
                    if ( tnode ) {
                        return tnode;
                    }
                }
                return __context__->code->makeNode<SimNode_FieldDeref>(at,
                                                                  value->simulate(),
                                                                  uint32_t(field*sizeof(VecT)));
            } else {
                return nullptr;
            }
        }
        virtual SimNode * simulateGetFieldR2V ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            int field = GetField(na);
            if ( field!=-1 ) {
                auto bt = TypeDecl::getVectorType(Type::tFloat, ColC);
                if ( !value->type->isPointer() ) {
                    auto tnode = value->trySimulate(field*sizeof(VecT), bt);
                    if ( tnode ) {
                        return tnode;
                    }
                }
                return __context__->code->makeValueNode<SimNode_FieldDerefR2V>(bt,
                                                                          at,
                                                                          value->simulate(),
                                                                          uint32_t(field*sizeof(VecT)));
            } else {
                return nullptr;
            }
        }
        virtual SimNode * simulateGetNew ( const LineInfo & at ) const override {
            return __context__->code->makeNode<SimNode_New>(at,int32_t(sizeof(ThisMatrix)));
        }
        virtual SimNode * simulateDeletePtr ( const LineInfo & at, SimNode * sube, uint32_t count ) const override {
            uint32_t ms = uint32_t(sizeof(ThisMatrix));
            return __context__->code->makeNode<SimNode_DeleteStructPtr>(at,sube,count,ms);
        }
        virtual SimNode * simulateSafeGetField ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            int field = GetField(na);
            if ( field!=-1 ) {
                return __context__->code->makeNode<SimNode_SafeFieldDeref>(at,
                                                                      value->simulate(),
                                                                      uint32_t(field*sizeof(VecT)));
            } else {
                return nullptr;
            }
        };
        virtual SimNode * simulateSafeGetFieldPtr ( const string & na, const LineInfo & at, const ExpressionPtr & value ) const override {
            int field = GetField(na);
            if ( field!=-1 ) {
                return __context__->code->makeNode<SimNode_SafeFieldDerefPtr>(at,
                                                                         value->simulate(),
                                                                         uint32_t(field*sizeof(VecT)));
            } else {
                return nullptr;
            }
        };
        SimNode * trySimulate ( const ExpressionPtr & subexpr, const ExpressionPtr & index,
                               Type r2vType, uint32_t ofs ) const {
            if ( index->rtti_isConstant() ) {
                // if its constant index, like a[3]..., we try to let node bellow simulate
                auto idxCE = static_pointer_cast<ExprConst>(index);
                uint32_t idxC = cast<uint32_t>::to(idxCE->value);
                if ( idxC >= RowC ) {
                    __context__->thisProgram->error("matrix index out of range", subexpr->at, CompilationError::index_out_of_range);
                    return nullptr;
                }
                uint32_t stride = sizeof(float)*ColC;
                auto tnode = subexpr->trySimulate(idxC*stride + ofs, r2vType);
                if ( tnode ) {
                    return tnode;
                }
            }
            return nullptr;
        }
        virtual SimNode * simulateGetAt ( const LineInfo & at, const TypeDeclPtr &,
                                         const ExpressionPtr & rv, const ExpressionPtr & idx, uint32_t ofs ) const override {
            if ( auto tnode = trySimulate(rv, idx, Type::none, ofs) ) {
                return tnode;
            } else {
                return __context__->code->makeNode<SimNode_At>(at,
                                                          rv->simulate(),
                                                          idx->simulate(),
                                                          uint32_t(sizeof(float)*ColC), ofs, RowC);
            }
        }
        virtual SimNode * simulateGetAtR2V ( const LineInfo & at, const TypeDeclPtr &,
                                            const ExpressionPtr & rv, const ExpressionPtr & idx, uint32_t ofs ) const override {
            Type r2vType = (Type) ToBasicType<VecT>::type;
            if ( auto tnode = trySimulate(rv, idx, r2vType, ofs) ) {
                return tnode;
            } else {
                return __context__->code->makeNode<SimNode_AtR2V<float>>(at,
                                                                    rv->simulate(),
                                                                    idx->simulate(),
                                                                    uint32_t(sizeof(float)*ColC), ofs, RowC);
            }
        }
        virtual void walk ( DataWalker & walker, void * data ) override {
            walker.walk((char *)data, matrixTypeInfo);
        }
    };

    typedef MatrixAnnotation<float4,4> float4x4_ann;
    typedef MatrixAnnotation<float3,4> float3x4_ann;

    template <typename MatT>
    struct SimNode_MatrixCtor : SimNode_CallBase {
        SimNode_MatrixCtor(const LineInfo & at) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN();
            V_OP(MatrixCtor);
            V_END();
        }
        virtual vec4f eval() override {
            auto cmres = cmresEval->evalPtr();
            memset ( cmres, 0, sizeof(MatT) );
            return cast<void *>::from(cmres);
        }
    };

    template <int r, int c>
    __forceinline void matrix_identity ( float * mat ) {
        for ( int y=0; y!=r; ++y ) {
            for ( int x=0; x!=c; ++x ) {
                *mat++ = x==y ? 1.0f : 0.0f;
            }
        }
    }

    void float4x4_identity ( float4x4 & mat ) {
        matrix_identity<4,4>((float*)&mat);
    }

    void float3x4_identity ( float3x4 & mat ) {
        matrix_identity<4,3>((float*)&mat);
    }

    float4x4 float_4x4_translation(float3 xyz) {
        float4x4 mat;
        matrix_identity<4,4>((float*)&mat);
        mat.m[3].x = xyz.x;
        mat.m[3].y = xyz.y;
        mat.m[3].z = xyz.z;
        return mat;
    }

    float3x4 float3x4_mul(const float3x4 &a, const float3x4 &b) {
        //not working yet!
        mat44f va,vb,vc;
        v_mat44_make_from_43cu(va, &a.m[0].x);
        v_mat44_make_from_43cu(vb, &b.m[0].x);
        v_mat44_mul43(vc, va, vb);
        alignas(16) float3x4 ret;
        v_mat_43ca_from_mat44(&ret.m[0].x, vc);
        return ret;
    }

    void Module_BuiltIn::addMatrixTypes(ModuleLibrary & lib) {
        // structure annotations
        addAnnotation(make_shared<float4x4_ann>());
        addAnnotation(make_shared<float3x4_ann>());
        // c-tor
        addFunction ( make_shared< BuiltInFn< SimNode_MatrixCtor<float3x4>,float3x4 > >("float3x4",lib) );
        addFunction ( make_shared< BuiltInFn< SimNode_MatrixCtor<float4x4>,float4x4 > >("float4x4",lib) );
        // 4x4
        addExtern<DAS_BIND_FUN(float4x4_identity)>(*this, lib, "identity", SideEffects::modifyArgument);
        addExtern<DAS_BIND_FUN(float_4x4_translation), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "translation", SideEffects::none);
        // 3x4
        addExtern<DAS_BIND_FUN(float3x4_identity)>(*this, lib, "identity", SideEffects::modifyArgument);
        addExtern<DAS_BIND_FUN(float3x4_mul), SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "*", SideEffects::none);
    }
}

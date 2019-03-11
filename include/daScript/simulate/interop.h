#pragma once

#include "daScript/simulate/simulate.h"
#include "daScript/misc/function_traits.h"

#include "daScript/simulate/simulate_visit_op.h"

namespace das
{
    template <typename TT>
    struct cast_arg {
        static __forceinline TT to ( SimNode * x ) {
            return EvalTT<TT>::eval(x);
        }
    };

    template <>
    struct cast_arg<vec4f> {
        static __forceinline vec4f to ( SimNode * x ) {
            return x->eval();
        }
    };

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4100)
#endif
    template <typename Result>
    struct ImplCallStaticFunction {
        template <typename FunctionType, typename ArgumentsType, size_t... I>
        static __forceinline vec4f call(FunctionType && fn, SimNode ** args, index_sequence<I...> ) {
            return cast<Result>::from( fn( cast_arg< typename tuple_element<I, ArgumentsType>::type  >::to ( args[ I ] )... ) );
        }
    };

    template <>
    struct ImplCallStaticFunction<void> {
        template <typename FunctionType, typename ArgumentsType, size_t... I>
        static __forceinline vec4f call(FunctionType && fn, SimNode ** args, index_sequence<I...> ) {
            fn( cast_arg< typename tuple_element<I, ArgumentsType>::type  >::to ( args[ I ] )... );
            return v_zero();
        }
    };

    template <typename Result, typename CType, bool Pointer=is_pointer<Result>::value&&is_pointer<CType>::value>
    struct ImplCallStaticFunctionImm {
        enum { valid = false };
        template <typename FunctionType, typename ArgumentsType, size_t... I>
        static __forceinline CType call(FunctionType &&, SimNode **, index_sequence<I...> ) {
            DAS_ASSERTF(0, "if this assert triggers, somehow prohibited call was called explicitly."
                        "like evalDouble on pointer or something similar."
                        "this means that this template needs to be revisited."
                        "we should not even be here, because code above verifies 'valid' field.");
            return CType();
        }
    };

    template <typename Result, typename CType>
    struct ImplCallStaticFunctionImm<Result, CType, true> {
        enum { valid = true };
        template <typename FunctionType, typename ArgumentsType, size_t... I>
        static __forceinline CType call(FunctionType && fn, SimNode ** args, index_sequence<I...>) {
            return (CType)fn(cast_arg< typename tuple_element<I, ArgumentsType>::type  >::to(args[I])...);
        }
    };

    template <typename Result>
    struct ImplCallStaticFunctionImm<Result,Result, false> {
        enum { valid = true };
        template <typename FunctionType, typename ArgumentsType, size_t... I>
        static __forceinline Result call(FunctionType && fn, SimNode ** args, index_sequence<I...> ) {
            return fn( cast_arg< typename tuple_element<I, ArgumentsType>::type  >::to ( args[ I ] )... );
        }
    };

    template <typename CType, bool Pointer>
    struct ImplCallStaticFunctionImm<void,CType,Pointer> {
        enum { valid = true };
        template <typename FunctionType, typename ArgumentsType, size_t... I>
        static __forceinline CType call(FunctionType && fn, SimNode ** args, index_sequence<I...> ) {
            fn( cast_arg< typename tuple_element<I, ArgumentsType>::type  >::to ( args[ I ] )... );
            return CType();
        }
    };

    template <typename Result>
    struct ImplCallStaticFunctionAndCopy {
        enum { valid = true };
        template <typename FunctionType, typename ArgumentsType, size_t... I>
        static __forceinline void call(FunctionType && fn, Result * res, SimNode ** args, index_sequence<I...> ) {
            *res = fn( cast_arg< typename tuple_element<I, ArgumentsType>::type  >::to ( args[ I ] )... );
        }
    };

    template <>
    struct ImplCallStaticFunctionAndCopy<void>;

#ifdef _MSC_VER
#pragma warning(pop)
#endif

    template <typename FuncT, FuncT fn>
    struct SimNode_ExtFuncCall : SimNode_CallBase {
        const char * extFnName = nullptr;
        SimNode_ExtFuncCall ( const LineInfo & at, const char * fnName )
            : SimNode_CallBase(at) { extFnName = fnName; }
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN();
            vis.op(extFnName);
            V_CALL();
            V_END();
        }
        virtual vec4f eval (  ) override {
            using FunctionTrait = function_traits<FuncT>;
            using Result = typename FunctionTrait::return_type;
            using Arguments = typename FunctionTrait::arguments;
            const int nargs = tuple_size<Arguments>::value;
            using Indices = make_index_sequence<nargs>;
            return ImplCallStaticFunction<Result>::template
                call<FuncT,Arguments>(*fn, arguments, Indices());
        }
#define EVAL_NODE(TYPE,CTYPE)\
        virtual CTYPE eval##TYPE ( ) override {                   \
                using FunctionTrait = function_traits<FuncT>;                       \
                using Result = typename FunctionTrait::return_type;                 \
                using Arguments = typename FunctionTrait::arguments;                \
                const int nargs = tuple_size<Arguments>::value;                     \
                using Indices = make_index_sequence<nargs>;                         \
                if ( !ImplCallStaticFunctionImm<Result,CTYPE>::valid )              \
                    __context__->throw_error_at(debugInfo,"internal integration error"); \
                return ImplCallStaticFunctionImm<Result,CTYPE>::template            \
                    call<FuncT,Arguments>(*fn, arguments, Indices());      \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    template <typename FuncT, FuncT fn>
    struct SimNode_ExtFuncCallAndCopyOrMove : SimNode_CallBase {
        const char * extFnName = nullptr;
        SimNode_ExtFuncCallAndCopyOrMove ( const LineInfo & at, const char * fnName )
            : SimNode_CallBase(at) { extFnName = fnName; }
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN();
            vis.op(extFnName);
            V_CALL();
            V_END();
        }
        virtual vec4f eval ( ) override {
            using FunctionTrait = function_traits<FuncT>;
            using Result = typename FunctionTrait::return_type;
            using Arguments = typename FunctionTrait::arguments;
            const int nargs = tuple_size<Arguments>::value;
            using Indices = make_index_sequence<nargs>;
            Result * cmres = (Result *)(cmresEval->evalPtr());
            ImplCallStaticFunctionAndCopy<Result>::template
                call<FuncT,Arguments>(*fn, cmres, arguments, Indices());
            return cast<Result *>::from(cmres);
        }
    };

    typedef vec4f ( InteropFunction ) ( SimNode_CallBase * node, vec4f * args );

    template <InteropFunction fn>
    struct SimNode_InteropFuncCall : SimNode_CallBase {
        const char * extFnName = nullptr;
        SimNode_InteropFuncCall ( const LineInfo & at, const char * fnName )
            : SimNode_CallBase(at) { extFnName = fnName; }
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN();
            vis.op(extFnName);
            V_CALL();
            V_END();
        }
        virtual vec4f eval (  ) override {
            vec4f * args = (vec4f *)(alloca(nArguments * sizeof(vec4f)));
            evalArgs( args);
            auto res = fn(this,args);
            return res;
        }
    };
}

#include "daScript/simulate/simulate_visit_op_undef.h"



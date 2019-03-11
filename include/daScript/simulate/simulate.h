#pragma once

#include <setjmp.h>
#include "daScript/misc/vectypes.h"
#include "daScript/misc/arraytype.h"
#include "daScript/simulate/cast.h"
#include "daScript/simulate/runtime_string.h"
#include "daScript/simulate/debug_info.h"
#include "daScript/simulate/sim_policy.h"
#include "daScript/simulate/heap.h"

#include "daScript/simulate/simulate_visit_op.h"

namespace das
{
    #define DAS_BIND_FUN(a)                     decltype(&a), a
    #define DAS_BIND_PROP(BIGTYPE,FIELDNAME)    decltype(&BIGTYPE::FIELDNAME), &BIGTYPE::FIELDNAME

    template <class T, class M> M get_member_type(M T:: *);
    #define GET_TYPE_OF(mem) decltype(das::get_member_type(mem))
    #define DAS_BIND_FIELD(BIGTYPE,FIELDNAME)   GET_TYPE_OF(&BIGTYPE::FIELDNAME),offsetof(BIGTYPE,FIELDNAME)

    #ifndef DAS_ENABLE_STACK_WALK
    #define DAS_ENABLE_STACK_WALK   1
    #endif

    #ifndef DAS_ENABLE_EXCEPTIONS
    #define DAS_ENABLE_EXCEPTIONS   0
    #endif

    #define MAX_FOR_ITERATORS   16

    class Context;

    extern DAS_THREAD_LOCAL Context * __restrict __context__;

    struct SimNode;
    struct Block;
    struct SimVisitor;

    struct GlobalVariable {
        char *          name;
        VarInfo *       debugInfo;
        SimNode *       init;
        uint32_t        size;
        uint32_t        offset;
    };

    struct SimFunction {
        char *      name;
        SimNode *   code;
        uint32_t    stackSize;
        FuncInfo *  debugInfo;
    };

    struct SimNode {
        SimNode ( const LineInfo & at ) : debugInfo(at) {}
        virtual vec4f eval ( void ) = 0;
        virtual SimNode * visit ( SimVisitor & vis );
        virtual char *      evalPtr ( void );
        virtual bool        evalBool ( void );
        virtual float       evalFloat ( void );
        virtual double      evalDouble ( void );
        virtual int32_t     evalInt ( void );
        virtual uint32_t    evalUInt ( void );
        virtual int64_t     evalInt64 ( void );
        virtual uint64_t    evalUInt64 ( void );
        LineInfo debugInfo;
    protected:
        virtual ~SimNode() {}
    };

    struct Prologue {
        union {
            struct {
                vec4f *     arguments;
                FuncInfo *  info;
                int32_t     line;
            };
            vec4f           dummy;
        };
    };
    static_assert((sizeof(Prologue) & 0xf)==0, "it has to be 16 byte aligned");

    struct BlockArguments {
        vec4f *     arguments;
        char *      copyOrMoveResult;
    };

    enum EvalFlags : uint32_t {
        stopForBreak        = 1 << 0
    ,   stopForReturn       = 1 << 1
    };

#if DAS_ENABLE_EXCEPTIONS
    class dasException : public runtime_error {
    public:
        dasException ( const char * why ) : runtime_error(why) {}
    };
#endif

    struct SimVisitor {
        virtual void preVisit ( SimNode * ) { }
        virtual void cr () {}
        virtual void op ( const char * /* name */ ) {}
        virtual void sp ( uint32_t /* stackTop */,  const char * /* op */ = "#sp" ) { }
        virtual void arg ( int32_t /* argV */,  const char * /* argN */  ) { }
        virtual void arg ( uint32_t /* argV */,  const char * /* argN */  ) { }
        virtual void arg ( const char * /* argV */,  const char * /* argN */  ) { }
        virtual void arg ( vec4f /* argV */,  const char * /* argN */  ) { }
        virtual void arg ( uint64_t /* argV */,  const char * /* argN */  ) { }
        virtual void arg ( bool /* argV */,  const char * /* argN */  ) { }
        virtual void sub ( SimNode ** nodes, uint32_t count, const char * );
        virtual SimNode * sub ( SimNode * node, const char * /* opN */ = "subexpr" ) { return node->visit(*this); }
        virtual SimNode * visit ( SimNode * node ) { return node; }
    };

    void printSimNode ( TextWriter & ss, SimNode * node );

    class Context {
        template <typename TT> friend struct SimNode_GetGlobalR2V;
        friend struct SimNode_GetGlobal;
        friend struct SimNode_TryCatch;
        friend class Program;
    public:
        Context();
        Context(const Context &);
        Context & operator = (const Context &) = delete;
        virtual ~Context();

        __forceinline void bind() {
            __context__ = this;
        }

        __forceinline void unbind() {
            __context__ = nullptr;
        }

        __forceinline void * getVariable ( int index ) const {
            return (uint32_t(index)<uint32_t(totalVariables)) ? (globals + globalVariables[index].offset) : nullptr;
        }

        __forceinline VarInfo * getVariableInfo( int index ) const {
            return (uint32_t(index)<uint32_t(totalVariables)) ? globalVariables[index].debugInfo  : nullptr;;
        }

        __forceinline void simEnd() {
            thisProgram = nullptr;
            thisHelper = nullptr;
        }

        __forceinline void restart( ) {
            stopFlags = 0;
            exception = nullptr;
            stack.reset();
        }

        __forceinline vec4f eval ( const SimFunction * fnPtr, vec4f * args = nullptr, void * res = nullptr ) {
            return callWithCopyOnReturn(fnPtr, args, res, 0);
        }

        vec4f evalWithCatch ( SimFunction * fnPtr, vec4f * args = nullptr, void * res = nullptr );
        vec4f evalWithCatch ( SimNode * node );

        void throw_error ( const char * message );
        void throw_error_ex ( const char * message, ... );
        void throw_error_at ( const LineInfo & at, const char * message, ... );

        __forceinline SimFunction * getFunction ( int index ) const {
            return (index>=0 && index<totalFunctions) ? functions + index : nullptr;
        }

        SimFunction * findFunction ( const char * name ) const;
        int findVariable ( const char * name ) const;
        void stackWalk();
        string getStackWalk( bool args = true );
        void runInitScript ( void );

        virtual void to_out ( const char * message );           // output to stdout or equivalent
        virtual void to_err ( const char * message );           // output to stderr or equivalent
        virtual void breakPoint(int column, int line) const;    // what to do in case of breakpoint

        __forceinline vec4f * abiArguments() {
            return abiArg;
        }

        __forceinline vec4f & abiResult() {
            return result;
        }

        __forceinline char * abiCopyOrMoveResult() {
            return (char *) abiCMRES;
        }

        __forceinline vec4f call(const SimFunction * fn, vec4f * args, int line) {
            // PUSH
            char * EP, *SP;
            if (!stack.push(fn->stackSize, EP, SP)) {
                throw_error_ex("stack overflow at line %i",line);
                return v_zero();
            }
            // fill prologue
            auto aa = abiArg;
            abiArg = args;
#if DAS_ENABLE_STACK_WALK
            Prologue * pp = (Prologue *)stack.sp();
            pp->arguments = args;
            pp->info = fn->debugInfo;
            pp->line = line;
#endif
            // CALL
            fn->code->eval();
            stopFlags &= ~(EvalFlags::stopForReturn | EvalFlags::stopForBreak);
            // POP
            abiArg = aa;
            stack.pop(EP, SP);
            return result;
        }

        __forceinline vec4f callWithCopyOnReturn(const SimFunction * fn, vec4f * args, void * cmres, int line) {
            // PUSH
            char * EP, *SP;
            if (!stack.push(fn->stackSize, EP, SP)) {
                throw_error_ex("stack overflow at line %i",line);
                return v_zero();
            }
            // fill prologue
            auto aa = abiArg; auto acm = abiCMRES;
            abiArg = args; abiCMRES = cmres;
#if DAS_ENABLE_STACK_WALK
            Prologue * pp = (Prologue *)stack.sp();
            pp->arguments = args;
            pp->info = fn->debugInfo;
            pp->line = line;
#endif
            // CALL
            fn->code->eval();
            stopFlags &= ~(EvalFlags::stopForReturn | EvalFlags::stopForBreak);
            // POP
            abiArg = aa; abiCMRES = acm;
            stack.pop(EP, SP);
            return result;
        }

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4701)
#pragma warning(disable:4324)
#endif
        __forceinline vec4f invoke(const Block &block, vec4f * args, void * cmres ) {
            char * EP, *SP;
            stack.invoke(block.stackOffset, EP, SP);
            BlockArguments * __restrict ba = nullptr;
            BlockArguments saveArguments;
            if ( block.argumentsOffset ) {
                ba = (BlockArguments *) ( stack.bottom() + block.argumentsOffset );
                saveArguments = *ba;
                ba->arguments = args;
                ba->copyOrMoveResult = (char *) cmres;
            }
            vec4f * __restrict saveFunctionArguments = abiArg;
            abiArg = block.functionArguments;
            vec4f block_result = block.body->eval();
            abiArg = saveFunctionArguments;
            if ( ba ) {
                *ba = saveArguments;
            }
            stack.pop(EP, SP);
            return block_result;
        }

        template <typename Fn>
        vec4f invokeEx(const Block &block, vec4f * args, void * cmres, Fn && when) {
            char * EP, *SP;
            stack.invoke(block.stackOffset,EP,SP);
            BlockArguments * ba = nullptr;
            BlockArguments saveArguments;
            if ( block.argumentsOffset ) {
                ba = (BlockArguments *) ( stack.bottom() + block.argumentsOffset );
                saveArguments = *ba;
                ba->arguments = args;
                ba->copyOrMoveResult = (char *) cmres;
            }
            vec4f * __restrict saveFunctionArguments = abiArg;
            abiArg = block.functionArguments;
            when(block.body);
            abiArg = saveFunctionArguments;
            if ( ba ) {
                *ba = saveArguments;
            }
            stack.pop(EP,SP);
            return result;
        }
#ifdef _MSC_VER
#pragma warning(pop)
#endif

        template <typename Fn>
        vec4f callEx(const SimFunction * fn, vec4f *args, void * cmres, int line, Fn && when) {
            // PUSH
            char * EP, *SP;
            if(!stack.push(fn->stackSize,EP,SP)) {
                throw_error_ex("stack overflow at line %i", line);
                return v_zero();
            }
            // fill prologue
            auto aa = abiArg; auto acm = cmres;
            abiArg = args;  abiCMRES = cmres;
    #if DAS_ENABLE_STACK_WALK
            Prologue * pp           = (Prologue *) stack.sp();
            pp->arguments           = args;
            pp->info                = fn->debugInfo;
            pp->line                = line;
    #endif
            // CALL
            when(fn->code);
            stopFlags &= ~(EvalFlags::stopForReturn | EvalFlags::stopForBreak);
            // POP
            abiArg = aa; abiCMRES = acm;
            stack.pop(EP,SP);
            return result;
        }

        __forceinline const char * getException() const {
            return exception;
        }

    public:
        HeapAllocator               heap;
        char *                      globals = nullptr;
        shared_ptr<NodeAllocator>   code;
        shared_ptr<NodeAllocator>   debugInfo;
        StackAllocator              stack;
    public:
        vec4f *         abiArg;
        void *          abiCMRES;
    protected:
        const char *    exception = nullptr;
        string          lastError;
#if !DAS_ENABLE_EXCEPTIONS
        jmp_buf *       throwBuf = nullptr;
#endif
    protected:
        GlobalVariable * globalVariables = nullptr;
        uint32_t globalsSize = 0;
        uint32_t globalInitStackSize = 0;
        SimFunction * functions = nullptr;
        int totalVariables = 0;
        int totalFunctions = 0;
    public:
        class Program * thisProgram = nullptr;
        class DebugInfoHelper * thisHelper = nullptr;
    public:
        uint32_t stopFlags = 0;
        vec4f result;
    };

    struct context_guard {
        context_guard() = delete;
        context_guard(const context_guard &) = delete;
        context_guard(Context & ctx) { 
            that = __context__;
            __context__ = &ctx;
        }
        ~context_guard() {
            __context__ = that;
        }
        Context * that = nullptr;
    };

#define DAS_EVAL_NODE               \
    EVAL_NODE(Ptr,char *);          \
    EVAL_NODE(Int,int32_t);         \
    EVAL_NODE(UInt,uint32_t);       \
    EVAL_NODE(Int64,int64_t);       \
    EVAL_NODE(UInt64,uint64_t);     \
    EVAL_NODE(Float,float);         \
    EVAL_NODE(Double,double);       \
    EVAL_NODE(Bool,bool);

#define DAS_NODE(TYPE,CTYPE)                      \
    virtual vec4f eval ( void ) override {        \
        return cast<CTYPE>::from(compute());      \
    }                                             \
    virtual CTYPE eval##TYPE ( void ) override {  \
        return compute();                         \
    }

#define DAS_PTR_NODE    DAS_NODE(Ptr,char *)
#define DAS_BOOL_NODE   DAS_NODE(Bool,bool)
#define DAS_INT_NODE    DAS_NODE(Int,int32_t)
#define DAS_FLOAT_NODE  DAS_NODE(Float,float)
#define DAS_DOUBLE_NODE DAS_NODE(Double,double)

    template <typename TT>
    struct EvalTT { static __forceinline TT eval ( SimNode * node ) {
        return cast<TT>::to(node->eval()); }};
    template <>
    struct EvalTT<int32_t> { static __forceinline int32_t eval ( SimNode * node ) {
        return node->evalInt(); }};
    template <>
    struct EvalTT<uint32_t> { static __forceinline uint32_t eval ( SimNode * node ) {
        return node->evalUInt(); }};
    template <>
    struct EvalTT<int64_t> { static __forceinline int64_t eval ( SimNode * node ) {
        return node->evalInt64(); }};
    template <>
    struct EvalTT<uint64_t> { static __forceinline uint64_t eval ( SimNode * node ) {
        return node->evalUInt64(); }};
    template <>
    struct EvalTT<float> { static __forceinline float eval ( SimNode * node ) {
        return node->evalFloat(); }};
    template <>
    struct EvalTT<double> { static __forceinline double eval ( SimNode * node ) {
        return node->evalDouble(); }};
    template <>
    struct EvalTT<bool> { static __forceinline bool eval ( SimNode * node ) {
        return node->evalBool(); }};

    // Delete
    struct SimNode_Delete : SimNode {
        SimNode_Delete ( const LineInfo & a, SimNode * s, uint32_t t )
            : SimNode(a), subexpr(s), total(t) {}
        SimNode *   subexpr;
        uint32_t    total;
    };

    // Delete structures
    struct SimNode_DeleteStructPtr : SimNode_Delete {
        SimNode_DeleteStructPtr ( const LineInfo & a, SimNode * s, uint32_t t, uint32_t ss )
            : SimNode_Delete(a,s,t), structSize(ss) {}
        virtual vec4f eval ( ) override;
        virtual SimNode * visit ( SimVisitor & vis ) override;
        uint32_t    structSize;
    };

    // New handle, default
    template <typename TT>
    struct SimNode_NewHandle : SimNode {
        DAS_PTR_NODE;
        SimNode_NewHandle ( const LineInfo & a ) : SimNode(a) {}
        __forceinline char * compute ( ) {
            return (char *) new TT();
        }
        virtual SimNode * visit ( SimVisitor & vis ) override;
    };

    // Delete handle, default
    template <typename TT>
    struct SimNode_DeleteHandlePtr : SimNode_Delete {
        SimNode_DeleteHandlePtr ( const LineInfo & a, SimNode * s, uint32_t t )
            : SimNode_Delete(a,s,t) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto pH = (TT **) subexpr->evalPtr();
            for ( uint32_t i=0; i!=total; ++i, pH++ ) {
                if ( *pH ) {
                    delete * pH;
                    *pH = nullptr;
                }
            }
            return v_zero();
        }
    };

    // MakeBlock
    struct SimNode_MakeBlock : SimNode {
        SimNode_MakeBlock ( const LineInfo & at, SimNode * s, uint32_t a, uint32_t spp )
            : SimNode(at), subexpr(s), argStackTop(a), stackTop(spp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        SimNode *       subexpr;
        uint32_t        argStackTop;
        uint32_t        stackTop;
    };

    // ASSERT
    struct SimNode_Assert : SimNode {
        SimNode_Assert ( const LineInfo & at, SimNode * s, const char * m )
            : SimNode(at), subexpr(s), message(m) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        SimNode *       subexpr;
        const char *    message;
    };

    // VECTOR SWIZZLE
    // TODO: make at least 3 different versions
    struct SimNode_Swizzle : SimNode {
        SimNode_Swizzle ( const LineInfo & at, SimNode * rv, uint8_t * fi )
            : SimNode(at), value(rv) {
                fields[0] = fi[0];
                fields[1] = fi[1];
                fields[2] = fi[2];
                fields[3] = fi[3];
            }
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        SimNode *   value;
        uint8_t     fields[4];
    };

    // FIELD .
    struct SimNode_FieldDeref : SimNode {
        DAS_PTR_NODE;
        SimNode_FieldDeref ( const LineInfo & at, SimNode * rv, uint32_t of )
            : SimNode(at), value(rv), offset(of) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            return value->evalPtr() + offset;
        }
        SimNode *   value;
        uint32_t    offset;
    };

    template <typename TT>
    struct SimNode_FieldDerefR2V : SimNode_FieldDeref {
        SimNode_FieldDerefR2V ( const LineInfo & at, SimNode * rv, uint32_t of )
            : SimNode_FieldDeref(at,rv,of) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto prv = value->evalPtr();
            TT * pR = (TT *)( prv + offset );
            return cast<TT>::from(*pR);

        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {   \
            auto prv = value->evalPtr();                     \
            return * (CTYPE *)( prv + offset );                     \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    // PTR FIELD .
    struct SimNode_PtrFieldDeref : SimNode {
        DAS_PTR_NODE;
        SimNode_PtrFieldDeref(const LineInfo & at, SimNode * rv, uint32_t of)
            : SimNode(at), value(rv), offset(of) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute() {
            auto prv = value->evalPtr();
            if (prv) {
                return prv + offset;
            }
            else {
                __context__->throw_error_at(debugInfo,"dereferencing null pointer");
                return nullptr;
            }
        }
        SimNode *   value;
        uint32_t    offset;
    };

    template <typename TT>
    struct SimNode_PtrFieldDerefR2V : SimNode_PtrFieldDeref {
        SimNode_PtrFieldDerefR2V(const LineInfo & at, SimNode * rv, uint32_t of)
            : SimNode_PtrFieldDeref(at, rv, of) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval() override {
            auto prv = value->evalPtr();
            if (prv) {
                TT * pR = (TT *)(prv + offset);
                return cast<TT>::from(*pR);
            }
            else {
                __context__->throw_error_at(debugInfo,"dereferencing null pointer");
                return v_zero();
            }
        }
        virtual char * evalPtr() override {
            auto prv = value->evalPtr();
            if (prv) {
                return *(char **)(prv + offset);
            }
            else {
                __context__->throw_error_at(debugInfo,"dereferencing null pointer");
                return nullptr;
            }
        }
    };

    // FIELD ?.
    struct SimNode_SafeFieldDeref : SimNode_FieldDeref {
        DAS_PTR_NODE;
        SimNode_SafeFieldDeref ( const LineInfo & at, SimNode * rv, uint32_t of )
            : SimNode_FieldDeref(at,rv,of) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            auto prv = value->evalPtr();
            return prv ? prv + offset : nullptr;
        }
    };

    // FIELD ?.->
    struct SimNode_SafeFieldDerefPtr : SimNode_FieldDeref {
        DAS_PTR_NODE;
        SimNode_SafeFieldDerefPtr ( const LineInfo & at, SimNode * rv, uint32_t of )
            : SimNode_FieldDeref(at,rv,of) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            char ** prv = (char **) value->evalPtr();
            return prv ? *(prv + offset) : nullptr;
        }
    };

    // AT (INDEX)
    struct SimNode_At : SimNode {
        DAS_PTR_NODE;
        SimNode_At ( const LineInfo & at, SimNode * rv, SimNode * idx, uint32_t strd, uint32_t o, uint32_t rng )
            : SimNode(at), value(rv), index(idx), stride(strd), offset(o), range(rng) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute () {
            auto pValue = value->evalPtr();
            uint32_t idx = cast<uint32_t>::to(index->eval());
            if (idx >= range) {
                __context__->throw_error_at(debugInfo,"index out of range");
                return nullptr;
            } else {
                return pValue + idx*stride + offset;
            }
        }
        SimNode * value, * index;
        uint32_t  stride, offset, range;
    };

    template <typename TT>
    struct SimNode_AtR2V : SimNode_At {
        SimNode_AtR2V ( const LineInfo & at, SimNode * rv, SimNode * idx, uint32_t strd, uint32_t o, uint32_t rng )
            : SimNode_At(at,rv,idx,strd,o,rng) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pR = (TT *) compute();
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {   \
            return *(CTYPE *)compute();                      \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    // AT (INDEX)
    template <typename TT>
    struct SimNode_AtVector;

#define SIM_NODE_AT_VECTOR(TYPE,CTYPE)                                                          \
    template <>                                                                                 \
    struct SimNode_AtVector<CTYPE> : SimNode {                                                  \
        SimNode_AtVector ( const LineInfo & at, SimNode * rv, SimNode * idx, uint32_t rng )     \
            : SimNode(at), value(rv), index(idx), range(rng) {}                                 \
        virtual SimNode * visit ( SimVisitor & vis ) override {                                 \
            V_BEGIN();                                                                          \
            V_OP(AtVector "_" #TYPE);                                                           \
            V_SUB(value);                                                                       \
            V_SUB(index);                                                                       \
            V_ARG(range);                                                                       \
            V_END();                                                                            \
        }                                                                                       \
        __forceinline CTYPE compute ( ) {                                                       \
            auto vec = value->eval();                                                    \
            uint32_t idx = cast<uint32_t>::to(index->eval());                                   \
            if (idx >= range) {                                                                 \
                __context__->throw_error_at(debugInfo,"index out of range");                         \
                return (CTYPE) 0;                                                               \
            } else {                                                                            \
                CTYPE * pv = (CTYPE *) &vec;                                                    \
                return pv[idx];                                                                 \
            }                                                                                   \
        }                                                                                       \
        DAS_NODE(TYPE, CTYPE)                                                                   \
        SimNode * value, * index;                                                               \
        uint32_t  range;                                                                        \
    };

SIM_NODE_AT_VECTOR(Int,   int32_t)
SIM_NODE_AT_VECTOR(UInt,  uint32_t)
SIM_NODE_AT_VECTOR(Float, float)

    template <int nElem>
    struct EvalBlock { static __forceinline void eval(SimNode ** arguments, vec4f * argValues) {
            for (int i = 0; i != nElem && !__context__->stopFlags; ++i)
                argValues[i] = arguments[i]->eval();
    }};
    template <>    struct EvalBlock<0> { static __forceinline void eval(SimNode **, vec4f *) {} };
    template <> struct EvalBlock<1> {    static __forceinline void eval(SimNode ** arguments, vec4f * argValues) {
                                    argValues[0] = arguments[0]->eval();
    }};
    template <> struct EvalBlock<2> {    static __forceinline void eval(SimNode ** arguments, vec4f * argValues) {
                                    argValues[0] = arguments[0]->eval();
            if (!__context__->stopFlags) argValues[1] = arguments[1]->eval();
    }};
    template <> struct EvalBlock<3> {    static __forceinline void eval(SimNode ** arguments, vec4f * argValues) {
                                    argValues[0] = arguments[0]->eval();
            if (!__context__->stopFlags) argValues[1] = arguments[1]->eval();
            if (!__context__->stopFlags) argValues[2] = arguments[2]->eval();
    }};
    template <> struct EvalBlock<4> {    static __forceinline void eval(SimNode ** arguments, vec4f * argValues) {
                                    argValues[0] = arguments[0]->eval();
            if (!__context__->stopFlags) argValues[1] = arguments[1]->eval();
            if (!__context__->stopFlags) argValues[2] = arguments[2]->eval();
            if (!__context__->stopFlags) argValues[3] = arguments[3]->eval();
    }};

    // FUNCTION CALL
    struct SimNode_CallBase : SimNode {
        SimNode_CallBase ( const LineInfo & at ) : SimNode(at) {}
        void visitCall ( SimVisitor & vis );
        __forceinline void evalArgs ( vec4f * argValues ) {
            for ( int i=0; i!=nArguments && !__context__->stopFlags; ++i ) {
                argValues[i] = arguments[i]->eval();
            }
        }
        SimNode * visitOp1 ( SimVisitor & vis, const char * op );
        SimNode * visitOp2 ( SimVisitor & vis, const char * op );
        SimNode * visitOp3 ( SimVisitor & vis, const char * op );
#define EVAL_NODE(TYPE,CTYPE)\
        virtual CTYPE eval##TYPE ( ) override {   \
            return cast<CTYPE>::to(eval());       \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
        SimNode ** arguments;
        TypeInfo ** types;
        SimFunction * fnPtr = nullptr;
        int32_t  nArguments;
        SimNode * cmresEval = nullptr;
        // uint32_t stackTop = 0;
    };

    // FUNCTION CALL via FASTCALL convention
    template <int argCount>
    struct SimNode_FastCall : SimNode_CallBase {
        SimNode_FastCall ( const LineInfo & at ) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            vec4f argValues[argCount ? argCount : 1];
            EvalBlock<argCount>::eval(arguments, argValues);
            auto aa = __context__->abiArg;
            __context__->abiArg = argValues;
            auto res = fnPtr->code->eval();
            __context__->stopFlags &= ~(EvalFlags::stopForReturn | EvalFlags::stopForBreak);
            __context__->abiArg = aa;
            return res;
        }
#define EVAL_NODE(TYPE,CTYPE)\
        virtual CTYPE eval##TYPE ( ) override {                                                 \
                vec4f argValues[argCount ? argCount : 1];                                       \
                EvalBlock<argCount>::eval(arguments, argValues);                       \
                auto aa = __context__->abiArg;                                                       \
                __context__->abiArg = argValues;                                                     \
                auto res = EvalTT<CTYPE>::eval(fnPtr->code);                                    \
                __context__->stopFlags &= ~(EvalFlags::stopForReturn | EvalFlags::stopForBreak);     \
                __context__->abiArg = aa;                                                            \
                return res;                                                                     \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    // FUNCTION CALL
    template <int argCount>
    struct SimNode_Call : SimNode_CallBase {
        SimNode_Call ( const LineInfo & at ) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            vec4f argValues[argCount ? argCount : 1];
            EvalBlock<argCount>::eval(arguments, argValues);
            return __context__->call(fnPtr, argValues, debugInfo.line);
        }
#define EVAL_NODE(TYPE,CTYPE)\
        virtual CTYPE eval##TYPE ( ) override {                                                 \
                vec4f argValues[argCount ? argCount : 1];                                       \
                EvalBlock<argCount>::eval(arguments, argValues);                                \
                return cast<CTYPE>::to(__context__->call(fnPtr, argValues, debugInfo.line));    \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    // FUNCTION CALL with copy-or-move-on-return
    template <int argCount>
    struct SimNode_CallAndCopyOrMove : SimNode_CallBase {
        DAS_PTR_NODE;
        SimNode_CallAndCopyOrMove ( const LineInfo & at ) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
                auto cmres = cmresEval->evalPtr();
                vec4f argValues[argCount ? argCount : 1];
                EvalBlock<argCount>::eval(arguments, argValues);
                return cast<char *>::to(__context__->callWithCopyOnReturn(fnPtr, argValues, cmres, debugInfo.line));
        }
    };

    // Invoke
    template <int argCount>
    struct SimNode_Invoke : SimNode_CallBase {
        SimNode_Invoke ( const LineInfo & at ) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            vec4f argValues[argCount ? argCount : 1];
            EvalBlock<argCount>::eval(arguments, argValues);
            Block * block = cast<Block *>::to(argValues[0]);
            if ( argCount>1 ) {
                return __context__->invoke(*block, argValues + 1, nullptr);
            } else {
                return __context__->invoke(*block, nullptr, nullptr);
            }
        }
#define EVAL_NODE(TYPE,CTYPE)                                                                   \
        virtual CTYPE eval##TYPE ( ) override {                                                 \
            vec4f argValues[argCount ? argCount : 1];                                           \
            EvalBlock<argCount>::eval(arguments, argValues);                           \
            Block * block = cast<Block *>::to(argValues[0]);                                    \
            if ( argCount>1 ) {                                                                 \
                return cast<CTYPE>::to(__context__->invoke(*block, argValues + 1, nullptr));    \
            } else {                                                                            \
                return cast<CTYPE>::to(__context__->invoke(*block, nullptr, nullptr));          \
            }                                                                                   \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    // Invoke with copy-or-move-on-return
    template <int argCount>
    struct SimNode_InvokeAndCopyOrMove : SimNode_CallBase {
        SimNode_InvokeAndCopyOrMove ( const LineInfo & at, SimNode * spCMRES )
            : SimNode_CallBase(at) { cmresEval = spCMRES; }
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto cmres = cmresEval->evalPtr();
            vec4f argValues[argCount ? argCount : 1];
            EvalBlock<argCount>::eval(arguments, argValues);
            Block * block = cast<Block *>::to(argValues[0]);
            if ( argCount>1 ) {
                return __context__->invoke(*block, argValues + 1, cmres);
            } else {
                return __context__->invoke(*block, nullptr, cmres);
            }
        }
#define EVAL_NODE(TYPE,CTYPE)                                                                   \
        virtual CTYPE eval##TYPE ( ) override {                                                 \
            auto cmres = cmresEval->evalPtr();                                           \
            vec4f argValues[argCount ? argCount : 1];                                           \
            EvalBlock<argCount>::eval(arguments, argValues);                           \
            Block * block = cast<Block *>::to(argValues[0]);                                    \
            if ( argCount>1 ) {                                                                 \
                return cast<CTYPE>::to(__context__->invoke(*block, argValues + 1, cmres));      \
            } else {                                                                            \
                return cast<CTYPE>::to(__context__->invoke(*block, nullptr, cmres));            \
            }                                                                                   \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    // Invoke function
    template <int argCount>
    struct SimNode_InvokeFn : SimNode_CallBase {
        SimNode_InvokeFn ( const LineInfo & at ) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            vec4f argValues[argCount ? argCount : 1];
            EvalBlock<argCount>::eval(arguments, argValues);
            SimFunction * simFunc = __context__->getFunction(cast<Func>::to(argValues[0]).index-1);
            if (!simFunc) __context__->throw_error_at(debugInfo,"invoke null function");
            if ( argCount>1 ) {
                return __context__->call(simFunc, argValues + 1, debugInfo.line);
            } else {
                return __context__->call(simFunc, nullptr, debugInfo.line);
            }
        }
#define EVAL_NODE(TYPE,CTYPE)                                                                   \
        virtual CTYPE eval##TYPE ( ) override {                                                 \
            vec4f argValues[argCount ? argCount : 1];                                           \
            EvalBlock<argCount>::eval(arguments, argValues);                           \
            SimFunction * simFunc = __context__->getFunction(cast<Func>::to(argValues[0]).index-1);  \
            if (!simFunc) __context__->throw_error_at(debugInfo,"invoke null function");             \
            if ( argCount>1 ) {                                                                 \
                return cast<CTYPE>::to(__context__->call(simFunc, argValues + 1, debugInfo.line));   \
            } else {                                                                            \
                return cast<CTYPE>::to(__context__->call(simFunc, nullptr, debugInfo.line));    \
            }                                                                                   \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    // Invoke function
    template <int argCount>
    struct SimNode_InvokeLambda : SimNode_CallBase {
        SimNode_InvokeLambda ( const LineInfo & at ) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            vec4f argValues[argCount ? argCount : 1];
            EvalBlock<argCount>::eval(arguments, argValues);
            int32_t * fnIndex = (int32_t *) cast<char *>::to(argValues[0]);
            if (!fnIndex) __context__->throw_error_at(debugInfo,"invoke null lambda");
            SimFunction * simFunc = __context__->getFunction(*fnIndex-1);
            if (!simFunc) __context__->throw_error_at(debugInfo,"invoke null function");
            return __context__->call(simFunc, argValues, debugInfo.line);
        }
#define EVAL_NODE(TYPE,CTYPE)                                                                   \
        virtual CTYPE eval##TYPE (  ) override {                                                \
            vec4f argValues[argCount ? argCount : 1];                                           \
            EvalBlock<argCount>::eval(arguments, argValues);                           \
            int32_t * fnIndex = (int32_t *) cast<char *>::to(argValues[0]);                     \
            if (!fnIndex) __context__->throw_error_at(debugInfo,"invoke null lambda");               \
            SimFunction * simFunc = __context__->getFunction(*fnIndex-1);                            \
            if (!simFunc) __context__->throw_error_at(debugInfo,"invoke null function");             \
            return cast<CTYPE>::to(__context__->call(simFunc, argValues, debugInfo.line));      \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    // Invoke function with copy-or-move-on-return
    template <int argCount>
    struct SimNode_InvokeAndCopyOrMoveFn : SimNode_CallBase {
        SimNode_InvokeAndCopyOrMoveFn ( const LineInfo & at, SimNode * spEval )
            : SimNode_CallBase(at) { cmresEval = spEval; }
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            auto cmres = cmresEval->evalPtr();
            vec4f argValues[argCount ? argCount : 1];
            EvalBlock<argCount>::eval(arguments, argValues);
            SimFunction * simFunc = __context__->getFunction(cast<Func>::to(argValues[0]).index-1);
            if (!simFunc) __context__->throw_error_at(debugInfo,"invoke null function");
            if ( argCount>1 ) {
                return __context__->callWithCopyOnReturn(simFunc, argValues + 1, cmres, debugInfo.line);
            } else {
                return __context__->callWithCopyOnReturn(simFunc, nullptr, cmres, debugInfo.line);
            }
        }
#define EVAL_NODE(TYPE,CTYPE)                                                                       \
        virtual CTYPE eval##TYPE ( ) override {                                                     \
            auto cmres = cmresEval->evalPtr();                                               \
            vec4f argValues[argCount ? argCount : 1];                                               \
            EvalBlock<argCount>::eval(arguments, argValues);                               \
            SimFunction * simFunc = __context__->getFunction(cast<Func>::to(argValues[0]).index-1);      \
            if (!simFunc) __context__->throw_error_at(debugInfo,"invoke null function");                 \
            if ( argCount>1 ) {                                                                     \
                return cast<CTYPE>::to(__context__->callWithCopyOnReturn(simFunc, argValues + 1, cmres, debugInfo.line)); \
            } else {                                                                                \
                return cast<CTYPE>::to(__context__->callWithCopyOnReturn(simFunc, nullptr, cmres, debugInfo.line)); \
            }                                                                                       \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    // Invoke function
    template <int argCount>
    struct SimNode_InvokeAndCopyOrMoveLambda : SimNode_CallBase {
        SimNode_InvokeAndCopyOrMoveLambda ( const LineInfo & at, SimNode * spEval )
            : SimNode_CallBase(at) { cmresEval = spEval; }
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto cmres = cmresEval->evalPtr();
            vec4f argValues[argCount ? argCount : 1];
            EvalBlock<argCount>::eval(arguments, argValues);
            int32_t * fnIndex = (int32_t *) cast<char *>::to(argValues[0]);
            if (!fnIndex) __context__->throw_error_at(debugInfo,"invoke null lambda");
            SimFunction * simFunc = __context__->getFunction(*fnIndex-1);
            if (!simFunc) __context__->throw_error_at(debugInfo,"invoke null function");
            return __context__->callWithCopyOnReturn(simFunc, argValues, cmres, debugInfo.line);
        }
#define EVAL_NODE(TYPE,CTYPE)                                                                   \
        virtual CTYPE eval##TYPE (  ) override {                                                \
            auto cmres = cmresEval->evalPtr();                                                  \
            vec4f argValues[argCount ? argCount : 1];                                           \
            EvalBlock<argCount>::eval(arguments, argValues);                           \
            int32_t * fnIndex = (int32_t *) cast<char *>::to(argValues[0]);                     \
            if (!fnIndex) __context__->throw_error_at(debugInfo,"invoke null lambda");               \
            SimFunction * simFunc = __context__->getFunction(*fnIndex-1);                            \
            if (!simFunc) __context__->throw_error_at(debugInfo,"invoke null function");             \
            return cast<CTYPE>::to(__context__->callWithCopyOnReturn(simFunc, argValues, cmres, debugInfo.line));    \
        }
        DAS_EVAL_NODE
#undef  EVAL_NODE
    };

    // StringBuilder
    struct SimNode_StringBuilder : SimNode_CallBase {
        SimNode_StringBuilder ( const LineInfo & at ) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        TypeInfo ** types;
    };

    // CAST
    template <typename CastTo, typename CastFrom>
    struct SimNode_Cast : SimNode_CallBase {
        SimNode_Cast ( const LineInfo & at ) : SimNode_CallBase(at) { }
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            vec4f res = arguments[0]->eval();
            CastTo value = (CastTo) cast<CastFrom>::to(res);
            return cast<CastTo>::from(value);
        }
    };

    // LEXICAL CAST
    template <typename CastFrom>
    struct SimNode_LexicalCast : SimNode_CallBase {
        SimNode_LexicalCast ( const LineInfo & at ) : SimNode_CallBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            vec4f res = arguments[0]->eval();
            auto str = to_string ( cast<CastFrom>::to(res) );
            auto cpy = __context__->heap.allocateString(str);
            if ( !cpy ) {
                __context__->throw_error_at(debugInfo,"can't cast to string, out of heap");
                return v_zero();
            }
            return cast<char *>::from(cpy);
        }
    };

    // "DEBUG"
    struct SimNode_Debug : SimNode {
        SimNode_Debug ( const LineInfo & at, SimNode * s, TypeInfo * ti, char * msg )
            : SimNode(at), subexpr(s), typeInfo(ti), message(msg) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        SimNode *       subexpr;
        TypeInfo *      typeInfo;
        const char *    message;
    };

    // CMRES "GET" + OFFSET
    struct SimNode_GetCMResOfs : SimNode {
        DAS_PTR_NODE;
        SimNode_GetCMResOfs(const LineInfo & at, uint32_t o)
            : SimNode(at), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            return __context__->abiCopyOrMoveResult() + offset;
        }
        uint32_t offset;
    };

    template <typename TT>
    struct SimNode_GetCMResOfsR2V : SimNode_GetCMResOfs {
        SimNode_GetCMResOfsR2V(const LineInfo & at, uint32_t o)
            : SimNode_GetCMResOfs(at,o)  {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pR = (TT *)compute();
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                     \
        virtual CTYPE eval##TYPE ( ) override {   \
            return *(CTYPE *)compute();           \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    // BLOCK CMRES "GET" + OFFSET
    struct SimNode_GetBlockCMResOfs : SimNode {
        DAS_PTR_NODE;
        SimNode_GetBlockCMResOfs(const LineInfo & at, uint32_t o, uint32_t asp)
            : SimNode(at), offset(o), argStackTop(asp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            auto ba = (BlockArguments *) ( __context__->stack.sp() + argStackTop );
            return ba->copyOrMoveResult + offset;
        }
        uint32_t offset, argStackTop;
    };

    // LOCAL VARIABLE "GET"
    struct SimNode_GetLocal : SimNode {
        DAS_PTR_NODE;
        SimNode_GetLocal(const LineInfo & at, uint32_t sp)
            : SimNode(at), stackTop(sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            return __context__->stack.sp() + stackTop;
        }
        uint32_t stackTop;
    };

    template <typename TT>
    struct SimNode_GetLocalR2V : SimNode_GetLocal {
        SimNode_GetLocalR2V(const LineInfo & at, uint32_t sp)
            : SimNode_GetLocal(at,sp)  {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pR = (TT *)(__context__->stack.sp() + stackTop);
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                                      \
        virtual CTYPE eval##TYPE ( ) override {                    \
            return *(CTYPE *)(__context__->stack.sp() + stackTop); \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    // WHEN LOCAL VARIABLE STORES REFERENCE
    struct SimNode_GetLocalRef : SimNode_GetLocal {
        DAS_PTR_NODE;
        SimNode_GetLocalRef(const LineInfo & at, uint32_t sp)
            : SimNode_GetLocal(at,sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute (  ) {
            return *(char **)(__context__->stack.sp() + stackTop);
        }
    };

    template <typename TT>
    struct SimNode_GetLocalRefR2V : SimNode_GetLocalRef {
        SimNode_GetLocalRefR2V(const LineInfo & at, uint32_t sp)
            : SimNode_GetLocalRef(at,sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            TT * pR = *(TT **)(__context__->stack.sp() + stackTop);
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {   \
            return **(CTYPE **)(__context__->stack.sp() + stackTop);     \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    // WHEN LOCAL VARIABLE STORES REFERENCE
    struct SimNode_GetLocalRefOff : SimNode_GetLocal {
        DAS_PTR_NODE;
        SimNode_GetLocalRefOff(const LineInfo & at, uint32_t sp, uint32_t o)
            : SimNode_GetLocal(at,sp), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            return (*(char **)(__context__->stack.sp() + stackTop)) + offset;
        }
        uint32_t offset;
    };

    template <typename TT>
    struct SimNode_GetLocalRefR2VOff : SimNode_GetLocalRef {
        SimNode_GetLocalRefR2VOff(const LineInfo & at, uint32_t sp, uint32_t o)
            : SimNode_GetLocalRef(at,sp), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            TT * pR = (TT *)((*(char **)(__context__->stack.sp() + stackTop)) + offset);
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {   \
            return *(CTYPE *)((*(char **)(__context__->stack.sp() + stackTop)) + offset); \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
        uint32_t offset;
    };

    template <typename TT>
    struct SimNode_SetLocalRefRefOffT : SimNode {
        SimNode_SetLocalRefRefOffT(const LineInfo & at, SimNode * rv, uint32_t sp, uint32_t o)
            : SimNode(at), value(rv), stackTop(sp), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto pr = (TT *) value->evalPtr();
            TT * pL = (TT *)((*(char **)(__context__->stack.sp() + stackTop)) + offset);
            *pL = *pr;
            return v_zero();
        }
        SimNode * value;
        uint32_t stackTop;
        uint32_t offset;
    };

    template <typename TT>
    struct SimNode_SetLocalValueRefOffT : SimNode {
        SimNode_SetLocalValueRefOffT(const LineInfo & at, SimNode * rv, uint32_t sp, uint32_t o)
            : SimNode(at), value(rv), stackTop(sp), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            TT * pL = (TT *)((*(char **)(__context__->stack.sp() + stackTop)) + offset);
            *pL = EvalTT<TT>::eval(value);
            return v_zero();
        }
        SimNode * value;
        uint32_t stackTop;
        uint32_t offset;
    };

    template <typename TT>
    struct SimNode_CopyLocal2LocalT : SimNode {
        SimNode_CopyLocal2LocalT(const LineInfo & at, uint32_t spL, uint32_t spR)
            : SimNode(at), stackTopLeft(spL), stackTopRight(spR) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pl = (TT *) ( __context__->stack.sp() + stackTopLeft );
            TT * pr = (TT *) ( __context__->stack.sp() + stackTopRight );
            *pl = *pr;
            return v_zero();
        }
        uint32_t stackTopLeft, stackTopRight;
    };

    template <typename TT>
    struct SimNode_SetLocalRefT : SimNode {
        SimNode_SetLocalRefT(const LineInfo & at, SimNode * rv, uint32_t sp)
            : SimNode(at), value(rv), stackTop(sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto pr = (TT *) value->evalPtr();
            TT * pl = (TT *) ( __context__->stack.sp() + stackTop );
            *pl = *pr;
            return v_zero();
        }
        SimNode * value;
        uint32_t stackTop;
    };

    template <typename TT>
    struct SimNode_SetLocalValueT : SimNode {
        SimNode_SetLocalValueT(const LineInfo & at, SimNode * rv, uint32_t sp)
            : SimNode(at), value(rv), stackTop(sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pl = (TT *) ( __context__->stack.sp() + stackTop );
            *pl = EvalTT<TT>::eval(value);
            return v_zero();
        }
        SimNode * value;
        uint32_t stackTop;
    };

    template <typename TT>
    struct SimNode_SetCMResRefT : SimNode {
        SimNode_SetCMResRefT(const LineInfo & at, SimNode * rv, uint32_t o)
            : SimNode(at), value(rv), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto pr = (TT *) value->evalPtr();
            TT * pl = (TT *) ( __context__->abiCopyOrMoveResult() + offset );
            *pl = *pr;
            return v_zero();
        }
        SimNode * value;
        uint32_t offset;
    };

    template <typename TT>
    struct SimNode_SetCMResValueT : SimNode {
        SimNode_SetCMResValueT(const LineInfo & at, SimNode * rv, uint32_t o)
            : SimNode(at), value(rv), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pl = (TT *) ( __context__->abiCopyOrMoveResult() + offset );
            *pl = EvalTT<TT>::eval(value);
            return v_zero();
        }
        SimNode * value;
        uint32_t offset;
    };

    // AT (INDEX)
    struct SimNode_SetLocalRefAndEval : SimNode {
        DAS_PTR_NODE;
        SimNode_SetLocalRefAndEval ( const LineInfo & at, SimNode * rv, SimNode * ev, uint32_t sp )
            : SimNode(at), refValue(rv), evalValue(ev), stackTop(sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute () {
            auto refV = refValue->evalPtr();
            auto pR = (char **)(__context__->stack.sp() + stackTop);
            *pR = refV;
            evalValue->eval();
            return refV;
        }
        SimNode * refValue, * evalValue;
        uint32_t  stackTop;
    };

    // ZERO MEMORY OF UNITIALIZED LOCAL VARIABLE
    struct SimNode_InitLocal : SimNode {
        SimNode_InitLocal(const LineInfo & at, uint32_t sp, uint32_t sz)
            : SimNode(at), stackTop(sp), size(sz) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            memset(__context__->stack.sp() + stackTop, 0, size);
            return v_zero();
        }
        uint32_t stackTop, size;
    };

    // ZERO MEMORY OF UNITIALIZED CMRES LOCAL VARIABLE
    struct SimNode_InitLocalCMRes : SimNode {
        SimNode_InitLocalCMRes(const LineInfo & at, uint32_t o, uint32_t sz)
            : SimNode(at), offset(o), size(sz) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            memset(__context__->abiCopyOrMoveResult() + offset, 0, size);
            return v_zero();
        }
        uint32_t offset, size;
    };

    // ZERO MEMORY OF UNITIALIZED LOCAL VARIABLE VIA REFERENCE AND OFFSET
    struct SimNode_InitLocalRef : SimNode {
        SimNode_InitLocalRef(const LineInfo & at, uint32_t sp, uint32_t o, uint32_t sz)
            : SimNode(at), stackTop(sp), offset(o), size(sz) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            char * pI = *((char **)(__context__->stack.sp() + stackTop)) + offset;
            memset(pI, 0, size);
            return v_zero();
        }
        uint32_t stackTop, offset, size;
    };

    // ARGUMENT VARIABLE "GET"
    struct SimNode_GetArgument : SimNode {
        SimNode_GetArgument ( const LineInfo & at, int32_t i )
            : SimNode(at), index(i) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            return __context__->abiArguments()[index];
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {   \
            return cast<CTYPE>::to(__context__->abiArguments()[index]);  \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
        int32_t index;
    };

    struct SimNode_GetArgumentRef : SimNode_GetArgument {
        DAS_PTR_NODE;
        SimNode_GetArgumentRef(const LineInfo & at, int32_t i)
            : SimNode_GetArgument(at,i) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute() {
            return (char *)(&__context__->abiArguments()[index]);
        }
    };

    template <typename TT>
    struct SimNode_GetArgumentR2V : SimNode_GetArgument {
        SimNode_GetArgumentR2V ( const LineInfo & at, int32_t i )
            : SimNode_GetArgument(at,i) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pR = cast<TT *>::to(__context__->abiArguments()[index]);
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                                               \
        virtual CTYPE eval##TYPE ( ) override {           \
            return * cast<CTYPE *>::to(__context__->abiArguments()[index]);      \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    struct SimNode_GetArgumentOff : SimNode_GetArgument {
        DAS_PTR_NODE;
        SimNode_GetArgumentOff(const LineInfo & at, int32_t i, uint32_t o)
            : SimNode_GetArgument(at,i), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute() {
            char * pR = cast<char *>::to(__context__->abiArguments()[index]);
            return pR + offset;
        }
        uint32_t offset;
    };

    template <typename TT>
    struct SimNode_GetArgumentR2VOff : SimNode_GetArgument {
        SimNode_GetArgumentR2VOff ( const LineInfo & at, int32_t i, uint32_t o )
            : SimNode_GetArgument(at,i), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            char * pR = cast<char *>::to(__context__->abiArguments()[index]);
            return cast<TT>::from(*((TT *)(pR+offset)));
        }
#define EVAL_NODE(TYPE,CTYPE)                                               \
        virtual CTYPE eval##TYPE (  ) override {           \
            char * pR = cast<char *>::to(__context__->abiArguments()[index]);    \
            return *(CTYPE *)(pR + offset);                                 \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
        uint32_t offset;
    };

    // BLOCK VARIABLE "GET"
    struct SimNode_GetBlockArgument : SimNode {
        SimNode_GetBlockArgument ( const LineInfo & at, int32_t i, uint32_t sp )
            : SimNode(at), index(i), stackTop(sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            vec4f * args = *((vec4f **)(__context__->stack.sp() + stackTop));
            return args[index];
        }
#define EVAL_NODE(TYPE,CTYPE)                                               \
        virtual CTYPE eval##TYPE (  ) override {           \
            vec4f * args = *((vec4f **)(__context__->stack.sp() + stackTop));    \
            return cast<CTYPE>::to(args[index]);                            \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
        int32_t     index;
        uint32_t    stackTop;
    };

    template <typename TT>
    struct SimNode_GetBlockArgumentR2V : SimNode_GetBlockArgument {
        SimNode_GetBlockArgumentR2V ( const LineInfo & at, int32_t i, uint32_t sp )
            : SimNode_GetBlockArgument(at,i,sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            vec4f * args = *((vec4f **)(__context__->stack.sp() + stackTop));
            TT * pR = (TT *) cast<char *>::to(args[index]);
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                                               \
        virtual CTYPE eval##TYPE ( ) override {           \
            vec4f * args = *((vec4f **)(__context__->stack.sp() + stackTop));    \
            return * cast<CTYPE *>::to(args[index]);                        \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    struct SimNode_GetBlockArgumentRef : SimNode_GetBlockArgument {
        DAS_PTR_NODE;
        SimNode_GetBlockArgumentRef(const LineInfo & at, int32_t i, uint32_t sp)
            : SimNode_GetBlockArgument(at,i,sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute() {
            vec4f * args = *((vec4f **)(__context__->stack.sp() + stackTop));
            return (char *)(&args[index]);
        }
    };

    // GLOBAL VARIABLE "GET"
    struct SimNode_GetGlobal : SimNode {
        DAS_PTR_NODE;
        SimNode_GetGlobal ( const LineInfo & at, uint32_t o )
            : SimNode(at), offset(o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute () {
            return __context__->globals + offset;
        }
        uint32_t    offset;
    };

    template <typename TT>
    struct SimNode_GetGlobalR2V : SimNode_GetGlobal {
        SimNode_GetGlobalR2V ( const LineInfo & at, uint32_t o )
            : SimNode_GetGlobal(at,o) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval () override {
            TT * pR = (TT *)(__context__->globals + offset);
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE (  ) override {   \
            return *(CTYPE *)(__context__->globals + offset);            \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    // TRY-CATCH
    struct SimNode_TryCatch : SimNode {
        SimNode_TryCatch ( const LineInfo & at, SimNode * t, SimNode * c )
            : SimNode(at), try_block(t), catch_block(c) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
        SimNode * try_block, * catch_block;
    };

    // RETURN
    struct SimNode_Return : SimNode {
        SimNode_Return ( const LineInfo & at, SimNode * s )
            : SimNode(at), subexpr(s) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
        SimNode * subexpr;
    };

    struct SimNode_ReturnConst : SimNode {
        SimNode_ReturnConst ( const LineInfo & at, vec4f v )
            : SimNode(at), value(v) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
        vec4f value;
    };

    struct SimNode_ReturnAndCopy : SimNode_Return {
        SimNode_ReturnAndCopy ( const LineInfo & at, SimNode * s, uint32_t sz )
            : SimNode_Return(at,s), size(sz) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
        uint32_t size;
    };

    struct SimNode_ReturnRefAndEval : SimNode_Return {
        SimNode_ReturnRefAndEval ( const LineInfo & at, SimNode * s, uint32_t sp )
            : SimNode_Return(at,s), stackTop(sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
        uint32_t stackTop;
    };

    struct SimNode_ReturnAndMove : SimNode_ReturnAndCopy {
        SimNode_ReturnAndMove ( const LineInfo & at, SimNode * s, uint32_t sz )
            : SimNode_ReturnAndCopy(at,s,sz) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
    };

    struct SimNode_ReturnReference : SimNode_Return {
        SimNode_ReturnReference ( const LineInfo & at, SimNode * s )
            : SimNode_Return(at,s) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
    };

    struct SimNode_ReturnRefAndEvalFromBlock : SimNode_Return {
        SimNode_ReturnRefAndEvalFromBlock ( const LineInfo & at, SimNode * s, uint32_t sp, uint32_t asp )
            : SimNode_Return(at,s), stackTop(sp), argStackTop(asp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
        uint32_t stackTop, argStackTop;
    };

    struct SimNode_ReturnAndCopyFromBlock : SimNode_ReturnAndCopy {
        SimNode_ReturnAndCopyFromBlock ( const LineInfo & at, SimNode * s, uint32_t sz, uint32_t asp )
            : SimNode_ReturnAndCopy(at,s,sz), argStackTop(asp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
        uint32_t argStackTop;
    };

    struct SimNode_ReturnAndMoveFromBlock : SimNode_ReturnAndCopyFromBlock {
        SimNode_ReturnAndMoveFromBlock ( const LineInfo & at, SimNode * s, uint32_t sz, uint32_t asp )
            : SimNode_ReturnAndCopyFromBlock(at,s,sz, asp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
    };

    struct SimNode_ReturnReferenceFromBlock : SimNode_Return {
        SimNode_ReturnReferenceFromBlock ( const LineInfo & at, SimNode * s )
            : SimNode_Return(at,s) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
    };

    // BREAK
    struct SimNode_Break : SimNode {
        SimNode_Break ( const LineInfo & at ) : SimNode(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            __context__->stopFlags |= EvalFlags::stopForBreak;
            return v_zero();
        }
    };

    // DEREFERENCE
    template <typename TT>
    struct SimNode_Ref2Value : SimNode {      // &value -> value
        SimNode_Ref2Value ( const LineInfo & at, SimNode * s )
            : SimNode(at), subexpr(s) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            TT * pR = (TT *) subexpr->evalPtr();
            return cast<TT>::from(*pR);
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE () override {     \
            auto pR = (CTYPE *)subexpr->evalPtr();           \
            return *pR;                                             \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
        SimNode * subexpr;
    };

    // POINTER TO REFERENCE (CAST)
    struct SimNode_Ptr2Ref : SimNode {      // ptr -> &value
        DAS_PTR_NODE;
        SimNode_Ptr2Ref ( const LineInfo & at, SimNode * s )
            : SimNode(at), subexpr(s) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            auto ptr = subexpr->evalPtr();
            if ( !ptr ) {
                __context__->throw_error_at(debugInfo,"dereferencing null pointer");
            }
            return ptr;
        }
        SimNode * subexpr;
    };

    // let(a:int?) x = a && 0
    template <typename TT>
    struct SimNode_NullCoalescing : SimNode_Ptr2Ref {
        SimNode_NullCoalescing ( const LineInfo & at, SimNode * s, SimNode * dv )
            : SimNode_Ptr2Ref(at,s), value(dv) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pR = (TT *) subexpr->evalPtr();
            return pR ? cast<TT>::from(*pR) : value->eval();
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {   \
            auto pR = (CTYPE *) subexpr->evalPtr();          \
            return pR ? *pR : value->eval##TYPE();           \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
        SimNode * value;
    };

    // let(a:int?) x = a && default_a
    struct SimNode_NullCoalescingRef : SimNode_Ptr2Ref {
        DAS_PTR_NODE;
        SimNode_NullCoalescingRef ( const LineInfo & at, SimNode * s, SimNode * dv )
            : SimNode_Ptr2Ref(at,s), value(dv) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            auto ptr = subexpr->evalPtr();
            return ptr ? ptr : value->evalPtr();
        }
        SimNode * value;
    };

    // NEW
    struct SimNode_New : SimNode {
        DAS_PTR_NODE;
        SimNode_New ( const LineInfo & at, int32_t b )
            : SimNode(at), bytes(b) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            if ( char * ptr = (char *) __context__->heap.allocate(bytes) ) {
                memset ( ptr, 0, bytes );
                return ptr;
            } else {
                __context__->throw_error_at(debugInfo,"out of heap");
                return nullptr;
            }
        }
        int32_t     bytes;
    };

    template <bool move>
    struct SimNode_Ascend : SimNode {
        DAS_PTR_NODE;
        SimNode_Ascend ( const LineInfo & at, SimNode * se, uint32_t b )
            : SimNode(at), subexpr(se), bytes(b) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            if ( char * ptr = (char *) __context__->heap.allocate(bytes) ) {
                auto src = subexpr->evalPtr();
                memcpy ( ptr, src, bytes );
                if ( move ) {
                    memset ( src, 0, bytes );
                }
                return ptr;
            } else {
                __context__->throw_error_at(debugInfo,"out of heap");
                return nullptr;
            }
        }
        SimNode *   subexpr;
        uint32_t    bytes;
    };

    template <bool move>
    struct SimNode_AscendAndRef : SimNode {
        DAS_PTR_NODE;
        SimNode_AscendAndRef ( const LineInfo & at, SimNode * se, uint32_t b, uint32_t sp )
            : SimNode(at), subexpr(se), bytes(b), stackTop(sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            if ( char * ptr = (char *) __context__->heap.allocate(bytes) ) {
                memset ( ptr, 0, bytes );
                char ** pRef = (char **)(__context__->stack.sp()+stackTop);
                *pRef = ptr;
                subexpr->evalPtr();
                return ptr;
            } else {
                __context__->throw_error_at(debugInfo,"out of heap");
                return nullptr;
            }
        }
        SimNode *   subexpr;
        uint32_t    bytes;
        uint32_t    stackTop;
    };

    template <int argCount>
    struct SimNode_NewWithInitializer : SimNode_CallBase {
        DAS_PTR_NODE;
        SimNode_NewWithInitializer ( const LineInfo & at, uint32_t b )
            : SimNode_CallBase(at), bytes(b) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            if ( char * ptr = (char *) __context__->heap.allocate(bytes) ) {
                vec4f argValues[argCount ? argCount : 1];
                EvalBlock<argCount>::eval(arguments, argValues);
                __context__->callWithCopyOnReturn(fnPtr, argValues, ptr, debugInfo.line);
                return ptr;
            } else {
                __context__->throw_error_at(debugInfo,"out of heap");
                return nullptr;
            }
        }
        uint32_t     bytes;
    };

    struct SimNode_NewArray : SimNode {
        DAS_PTR_NODE;
        SimNode_NewArray ( const LineInfo & a, SimNode * nn, uint32_t sp, uint32_t c )
            : SimNode(a), newNode(nn), stackTop(sp), count(c) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            auto nodes = (char **)(__context__->stack.sp() + stackTop);
            for ( uint32_t i=0; i!=count; ++i ) {
                nodes[i] = newNode->evalPtr();
            }
            return (char *) nodes;
        }
        SimNode *   newNode;
        uint32_t    stackTop;
        uint32_t    count;
    };

    // CONST-VALUE
    struct SimNode_ConstValue : SimNode {
        SimNode_ConstValue(const LineInfo & at, vec4f c)
            : SimNode(at), value(c) { }
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f       eval ()        override { return value; }
        virtual char *      evalPtr()      override { return valuePtr; }
        virtual int32_t     evalInt()      override { return valueI; }
        virtual uint32_t    evalUInt()     override { return valueU; }
        virtual int64_t     evalInt64()    override { return valueI64; }
        virtual uint64_t    evalUInt64()   override { return valueU64; }
        virtual float       evalFloat()    override { return valueF; }
        virtual double      evalDouble()   override { return valueLF; }
        virtual bool        evalBool()     override { return valueB; }
        union {
            vec4f       value;
            char *      valuePtr;
            int32_t     valueI;
            uint32_t    valueU;
            int64_t     valueI64;
            uint64_t    valueU64;
            float       valueF;
            double      valueLF;
            bool        valueB;
        };
    };

    struct SimNode_Zero : SimNode_CallBase {
        SimNode_Zero(const LineInfo & at) : SimNode_CallBase(at) { }
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            return v_zero();
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {            \
            return 0;                                               \
        }
        DAS_EVAL_NODE
#undef EVAL_NODE
    };

    // COPY REFERENCE (int & a = b)
    struct SimNode_CopyReference : SimNode {
        SimNode_CopyReference(const LineInfo & at, SimNode * ll, SimNode * rr)
            : SimNode(at), l(ll), r(rr) {};
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            char  ** pl = (char **) l->evalPtr();
            char * pr = r->evalPtr();
            *pl = pr;
            return v_zero();
        }
        SimNode * l, * r;
    };

    // COPY VALUE
    template <typename TT>
    struct SimNode_CopyValue : SimNode {
        SimNode_CopyValue(const LineInfo & at, SimNode * ll, SimNode * rr)
            : SimNode(at), l(ll), r(rr) {};
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            TT * pl = (TT *) l->evalPtr();
            vec4f rr = r->eval();
            TT * pr = (TT *) &rr;
            *pl = *pr;
            return v_zero();
        }
        SimNode * l, * r;
    };

    // COPY REFERENCE VALUE
    struct SimNode_CopyRefValue : SimNode {
        SimNode_CopyRefValue(const LineInfo & at, SimNode * ll, SimNode * rr, uint32_t sz)
            : SimNode(at), l(ll), r(rr), size(sz) {};
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override;
        SimNode * l, * r;
        uint32_t size;
    };

    template <typename TT>
    struct SimNode_CopyRefValueT : SimNode {
        SimNode_CopyRefValueT(const LineInfo & at, SimNode * ll, SimNode * rr)
            : SimNode(at), l(ll), r(rr) {};
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval (  ) override {
            TT * pl = (TT *) l->evalPtr();
            TT * pr = (TT *) r->evalPtr();
            *pl = *pr;
            return v_zero();
        }
        SimNode * l, * r;
    };

    // MOVE REFERENCE VALUE
    struct SimNode_MoveRefValue : SimNode {
        SimNode_MoveRefValue(const LineInfo & at, SimNode * ll, SimNode * rr, uint32_t sz)
            : SimNode(at), l(ll), r(rr), size(sz) {};
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        SimNode * l, * r;
        uint32_t size;
    };

    struct SimNode_Final : SimNode {
        SimNode_Final ( const LineInfo & a ) : SimNode(a) {}
        void visitFinal ( SimVisitor & vis );
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline void evalFinal ( ) {
            if ( totalFinal ) {
                auto SF = __context__->stopFlags;
                __context__->stopFlags = 0;
                for ( uint32_t i=0; i!=totalFinal; ++i ) {
                    finalList[i]->eval();
                }
                __context__->stopFlags = SF;
            }
        }
        SimNode ** finalList = nullptr;
        uint32_t totalFinal = 0;
    };

    // BLOCK
    struct SimNode_Block : SimNode_Final {
        SimNode_Block ( const LineInfo & at ) : SimNode_Final(at) {}
        void visitBlock ( SimVisitor & vis );
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        SimNode ** list = nullptr;
        uint32_t total = 0;
    };

    struct SimNode_ClosureBlock : SimNode_Block {
        SimNode_ClosureBlock ( const LineInfo & at, bool nr, uint64_t ad )
            : SimNode_Block(at), needResult(nr), annotationData(ad) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        bool needResult = false;
        uint64_t annotationData = 0;
    };

    struct SimNode_MakeLocal : SimNode_Block {
        DAS_PTR_NODE;
        SimNode_MakeLocal ( const LineInfo & at, uint32_t sp )
            : SimNode_Block(at), stackTop(sp) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            for ( uint32_t i = 0; i!=total && !__context__->stopFlags; ) {
                list[i++]->eval();
            }
            return __context__->stack.sp() + stackTop;
        }
        uint32_t stackTop;
    };

    struct SimNode_MakeLocalCMRes : SimNode_Block {
        DAS_PTR_NODE;
        SimNode_MakeLocalCMRes ( const LineInfo & at )
            : SimNode_Block(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        __forceinline char * compute ( ) {
            for ( uint32_t i = 0; i!=total && !__context__->stopFlags; ) {
                list[i++]->eval();
            }
            return __context__->abiCopyOrMoveResult();
        }
    };

    // LET
    struct SimNode_Let : SimNode_Block {
        SimNode_Let ( const LineInfo & at ) : SimNode_Block(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        SimNode * subexpr = nullptr;
    };

    // IF-THEN-ELSE (also Cond)
    struct SimNode_IfThenElse : SimNode {
        SimNode_IfThenElse ( const LineInfo & at, SimNode * c, SimNode * t, SimNode * f )
            : SimNode(at), cond(c), if_true(t), if_false(f) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            bool cmp = cond->evalBool();
            if ( cmp ) {
                return if_true->eval();
            } else {
                return if_false->eval();
            }
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE (  ) override {   \
                bool cmp = cond->evalBool();                 \
                if ( cmp ) {                                        \
                    return if_true->eval##TYPE();            \
                } else {                                            \
                    return if_false->eval##TYPE();           \
                }                                                   \
            }
        DAS_EVAL_NODE
#undef EVAL_NODE
        SimNode * cond, * if_true, * if_false;
    };

    template <typename TT>
    struct SimNode_IfZeroThenElse : SimNode {
        SimNode_IfZeroThenElse ( const LineInfo & at, SimNode * c, SimNode * t, SimNode * f )
            : SimNode(at), cond(c), if_true(t), if_false(f) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto res = EvalTT<TT>::eval(cond);
            if ( res == 0 ) {
                return if_true->eval();
            } else {
                return if_false->eval();
            }
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {   \
                auto res = EvalTT<TT>::eval(cond);          \
                if ( res==0 ) {                                     \
                    return if_true->eval##TYPE();            \
                } else {                                            \
                    return if_false->eval##TYPE();           \
                }                                                   \
            }
        DAS_EVAL_NODE
#undef EVAL_NODE
        SimNode * cond, * if_true, * if_false;
    };

    template <typename TT>
    struct SimNode_IfNotZeroThenElse : SimNode {
        SimNode_IfNotZeroThenElse ( const LineInfo & at, SimNode * c, SimNode * t, SimNode * f )
            : SimNode(at), cond(c), if_true(t), if_false(f) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto res = EvalTT<TT>::eval(cond);
            if ( res != 0 ) {
                return if_true->eval();
            } else {
                return if_false->eval();
            }
        }
#define EVAL_NODE(TYPE,CTYPE)                                       \
        virtual CTYPE eval##TYPE ( ) override {   \
                auto res = EvalTT<TT>::eval(cond);          \
                if ( res!=0 ) {                                     \
                    return if_true->eval##TYPE();            \
                } else {                                            \
                    return if_false->eval##TYPE();           \
                }                                                   \
            }
        DAS_EVAL_NODE
#undef EVAL_NODE
        SimNode * cond, * if_true, * if_false;
    };

    // IF-THEN
    struct SimNode_IfThen : SimNode {
        SimNode_IfThen ( const LineInfo & at, SimNode * c, SimNode * t )
            : SimNode(at), cond(c), if_true(t) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            bool cmp = cond->evalBool();
            if ( cmp ) {
                return if_true->eval();
            } else {
                return v_zero();
            }
        }
        SimNode * cond, * if_true;
    };

    template <typename TT>
    struct SimNode_IfZeroThen : SimNode {
        SimNode_IfZeroThen ( const LineInfo & at, SimNode * c, SimNode * t )
            : SimNode(at), cond(c), if_true(t) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto res = EvalTT<TT>::eval(cond);
            if ( res==0 ) {
                return if_true->eval();
            } else {
                return v_zero();
            }
        }
        SimNode * cond, * if_true;
    };

    template <typename TT>
    struct SimNode_IfNotZeroThen : SimNode {
        SimNode_IfNotZeroThen ( const LineInfo & at, SimNode * c, SimNode * t )
            : SimNode(at), cond(c), if_true(t) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto res = EvalTT<TT>::eval(cond);
            if ( res != 0 ) {
                return if_true->eval();
            } else {
                return v_zero();
            }
        }
        SimNode * cond, * if_true;
    };


    // WHILE
    struct SimNode_While : SimNode_Block {
        SimNode_While ( const LineInfo & at, SimNode * c )
            : SimNode_Block(at), cond(c) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override;
        SimNode * cond;
    };

    template <typename OT, typename Fun, Fun PROP, bool SAFE, typename CTYPE>
    struct SimNode_PropertyImpl : SimNode {
        SimNode_PropertyImpl(const LineInfo & a, SimNode * se)
            : SimNode(a), subexpr(se) {}
        virtual SimNode * visit ( SimVisitor & vis ) override;
        virtual vec4f eval ( ) override {
            auto pv = (OT *) subexpr->evalPtr();
            if ( !pv ) {
                if ( !SAFE ) {
                    __context__->throw_error_at(debugInfo,"Property, dereferencing null pointer");
                }
                return v_zero();
            }
            auto value = (pv->*PROP)();
            return cast<CTYPE>::from(value);
        }
        SimNode * subexpr;
    };

#define IMPLEMENT_PROPERTY(TYPE,CTYPE) \
    template <typename OT, typename Fun, Fun PROP, bool SAFE> \
    struct SimNode_PropertyImpl<OT,Fun,PROP,SAFE,CTYPE> : SimNode { \
        DAS_NODE(TYPE,CTYPE); \
        SimNode_PropertyImpl(const LineInfo & a, SimNode * se) : SimNode(a), subexpr(se) {} \
        virtual SimNode * visit ( SimVisitor & vis ) override { \
            V_BEGIN(); \
            V_OP("PropertyImpl_" #TYPE); \
            V_SUB_OPT(subexpr); \
            V_END(); \
        } \
        __forceinline CTYPE compute() { \
            auto pv = (OT *) subexpr->evalPtr(); \
            if ( !pv ) { \
                if ( !SAFE ) { \
                    __context__->throw_error_at(debugInfo,"Property, dereferencing null pointer"); \
                } \
                return (CTYPE) 0; \
            } \
            return (pv->*PROP)(); \
        } \
        SimNode * subexpr; \
    };

    IMPLEMENT_PROPERTY(Bool,    bool);
    IMPLEMENT_PROPERTY(Int,     int32_t);
    IMPLEMENT_PROPERTY(UInt,    uint32_t);
    IMPLEMENT_PROPERTY(Int64,   int64_t);
    IMPLEMENT_PROPERTY(UInt64,  uint64_t);
    IMPLEMENT_PROPERTY(Float,   float);
    IMPLEMENT_PROPERTY(Ptr,     char *);

    template <typename OT, typename FunT, FunT PROPT, bool SAFET>
    struct SimNode_Property : SimNode_PropertyImpl<OT, FunT, PROPT, SAFET, decltype((((OT *)0)->*PROPT)())> {
        using returnType = decltype((((OT *)0)->*PROPT)());
        SimNode_Property(const LineInfo & a, SimNode * se) :
            SimNode_PropertyImpl<OT,FunT,PROPT,SAFET,returnType>(a,se) {
        }
    };

    // iterator

    struct IteratorContext {
        vec4f value;
        union {
            vec4f tail;
            struct {
                char *  table_end;
                Table * table;
            };
            struct {
                char *  array_end;
                Array * array;
            };
            struct {
                char *  fixed_array_end;
            };
            struct {
                int32_t range_to;
            };
        };
    };

    struct Iterator {
          virtual ~Iterator() {}
        virtual bool first ( IteratorContext & itc ) = 0;
        virtual bool next  ( IteratorContext & itc ) = 0;
        virtual void close ( IteratorContext & itc ) = 0;    // can't throw
    };

    struct SimNode_ForBase : SimNode_Block {
        SimNode_ForBase ( const LineInfo & at ) : SimNode_Block(at) {}
        SimNode * visitFor ( SimVisitor & vis, int total, const char * loopName );
        SimNode *   sources [MAX_FOR_ITERATORS];
        uint32_t    strides [MAX_FOR_ITERATORS];
        uint32_t    stackTop[MAX_FOR_ITERATORS];
        uint32_t    size;
    };

    struct SimNode_ForWithIteratorBase : SimNode_Block {
        SimNode_ForWithIteratorBase ( const LineInfo & at )
            : SimNode_Block(at) {}
        SimNode * visitFor ( SimVisitor & vis, int total );
        SimNode *   source_iterators[MAX_FOR_ITERATORS];
        uint32_t    stackTop[MAX_FOR_ITERATORS];
    };

    template <int totalCount>
    struct SimNode_ForWithIterator : SimNode_ForWithIteratorBase {
        SimNode_ForWithIterator ( const LineInfo & at )
            : SimNode_ForWithIteratorBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override {
            return visitFor(vis, total);
        }
        virtual vec4f eval ( ) override {
            vec4f * pi[totalCount];
            for ( int t=0; t!=totalCount; ++t ) {
                pi[t] = (vec4f *)(__context__->stack.sp() + stackTop[t]);
            }
            Iterator * sources[totalCount] = {};
            for ( int t=0; t!=totalCount; ++t ) {
                vec4f ll = source_iterators[t]->eval();
                sources[t] = cast<Iterator *>::to(ll);
            }
            IteratorContext ph[totalCount];
            bool needLoop = true;
            SimNode ** __restrict tail = list + total;
            for ( int t=0; t!=totalCount; ++t ) {
                needLoop = sources[t]->first(ph[t]) && needLoop;
                if ( __context__->stopFlags ) goto loopend;
            }
            if ( !needLoop ) goto loopend;
            for ( int i=0; !__context__->stopFlags; ++i ) {
                for ( int t=0; t!=totalCount; ++t ){
                    *pi[t] = ph[t].value;
                }
                for (SimNode ** __restrict body = list; body!=tail; ++body) {
                    (*body)->eval();
                    if (__context__->stopFlags) goto loopend;
                }
                for ( int t=0; t!=totalCount; ++t ){
                    if ( !sources[t]->next(ph[t]) ) goto loopend;
                    if ( __context__->stopFlags ) goto loopend;
                }
            }
        loopend:
            evalFinal();
            for ( int t=0; t!=totalCount; ++t ) {
                sources[t]->close(ph[t]);
            }
            __context__->stopFlags &= ~EvalFlags::stopForBreak;
            return v_zero();
        }
    };

    template <>
    struct SimNode_ForWithIterator<0> : SimNode_ForWithIteratorBase {
        SimNode_ForWithIterator ( const LineInfo & at )
            : SimNode_ForWithIteratorBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override {
            V_BEGIN_CR();
            V_OP(ForWithIterator_0);
            V_FINAL();
            V_END();
        }
        virtual vec4f eval (  ) override {
            evalFinal();
            return v_zero();
        }
    };

    template <>
    struct SimNode_ForWithIterator<1> : SimNode_ForWithIteratorBase {
        SimNode_ForWithIterator ( const LineInfo & at )
            : SimNode_ForWithIteratorBase(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override {
            return visitFor(vis, 1);
        }
        virtual vec4f eval ( ) override {
            vec4f * pi = (vec4f *)(__context__->stack.sp() + stackTop[0]);
            Iterator * sources;
            vec4f ll = source_iterators[0]->eval();
            sources = cast<Iterator *>::to(ll);
            IteratorContext ph;
            bool needLoop = true;
            SimNode ** __restrict tail = list + total;
            needLoop = sources->first(ph) && needLoop;
            if ( __context__->stopFlags ) goto loopend;
            for ( int i=0; !__context__->stopFlags; ++i ) {
                *pi = ph.value;
                for (SimNode ** __restrict body = list; body!=tail; ++body) {
                    (*body)->eval();
                    if (__context__->stopFlags) goto loopend;
                }
                if ( !sources->next(ph) ) goto loopend;
                if ( __context__->stopFlags ) goto loopend;
            }
        loopend:
            evalFinal();
            sources->close(ph);
            __context__->stopFlags &= ~EvalFlags::stopForBreak;
            return v_zero();
        }
    };

    struct SimNode_Op1 : SimNode {
        SimNode_Op1 ( const LineInfo & at ) : SimNode(at) {}
        SimNode * visitOp1 ( SimVisitor & vis, const char * op );
        SimNode * x = nullptr;
    };

    struct SimNode_Op2 : SimNode {
        SimNode_Op2 ( const LineInfo & at ) : SimNode(at) {}
        SimNode * visitOp2 ( SimVisitor & vis, const char * op );
        SimNode * l = nullptr;
        SimNode * r = nullptr;
    };

    struct Sim_BoolAnd : SimNode_Op2 {
        DAS_BOOL_NODE;
        Sim_BoolAnd ( const LineInfo & at ) : SimNode_Op2(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override {
            return visitOp2(vis, "BoolAnd");
        }
        __forceinline bool compute ( ) {
            if ( !l->evalBool() ) {      // if not left, then false
                return false;
            } else {
                return r->evalBool();    // if left, then right
            }
        }
    };

    struct Sim_BoolOr : SimNode_Op2 {
        DAS_BOOL_NODE;
        Sim_BoolOr ( const LineInfo & at ) : SimNode_Op2(at) {}
        virtual SimNode * visit ( SimVisitor & vis ) override {
            return visitOp2(vis, "BoolOr");
        }
        __forceinline bool compute ( )  {
            if ( l->evalBool() ) {       // if left, then true
                return true;
            } else {
                return r->evalBool();    // if not left, then right
            }
        }
    };

#define DEFINE_POLICY(CALL) template <typename SimPolicy> struct Sim_##CALL;

#define IMPLEMENT_OP1_POLICY(CALL,TYPE,CTYPE)                           \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op1 {                           \
        DAS_NODE(TYPE,CTYPE);                                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op1(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp1(vis, #CALL);                                \
        }                                                               \
        __forceinline CTYPE compute (  ) {             \
            auto val = x->eval##TYPE();                          \
            return SimPolicy<CTYPE>::CALL(val);                 \
        }                                                               \
    };

#define IMPLEMENT_OP1_FUNCTION_POLICY(CALL,TYPE,CTYPE)                  \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_CallBase {                      \
        DAS_NODE(TYPE,CTYPE);                                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_CallBase(at) {}    \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp1(vis, #CALL);                                \
        }                                                               \
        __forceinline CTYPE compute (  ) {             \
            auto val = arguments[0]->eval##TYPE();               \
            return SimPolicy<CTYPE>::CALL(val);                 \
        }                                                               \
    };

#define IMPLEMENT_OP1_FUNCTION_POLICY_EX(CALL,TYPE,CTYPE,ATYPE,ACTYPE)  \
    template <>                                                         \
    struct Sim_##CALL <ACTYPE> : SimNode_CallBase {                     \
        DAS_NODE(TYPE,CTYPE);                                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_CallBase(at) {}    \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp1(vis, #CALL);                                \
        }                                                               \
        __forceinline CTYPE compute ( ) {             \
            auto val = arguments[0]->eval##ATYPE();              \
            return SimPolicy<ACTYPE>::CALL(val);                \
        }                                                               \
    };

#define IMPLEMENT_OP1_SET_POLICY(CALL,TYPE,CTYPE)                       \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op1 {                           \
        DAS_NODE(TYPE,CTYPE);                                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op1(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp1(vis, #CALL);                                \
        }                                                               \
        __forceinline CTYPE compute ( ) {             \
            auto val = (CTYPE *) x->evalPtr();                   \
            return SimPolicy<CTYPE>::CALL(*val);                \
        }                                                               \
    };

#define IMPLEMENT_OP1_EVAL_POLICY(CALL,CTYPE)                           \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op1 {                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op1(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp1(vis, #CALL);                                \
        }                                                               \
        virtual vec4f eval ( ) override {             \
            auto val = x->eval();                                \
            return SimPolicy<CTYPE>::CALL(val);                 \
        }                                                               \
    };

#define IMPLEMENT_OP1_EVAL_FUNCTION_POLICY(CALL,CTYPE)                  \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_CallBase {                      \
        Sim_##CALL ( const LineInfo & at ) : SimNode_CallBase(at) {}    \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp1(vis, #CALL);                                \
        }                                                               \
        virtual vec4f eval ( ) override {             \
            auto val = arguments[0]->eval();                     \
            return SimPolicy<CTYPE>::CALL(val);                 \
        }                                                               \
    };

#define DEFINE_OP1_NUMERIC_INTEGER(CALL)                \
    IMPLEMENT_OP1_POLICY(CALL,Int,int32_t);             \
    IMPLEMENT_OP1_POLICY(CALL,UInt,uint32_t);           \
    IMPLEMENT_OP1_POLICY(CALL,Int64,int64_t);           \
    IMPLEMENT_OP1_POLICY(CALL,UInt64,uint64_t);         \

#define DEFINE_OP1_NUMERIC(CALL);                       \
    DEFINE_OP1_NUMERIC_INTEGER(CALL);                   \
    IMPLEMENT_OP1_POLICY(CALL,Double,double);           \
    IMPLEMENT_OP1_POLICY(CALL,Float,float);

#define DEFINE_OP1_SET_NUMERIC_INTEGER(CALL)            \
    IMPLEMENT_OP1_SET_POLICY(CALL,Int,int32_t);         \
    IMPLEMENT_OP1_SET_POLICY(CALL,UInt,uint32_t);       \
    IMPLEMENT_OP1_SET_POLICY(CALL,Int64,int64_t);       \
    IMPLEMENT_OP1_SET_POLICY(CALL,UInt64,uint64_t);     \

#define DEFINE_OP1_SET_NUMERIC(CALL);                   \
    DEFINE_OP1_SET_NUMERIC_INTEGER(CALL);               \
    IMPLEMENT_OP1_SET_POLICY(CALL,Double,double);       \
    IMPLEMENT_OP1_SET_POLICY(CALL,Float,float);

#define IMPLEMENT_OP2_POLICY(CALL,TYPE,CTYPE)                           \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op2 {                           \
        DAS_NODE(TYPE,CTYPE);                                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op2(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp2(vis, #CALL);                                \
        }                                                               \
        __forceinline CTYPE compute (  ) {             \
            auto lv = l->eval##TYPE();                           \
            auto rv = r->eval##TYPE();                           \
            return SimPolicy<CTYPE>::CALL(lv,rv);               \
        }                                                               \
    };

#define IMPLEMENT_OP2_FUNCTION_POLICY(CALL,TYPE,CTYPE)                  \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_CallBase {                      \
        DAS_NODE(TYPE,CTYPE);                                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_CallBase(at) {}    \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp2(vis, #CALL);                                \
        }                                                               \
        __forceinline CTYPE compute ( ) {             \
            auto lv = arguments[0]->eval##TYPE();                \
            auto rv = arguments[1]->eval##TYPE();                \
            return SimPolicy<CTYPE>::CALL(lv,rv);               \
        }                                                               \
    };

#define IMPLEMENT_OP2_SET_POLICY(CALL,TYPE,CTYPE)                       \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op2 {                           \
        DAS_NODE(TYPE,CTYPE);                                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op2(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp2(vis, #CALL);                                \
        }                                                               \
        __forceinline CTYPE compute (  ) {             \
            auto lv = (CTYPE *) l->evalPtr();                    \
            auto rv = r->eval##TYPE();                           \
            SimPolicy<CTYPE>::CALL(*lv,rv);                     \
            return CTYPE();                                             \
        }                                                               \
    };

#define IMPLEMENT_OP2_BOOL_POLICY(CALL,TYPE,CTYPE)                      \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op2 {                           \
        DAS_BOOL_NODE;                                                  \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op2(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp2(vis, #CALL);                                \
        }                                                               \
        __forceinline bool compute ( ) {              \
            auto lv = l->eval##TYPE();                           \
            auto rv = r->eval##TYPE();                           \
            return SimPolicy<CTYPE>::CALL(lv,rv);               \
        }                                                               \
    };

#define IMPLEMENT_OP2_EVAL_POLICY(CALL,CTYPE)                           \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op2 {                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op2(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp2(vis, #CALL);                                \
        }                                                               \
        virtual vec4f eval ( ) override {             \
            auto lv = l->eval();                                 \
            auto rv = r->eval();                                 \
            return SimPolicy<CTYPE>::CALL(lv,rv);               \
        }                                                               \
    };

#define IMPLEMENT_OP2_EVAL_FUNCTION_POLICY(CALL,CTYPE)                  \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_CallBase {                      \
        Sim_##CALL ( const LineInfo & at ) : SimNode_CallBase(at) {}    \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp2(vis, #CALL);                                \
        }                                                               \
        virtual vec4f eval ( ) override {             \
            auto lv = arguments[0]->eval();                      \
            auto rv = arguments[1]->eval();                      \
            return SimPolicy<CTYPE>::CALL(lv,rv);               \
        }                                                               \
    };

#define IMPLEMENT_OP2_EVAL_SET_POLICY(CALL,CTYPE)                       \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op2 {                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op2(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp2(vis, #CALL);                                \
        }                                                               \
        virtual vec4f eval ( ) override {             \
            auto lv = l->evalPtr();                              \
            auto rv = r->eval();                                 \
            SimPolicy<CTYPE>::CALL(lv,rv);                      \
            return v_zero();                                            \
        }                                                               \
    };

#define IMPLEMENT_OP2_EVAL_BOOL_POLICY(CALL,CTYPE)                      \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_Op2 {                           \
        DAS_BOOL_NODE;                                                  \
        Sim_##CALL ( const LineInfo & at ) : SimNode_Op2(at) {}         \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp2(vis, #CALL);                                \
        }                                                               \
        __forceinline bool compute ( ) {              \
            auto lv = l->eval();                                 \
            auto rv = r->eval();                                 \
            return SimPolicy<CTYPE>::CALL(lv,rv);               \
        }                                                               \
    };

#define DEFINE_OP2_NUMERIC_INTEGER(CALL)                \
    IMPLEMENT_OP2_POLICY(CALL,Int,int32_t);             \
    IMPLEMENT_OP2_POLICY(CALL,UInt,uint32_t);           \
    IMPLEMENT_OP2_POLICY(CALL,Int64,int64_t);           \
    IMPLEMENT_OP2_POLICY(CALL,UInt64,uint64_t);         \

#define DEFINE_OP2_NUMERIC(CALL);                       \
    DEFINE_OP2_NUMERIC_INTEGER(CALL);                   \
    IMPLEMENT_OP2_POLICY(CALL,Double,double);           \
    IMPLEMENT_OP2_POLICY(CALL,Float,float);

#define DEFINE_OP2_FUNCTION_NUMERIC_INTEGER(CALL)                \
    IMPLEMENT_OP2_FUNCTION_POLICY(CALL,Int,int32_t);             \
    IMPLEMENT_OP2_FUNCTION_POLICY(CALL,UInt,uint32_t);           \
    IMPLEMENT_OP2_FUNCTION_POLICY(CALL,Int64,int64_t);           \
    IMPLEMENT_OP2_FUNCTION_POLICY(CALL,UInt64,uint64_t);         \

#define DEFINE_OP2_FUNCTION_NUMERIC(CALL);                       \
    DEFINE_OP2_FUNCTION_NUMERIC_INTEGER(CALL);                   \
    IMPLEMENT_OP2_FUNCTION_POLICY(CALL,Double,double);           \
    IMPLEMENT_OP2_FUNCTION_POLICY(CALL,Float,float);

#define DEFINE_OP2_BOOL_NUMERIC_INTEGER(CALL)           \
    IMPLEMENT_OP2_BOOL_POLICY(CALL,Int,int32_t);        \
    IMPLEMENT_OP2_BOOL_POLICY(CALL,UInt,uint32_t);      \
    IMPLEMENT_OP2_BOOL_POLICY(CALL,Int64,int64_t);      \
    IMPLEMENT_OP2_BOOL_POLICY(CALL,UInt64,uint64_t);    \

#define DEFINE_OP2_BOOL_NUMERIC(CALL);                  \
    DEFINE_OP2_BOOL_NUMERIC_INTEGER(CALL);              \
    IMPLEMENT_OP2_BOOL_POLICY(CALL,Double,double);      \
    IMPLEMENT_OP2_BOOL_POLICY(CALL,Float,float);

#define DEFINE_OP2_SET_NUMERIC_INTEGER(CALL)            \
    IMPLEMENT_OP2_SET_POLICY(CALL,Int,int32_t);         \
    IMPLEMENT_OP2_SET_POLICY(CALL,UInt,uint32_t);       \
    IMPLEMENT_OP2_SET_POLICY(CALL,Int64,int64_t);       \
    IMPLEMENT_OP2_SET_POLICY(CALL,UInt64,uint64_t);     \

#define DEFINE_OP2_SET_NUMERIC(CALL);                   \
    DEFINE_OP2_SET_NUMERIC_INTEGER(CALL);               \
    IMPLEMENT_OP2_SET_POLICY(CALL,Double,double);       \
    IMPLEMENT_OP2_SET_POLICY(CALL,Float,float);

#define DEFINE_OP2_BASIC_POLICY(TYPE,CTYPE)             \
    IMPLEMENT_OP2_BOOL_POLICY(Equ, TYPE, CTYPE);        \
    IMPLEMENT_OP2_BOOL_POLICY(NotEqu, TYPE, CTYPE);

#define DEFINE_OP2_EVAL_BASIC_POLICY(CTYPE)             \
    IMPLEMENT_OP2_EVAL_BOOL_POLICY(Equ, CTYPE);         \
    IMPLEMENT_OP2_EVAL_BOOL_POLICY(NotEqu, CTYPE);

#define DEFINE_OP2_EVAL_ORDERED_POLICY(CTYPE)           \
    IMPLEMENT_OP2_EVAL_BOOL_POLICY(LessEqu,CTYPE);      \
    IMPLEMENT_OP2_EVAL_BOOL_POLICY(GtEqu,CTYPE);        \
    IMPLEMENT_OP2_EVAL_BOOL_POLICY(Less,CTYPE);         \
    IMPLEMENT_OP2_EVAL_BOOL_POLICY(Gt,CTYPE);

#define DEFINE_OP2_EVAL_GROUPBYADD_POLICY(CTYPE)        \
    IMPLEMENT_OP2_EVAL_POLICY(Add, CTYPE);              \
    IMPLEMENT_OP2_EVAL_SET_POLICY(SetAdd, CTYPE);

#define DEFINE_OP2_EVAL_NUMERIC_POLICY(CTYPE)           \
    DEFINE_OP2_EVAL_GROUPBYADD_POLICY(CTYPE);           \
    IMPLEMENT_OP1_EVAL_POLICY(Unp, CTYPE);              \
    IMPLEMENT_OP1_EVAL_POLICY(Unm, CTYPE);              \
    IMPLEMENT_OP2_EVAL_POLICY(Sub, CTYPE);              \
    IMPLEMENT_OP2_EVAL_POLICY(Div, CTYPE);              \
    IMPLEMENT_OP2_EVAL_POLICY(Mul, CTYPE);              \
    IMPLEMENT_OP2_EVAL_POLICY(Mod, CTYPE);              \
    IMPLEMENT_OP2_EVAL_SET_POLICY(SetSub, CTYPE);       \
    IMPLEMENT_OP2_EVAL_SET_POLICY(SetDiv, CTYPE);       \
    IMPLEMENT_OP2_EVAL_SET_POLICY(SetMul, CTYPE);       \
    IMPLEMENT_OP2_EVAL_SET_POLICY(SetMod, CTYPE);

#define DEFINE_OP2_EVAL_VECNUMERIC_POLICY(CTYPE)        \
    IMPLEMENT_OP2_EVAL_POLICY(DivVecScal, CTYPE);       \
    IMPLEMENT_OP2_EVAL_POLICY(MulVecScal, CTYPE);       \
    IMPLEMENT_OP2_EVAL_POLICY(DivScalVec, CTYPE);       \
    IMPLEMENT_OP2_EVAL_POLICY(MulScalVec, CTYPE);       \
    IMPLEMENT_OP2_EVAL_SET_POLICY(SetDivScal, CTYPE);   \
    IMPLEMENT_OP2_EVAL_SET_POLICY(SetMulScal, CTYPE);

#define DEFINE_VECTOR_POLICY(CTYPE)             \
    DEFINE_OP2_EVAL_BASIC_POLICY(CTYPE);        \
    DEFINE_OP2_EVAL_NUMERIC_POLICY(CTYPE);      \
    DEFINE_OP2_EVAL_VECNUMERIC_POLICY(CTYPE);

#define IMPLEMENT_OP3_FUNCTION_POLICY(CALL,TYPE,CTYPE)                  \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_CallBase {                      \
        DAS_NODE(TYPE,CTYPE);                                           \
        Sim_##CALL ( const LineInfo & at ) : SimNode_CallBase(at) {}    \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp3(vis, #CALL);                                \
        }                                                               \
        __forceinline CTYPE compute ( ) {             \
            auto a0 = arguments[0]->eval##TYPE();                \
            auto a1 = arguments[1]->eval##TYPE();                \
            auto a2 = arguments[2]->eval##TYPE();                \
            return SimPolicy<CTYPE>::CALL(a0,a1,a2);            \
        }                                                               \
    };

#define IMPLEMENT_OP3_EVAL_FUNCTION_POLICY(CALL,CTYPE)                  \
    template <>                                                         \
    struct Sim_##CALL <CTYPE> : SimNode_CallBase {                      \
        Sim_##CALL ( const LineInfo & at ) : SimNode_CallBase(at) {}    \
        virtual SimNode * visit ( SimVisitor & vis ) override {         \
            return visitOp3(vis, #CALL);                                \
        }                                                               \
        virtual vec4f eval ( ) override {             \
            auto a0 = arguments[0]->eval();                      \
            auto a1 = arguments[1]->eval();                      \
            auto a2 = arguments[2]->eval();                      \
            return SimPolicy<CTYPE>::CALL(a0,a1,a2);            \
        }                                                               \
    };

    // unary
    DEFINE_POLICY(Unp);
    DEFINE_POLICY(Unm);
    DEFINE_POLICY(Inc);
    DEFINE_POLICY(Dec);
    DEFINE_POLICY(IncPost);
    DEFINE_POLICY(DecPost);
    DEFINE_POLICY(BinNot);
    DEFINE_POLICY(BoolNot);
    // binary
    // +,-,*,/,%
    DEFINE_POLICY(Add);
    DEFINE_POLICY(Sub);
    DEFINE_POLICY(Mul);
    DEFINE_POLICY(Div);
    DEFINE_POLICY(Mod);
    DEFINE_POLICY(SetAdd);
    DEFINE_POLICY(SetSub);
    DEFINE_POLICY(SetMul);
    DEFINE_POLICY(SetDiv);
    DEFINE_POLICY(SetMod);
    // comparisons
    DEFINE_POLICY(Equ);
    DEFINE_POLICY(NotEqu);
    DEFINE_POLICY(LessEqu);
    DEFINE_POLICY(GtEqu);
    DEFINE_POLICY(Less);
    DEFINE_POLICY(Gt);
    DEFINE_POLICY(Min);
    DEFINE_POLICY(Max);
    // binary and, or, xor
    DEFINE_POLICY(BinAnd);
    DEFINE_POLICY(BinOr);
    DEFINE_POLICY(BinXor);
    DEFINE_POLICY(BinShl);
    DEFINE_POLICY(BinShr);
    DEFINE_POLICY(SetBinAnd);
    DEFINE_POLICY(SetBinOr);
    DEFINE_POLICY(SetBinXor);
    DEFINE_POLICY(SetBinShl);
    DEFINE_POLICY(SetBinShr);
    // boolean and, or, xor
    DEFINE_POLICY(SetBoolAnd);
    DEFINE_POLICY(SetBoolOr);
    DEFINE_POLICY(SetBoolXor);
    DEFINE_POLICY(BoolXor);
    // vector*scalar, scalar*vector
    DEFINE_POLICY(DivVecScal);
    DEFINE_POLICY(MulVecScal);
    DEFINE_POLICY(DivScalVec);
    DEFINE_POLICY(MulScalVec);
    DEFINE_POLICY(SetBoolAnd);
    DEFINE_POLICY(SetBoolOr);
    DEFINE_POLICY(SetBoolXor);
    DEFINE_POLICY(SetDivScal);
    DEFINE_POLICY(SetMulScal);
}

#include "daScript/simulate/simulate_visit.h"
#include "daScript/simulate/simulate_visit_op_undef.h"

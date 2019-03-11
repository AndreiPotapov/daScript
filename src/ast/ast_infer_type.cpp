#include "daScript/misc/platform.h"

#include "daScript/ast/ast.h"
#include "daScript/ast/ast_generate.h"

namespace das {

    class CaptureLambda : public Visitor {
    public:
        virtual void preVisit ( ExprVar * expr ) override {
            auto var = expr->variable;
            if ( expr->local || expr->argumentIndex!=-1 ) {
                if ( scope.find(var) != scope.end() ) {
                    auto varT = var->type;
                    if ( !varT || varT->isAuto() || varT->isAlias() ) {
                        fail = true;
                        return;
                    }
                    capt.insert(var);
                }
            }
        }
        set<VariablePtr>    scope;
        set<VariablePtr>    capt;
        bool                fail = false;
    };


    // type inference

    class InferTypes : public Visitor {
    public:
        InferTypes( const ProgramPtr & prog ) {
            program = prog;
        }
        bool finished() const { return !needRestart; }
    protected:
        ProgramPtr              program;
        FunctionPtr             func;
        vector<VariablePtr>     local;
        vector<ExpressionPtr>   loop;
        vector<ExprBlock *>     blocks;
        vector<ExprBlock *>     scopes;
        vector<ExprWith *>      with;
        vector<size_t>          varStack;
        size_t                  fieldOffset = 0;
        bool                    needRestart = false;
        uint32_t                newLambdaIndex = 1;
    public:
        vector<FunctionPtr>     extraFunctions;
    protected:
        string generateNewLambdaName(const LineInfo & at) {
            return "#lambda#" + to_string(at.line) + "#" + to_string(newLambdaIndex++);
        }
        void pushVarStack() {
            varStack.push_back(local.size());
        }
        void popVarStack()  {
            local.resize(varStack.back());
            varStack.pop_back();
        }
        void error ( const string & err, const LineInfo & at, CompilationError cerr = CompilationError::unspecified ) const {
            if ( func ) {
                string extra = func->getLocationExtra();
                program->error(err + extra,at,cerr);
            } else {
                program->error(err,at,cerr);
            }
        }
        void reportGenericInfer() {
            needRestart = true;
        }
    protected:

        void verifyType ( const TypeDeclPtr & decl ) const {
            if ( decl->dim.size() && decl->ref ) {
                error("can't declare an array of references",decl->at,CompilationError::invalid_type);
            }
            if ( decl->baseType==Type::tVoid ) {
                if ( decl->dim.size() ) {
                    error("can't declare an array of void",decl->at,CompilationError::invalid_type);
                }
                if ( decl->ref ) {
                    error("can't declare a void reference",decl->at,CompilationError::invalid_type);
                }
            } else if ( decl->baseType==Type::tPointer ) {
                if ( auto ptrType = decl->firstType ) {
                    if ( ptrType->ref ) {
                        error("can't declare a pointer to a reference",ptrType->at,CompilationError::invalid_type);
                    }
                    verifyType(ptrType);
                }
            } else if ( decl->baseType==Type::tArray ) {
                if ( auto arrayType = decl->firstType ) {
                    if ( arrayType->ref ) {
                        error("can't declare an array of references",arrayType->at,CompilationError::invalid_array_type);
                    }
                    if ( arrayType->baseType==Type::tVoid) {
                        error("can't declare a void array",arrayType->at,CompilationError::invalid_array_type);
                    }
                    verifyType(arrayType);
                }
            } else if ( decl->baseType==Type::tTable ) {
                if ( auto keyType = decl->firstType ) {
                    if ( keyType->ref ) {
                        error("table key can't be declared as a reference",keyType->at,CompilationError::invalid_table_type);
                    }
                    if ( !keyType->isWorkhorseType() ) {
                        error("table key has to be declare as a basic 'hashable' type",keyType->at,CompilationError::invalid_table_type);
                    }
                    verifyType(keyType);
                }
                if ( auto valueType = decl->secondType ) {
                    if ( valueType->ref ) {
                        error("table value can't be declared as a reference",valueType->at,CompilationError::invalid_table_type);
                    }
                    verifyType(valueType);
                }
            } else if ( decl->baseType==Type::tBlock || decl->baseType==Type::tFunction || decl->baseType==Type::tLambda ) {
                if ( auto resultType = decl->firstType ) {
                    if ( !resultType->isReturnType() ) {
                        error("not a valid return type",resultType->at,CompilationError::invalid_return_type);
                    }
                    verifyType(resultType);
                }
                for ( auto & argType : decl->argTypes ) {
                    if ( argType->ref && argType->isRefType() ) {
                        error("can't pass a boxed type by a reference", argType->at,CompilationError::invalid_argument_type);
                    }
                    verifyType(argType);
                }
            }
        }

        // find type alias name, and resolve it to type
        // without one generic function
        const TypeDecl * findFuncAlias ( const FunctionPtr & fptr, const string & name ) const {
            for ( auto & arg : fptr->arguments ) {
                if ( auto aT = arg->type->findAlias(name,true) ) {
                    return aT;
                }
            }
            for ( auto & gvKV : program->thisModule->globals ) {
                auto & gvar = gvKV.second;
                if ( auto vT = gvar->type->findAlias(name,false) ) {
                    return vT;
                }
            }
            return nullptr;
        }

        // find type alias name, and resolve it to type
        // within current context
        const TypeDecl * findAlias ( const string & name ) const {
            if ( func ) {
                for ( auto it = local.rbegin(); it!=local.rend(); ++it ) {
                    auto & var = *it;
                    if ( auto vT = var->type->findAlias(name) ) {
                        return vT;
                    }
                }
                for ( auto & arg : func->arguments ) {
                    if ( auto aT = arg->type->findAlias(name) ) {
                        return aT;
                    }
                }
            }
            for ( auto & gvKV : program->thisModule->globals ) {
                auto & gvar = gvKV.second;
                if ( auto vT = gvar->type->findAlias(name) ) {
                    return vT;
                }
            }
            return nullptr;
        }

        // infer alias type
        TypeDeclPtr inferAlias ( const TypeDeclPtr & decl, const FunctionPtr & fptr = nullptr ) const {
            if ( decl->baseType==Type::autoinfer ) {    // until alias is fully resolved, can't infer
                return nullptr;
            }
            if ( decl->baseType==Type::alias ) {
                if ( auto aT = fptr ? findFuncAlias(fptr, decl->alias) : findAlias(decl->alias) ) {
                    auto resT = make_shared<TypeDecl>(*aT);
                    resT->at = decl->at;
                    resT->ref = (resT->ref | decl->ref) & !decl->removeRef;
                    resT->constant = (resT->constant | decl->constant) & !decl->removeConstant;
                    resT->dim.insert(resT->dim.end(), decl->dim.begin(), decl->dim.end());
                    resT->alias = decl->alias;
                    return resT;
                } else {
                    return nullptr;
                }
            }
            auto resT = make_shared<TypeDecl>(*decl);
            if ( decl->baseType==Type::tPointer ) {
                if ( decl->firstType ) {
                    resT->firstType = inferAlias(decl->firstType,fptr);
                    if ( !resT->firstType ) return nullptr;
                }
            } else if ( decl->baseType==Type::tArray ) {
                if ( decl->firstType ) {
                    resT->firstType = inferAlias(decl->firstType,fptr);
                    if ( !resT->firstType ) return nullptr;
                }
            } else if ( decl->baseType==Type::tTable ) {
                if ( decl->firstType ) {
                    resT->firstType = inferAlias(decl->firstType,fptr);
                    if ( !resT->firstType ) return nullptr;
                }
                if ( decl->secondType ) {
                    resT->secondType = inferAlias(decl->secondType,fptr);
                    if ( !resT->secondType ) return nullptr;
                }
            } else if ( decl->baseType==Type::tBlock || decl->baseType==Type::tFunction || decl->baseType==Type::tLambda ) {
                for ( size_t iA=0; iA!=decl->argTypes.size(); ++iA ) {
                    auto & declAT = decl->argTypes[iA];
                    if ( auto infAT = inferAlias(declAT,fptr) ) {
                        resT->argTypes[iA] = infAT;
                    } else {
                        return nullptr;
                    }
                }
                resT->firstType = inferAlias(decl->firstType,fptr);
                if ( !resT->firstType ) return nullptr;
            }
            return resT;
        }

        vector<FunctionPtr> findFuncAddr ( const string & name ) const {
            string moduleName, funcName;
            splitTypeName(name, moduleName, funcName);
            vector<FunctionPtr> result;
            program->library.foreach([&](Module * mod) -> bool {
                auto itFnList = mod->functionsByName.find(funcName);
                if ( itFnList != mod->functionsByName.end() ) {
                    auto & goodFunctions = itFnList->second;
                    result.insert(result.end(), goodFunctions.begin(), goodFunctions.end());
                }
                return true;
            },moduleName);
            return result;
        }

        vector<FunctionPtr> findCandidates ( const string & name, const vector<TypeDeclPtr> & ) const {
            string moduleName, funcName;
            splitTypeName(name, moduleName, funcName);
            vector<FunctionPtr> result;
            program->library.foreach([&](Module * mod) -> bool {
                auto itFnList = mod->functionsByName.find(funcName);
                if ( itFnList != mod->functionsByName.end() ) {
                    auto & goodFunctions = itFnList->second;
                    result.insert(result.end(), goodFunctions.begin(), goodFunctions.end());
                }
                return true;
            },moduleName);
            return result;
        }

        vector<FunctionPtr> findGenericCandidates ( const string & name, const vector<TypeDeclPtr> & ) const {
            string moduleName, funcName;
            splitTypeName(name, moduleName, funcName);
            vector<FunctionPtr> result;
            program->library.foreach([&](Module * mod) -> bool {
                auto itFnList = mod->genericsByName.find(funcName);
                if ( itFnList != mod->genericsByName.end() ) {
                    auto & goodFunctions = itFnList->second;
                    result.insert(result.end(), goodFunctions.begin(), goodFunctions.end());
                }
                return true;
            },moduleName);
            return result;
        }

        bool isMatchingArgument(const FunctionPtr & pFn, TypeDeclPtr argType, TypeDeclPtr passType, bool inferAuto, bool inferBlock) const {
            if (!passType) {
                return false;
            }
            if ( argType->baseType==Type::anyArgument ) {
                return true;
            }
            if (inferAuto) {
                // if it's an alias, we de'alias it, and see if it matches at all
                if (argType->isAlias()) {
                    argType = inferAlias(argType, pFn);
                    if ( !argType ) {
                        return false;
                    }
                }
                // match auto argument
                if (argType->isAuto()) {
                    return TypeDecl::inferAutoType(argType, passType) != nullptr;
                }
            }
            // match inferable block
            if (inferBlock && passType->isAuto() && passType->isGoodBlockType()) {
                return TypeDecl::inferAutoType(passType, argType) != nullptr;
            }
            // compare types which don't need inference
            if (passType && ((argType->isRef() && !passType->isRef()) || !argType->isSameType(*passType, false, false))) {
                return false;
            }
            // ref types can only add constness
            if (argType->isRef() && !argType->constant && passType->constant) {
                return false;
            }
            // pointer types can only add constant
            if (argType->isPointer() && !argType->constant && passType->constant) {
                return false;
            }
            // all good
            return true;
        }

        bool isFunctionCompatible ( const FunctionPtr & pFn, const vector<TypeDeclPtr> & types, bool inferAuto, bool inferBlock ) const {
            if ( pFn->arguments.size() < types.size() ) {
                return false;
            }
            for ( size_t ai = 0; ai != types.size(); ++ai ) {
                if (!isMatchingArgument(pFn, pFn->arguments[ai]->type, types[ai],inferAuto,inferBlock)) {
                    return false;
                }
            }
            for ( auto ti = types.size(); ti != pFn->arguments.size(); ++ti ) {
                if ( !pFn->arguments[ti]->init ) {
                    return false;
                }
            }
            return true;
        }

        string describeMismatchingFunction(const FunctionPtr & pFn, const vector<TypeDeclPtr> & types, bool inferAuto, bool inferBlock) const {
            TextWriter ss;
            size_t tot = min ( types.size(), pFn->arguments.size() );
            for (size_t ai = 0; ai != tot; ++ai) {
                auto & arg = pFn->arguments[ai];
                auto & passType = types[ai];
                if (!isMatchingArgument(pFn, arg->type, passType, inferAuto, inferBlock)) {
                    ss << "\ninvalid argument " << arg->name << ", expecting ("
                        << arg->type->describe() << ") passing (" << passType->describe() << ")";
                }
            }
            return ss.str();
        }

        vector<FunctionPtr> findMatchingFunctions ( const string & name, const vector<TypeDeclPtr> & types, bool inferBlock = false ) const {
            string moduleName, funcName;
            splitTypeName(name, moduleName, funcName);
            vector<FunctionPtr> result;
            program->library.foreach([&](Module * mod) -> bool {
                auto itFnList = mod->functionsByName.find(funcName);
                if ( itFnList != mod->functionsByName.end() ) {
                    auto & goodFunctions = itFnList->second;
                    for ( auto & pFn : goodFunctions ) {
                        if ( isFunctionCompatible(pFn, types, false, inferBlock) ) {
                            result.push_back(pFn);
                        }
                    }
                }
                return true;
            },moduleName);
            return result;
        }

        vector<FunctionPtr> findMatchingGenerics ( const string & name, const vector<TypeDeclPtr> & types ) const {
            string moduleName, funcName;
            splitTypeName(name, moduleName, funcName);
            vector<FunctionPtr> result;
            program->library.foreach([&](Module * mod) -> bool {
                auto itFnList = mod->genericsByName.find(funcName);
                if ( itFnList != mod->genericsByName.end() ) {
                    auto & goodFunctions = itFnList->second;
                    for ( auto & pFn : goodFunctions ) {
                        if ( isFunctionCompatible(pFn, types, true, true) ) {   // infer block here?
                            result.push_back(pFn);
                        }
                    }
                }
                return true;
            },moduleName);
            return result;
        }

        void reportFunctionNotFound( const string & extra, const LineInfo & at, const vector<FunctionPtr> & candidateFunctions,
            const vector<TypeDeclPtr> & types, bool inferAuto, bool inferBlocks ) {
            if (candidateFunctions.size() == 1) {
                auto missFn = candidateFunctions.back();
                auto problems = describeMismatchingFunction(missFn, types, inferAuto, inferBlocks);
                error(extra + "\ncandidate function:\n\t"
                    + missFn->describe() + problems, at, CompilationError::function_not_found);
            }
            else {
                string candidates = program->describeCandidates(candidateFunctions);
                error(extra + "\n" + candidates, at, CompilationError::function_not_found);
            }
        }

        bool hasUserConstructor ( const string & sna ) const {
            vector<TypeDeclPtr> argDummy;
            auto fnlist = findMatchingFunctions(sna, argDummy);
            return fnlist.size() != 0;  // at least one. if more its an error, but it has one for sure
        }

        ExprWith * hasMatchingWith ( const string & fieldName ) const {
            for ( auto it=with.rbegin(); it!=with.rend(); ++it ) {
                auto eW = *it;
                if ( auto eWT = eW->with->type ) {
                    StructurePtr pSt;
                    if ( eWT->isStructure() ) {
                        pSt = eWT->structType->shared_from_this();
                    } else if ( eWT->isPointer() && eWT->firstType && eWT->firstType->isStructure() ) {
                        pSt = eWT->firstType->structType->shared_from_this();
                    }
                    if ( pSt ) {
                        for ( auto fi : pSt->fields ) {
                            if ( fi.name==fieldName ) {
                                return eW;
                            }
                        }
                    }
                }
            }
            return nullptr;
        }

    protected:
    // strcuture
        virtual void preVisit ( Structure * that ) override {
            Visitor::preVisit(that);
            fieldOffset = 0;
        }
        virtual void preVisitStructureField ( Structure * that, Structure::FieldDeclaration & decl, bool last ) override {
            Visitor::preVisitStructureField(that, decl, last);
            if ( decl.type->isAuto() && !decl.init) {
                error("structure field type can't be infered, it needs an initializer",
                      decl.at, CompilationError::cant_infer_missing_initializer );
            }
        }
        virtual void visitStructureField ( Structure * st, Structure::FieldDeclaration & decl, bool ) override {
            if ( decl.parentType ) {
                auto pf = st->parent->findField(decl.name);
                if ( !pf->type->isAuto() && !pf->type->isAlias() ) {
                    decl.type = make_shared<TypeDecl>(*pf->type);
                    decl.parentType = false;
                    reportGenericInfer();
                } else {
                    error("not fully resolved yet", decl.at);
                }
                return;
            }
            if ( decl.type->isAlias() ) {
                if ( auto aT = inferAlias(decl.type) ) {
                    decl.type = aT;
                    reportGenericInfer();
                } else {
                    error("undefined type " + decl.type->describe(), decl.at, CompilationError::invalid_structure_field_type );
                }
            }
            if ( decl.type->isAuto() && decl.init && decl.init->type ) {
                auto varT = TypeDecl::inferAutoType(decl.type, decl.init->type);
                if ( !varT ) {
                    error("structure field initialization type can't be infered, "
                          + decl.type->describe() + " = " + decl.init->type->describe(),
                          decl.at, CompilationError::invalid_structure_field_type );
                } else {
                    TypeDecl::applyAutoContracts(varT, decl.type);
                    decl.type = varT;
                    decl.type->ref = false;
                    reportGenericInfer();
                }
            }
            if ( decl.type->isVoid() ) {
                error("structure field type can't be declared void",decl.at,CompilationError::invalid_structure_field_type);
            } else if ( decl.type->ref ) {
                error("structure field type can't be declared a reference",decl.at,CompilationError::invalid_structure_field_type);
            }
            if ( decl.init ) {
                if ( decl.init->type ) {
                    if ( !decl.type->isSameType(*decl.init->type,false) ) {
                        error("structure field initialization type mismatch, "
                              + decl.type->describe() + " = " + decl.init->type->describe(), decl.at,
                              CompilationError::invalid_initialization_type);
                    } else if ( !decl.type->canCopy() && !decl.moveSemantic ) {
                        error("this field can't be copied, use <- instead",
                              decl.init->at, CompilationError::invalid_initialization_type );
                    } else if ( !decl.init->type->canCopy() && !decl.init->type->canMove() ) {
                        error("this field can't be initialized at all", decl.at,
                              CompilationError::invalid_initialization_type);
                    }
                } else if ( !decl.type->isAuto() ){
                    if ( decl.init->rtti_isCast() ) {
                        auto castExpr = static_pointer_cast<ExprCast>(decl.init);
                        if ( castExpr->castType->isAuto() ) {
                            reportGenericInfer();
                            castExpr->castType = make_shared<TypeDecl>(*decl.type);
                        }
                    }
                }
            }
            if ( !decl.type->isAuto() ) {
                auto fa = decl.type->getAlignOf() - 1;
                fieldOffset = (fieldOffset + fa) & ~fa;
                decl.offset = int(fieldOffset);
                fieldOffset += decl.type->getSizeOf();
            }
            verifyType(decl.type);
        }
        virtual StructurePtr visit ( Structure * var ) override {
            if ( !var->genCtor && var->hasAnyInitializers() ) {
                if ( !hasUserConstructor(var->name) ) {
                    auto ctor = makeConstructor(var);
                    ctor->exports = program->options.getOption("alwaysExportInitializer", false);
                    extraFunctions.push_back(ctor);
                    var->genCtor = true;
                    reportGenericInfer();
                } else {
                    error("structure already has user defined initializer", var->at,
                          CompilationError::structure_already_has_initializer);
                }
            }
            return Visitor::visit(var);
        }
    // globals
        virtual void preVisitGlobalLet ( const VariablePtr & var ) override {
            Visitor::preVisitGlobalLet(var);
            if ( var->type->isAuto() && !var->init) {
                error("global variable type can't be infered, it needs an initializer",
                      var->at, CompilationError::cant_infer_missing_initializer );
            }
        }
        virtual ExpressionPtr visitGlobalLetInit ( const VariablePtr & var, Expression * init ) override {
            if ( !var->init->type ) return Visitor::visitGlobalLetInit(var, init);
            if ( var->type->isAuto() ) {
                auto varT = TypeDecl::inferAutoType(var->type, var->init->type);
                if ( !varT ) {
                    error("global variable initialization type can't be infered, "
                          + var->type->describe() + " = " + var->init->type->describe(),
                          var->at, CompilationError::cant_infer_mismatching_restrictions );
                } else {
                    varT->ref = false;
                    TypeDecl::applyAutoContracts(varT, var->type);
                    var->type = varT;
                    reportGenericInfer();
                }
            } else if ( !var->type->isSameType(*var->init->type,false,false) ) {
                error("global variable initialization type mismatch, "
                      + var->type->describe() + " = " + var->init->type->describe(), var->at,
                    CompilationError::invalid_initialization_type);
            } else if ( !var->type->isConst() && var->init->type->isConst() ) {
                error("global variable initialization type mismatch, const matters "
                      + var->type->describe() + " = " + var->init->type->describe(), var->at,
                      CompilationError::invalid_initialization_type);
            } else if ( !var->init->type->canCopy() && !var->init->type->canMove() ) {
                error("this global variable can't be initialized at all", var->at,
                    CompilationError::invalid_initialization_type);
            }
            return Visitor::visitGlobalLetInit(var, init);
        }
        virtual VariablePtr visitGlobalLet ( const VariablePtr & var ) override {
            if ( var->type->ref )
                error("global variable can't be declared a reference", var->at,
                      CompilationError::invalid_variable_type);
            if ( var->type->isVoid() )
                error("global variable can't be declared void", var->at,
                      CompilationError::invalid_variable_type);
            if ( var->type->isHandle() && !var->type->annotation->isLocal() )
                error("can't have a global variable of handled type " + var->type->annotation->name,
                      var->at, CompilationError::invalid_variable_type);
            verifyType(var->type);
            return Visitor::visitGlobalLet(var);
        }
    // function
        virtual void preVisit ( Function * f ) override {
            Visitor::preVisit(f);
            func = f->shared_from_this();
            func->hasReturn = false;
        }
        virtual void preVisitArgument ( Function * fn, const VariablePtr & var, bool lastArg ) override {
            Visitor::preVisitArgument(fn, var, lastArg);
            if ( var->type->isAlias() ) {
                if ( auto aT = inferAlias(var->type) ) {
                    var->type = aT;
                    reportGenericInfer();
                } else {
                    error("undefined type " + var->type->describe(), var->at, CompilationError::type_not_found );
                }
            }
            if ( var->type->isAuto() ) {
                error("unresolved generics are not supported", var->at, CompilationError::cant_infer_generic );
            }
        }
        virtual ExpressionPtr visitArgumentInit ( Function * f, const VariablePtr & arg, Expression * that ) override {
            if ( !arg->init->type || !arg->type->isSameType(*arg->init->type, true, false) ) {
                error("function argument default value type mismatch", arg->init->at);
            }
            return Visitor::visitArgumentInit(f, arg, that);
        }
        virtual VariablePtr visitArgument ( Function * fn, const VariablePtr & var, bool lastArg ) override {
            if ( var->type->ref && var->type->isRefType() ) {
                error("can't pass boxed type by reference",var->at,CompilationError::invalid_argument_type);
            }
            verifyType(var->type);
            return Visitor::visitArgument(fn, var, lastArg);
        }
        virtual FunctionPtr visit ( Function * that ) override {
            // if function got no 'result', function is a void function
            if ( !func->hasReturn ) {
                if ( func->result->isAuto() ) {
                    func->result = make_shared<TypeDecl>(Type::tVoid);
                    reportGenericInfer();
                } else if ( !func->result->isVoid() ){
                    error("function does not return a value", func->at, CompilationError::expecting_return_value);
                }
            }
            verifyType(func->result);
            if ( !func->result->isReturnType() ) {
                error("not a valid function return type " + func->result->describe(),
                      func->result->at,CompilationError::invalid_return_type);
            }
            if ( func->result->isRefType() ) {
                if ( func->result->canCopy() ) {
                    func->copyOnReturn = true;
                    func->moveOnReturn = false;
                } else if ( func->result->canMove() ) {
                    func->copyOnReturn = false;
                    func->moveOnReturn = true;
                } else {
                    // the error will be reported in the inferReturnType
                    /*
                    error("this type can't be copied or moved. not a valid function return type "
                          + func->result->describe(),func->result->at,CompilationError::invalid_return_type);
                    */
                }
            } else {
                func->copyOnReturn = false;
                func->moveOnReturn = false;
            }
            // if any of this asserts failed, there is logic error in how we pop
            DAS_ASSERT(scopes.size()==0);
            DAS_ASSERT(blocks.size()==0);
            DAS_ASSERT(local.size()==0);
            DAS_ASSERT(with.size()==0);
            func.reset();
            return Visitor::visit(that);
        }
    // any expression
        virtual void preVisitExpression ( Expression * expr ) override {
            Visitor::preVisitExpression(expr);
            expr->type.reset();
        }
    // const
        virtual ExpressionPtr visit ( ExprConst * c ) override {
            c->type = make_shared<TypeDecl>(c->baseType);
            if ( c->baseType == Type::tEnumeration ) {
                auto cE = static_cast<ExprConstEnumeration *>(c);
                c->type->enumType = cE->enumType;
            }
            return Visitor::visit(c);
        }
    // ExprRef2Value
        virtual ExpressionPtr visit ( ExprRef2Value * expr ) override {
            if ( !expr->subexpr->type ) return Visitor::visit(expr);
            // infer
            if ( !expr->subexpr->type->isRef() ) {
                error("can only dereference a reference", expr->at);
            } else if ( !expr->subexpr->type->isSimpleType() && !expr->subexpr->type->isPointer() && !expr->subexpr->type->isEnum() ) {
                error("can only dereference a simple type, not a " + expr->subexpr->type->describe(), expr->at);
            } else {
                expr->type = make_shared<TypeDecl>(*expr->subexpr->type);
                expr->type->ref = false;
            }
            return Visitor::visit(expr);
        }
    // ExprAddr
        virtual ExpressionPtr visit ( ExprAddr * expr ) override {
            expr->func = nullptr;
            auto fns = findFuncAddr(expr->target);
            if ( fns.size()==1 ) {
                expr->func = fns.back().get();
                expr->func->addr = true;
                expr->type = make_shared<TypeDecl>(Type::tFunction);
                expr->type->firstType = make_shared<TypeDecl>(*expr->func->result);
                expr->type->argTypes.reserve ( expr->func->arguments.size() );
                for ( auto & arg : expr->func->arguments ) {
                    auto at = make_shared<TypeDecl>(*arg->type);
                    expr->type->argTypes.push_back(at);
                }
                verifyType(expr->type);
            } else if ( fns.size()==0 ) {
                error("function not found " + expr->target, expr->at,
                      CompilationError::function_not_found);
            } else {
                 string candidates = program->describeCandidates(fns);
                error("function not found " + expr->target + "\n" + candidates, expr->at,
                      CompilationError::function_not_found);
            }
            return Visitor::visit(expr);
        }
    // ExprPtr2Ref
        virtual ExpressionPtr visit ( ExprPtr2Ref * expr ) override {
            if ( !expr->subexpr->type ) return Visitor::visit(expr);
            // infer
            expr->subexpr = Expression::autoDereference(expr->subexpr);
            if ( !expr->subexpr->type->isPointer() ) {
                error("can only dereference a pointer", expr->at, CompilationError::cant_dereference);
            } else if ( !expr->subexpr->type->firstType || expr->subexpr->type->firstType->isVoid() ) {
                error("can only dereference a pointer to something", expr->at, CompilationError::cant_dereference);
            } else {
                expr->type = make_shared<TypeDecl>(*expr->subexpr->type->firstType);
                expr->type->ref = true;
                expr->type->constant |= expr->subexpr->type->constant;
            }
            return Visitor::visit(expr);
        }
    // ExprNullCoalescing
        virtual ExpressionPtr visit ( ExprNullCoalescing * expr ) override {
            if ( !expr->subexpr->type | !expr->defaultValue->type ) return Visitor::visit(expr);
            // infer
            expr->subexpr = Expression::autoDereference(expr->subexpr);
            auto seT = expr->subexpr->type;
            auto dvT = expr->defaultValue->type;
            if ( !seT->isPointer() ) {
                error("can only dereference a pointer", expr->at, CompilationError::cant_dereference);
            } else if ( !seT->firstType || seT->firstType->isVoid() ) {
                error("can only dereference a pointer to something", expr->at, CompilationError::cant_dereference);
            } else if ( !seT->firstType->isSameType(*dvT,false,false) ) {
                error("default value type mismatch in (" + seT->firstType->describe() + ") vs ("
                      + dvT->describe() + ")", expr->at, CompilationError::cant_dereference);
            } else if ( !seT->isConst() && dvT->isConst() ) {
                error("default value type mismatch, constant matters in (" + seT->describe() + ") vs ("
                      + dvT->describe() + ")", expr->at, CompilationError::cant_dereference);
            } else {
                expr->type = make_shared<TypeDecl>(*dvT);
                expr->type->constant |= expr->subexpr->type->constant;
            }
            return Visitor::visit(expr);
        }
    // ExprStaticAssert
        virtual ExpressionPtr visit ( ExprStaticAssert * expr ) override {
            if ( expr->argumentsFailedToInfer ) return Visitor::visit(expr);
            if ( expr->arguments.size()<1 || expr->arguments.size()>2  ) {
                error("static_assert(expr) or static_assert(expr,string)", expr->at, CompilationError::invalid_argument_count);
                return Visitor::visit(expr);
            }
            // infer
            expr->autoDereference();
            if ( !expr->arguments[0]->type->isSimpleType(Type::tBool) )
                error("static assert condition must be boolean", expr->at, CompilationError::invalid_argument_type);
            if ( expr->arguments.size()==2 && !expr->arguments[1]->rtti_isStringConstant() ) {
                error("static assert comment must be string constant", expr->at, CompilationError::invalid_argument_type);
                return nullptr;
            }
            expr->type = make_shared<TypeDecl>(Type::tVoid);
            return Visitor::visit(expr);
        }
    // ExprAssert
        virtual ExpressionPtr visit ( ExprAssert * expr ) override {
            if ( expr->argumentsFailedToInfer ) return Visitor::visit(expr);
            if ( expr->arguments.size()<1 || expr->arguments.size()>2  ) {
                error("assert(expr) or assert(expr,string)", expr->at, CompilationError::invalid_argument_count);
                return Visitor::visit(expr);
            }
            // infer
            expr->autoDereference();
            if ( !expr->arguments[0]->type->isSimpleType(Type::tBool) )
                error("assert condition must be boolean", expr->at, CompilationError::invalid_argument_type);
            if ( expr->arguments.size()==2 && !expr->arguments[1]->rtti_isStringConstant() ) {
                error("assert comment must be string constant", expr->at, CompilationError::invalid_argument_type);
            }
            expr->type = make_shared<TypeDecl>(Type::tVoid);
            return Visitor::visit(expr);
        }
    // ExprDebug
        virtual ExpressionPtr visit ( ExprDebug * expr ) override {
            if ( expr->argumentsFailedToInfer ) return Visitor::visit(expr);
            if ( expr->arguments.size()<1 || expr->arguments.size()>2 ) {
                error("debug(expr) or debug(expr,string)", expr->at, CompilationError::invalid_argument_count);
                return Visitor::visit(expr);
            }
            // infer
            if ( expr->arguments.size()==2 && !expr->arguments[1]->rtti_isStringConstant() )
                error("debug comment must be string constant", expr->at, CompilationError::invalid_argument_type);
            expr->type = make_shared<TypeDecl>(*expr->arguments[0]->type);
            return Visitor::visit(expr);
        }
    // ExprMakeLambda
        virtual ExpressionPtr visit ( ExprMakeLambda * expr ) override {
            if ( expr->arguments.size()!=1 ) {
                error("expecting lambda(closure)", expr->at, CompilationError::invalid_argument_count);
            } else if ( !expr->arguments[0]->rtti_isMakeBlock() ) {
                error("expecting lambda(closure)", expr->at, CompilationError::invalid_argument_type);
            } else {
                auto mkBlock = static_pointer_cast<ExprMakeBlock>(expr->arguments[0]);
                auto block = static_pointer_cast<ExprBlock>(mkBlock->block);
                if ( auto bT = block->type ) {
                    if ( bT->isAlias() || bT->isAuto() ) {
                        error("can't infer lambda block type", expr->at, CompilationError::invalid_block);
                    } else {
                        CaptureLambda cl;
                        // we can only capture in-scope variables
                        // i.e stuff BEFORE the scope
                        for ( auto & lv : local )
                            cl.scope.insert(lv);
                        for ( auto & bls : blocks ) {
                            for ( auto & blv : bls->arguments ) {
                                cl.scope.insert(blv);
                            }
                        }
                        block->visit(cl);
                        if ( !cl.fail ) {
                            for ( auto ba : block->arguments ) {
                                cl.capt.erase(ba);
                            }
                            string lname = generateNewLambdaName(block->at);
                            auto ls = generateLambdaStruct(lname, block.get(), cl.capt);
                            if ( program->addStructure(ls) ) {
                                auto pFn = generateLambdaFunction(lname, block.get(), ls);
                                if ( program->addFunction(pFn) ) {
                                    auto ms = generateLambdaMakeStruct ( ls, pFn, cl.capt );
                                    return ms;
                                } else {
                                    error("lambda function name mismatch", expr->at, CompilationError::invalid_block);
                                }
                            } else {
                                error("lambda struct name mismatch", expr->at, CompilationError::invalid_block);
                            }
                        }
                    }
                }
            }
            return Visitor::visit(expr);
        }
    // ExprMakeBlock
        virtual ExpressionPtr visit ( ExprMakeBlock * expr ) override {
            auto block = static_pointer_cast<ExprBlock>(expr->block);
            expr->type = block->makeBlockType();
            return Visitor::visit(expr);
        }
    // ExprInvoke
        virtual ExpressionPtr visit ( ExprInvoke * expr ) override {
            if ( expr->argumentsFailedToInfer ) {
                auto blockT = expr->arguments[0]->type;
                if ( !blockT ) {
                    // no go, no block
                } else if ( !blockT->isGoodBlockType() && !blockT->isGoodFunctionType() && !blockT->isGoodLambdaType() ) {
                    // no go, not a good block
                } else if ( expr->arguments.size()-1 != blockT->argTypes.size() ) {
                    // no go, not a good argument
                } else {
                    for ( size_t i=0; i != blockT->argTypes.size(); ++i ) {
                        auto & arg = expr->arguments[i+1];
                        auto & passType = arg->type;
                        auto & argType = blockT->argTypes[i];
                        if ( arg->rtti_isCast() && !passType ) {
                            auto argCast = static_pointer_cast<ExprCast>(arg);
                            if ( argCast->castType->isAuto() ) {
                                reportGenericInfer();
                                argCast->castType = make_shared<TypeDecl>(*argType);
                            }
                        }
                    }
                }
                return Visitor::visit(expr);
            }
            if ( expr->arguments.size()<1 ) {
                error("expecting invoke(block_or_function_or_lambda) or invoke(block_or_function_or_lambda,...)", expr->at,
                      CompilationError::invalid_argument_count);
                return Visitor::visit(expr);
            }
            // infer
            expr->arguments[0] = Expression::autoDereference(expr->arguments[0]);
            auto blockT = expr->arguments[0]->type;
            if ( !blockT->isGoodBlockType() && !blockT->isGoodFunctionType() && !blockT->isGoodLambdaType() ) {
                error("expecting block, or function, or lambda, not a " + blockT->describe(), expr->at,
                      CompilationError::invalid_argument_type);
            }
            if ( expr->arguments.size()-1 != blockT->argTypes.size() ) {
                error("invalid number of arguments, expecting " + blockT->describe(),
                      expr->at, CompilationError::invalid_argument_count);
                return Visitor::visit(expr);
            }
            if ( blockT->isGoodLambdaType() ) {
                expr->arguments[0] = Expression::autoDereference(expr->arguments[0]);
            }
            for ( size_t i=0; i != blockT->argTypes.size(); ++i ) {
                auto & passType = expr->arguments[i+1]->type;
                auto & argType = blockT->argTypes[i];
                // same type only
                if ( passType && ((argType->isRef() && !passType->isRef()) || !argType->isSameType(*passType, false, false)) ) {
                    error("incomaptible argument " + to_string(i+1) + " (" + passType->describe() + ") vs "
                          + argType->describe() + ")", expr->at, CompilationError::invalid_argument_type);
                }
                // ref types can only add constness
                if ( argType->isRef() && !argType->constant && passType->constant ) {
                    error("incomaptible argument " + to_string(i+1) + " (" + passType->describe() + ") vs "
                          + argType->describe() + "), passing const to non-const argument",
                            expr->at, CompilationError::invalid_argument_type);
                }
                // pointer types can only add constant
                if ( argType->isPointer() && !argType->constant && passType->constant ) {
                    error("incomaptible argument " + to_string(i+1) + " (" + passType->describe() + ") vs "
                          + argType->describe() + "), passing const pointer to non-const pointer argument",
                          expr->at, CompilationError::invalid_argument_type);
                }
                if ( !argType->isRef() )
                    expr->arguments[i+1] = Expression::autoDereference(expr->arguments[i+1]);
            }
            if ( blockT->firstType ) {
                expr->type = make_shared<TypeDecl>(*blockT->firstType);
            } else {
                expr->type = make_shared<TypeDecl>();
            }
            return Visitor::visit(expr);
        }
    // ExprErase
        virtual ExpressionPtr visit ( ExprErase * expr ) override {
            if ( expr->argumentsFailedToInfer ) return Visitor::visit(expr);
            if ( expr->arguments.size()!=2 ) {
                error("eraseKey(table,key)", expr->at, CompilationError::invalid_argument_count);
                return Visitor::visit(expr);
            }
            // infer
            expr->arguments[1] = Expression::autoDereference(expr->arguments[1]);
            auto containerType = expr->arguments[0]->type;
            auto valueType = expr->arguments[1]->type;
            if ( containerType->isGoodTableType() ) {
                if ( !containerType->firstType->isSameType(*valueType,false) )
                    error("key must be of the same type as table<key,...>", expr->at, CompilationError::invalid_argument_type);
                expr->type = make_shared<TypeDecl>(Type::tBool);
            } else {
                error("first argument must be fully qualified table", expr->at, CompilationError::invalid_argument_type);
            }
            valueType->constant = true;
            return Visitor::visit(expr);
        }
    // ExprFind
        virtual ExpressionPtr visit ( ExprFind * expr ) override {
            if ( expr->argumentsFailedToInfer ) return Visitor::visit(expr);
            if ( expr->arguments.size()!=2 ) {
                error("findKey(table,key)", expr->at, CompilationError::invalid_argument_count);
                return Visitor::visit(expr);
            }
            // infer
            expr->arguments[1] = Expression::autoDereference(expr->arguments[1]);
            auto containerType = expr->arguments[0]->type;
            auto valueType = expr->arguments[1]->type;
            if ( containerType->isGoodTableType() ) {
                if ( !containerType->firstType->isSameType(*valueType,false) )
                    error("key must be of the same type as table<key,...>", expr->at, CompilationError::invalid_argument_type);
                expr->type = make_shared<TypeDecl>(Type::tPointer);
                expr->type->firstType = make_shared<TypeDecl>(*containerType->secondType);
            } else {
                error("first argument must be fully qualified table", expr->at, CompilationError::invalid_argument_type);
            }
            containerType->constant = true;
            valueType->constant = true;
            return Visitor::visit(expr);
        }
    // ExprSizeOf
        virtual ExpressionPtr visit ( ExprSizeOf * expr ) override {
            // check subexpression
            if ( expr->subexpr && expr->subexpr->type ) {
                expr->typeexpr = make_shared<TypeDecl>(*expr->subexpr->type);
            }
            // verify
            if ( !expr->typeexpr ) {
                error("sizeof(...) can't be infered", expr->at, CompilationError::type_not_found);
                return Visitor::visit(expr);
            }
            if ( expr->typeexpr->isAlias() ) {
                if ( auto eT = inferAlias(expr->typeexpr) ) {
                    expr->typeexpr = eT;
                    reportGenericInfer();
                } else {
                    error("udefined type " + expr->typeexpr->describe(),
                          expr->at, CompilationError::type_not_found);
                }
            }
            if ( expr->typeexpr->ref ) {
                error("sizeof(ref) is prohibited, " + expr->typeexpr->describe(),
                      expr->at,CompilationError::sizeof_reference);
            } else if ( expr->typeexpr->isAuto() ) {
                error("sizeof(auto) is undefined, " + expr->typeexpr->describe(),
                      expr->at, CompilationError::sizeof_auto);
            }
            verifyType(expr->typeexpr);
            // infer
            expr->type = make_shared<TypeDecl>(Type::tInt);
            return Visitor::visit(expr);
        }
    // ExprTypeName
        virtual ExpressionPtr visit ( ExprTypeName * expr ) override {
            // check subexpression
            if ( expr->subexpr && expr->subexpr->type ) {
                expr->typeexpr = make_shared<TypeDecl>(*expr->subexpr->type);
            }
            // verify
            if ( !expr->typeexpr ) {
                error("typename(...) can't be infered", expr->at, CompilationError::type_not_found);
                return Visitor::visit(expr);
            }
            if ( expr->typeexpr->isAlias() ) {
                if ( auto eT = inferAlias(expr->typeexpr) ) {
                    expr->typeexpr = eT;
                    reportGenericInfer();
                } else {
                    error("udefined type " + expr->typeexpr->describe(),
                          expr->at, CompilationError::type_not_found);
                }
            }
            if ( expr->typeexpr->isAuto() ) {
                error("typename(auto) is undefined, " + expr->typeexpr->describe(),
                      expr->at, CompilationError::typename_auto);
            }
            verifyType(expr->typeexpr);
            // infer
            expr->type = make_shared<TypeDecl>(Type::tString);
            return Visitor::visit(expr);
        }
    // ExprDelete
        virtual ExpressionPtr visit ( ExprDelete * expr ) override {
            if ( !expr->subexpr->type ) return Visitor::visit(expr);
            if ( !expr->subexpr->type->canDelete() ) {
                error("can't delete " + expr->subexpr->type->describe(),
                      expr->at, CompilationError::bad_delete);
            } else if ( !expr->subexpr->type->isRef() ) {
                error("can only delete reference " + expr->subexpr->type->describe(),
                      expr->at, CompilationError::bad_delete);
            } else if ( expr->subexpr->type->isConst() ) {
                error("can't delete constant expression " + expr->subexpr->type->describe(),
                      expr->at, CompilationError::bad_delete);
            } else if ( expr->subexpr->type->isPointer() ) {
                if ( func && !func->unsafe ) {
                    error("delete of pointer requires [unsafe]", expr->at,
                          CompilationError::unsafe);
                }
            }
            expr->type = make_shared<TypeDecl>();
            return Visitor::visit(expr);
        }
    // ExprCast
        TypeDeclPtr castStruct ( const LineInfo & at, const TypeDeclPtr & subexprType, const TypeDeclPtr & castType, bool upcast ) const {
            auto seT = subexprType;
            auto cT = castType;
            if ( seT->isStructure() ) {
                if ( cT->isStructure() ) {
                    bool compatibleCast;
                    if ( upcast ) {
                        compatibleCast = seT->structType->isCompatibleCast(*cT->structType);
                    } else {
                        compatibleCast = cT->structType->isCompatibleCast(*seT->structType);
                    }
                    if ( compatibleCast ) {
                        auto exprType = make_shared<TypeDecl>(*cT);
                        exprType->ref = seT->ref;
                        exprType->constant = seT->constant;
                        return exprType;
                    } else {
                        error("incompatible cast, can't cast " + seT->structType->name
                              + " to " + cT->structType->name, at,
                              CompilationError::invalid_cast);
                    }
                } else {
                    error("invalid cast, expecting structure", at,
                          CompilationError::invalid_cast);
                }
            } else if ( seT->isPointer() && seT->firstType->isStructure() ) {
                if ( cT->isPointer() && cT->firstType->isStructure() ) {
                    bool compatibleCast;
                    if ( upcast ) {
                        compatibleCast = seT->firstType->structType->isCompatibleCast(*cT->firstType->structType);
                    } else {
                        compatibleCast = cT->firstType->structType->isCompatibleCast(*seT->firstType->structType);
                    }
                    if ( compatibleCast ) {
                        auto exprType = make_shared<TypeDecl>(*cT);
                        exprType->ref = seT->ref;
                        exprType->constant = seT->constant;
                        return exprType;
                    } else {
                        error("incompatible cast, can't cast " + seT->firstType->structType->name
                              + "? to " + cT->firstType->structType->name + "?", at,
                              CompilationError::invalid_cast);
                    }
                } else {
                    error("invalid cast, expecting structure pointer", at,
                          CompilationError::invalid_cast);
                }
            }
            return nullptr;
        }
        TypeDeclPtr castFunc ( const LineInfo & at, const TypeDeclPtr & subexprType, const TypeDeclPtr & castType, bool upcast ) const {
            auto seTF = subexprType;
            auto cTF = castType;
            if ( seTF->argTypes.size()!=cTF->argTypes.size() ) {
                error("invalid cast, number of arguments does not match", at,
                      CompilationError::invalid_cast);
                return nullptr;
            }
            // result
            auto funT = make_shared<TypeDecl>(*seTF);
            auto cresT = cTF->firstType;
            auto resT = funT->firstType;
            if ( !cresT->isSameType(*resT,true,false) ) {
                if ( resT->isStructure() || (resT->isPointer() && resT->firstType->isStructure()) ) {
                    auto tryRes = castStruct(at, resT, cresT, upcast);
                    if ( tryRes ) {
                        funT->firstType = tryRes;
                    }
                }
            }
            funT->firstType->constant = cresT->constant;
            // arguments
            for ( size_t i=0; i!=seTF->argTypes.size(); ++i ) {
                auto seT = seTF->argTypes[i];
                auto cT = cTF->argTypes[i];
                if ( !cT->isSameType(*seT,true,false) ) {
                    if ( seT->isStructure() || (seT->isPointer() && seT->firstType->isStructure()) ) {
                        auto tryArg = castStruct(at, seT, cT, upcast);
                        if ( tryArg ) {
                            funT->argTypes[i] = tryArg;
                        }
                    }
                }
                funT->argTypes[i]->constant = cT->constant;
            }
            if ( castType->isSameType(*funT,true,true) ) {
                return funT;
            } else {
                error("incompatible cast, can't cast " + funT->describe() + " to " + castType->describe(), at,
                      CompilationError::invalid_cast);
                return nullptr;
            }
        }

        virtual ExpressionPtr visit ( ExprCast * expr ) override {
            if ( !expr->subexpr->type ) return Visitor::visit(expr);
            if ( expr->castType->isAlias() ) {
                auto aT = inferAlias(expr->castType);
                if ( aT ) {
                    expr->castType = aT;
                    reportGenericInfer();
                } else {
                    error("udefined type " + expr->castType->describe(), expr->at,
                          CompilationError::type_not_found);
                    return Visitor::visit(expr);
                }
            }
            if ( expr->castType->isAuto() ) {
                error("casting to udefined type " + expr->castType->describe(), expr->at,
                      CompilationError::type_not_found);
                return Visitor::visit(expr);
            }
            if ( expr->subexpr->type->isSameType(*expr->castType,true,true) ) {
                reportGenericInfer();
                return expr->subexpr;
            }
            if ( expr->castType->isGoodBlockType() ||  expr->castType->isGoodFunctionType() || expr->castType->isGoodLambdaType() ) {
                expr->type = castFunc(expr->at, expr->subexpr->type, expr->castType, expr->upcast);
            } else {
                expr->type = castStruct(expr->at, expr->subexpr->type, expr->castType, expr->upcast);
            }
            if ( expr->upcast && func && !func->unsafe ) {
                error("upcast requires [unsafe]", expr->at, CompilationError::unsafe);
            }
            if ( expr->type ) {
                verifyType(expr->type);
            }
            return Visitor::visit(expr);
        }
    // ExprAscend
        virtual ExpressionPtr visit ( ExprAscend * expr ) override {
            if ( !expr->subexpr->type ) return Visitor::visit(expr);
            if ( !expr->subexpr->type->isRef() ) {
                error("can't ascend (to heap) non-reference value", expr->at,
                      CompilationError::invalid_new_type);
            }
            if ( expr->ascType ) {
                expr->type = make_shared<TypeDecl>(*expr->ascType);
            } else {
                expr->type = make_shared<TypeDecl>(Type::tPointer);
                expr->type->firstType = make_shared<TypeDecl>(*expr->subexpr->type);
                expr->type->firstType->ref = false;
            }
            return Visitor::visit(expr);
        }
    // ExprNew
        virtual void preVisit ( ExprNew * call ) override {
            Visitor::preVisit(call);
            call->argumentsFailedToInfer = false;
        }
        virtual ExpressionPtr visitNewArg ( ExprNew * call, Expression * arg , bool last ) override {
            if ( !arg->type ) call->argumentsFailedToInfer = true;
            return Visitor::visitNewArg(call, arg, last);
        }
        virtual ExpressionPtr visit ( ExprNew * expr ) override {
            // infer
            if ( expr->typeexpr->isAlias() ) {
                if ( auto aT = findAlias(expr->typeexpr->alias) ) {
                    expr->typeexpr = make_shared<TypeDecl>(*aT);
                    expr->typeexpr->ref = false;      // drop a ref
                    expr->typeexpr->constant = false; // drop a const
                    reportGenericInfer();
                } else {
                    error("undefined type " + expr->typeexpr->describe(),
                          expr->at, CompilationError::type_not_found);
                    return Visitor::visit(expr);
                }
            }
            expr->name.clear();
            expr->func = nullptr;
            if ( expr->typeexpr->ref ) {
                error("can't new a reference", expr->at, CompilationError::invalid_new_type);
            } if ( expr->typeexpr->baseType==Type::tStructure ) {
                expr->type = make_shared<TypeDecl>(Type::tPointer);
                expr->type->firstType = make_shared<TypeDecl>(*expr->typeexpr);
                expr->type->firstType->dim.clear();
                expr->type->dim = expr->typeexpr->dim;
                expr->name = expr->typeexpr->structType->getMangledName();
            } else if ( expr->typeexpr->baseType==Type::tHandle ) {
                if ( expr->typeexpr->annotation->canNew() ) {
                    expr->type = make_shared<TypeDecl>(Type::tPointer);
                    expr->type->firstType = make_shared<TypeDecl>(*expr->typeexpr);
                    expr->type->firstType->dim.clear();
                    expr->type->dim = expr->typeexpr->dim;
                } else {
                    error("can new this type " + expr->typeexpr->describe(),
                          expr->at, CompilationError::invalid_new_type);
                }
            } else {
                error("can only new structures or handled types " + expr->typeexpr->describe(),
                      expr->at, CompilationError::invalid_new_type);
            }
            if ( expr->initializer && expr->name.empty() ) {
                error("only native structures can have initializers " + expr->typeexpr->describe(),
                      expr->at, CompilationError::invalid_new_type);
            }
            if ( expr->type && expr->initializer && !expr->name.empty() ) {
                auto resultType = expr->type;
                expr->func = inferFunctionCall(expr).get();
                swap ( resultType, expr->type );
                if ( expr->func ) {
                    if ( !expr->type->firstType->isSameType(*resultType,true,true) ) {
                        error("initializer returns (" +resultType->describe() + ") vs "
                            +  expr->type->firstType->describe() + ")",
                              expr->at, CompilationError::invalid_new_type);
                    }
                }
                else {
                    error(expr->type->firstType->describe() + " does not have default initializer",
                        expr->at, CompilationError::invalid_new_type);
                }
            }
            verifyType(expr->typeexpr);
            return Visitor::visit(expr);
        }
    // ExprAt
        virtual ExpressionPtr visit ( ExprAt * expr ) override {
            if ( !expr->subexpr->type || !expr->index->type) return Visitor::visit(expr);
            // infer
            expr->index = Expression::autoDereference(expr->index);
            auto seT = expr->subexpr->type;
            auto ixT = expr->index->type;
            if ( seT->isGoodTableType() ) {
                if ( !seT->firstType->isSameType(*ixT) ) {
                    error("table index type mismatch, (" + expr->index->type->describe() + ") vs (" +
                          ixT->describe() + ")", expr->index->at, CompilationError::invalid_index_type);
                    return Visitor::visit(expr);
                }
                expr->type = make_shared<TypeDecl>(*seT->secondType);
                expr->type->ref = true;
                expr->type->constant |= seT->constant;
            } else if ( seT->isHandle() ) {
                if ( !seT->annotation->isIndexable(ixT) ) {
                    error("handle does not support this index type", expr->index->at, CompilationError::invalid_index_type);
                    return Visitor::visit(expr);
                }
                expr->type = seT->annotation->makeIndexType(ixT);
                expr->type->constant |= seT->constant;
            } else {
                if ( !ixT->isIndex() ) {
                    error("index must int or uint", expr->index->at, CompilationError::invalid_index_type);
                    return Visitor::visit(expr);
                }
                if ( seT->isVectorType() ) {
                    expr->type = make_shared<TypeDecl>(seT->getVectorBaseType());
                    expr->type->ref = seT->ref;
                    expr->type->constant = seT->constant;
                } else if ( seT->isGoodArrayType() ) {
                    expr->type = make_shared<TypeDecl>(*seT->firstType);
                    expr->type->ref = true;
                    expr->type->constant |= seT->constant;
                } else if ( !seT->isRef() ) {
                    error("can only index a reference", expr->subexpr->at, CompilationError::cant_index);
                } else if ( !seT->dim.size() ) {
                    error("can only index an array", expr->subexpr->at, CompilationError::cant_index);
                } else {
                    expr->type = make_shared<TypeDecl>(*seT);
                    expr->type->ref = true;
                    expr->type->dim.pop_back();
                }
            }
            return Visitor::visit(expr);
        }
    // ExprBlock
        void setBlockCopyMoveFlags ( ExprBlock * block ) {
            if ( block->returnType->isRefType() ) {
                if ( block->returnType->canCopy() ) {
                    block->copyOnReturn = true;
                    block->moveOnReturn = false;
                } else if ( func->result->canMove() ) {
                    block->copyOnReturn = false;
                    block->moveOnReturn = true;
                } else {
                    error("this type can't be returned at all " + block->returnType->describe(),
                          block->at, CompilationError::invalid_return_type);
                }
            } else {
                block->copyOnReturn = false;
                block->moveOnReturn = false;
            }
        }
        virtual void preVisit ( ExprBlock * block ) override {
            Visitor::preVisit(block);
            block->hasReturn = false;
            if ( block->isClosure ) {
                blocks.push_back(block);
                block->type = make_shared<TypeDecl>(*block->returnType);
            }
            scopes.push_back(block);
            pushVarStack();
        }
        virtual void preVisitBlockFinal ( ExprBlock * block ) override {
            Visitor::preVisitBlockFinal(block);
            if ( block->getFinallyEvalFlags() ) {
                error("finally section can't have break or return", block->at,
                      CompilationError::return_or_break_in_finally );
            }
        }
        virtual void preVisitBlockArgument ( ExprBlock * block, const VariablePtr & var, bool lastArg ) override {
            Visitor::preVisitBlockArgument(block, var, lastArg);
            for ( auto & lv : local ) {
                if ( lv->name==var->name ) {
                    error("block argument " + var->name +" is shadowed by local variable "
                          + lv->name + " : " + lv->type->describe() + " at line " + to_string(lv->at.line),
                              var->at, CompilationError::variable_not_found);
                    break;
                }
            }
            if ( auto eW = hasMatchingWith(var->name) ) {
                error("block argument " + var->name + " is shadowed by with expression at line " + to_string(eW->at.line),
                      var->at, CompilationError::variable_not_found);
            }
            if ( var->type->isAuto() && !var->init) {
                error("block argument type can't be infered, it needs an initializer",
                      var->at, CompilationError::cant_infer_missing_initializer );
            }
            if ( var->type->ref && var->type->isRefType() ) {
                error("can't pass boxed type by reference",var->at,CompilationError::invalid_argument_type);
            }
            verifyType(var->type);
        }
        virtual ExpressionPtr visitBlockArgumentInit (ExprBlock * block, const VariablePtr & arg, Expression * that ) override {
            if ( arg->type->isAuto() ) {
                auto argT = TypeDecl::inferAutoType(arg->type, arg->init->type);
                if ( !argT ) {
                    error("block argument initialization type can't be infered, "
                          + arg->type->describe() + " = " + arg->init->type->describe(),
                          arg->at, CompilationError::cant_infer_mismatching_restrictions );
                } else {
                    TypeDecl::applyAutoContracts(argT, arg->type);
                    arg->type = argT;
                    reportGenericInfer();
                }
            }
            if ( !arg->init->type || !arg->type->isSameType(*arg->init->type, true, false) ) {
                error("block argument default value type mismatch", arg->init->at,
                  CompilationError::invalid_argument_type);
            }
            return Visitor::visitBlockArgumentInit(block, arg, that);
        }
        virtual ExpressionPtr visit ( ExprBlock * block ) override {
            popVarStack();
            scopes.pop_back();
            if ( block->isClosure ) {
                blocks.pop_back();
            }
            if ( block->isClosure ) {
                if ( block->list.size() ) {
                    uint32_t flags = block->getEvalFlags();
                    if ( flags & EvalFlags::stopForBreak ) {
                        error("captured block can't 'break' outside of the block",
                              block->at, CompilationError::invalid_block);
                    }
                }
                if ( !block->hasReturn && block->type->isAuto() ) {
                    block->returnType = make_shared<TypeDecl>(Type::tVoid);
                    block->type = make_shared<TypeDecl>(Type::tVoid);
                    setBlockCopyMoveFlags(block);
                    reportGenericInfer();
                }
                if ( block->returnType ) {
                    verifyType(block->returnType);
                }
            }
            return Visitor::visit(block);
        }
    // Swizzle
            virtual ExpressionPtr visit ( ExprSwizzle * expr ) override {
                if ( !expr->value->type ) return Visitor::visit(expr);
                auto valT = expr->value->type;
                int dim = valT->getVectorDim();
                if ( !TypeDecl::buildSwizzleMask(expr->mask, dim, expr->fields) ) {
                    error("invalid swizzle mask", expr->at, CompilationError::invalid_swizzle_mask);
                } else {
                    auto bt = valT->getVectorBaseType();
                    auto rt = TypeDecl::getVectorType(bt, int(expr->fields.size()));
                    expr->type = make_shared<TypeDecl>(rt);
                    expr->type->constant = valT->constant;
                    expr->type->ref = valT->ref;
                    if ( expr->type->ref ) {
                        expr->type->ref &= TypeDecl::isSequencialMask(expr->fields);
                    }
                    if ( !expr->type->ref ) {
                        expr->value = Expression::autoDereference(expr->value);
                    }
                }
                return Visitor::visit(expr);
            }
    // ExprField
        virtual ExpressionPtr visit ( ExprField * expr ) override {
            if ( !expr->value->type ) return Visitor::visit(expr);
            // infer
            auto valT = expr->value->type;
            if ( valT->isVectorType() ) {
                reportGenericInfer();
                return make_shared<ExprSwizzle>(expr->at,expr->value,expr->name);
            } else if ( valT->isArray() ) {
                error("can't get a field of an array", expr->at, CompilationError::cant_get_field);
                return Visitor::visit(expr);
            } else if ( valT->isHandle() ) {
                expr->annotation = valT->annotation;
                expr->type = expr->annotation->makeFieldType(expr->name);
            } else if ( valT->isStructure() ) {
                expr->field = valT->structType->findField(expr->name);
            } else if ( valT->isPointer() ) {
                expr->value = Expression::autoDereference(expr->value);
                if ( valT->firstType->baseType==Type::tStructure ) {
                    expr->field = valT->firstType->structType->findField(expr->name);
                } else if ( valT->firstType->isHandle() ) {
                    expr->annotation = valT->firstType->annotation;
                    expr->type = expr->annotation->makeFieldType(expr->name);
                }
            }
            // handle
            if ( expr->field ) {
                expr->type = make_shared<TypeDecl>(*expr->field->type);
                expr->type->ref = true;
                expr->type->constant |= valT->constant;
            } else if ( !expr->type ) {
                error("field " + expr->name + " not found", expr->at, CompilationError::cant_get_field);
            } else {
                expr->type->constant |= valT->constant;
            }
            return Visitor::visit(expr);
        }
    // ExprSafeField
        virtual ExpressionPtr visit ( ExprSafeField * expr ) override {
            if ( !expr->value->type ) return Visitor::visit(expr);
            // infer
            auto valT = expr->value->type;
            if ( !valT->isPointer() || !valT->firstType ) {
                error("can only safe dereference a pointer to a structure or handle " + valT->describe(),
                      expr->at, CompilationError::cant_get_field);
                return Visitor::visit(expr);
            }
            expr->value = Expression::autoDereference(expr->value);
            if ( valT->firstType->structType ) {
                expr->field = valT->firstType->structType->findField(expr->name);
                if ( !expr->field ) {
                    error("can't safe get field " + expr->name, expr->at, CompilationError::cant_get_field);
                    return Visitor::visit(expr);
                }
                expr->type = make_shared<TypeDecl>(*expr->field->type);
            } else if ( valT->firstType->isHandle() ) {
                expr->annotation = valT->firstType->annotation;
                expr->type = expr->annotation->makeSafeFieldType(expr->name);
                if ( !expr->type ) {
                    error("can't safe get field " + expr->name, expr->at, CompilationError::cant_get_field);
                    return Visitor::visit(expr);
                }
            } else {
                error("can only safe dereference a pointer to a structure or a handle " + valT->describe(),
                      expr->at, CompilationError::cant_get_field);
                return Visitor::visit(expr);
            }
            expr->skipQQ = expr->type->isPointer();
            if ( !expr->skipQQ ) {
                auto fieldType = expr->type;
                expr->type = make_shared<TypeDecl>(Type::tPointer);
                expr->type->firstType = fieldType;
            }
            expr->type->constant |= valT->constant;
            return Visitor::visit(expr);
        }
    // ExprVar
        virtual void preVisit ( ExprVar * expr ) override {
            Visitor::preVisit(expr);
            expr->variable = nullptr;
            expr->local = false;
            expr->block = false;
            expr->pBlock.reset();
            expr->argument = false;
            expr->argumentIndex = -1;
        }
        virtual ExpressionPtr visit ( ExprVar * expr ) override {
            // local (that on the stack)
            for ( auto it = local.rbegin(); it!=local.rend(); ++it ) {
                auto var = *it;
                if ( var->name==expr->name ) {
                    expr->variable = var;
                    expr->local = true;
                    expr->type = make_shared<TypeDecl>(*var->type);
                    expr->type->ref = true;
                    return Visitor::visit(expr);
                }
            }
            // with
            if ( auto eW = hasMatchingWith(expr->name) ) {
                reportGenericInfer();
                return make_shared<ExprField>(expr->at, eW->with->clone(), expr->name);
            }
            // block arguments
            for ( auto it = blocks.rbegin(); it!=blocks.rend(); ++it ) {
                auto block = *it;
                int argumentIndex = 0;
                for ( auto & arg : block->arguments ) {
                    if ( arg->name==expr->name ) {
                        expr->variable = arg;
                        expr->argumentIndex = argumentIndex;
                        expr->block = true;
                        expr->type = make_shared<TypeDecl>(*arg->type);
                        if (!expr->type->isRefType())
                            expr->type->ref = true;
                        expr->pBlock = static_pointer_cast<ExprBlock>(block->shared_from_this());
                        return Visitor::visit(expr);
                    }
                    argumentIndex ++;
                }
            }
            // function argument
            if ( func ) {
                int argumentIndex = 0;
                for ( auto & arg : func->arguments ) {
                    if ( arg->name==expr->name ) {
                        expr->variable = arg;
                        expr->argumentIndex = argumentIndex;
                        expr->argument = true;
                        expr->type = make_shared<TypeDecl>(*arg->type);
                        if (!expr->type->isRefType())
                            expr->type->ref = true;
                        return Visitor::visit(expr);
                    }
                    argumentIndex ++;
                }
            }
            // global
            auto var = program->findVariable(expr->name);
            if ( !var ) {
                error("can't locate variable " + expr->name, expr->at, CompilationError::variable_not_found);
            } else {
                expr->variable = var;
                expr->type = make_shared<TypeDecl>(*var->type);
                expr->type->ref = true;
            }
            return Visitor::visit(expr);
        }
    // ExprOp1
        virtual ExpressionPtr visit ( ExprOp1 * expr ) override {
            if ( !expr->subexpr->type ) return Visitor::visit(expr);
            // infer
            vector<TypeDeclPtr> types = { expr->subexpr->type };
            auto functions = findMatchingFunctions(expr->op, types);
            if ( functions.size()==0 ) {
                string candidates = program->describeCandidates(findCandidates(expr->op,types));
                error("no matching operator '" + expr->op
                      + "' with argument (" + expr->subexpr->type->describe() + ")", expr->at, CompilationError::operator_not_found);
            } else if ( functions.size()>1 ) {
                string candidates = program->describeCandidates(functions);
                error("too many matching operators '" + expr->op
                      + "' with argument (" + expr->subexpr->type->describe() + ")", expr->at, CompilationError::operator_not_found);
            } else {
                expr->func = functions[0].get();
                expr->type = make_shared<TypeDecl>(*expr->func->result);
                if ( !expr->func->arguments[0]->type->isRef() )
                    expr->subexpr = Expression::autoDereference(expr->subexpr);
            }
            return Visitor::visit(expr);
        }
    // ExprOp2
        virtual ExpressionPtr visit ( ExprOp2 * expr ) override {
            if ( !expr->left->type || !expr->right->type ) return Visitor::visit(expr);
            // infer
            if ( expr->left->type->isPointer() && expr->right->type->isPointer() )
                if ( !expr->left->type->isSameType(*expr->right->type,false) )
                    error("operations on incompatible pointers are prohibited", expr->at);
            if ( expr->left->type->isEnum() && expr->right->type->isEnum() )
                if ( !expr->left->type->isSameType(*expr->right->type,false,false) )
                    error("operations on different enumerations are prohibited", expr->at);
            vector<TypeDeclPtr> types = { expr->left->type, expr->right->type };
            auto functions = findMatchingFunctions(expr->op, types);
            if ( functions.size()==0 ) {
                string candidates = program->describeCandidates(findCandidates(expr->op,types));
                error("no matching operator '" + expr->op
                      + "' with arguments (" + expr->left->type->describe() + ", " + expr->right->type->describe()
                      + ")\n" + candidates, expr->at, CompilationError::operator_not_found);
            } else if ( functions.size()>1 ) {
                string candidates = program->describeCandidates(functions);
                error("too many matching operators '" + expr->op
                      + "' with arguments (" + expr->left->type->describe() + ", " + expr->right->type->describe()
                      + ")\n" + candidates, expr->at, CompilationError::operator_not_found);
            } else {
                expr->func = functions[0].get();
                expr->type = make_shared<TypeDecl>(*expr->func->result);
                if ( !expr->func->arguments[0]->type->isRef() )
                    expr->left = Expression::autoDereference(expr->left);
                if ( !expr->func->arguments[1]->type->isRef() )
                    expr->right = Expression::autoDereference(expr->right);
            }
            return Visitor::visit(expr);
        }
    // ExprOp3
        virtual ExpressionPtr visit ( ExprOp3 * expr ) override {
            if ( !expr->subexpr->type || !expr->left->type || !expr->right->type ) return Visitor::visit(expr);
            // infer
            if ( expr->op!="?" ) {
                error("Op3 currently only supports 'is'", expr->at, CompilationError::operator_not_found);
                return Visitor::visit(expr);
            }
            expr->subexpr = Expression::autoDereference(expr->subexpr);
            if ( !expr->subexpr->type->isSimpleType(Type::tBool) ) {
                error("cond operator condition must be boolean", expr->at, CompilationError::condition_must_be_bool);
            } else if ( !expr->left->type->isSameType(*expr->right->type,false,false) ) {
                error("cond operator must return the same types on both sides",
                      expr->at, CompilationError::operator_not_found);
            } else {
                if ( expr->left->type->ref ^ expr->right->type->ref ) { // if either one is not ref
                    expr->left = Expression::autoDereference(expr->left);
                    expr->right = Expression::autoDereference(expr->right);
                }
                expr->type = make_shared<TypeDecl>(*expr->left->type);
                expr->type->constant |= expr->right->type->constant;
            }
            return Visitor::visit(expr);
        }
    // ExprMove
        virtual ExpressionPtr visit ( ExprMove * expr ) override {
            if ( !expr->left->type || !expr->right->type ) return Visitor::visit(expr);
            // infer
            if ( !expr->left->type->isSameType(*expr->right->type,false,false) ) {
                error("can only move the same type", expr->at, CompilationError::operator_not_found);
            } else if ( !expr->left->type->isRef() ) {
                error("can only move to a reference", expr->at, CompilationError::cant_write_to_non_reference);
            } else if ( expr->left->type->constant ) {
                error("can't move to a constant value", expr->at, CompilationError::cant_move_to_const);
            } else if ( !expr->left->type->canMove() ) {
                error("this type can't be moved", expr->at, CompilationError::cant_move);
            }
            expr->type = make_shared<TypeDecl>();  // we return nothing
            return Visitor::visit(expr);
        }
    // ExprCopy
        virtual ExpressionPtr visit ( ExprCopy * expr ) override {
            if ( !expr->left->type || !expr->right->type ) return Visitor::visit(expr);
            // infer
            if ( !expr->left->type->isSameType(*expr->right->type,false,false) ) {
                error("can only copy the same type " + expr->left->type->describe() + " vs " + expr->right->type->describe(),
                      expr->at, CompilationError::operator_not_found);
            } else if ( !expr->left->type->isRef() ) {
                error("can only copy to a reference", expr->at, CompilationError::cant_write_to_non_reference);
            } else if ( expr->left->type->constant ) {
                error("can't write to a constant value", expr->at, CompilationError::cant_write_to_const);
            }
            if ( !expr->left->type->canCopy() ) {
                error("this type can't be copied, use move (<-) instead", expr->at, CompilationError::cant_copy);
            }
            expr->type = make_shared<TypeDecl>();  // we return nothing
            return Visitor::visit(expr);
        }
    // ExprTryCatch
        // do nothing
    // ExprReturn
        bool inferReturnType ( TypeDeclPtr & resType, ExprReturn * expr ) {
            if ( resType->isAuto() ) {
                if ( expr->subexpr ) {
                    auto resT = TypeDecl::inferAutoType(resType, expr->subexpr->type);
                    if ( !resT ) {
                        error("type can't be infered, "
                              + resType->describe() + ", returns " + expr->subexpr->type->describe(),
                              expr->at, CompilationError::cant_infer_mismatching_restrictions );
                    } else {
                        resT->ref = false;
                        TypeDecl::applyAutoContracts(resT, resType);
                        resType = resT;
                        reportGenericInfer();
                        return true;
                    }
                } else {
                    resType = make_shared<TypeDecl>(Type::tVoid);
                    reportGenericInfer();
                    return true;
                }
            }
            if ( resType->isVoid() ) {
                if ( expr->subexpr ) {
                    error("not expecting a return value", expr->at, CompilationError::not_expecting_return_value);
                }
            } else {
                if ( !expr->subexpr ) {
                    error("expecting a return value", expr->at, CompilationError::expecting_return_value);
                } else {
                    if ( !resType->isSameType(*expr->subexpr->type,false,false) ) {
                        error("incompatible return type, expecting ("
                              + resType->describe() + ") vs (" + expr->subexpr->type->describe() + ")",
                              expr->at, CompilationError::invalid_return_type);
                    }
                    if ( resType->ref && !expr->subexpr->type->ref ) {
                        error("incompatible return type, reference matters. expecting ("
                              + resType->describe() + ") vs (" + expr->subexpr->type->describe() + ")",
                              expr->at, CompilationError::invalid_return_type);
                    }
                    if ( !resType->isConst() && expr->subexpr->type->isConst() ) {
                        error("incompatible return type, constant matters. expecting "
                              + resType->describe() + ") vs (" + expr->subexpr->type->describe() + ")",
                              expr->at, CompilationError::invalid_return_type);
                    }
                }
            }
            if ( resType->isRefType() ) {
                if ( !resType->canCopy() && !resType->canMove() ) {
                    error("this type can't be returned at all " + resType->describe(),
                          expr->at, CompilationError::invalid_return_type);
                }
            }
            return false;
        }
        virtual void preVisit ( ExprReturn * expr ) override {
            Visitor::preVisit(expr);
            expr->block = nullptr;
        }
        virtual ExpressionPtr visit ( ExprReturn * expr ) override {
            expr->func = nullptr;
            if ( blocks.size() ) {
                ExprBlock * block = blocks.back();
                expr->block = block;
                block->hasReturn = true;
                if ( expr->subexpr ) {
                    if ( !expr->subexpr->type ) return Visitor::visit(expr);
                    if ( !block->returnType->ref ) {
                        expr->subexpr = Expression::autoDereference(expr->subexpr);
                    } else {
                        expr->returnReference = true;
                    }
                    expr->returnInBlock = true;
                }
                if ( inferReturnType(block->type, expr) ) {
                    block->returnType = make_shared<TypeDecl>(*block->type);
                    setBlockCopyMoveFlags(block);
                }
                if ( block->moveOnReturn && !expr->moveSemantics ) {
                    error("this type can't be copied, use return <- instead",
                          expr->at, CompilationError::invalid_return_semantics );
                }
            } else {
                // infer
                expr->func = func.get();
                func->hasReturn = true;
                if ( expr->subexpr ) {
                    if ( !expr->subexpr->type ) return Visitor::visit(expr);
                    if ( !func->result->ref ) {
                        expr->subexpr = Expression::autoDereference(expr->subexpr);
                    } else {
                        expr->returnReference = true;
                    }
                }
                inferReturnType(func->result, expr);
                if ( func->moveOnReturn && !expr->moveSemantics ) {
                    error("this type can't be copied, use return <- instead",
                          expr->at, CompilationError::invalid_return_semantics );
                }
            }
            expr->type = make_shared<TypeDecl>();
            return Visitor::visit(expr);
        }
    // ExprBreak
        virtual ExpressionPtr visit ( ExprBreak * expr ) override {
            if ( !loop.size() )
                error("'break' without a loop", expr->at);
            return Visitor::visit(expr);
        }
    // ExprIfThenElse
        virtual ExpressionPtr visit ( ExprIfThenElse * expr ) override {
            if ( !expr->cond->type ) return Visitor::visit(expr);
            // infer
            if ( !expr->cond->type->isSimpleType(Type::tBool) ) {
                error("if-then-else condition must be boolean", expr->at, CompilationError::condition_must_be_bool);
            }
            if ( expr->cond->type->isRef() ) {
                expr->cond = Expression::autoDereference(expr->cond);
            }
            return Visitor::visit(expr);
        }
    // ExprWith
        virtual void preVisit ( ExprWith * expr ) override {
            Visitor::preVisit(expr);
            with.push_back(expr);
        }
        virtual ExpressionPtr visit ( ExprWith * expr ) override {
            if ( auto wT = expr->with->type ) {
                StructurePtr pSt;
                if ( wT->dim.size() ) {
                    error("with array in undefined, " + wT->describe(), expr->at,
                          CompilationError::invalid_with_type );
                } else if ( wT->isStructure() ) {
                    pSt = wT->structType->shared_from_this();
                } else if ( wT->isPointer() && wT->firstType && wT->firstType->isStructure() ) {
                    pSt = wT->firstType->structType->shared_from_this();
                } else {
                    error("unexpected with type " + wT->describe(), expr->at,
                          CompilationError::invalid_with_type );
                }
                if ( pSt ) {
                    for ( auto fi : pSt->fields ) {
                        for ( auto & lv : local ) {
                            if ( lv->name==fi.name ) {
                                error("with expression shadows local variable " +
                                      lv->name + " at line " + to_string(lv->at.line),
                                        expr->at, CompilationError::variable_not_found);
                            }
                        }
                    }
                }
            }
            with.pop_back();
            return Visitor::visit(expr);
        }
    // ExprWhile
        virtual void preVisit ( ExprWhile * expr ) override {
            Visitor::preVisit(expr);
            loop.push_back(expr->shared_from_this());
        }
        virtual ExpressionPtr visit ( ExprWhile * expr ) override {
            loop.pop_back();
            if ( !expr->cond->type ) return Visitor::visit(expr);
            // infer
            if ( !expr->cond->type->isSimpleType(Type::tBool) ) {
                error("while loop condition must be boolean", expr->at);
            }
            if ( expr->cond->type->isRef() ) {
                expr->cond = Expression::autoDereference(expr->cond);
            }
            return Visitor::visit(expr);
        }
    // ExprFor
        virtual void preVisit ( ExprFor * expr ) override {
            Visitor::preVisit(expr);
            loop.push_back(expr->shared_from_this());
            pushVarStack();
        }
        virtual void preVisitForStack ( ExprFor * expr ) override {
            Visitor::preVisitForStack(expr);
            if ( !expr->iterators.size() ) {
                error("for loop needs at least one iterator", expr->at);
                return;
            } else if ( expr->iterators.size() != expr->sources.size() ) {
                error("for loop needs as many iterators as there are sources", expr->at);
                return;
            } else if ( expr->sources.size()>MAX_FOR_ITERATORS ) {
                error("for loop has too many sources", expr->at);
                return;
            }
            // iterator variables
            int idx = 0;
            expr->iteratorVariables.clear();
            for ( auto & src : expr->sources ) {
                if ( !src->type ) continue;
                auto pVar = make_shared<Variable>();
                pVar->name = expr->iterators[idx];
                pVar->at = expr->at;
                if ( src->type->dim.size() ) {
                    pVar->type = make_shared<TypeDecl>(*src->type);
                    pVar->type->ref = true;
                    pVar->type->dim.pop_back();
                } else if ( src->type->isGoodIteratorType() ) {
                    pVar->type = make_shared<TypeDecl>(*src->type->firstType);
                } else if ( src->type->isGoodArrayType() ) {
                    pVar->type = make_shared<TypeDecl>(*src->type->firstType);
                    pVar->type->ref = true;
                } else if ( src->type->isRange() ) {
                    pVar->type = make_shared<TypeDecl>(src->type->getRangeBaseType());
                    pVar->type->ref = false;
                } else if ( src->type->isHandle() && src->type->annotation->isIterable() ) {
                    pVar->type = make_shared<TypeDecl>(*src->type->annotation->makeIteratorType());
                } else {
                    error("unsupported iteration type for the loop variable " + pVar->name, expr->at);
                    return;
                }
                pVar->type->constant |= src->type->isConst();
                pVar->source = src;
                local.push_back(pVar);
                expr->iteratorVariables.push_back(pVar);
                ++ idx;
            }
        }
        virtual ExpressionPtr visit ( ExprFor * expr ) override {
            popVarStack();
            loop.pop_back();
            return Visitor::visit(expr);
        }
    // ExprLet
        virtual void preVisit ( ExprLet * expr ) override {
            Visitor::preVisit(expr);
            if ( expr->scoped ) {
                pushVarStack();
            }
        }
        virtual void preVisitLet ( ExprLet * expr, const VariablePtr & var, bool last ) override {
            Visitor::preVisitLet(expr, var, last);
            if ( var->type->isAlias() ) {
                auto aT = inferAlias(var->type);
                if ( aT ) {
                    var->type = aT;
                    reportGenericInfer();
                } else {
                    error("udefined type " + var->type->describe(), var->at, CompilationError::type_not_found);
                }
            }
            if ( var->type->isAuto() && !var->init) {
                error("local variable type can't be infered, it needs an initializer",
                      var->at, CompilationError::cant_infer_missing_initializer );
            }
            for ( auto & lv : local ) {
                if ( lv->name==var->name ) {
                    error("local variable " + var->name +" is shadowed by another local variable "
                          + lv->name + " : " + lv->type->describe() + " at line " + to_string(lv->at.line),
                          var->at, CompilationError::variable_not_found);
                    break;
                }
            }
            if ( auto eW = hasMatchingWith(var->name) ) {
                error("local variable " + var->name + " is shadowed by with expression at line " + to_string(eW->at.line),
                      var->at, CompilationError::variable_not_found);
            }
            local.push_back(var);
        }
        virtual VariablePtr visitLet ( ExprLet * expr, const VariablePtr & var, bool last ) override {
            if ( var->type->ref && !var->init )
                error("local reference has to be initialized",
                      var->at, CompilationError::invalid_variable_type);
            if ( var->type->isVoid() )
                error("local variable can't be declared void",
                      var->at, CompilationError::invalid_variable_type);
            if ( var->type->isHandle() && !var->type->annotation->isLocal() )
                error("can't have local variable of handled type " + var->type->annotation->name ,
                      var->at, CompilationError::invalid_variable_type);
            if ( !var->type->isAuto() && !var->type->isAlias() ){
                if ( var->init && var->init->rtti_isCast() ) {
                    auto castExpr = static_pointer_cast<ExprCast>(var->init);
                    if ( castExpr->castType->isAuto() ) {
                        reportGenericInfer();
                        castExpr->castType = make_shared<TypeDecl>(*var->type);
                    }
                }
            }
            verifyType(var->type);
            if ( expr->inScope && var->type->canDelete() ) {
                auto scope = scopes.back();
                auto del = makeDelete(var);
                scope->finalList.insert(scope->finalList.begin(), del);
            }
            return Visitor::visitLet(expr,var,last);
        }
        virtual ExpressionPtr visitLetInit ( ExprLet * expr, const VariablePtr & var, Expression * init ) override {
            if ( !var->init->type ) return Visitor::visitLetInit(expr, var, init);
            if ( var->type->isAuto() ) {
                auto varT = TypeDecl::inferAutoType(var->type, var->init->type);
                if ( !varT ) {
                    error("local variable initialization type can't be infered, "
                          + var->type->describe() + " = " + var->init->type->describe(),
                          var->at, CompilationError::cant_infer_mismatching_restrictions );
                } else {
                    varT->ref = false;
                    TypeDecl::applyAutoContracts(varT, var->type);
                    var->type = varT;
                    reportGenericInfer();
                }
            } else if ( !var->type->isSameType(*var->init->type,false,false) ) {
                error("local variable initialization type mismatch, "
                      + var->type->describe() + " = " + var->init->type->describe(), var->at,
                        CompilationError::invalid_initialization_type);
            } else if ( var->type->ref && !var->type->isSameType(*var->init->type,false,false) && var->init->type->isRef()) {
                error("local variable initialization type mismatch. reference can't be initialized via value, "
                      + var->type->describe() + " = " + var->init->type->describe(), var->at,
                        CompilationError::invalid_initialization_type);
            } else if ( var->type->isRef() &&  !var->type->isConst() && var->init->type->isConst() ) {
                error("local variable initialization type mismatch. const matters, "
                      + var->type->describe() + " = " + var->init->type->describe(), var->at,
                    CompilationError::invalid_initialization_type);
            } else if ( !var->init->type->canCopy() && !var->init->type->canMove() ) {
                error("this local variable can't be initialized at all", var->at,
                    CompilationError::invalid_initialization_type);
            } else if ( !var->type->ref && !var->init->type->canCopy()
                       && var->init->type->canMove() && !var->move_to_init ) {
                error("this local variable can only be move-initialized, use <- for that", var->at,
                    CompilationError::invalid_initialization_type);
            }
            return Visitor::visitLetInit(expr, var, init);
        }
        virtual ExpressionPtr visit ( ExprLet * expr ) override {
            if ( expr->scoped ) {
                popVarStack();
            }
            if ( expr->inScope ) {
                expr->inScope = false;
                reportGenericInfer();
            }
            return Visitor::visit(expr);
        }
    // ExprLooksLikeCall
        virtual void preVisit ( ExprLooksLikeCall * call ) override {
            Visitor::preVisit(call);
            call->argumentsFailedToInfer = false;
        }
        virtual ExpressionPtr visitLooksLikeCallArg ( ExprLooksLikeCall * call, Expression * arg , bool last ) override {
            if ( !arg->type ) call->argumentsFailedToInfer = true;
            return Visitor::visitLooksLikeCallArg(call, arg, last);
        }
    // ExprCall
        virtual void preVisit ( ExprCall * call ) override {
            Visitor::preVisit(call);
            call->argumentsFailedToInfer = false;
        }
        virtual ExpressionPtr visitCallArg ( ExprCall * call, Expression * arg , bool last ) override {
            if ( !arg->type ) call->argumentsFailedToInfer = true;
            return Visitor::visitCallArg(call, arg, last);
        }
        FunctionPtr inferFunctionCall ( ExprLooksLikeCall * expr ) {
            // infer
            vector<TypeDeclPtr> types;
            types.reserve(expr->arguments.size());
            for ( auto & ar : expr->arguments ) {
                if ( !ar->type ) {
                    return nullptr;
                }
                types.push_back(ar->type);
            }
            auto functions = findMatchingFunctions(expr->name, types, true);
            if ( functions.size()==0 ) {
                // ok, time to find us a good generic
                auto generics = findMatchingGenerics(expr->name, types);
                if ( generics.size()==1 ) {
                    auto oneGeneric = generics[0];
                    auto clone = oneGeneric->clone();
                    clone->inferStack.emplace_back(expr->at, func);
                    clone->inferStack.insert(clone->inferStack.end(), func->inferStack.begin(), func->inferStack.end());
                    for ( size_t sz = 0; sz != types.size(); ++sz ) {
                        auto & argT = clone->arguments[sz]->type;
                        if ( argT->isAuto() ) {
                            auto & passT = types[sz];
                            auto resT = TypeDecl::inferAutoType(argT, passT);
                            DAS_ASSERTF(resT, "how? we had this working at findMatchingGenerics");
                            resT->ref = false;              // by default no ref
                            TypeDecl::applyAutoContracts(resT, argT);
                            if ( resT->isRefType() ) {   // we don't pass boxed type by reference ever
                                resT->ref = false;
                            }
                            argT = resT;
                        }
                    }
                    if ( program->addFunction(clone) ) {
                        reportGenericInfer();
                    } else {
                        auto realFn = program->findFunction(clone->getMangledName());
                        vector<FunctionPtr> candidates = { realFn };
                        reportFunctionNotFound("no matching generic function " + expr->describe(),
                                               expr->at, candidates, types, true, true);
                    }
                } else if ( generics.size()>0 ) {
                    reportFunctionNotFound("too many matching generic functions " + expr->describe(),
                                           expr->at, findGenericCandidates(expr->name, types), types, true, true);
                } else {
                    if ( auto aliasT = findAlias(expr->name) ) {
                        if ( aliasT->isCtorType() ) {
                            expr->name = das_to_string(aliasT->baseType);
                            reportGenericInfer();
                        }
                    } else {
                        reportFunctionNotFound("no matching function " + expr->describe(),
                                               expr->at, findCandidates(expr->name, types), types, false, true);
                    }
                }
            } else if ( functions.size()>1 ) {
                string candidates = program->describeCandidates(functions);
                error("too many matching functions " + expr->describe() + "\n" + candidates,
                      expr->at, CompilationError::function_not_found);
            } else {
                auto funcC = functions[0];
                expr->type = make_shared<TypeDecl>(*funcC->result);
                // infer FORWARD types
                for ( size_t iF=0; iF!=expr->arguments.size(); ++iF ) {
                    auto & arg = expr->arguments[iF];
                    if ( arg->type->isAuto() && arg->type->isGoodBlockType() ) {
                        DAS_ASSERTF ( arg->rtti_isMakeBlock(), "it's always MakeBlock. this is how we construct new [[ ]]" );
                        auto mkBlock = static_pointer_cast<ExprMakeBlock>(arg);
                        auto block = static_pointer_cast<ExprBlock>(mkBlock->block);
                        auto retT = TypeDecl::inferAutoType(mkBlock->type, funcC->arguments[iF]->type);
                        DAS_ASSERTF ( retT, "how? it matched during findMatchingFunctions the same way");
                        TypeDecl::applyAutoContracts(mkBlock->type, funcC->arguments[iF]->type);
                        block->returnType = make_shared<TypeDecl>(*retT->firstType);
                        for ( size_t ba=0; ba!=retT->argTypes.size(); ++ba ) {
                            block->arguments[ba]->type = make_shared<TypeDecl>(*retT->argTypes[ba]);
                        }
                        setBlockCopyMoveFlags(block.get());
                        reportGenericInfer();
                    }
                }
                // append default arguments
                for ( size_t iT = expr->arguments.size(); iT != funcC->arguments.size(); ++iT ) {
                    auto newArg = funcC->arguments[iT]->init->clone();
                    if ( !newArg->type ) {
                        // recursive resolve???
                        newArg = newArg->visit(*this);
                    }
                    expr->arguments.push_back(newArg);
                }
                // dereference what needs dereferences
                for ( size_t iA = 0; iA != expr->arguments.size(); ++iA )
                    if ( !funcC->arguments[iA]->type->isRef() )
                        expr->arguments[iA] = Expression::autoDereference(expr->arguments[iA]);
                // and all good
                return funcC;
            }
            return nullptr;
        }
        virtual ExpressionPtr visit ( ExprCall * expr ) override {
            expr->func = inferFunctionCall(expr).get();
            return Visitor::visit(expr);
        }
    // ExprKeys
        virtual ExpressionPtr visit ( ExprKeys * expr ) override {
            if ( expr->argumentsFailedToInfer ) return Visitor::visit(expr);
            if ( expr->arguments.size()!=1 ) {
                error("expecting Keys(table)", expr->at);
                return Visitor::visit(expr);
            }
            // infer
            auto tableType = expr->arguments[0]->type;
            if ( !tableType->isGoodTableType() ) {
                error("must be fully qualified table", expr->at);
                return Visitor::visit(expr);
            }
            auto iterType = tableType->firstType;
            expr->arguments[0]->type->constant = true;
            expr->type = make_shared<TypeDecl>(Type::tIterator);
            expr->type->firstType = make_shared<TypeDecl>(*iterType);
            expr->type->firstType->ref = true;
            expr->type->firstType->constant = true;
            return Visitor::visit(expr);
        }
    // ExprValues
        virtual ExpressionPtr visit ( ExprValues * expr ) override {
            if ( expr->argumentsFailedToInfer ) return Visitor::visit(expr);
            if ( expr->arguments.size()!=1 ) {
                error("expecting Values(table)", expr->at);
                return Visitor::visit(expr);
            }
            // infer
            auto tableType = expr->arguments[0]->type;
            if ( !tableType->isGoodTableType() ) {
                error("must be fully qualified table", expr->at);
                return Visitor::visit(expr);
            }
            auto iterType = tableType->secondType;
            expr->arguments[0]->type->constant = true;
            expr->type = make_shared<TypeDecl>(Type::tIterator);
            expr->type->firstType = make_shared<TypeDecl>(*iterType);
            expr->type->firstType->ref = true;
            expr->type->firstType->constant = false;
            return Visitor::visit(expr);
        }
    // StringBuilder
        virtual ExpressionPtr visitStringBuilderElement ( ExprStringBuilder *, Expression * expr, bool ) override {
            return Expression::autoDereference(expr->shared_from_this());
        }
        virtual ExpressionPtr visit ( ExprStringBuilder * expr ) override {
            expr->type = make_shared<TypeDecl>(Type::tString);
            return Visitor::visit(expr);
        }
    // make structure
        virtual void preVisit ( ExprMakeStructure * expr ) override {
            Visitor::preVisit(expr);
            verifyType(expr->makeType);
            if ( expr->makeType->baseType != Type::tStructure ) {
                error("[[" + expr->makeType->describe() + "]] with non-structure type", expr->at, CompilationError::invalid_type);
            } else if ( expr->makeType->dim.size()>1 ) {
                error("[[" + expr->makeType->describe() + "]] can only initialize single dimension arrays", expr->at, CompilationError::invalid_type);
            } else if ( expr->makeType->dim.size()==1 && expr->makeType->dim[0]!=expr->structs.size() ) {
                error("[[" + expr->makeType->describe() + "]] dimension mismatch, provided " +
                      to_string(expr->structs.size()) + " elements", expr->at,
                          CompilationError::invalid_type);
            } else if ( expr->makeType->ref ) {
                error("[[" + expr->makeType->describe() + "]] can't be reference", expr->at, CompilationError::invalid_type);
            }
        }
        virtual MakeFieldDeclPtr visitMakeStructureField ( ExprMakeStructure * expr, int index, MakeFieldDecl * decl, bool last ) override {
            if ( !decl->value->type ) {
                return Visitor::visitMakeStructureField(expr,index,decl,last);
            }
            if ( expr->makeType->baseType == Type::tStructure ) {
                if ( auto field = expr->makeType->structType->findField(decl->name) ) {
                    if ( !field->type->isSameType(*decl->value->type,false,false) ) {
                        error("can't initialize field, " + decl->name + " expecting ("
                              +field->type->describe()+"), passing ("+decl->value->type->describe()+")",
                                decl->value->at, CompilationError::invalid_type );
                    }
                    if( !field->type->canCopy() && !decl->moveSemantic ) {
                        error("this field can't be copied, use <- instead",
                              decl->at, CompilationError::invalid_type );
                    }
                } else {
                    error("field not found, " + decl->name, decl->at, CompilationError::cant_get_field);
                }
            }
            return Visitor::visitMakeStructureField(expr,index,decl,last);
        }
        virtual ExpressionPtr visit ( ExprMakeStructure * expr ) override {
            // see if we need to fill in missing fields
            if ( expr->useInitializer && expr->makeType->structType ) {
                for ( auto & stf : expr->makeType->structType->fields  ) {
                    if ( stf.init  ) {
                        if ( !stf.init->type || stf.init->type->isAuto() ) {
                            error("not fully resolved yet", expr->at);
                            return Visitor::visit(expr);
                        }
                    }
                }
                bool anyInit = false;
                for ( auto & st : expr->structs ) {
                    for ( auto & fi : expr->makeType->structType->fields ) {
                        if ( fi.init ) {
                            anyInit = true;
                            auto it = find_if(st->begin(), st->end(), [&](const MakeFieldDeclPtr & fd){
                                return fd->name == fi.name;
                            });
                            if ( it==st->end() ) {
                                auto msf = make_shared<MakeFieldDecl>(fi.at, fi.name, fi.init->clone(), !fi.init->type->canCopy());
                                st->push_back(msf);
                                reportGenericInfer();
                            }
                        }
                    }
                }
                if ( !anyInit ) {
                    error("[[" + expr->makeType->describe() + "() ]] does not have default initializer",
                          expr->at, CompilationError::invalid_type);
                } else {
                    expr->useInitializer = false;
                }
            }
            // result type
            auto resT = make_shared<TypeDecl>(*expr->makeType);
            uint32_t resDim = uint32_t(expr->structs.size());
            if ( resDim!=1 ) {
                resT->dim.resize(1);
                resT->dim[0] = resDim;
            } else {
                resT->dim.clear();
            }
            expr->type = resT;
            verifyType(expr->type);
            return Visitor::visit(expr);
        }
    // make array
        virtual void preVisit ( ExprMakeArray * expr ) override {
            Visitor::preVisit(expr);
            verifyType(expr->makeType);
            if ( expr->makeType->dim.size()>1 ) {
                error("[[" + expr->makeType->describe() + "]] can only initialize single dimension arrays",
                      expr->at, CompilationError::invalid_type);
            } else if ( expr->makeType->dim.size()==1 && expr->makeType->dim[0]!=expr->values.size() ) {
                error("[[" + expr->makeType->describe() + "]] dimension mismatch, provided " +
                      to_string(expr->values.size()) + " elements", expr->at,
                      CompilationError::invalid_type);
            } else if ( expr->makeType->ref ) {
                error("[[" + expr->makeType->describe() + "]] can't be reference", expr->at, CompilationError::invalid_type);
            }
            expr->recordType = make_shared<TypeDecl>(*expr->makeType);
            expr->recordType->dim.clear();
        }
        virtual ExpressionPtr visitMakeArrayIndex ( ExprMakeArray * expr, int index, Expression * init, bool last ) override {
            if ( !init->type ) {
                return Visitor::visitMakeArrayIndex(expr,index,init,last);
            }
            if ( !expr->recordType->isSameType(*init->type,false,false) ) {
                error("can't initialize array element, " + to_string(index) + " expecting ("
                      +expr->recordType->describe()+"), passing ("+init->type->describe()+")",
                        init->at, CompilationError::invalid_type );
            }
            return Visitor::visitMakeArrayIndex(expr,index,init,last);
        }
        virtual ExpressionPtr visit ( ExprMakeArray * expr ) override {
            auto resT = make_shared<TypeDecl>(*expr->makeType);
            uint32_t resDim = uint32_t(expr->values.size());
            if ( resDim!=1 ) {
                resT->dim.resize(1);
                resT->dim[0] = resDim;
            } else {
                resT->dim.clear();
            }
            expr->type = resT;
            verifyType(expr->type);
            return Visitor::visit(expr);
        }
    };

    // program

    void Program::inferTypes(TextWriter & logs) {
        const bool log = options.getOption("logInferPasses",false);
        int pass = 0, maxPasses = 50;
        if (auto maxP = options.find("maxInferPasses", Type::tInt)) {
            maxPasses = maxP->iValue;
        }
        if ( log ) {
            logs << "INITIAL CODE:\n" << *this;
        }
        for ( pass = 0; pass < maxPasses; ++pass ) {
            failToCompile = false;
            errors.clear();
            InferTypes ift(shared_from_this());
            visit(ift);
            for ( auto efn : ift.extraFunctions ) {
                addFunction(efn);
            }
            if ( log ) {
                logs << "PASS " << pass << ":\n" << *this;
                sort(errors.begin(), errors.end());
                for (auto & err : errors) {
                    logs << reportError(err.at, err.what, err.cerr);
                }
            }
            if ( ift.finished() )
                break;
        }
        if (pass == maxPasses) {
            error("type inference exceeded maximum allowed number of passes ("+to_string(maxPasses)+")\n"
                    "this is likely due to a loop in the type system", LineInfo(), CompilationError::too_many_infer_passes);
        }
    }
}


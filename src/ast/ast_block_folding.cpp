#include "daScript/misc/platform.h"

#include "daScript/ast/ast.h"

namespace das {

    // this folds the following, by setting r2v flag on expressions
    //  r2v(var)            = @var
    //  r2v(expr.field)     = expr.@field
    //  r2v(expr[index])    = expr@[index]
    //  r2v(a ? b : c)      = a ? r2v(b) : r2v(c)
    //  r2v(cast(x))        = cast(r2v(x))
    class RefFolding : public OptVisitor {
    protected:
        virtual ExpressionPtr visit ( ExprRef2Value * expr ) override {
            if ( expr->subexpr->rtti_isCast() ) {
                reportFolding();
                auto ecast = static_pointer_cast<ExprCast>(expr->subexpr);
                auto nr2v = make_shared<ExprRef2Value>();
                nr2v->at = expr->at;
                nr2v->subexpr = ecast->subexpr;
                ecast->subexpr = nr2v;
                ecast->type->ref = false;
                return ecast;
            } else if ( expr->subexpr->rtti_isVar() ) {
                if ( expr->subexpr->type->isHandle() ) {
                    return Visitor::visit(expr);
                } else {
                    reportFolding();
                    auto evar = static_pointer_cast<ExprVar>(expr->subexpr);
                    evar->r2v = true;
                    evar->type->ref = false;
                    return evar;
                }
            } else if ( expr->subexpr->rtti_isField() ) {
                reportFolding();
                auto efield = static_pointer_cast<ExprField>(expr->subexpr);
                efield->r2v = true;
                efield->type->ref = false;
                return efield;
            } else if ( expr->subexpr->rtti_isSwizzle() ) {
                reportFolding();
                auto eswiz = static_pointer_cast<ExprSwizzle>(expr->subexpr);
                eswiz->r2v = true;
                eswiz->type->ref = false;
                if (!TypeDecl::isSequencialMask(eswiz->fields)) {
                    eswiz->value = Expression::autoDereference(eswiz->value);
                }
                return eswiz;
            }else if ( expr->subexpr->rtti_isSafeField() ) {
                reportFolding();
                auto efield = static_pointer_cast<ExprSafeField>(expr->subexpr);
                efield->r2v = true;
                efield->type->ref = false;
                return efield;
            } else if ( expr->subexpr->rtti_isAt() ) {
                reportFolding();
                auto eat = static_pointer_cast<ExprAt>(expr->subexpr);
                eat->r2v = true;
                eat->type->ref = false;
                return eat;
            } else if ( expr->subexpr->rtti_isOp3() ) {
                reportFolding();
                auto op3 = static_pointer_cast<ExprOp3>(expr->subexpr);
                op3->left = Expression::autoDereference(op3->left);
                op3->right = Expression::autoDereference(op3->right);
                op3->type->ref = false;
                return expr->subexpr;
            } else if ( expr->subexpr->rtti_isNullCoalescing() ) {
                reportFolding();
                auto nc = static_pointer_cast<ExprNullCoalescing>(expr->subexpr);
                nc->defaultValue = Expression::autoDereference(nc->defaultValue);
                nc->type->ref = false;
                return nc;
            } else {
                return Visitor::visit(expr);
            }
        }
    };

    class BlockFolding : public OptVisitor {
    protected:
        void collect ( vector<ExpressionPtr> & list, vector<ExpressionPtr> & blockList ) {
            for ( auto & expr : blockList ) {
                if ( !expr ) continue;
                if ( expr->rtti_isBreak() || expr->rtti_isReturn() ) {
                    list.push_back(expr);
                    break;
                }
                if ( expr->rtti_isBlock() ) {
                    auto pBlock = static_pointer_cast<ExprBlock>(expr);
                    if ( !pBlock->isClosure && !pBlock->finalList.size() ) {
                        collect(list, pBlock->list);
                    } else {
                        list.push_back(expr);
                    }
                } else if ( expr->rtti_isWith() ) {
                    auto pWith = static_pointer_cast<ExprWith>(expr);
                    if ( pWith->body ) {
                        list.push_back(pWith->body);
                    }
                } else {
                    list.push_back(expr);
                }
            }
        }
    protected:
    // ExprBlock
        virtual ExpressionPtr visit ( ExprBlock * block ) override {
            vector<ExpressionPtr> list;
            collect(list, block->list);
            if ( list!=block->list ) {
                swap ( block->list, list );
                reportFolding();
            }
            vector<ExpressionPtr> finalList;
            collect(finalList, block->finalList);
            if ( finalList!=block->finalList ) {
                swap ( block->finalList, finalList );
                reportFolding();
            }
            return Visitor::visit(block);
        }
    // ExprLet
        virtual ExpressionPtr visit ( ExprLet * let ) override {
            if ( let->variables.size()==0 ) {
                reportFolding();
                return let->subexpr;
            }
            return Visitor::visit(let);
        }
    // function
        virtual FunctionPtr visit ( Function * func ) override {
            if ( func->body && func->result->isVoid() ) {   // remove trailing return on the void function
                if ( func->body->rtti_isBlock() ) {
                    auto block = static_pointer_cast<ExprBlock>(func->body);
                    if ( block->list.size() && block->list.back()->rtti_isReturn() ) {
                        block->list.resize(block->list.size()-1);
                        reportFolding();
                        return Visitor::visit(func);
                    }
                }
            }
            return Visitor::visit(func);
        }
    };

    class CondFolding : public OptVisitor {
    protected:
        virtual ExpressionPtr visit ( ExprIfThenElse * expr ) override {
            // if (cond) return x; else return y; => (cond ? x : y)
            if (expr->if_false) {
                shared_ptr<ExprReturn> lr, rr;
                if (expr->if_true->rtti_isBlock()) {
                    auto tb = static_pointer_cast<ExprBlock>(expr->if_true);
                    if (tb->list.size() == 1 && tb->list.back()->rtti_isReturn()) {
                        lr = static_pointer_cast<ExprReturn>(tb->list.back());
                    }
                }
                if (expr->if_false->rtti_isBlock()) {
                    auto fb = static_pointer_cast<ExprBlock>(expr->if_false);
                    if (fb->list.size() == 1 && fb->list.back()->rtti_isReturn()) {
                        rr = static_pointer_cast<ExprReturn>(fb->list.back());
                    }
                }
                if (lr && rr) {
                    if ( lr->subexpr ) {
                        auto newCond = make_shared<ExprOp3>(expr->at, "?", expr->cond, lr->subexpr, rr->subexpr);
                        newCond->type = make_shared<TypeDecl>(*lr->subexpr->type);
                        auto newRet = make_shared<ExprReturn>(expr->at, newCond);
                        reportFolding();
                        return newRet;
                    } else {
                        // this is actually if ( a ) return; else return;
                        reportFolding();
                        return lr;
                    }
                }
            }
            return Visitor::visit(expr);
        }
        // ExprBlock
        virtual ExpressionPtr visit ( ExprBlock * block ) override {
            /*
            if ( cond )
                ...
                break or return
            b
                =>
            if ( cond )
                ...
                break or return
            else
                b
            */
            if (!block->isClosure && block->list.size() > 1) {
                for ( int i=0; i!=int(block->list.size())-1; ++i ) {
                    auto expr = block->list[i];
                    if (expr != block->list.back()) {
                        if (expr->rtti_isIfThenElse()) {
                            auto ite = static_pointer_cast<ExprIfThenElse>(expr);
                            if (!ite->if_false) {
                                if (ite->if_true->rtti_isBlock()) {
                                    auto tb = static_pointer_cast<ExprBlock>(ite->if_true);
                                    if ( tb->list.size() ) {
                                        auto lastE = tb->list.back();
                                        if (lastE->rtti_isReturn() || lastE->rtti_isBreak()) {
                                            vector<ExpressionPtr> tail;
                                            tail.insert(tail.begin(), block->list.begin() + i + 1, block->list.end());
                                            auto fb = make_shared<ExprBlock>();
                                            fb->at = tail.front()->at;
                                            swap(fb->list, tail);
                                            ite->if_false = fb;
                                            block->list.resize(i + 1);
                                            reportFolding();
                                            return Visitor::visit(block);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return Visitor::visit(block);
        }
    };

    // program

    bool Program::optimizationRefFolding() {
        bool any = false, anything = false;
        do {
            RefFolding rf;
            visit(rf);
            any = rf.didAnything();
            anything |= any;
        } while ( any );
        return anything;
    }

    bool Program::optimizationBlockFolding() {
        BlockFolding bf;
        visit(bf);
        return bf.didAnything();
    }

    bool Program::optimizationCondFolding() {
        CondFolding cf;
        visit(cf);
        return cf.didAnything();
    }

}


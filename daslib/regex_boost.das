options indenting = 4

module regex_boost

require ast
require strings
require daslib/ast_boost
require daslib/regex

[reader_macro(name="regex")]
class RegexReader : AstReaderMacro
    def override accept ( prog:ProgramPtr; mod:Module?; var expr:ExprReader?; ch:int; info:LineInfo ) : bool
        if ch!='\n' && ch!='\r'
            append(expr.sequence,ch)
        if ends_with(expr.sequence,"%%")
            let len = length(expr.sequence)
            resize(expr.sequence,len-2)
            return false
        else
            return true
    def override visit ( prog:ProgramPtr; mod:Module?; expr:smart_ptr<ExprReader> ) : ExpressionPtr
        var regex:Regex
        peek(expr.sequence) <| $ ( seqStr )
            regex_compile(regex,seqStr)
        if !is_valid(regex)
            delete regex
            macro_error(prog,expr.at,"regular expression did not compile")
            return [[ExpressionPtr]]
        // TODO: turn into AOT?
        let re_data <- convert_to_expression(regex,expr.at)
        delete regex
        var creg <- new [[ExprCall() at=expr.at, name:="regex::regex_compile"]]
        push(creg.arguments,re_data)
        return creg

/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         DAS2_YYSTYPE
#define YYLTYPE         DAS2_YYLTYPE
/* Substitute the variable and function names.  */
#define yyparse         das2_yyparse
#define yylex           das2_yylex
#define yyerror         das2_yyerror
#define yydebug         das2_yydebug
#define yynerrs         das2_yynerrs

/* First part of user prologue.  */

    #include "daScript/misc/platform.h"
    #include "daScript/simulate/debug_info.h"
    #include "daScript/ast/compilation_errors.h"

    #ifdef _MSC_VER
    #pragma warning(disable:4262)
    #pragma warning(disable:4127)
    #pragma warning(disable:4702)
    #endif

    using namespace das;

    union DAS2_YYSTYPE;
    struct DAS2_YYLTYPE;

    #define YY_NO_UNISTD_H
    #include "lex2.yy.h"

    void das2_yyerror ( DAS2_YYLTYPE * lloc, yyscan_t scanner, const string & error );
    void das2_yyfatalerror ( DAS2_YYLTYPE * lloc, yyscan_t scanner, const string & error, CompilationError cerr );
    int yylex ( DAS2_YYSTYPE *lvalp, DAS2_YYLTYPE *llocp, yyscan_t scanner );
    void yybegin ( const char * str );

    void das2_yybegin_reader ( yyscan_t yyscanner );
    void das2_yyend_reader ( yyscan_t yyscanner );
    void das2_accept_sequence ( yyscan_t yyscanner, const char * seq, size_t seqLen, int lineNo, FileInfo * info );

    namespace das { class Module; }
    void das2_collect_keywords ( das::Module * mod, yyscan_t yyscanner );

    #undef yyextra
    #define yyextra (*((das::DasParserState **)(scanner)))


# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "ds2_parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LEXER_ERROR = 3,                /* "lexer error"  */
  YYSYMBOL_DAS_CAPTURE = 4,                /* "capture"  */
  YYSYMBOL_DAS_STRUCT = 5,                 /* "struct"  */
  YYSYMBOL_DAS_CLASS = 6,                  /* "class"  */
  YYSYMBOL_DAS_LET = 7,                    /* "let"  */
  YYSYMBOL_DAS_DEF = 8,                    /* "def"  */
  YYSYMBOL_DAS_WHILE = 9,                  /* "while"  */
  YYSYMBOL_DAS_IF = 10,                    /* "if"  */
  YYSYMBOL_DAS_STATIC_IF = 11,             /* "static_if"  */
  YYSYMBOL_DAS_ELSE = 12,                  /* "else"  */
  YYSYMBOL_DAS_FOR = 13,                   /* "for"  */
  YYSYMBOL_DAS_CATCH = 14,                 /* "recover"  */
  YYSYMBOL_DAS_TRUE = 15,                  /* "true"  */
  YYSYMBOL_DAS_FALSE = 16,                 /* "false"  */
  YYSYMBOL_DAS_NEWT = 17,                  /* "new"  */
  YYSYMBOL_DAS_TYPEINFO = 18,              /* "typeinfo"  */
  YYSYMBOL_DAS_TYPE = 19,                  /* "type"  */
  YYSYMBOL_DAS_IN = 20,                    /* "in"  */
  YYSYMBOL_DAS_IS = 21,                    /* "is"  */
  YYSYMBOL_DAS_AS = 22,                    /* "as"  */
  YYSYMBOL_DAS_ELIF = 23,                  /* "elif"  */
  YYSYMBOL_DAS_STATIC_ELIF = 24,           /* "static_elif"  */
  YYSYMBOL_DAS_ARRAY = 25,                 /* "array"  */
  YYSYMBOL_DAS_RETURN = 26,                /* "return"  */
  YYSYMBOL_DAS_NULL = 27,                  /* "null"  */
  YYSYMBOL_DAS_BREAK = 28,                 /* "break"  */
  YYSYMBOL_DAS_TRY = 29,                   /* "try"  */
  YYSYMBOL_DAS_OPTIONS = 30,               /* "options"  */
  YYSYMBOL_DAS_TABLE = 31,                 /* "table"  */
  YYSYMBOL_DAS_EXPECT = 32,                /* "expect"  */
  YYSYMBOL_DAS_CONST = 33,                 /* "const"  */
  YYSYMBOL_DAS_REQUIRE = 34,               /* "require"  */
  YYSYMBOL_DAS_OPERATOR = 35,              /* "operator"  */
  YYSYMBOL_DAS_ENUM = 36,                  /* "enum"  */
  YYSYMBOL_DAS_FINALLY = 37,               /* "finally"  */
  YYSYMBOL_DAS_DELETE = 38,                /* "delete"  */
  YYSYMBOL_DAS_DEREF = 39,                 /* "deref"  */
  YYSYMBOL_DAS_TYPEDEF = 40,               /* "typedef"  */
  YYSYMBOL_DAS_TYPEDECL = 41,              /* "typedecl"  */
  YYSYMBOL_DAS_WITH = 42,                  /* "with"  */
  YYSYMBOL_DAS_AKA = 43,                   /* "aka"  */
  YYSYMBOL_DAS_ASSUME = 44,                /* "assume"  */
  YYSYMBOL_DAS_CAST = 45,                  /* "cast"  */
  YYSYMBOL_DAS_OVERRIDE = 46,              /* "override"  */
  YYSYMBOL_DAS_ABSTRACT = 47,              /* "abstract"  */
  YYSYMBOL_DAS_UPCAST = 48,                /* "upcast"  */
  YYSYMBOL_DAS_ITERATOR = 49,              /* "iterator"  */
  YYSYMBOL_DAS_VAR = 50,                   /* "var"  */
  YYSYMBOL_DAS_ADDR = 51,                  /* "addr"  */
  YYSYMBOL_DAS_CONTINUE = 52,              /* "continue"  */
  YYSYMBOL_DAS_WHERE = 53,                 /* "where"  */
  YYSYMBOL_DAS_PASS = 54,                  /* "pass"  */
  YYSYMBOL_DAS_REINTERPRET = 55,           /* "reinterpret"  */
  YYSYMBOL_DAS_MODULE = 56,                /* "module"  */
  YYSYMBOL_DAS_PUBLIC = 57,                /* "public"  */
  YYSYMBOL_DAS_LABEL = 58,                 /* "label"  */
  YYSYMBOL_DAS_GOTO = 59,                  /* "goto"  */
  YYSYMBOL_DAS_IMPLICIT = 60,              /* "implicit"  */
  YYSYMBOL_DAS_EXPLICIT = 61,              /* "explicit"  */
  YYSYMBOL_DAS_SHARED = 62,                /* "shared"  */
  YYSYMBOL_DAS_PRIVATE = 63,               /* "private"  */
  YYSYMBOL_DAS_SMART_PTR = 64,             /* "smart_ptr"  */
  YYSYMBOL_DAS_UNSAFE = 65,                /* "unsafe"  */
  YYSYMBOL_DAS_INSCOPE = 66,               /* "inscope"  */
  YYSYMBOL_DAS_STATIC = 67,                /* "static"  */
  YYSYMBOL_DAS_FIXED_ARRAY = 68,           /* "fixed_array"  */
  YYSYMBOL_DAS_DEFAULT = 69,               /* "default"  */
  YYSYMBOL_DAS_UNINITIALIZED = 70,         /* "uninitialized"  */
  YYSYMBOL_DAS_TBOOL = 71,                 /* "bool"  */
  YYSYMBOL_DAS_TVOID = 72,                 /* "void"  */
  YYSYMBOL_DAS_TSTRING = 73,               /* "string"  */
  YYSYMBOL_DAS_TAUTO = 74,                 /* "auto"  */
  YYSYMBOL_DAS_TINT = 75,                  /* "int"  */
  YYSYMBOL_DAS_TINT2 = 76,                 /* "int2"  */
  YYSYMBOL_DAS_TINT3 = 77,                 /* "int3"  */
  YYSYMBOL_DAS_TINT4 = 78,                 /* "int4"  */
  YYSYMBOL_DAS_TUINT = 79,                 /* "uint"  */
  YYSYMBOL_DAS_TBITFIELD = 80,             /* "bitfield"  */
  YYSYMBOL_DAS_TUINT2 = 81,                /* "uint2"  */
  YYSYMBOL_DAS_TUINT3 = 82,                /* "uint3"  */
  YYSYMBOL_DAS_TUINT4 = 83,                /* "uint4"  */
  YYSYMBOL_DAS_TFLOAT = 84,                /* "float"  */
  YYSYMBOL_DAS_TFLOAT2 = 85,               /* "float2"  */
  YYSYMBOL_DAS_TFLOAT3 = 86,               /* "float3"  */
  YYSYMBOL_DAS_TFLOAT4 = 87,               /* "float4"  */
  YYSYMBOL_DAS_TRANGE = 88,                /* "range"  */
  YYSYMBOL_DAS_TURANGE = 89,               /* "urange"  */
  YYSYMBOL_DAS_TRANGE64 = 90,              /* "range64"  */
  YYSYMBOL_DAS_TURANGE64 = 91,             /* "urange64"  */
  YYSYMBOL_DAS_TBLOCK = 92,                /* "block"  */
  YYSYMBOL_DAS_TINT64 = 93,                /* "int64"  */
  YYSYMBOL_DAS_TUINT64 = 94,               /* "uint64"  */
  YYSYMBOL_DAS_TDOUBLE = 95,               /* "double"  */
  YYSYMBOL_DAS_TFUNCTION = 96,             /* "function"  */
  YYSYMBOL_DAS_TLAMBDA = 97,               /* "lambda"  */
  YYSYMBOL_DAS_TINT8 = 98,                 /* "int8"  */
  YYSYMBOL_DAS_TUINT8 = 99,                /* "uint8"  */
  YYSYMBOL_DAS_TINT16 = 100,               /* "int16"  */
  YYSYMBOL_DAS_TUINT16 = 101,              /* "uint16"  */
  YYSYMBOL_DAS_TTUPLE = 102,               /* "tuple"  */
  YYSYMBOL_DAS_TVARIANT = 103,             /* "variant"  */
  YYSYMBOL_DAS_GENERATOR = 104,            /* "generator"  */
  YYSYMBOL_DAS_YIELD = 105,                /* "yield"  */
  YYSYMBOL_DAS_SEALED = 106,               /* "sealed"  */
  YYSYMBOL_ADDEQU = 107,                   /* "+="  */
  YYSYMBOL_SUBEQU = 108,                   /* "-="  */
  YYSYMBOL_DIVEQU = 109,                   /* "/="  */
  YYSYMBOL_MULEQU = 110,                   /* "*="  */
  YYSYMBOL_MODEQU = 111,                   /* "%="  */
  YYSYMBOL_ANDEQU = 112,                   /* "&="  */
  YYSYMBOL_OREQU = 113,                    /* "|="  */
  YYSYMBOL_XOREQU = 114,                   /* "^="  */
  YYSYMBOL_SHL = 115,                      /* "<<"  */
  YYSYMBOL_SHR = 116,                      /* ">>"  */
  YYSYMBOL_ADDADD = 117,                   /* "++"  */
  YYSYMBOL_SUBSUB = 118,                   /* "--"  */
  YYSYMBOL_LEEQU = 119,                    /* "<="  */
  YYSYMBOL_SHLEQU = 120,                   /* "<<="  */
  YYSYMBOL_SHREQU = 121,                   /* ">>="  */
  YYSYMBOL_GREQU = 122,                    /* ">="  */
  YYSYMBOL_EQUEQU = 123,                   /* "=="  */
  YYSYMBOL_NOTEQU = 124,                   /* "!="  */
  YYSYMBOL_RARROW = 125,                   /* "->"  */
  YYSYMBOL_LARROW = 126,                   /* "<-"  */
  YYSYMBOL_QQ = 127,                       /* "??"  */
  YYSYMBOL_QDOT = 128,                     /* "?."  */
  YYSYMBOL_QBRA = 129,                     /* "?["  */
  YYSYMBOL_LPIPE = 130,                    /* "<|"  */
  YYSYMBOL_RPIPE = 131,                    /* "|>"  */
  YYSYMBOL_CLONEEQU = 132,                 /* ":="  */
  YYSYMBOL_ROTL = 133,                     /* "<<<"  */
  YYSYMBOL_ROTR = 134,                     /* ">>>"  */
  YYSYMBOL_ROTLEQU = 135,                  /* "<<<="  */
  YYSYMBOL_ROTREQU = 136,                  /* ">>>="  */
  YYSYMBOL_MAPTO = 137,                    /* "=>"  */
  YYSYMBOL_COLCOL = 138,                   /* "::"  */
  YYSYMBOL_ANDAND = 139,                   /* "&&"  */
  YYSYMBOL_OROR = 140,                     /* "||"  */
  YYSYMBOL_XORXOR = 141,                   /* "^^"  */
  YYSYMBOL_ANDANDEQU = 142,                /* "&&="  */
  YYSYMBOL_OROREQU = 143,                  /* "||="  */
  YYSYMBOL_XORXOREQU = 144,                /* "^^="  */
  YYSYMBOL_DOTDOT = 145,                   /* ".."  */
  YYSYMBOL_MTAG_E = 146,                   /* "$$"  */
  YYSYMBOL_MTAG_I = 147,                   /* "$i"  */
  YYSYMBOL_MTAG_V = 148,                   /* "$v"  */
  YYSYMBOL_MTAG_B = 149,                   /* "$b"  */
  YYSYMBOL_MTAG_A = 150,                   /* "$a"  */
  YYSYMBOL_MTAG_T = 151,                   /* "$t"  */
  YYSYMBOL_MTAG_C = 152,                   /* "$c"  */
  YYSYMBOL_MTAG_F = 153,                   /* "$f"  */
  YYSYMBOL_MTAG_DOTDOTDOT = 154,           /* "..."  */
  YYSYMBOL_INTEGER = 155,                  /* "integer constant"  */
  YYSYMBOL_LONG_INTEGER = 156,             /* "long integer constant"  */
  YYSYMBOL_UNSIGNED_INTEGER = 157,         /* "unsigned integer constant"  */
  YYSYMBOL_UNSIGNED_LONG_INTEGER = 158,    /* "unsigned long integer constant"  */
  YYSYMBOL_UNSIGNED_INT8 = 159,            /* "unsigned int8 constant"  */
  YYSYMBOL_FLOAT = 160,                    /* "floating point constant"  */
  YYSYMBOL_DOUBLE = 161,                   /* "double constant"  */
  YYSYMBOL_NAME = 162,                     /* "name"  */
  YYSYMBOL_DAS_EMIT_COMMA = 163,           /* "emitted ,"  */
  YYSYMBOL_DAS_EMIT_SEMICOLON = 164,       /* "emitted ;"  */
  YYSYMBOL_BEGIN_STRING = 165,             /* "start of the string"  */
  YYSYMBOL_STRING_CHARACTER = 166,         /* STRING_CHARACTER  */
  YYSYMBOL_STRING_CHARACTER_ESC = 167,     /* STRING_CHARACTER_ESC  */
  YYSYMBOL_END_STRING = 168,               /* "end of the string"  */
  YYSYMBOL_BEGIN_STRING_EXPR = 169,        /* "{"  */
  YYSYMBOL_END_STRING_EXPR = 170,          /* "}"  */
  YYSYMBOL_END_OF_READ = 171,              /* "end of failed eader macro"  */
  YYSYMBOL_172_ = 172,                     /* ','  */
  YYSYMBOL_173_ = 173,                     /* '='  */
  YYSYMBOL_174_ = 174,                     /* '?'  */
  YYSYMBOL_175_ = 175,                     /* ':'  */
  YYSYMBOL_176_ = 176,                     /* '|'  */
  YYSYMBOL_177_ = 177,                     /* '^'  */
  YYSYMBOL_178_ = 178,                     /* '&'  */
  YYSYMBOL_179_ = 179,                     /* '<'  */
  YYSYMBOL_180_ = 180,                     /* '>'  */
  YYSYMBOL_181_ = 181,                     /* '-'  */
  YYSYMBOL_182_ = 182,                     /* '+'  */
  YYSYMBOL_183_ = 183,                     /* '*'  */
  YYSYMBOL_184_ = 184,                     /* '/'  */
  YYSYMBOL_185_ = 185,                     /* '%'  */
  YYSYMBOL_UNARY_MINUS = 186,              /* UNARY_MINUS  */
  YYSYMBOL_UNARY_PLUS = 187,               /* UNARY_PLUS  */
  YYSYMBOL_188_ = 188,                     /* '~'  */
  YYSYMBOL_189_ = 189,                     /* '!'  */
  YYSYMBOL_PRE_INC = 190,                  /* PRE_INC  */
  YYSYMBOL_PRE_DEC = 191,                  /* PRE_DEC  */
  YYSYMBOL_LLPIPE = 192,                   /* LLPIPE  */
  YYSYMBOL_POST_INC = 193,                 /* POST_INC  */
  YYSYMBOL_POST_DEC = 194,                 /* POST_DEC  */
  YYSYMBOL_DEREF = 195,                    /* DEREF  */
  YYSYMBOL_196_ = 196,                     /* '.'  */
  YYSYMBOL_197_ = 197,                     /* '['  */
  YYSYMBOL_198_ = 198,                     /* ']'  */
  YYSYMBOL_199_ = 199,                     /* '('  */
  YYSYMBOL_200_ = 200,                     /* ')'  */
  YYSYMBOL_201_ = 201,                     /* '$'  */
  YYSYMBOL_202_ = 202,                     /* '@'  */
  YYSYMBOL_203_ = 203,                     /* ';'  */
  YYSYMBOL_204_ = 204,                     /* '{'  */
  YYSYMBOL_205_ = 205,                     /* '}'  */
  YYSYMBOL_206_ = 206,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 207,                 /* $accept  */
  YYSYMBOL_program = 208,                  /* program  */
  YYSYMBOL_COMMA = 209,                    /* COMMA  */
  YYSYMBOL_SEMICOLON = 210,                /* SEMICOLON  */
  YYSYMBOL_top_level_reader_macro = 211,   /* top_level_reader_macro  */
  YYSYMBOL_optional_public_or_private_module = 212, /* optional_public_or_private_module  */
  YYSYMBOL_module_name = 213,              /* module_name  */
  YYSYMBOL_module_declaration = 214,       /* module_declaration  */
  YYSYMBOL_character_sequence = 215,       /* character_sequence  */
  YYSYMBOL_string_constant = 216,          /* string_constant  */
  YYSYMBOL_string_builder_body = 217,      /* string_builder_body  */
  YYSYMBOL_string_builder = 218,           /* string_builder  */
  YYSYMBOL_reader_character_sequence = 219, /* reader_character_sequence  */
  YYSYMBOL_expr_reader = 220,              /* expr_reader  */
  YYSYMBOL_221_1 = 221,                    /* $@1  */
  YYSYMBOL_options_declaration = 222,      /* options_declaration  */
  YYSYMBOL_require_declaration = 223,      /* require_declaration  */
  YYSYMBOL_require_module_name = 224,      /* require_module_name  */
  YYSYMBOL_require_module = 225,           /* require_module  */
  YYSYMBOL_is_public_module = 226,         /* is_public_module  */
  YYSYMBOL_expect_declaration = 227,       /* expect_declaration  */
  YYSYMBOL_expect_list = 228,              /* expect_list  */
  YYSYMBOL_expect_error = 229,             /* expect_error  */
  YYSYMBOL_expression_label = 230,         /* expression_label  */
  YYSYMBOL_expression_goto = 231,          /* expression_goto  */
  YYSYMBOL_elif_or_static_elif = 232,      /* elif_or_static_elif  */
  YYSYMBOL_emit_semis = 233,               /* emit_semis  */
  YYSYMBOL_optional_emit_semis = 234,      /* optional_emit_semis  */
  YYSYMBOL_expression_else = 235,          /* expression_else  */
  YYSYMBOL_if_or_static_if = 236,          /* if_or_static_if  */
  YYSYMBOL_expression_else_one_liner = 237, /* expression_else_one_liner  */
  YYSYMBOL_expression_if_one_liner = 238,  /* expression_if_one_liner  */
  YYSYMBOL_semis = 239,                    /* semis  */
  YYSYMBOL_optional_semis = 240,           /* optional_semis  */
  YYSYMBOL_expression_if_then_else = 241,  /* expression_if_then_else  */
  YYSYMBOL_242_2 = 242,                    /* $@2  */
  YYSYMBOL_expression_if_then_else_oneliner = 243, /* expression_if_then_else_oneliner  */
  YYSYMBOL_expression_for_loop = 244,      /* expression_for_loop  */
  YYSYMBOL_245_3 = 245,                    /* $@3  */
  YYSYMBOL_expression_unsafe = 246,        /* expression_unsafe  */
  YYSYMBOL_expression_while_loop = 247,    /* expression_while_loop  */
  YYSYMBOL_248_4 = 248,                    /* $@4  */
  YYSYMBOL_expression_with = 249,          /* expression_with  */
  YYSYMBOL_250_5 = 250,                    /* $@5  */
  YYSYMBOL_expression_with_alias = 251,    /* expression_with_alias  */
  YYSYMBOL_annotation_argument_value = 252, /* annotation_argument_value  */
  YYSYMBOL_annotation_argument_value_list = 253, /* annotation_argument_value_list  */
  YYSYMBOL_annotation_argument_name = 254, /* annotation_argument_name  */
  YYSYMBOL_annotation_argument = 255,      /* annotation_argument  */
  YYSYMBOL_annotation_argument_list = 256, /* annotation_argument_list  */
  YYSYMBOL_metadata_argument_list = 257,   /* metadata_argument_list  */
  YYSYMBOL_annotation_declaration_name = 258, /* annotation_declaration_name  */
  YYSYMBOL_annotation_declaration_basic = 259, /* annotation_declaration_basic  */
  YYSYMBOL_annotation_declaration = 260,   /* annotation_declaration  */
  YYSYMBOL_annotation_list = 261,          /* annotation_list  */
  YYSYMBOL_optional_annotation_list = 262, /* optional_annotation_list  */
  YYSYMBOL_optional_annotation_list_with_emit_semis = 263, /* optional_annotation_list_with_emit_semis  */
  YYSYMBOL_optional_function_argument_list = 264, /* optional_function_argument_list  */
  YYSYMBOL_optional_function_type = 265,   /* optional_function_type  */
  YYSYMBOL_function_name = 266,            /* function_name  */
  YYSYMBOL_global_function_declaration = 267, /* global_function_declaration  */
  YYSYMBOL_optional_public_or_private_function = 268, /* optional_public_or_private_function  */
  YYSYMBOL_function_declaration_header = 269, /* function_declaration_header  */
  YYSYMBOL_function_declaration = 270,     /* function_declaration  */
  YYSYMBOL_271_6 = 271,                    /* $@6  */
  YYSYMBOL_expression_block_finally = 272, /* expression_block_finally  */
  YYSYMBOL_273_7 = 273,                    /* $@7  */
  YYSYMBOL_274_8 = 274,                    /* $@8  */
  YYSYMBOL_expression_block = 275,         /* expression_block  */
  YYSYMBOL_276_9 = 276,                    /* $@9  */
  YYSYMBOL_277_10 = 277,                   /* $@10  */
  YYSYMBOL_expr_call_pipe = 278,           /* expr_call_pipe  */
  YYSYMBOL_expression_any = 279,           /* expression_any  */
  YYSYMBOL_expressions = 280,              /* expressions  */
  YYSYMBOL_optional_expr_list = 281,       /* optional_expr_list  */
  YYSYMBOL_optional_expr_map_tuple_list = 282, /* optional_expr_map_tuple_list  */
  YYSYMBOL_type_declaration_no_options_list = 283, /* type_declaration_no_options_list  */
  YYSYMBOL_name_in_namespace = 284,        /* name_in_namespace  */
  YYSYMBOL_expression_delete = 285,        /* expression_delete  */
  YYSYMBOL_new_type_declaration = 286,     /* new_type_declaration  */
  YYSYMBOL_287_11 = 287,                   /* $@11  */
  YYSYMBOL_288_12 = 288,                   /* $@12  */
  YYSYMBOL_expr_new = 289,                 /* expr_new  */
  YYSYMBOL_expression_break = 290,         /* expression_break  */
  YYSYMBOL_expression_continue = 291,      /* expression_continue  */
  YYSYMBOL_expression_return = 292,        /* expression_return  */
  YYSYMBOL_expression_yield = 293,         /* expression_yield  */
  YYSYMBOL_expression_try_catch = 294,     /* expression_try_catch  */
  YYSYMBOL_kwd_let_var_or_nothing = 295,   /* kwd_let_var_or_nothing  */
  YYSYMBOL_kwd_let = 296,                  /* kwd_let  */
  YYSYMBOL_optional_in_scope = 297,        /* optional_in_scope  */
  YYSYMBOL_tuple_expansion = 298,          /* tuple_expansion  */
  YYSYMBOL_tuple_expansion_variable_declaration = 299, /* tuple_expansion_variable_declaration  */
  YYSYMBOL_expression_let = 300,           /* expression_let  */
  YYSYMBOL_expr_cast = 301,                /* expr_cast  */
  YYSYMBOL_302_13 = 302,                   /* $@13  */
  YYSYMBOL_303_14 = 303,                   /* $@14  */
  YYSYMBOL_304_15 = 304,                   /* $@15  */
  YYSYMBOL_305_16 = 305,                   /* $@16  */
  YYSYMBOL_306_17 = 306,                   /* $@17  */
  YYSYMBOL_307_18 = 307,                   /* $@18  */
  YYSYMBOL_expr_type_decl = 308,           /* expr_type_decl  */
  YYSYMBOL_309_19 = 309,                   /* $@19  */
  YYSYMBOL_310_20 = 310,                   /* $@20  */
  YYSYMBOL_expr_type_info = 311,           /* expr_type_info  */
  YYSYMBOL_expr_list = 312,                /* expr_list  */
  YYSYMBOL_block_or_simple_block = 313,    /* block_or_simple_block  */
  YYSYMBOL_block_or_lambda = 314,          /* block_or_lambda  */
  YYSYMBOL_capture_entry = 315,            /* capture_entry  */
  YYSYMBOL_capture_list = 316,             /* capture_list  */
  YYSYMBOL_optional_capture_list = 317,    /* optional_capture_list  */
  YYSYMBOL_expr_full_block = 318,          /* expr_full_block  */
  YYSYMBOL_expr_full_block_assumed_piped = 319, /* expr_full_block_assumed_piped  */
  YYSYMBOL_expr_numeric_const = 320,       /* expr_numeric_const  */
  YYSYMBOL_expr_assign = 321,              /* expr_assign  */
  YYSYMBOL_expr_named_call = 322,          /* expr_named_call  */
  YYSYMBOL_expr_method_call = 323,         /* expr_method_call  */
  YYSYMBOL_func_addr_name = 324,           /* func_addr_name  */
  YYSYMBOL_func_addr_expr = 325,           /* func_addr_expr  */
  YYSYMBOL_326_21 = 326,                   /* $@21  */
  YYSYMBOL_327_22 = 327,                   /* $@22  */
  YYSYMBOL_328_23 = 328,                   /* $@23  */
  YYSYMBOL_329_24 = 329,                   /* $@24  */
  YYSYMBOL_expr_field = 330,               /* expr_field  */
  YYSYMBOL_331_25 = 331,                   /* $@25  */
  YYSYMBOL_332_26 = 332,                   /* $@26  */
  YYSYMBOL_expr_call = 333,                /* expr_call  */
  YYSYMBOL_expr = 334,                     /* expr  */
  YYSYMBOL_335_27 = 335,                   /* $@27  */
  YYSYMBOL_336_28 = 336,                   /* $@28  */
  YYSYMBOL_337_29 = 337,                   /* $@29  */
  YYSYMBOL_338_30 = 338,                   /* $@30  */
  YYSYMBOL_339_31 = 339,                   /* $@31  */
  YYSYMBOL_340_32 = 340,                   /* $@32  */
  YYSYMBOL_expr_generator = 341,           /* expr_generator  */
  YYSYMBOL_expr_mtag = 342,                /* expr_mtag  */
  YYSYMBOL_optional_field_annotation = 343, /* optional_field_annotation  */
  YYSYMBOL_optional_override = 344,        /* optional_override  */
  YYSYMBOL_optional_constant = 345,        /* optional_constant  */
  YYSYMBOL_optional_public_or_private_member_variable = 346, /* optional_public_or_private_member_variable  */
  YYSYMBOL_optional_static_member_variable = 347, /* optional_static_member_variable  */
  YYSYMBOL_structure_variable_declaration = 348, /* structure_variable_declaration  */
  YYSYMBOL_struct_variable_declaration_list = 349, /* struct_variable_declaration_list  */
  YYSYMBOL_350_33 = 350,                   /* $@33  */
  YYSYMBOL_351_34 = 351,                   /* $@34  */
  YYSYMBOL_352_35 = 352,                   /* $@35  */
  YYSYMBOL_function_argument_declaration = 353, /* function_argument_declaration  */
  YYSYMBOL_function_argument_list = 354,   /* function_argument_list  */
  YYSYMBOL_tuple_type = 355,               /* tuple_type  */
  YYSYMBOL_tuple_type_list = 356,          /* tuple_type_list  */
  YYSYMBOL_tuple_alias_type_list = 357,    /* tuple_alias_type_list  */
  YYSYMBOL_variant_type = 358,             /* variant_type  */
  YYSYMBOL_variant_type_list = 359,        /* variant_type_list  */
  YYSYMBOL_variant_alias_type_list = 360,  /* variant_alias_type_list  */
  YYSYMBOL_copy_or_move = 361,             /* copy_or_move  */
  YYSYMBOL_variable_declaration = 362,     /* variable_declaration  */
  YYSYMBOL_copy_or_move_or_clone = 363,    /* copy_or_move_or_clone  */
  YYSYMBOL_optional_ref = 364,             /* optional_ref  */
  YYSYMBOL_let_variable_name_with_pos_list = 365, /* let_variable_name_with_pos_list  */
  YYSYMBOL_global_let_variable_name_with_pos_list = 366, /* global_let_variable_name_with_pos_list  */
  YYSYMBOL_variable_declaration_list = 367, /* variable_declaration_list  */
  YYSYMBOL_let_variable_declaration = 368, /* let_variable_declaration  */
  YYSYMBOL_global_let_variable_declaration = 369, /* global_let_variable_declaration  */
  YYSYMBOL_optional_shared = 370,          /* optional_shared  */
  YYSYMBOL_optional_public_or_private_variable = 371, /* optional_public_or_private_variable  */
  YYSYMBOL_global_variable_declaration_list = 372, /* global_variable_declaration_list  */
  YYSYMBOL_373_36 = 373,                   /* $@36  */
  YYSYMBOL_global_let = 374,               /* global_let  */
  YYSYMBOL_375_37 = 375,                   /* $@37  */
  YYSYMBOL_enum_expression = 376,          /* enum_expression  */
  YYSYMBOL_commas = 377,                   /* commas  */
  YYSYMBOL_enum_list = 378,                /* enum_list  */
  YYSYMBOL_optional_public_or_private_alias = 379, /* optional_public_or_private_alias  */
  YYSYMBOL_single_alias = 380,             /* single_alias  */
  YYSYMBOL_381_38 = 381,                   /* $@38  */
  YYSYMBOL_alias_declaration = 382,        /* alias_declaration  */
  YYSYMBOL_optional_public_or_private_enum = 383, /* optional_public_or_private_enum  */
  YYSYMBOL_enum_name = 384,                /* enum_name  */
  YYSYMBOL_optional_enum_basic_type_declaration = 385, /* optional_enum_basic_type_declaration  */
  YYSYMBOL_optional_commas = 386,          /* optional_commas  */
  YYSYMBOL_emit_commas = 387,              /* emit_commas  */
  YYSYMBOL_optional_emit_commas = 388,     /* optional_emit_commas  */
  YYSYMBOL_enum_declaration = 389,         /* enum_declaration  */
  YYSYMBOL_390_39 = 390,                   /* $@39  */
  YYSYMBOL_391_40 = 391,                   /* $@40  */
  YYSYMBOL_392_41 = 392,                   /* $@41  */
  YYSYMBOL_optional_structure_parent = 393, /* optional_structure_parent  */
  YYSYMBOL_optional_sealed = 394,          /* optional_sealed  */
  YYSYMBOL_structure_name = 395,           /* structure_name  */
  YYSYMBOL_class_or_struct = 396,          /* class_or_struct  */
  YYSYMBOL_optional_public_or_private_structure = 397, /* optional_public_or_private_structure  */
  YYSYMBOL_optional_struct_variable_declaration_list = 398, /* optional_struct_variable_declaration_list  */
  YYSYMBOL_structure_declaration = 399,    /* structure_declaration  */
  YYSYMBOL_400_42 = 400,                   /* $@42  */
  YYSYMBOL_401_43 = 401,                   /* $@43  */
  YYSYMBOL_402_44 = 402,                   /* $@44  */
  YYSYMBOL_variable_name_with_pos_list = 403, /* variable_name_with_pos_list  */
  YYSYMBOL_basic_type_declaration = 404,   /* basic_type_declaration  */
  YYSYMBOL_enum_basic_type_declaration = 405, /* enum_basic_type_declaration  */
  YYSYMBOL_structure_type_declaration = 406, /* structure_type_declaration  */
  YYSYMBOL_auto_type_declaration = 407,    /* auto_type_declaration  */
  YYSYMBOL_bitfield_bits = 408,            /* bitfield_bits  */
  YYSYMBOL_bitfield_alias_bits = 409,      /* bitfield_alias_bits  */
  YYSYMBOL_bitfield_type_declaration = 410, /* bitfield_type_declaration  */
  YYSYMBOL_411_45 = 411,                   /* $@45  */
  YYSYMBOL_412_46 = 412,                   /* $@46  */
  YYSYMBOL_c_or_s = 413,                   /* c_or_s  */
  YYSYMBOL_table_type_pair = 414,          /* table_type_pair  */
  YYSYMBOL_dim_list = 415,                 /* dim_list  */
  YYSYMBOL_type_declaration_no_options = 416, /* type_declaration_no_options  */
  YYSYMBOL_type_declaration_no_options_no_dim = 417, /* type_declaration_no_options_no_dim  */
  YYSYMBOL_418_47 = 418,                   /* $@47  */
  YYSYMBOL_419_48 = 419,                   /* $@48  */
  YYSYMBOL_420_49 = 420,                   /* $@49  */
  YYSYMBOL_421_50 = 421,                   /* $@50  */
  YYSYMBOL_422_51 = 422,                   /* $@51  */
  YYSYMBOL_423_52 = 423,                   /* $@52  */
  YYSYMBOL_424_53 = 424,                   /* $@53  */
  YYSYMBOL_425_54 = 425,                   /* $@54  */
  YYSYMBOL_426_55 = 426,                   /* $@55  */
  YYSYMBOL_427_56 = 427,                   /* $@56  */
  YYSYMBOL_428_57 = 428,                   /* $@57  */
  YYSYMBOL_429_58 = 429,                   /* $@58  */
  YYSYMBOL_430_59 = 430,                   /* $@59  */
  YYSYMBOL_431_60 = 431,                   /* $@60  */
  YYSYMBOL_432_61 = 432,                   /* $@61  */
  YYSYMBOL_433_62 = 433,                   /* $@62  */
  YYSYMBOL_434_63 = 434,                   /* $@63  */
  YYSYMBOL_435_64 = 435,                   /* $@64  */
  YYSYMBOL_436_65 = 436,                   /* $@65  */
  YYSYMBOL_437_66 = 437,                   /* $@66  */
  YYSYMBOL_438_67 = 438,                   /* $@67  */
  YYSYMBOL_439_68 = 439,                   /* $@68  */
  YYSYMBOL_440_69 = 440,                   /* $@69  */
  YYSYMBOL_441_70 = 441,                   /* $@70  */
  YYSYMBOL_442_71 = 442,                   /* $@71  */
  YYSYMBOL_443_72 = 443,                   /* $@72  */
  YYSYMBOL_444_73 = 444,                   /* $@73  */
  YYSYMBOL_type_declaration = 445,         /* type_declaration  */
  YYSYMBOL_tuple_alias_declaration = 446,  /* tuple_alias_declaration  */
  YYSYMBOL_447_74 = 447,                   /* $@74  */
  YYSYMBOL_448_75 = 448,                   /* $@75  */
  YYSYMBOL_449_76 = 449,                   /* $@76  */
  YYSYMBOL_450_77 = 450,                   /* $@77  */
  YYSYMBOL_variant_alias_declaration = 451, /* variant_alias_declaration  */
  YYSYMBOL_452_78 = 452,                   /* $@78  */
  YYSYMBOL_453_79 = 453,                   /* $@79  */
  YYSYMBOL_454_80 = 454,                   /* $@80  */
  YYSYMBOL_455_81 = 455,                   /* $@81  */
  YYSYMBOL_bitfield_alias_declaration = 456, /* bitfield_alias_declaration  */
  YYSYMBOL_457_82 = 457,                   /* $@82  */
  YYSYMBOL_458_83 = 458,                   /* $@83  */
  YYSYMBOL_459_84 = 459,                   /* $@84  */
  YYSYMBOL_460_85 = 460,                   /* $@85  */
  YYSYMBOL_make_decl = 461,                /* make_decl  */
  YYSYMBOL_make_struct_fields = 462,       /* make_struct_fields  */
  YYSYMBOL_make_variant_dim = 463,         /* make_variant_dim  */
  YYSYMBOL_make_struct_single = 464,       /* make_struct_single  */
  YYSYMBOL_make_struct_dim_list = 465,     /* make_struct_dim_list  */
  YYSYMBOL_make_struct_dim_decl = 466,     /* make_struct_dim_decl  */
  YYSYMBOL_optional_make_struct_dim_decl = 467, /* optional_make_struct_dim_decl  */
  YYSYMBOL_use_initializer = 468,          /* use_initializer  */
  YYSYMBOL_make_struct_decl = 469,         /* make_struct_decl  */
  YYSYMBOL_470_86 = 470,                   /* $@86  */
  YYSYMBOL_471_87 = 471,                   /* $@87  */
  YYSYMBOL_472_88 = 472,                   /* $@88  */
  YYSYMBOL_473_89 = 473,                   /* $@89  */
  YYSYMBOL_474_90 = 474,                   /* $@90  */
  YYSYMBOL_475_91 = 475,                   /* $@91  */
  YYSYMBOL_476_92 = 476,                   /* $@92  */
  YYSYMBOL_477_93 = 477,                   /* $@93  */
  YYSYMBOL_make_map_tuple = 478,           /* make_map_tuple  */
  YYSYMBOL_make_tuple_call = 479,          /* make_tuple_call  */
  YYSYMBOL_480_94 = 480,                   /* $@94  */
  YYSYMBOL_481_95 = 481,                   /* $@95  */
  YYSYMBOL_make_dim_decl = 482,            /* make_dim_decl  */
  YYSYMBOL_483_96 = 483,                   /* $@96  */
  YYSYMBOL_484_97 = 484,                   /* $@97  */
  YYSYMBOL_485_98 = 485,                   /* $@98  */
  YYSYMBOL_486_99 = 486,                   /* $@99  */
  YYSYMBOL_487_100 = 487,                  /* $@100  */
  YYSYMBOL_488_101 = 488,                  /* $@101  */
  YYSYMBOL_489_102 = 489,                  /* $@102  */
  YYSYMBOL_490_103 = 490,                  /* $@103  */
  YYSYMBOL_491_104 = 491,                  /* $@104  */
  YYSYMBOL_492_105 = 492,                  /* $@105  */
  YYSYMBOL_expr_map_tuple_list = 493,      /* expr_map_tuple_list  */
  YYSYMBOL_make_table_decl = 494,          /* make_table_decl  */
  YYSYMBOL_array_comprehension_where = 495, /* array_comprehension_where  */
  YYSYMBOL_optional_comma = 496,           /* optional_comma  */
  YYSYMBOL_array_comprehension = 497       /* array_comprehension  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined DAS2_YYLTYPE_IS_TRIVIAL && DAS2_YYLTYPE_IS_TRIVIAL \
             && defined DAS2_YYSTYPE_IS_TRIVIAL && DAS2_YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  832
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1518

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   434


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   189,     2,   206,   201,   185,   178,     2,
     199,   200,   183,   182,   172,   181,   196,   184,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   175,   203,
     179,   173,   180,   174,   202,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   197,     2,   198,   177,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   204,   176,   205,   188,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   186,   187,   190,
     191,   192,   193,   194,   195
};

#if DAS2_YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   535,   535,   536,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   557,   558,   562,
     563,   567,   573,   574,   575,   579,   580,   584,   602,   603,
     604,   605,   609,   610,   614,   619,   628,   636,   652,   657,
     665,   665,   704,   722,   726,   729,   733,   739,   748,   751,
     757,   758,   762,   766,   767,   771,   774,   780,   786,   789,
     795,   796,   800,   801,   805,   806,   810,   811,   812,   821,
     822,   826,   827,   833,   834,   835,   836,   837,   841,   842,
     846,   847,   851,   851,   863,   870,   870,   879,   887,   887,
     900,   900,   912,   919,   920,   921,   922,   923,   924,   928,
     933,   941,   942,   943,   947,   948,   949,   950,   951,   952,
     953,   954,   960,   963,   969,   972,   978,   979,   980,   984,
     997,  1015,  1018,  1026,  1037,  1048,  1059,  1062,  1069,  1073,
    1080,  1081,  1085,  1086,  1090,  1091,  1092,  1096,  1099,  1106,
    1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,  1193,  1198,  1216,  1217,  1218,  1222,  1228,
    1228,  1245,  1248,  1250,  1248,  1258,  1260,  1258,  1275,  1288,
    1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,
    1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1310,  1315,
    1321,  1327,  1328,  1332,  1333,  1337,  1341,  1348,  1349,  1360,
    1364,  1367,  1375,  1375,  1375,  1378,  1384,  1387,  1391,  1395,
    1402,  1409,  1415,  1419,  1423,  1426,  1429,  1437,  1440,  1448,
    1454,  1455,  1456,  1460,  1461,  1465,  1466,  1470,  1475,  1483,
    1489,  1501,  1504,  1507,  1513,  1513,  1513,  1516,  1516,  1516,
    1521,  1521,  1521,  1529,  1529,  1529,  1535,  1545,  1556,  1571,
    1574,  1580,  1581,  1588,  1599,  1600,  1601,  1605,  1606,  1607,
    1608,  1609,  1613,  1618,  1626,  1627,  1631,  1638,  1642,  1648,
    1649,  1650,  1651,  1652,  1653,  1654,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,
    1672,  1673,  1674,  1675,  1676,  1680,  1687,  1699,  1704,  1714,
    1718,  1725,  1728,  1728,  1728,  1733,  1733,  1733,  1746,  1750,
    1754,  1759,  1766,  1771,  1778,  1778,  1778,  1785,  1789,  1799,
    1808,  1817,  1821,  1824,  1830,  1831,  1832,  1833,  1834,  1835,
    1836,  1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,
    1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,
    1871,  1872,  1873,  1874,  1875,  1888,  1889,  1890,  1891,  1892,
    1893,  1894,  1895,  1896,  1897,  1898,  1899,  1900,  1901,  1904,
    1904,  1904,  1907,  1912,  1916,  1920,  1920,  1920,  1925,  1928,
    1932,  1932,  1932,  1937,  1940,  1941,  1942,  1943,  1944,  1945,
    1946,  1947,  1948,  1950,  1954,  1955,  1963,  1966,  1969,  1978,
    1979,  1980,  1981,  1982,  1983,  1984,  1988,  1992,  1996,  2000,
    2004,  2008,  2012,  2016,  2020,  2027,  2028,  2032,  2033,  2034,
    2038,  2039,  2043,  2044,  2045,  2049,  2050,  2054,  2065,  2068,
    2069,  2069,  2088,  2087,  2101,  2100,  2116,  2125,  2135,  2136,
    2140,  2143,  2152,  2153,  2157,  2160,  2164,  2178,  2187,  2188,
    2192,  2195,  2199,  2213,  2214,  2218,  2224,  2230,  2233,  2237,
    2246,  2247,  2248,  2252,  2253,  2257,  2264,  2269,  2278,  2284,
    2295,  2302,  2311,  2314,  2317,  2324,  2327,  2332,  2343,  2346,
    2351,  2363,  2364,  2368,  2369,  2370,  2374,  2377,  2380,  2380,
    2400,  2403,  2403,  2421,  2426,  2434,  2435,  2439,  2442,  2455,
    2472,  2473,  2474,  2479,  2479,  2505,  2509,  2510,  2511,  2515,
    2525,  2528,  2534,  2535,  2539,  2540,  2544,  2545,  2549,  2551,
    2556,  2549,  2572,  2573,  2577,  2578,  2582,  2588,  2589,  2593,
    2594,  2595,  2599,  2602,  2608,  2610,  2615,  2608,  2630,  2637,
    2642,  2651,  2657,  2668,  2669,  2670,  2671,  2672,  2673,  2674,
    2675,  2676,  2677,  2678,  2679,  2680,  2681,  2682,  2683,  2684,
    2685,  2686,  2687,  2688,  2689,  2690,  2691,  2692,  2693,  2694,
    2698,  2699,  2700,  2701,  2702,  2703,  2704,  2705,  2709,  2720,
    2724,  2731,  2743,  2750,  2759,  2764,  2774,  2787,  2787,  2787,
    2800,  2801,  2805,  2809,  2816,  2820,  2824,  2828,  2835,  2838,
    2856,  2857,  2858,  2859,  2860,  2860,  2860,  2864,  2869,  2876,
    2876,  2883,  2887,  2891,  2896,  2901,  2906,  2911,  2915,  2919,
    2924,  2928,  2932,  2937,  2937,  2937,  2943,  2950,  2950,  2950,
    2955,  2955,  2955,  2961,  2961,  2961,  2966,  2970,  2970,  2970,
    2975,  2975,  2975,  2984,  2988,  2988,  2988,  2993,  2993,  2993,
    3002,  3006,  3006,  3006,  3011,  3011,  3011,  3020,  3020,  3020,
    3026,  3026,  3026,  3035,  3038,  3049,  3065,  3067,  3072,  3077,
    3065,  3103,  3105,  3110,  3116,  3103,  3142,  3144,  3149,  3154,
    3142,  3185,  3186,  3187,  3188,  3189,  3193,  3200,  3207,  3213,
    3219,  3226,  3233,  3239,  3248,  3254,  3262,  3267,  3274,  3279,
    3285,  3286,  3290,  3291,  3295,  3295,  3295,  3303,  3303,  3303,
    3310,  3310,  3310,  3317,  3317,  3317,  3328,  3334,  3340,  3346,
    3346,  3346,  3356,  3365,  3365,  3365,  3375,  3375,  3375,  3385,
    3385,  3385,  3395,  3404,  3404,  3404,  3424,  3431,  3431,  3431,
    3441,  3444,  3450,  3458,  3466,  3486,  3511,  3512,  3516,  3517,
    3521,  3524,  3527
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"lexer error\"",
  "\"capture\"", "\"struct\"", "\"class\"", "\"let\"", "\"def\"",
  "\"while\"", "\"if\"", "\"static_if\"", "\"else\"", "\"for\"",
  "\"recover\"", "\"true\"", "\"false\"", "\"new\"", "\"typeinfo\"",
  "\"type\"", "\"in\"", "\"is\"", "\"as\"", "\"elif\"", "\"static_elif\"",
  "\"array\"", "\"return\"", "\"null\"", "\"break\"", "\"try\"",
  "\"options\"", "\"table\"", "\"expect\"", "\"const\"", "\"require\"",
  "\"operator\"", "\"enum\"", "\"finally\"", "\"delete\"", "\"deref\"",
  "\"typedef\"", "\"typedecl\"", "\"with\"", "\"aka\"", "\"assume\"",
  "\"cast\"", "\"override\"", "\"abstract\"", "\"upcast\"", "\"iterator\"",
  "\"var\"", "\"addr\"", "\"continue\"", "\"where\"", "\"pass\"",
  "\"reinterpret\"", "\"module\"", "\"public\"", "\"label\"", "\"goto\"",
  "\"implicit\"", "\"explicit\"", "\"shared\"", "\"private\"",
  "\"smart_ptr\"", "\"unsafe\"", "\"inscope\"", "\"static\"",
  "\"fixed_array\"", "\"default\"", "\"uninitialized\"", "\"bool\"",
  "\"void\"", "\"string\"", "\"auto\"", "\"int\"", "\"int2\"", "\"int3\"",
  "\"int4\"", "\"uint\"", "\"bitfield\"", "\"uint2\"", "\"uint3\"",
  "\"uint4\"", "\"float\"", "\"float2\"", "\"float3\"", "\"float4\"",
  "\"range\"", "\"urange\"", "\"range64\"", "\"urange64\"", "\"block\"",
  "\"int64\"", "\"uint64\"", "\"double\"", "\"function\"", "\"lambda\"",
  "\"int8\"", "\"uint8\"", "\"int16\"", "\"uint16\"", "\"tuple\"",
  "\"variant\"", "\"generator\"", "\"yield\"", "\"sealed\"", "\"+=\"",
  "\"-=\"", "\"/=\"", "\"*=\"", "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"",
  "\"<<\"", "\">>\"", "\"++\"", "\"--\"", "\"<=\"", "\"<<=\"", "\">>=\"",
  "\">=\"", "\"==\"", "\"!=\"", "\"->\"", "\"<-\"", "\"??\"", "\"?.\"",
  "\"?[\"", "\"<|\"", "\"|>\"", "\":=\"", "\"<<<\"", "\">>>\"", "\"<<<=\"",
  "\">>>=\"", "\"=>\"", "\"::\"", "\"&&\"", "\"||\"", "\"^^\"", "\"&&=\"",
  "\"||=\"", "\"^^=\"", "\"..\"", "\"$$\"", "\"$i\"", "\"$v\"", "\"$b\"",
  "\"$a\"", "\"$t\"", "\"$c\"", "\"$f\"", "\"...\"",
  "\"integer constant\"", "\"long integer constant\"",
  "\"unsigned integer constant\"", "\"unsigned long integer constant\"",
  "\"unsigned int8 constant\"", "\"floating point constant\"",
  "\"double constant\"", "\"name\"", "\"emitted ,\"", "\"emitted ;\"",
  "\"start of the string\"", "STRING_CHARACTER", "STRING_CHARACTER_ESC",
  "\"end of the string\"", "\"{\"", "\"}\"",
  "\"end of failed eader macro\"", "','", "'='", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'", "'%'",
  "UNARY_MINUS", "UNARY_PLUS", "'~'", "'!'", "PRE_INC", "PRE_DEC",
  "LLPIPE", "POST_INC", "POST_DEC", "DEREF", "'.'", "'['", "']'", "'('",
  "')'", "'$'", "'@'", "';'", "'{'", "'}'", "'#'", "$accept", "program",
  "COMMA", "SEMICOLON", "top_level_reader_macro",
  "optional_public_or_private_module", "module_name", "module_declaration",
  "character_sequence", "string_constant", "string_builder_body",
  "string_builder", "reader_character_sequence", "expr_reader", "$@1",
  "options_declaration", "require_declaration", "require_module_name",
  "require_module", "is_public_module", "expect_declaration",
  "expect_list", "expect_error", "expression_label", "expression_goto",
  "elif_or_static_elif", "emit_semis", "optional_emit_semis",
  "expression_else", "if_or_static_if", "expression_else_one_liner",
  "expression_if_one_liner", "semis", "optional_semis",
  "expression_if_then_else", "$@2", "expression_if_then_else_oneliner",
  "expression_for_loop", "$@3", "expression_unsafe",
  "expression_while_loop", "$@4", "expression_with", "$@5",
  "expression_with_alias", "annotation_argument_value",
  "annotation_argument_value_list", "annotation_argument_name",
  "annotation_argument", "annotation_argument_list",
  "metadata_argument_list", "annotation_declaration_name",
  "annotation_declaration_basic", "annotation_declaration",
  "annotation_list", "optional_annotation_list",
  "optional_annotation_list_with_emit_semis",
  "optional_function_argument_list", "optional_function_type",
  "function_name", "global_function_declaration",
  "optional_public_or_private_function", "function_declaration_header",
  "function_declaration", "$@6", "expression_block_finally", "$@7", "$@8",
  "expression_block", "$@9", "$@10", "expr_call_pipe", "expression_any",
  "expressions", "optional_expr_list", "optional_expr_map_tuple_list",
  "type_declaration_no_options_list", "name_in_namespace",
  "expression_delete", "new_type_declaration", "$@11", "$@12", "expr_new",
  "expression_break", "expression_continue", "expression_return",
  "expression_yield", "expression_try_catch", "kwd_let_var_or_nothing",
  "kwd_let", "optional_in_scope", "tuple_expansion",
  "tuple_expansion_variable_declaration", "expression_let", "expr_cast",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "expr_type_decl", "$@19",
  "$@20", "expr_type_info", "expr_list", "block_or_simple_block",
  "block_or_lambda", "capture_entry", "capture_list",
  "optional_capture_list", "expr_full_block",
  "expr_full_block_assumed_piped", "expr_numeric_const", "expr_assign",
  "expr_named_call", "expr_method_call", "func_addr_name",
  "func_addr_expr", "$@21", "$@22", "$@23", "$@24", "expr_field", "$@25",
  "$@26", "expr_call", "expr", "$@27", "$@28", "$@29", "$@30", "$@31",
  "$@32", "expr_generator", "expr_mtag", "optional_field_annotation",
  "optional_override", "optional_constant",
  "optional_public_or_private_member_variable",
  "optional_static_member_variable", "structure_variable_declaration",
  "struct_variable_declaration_list", "$@33", "$@34", "$@35",
  "function_argument_declaration", "function_argument_list", "tuple_type",
  "tuple_type_list", "tuple_alias_type_list", "variant_type",
  "variant_type_list", "variant_alias_type_list", "copy_or_move",
  "variable_declaration", "copy_or_move_or_clone", "optional_ref",
  "let_variable_name_with_pos_list",
  "global_let_variable_name_with_pos_list", "variable_declaration_list",
  "let_variable_declaration", "global_let_variable_declaration",
  "optional_shared", "optional_public_or_private_variable",
  "global_variable_declaration_list", "$@36", "global_let", "$@37",
  "enum_expression", "commas", "enum_list",
  "optional_public_or_private_alias", "single_alias", "$@38",
  "alias_declaration", "optional_public_or_private_enum", "enum_name",
  "optional_enum_basic_type_declaration", "optional_commas", "emit_commas",
  "optional_emit_commas", "enum_declaration", "$@39", "$@40", "$@41",
  "optional_structure_parent", "optional_sealed", "structure_name",
  "class_or_struct", "optional_public_or_private_structure",
  "optional_struct_variable_declaration_list", "structure_declaration",
  "$@42", "$@43", "$@44", "variable_name_with_pos_list",
  "basic_type_declaration", "enum_basic_type_declaration",
  "structure_type_declaration", "auto_type_declaration", "bitfield_bits",
  "bitfield_alias_bits", "bitfield_type_declaration", "$@45", "$@46",
  "c_or_s", "table_type_pair", "dim_list", "type_declaration_no_options",
  "type_declaration_no_options_no_dim", "$@47", "$@48", "$@49", "$@50",
  "$@51", "$@52", "$@53", "$@54", "$@55", "$@56", "$@57", "$@58", "$@59",
  "$@60", "$@61", "$@62", "$@63", "$@64", "$@65", "$@66", "$@67", "$@68",
  "$@69", "$@70", "$@71", "$@72", "$@73", "type_declaration",
  "tuple_alias_declaration", "$@74", "$@75", "$@76", "$@77",
  "variant_alias_declaration", "$@78", "$@79", "$@80", "$@81",
  "bitfield_alias_declaration", "$@82", "$@83", "$@84", "$@85",
  "make_decl", "make_struct_fields", "make_variant_dim",
  "make_struct_single", "make_struct_dim_list", "make_struct_dim_decl",
  "optional_make_struct_dim_decl", "use_initializer", "make_struct_decl",
  "$@86", "$@87", "$@88", "$@89", "$@90", "$@91", "$@92", "$@93",
  "make_map_tuple", "make_tuple_call", "$@94", "$@95", "make_dim_decl",
  "$@96", "$@97", "$@98", "$@99", "$@100", "$@101", "$@102", "$@103",
  "$@104", "$@105", "expr_map_tuple_list", "make_table_decl",
  "array_comprehension_where", "optional_comma", "array_comprehension", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1385)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-735)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1385,   114, -1385, -1385,    42,    47,    91,    31, -1385,   -22,
   -1385, -1385, -1385, -1385,   165,   113, -1385, -1385, -1385, -1385,
      21,    21,    21, -1385,   209,   197, -1385,   285, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,    79, -1385,
     191,   213,   238, -1385, -1385,    91,    15, -1385, -1385, -1385,
     263,    21, -1385, -1385,   285,    31,    31,    31,   301,   436,
   -1385, -1385, -1385,   113,   113,   113,   330, -1385,   566,    37,
   -1385, -1385, -1385, -1385, -1385,   234,   281, -1385,   259,    65,
      42,   421,    47,   392,   449, -1385,   461,   464, -1385, -1385,
   -1385,   302,   497,   499,   502, -1385,   507,   514, -1385, -1385,
     -40,    42,   113,   113,   113,   113,    18,   529, -1385, -1385,
   -1385, -1385, -1385, -1385,   578, -1385, -1385,   478, -1385, -1385,
   -1385, -1385, -1385,   561,   100, -1385, -1385, -1385, -1385,   599,
   -1385, -1385,   513, -1385, -1385, -1385,   525,   537,   537, -1385,
   -1385,   551, -1385,   -87, -1385,   432,   564,   566, -1385,   555,
   -1385, -1385, -1385,   562,  7028, -1385, -1385, -1385, -1385,   520,
   -1385, -1385, -1385,   584, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385,   107, -1385,  1773, -1385,   563, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385,   572, 10397, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
     706,   718, -1385,   556,   537,   654,   -93,    42,   559,   600,
   -1385, -1385, -1385,   100, -1385,   586,   589,   590,   573,   591,
     603, -1385, -1385, -1385,   579, -1385, -1385, -1385, -1385, -1385,
     604, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385,   605, -1385, -1385, -1385,   607,   608, -1385, -1385,
   -1385, -1385,   609,   610,   602,   165, -1385, -1385, -1385, -1385,
   -1385, -1385,  1193,   614, -1385,   598,   601,   606,   453,   525,
     642,   647, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385,   651,   617, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385,   786, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,   655,
     618, -1385, -1385,   -76,   643, -1385, -1385,   657,   537, -1385,
   -1385,   520,   537,    42, -1385,   340, -1385, -1385, -1385, -1385,
   -1385,  6444, -1385, -1385,   658, -1385,   -13,   311,   430, -1385,
   -1385,  6444,   199, -1385, -1385, -1385,     9, -1385, -1385, -1385,
      13,  3594, -1385,   624,   882, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385,   620, -1385, -1385,
   -1385, -1385,   660,   695, -1385,   633, -1385,    70, -1385,  -114,
    1773, -1385, -1385,   629,   659, -1385,   -55, -1385,   537,   673,
    1773, -1385,    25,  1773,  1773,  1773,   662,   668, -1385, -1385,
      35,   165,   669,    27, -1385,   232,   637,   670,   671,   640,
     674,   653,   288,   676, -1385,   380,   677,   678,  6444,  6444,
     661,   663,   664,   665,   666,   667, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385,  6444,  6444,  6444,  6444,  6444,
    3214,  6444, -1385,   656,  3784, -1385, -1385, -1385,   672, -1385,
   -1385, -1385, -1385,   675, -1385, -1385, -1385, -1385, -1385, -1385,
     272,  6869, -1385, -1385,   680, -1385, -1385, -1385, -1385, -1385,
   -1385,  1773,  1773,   681,   697,  1773,   556,  1773,   556,  1773,
     556,  6779,   699,  6957, -1385,  6444, -1385, -1385, -1385, -1385,
     682, -1385, -1385,  9878,  3974, -1385, -1385,   707,  6779,   699,
   -1385, -1385, -1385,  6444, -1385, -1385,    28, -1385,   -85,   614,
   -1385,   165, -1385,   490,   683,   825,   467, -1385, -1385, -1385,
     -62, -1385, -1385, -1385,  6444,   -15,   346,   696,   296, -1385,
   -1385, -1385,   684, -1385, -1385,   391, -1385,   705,   709,   715,
   -1385,  6444,  1773,  6444,  6444, -1385, -1385,  6444, -1385,  6444,
   -1385,  6444, -1385, -1385,  6444, -1385,  1773,   974,   974,  6444,
    6444,  6444,  6444,  6444,  6444,   543,   974,   974,   -61,   974,
     974,   686,   862,   723, 10732,   723,   253,   700, 10480, -1385,
     724,  2834,   113,   894,   698, -1385,   675, -1385,  1619, 10551,
    6444,  6444, -1385, -1385,  6444,  6444,  6444,  6444,   740,  6444,
     131,  6444,  6444,  6444,  6444,  6444,  6444,  6444,  6444,  6444,
    4164,  6444,  6444,  6444,  6444,  6444,  6444,  6444,  6444,  6444,
    6444, 11232,  6444, -1385,  4354,   354,   442, -1385, -1385,    86,
     470,   643,   471,   643,   472,   643,   121, -1385,   353,   614,
     729, -1385,   378, -1385,  1773,   708,   723, -1385, -1385, -1385,
    9962, -1385,   306, -1385,    21, -1385,    21,   744,  7046,   710,
     867, -1385,   164, -1385,  2033, -1385, -1385, -1385, -1385,  6444,
     749,   756,  1773,    25, -1385,  6444,  1814, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385,  1773,  1773,  1773,  1773,  3404,   757,
    6444,  1773, -1385, -1385, -1385,  1773,   723,   403,   724,  7134,
    1773,  1773,  7223,  1773,  7311,  1773,   723,  1773,  1773,   723,
    1773,   745,  7400,  7488,  7577,  7665,  7754,  7842, -1385,  6444,
     505,    28,   721,  6444,   726,   728,   727,   730,   433, -1385,
   -1385,    28,  6444,  6444,   725,   -75,   734,   142,  3024, -1385,
     126,   763,   736,   111,   738,   556, -1385,  2238,   894,   759,
     741, -1385, -1385,   760,   742, -1385, -1385,  1222,  1222,  1107,
    1107, 11074, 11074,   746,   299,   748, -1385, 10046,   109,   109,
     680,  1222,  1222, 10929,  1546,   615, 10815, 11201, 10566, 10960,
     323, 11043,  1107,  1107,   646,   646,   299,   299,   299,   383,
    6444,   750,   752,   463,  6444,   942,   753, 10130, -1385,   151,
   -1385, -1385, -1385,   782, -1385,   768, -1385,   806, -1385,   807,
    1773, -1385,  6779,  1773, -1385,   699,   437,   614, -1385, -1385,
   -1385, -1385,   214, -1385, -1385,   975, -1385,    78, -1385,   815,
   -1385,   306, -1385,  6444,   828, -1385,   829, -1385,  1773, -1385,
    6444, -1385,  4544, -1385, -1385,  4734,   831, -1385,    21,   842,
    4924,   -91,  5114, -1385,    21,    21,   988, -1385,   623, -1385,
   -1385,   986, -1385, -1385,   992, -1385,   960,    21,   798, -1385,
      21,    21,    21,    21,    21, -1385,   938, -1385,    21,  1338,
      44,  7931, -1385,   962,   -62,  6444,  1814, -1385, -1385, -1385,
   -1385,   614,   827,   832,   473,   466,   169,   808,   818,   440,
    8019,   482,  1773,  1773,  1773,   835,   819,   822,  1773,   823,
   -1385,   845,   851, -1385,   852, -1385,   854,   836,   857,   858,
     840,   861,   894, -1385, -1385, -1385, -1385, -1385,   843, 10649,
      23,    28, 10732, -1385, -1385,  6444,  6444,  1773,   556,    24,
   10732, -1385, -1385,    45, -1385,   879,  6444,  6444,  6444,   174,
    6634, -1385,   468, -1385, -1385,   156,   643, -1385,   556, -1385,
    6444, -1385,  6444,  5304,  6444, -1385,   864,   846, -1385, -1385,
    6444,   881, -1385, 10214,  6444,  5494,   885, -1385, 10298, -1385,
    5684, -1385,  6444, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385,   614, -1385, -1385,   614, -1385, -1385,
     887,  1773, -1385, -1385,   817, -1385, -1385,   876, -1385,   884,
    6444,   452, -1385,  8108, -1385,  1044,   128, 10732,  6444, 10732,
    1079,  6444, 10732,   922, -1385,   923,   945, 10732, -1385,  6444,
   10732, -1385, -1385,   898, -1385, -1385,   902,   907,   908,   909,
   -1385,  1072, -1385, -1385, -1385, -1385, -1385, -1385,   -71, -1385,
    6444,  6444,  6444,  6444,  6444,  6444,  6444,  6444,  6444,  6444,
    6444,  6444,  6444,  6444,  6444,  6444,  6444,  6444, -1385,   113,
   -1385,  1102,   520, -1385,   949, -1385,  6444,  1814, -1385, -1385,
   -1385, -1385,   912, -1385, -1385, -1385,   915,   954, -1385, -1385,
     937,   939,   940, -1385, -1385,  6444,   941, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385,   -25,  5874, -1385,
    6444,    29,  8196,  8285,   943,   643,  6444, -1385,  8373, 10732,
   10732,   924,  3024,   926,   137,   965,   968,   932,   970,   971,
   -1385,   185,   537,   643,  1773,  8462,  1773,  8550, -1385,   190,
    8639, -1385,  6444, 10846,  6444, -1385,  8727, -1385,   192,  6444,
   -1385, -1385, -1385,   196, -1385, -1385, -1385,  6444,   614, -1385,
   -1385, -1385, 10732, -1385,   917, -1385,   979,  6444, 10732, -1385,
   10732,  6444, -1385, -1385, -1385, 10732,  6444,  6444,    28,  6444,
    6444, -1385, -1385,   982, -1385, -1385, -1385, 10732, 10732, 10732,
   10732, 10732, 10732, 10732, 10732, 10732, 10732, 10732, 10732, 10732,
   10732, 10732, 10732, 10732, 10732,   189,   581,  1069,    21, -1385,
    1814, -1385,   946,   947, -1385, -1385,  6444,   976, -1385, -1385,
   -1385, -1385,   958,   948,   724,   959,  6444,  6444,  6444,   961,
    1089,   963,   964,  6064, -1385, -1385,   212,   237,  6444, -1385,
   -1385, -1385,   981,   262,   182, -1385,   246,  6444,  6444,  6444,
   -1385, -1385,  1002, -1385, -1385,   156, -1385,  1028,   537,   987,
   -1385,   494, -1385, -1385, -1385,  1773,  8816,  8904, -1385, -1385,
    8993, -1385,   966, -1385, -1385, 10732, -1385, 10732,  9081,  9170,
      49,  9258,  9347,   969, -1385,   264,   130,   537, -1385, -1385,
     560, -1385,    17, -1385, -1385,  1089,  1089,  9435,   973,   978,
     980,   984,  6444, -1385, -1385,  6444,  1107,  1107,  1107,  6444,
   -1385, -1385,  1089,   466, -1385,  9524, -1385, -1385,   972,   271,
     376, -1385,   977,  6444,  6444,   989,  9612, 10732, 10732,   991,
   -1385,  6254, -1385, -1385, -1385, -1385, -1385,   501, -1385, -1385,
   -1385, -1385,  1156,   537,  6444,   537,   537, -1385,  1007,   382,
   -1385, -1385, -1385,  1141,    17, -1385, -1385,   581,   -10,   -10,
   -1385,  6444,  1089,  1089,   466,  1012,  1014,   723,   -10,   763,
    1015, -1385,  6444,  1013, -1385,   376,  6444, 10732, 10732, -1385,
     187, -1385,  6444, 10815, -1385, -1385, -1385, -1385,  2644,    21,
   -1385,   277, -1385, -1385,  2443, -1385,  1773,    25, -1385, -1385,
    1141,    28,   466,   763,  1045, -1385,  1018,  1019,  9701,   -10,
     -10,  1020, -1385, -1385,  1021,  1033, -1385,  6780,  6444, -1385,
    1036,  6444,  6444, 10846, -1385, -1385, -1385, -1385, -1385, -1385,
   10732, -1385,   458,   537, -1385, -1385,  1037,    25,  6444,  7028,
   -1385, -1385,   283,   985, -1385, -1385, -1385, -1385,  1046,  1047,
   -1385, -1385, -1385,  1192,  1050,  6780,  1051, 10732, 10732,   537,
   -1385, -1385,  1052, -1385, -1385, -1385,  6444,  1814,    21,  7028,
   -1385,   466, -1385, -1385,  6444, -1385,  1054, -1385, -1385,  6444,
   -1385,  1814, -1385, -1385,   537,   289, 10732, -1385, -1385,  9789,
   -1385, -1385, -1385,   537, -1385, -1385,   458, -1385
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,   132,     1,   293,     0,     0,     0,   580,   294,     0,
     756,   746,   751,    20,     0,     0,    19,    16,    15,     3,
       0,     0,     0,     8,     0,   614,     7,   561,     6,    11,
       5,     4,    13,    12,    14,   102,   103,   101,   110,   112,
      42,    55,    52,    53,    44,     0,    50,    43,   582,   581,
       0,     0,    26,    25,   561,   580,   580,   580,     0,   267,
      40,   117,   118,     0,     0,     0,   119,   121,   128,     0,
     116,    21,    10,     9,   598,   225,     0,   562,   563,     0,
       0,     0,     0,    45,     0,    51,     0,     0,    48,   583,
     585,    22,     0,     0,     0,   269,     0,     0,   127,   122,
       0,     0,     0,     0,     0,     0,    64,   586,   227,   226,
     229,   224,   608,   607,   609,   565,   564,   571,   108,   109,
     106,   107,   105,     0,     0,   104,   113,    56,    54,    50,
      47,    46,     0,    23,    24,    27,   596,    64,    64,   268,
      38,    41,   126,     0,   123,   124,   125,   129,    62,    65,
     133,   588,   587,     0,     0,   611,   610,   615,   566,   495,
      28,    29,    33,     0,    97,    98,    95,    96,    94,    93,
      99,     0,    49,     0,   594,   597,   757,   747,   752,    39,
     120,    63,   589,   590,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
       0,     0,   139,   134,    64,   604,   568,     0,   496,     0,
      30,    31,    32,     0,   111,     0,     0,     0,     0,     0,
       0,   623,   643,   624,   659,   625,   629,   630,   631,   632,
     649,   636,   637,   638,   639,   640,   641,   642,   644,   645,
     646,   647,   716,   628,   635,   648,   723,   730,   626,   633,
     627,   634,     0,     0,     0,     0,   658,   680,   683,   681,
     682,   743,   678,   584,   595,     0,     0,     0,     0,   596,
     193,   194,   191,   142,   143,   145,   144,   146,   147,   148,
     149,   175,   176,   173,   174,   166,   177,   178,   167,   164,
     165,   192,   186,     0,   190,   179,   180,   181,   182,   153,
     154,   155,   150,   151,   152,   163,     0,   169,   170,   168,
     161,   162,   157,   156,   158,   159,   160,   141,   140,   185,
       0,   171,   172,   495,   137,   235,   605,     0,    64,   570,
     567,   495,    64,     0,   550,   543,   572,   100,   684,   707,
     710,     0,   713,   703,     0,   667,   717,   724,   731,   737,
     740,     0,     0,   693,   698,   692,     0,   706,   702,   695,
       0,     0,   697,   679,     0,   758,   748,   753,   650,   653,
     656,   657,   651,   654,   652,   655,   591,     0,   195,   196,
     189,   184,   197,   187,   183,     0,   135,   292,   518,     0,
       0,   228,   230,     0,   602,   616,     0,   114,    64,     0,
       0,   544,     0,     0,     0,     0,     0,     0,   400,   401,
       0,     0,     0,     0,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   649,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,   339,   341,   340,
     342,   343,   344,   345,    34,     0,     0,     0,     0,     0,
       0,     0,   324,   325,     0,   398,   397,   474,   395,   467,
     466,   465,   464,   130,   470,   396,   469,   468,   441,   402,
     442,     0,   446,   403,     0,   399,   761,   765,   762,   763,
     764,     0,     0,     0,     0,     0,   134,     0,   134,     0,
     134,     0,     0,     0,   689,   261,   700,   701,   694,   696,
       0,   699,   675,     0,     0,   745,   744,   664,   524,   530,
     599,   198,   188,     0,   290,   291,     0,   136,   495,   138,
     258,     0,   606,     0,     0,   545,   543,   569,   115,   551,
       0,   541,   542,   540,     0,     0,     0,     0,   672,   784,
     787,   272,   276,   275,   281,     0,   313,     0,     0,     0,
     813,     0,     0,     0,     0,   304,   307,     0,   310,     0,
     817,     0,   793,   799,     0,   790,     0,   430,   431,     0,
       0,     0,     0,     0,     0,     0,   407,   406,   443,   405,
     404,     0,     0,   828,   319,   828,   326,     0,   797,   820,
     828,     0,     0,   334,   325,   258,   130,   238,     0,     0,
       0,     0,   432,   433,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   384,     0,   687,     0,     0,     0,   660,   662,     0,
       0,   137,     0,   137,     0,   137,   267,   522,     0,   520,
       0,   528,     0,   661,     0,     0,   828,   691,   674,   677,
       0,   665,   592,   525,    80,   531,    80,   577,     0,     0,
     618,   516,   535,   519,     0,   603,   612,   508,   617,     0,
       0,     0,     0,     0,   558,     0,     0,   685,   708,   711,
      18,    17,   670,   671,     0,     0,     0,     0,   782,     0,
       0,     0,   803,   806,   809,     0,   828,     0,   828,     0,
       0,     0,     0,     0,     0,     0,   828,     0,     0,   828,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      35,     0,     0,   829,     0,     0,     0,     0,   372,   369,
     371,     0,     0,   829,     0,     0,     0,   267,     0,   387,
       0,   775,     0,     0,     0,   134,   326,     0,   334,     0,
       0,   453,   452,     0,     0,   454,   458,   408,   409,   421,
     422,   419,   420,     0,   447,     0,   439,     0,   471,   472,
     473,   410,   411,   426,   427,   428,   429,     0,     0,   424,
     425,   423,   417,   418,   413,   412,   414,   415,   416,     0,
       0,     0,   378,     0,     0,     0,     0,     0,   392,     0,
     714,   704,   668,     0,   718,     0,   725,     0,   732,     0,
       0,   738,     0,     0,   741,     0,     0,   265,   688,   262,
     676,   575,   593,   759,    78,    81,   749,    81,   754,   573,
     578,   592,   517,     0,     0,   534,     0,   533,     0,   536,
       0,   260,   284,   282,   235,     0,     0,   283,     0,     0,
       0,    64,     0,   239,     0,     0,     0,   252,     0,   253,
     247,     0,   244,   243,     0,   245,     0,     0,     0,   259,
       0,    76,    77,    74,    75,   254,   296,   242,     0,   346,
     510,     0,   547,   548,     0,     0,     0,   560,   686,   709,
     712,   673,     0,     0,     0,   783,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     444,     0,     0,   445,     0,   475,     0,     0,     0,     0,
       0,     0,   334,   479,   480,   481,   482,   483,     0,     0,
       0,     0,   320,   802,   434,     0,     0,     0,   134,     0,
     796,   821,   822,     0,   388,     0,     0,     0,     0,     0,
       0,   391,     0,   389,   131,     0,   137,   338,   134,   449,
       0,   455,     0,     0,     0,   437,     0,     0,   459,   463,
       0,     0,   440,     0,     0,     0,     0,   379,     0,   385,
       0,   435,     0,   393,   715,   705,   669,   663,   719,   721,
     726,   728,   733,   735,   521,   739,   523,   527,   742,   529,
       0,     0,   666,   576,     0,    79,   526,     0,   532,     0,
       0,   593,   600,     0,   620,   621,   537,   539,     0,   285,
       0,     0,   270,     0,   257,     0,     0,    59,   235,     0,
     287,   255,   256,     0,    69,    70,     0,     0,     0,     0,
     246,   231,   241,   248,   249,   250,   251,   295,     0,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   509,     0,
     613,     0,   495,   546,     0,   555,     0,     0,   559,   785,
     788,   273,     0,   278,   279,   277,     0,     0,   316,   314,
       0,     0,     0,   814,   812,   263,     0,   823,   305,   308,
     311,   818,   816,   794,   800,   798,   791,    64,     0,    36,
       0,     0,     0,     0,     0,   137,     0,   390,     0,   767,
     766,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     332,     0,    64,   137,     0,     0,     0,     0,   367,     0,
       0,   460,     0,   448,     0,   438,     0,   380,     0,     0,
     436,   386,   382,     0,   722,   729,   736,   261,   266,   760,
     750,   755,   574,   579,     0,   619,     0,     0,   286,   235,
     271,     0,    57,    58,    87,   288,     0,     0,     0,     0,
       0,   232,   237,     0,   552,   302,   301,   356,   357,   359,
     358,   360,   350,   351,   352,   361,   362,   348,   349,   363,
     364,   353,   354,   355,   347,     0,   502,   505,     0,   549,
       0,   557,     0,     0,   274,   280,     0,     0,   315,   804,
     807,   810,     0,     0,   828,     0,     0,     0,     0,     0,
     782,     0,     0,     0,   235,   485,     0,     0,     0,   370,
     494,   373,     0,     0,     0,   365,     0,     0,     0,     0,
     329,   330,     0,   328,   327,     0,   335,   235,    64,     0,
     493,     0,   491,   368,   488,     0,     0,     0,   487,   381,
       0,   383,     0,   601,   622,   538,   289,    92,     0,     0,
       0,     0,     0,     0,   297,     0,     0,    64,   503,   504,
     505,   506,   497,   511,   556,   782,   782,     0,     0,     0,
       0,     0,   261,   824,   264,   263,   306,   309,   312,     0,
     783,   795,   782,     0,   476,     0,   478,   486,     0,     0,
       0,   376,     0,     0,     0,     0,     0,   769,   768,     0,
     333,     0,   321,   336,   235,   450,   456,     0,   492,   490,
     489,   690,    71,    64,     0,    64,    64,   258,     0,   543,
     303,   553,   554,   500,   497,   498,   499,   502,   781,   781,
     317,     0,   782,   782,     0,     0,     0,   828,   781,   774,
       0,   477,     0,     0,   374,     0,     0,   771,   770,   366,
       0,   331,     0,   322,   337,   451,   457,   461,     0,     0,
     235,     0,   235,   235,     0,   298,     0,     0,   501,   512,
     500,     0,     0,   778,   828,   780,     0,     0,     0,   781,
     781,     0,   815,   825,     0,     0,   792,   826,     0,   377,
     826,     0,     0,   323,   462,    72,    76,    77,    74,    75,
      73,    84,    66,    64,    89,    91,     0,     0,     0,     0,
     514,   507,     0,   829,   779,   786,   789,   318,     0,     0,
     811,   819,   801,     0,     0,   826,     0,   773,   772,    64,
      60,    61,     0,    83,   235,   234,     0,     0,     0,     0,
     776,     0,   805,   808,     0,   830,     0,   832,   235,     0,
      86,     0,   300,   513,    64,     0,   827,   831,    67,     0,
     299,   235,   777,    64,   515,   235,    66,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1385, -1385,  -658,    -1, -1385, -1385, -1385, -1385,   679,  1170,
   -1385, -1385, -1385,  1249, -1385, -1385, -1385,  1212, -1385,  1129,
   -1385, -1385,  1177, -1385, -1385, -1385, -1385,  -135,  -255, -1385,
   -1385,  -146,   587,   592, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385,  1042, -1385, -1385,   -58,  1166,
   -1385, -1385, -1385,   318,  -589,  -426,   369,  -465,  -626, -1385,
   -1385, -1385, -1384, -1385, -1385, -1385, -1385, -1385,  -819, -1385,
   -1385, -1385, -1385,  -600, -1122,   -54, -1385,    -7, -1385, -1385,
   -1385, -1385, -1385,  -138,  -136,  -134,  -133, -1385, -1385,  1275,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385,  -452, -1385,   797,     4, -1385,
    -729, -1385, -1385, -1385, -1385, -1385, -1385, -1289, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385,   571, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385,  -158,   -94,  -137,   -95,
     -26, -1385, -1385, -1385, -1385, -1385,   758, -1385,  -492, -1385,
   -1385,  -504, -1385, -1385,  -665,  -128,  -530,  -532, -1385, -1385,
   -1385, -1045, -1385,  1231, -1385, -1385, -1385, -1385, -1385,   256,
     443, -1385,   702, -1385, -1385, -1385, -1385, -1385, -1385,   444,
   -1385,  1017, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385,  -723,  -143, -1385,   877,
   -1385, -1385, -1385, -1385, -1385, -1385,  -624, -1385, -1385,  -326,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,  -167, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385,   878,  -577,   -84,  -672, -1385, -1385,
   -1261, -1160, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385,  -741, -1385, -1385, -1385, -1385, -1385, -1385, -1385, -1385,
   -1385, -1385, -1385, -1385, -1385, -1385,  -405, -1385, -1287,  -584,
   -1385
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   702,   703,    18,   135,    54,    19,   163,   169,
     585,   465,   141,   466,    97,    21,    22,    46,    47,    88,
      23,    42,    43,   874,   875,  1482,   149,   150,  1483,  1056,
    1409,   876,   845,   846,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,   887,   170,   171,    38,    39,    40,
     218,    66,    67,    68,    69,    24,    25,   334,   401,   213,
      26,   110,   214,   111,   154,  1202,  1303,  1456,   402,   403,
     888,   467,   889,   684,   665,  1243,   836,   468,   890,   552,
     707,  1234,   469,   891,   892,   893,   894,   895,   526,   896,
    1068,  1305,  1205,   897,   470,   720,  1246,   721,  1247,   723,
    1248,   471,   711,  1238,   472,   593,  1353,   473,  1150,  1151,
     765,   474,   607,   475,   898,   476,   477,   750,   478,   957,
    1340,   958,  1395,   479,   815,  1171,   480,   594,  1154,  1405,
    1156,  1406,  1285,  1444,   482,   483,   397,  1377,  1419,  1310,
    1312,  1228,   900,  1092,  1459,  1489,   398,   399,   657,   658,
     674,   661,   662,   676,   968,   681,   544,   412,   536,   345,
    1306,   537,   346,    78,   117,   216,   341,    28,   159,   850,
     842,   851,    50,    51,   132,    29,   153,   183,   279,   843,
     175,   176,    30,   107,   677,  1184,   532,   337,   338,   114,
     157,   688,    31,    76,   215,   533,   682,   484,   386,   268,
     269,   649,   672,   270,   494,  1006,   704,   547,   373,   271,
     272,   413,   908,   664,   492,  1005,   414,   909,   415,   910,
     491,  1004,   495,  1008,   496,  1174,   497,  1010,   498,  1175,
     499,  1012,   500,  1176,   501,  1015,   502,  1018,   659,    32,
      56,   276,   518,  1027,    33,    57,   277,   519,  1029,    34,
      55,   275,   517,  1024,   485,  1423,  1390,   762,  1424,  1425,
    1426,   918,   486,   705,  1232,   706,  1233,   730,  1252,   727,
    1250,   599,   487,   728,  1251,   488,   922,  1319,   923,  1320,
     924,  1321,   715,  1242,   725,  1249,  1244,   489,  1474,   744,
     490
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,   219,   177,   178,   693,   767,   273,    60,    70,   595,
     695,   745,   961,   763,   841,   675,   754,   860,   950,    71,
      72,    73,   126,  1206,   761,   825,   673,   827,   959,   829,
     267,   651,   557,   653,   832,   655,   917,    84,   835,   978,
     416,   417,   506,  1130,  1136,  1040,   508,   603,   516,  1258,
      90,  1394,  -132,   666,  -131,  1292,    70,    70,    70,   600,
     423,    35,    36,  1375,   541,   395,   425,   620,   621,  1364,
     542,    13,    85,   148,   395,  1488,   534,   524,   756,   335,
     118,   119,   839,   965,   540,    80,   527,   963,    48,   528,
    1331,   535,   534,   928,    49,    70,    70,    70,    70,   102,
     103,   104,    13,   432,   433,  1504,  1439,   535,   569,   716,
      16,   543,   339,   180,     2,   164,   165,   217,  1427,   726,
     525,     3,   729,  1376,   396,   964,   217,  1435,  1203,   558,
     559,   761,   926,  1204,   929,   641,   642,   435,   436,   148,
      52,    16,   937,   756,     4,   940,     5,    61,     6,   760,
    -130,   541,   963,  1476,     7,  1378,  1379,   542,   718,   342,
     142,   374,  -720,   905,     8,   697,   266,  -720,  1468,  1469,
       9,   855,  1388,    58,  1253,   679,    62,   967,   761,    53,
     768,   969,   148,   406,  1023,    13,  -720,   507,  1496,  1422,
     680,   509,   819,   841,    10,   856,   856,    59,   543,    86,
    1385,   856,    41,   405,    37,    75,   560,   407,  1088,   105,
     510,    87,  1021,  1127,   551,   340,    11,    12,   857,   511,
     120,   856,  1429,  1430,    16,   121,   561,   122,  1131,  1194,
     123,   267,   460,   529,   618,   106,   717,   620,   621,   464,
     660,  1089,    13,  1102,    63,    74,   545,   546,   548,  1090,
     731,    58,    79,    44,   855,   166,   916,   267,   362,    96,
     167,  1372,   168,   855,   124,   123,   822,   267,   855,  1268,
     267,   267,   267,   538,   967,    59,    45,   534,    13,   223,
      96,    16,  1145,   105,   785,   408,   112,   113,  1146,   823,
     855,   108,   535,   786,    13,  1107,   830,   109,   970,    14,
     976,   857,    64,    58,   374,   641,   642,   224,   855,   974,
     857,    15,    65,   855,  1343,   857,   115,    16,  1147,  1441,
     608,   609,   116,  1002,   645,   646,   971,    59,   650,  1148,
     652,  1019,   654,    16,  1149,  1370,   856,   857,   761,   858,
    1016,  1002,   859,  1028,   608,   609,   972,    77,   267,   267,
    1152,  1003,   267,  1026,   267,   857,   267,  1275,   267,   133,
     857,   105,  1002,    80,  1002,   134,   904,   266,  1002,  1103,
    1296,  1187,  1141,  1023,  1096,   267,  1022,   700,   504,   912,
     913,    98,    99,   100,  1002,  1276,   701,  1307,    81,   925,
    1283,    58,  1289,   266,   931,   932,  1291,   934,   505,   936,
     746,   938,   939,   266,   941,   747,   266,   266,   266,  1002,
      82,   562,  1337,   266,   555,    59,   612,   613,   972,   267,
     144,   145,   146,   147,   618,    89,   619,   620,   621,   622,
     623,   563,   748,   267,  1002,  1336,  1368,  1338,   610,   611,
     612,   613,   614,  1002,  1345,   615,   616,   617,   618,  1002,
     619,   620,   621,   622,   623,   972,   624,   625,  1352,   700,
      13,   972,  1342,    95,  1369,   772,   776,   570,   701,   700,
    1479,  1393,   374,   462,   604,  1300,   605,  1453,   701,  1269,
     790,  1480,  1481,  1490,   266,   266,  -727,   571,   266,  1512,
     266,  -727,   266,  1135,   266,   641,   642,   837,   816,    16,
    1225,   633,   634,   635,   636,   637,   638,   639,   640,  1262,
    -727,   266,   409,  1153,    58,   410,   700,    13,   411,   641,
     642,   267,   374,   746,   685,   701,   698,  1278,   378,   101,
     374,  1159,   379,   831,   820,  1404,   991,   911,    59,   694,
     914,   700,    13,  1168,   921,   992,   380,   381,  1173,   267,
     701,   382,   383,   384,   385,   266,    16,  1416,   834,   573,
     411,   267,   267,   267,   267,  1266,   700,    13,   267,   266,
     709,   102,   267,   104,    96,   701,   127,   267,   267,   574,
     267,    16,   267,   927,   267,   267,   151,   267,    87,   749,
     710,  1452,   152,  1454,  1455,    70,  1110,  1111,  1112,  1344,
     700,    13,  1116,   700,    13,  -734,    16,  1373,  -375,   701,
    -734,   129,   701,  -375,   849,   700,   996,  1020,   374,   756,
    1106,  1143,   821,   130,   701,   997,   131,  1311,   963,  -734,
    1144,  1134,  -375,  1054,  1055,   155,   608,   609,  1308,   691,
      16,   156,   692,    16,  1309,   411,   374,   374,   374,   374,
     824,   826,   828,  1101,   989,  1440,    85,   266,   374,   136,
    1324,   137,  1109,  1014,   138,  1500,  1017,   608,   609,   139,
     374,   220,   221,   844,  1356,   844,  1256,   374,  1257,  1508,
     140,  1407,   158,   873,  1263,   266,   173,   267,   174,   267,
     267,  1036,  1514,   686,   687,   907,  1516,   266,   266,   266,
     266,   148,   267,   102,   266,   102,   103,   104,   266,   160,
     161,   738,   739,   266,   266,   267,   266,   179,   266,   181,
     266,   266,   217,   266,   182,   666,   274,   160,   161,   162,
     610,   611,   612,   613,   614,  1442,  1048,   615,   616,   617,
     618,   331,   619,   620,   621,   622,   623,   278,   624,   625,
     220,   221,   222,   332,   626,   333,  1389,    92,    93,    94,
     336,   343,   344,   612,   613,   348,   873,  1414,   349,   350,
     352,   618,   351,   619,   620,   621,   622,   623,   354,   267,
     267,   267,   353,   355,   356,   267,   357,   358,   359,   360,
     374,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   361,   375,  1434,   388,   376,  1339,  1389,   392,   389,
     377,   641,   642,   390,   267,   391,   394,   393,   400,   404,
     493,   514,   521,   266,   520,   266,   266,   522,  1279,   638,
     639,   640,   523,   530,   531,   539,   564,  1417,   266,   567,
    1464,   549,   641,   642,  1025,  1462,  1025,   550,   556,   565,
     566,   266,   569,   568,  1178,   572,   575,   576,   596,   648,
     579,   660,   580,   581,   582,   583,   584,  1044,   690,   671,
     666,   601,   602,  1051,  1052,   742,   699,  1387,   267,   644,
     667,   647,   689,   708,   712,   741,  1060,  1458,   713,  1062,
    1063,  1064,  1065,  1066,   714,   743,   753,  1069,   764,   751,
     766,   225,   783,  1095,   833,  1098,   849,   226,   838,   853,
     854,   902,  1411,   227,  1505,   266,   266,   266,   903,   919,
     951,   266,   481,   228,   953,   942,   955,  1486,   954,   956,
     962,   229,   503,   966,  1227,   972,   973,   975,   979,   981,
     980,   982,   513,   999,  1007,   983,   230,   984,  1009,   994,
     266,   995,  1000,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,  1011,  1013,  1030,  1281,
    1034,  1035,  1254,  1043,   225,   608,   609,  1045,  1053,  1057,
     226,  1058,  1059,  1061,  1067,  1094,   227,  1099,  1104,   577,
     578,   267,  1100,   267,   266,  1113,   228,  1277,  1105,  1114,
      58,  1115,  1179,  1117,   229,  1118,   586,   587,   588,   589,
     590,  1119,  1120,   264,  1121,   598,  1122,  1123,  1124,   230,
    1125,  1126,  1128,  1161,    59,  1162,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,  1137,
    1164,  1180,    70,   265,  1169,   670,  1177,  1186,   515,  1181,
    1457,   612,   613,  1189,   678,  1191,  1231,  1196,  1192,   618,
    1193,  1197,   620,   621,   622,   623,  1198,  1199,  1200,  1201,
    1226,  1229,  1235,    58,  1236,   696,  1237,  1239,  1357,  1240,
    1241,  1245,  1293,  1261,  1265,  1267,   264,  1270,   608,   609,
    1271,  1272,  1273,  1274,   598,   719,  1311,   656,   722,    13,
     724,  1294,   267,  1354,  1304,  1315,  1316,   266,  1323,   266,
     732,   733,   734,   735,   736,   737,  1318,  1322,  1325,  1330,
    1329,  1341,  1332,  1333,  1349,  1351,  1361,  1355,  1408,  1415,
     641,   642,  1381,  1367,  1418,  1392,   265,  1382,    16,  1383,
    1396,   777,   778,  1384,  1491,   779,   780,   781,   782,  1399,
     784,  1401,   787,   788,   789,   791,   792,   793,   794,   795,
     796,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   808,  1432,   817,  1433,  1436,  1438,  1463,  1465,  1466,
    1470,  1471,   610,   611,   612,   613,   363,  1313,  1410,  1314,
    1412,  1413,   618,  1472,   619,   620,   621,   622,   623,  1473,
     624,   625,  1485,   608,   609,  1494,  1492,  1493,  1495,   125,
      20,  1499,  1507,   364,   365,   899,  1497,    83,   172,   128,
     901,  1517,  1445,   847,   740,   347,   906,   143,   848,  1091,
    1446,  1386,  1447,   267,  1448,  1449,    27,   606,   266,  1350,
    1420,   920,  1421,  1460,  1374,    91,   683,  1183,   636,   637,
     638,   639,   640,  1461,  1031,  1032,   387,   553,   554,     0,
    1431,     0,     0,   641,   642,  1371,     0,     0,     0,     0,
     949,     0,     0,     0,   952,     0,   366,     0,  1484,     0,
     367,     0,     0,   960,   598,     0,     0,     0,     0,     0,
       0,     0,     0,   749,     0,     0,     0,     0,   899,   612,
     613,     0,     0,     0,  1498,     0,     0,   618,   -73,   619,
     620,   621,   622,   623,     0,     0,     0,     0,     0,   608,
     609,     0,     0,     0,     0,     0,     0,   368,     0,  1511,
       0,   369,     0,     0,   370,     0,     0,     0,  1515,     0,
       0,   993,     0,     0,     0,   998,     0,     0,   749,     0,
     371,     0,     0,     0,     0,     0,     0,     0,     0,   372,
       0,     0,     0,   636,   637,   638,   639,   640,  1451,   266,
       0,     0,     0,   873,     0,     0,     0,     0,   641,   642,
       0,     0,     0,     0,  1033,     0,     0,     0,     0,     0,
       0,  1037,     0,  1039,     0,     0,  1042,     0,     0,     0,
       0,  1047,     0,  1050,     0,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,   610,   611,   612,   613,   614,  1078,  1079,
     615,   616,   617,   618,  1080,   619,   620,   621,   622,   623,
    1081,   624,   625,  1082,  1083,     0,  1097,   626,   627,   628,
    1084,  1085,  1086,   629,     0,     0,  1502,  1503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1510,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1087,   630,     0,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,     0,     0,  1132,  1133,     0,     0,
       0,     0,     0,     0,   641,   642,     0,  1138,  1139,  1140,
       0,   952,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1155,     0,  1157,     0,  1160,     0,     0,     0,     0,
       0,  1163,     0,     0,     0,  1166,     0,   608,   609,     0,
       0,     0,     0,   952,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1182,     0,     0,     0,     0,     0,     0,     0,  1188,
       0,     0,  1190,     0,     0,     0,     0,     0,     0,     0,
    1195,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   769,     0,
       0,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,     0,
       0,   610,   611,   612,   613,   614,     0,  1230,   615,   616,
     617,   618,     0,   619,   620,   621,   622,   623,     0,   624,
     625,     0,     0,     0,     0,   626,   598,   628,     0,     0,
     231,   232,   233,     0,   235,   236,   237,   238,   239,   434,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,     0,   253,   254,   255,     0,     0,   258,   259,   260,
     261,     0,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,     0,  1286,     0,  1287,     0,     0,     0,     0,
    1290,     0,   641,   642,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1295,     0,
       0,     0,  1297,     0,     0,     0,     0,  1298,  1299,     0,
    1301,  1302,   770,     0,     0,     0,     0,     0,     0,     0,
       0,   771,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,     0,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,   227,     0,     0,  1317,     0,     0,
       0,     0,     0,     0,   228,     0,     0,  1326,  1327,  1328,
       0,     0,   229,     0,  1335,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   608,   609,   230,  1346,  1347,
    1348,     0,     0,     0,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,  1397,  1398,     0,     0,     0,     0,
       0,     0,  1403,     0,   264,     0,     0,     0,     0,   610,
     611,   612,   613,   614,     0,    59,   615,   616,   617,   618,
       0,   619,   620,   621,   622,   623,     0,   624,   625,     0,
       0,     0,  1428,   626,   627,   628,     0,     0,     0,   629,
       0,     0,     0,  1437,     0,     0,     0,   598,     0,     0,
       0,     0,     0,  1443,   265,     0,     0,     0,    13,  1450,
       0,     0,     0,     0,     0,   899,     0,     0,   630,     0,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1475,
     641,   642,  1477,  1478,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1487,
       0,     0,     0,     0,   861,     0,     0,     0,   416,   417,
       3,     0,   -88,   -82,   -82,     0,   -85,     0,   418,   419,
     420,   421,   422,     0,     0,     0,     0,  1501,   423,   862,
     424,   863,   864,     0,   425,  1506,     0,     0,     0,     0,
    1509,   865,   426,     0,     0,   -90,     0,   866,   427,     0,
       0,   428,     0,     8,   429,   867,     0,   868,   430,     0,
       0,   869,   870,     0,     0,     0,     0,     0,   871,     0,
       0,   432,   433,     0,   231,   232,   233,     0,   235,   236,
     237,   238,   239,   434,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,     0,   253,   254,   255,     0,
       0,   258,   259,   260,   261,   435,   436,   437,   872,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     438,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,   440,
     441,   442,   443,   444,     0,   445,     0,   446,   447,   448,
     449,   450,   451,   452,   453,    59,     0,    13,   454,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   455,   456,   457,     0,    14,     0,
       0,   458,   459,     0,     0,     0,     0,     0,     0,     0,
     460,     0,   461,     0,   462,   463,    16,   464,  -236,   861,
       0,     0,     0,   416,   417,     3,     0,   -88,   -82,   -82,
       0,   -85,     0,   418,   419,   420,   421,   422,     0,     0,
       0,     0,     0,   423,   862,   424,   863,   864,     0,   425,
       0,     0,     0,     0,     0,     0,   865,   426,     0,     0,
     -90,     0,   866,   427,     0,     0,   428,     0,     8,   429,
     867,     0,   868,   430,     0,     0,   869,   870,     0,     0,
       0,     0,     0,   871,     0,     0,   432,   433,     0,   231,
     232,   233,     0,   235,   236,   237,   238,   239,   434,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,   253,   254,   255,     0,     0,   258,   259,   260,   261,
     435,   436,   437,   872,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   438,   439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,   440,   441,   442,   443,   444,     0,
     445,     0,   446,   447,   448,   449,   450,   451,   452,   453,
      59,     0,    13,   454,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   455,
     456,   457,     0,    14,     0,     0,   458,   459,     0,     0,
       0,     0,     0,     0,     0,   460,     0,   461,     0,   462,
     463,    16,   464,   977,   861,     0,     0,     0,   416,   417,
       3,     0,   -88,   -82,   -82,     0,   -85,     0,   418,   419,
     420,   421,   422,     0,     0,     0,     0,     0,   423,   862,
     424,   863,   864,     0,   425,     0,     0,     0,     0,     0,
       0,   865,   426,     0,     0,   -90,     0,   866,   427,     0,
       0,   428,     0,     8,   429,   867,     0,   868,   430,     0,
       0,   869,   870,     0,     0,     0,     0,     0,   871,     0,
       0,   432,   433,     0,   231,   232,   233,     0,   235,   236,
     237,   238,   239,   434,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,     0,   253,   254,   255,     0,
       0,   258,   259,   260,   261,   435,   436,   437,   872,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     438,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,   440,
     441,   442,   443,   444,     0,   445,     0,   446,   447,   448,
     449,   450,   451,   452,   453,    59,     0,    13,   454,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   455,   456,   457,     0,    14,     0,
       0,   458,   459,     0,     0,     0,     0,     0,     0,     0,
     460,     0,   461,     0,   462,   463,    16,   464,  -233,   416,
     417,     0,     0,     0,     0,     0,     0,     0,     0,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
     862,   424,   863,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,   867,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,   872,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,   755,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,   756,   446,   447,
     448,   449,   450,   451,   452,   453,   757,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   758,     0,   461,   759,   462,   463,   591,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,   592,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,   756,   446,   447,
     448,   449,   450,   451,   452,   453,   757,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,   591,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,   592,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,   915,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,   756,   446,   447,
     448,   449,   450,   451,   452,   453,   757,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,   512,   461,     0,   462,   463,   597,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,   669,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,   797,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,   818,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
    1038,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,  1041,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,  1046,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
    1049,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,  1158,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,  1167,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,  1172,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,  1255,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,  1334,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
    1402,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,    14,
       0,     0,   458,   459,     0,     0,     0,     0,     0,   416,
     417,   460,     0,   461,     0,   462,   463,     0,   464,   418,
     419,   420,   421,   422,     0,     0,     0,     0,     0,   423,
       0,   424,     0,     0,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,   427,
       0,     0,   428,     0,     0,   429,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,   432,   433,     0,   231,   232,   233,     0,   235,
     236,   237,   238,   239,   434,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,   253,   254,   255,
       0,     0,   258,   259,   260,   261,   435,   436,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   439,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     440,   441,   442,   443,   444,     0,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,    59,     0,   225,   454,
       0,   608,   609,     0,   226,     0,     0,     0,     0,     0,
     227,     0,     0,     0,     0,   455,   456,   457,     0,    14,
     228,     0,   458,   459,     0,     0,     0,     0,   229,     0,
       0,  1142,     0,   461,     0,   462,   463,     0,   464,     0,
       0,     0,     0,   230,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,     0,     0,     0,     0,     0,     0,     0,
     608,   609,     0,     0,     0,   610,   611,   612,   613,   614,
       0,     0,   615,   616,   617,   618,     0,   619,   620,   621,
     622,   623,     0,   624,   625,     0,     0,    58,     0,   626,
     627,   628,     0,     0,     0,   629,     0,     0,     0,     0,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   656,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   641,   642,   608,   609,
     265,     0,     0,  1473,   610,   611,   612,   613,   614,     0,
       0,   615,   616,   617,   618,     0,   619,   620,   621,   622,
     623,     0,   624,   625,     0,     0,     0,     0,   626,   627,
     628,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,     0,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,     0,     0,     0,     0,     0,
       0,     0,     0,   184,     0,   641,   642,   608,   609,   643,
       0,     0,   610,   611,   612,   613,   614,     0,     0,   615,
     616,   617,   618,     0,   619,   620,   621,   622,   623,     0,
     624,   625,     0,     0,     0,     0,   626,   627,   628,   185,
       0,   186,   629,   187,   188,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
       0,   203,   204,   205,     0,     0,   206,   207,   208,   209,
       0,   630,     0,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,     0,     0,   210,   211,     0,     0,     0,
       0,     0,     0,   641,   642,   608,   609,   663,     0,     0,
       0,   610,   611,   612,   613,   614,     0,     0,   615,   616,
     617,   618,     0,   619,   620,   621,   622,   623,     0,   624,
     625,     0,     0,     0,     0,   626,   627,   628,     0,     0,
     212,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,     0,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   641,   642,   608,   609,   852,     0,     0,   610,
     611,   612,   613,   614,     0,     0,   615,   616,   617,   618,
       0,   619,   620,   621,   622,   623,     0,   624,   625,     0,
       0,     0,     0,   626,   627,   628,     0,     0,     0,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,     0,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   642,   608,   609,   930,     0,     0,     0,   610,   611,
     612,   613,   614,     0,     0,   615,   616,   617,   618,     0,
     619,   620,   621,   622,   623,     0,   624,   625,     0,     0,
       0,     0,   626,   627,   628,     0,     0,     0,   629,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,     0,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
     642,   608,   609,   933,     0,     0,   610,   611,   612,   613,
     614,     0,     0,   615,   616,   617,   618,     0,   619,   620,
     621,   622,   623,     0,   624,   625,     0,     0,     0,     0,
     626,   627,   628,     0,     0,     0,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,     0,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   641,   642,   608,
     609,   935,     0,     0,     0,   610,   611,   612,   613,   614,
       0,     0,   615,   616,   617,   618,     0,   619,   620,   621,
     622,   623,     0,   624,   625,     0,     0,     0,     0,   626,
     627,   628,     0,     0,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   641,   642,   608,   609,
     943,     0,     0,   610,   611,   612,   613,   614,     0,     0,
     615,   616,   617,   618,     0,   619,   620,   621,   622,   623,
       0,   624,   625,     0,     0,     0,     0,   626,   627,   628,
       0,     0,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,     0,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,   642,   608,   609,   944,     0,
       0,     0,   610,   611,   612,   613,   614,     0,     0,   615,
     616,   617,   618,     0,   619,   620,   621,   622,   623,     0,
     624,   625,     0,     0,     0,     0,   626,   627,   628,     0,
       0,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,   642,   608,   609,   945,     0,     0,
     610,   611,   612,   613,   614,     0,     0,   615,   616,   617,
     618,     0,   619,   620,   621,   622,   623,     0,   624,   625,
       0,     0,     0,     0,   626,   627,   628,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
       0,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,   642,   608,   609,   946,     0,     0,     0,   610,
     611,   612,   613,   614,     0,     0,   615,   616,   617,   618,
       0,   619,   620,   621,   622,   623,     0,   624,   625,     0,
       0,     0,     0,   626,   627,   628,     0,     0,     0,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,     0,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   642,   608,   609,   947,     0,     0,   610,   611,   612,
     613,   614,     0,     0,   615,   616,   617,   618,     0,   619,
     620,   621,   622,   623,     0,   624,   625,     0,     0,     0,
       0,   626,   627,   628,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,     0,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   641,   642,
     608,   609,   948,     0,     0,     0,   610,   611,   612,   613,
     614,     0,     0,   615,   616,   617,   618,     0,   619,   620,
     621,   622,   623,     0,   624,   625,     0,     0,     0,     0,
     626,   627,   628,     0,     0,     0,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,     0,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   641,   642,   608,
     609,  1093,     0,     0,   610,   611,   612,   613,   614,     0,
       0,   615,   616,   617,   618,     0,   619,   620,   621,   622,
     623,     0,   624,   625,     0,     0,     0,     0,   626,   627,
     628,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,     0,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   641,   642,   608,   609,  1108,
       0,     0,     0,   610,   611,   612,   613,   614,     0,     0,
     615,   616,   617,   618,     0,   619,   620,   621,   622,   623,
       0,   624,   625,     0,     0,     0,     0,   626,   627,   628,
       0,     0,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,     0,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,   642,   608,   609,  1185,     0,
       0,   610,   611,   612,   613,   614,     0,     0,   615,   616,
     617,   618,     0,   619,   620,   621,   622,   623,     0,   624,
     625,     0,     0,     0,     0,   626,   627,   628,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,     0,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   641,   642,   608,   609,  1259,     0,     0,     0,
     610,   611,   612,   613,   614,     0,     0,   615,   616,   617,
     618,     0,   619,   620,   621,   622,   623,     0,   624,   625,
       0,     0,     0,     0,   626,   627,   628,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
       0,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,   642,   608,   609,  1260,     0,     0,   610,   611,
     612,   613,   614,     0,     0,   615,   616,   617,   618,     0,
     619,   620,   621,   622,   623,     0,   624,   625,     0,     0,
       0,     0,   626,   627,   628,     0,     0,     0,   629,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,     0,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
     642,   608,   609,  1264,     0,     0,     0,   610,   611,   612,
     613,   614,     0,     0,   615,   616,   617,   618,     0,   619,
     620,   621,   622,   623,     0,   624,   625,     0,     0,     0,
       0,   626,   627,   628,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,     0,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   641,   642,
     608,   609,  1280,     0,     0,   610,   611,   612,   613,   614,
       0,     0,   615,   616,   617,   618,     0,   619,   620,   621,
     622,   623,     0,   624,   625,     0,     0,     0,     0,   626,
     627,   628,     0,     0,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   641,   642,   608,   609,
    1282,     0,     0,     0,   610,   611,   612,   613,   614,     0,
       0,   615,   616,   617,   618,     0,   619,   620,   621,   622,
     623,     0,   624,   625,     0,     0,     0,     0,   626,   627,
     628,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,     0,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   641,   642,   608,   609,  1284,
       0,     0,   610,   611,   612,   613,   614,     0,     0,   615,
     616,   617,   618,     0,   619,   620,   621,   622,   623,     0,
     624,   625,     0,     0,     0,     0,   626,   627,   628,     0,
       0,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,   642,   608,   609,  1288,     0,     0,
       0,   610,   611,   612,   613,   614,     0,     0,   615,   616,
     617,   618,     0,   619,   620,   621,   622,   623,     0,   624,
     625,     0,     0,     0,     0,   626,   627,   628,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,     0,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   641,   642,   608,   609,  1358,     0,     0,   610,
     611,   612,   613,   614,     0,     0,   615,   616,   617,   618,
       0,   619,   620,   621,   622,   623,     0,   624,   625,     0,
       0,     0,     0,   626,   627,   628,     0,     0,     0,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,     0,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   642,   608,   609,  1359,     0,     0,     0,   610,   611,
     612,   613,   614,     0,     0,   615,   616,   617,   618,     0,
     619,   620,   621,   622,   623,     0,   624,   625,     0,     0,
       0,     0,   626,   627,   628,     0,     0,     0,   629,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,     0,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
     642,   608,   609,  1360,     0,     0,   610,   611,   612,   613,
     614,     0,     0,   615,   616,   617,   618,     0,   619,   620,
     621,   622,   623,     0,   624,   625,     0,     0,     0,     0,
     626,   627,   628,     0,     0,     0,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,     0,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   641,   642,   608,
     609,  1362,     0,     0,     0,   610,   611,   612,   613,   614,
       0,     0,   615,   616,   617,   618,     0,   619,   620,   621,
     622,   623,     0,   624,   625,     0,     0,     0,     0,   626,
     627,   628,     0,     0,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   641,   642,   608,   609,
    1363,     0,     0,   610,   611,   612,   613,   614,     0,     0,
     615,   616,   617,   618,     0,   619,   620,   621,   622,   623,
       0,   624,   625,     0,     0,     0,     0,   626,   627,   628,
       0,     0,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,     0,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,   642,   608,   609,  1365,     0,
       0,     0,   610,   611,   612,   613,   614,     0,     0,   615,
     616,   617,   618,     0,   619,   620,   621,   622,   623,     0,
     624,   625,     0,     0,     0,     0,   626,   627,   628,     0,
       0,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,   642,   608,   609,  1366,     0,     0,
     610,   611,   612,   613,   614,     0,     0,   615,   616,   617,
     618,     0,   619,   620,   621,   622,   623,     0,   624,   625,
       0,     0,     0,     0,   626,   627,   628,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
       0,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,   642,   608,   609,  1380,     0,     0,     0,   610,
     611,   612,   613,   614,     0,     0,   615,   616,   617,   618,
       0,   619,   620,   621,   622,   623,     0,   624,   625,     0,
       0,     0,     0,   626,   627,   628,     0,     0,     0,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,     0,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   642,   608,   609,  1391,     0,     0,   610,   611,   612,
     613,   614,     0,     0,   615,   616,   617,   618,     0,   619,
     620,   621,   622,   623,     0,   624,   625,     0,     0,     0,
       0,   626,   627,   628,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,     0,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   641,   642,
     608,   609,  1400,     0,     0,     0,   610,   611,   612,   613,
     614,     0,     0,   615,   616,   617,   618,     0,   619,   620,
     621,   622,   623,     0,   624,   625,     0,     0,     0,     0,
     626,   627,   628,     0,     0,     0,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,     0,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   641,   642,   608,
     609,  1467,     0,     0,   610,   611,   612,   613,   614,     0,
       0,   615,   616,   617,   618,     0,   619,   620,   621,   622,
     623,     0,   624,   625,     0,     0,     0,     0,   626,   627,
     628,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,     0,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,     0,     0,     0,     0,     0,
       0,     0,     0,   608,   609,   641,   642,     0,     0,  1513,
       0,     0,     0,   610,   611,   612,   613,   614,     0,     0,
     615,   616,   617,   618,     0,   619,   620,   621,   622,   623,
       0,   624,   625,     0,     0,     0,     0,   626,   627,   628,
       0,     0,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,     0,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,     0,     0,     0,   608,   609,     0,
       0,     0,     0,     0,   641,   642,   668,   610,   611,   612,
     613,   614,     0,     0,   615,   616,   617,   618,     0,   619,
     620,   621,   622,   623,     0,   624,   625,     0,     0,     0,
       0,   626,   627,   628,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,     0,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,     0,     0,
       0,   608,   609,     0,     0,     0,     0,     0,   641,   642,
     840,   610,   611,   612,   613,   614,     0,     0,   615,   616,
     617,   618,     0,   619,   620,   621,   622,   623,     0,   624,
     625,     0,     0,     0,     0,   626,   627,   628,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,     0,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,     0,     0,     0,   608,   609,     0,     0,     0,
       0,     0,   641,   642,   985,   610,   611,   612,   613,   614,
       0,     0,   615,   616,   617,   618,     0,   619,   620,   621,
     622,   623,     0,   624,   625,     0,     0,     0,     0,   626,
     627,   628,     0,     0,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,     0,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,     0,     0,     0,   608,
     609,     0,     0,     0,     0,     0,   641,   642,  1001,   610,
     611,   612,   613,   614,     0,     0,   615,   616,   617,   618,
       0,   619,   620,   621,   622,   623,     0,   624,   625,     0,
       0,     0,     0,   626,   627,   628,     0,     0,     0,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,     0,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   642,  1165,   610,   611,   612,   613,   614,   280,   281,
     615,   616,   617,   618,     0,   619,   620,   621,   622,   623,
       0,   624,   625,     0,     0,   282,     0,   626,   627,   628,
       0,     0,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,     0,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,   642,  1170,     0,     0,     0,
       0,   608,   609,     0,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,     0,     0,   301,   302,   303,     0,     0,   304,
     305,   306,   307,   308,     0,     0,   309,   310,   311,   312,
     313,   314,   315,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     773,   316,     0,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,     0,     0,   327,   328,   608,   609,     0,
       0,     0,     0,   329,   330,   610,   611,   612,   613,   614,
       0,     0,   615,   616,   617,   618,     0,   619,   620,   621,
     622,   623,     0,   624,   625,     0,     0,   752,     0,   626,
     627,   628,   231,   232,   233,   629,   235,   236,   237,   238,
     239,   434,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     0,   253,   254,   255,     0,     0,   258,
     259,   260,   261,     0,   630,     0,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,     0,     0,     0,     0,
     608,   609,     0,     0,     0,     0,   641,   642,     0,     0,
       0,   610,   611,   612,   613,   614,     0,     0,   615,   616,
     617,   618,     0,   619,   620,   621,   622,   623,     0,   624,
     625,     0,     0,     0,   774,   626,   627,   628,     0,     0,
       0,   629,     0,   775,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,   990,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,     0,   608,   609,     0,     0,     0,     0,     0,
       0,     0,   641,   642,   610,   611,   612,   613,   614,     0,
       0,   615,   616,   617,   618,     0,   619,   620,   621,   622,
     623,     0,   624,   625,     0,     0,     0,     0,   626,   627,
     628,     0,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1129,
       0,     0,     0,   630,     0,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,     0,   608,   609,     0,     0,
       0,     0,     0,     0,     0,   641,   642,   610,   611,   612,
     613,   614,     0,     0,   615,   616,   617,   618,     0,   619,
     620,   621,   622,   623,     0,   624,   625,   608,   609,     0,
       0,   626,   627,   628,     0,     0,     0,   629,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,     0,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   641,   642,
     610,   611,   612,   613,   614,     0,     0,   615,   616,   617,
     618,     0,   619,   620,   621,   622,   623,     0,   624,   625,
     608,   609,     0,     0,   626,   627,   628,     0,     0,     0,
    -735,   610,   611,   612,   613,   614,     0,     0,   615,   616,
     617,   618,     0,   619,   620,   621,   622,   623,     0,   624,
     625,   608,   609,     0,     0,   626,   627,   628,     0,   630,
       0,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,   642,     0,     0,     0,     0,     0,     0,     0,
     630,     0,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   641,   642,   610,   611,   612,   613,   614,     0,
       0,   615,   616,   617,   618,     0,   619,   620,   621,   622,
     623,     0,   624,   625,   608,   609,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   610,   611,   612,   613,   614,
       0,     0,   615,   616,   617,   618,     0,   619,   620,   621,
     622,   623,     0,   624,   625,   608,   609,     0,     0,     0,
       0,     0,     0,     0,     0,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   641,   642,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,   633,   634,
     635,   636,   637,   638,   639,   640,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   641,   642,   610,   611,
     612,   613,   614,     0,     0,   615,   616,   617,   618,     0,
     619,   620,   621,   622,   623,     0,   624,   625,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     611,   612,   613,   614,     0,     0,   615,     0,     0,   618,
       0,   619,   620,   621,   622,   623,     0,   624,   625,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     986,     0,   634,   635,   636,   637,   638,   639,   640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
     642,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   634,   635,   636,   637,   638,   639,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   642,   231,   232,   233,     0,   235,   236,   237,   238,
     239,   434,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     0,   253,   254,   255,     0,     0,   258,
     259,   260,   261,   231,   232,   233,     0,   235,   236,   237,
     238,   239,   434,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,   253,   254,   255,     0,     0,
     258,   259,   260,   261,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   987,     0,     0,     0,     0,     0,
     809,   810,     0,   988,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   811,     0,     0,     0,     0,
       0,     0,     0,     0,   812,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   813,   814
};

static const yytype_int16 yycheck[] =
{
       1,   159,   137,   138,   536,   605,   173,    14,    15,   461,
     540,   595,   753,   602,   672,   519,   600,   682,   741,    20,
      21,    22,    80,  1068,   601,   651,   518,   653,   751,   655,
     173,   496,     5,   498,   658,   500,   708,    22,   662,   768,
       5,     6,    33,    20,    20,   864,    33,   473,   374,    20,
      51,  1340,     8,   505,    36,  1177,    63,    64,    65,   464,
      25,    19,    20,    46,   126,   150,    31,   128,   129,    20,
     132,   164,    57,   164,   150,  1459,   147,     7,   153,   214,
      15,    16,   666,   755,   410,   172,   200,   162,    57,   203,
    1250,   162,   147,   717,    63,   102,   103,   104,   105,   139,
     140,   141,   164,    68,    69,  1489,  1395,   162,   199,   561,
     203,   173,   205,   200,     0,    15,    16,   202,  1379,   571,
      50,     7,   574,   106,   200,   200,   202,  1388,   199,   102,
     103,   708,   716,   204,   718,   196,   197,   102,   103,   164,
     162,   203,   726,   153,    30,   729,    32,    34,    34,   601,
      36,   126,   162,  1440,    40,  1315,  1316,   132,   563,   217,
     200,   176,   175,   693,    50,   180,   173,   180,  1429,  1430,
      56,   126,  1332,   138,   199,   147,    63,   132,   755,   201,
     606,   758,   164,   341,   842,   164,   199,   178,  1475,   199,
     162,   178,   644,   851,    80,   172,   172,   162,   173,   184,
    1322,   172,   155,   338,   162,     8,   179,   342,   164,   172,
     197,   196,   836,   942,   179,   216,   102,   103,   173,   206,
     155,   172,  1382,  1383,   203,   160,   199,   162,   951,  1048,
     165,   374,   197,   400,   125,   198,   562,   128,   129,   204,
     162,   197,   164,   915,   131,    36,   413,   414,   415,   205,
     576,   138,   173,   162,   126,   155,   708,   400,   265,   138,
     160,  1306,   162,   126,   199,   165,   180,   410,   126,   132,
     413,   414,   415,   408,   132,   162,   185,   147,   164,   172,
     138,   203,   126,   172,   153,   343,     5,     6,   132,   203,
     126,    57,   162,   162,   164,   919,   175,    63,   172,   185,
     765,   173,   189,   138,   176,   196,   197,   200,   126,   198,
     173,   197,   199,   126,   132,   173,    57,   203,   162,   132,
      21,    22,    63,   172,   491,   492,   200,   162,   495,   173,
     497,   835,   499,   203,   178,   205,   172,   173,   915,   175,
     832,   172,   178,   847,    21,    22,   172,    62,   491,   492,
     976,   200,   495,   845,   497,   173,   499,   172,   501,    57,
     173,   172,   172,   172,   172,    63,   692,   374,   172,   200,
    1189,  1036,   198,  1031,   904,   518,   162,   163,   179,   705,
     706,    63,    64,    65,   172,   200,   172,   198,   175,   715,
     200,   138,   200,   400,   720,   721,   200,   723,   199,   725,
     147,   727,   728,   410,   730,   152,   413,   414,   415,   172,
     172,   179,   200,   420,   421,   162,   117,   118,   172,   562,
     102,   103,   104,   105,   125,   162,   127,   128,   129,   130,
     131,   199,   179,   576,   172,  1254,   172,   200,   115,   116,
     117,   118,   119,   172,   198,   122,   123,   124,   125,   172,
     127,   128,   129,   130,   131,   172,   133,   134,  1277,   163,
     164,   172,   200,   162,   200,   608,   609,   179,   172,   163,
      12,   200,   176,   201,   202,  1198,   204,   200,   172,  1144,
     623,    23,    24,   200,   491,   492,   175,   199,   495,   200,
     497,   180,   499,   958,   501,   196,   197,   664,   641,   203,
    1089,   178,   179,   180,   181,   182,   183,   184,   185,  1135,
     199,   518,   172,   978,   138,   175,   163,   164,   178,   196,
     197,   664,   176,   147,   531,   172,   180,  1153,    75,   199,
     176,   983,    79,   180,   180,  1354,   153,   704,   162,   540,
     707,   163,   164,   995,   711,   162,    93,    94,  1000,   692,
     172,    98,    99,   100,   101,   562,   203,   175,   180,   179,
     178,   704,   705,   706,   707,  1142,   163,   164,   711,   576,
     179,   139,   715,   141,   138,   172,   155,   720,   721,   199,
     723,   203,   725,   180,   727,   728,    57,   730,   196,   596,
     199,  1410,    63,  1412,  1413,   602,   922,   923,   924,  1264,
     163,   164,   928,   163,   164,   175,   203,    47,   175,   172,
     180,   162,   172,   180,   162,   163,   153,   180,   176,   153,
     180,   153,   180,   162,   172,   162,   162,    67,   162,   199,
     162,   957,   199,    10,    11,    57,    21,    22,    57,   172,
     203,    63,   175,   203,    63,   178,   176,   176,   176,   176,
     180,   180,   180,   180,   797,  1396,    57,   664,   176,   162,
    1244,   162,   180,   830,   162,  1484,   833,    21,    22,   162,
     176,   166,   167,   674,   180,   676,  1128,   176,  1130,  1498,
     166,   180,   204,   684,  1136,   692,   173,   830,   163,   832,
     833,   858,  1511,   203,   204,   696,  1515,   704,   705,   706,
     707,   164,   845,   139,   711,   139,   140,   141,   715,   166,
     167,   168,   169,   720,   721,   858,   723,   166,   725,   164,
     727,   728,   202,   730,   162,  1177,   163,   166,   167,   168,
     115,   116,   117,   118,   119,  1400,   871,   122,   123,   124,
     125,    35,   127,   128,   129,   130,   131,   175,   133,   134,
     166,   167,   168,    35,   139,   199,  1333,    55,    56,    57,
     106,   202,   162,   117,   118,   179,   767,  1367,   179,   179,
     179,   125,   199,   127,   128,   129,   130,   131,   199,   922,
     923,   924,   179,   179,   179,   928,   179,   179,   179,   179,
     176,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   199,   204,  1387,   162,   204,  1258,  1384,    22,   162,
     204,   196,   197,   162,   957,   198,   198,   162,   175,   162,
     162,   197,   162,   830,   204,   832,   833,   132,  1154,   183,
     184,   185,   199,   204,   175,   162,   199,  1369,   845,   199,
    1424,   179,   196,   197,   845,  1422,   847,   179,   179,   179,
     179,   858,   199,   179,  1021,   179,   179,   179,   202,   162,
     199,   162,   199,   199,   199,   199,   199,   868,    43,   162,
    1322,   199,   197,   874,   875,    13,   180,  1329,  1021,   199,
     198,   200,   199,   199,   179,   199,   887,  1417,   179,   890,
     891,   892,   893,   894,   179,   172,   172,   898,     4,   199,
     202,    19,   162,   904,   175,   906,   162,    25,   200,   199,
      43,   162,  1364,    31,  1491,   922,   923,   924,   162,   162,
     199,   928,   351,    41,   198,   180,   199,  1457,   200,   199,
     205,    49,   361,   199,  1092,   172,   200,   199,   179,   179,
     199,   199,   371,     1,   162,   199,    64,   199,   180,   199,
     957,   199,   199,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   180,   180,   173,  1156,
     162,   162,  1127,   162,    19,    21,    22,   155,    10,    13,
      25,     9,    42,   205,    66,    43,    31,   180,   200,   438,
     439,  1154,   180,  1156,  1021,   180,    41,  1152,   200,   200,
     138,   199,   205,   200,    49,   180,   455,   456,   457,   458,
     459,   180,   180,   151,   180,   464,   200,   180,   180,    64,
     200,   180,   199,   179,   162,   199,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   200,
     199,   205,  1089,   201,   199,   514,   199,    43,   206,   205,
    1416,   117,   118,    14,   523,   173,  1097,   199,   175,   125,
     155,   199,   128,   129,   130,   131,   199,   199,   199,    37,
       8,   162,   200,   138,   199,   544,   162,   180,  1285,   180,
     180,   180,   205,   180,   200,   199,   151,   162,    21,    22,
     162,   199,   162,   162,   563,   564,    67,   162,   567,   164,
     569,   162,  1285,  1278,   162,   199,   199,  1154,   200,  1156,
     579,   580,   581,   582,   583,   584,   180,   199,   199,    70,
     199,   180,   199,   199,   162,   137,   200,   180,    12,   162,
     196,   197,   199,   204,    33,   203,   201,   199,   203,   199,
     203,   610,   611,   199,   199,   614,   615,   616,   617,   200,
     619,   200,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   200,   642,   200,   200,   203,   172,   200,   200,
     200,   200,   115,   116,   117,   118,    33,  1228,  1363,  1230,
    1365,  1366,   125,   200,   127,   128,   129,   130,   131,   203,
     133,   134,   205,    21,    22,    53,   200,   200,   198,    79,
       1,   199,   198,    60,    61,   684,   205,    45,   129,    82,
     689,  1516,  1408,   676,   585,   223,   695,   101,   676,   900,
    1408,  1325,  1408,  1416,  1408,  1408,     1,   480,  1285,  1275,
    1374,   710,  1377,  1420,  1310,    54,   528,  1031,   181,   182,
     183,   184,   185,  1421,   851,   851,   279,   420,   420,    -1,
    1384,    -1,    -1,   196,   197,  1306,    -1,    -1,    -1,    -1,
     739,    -1,    -1,    -1,   743,    -1,   123,    -1,  1453,    -1,
     127,    -1,    -1,   752,   753,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1340,    -1,    -1,    -1,    -1,   767,   117,
     118,    -1,    -1,    -1,  1479,    -1,    -1,   125,    10,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,  1504,
      -1,   178,    -1,    -1,   181,    -1,    -1,    -1,  1513,    -1,
      -1,   810,    -1,    -1,    -1,   814,    -1,    -1,  1395,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
      -1,    -1,    -1,   181,   182,   183,   184,   185,  1409,  1416,
      -1,    -1,    -1,  1414,    -1,    -1,    -1,    -1,   196,   197,
      -1,    -1,    -1,    -1,   853,    -1,    -1,    -1,    -1,    -1,
      -1,   860,    -1,   862,    -1,    -1,   865,    -1,    -1,    -1,
      -1,   870,    -1,   872,    -1,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    -1,   905,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,  1487,  1488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,   955,   956,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,    -1,   966,   967,   968,
      -1,   970,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   980,    -1,   982,    -1,   984,    -1,    -1,    -1,    -1,
      -1,   990,    -1,    -1,    -1,   994,    -1,    21,    22,    -1,
      -1,    -1,    -1,  1002,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1038,
      -1,    -1,  1041,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,    -1,
      -1,   115,   116,   117,   118,   119,    -1,  1096,   122,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
     134,    -1,    -1,    -1,    -1,   139,  1115,   141,    -1,    -1,
      71,    72,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    99,   100,
     101,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,  1162,    -1,  1164,    -1,    -1,    -1,    -1,
    1169,    -1,   196,   197,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1187,    -1,
      -1,    -1,  1191,    -1,    -1,    -1,    -1,  1196,  1197,    -1,
    1199,  1200,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,  1236,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,  1246,  1247,  1248,
      -1,    -1,    49,    -1,  1253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    64,  1267,  1268,
    1269,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1325,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,  1343,  1344,    -1,    -1,    -1,    -1,
      -1,    -1,  1351,    -1,   151,    -1,    -1,    -1,    -1,   115,
     116,   117,   118,   119,    -1,   162,   122,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
      -1,    -1,  1381,   139,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,  1392,    -1,    -1,    -1,  1396,    -1,    -1,
      -1,    -1,    -1,  1402,   201,    -1,    -1,    -1,   164,  1408,
      -1,    -1,    -1,    -1,    -1,  1414,    -1,    -1,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1438,
     196,   197,  1441,  1442,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1458,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     5,     6,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,  1486,    25,    26,
      27,    28,    29,    -1,    31,  1494,    -1,    -1,    -1,    -1,
    1499,    38,    39,    -1,    -1,    42,    -1,    44,    45,    -1,
      -1,    48,    -1,    50,    51,    52,    -1,    54,    55,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    69,    -1,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,    -1,   152,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,   164,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,    -1,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,    -1,   201,   202,   203,   204,   205,     1,
      -1,    -1,    -1,     5,     6,     7,    -1,     9,    10,    11,
      -1,    13,    -1,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      42,    -1,    44,    45,    -1,    -1,    48,    -1,    50,    51,
      52,    -1,    54,    55,    -1,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    68,    69,    -1,    71,
      72,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,
     152,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,   185,    -1,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,   201,
     202,   203,   204,   205,     1,    -1,    -1,    -1,     5,     6,
       7,    -1,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    42,    -1,    44,    45,    -1,
      -1,    48,    -1,    50,    51,    52,    -1,    54,    55,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    69,    -1,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,    -1,   152,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,   164,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,    -1,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,   199,    -1,   201,   202,   203,   204,   205,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,   200,   201,   202,    13,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    13,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,   198,   199,    -1,   201,   202,    13,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,   198,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,   200,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,   200,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,   200,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,   200,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,   200,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,   200,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,     5,
       6,   197,    -1,   199,    -1,   201,   202,    -1,   204,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    19,   165,
      -1,    21,    22,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,
      41,    -1,   188,   189,    -1,    -1,    -1,    -1,    49,    -1,
      -1,   197,    -1,   199,    -1,   201,   202,    -1,   204,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,   134,    -1,    -1,   138,    -1,   139,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    21,    22,
     201,    -1,    -1,   203,   115,   116,   117,   118,   119,    -1,
      -1,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,   196,   197,    21,    22,   200,
      -1,    -1,   115,   116,   117,   118,   119,    -1,    -1,   122,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,    -1,
     133,   134,    -1,    -1,    -1,    -1,   139,   140,   141,    71,
      -1,    73,   145,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,   100,   101,
      -1,   174,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,    21,    22,   200,    -1,    -1,
      -1,   115,   116,   117,   118,   119,    -1,    -1,   122,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
     134,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,    -1,
     162,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    21,    22,   200,    -1,    -1,   115,
     116,   117,   118,   119,    -1,    -1,   122,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
      -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,    21,    22,   200,    -1,    -1,    -1,   115,   116,
     117,   118,   119,    -1,    -1,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,    -1,   133,   134,    -1,    -1,
      -1,    -1,   139,   140,   141,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,    21,    22,   200,    -1,    -1,   115,   116,   117,   118,
     119,    -1,    -1,   122,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,
     139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    21,
      22,   200,    -1,    -1,    -1,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    21,    22,
     200,    -1,    -1,   115,   116,   117,   118,   119,    -1,    -1,
     122,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,    21,    22,   200,    -1,
      -1,    -1,   115,   116,   117,   118,   119,    -1,    -1,   122,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,    -1,
     133,   134,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,    21,    22,   200,    -1,    -1,
     115,   116,   117,   118,   119,    -1,    -1,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,    -1,   133,   134,
      -1,    -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,    21,    22,   200,    -1,    -1,    -1,   115,
     116,   117,   118,   119,    -1,    -1,   122,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
      -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,    21,    22,   200,    -1,    -1,   115,   116,   117,
     118,   119,    -1,    -1,   122,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,   134,    -1,    -1,    -1,
      -1,   139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,
      21,    22,   200,    -1,    -1,    -1,   115,   116,   117,   118,
     119,    -1,    -1,   122,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,
     139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    21,
      22,   200,    -1,    -1,   115,   116,   117,   118,   119,    -1,
      -1,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,    21,    22,   200,
      -1,    -1,    -1,   115,   116,   117,   118,   119,    -1,    -1,
     122,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,    21,    22,   200,    -1,
      -1,   115,   116,   117,   118,   119,    -1,    -1,   122,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
     134,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    21,    22,   200,    -1,    -1,    -1,
     115,   116,   117,   118,   119,    -1,    -1,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,    -1,   133,   134,
      -1,    -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,    21,    22,   200,    -1,    -1,   115,   116,
     117,   118,   119,    -1,    -1,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,    -1,   133,   134,    -1,    -1,
      -1,    -1,   139,   140,   141,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,    21,    22,   200,    -1,    -1,    -1,   115,   116,   117,
     118,   119,    -1,    -1,   122,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,   134,    -1,    -1,    -1,
      -1,   139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,
      21,    22,   200,    -1,    -1,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    21,    22,
     200,    -1,    -1,    -1,   115,   116,   117,   118,   119,    -1,
      -1,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,    21,    22,   200,
      -1,    -1,   115,   116,   117,   118,   119,    -1,    -1,   122,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,    -1,
     133,   134,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,    21,    22,   200,    -1,    -1,
      -1,   115,   116,   117,   118,   119,    -1,    -1,   122,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
     134,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    21,    22,   200,    -1,    -1,   115,
     116,   117,   118,   119,    -1,    -1,   122,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
      -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,    21,    22,   200,    -1,    -1,    -1,   115,   116,
     117,   118,   119,    -1,    -1,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,    -1,   133,   134,    -1,    -1,
      -1,    -1,   139,   140,   141,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,    21,    22,   200,    -1,    -1,   115,   116,   117,   118,
     119,    -1,    -1,   122,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,
     139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    21,
      22,   200,    -1,    -1,    -1,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    21,    22,
     200,    -1,    -1,   115,   116,   117,   118,   119,    -1,    -1,
     122,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,    21,    22,   200,    -1,
      -1,    -1,   115,   116,   117,   118,   119,    -1,    -1,   122,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,    -1,
     133,   134,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,    21,    22,   200,    -1,    -1,
     115,   116,   117,   118,   119,    -1,    -1,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,    -1,   133,   134,
      -1,    -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,    21,    22,   200,    -1,    -1,    -1,   115,
     116,   117,   118,   119,    -1,    -1,   122,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
      -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,    21,    22,   200,    -1,    -1,   115,   116,   117,
     118,   119,    -1,    -1,   122,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,   134,    -1,    -1,    -1,
      -1,   139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,
      21,    22,   200,    -1,    -1,    -1,   115,   116,   117,   118,
     119,    -1,    -1,   122,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,
     139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,    21,
      22,   200,    -1,    -1,   115,   116,   117,   118,   119,    -1,
      -1,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,   196,   197,    -1,    -1,   200,
      -1,    -1,    -1,   115,   116,   117,   118,   119,    -1,    -1,
     122,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,   196,   197,   198,   115,   116,   117,
     118,   119,    -1,    -1,   122,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,   134,    -1,    -1,    -1,
      -1,   139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,   196,   197,
     198,   115,   116,   117,   118,   119,    -1,    -1,   122,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
     134,    -1,    -1,    -1,    -1,   139,   140,   141,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,   196,   197,   198,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,   196,   197,   198,   115,
     116,   117,   118,   119,    -1,    -1,   122,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
      -1,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,   198,   115,   116,   117,   118,   119,    21,    22,
     122,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,   134,    -1,    -1,    38,    -1,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,   198,    -1,    -1,    -1,
      -1,    21,    22,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,   127,   128,   129,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,   174,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,   188,   189,    21,    22,    -1,
      -1,    -1,    -1,   196,   197,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,   134,    -1,    -1,   137,    -1,   139,
     140,   141,    71,    72,    73,   145,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      99,   100,   101,    -1,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,   196,   197,    -1,    -1,
      -1,   115,   116,   117,   118,   119,    -1,    -1,   122,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
     134,    -1,    -1,    -1,   153,   139,   140,   141,    -1,    -1,
      -1,   145,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,   115,   116,   117,   118,   119,    -1,
      -1,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,    -1,   133,   134,    -1,    -1,    -1,    -1,   139,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,   115,   116,   117,
     118,   119,    -1,    -1,   122,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,   134,    21,    22,    -1,
      -1,   139,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,
     115,   116,   117,   118,   119,    -1,    -1,   122,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,    -1,   133,   134,
      21,    22,    -1,    -1,   139,   140,   141,    -1,    -1,    -1,
     145,   115,   116,   117,   118,   119,    -1,    -1,   122,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
     134,    21,    22,    -1,    -1,   139,   140,   141,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,   115,   116,   117,   118,   119,    -1,
      -1,   122,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,    -1,   133,   134,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,   134,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,   115,   116,
     117,   118,   119,    -1,    -1,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,    -1,   133,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
     116,   117,   118,   119,    -1,    -1,   122,    -1,    -1,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,    71,    72,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    -1,    -1,    98,
      99,   100,   101,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
     128,   129,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   208,     0,     7,    30,    32,    34,    40,    50,    56,
      80,   102,   103,   164,   185,   197,   203,   210,   211,   214,
     220,   222,   223,   227,   262,   263,   267,   296,   374,   382,
     389,   399,   446,   451,   456,    19,    20,   162,   254,   255,
     256,   155,   228,   229,   162,   185,   224,   225,    57,    63,
     379,   380,   162,   201,   213,   457,   447,   452,   138,   162,
     284,    34,    63,   131,   189,   199,   258,   259,   260,   261,
     284,   210,   210,   210,    36,     8,   400,    62,   370,   173,
     172,   175,   172,   224,    22,    57,   184,   196,   226,   162,
     210,   370,   379,   379,   379,   162,   138,   221,   260,   260,
     260,   199,   139,   140,   141,   172,   198,   390,    57,    63,
     268,   270,     5,     6,   396,    57,    63,   371,    15,    16,
     155,   160,   162,   165,   199,   216,   255,   155,   229,   162,
     162,   162,   381,    57,    63,   212,   162,   162,   162,   162,
     166,   219,   200,   256,   260,   260,   260,   260,   164,   233,
     234,    57,    63,   383,   271,    57,    63,   397,   204,   375,
     166,   167,   168,   215,    15,    16,   155,   160,   162,   216,
     252,   253,   226,   173,   163,   387,   388,   234,   234,   166,
     200,   164,   162,   384,    35,    71,    73,    75,    76,    77,
      78,    79,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    93,    94,    95,    98,    99,   100,   101,
     117,   118,   162,   266,   269,   401,   372,   202,   257,   343,
     166,   167,   168,   172,   200,    19,    25,    31,    41,    49,
      64,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   151,   201,   284,   404,   406,   407,
     410,   416,   417,   445,   163,   458,   448,   453,   175,   385,
      21,    22,    38,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   127,   128,   129,   132,   133,   134,   135,   136,   139,
     140,   141,   142,   143,   144,   145,   174,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   188,   189,   196,
     197,    35,    35,   199,   264,   234,   106,   394,   395,   205,
     210,   373,   255,   202,   162,   366,   369,   252,   179,   179,
     179,   199,   179,   179,   199,   179,   179,   179,   179,   179,
     179,   199,   284,    33,    60,    61,   123,   127,   174,   178,
     181,   197,   206,   415,   176,   204,   204,   204,    75,    79,
      93,    94,    98,    99,   100,   101,   405,   388,   162,   162,
     162,   198,    22,   162,   198,   150,   200,   343,   353,   354,
     175,   265,   275,   276,   162,   234,   343,   234,   255,   172,
     175,   178,   364,   418,   423,   425,     5,     6,    15,    16,
      17,    18,    19,    25,    27,    31,    39,    45,    48,    51,
      55,    65,    68,    69,    80,   102,   103,   104,   117,   118,
     146,   147,   148,   149,   150,   152,   154,   155,   156,   157,
     158,   159,   160,   161,   165,   181,   182,   183,   188,   189,
     197,   199,   201,   202,   204,   218,   220,   278,   284,   289,
     301,   308,   311,   314,   318,   320,   322,   323,   325,   330,
     333,   334,   341,   342,   404,   461,   469,   479,   482,   494,
     497,   427,   421,   162,   411,   429,   431,   433,   435,   437,
     439,   441,   443,   334,   179,   199,    33,   178,    33,   178,
     197,   206,   198,   334,   197,   206,   416,   459,   449,   454,
     204,   162,   132,   199,     7,    50,   295,   200,   203,   445,
     204,   175,   393,   402,   147,   162,   365,   368,   234,   162,
     416,   126,   132,   173,   363,   445,   445,   414,   445,   179,
     179,   179,   286,   406,   461,   284,   179,     5,   102,   103,
     179,   199,   179,   199,   199,   179,   179,   199,   179,   199,
     179,   199,   179,   179,   199,   179,   179,   334,   334,   199,
     199,   199,   199,   199,   199,   217,   334,   334,   334,   334,
     334,    13,    49,   312,   334,   312,   202,    13,   334,   478,
     493,   199,   197,   262,   202,   204,   314,   319,    21,    22,
     115,   116,   117,   118,   119,   122,   123,   124,   125,   127,
     128,   129,   130,   131,   133,   134,   139,   140,   141,   145,
     174,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   196,   197,   200,   199,   445,   445,   200,   162,   408,
     445,   264,   445,   264,   445,   264,   162,   355,   356,   445,
     162,   358,   359,   200,   420,   281,   312,   198,   198,   198,
     334,   162,   409,   355,   357,   358,   360,   391,   334,   147,
     162,   362,   403,   353,   280,   284,   203,   204,   398,   199,
      43,   172,   175,   364,   210,   363,   334,   180,   180,   180,
     163,   172,   209,   210,   413,   470,   472,   287,   199,   179,
     199,   309,   179,   179,   179,   489,   312,   416,   493,   334,
     302,   304,   334,   306,   334,   491,   312,   476,   480,   312,
     474,   416,   334,   334,   334,   334,   334,   334,   168,   169,
     215,   199,    13,   172,   496,   496,   147,   152,   179,   284,
     324,   199,   137,   172,   496,    70,   153,   162,   197,   200,
     312,   462,   464,   261,     4,   317,   202,   280,   262,    19,
     153,   162,   404,    19,   153,   162,   404,   334,   334,   334,
     334,   334,   334,   162,   334,   153,   162,   334,   334,   334,
     404,   334,   334,   334,   334,   334,   334,    22,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   128,
     129,   153,   162,   196,   197,   331,   404,   334,   200,   312,
     180,   180,   180,   203,   180,   265,   180,   265,   180,   265,
     175,   180,   413,   175,   180,   413,   283,   445,   200,   496,
     198,   209,   377,   386,   210,   239,   240,   239,   240,   162,
     376,   378,   200,   199,    43,   126,   172,   173,   175,   178,
     361,     1,    26,    28,    29,    38,    44,    52,    54,    58,
      59,    65,   105,   210,   230,   231,   238,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   277,   279,
     285,   290,   291,   292,   293,   294,   296,   300,   321,   334,
     349,   334,   162,   162,   416,   363,   334,   210,   419,   424,
     426,   445,   416,   416,   445,    70,   312,   464,   468,   162,
     334,   445,   483,   485,   487,   416,   496,   180,   413,   496,
     200,   416,   416,   200,   416,   200,   416,   496,   416,   416,
     496,   416,   180,   200,   200,   200,   200,   200,   200,   334,
     403,   199,   334,   198,   200,   199,   199,   326,   328,   403,
     334,   478,   205,   162,   200,   464,   199,   132,   361,   462,
     172,   200,   172,   200,   198,   199,   264,   205,   317,   179,
     199,   179,   199,   199,   199,   198,    19,   153,   162,   404,
     175,   153,   162,   334,   199,   199,   153,   162,   334,     1,
     199,   198,   172,   200,   428,   422,   412,   162,   430,   180,
     434,   180,   438,   180,   445,   442,   355,   445,   444,   358,
     180,   413,   162,   209,   460,   210,   355,   450,   358,   455,
     173,   377,   386,   334,   162,   162,   445,   334,   126,   334,
     275,    61,   334,   162,   210,   155,    58,   334,   234,   126,
     334,   210,   210,    10,    10,    11,   236,    13,     9,    42,
     210,   205,   210,   210,   210,   210,   210,    66,   297,   210,
     107,   108,   109,   110,   111,   112,   113,   114,   120,   121,
     126,   132,   135,   136,   142,   143,   144,   173,   164,   197,
     205,   263,   350,   200,    43,   210,   363,   334,   210,   180,
     180,   180,   464,   200,   200,   200,   180,   413,   200,   180,
     416,   416,   416,   180,   200,   199,   416,   200,   180,   180,
     180,   180,   200,   180,   180,   200,   180,   317,   199,   170,
      20,   403,   334,   334,   416,   264,    20,   200,   334,   334,
     334,   198,   197,   153,   162,   126,   132,   162,   173,   178,
     315,   316,   265,   264,   335,   334,   337,   334,   200,   312,
     334,   179,   199,   334,   199,   198,   334,   200,   312,   199,
     198,   332,   200,   312,   432,   436,   440,   199,   445,   205,
     205,   205,   334,   376,   392,   200,    43,   361,   334,    14,
     334,   173,   175,   155,   275,   334,   199,   199,   199,   199,
     199,    37,   272,   199,   204,   299,   368,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   261,     8,   343,   348,   162,
     334,   210,   471,   473,   288,   200,   199,   162,   310,   180,
     180,   180,   490,   282,   493,   180,   303,   305,   307,   492,
     477,   481,   475,   199,   234,   200,   312,   312,    20,   200,
     200,   180,   265,   312,   200,   200,   462,   199,   132,   361,
     162,   162,   199,   162,   162,   172,   200,   234,   265,   416,
     200,   445,   200,   200,   200,   339,   334,   334,   200,   200,
     334,   200,   281,   205,   162,   334,   275,   334,   334,   334,
     403,   334,   334,   273,   162,   298,   367,   198,    57,    63,
     346,    67,   347,   210,   210,   199,   199,   334,   180,   484,
     486,   488,   199,   200,   496,   199,   334,   334,   334,   199,
      70,   468,   199,   199,   200,   334,   275,   200,   200,   312,
     327,   180,   200,   132,   361,   198,   334,   334,   334,   162,
     315,   137,   275,   313,   234,   180,   180,   445,   200,   200,
     200,   200,   200,   200,    20,   200,   200,   204,   172,   200,
     205,   210,   368,    47,   347,    46,   106,   344,   468,   468,
     200,   199,   199,   199,   199,   281,   282,   312,   468,   462,
     463,   200,   203,   200,   324,   329,   203,   334,   334,   200,
     200,   200,   126,   334,   275,   336,   338,   180,    12,   237,
     234,   312,   234,   234,   280,   162,   175,   364,    33,   345,
     344,   346,   199,   462,   465,   466,   467,   467,   334,   468,
     468,   463,   200,   200,   496,   467,   200,   334,   203,   324,
     478,   132,   361,   334,   340,   238,   290,   291,   292,   293,
     334,   210,   275,   200,   275,   275,   274,   416,   363,   351,
     345,   362,   462,   172,   496,   200,   200,   200,   467,   467,
     200,   200,   200,   203,   495,   334,   495,   334,   334,    12,
      23,    24,   232,   235,   234,   205,   363,   334,   269,   352,
     200,   199,   200,   200,    53,   198,   495,   205,   234,   199,
     275,   334,   210,   210,   269,   462,   334,   198,   275,   334,
     210,   234,   200,   200,   275,   234,   275,   235
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   207,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   209,   209,   210,
     210,   211,   212,   212,   212,   213,   213,   214,   215,   215,
     215,   215,   216,   216,   217,   217,   217,   218,   219,   219,
     221,   220,   222,   223,   224,   224,   224,   224,   225,   225,
     226,   226,   227,   228,   228,   229,   229,   230,   231,   231,
     232,   232,   233,   233,   234,   234,   235,   235,   235,   236,
     236,   237,   237,   238,   238,   238,   238,   238,   239,   239,
     240,   240,   242,   241,   243,   245,   244,   246,   248,   247,
     250,   249,   251,   252,   252,   252,   252,   252,   252,   253,
     253,   254,   254,   254,   255,   255,   255,   255,   255,   255,
     255,   255,   256,   256,   257,   257,   258,   258,   258,   259,
     259,   260,   260,   260,   260,   260,   260,   260,   261,   261,
     262,   262,   263,   263,   264,   264,   264,   265,   265,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   267,   268,   268,   268,   269,   271,
     270,   272,   273,   274,   272,   276,   277,   275,   278,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   280,   280,
     280,   281,   281,   282,   282,   283,   283,   284,   284,   284,
     285,   285,   287,   288,   286,   286,   289,   289,   289,   289,
     289,   289,   290,   291,   292,   292,   292,   293,   293,   294,
     295,   295,   295,   296,   296,   297,   297,   298,   298,   299,
     299,   300,   300,   300,   302,   303,   301,   304,   305,   301,
     306,   307,   301,   309,   310,   308,   311,   311,   311,   312,
     312,   313,   313,   313,   314,   314,   314,   315,   315,   315,
     315,   315,   316,   316,   317,   317,   318,   319,   319,   320,
     320,   320,   320,   320,   320,   320,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   322,   322,   323,   323,   324,
     324,   325,   326,   327,   325,   328,   329,   325,   330,   330,
     330,   330,   330,   330,   331,   332,   330,   333,   333,   333,
     333,   333,   333,   333,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   335,
     336,   334,   334,   334,   334,   337,   338,   334,   334,   334,
     339,   340,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   341,   341,   341,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   343,   343,   344,   344,   344,
     345,   345,   346,   346,   346,   347,   347,   348,   349,   349,
     350,   349,   351,   349,   352,   349,   353,   353,   354,   354,
     355,   355,   356,   356,   357,   357,   357,   358,   359,   359,
     360,   360,   360,   361,   361,   362,   362,   362,   362,   362,
     363,   363,   363,   364,   364,   365,   365,   365,   365,   365,
     366,   366,   367,   367,   367,   368,   368,   368,   369,   369,
     369,   370,   370,   371,   371,   371,   372,   372,   373,   372,
     374,   375,   374,   376,   376,   377,   377,   378,   378,   378,
     379,   379,   379,   381,   380,   382,   383,   383,   383,   384,
     385,   385,   386,   386,   387,   387,   388,   388,   390,   391,
     392,   389,   393,   393,   394,   394,   395,   396,   396,   397,
     397,   397,   398,   398,   400,   401,   402,   399,   403,   403,
     403,   403,   403,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     405,   405,   405,   405,   405,   405,   405,   405,   406,   407,
     407,   407,   408,   408,   409,   409,   409,   411,   412,   410,
     413,   413,   414,   414,   415,   415,   415,   415,   416,   416,
     417,   417,   417,   417,   418,   419,   417,   417,   417,   420,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   421,   422,   417,   417,   423,   424,   417,
     425,   426,   417,   427,   428,   417,   417,   429,   430,   417,
     431,   432,   417,   417,   433,   434,   417,   435,   436,   417,
     417,   437,   438,   417,   439,   440,   417,   441,   442,   417,
     443,   444,   417,   445,   445,   445,   447,   448,   449,   450,
     446,   452,   453,   454,   455,   451,   457,   458,   459,   460,
     456,   461,   461,   461,   461,   461,   462,   462,   462,   462,
     462,   462,   462,   462,   463,   464,   465,   465,   466,   466,
     467,   467,   468,   468,   470,   471,   469,   472,   473,   469,
     474,   475,   469,   476,   477,   469,   478,   478,   479,   480,
     481,   479,   482,   483,   484,   482,   485,   486,   482,   487,
     488,   482,   482,   489,   490,   482,   482,   491,   492,   482,
     493,   493,   494,   494,   494,   494,   495,   495,   496,   496,
     497,   497,   497
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     3,
       3,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     2,     0,     1,     1,     1,     1,     4,     1,     1,
       2,     2,     3,     2,     0,     2,     4,     3,     1,     2,
       0,     4,     2,     2,     1,     2,     3,     3,     2,     4,
       0,     1,     2,     1,     3,     1,     3,     3,     3,     2,
       1,     1,     1,     2,     0,     1,     0,     3,     7,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     0,     8,     7,     0,     9,     3,     0,     7,
       0,     7,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     5,     1,     3,     3,     4,     1,     1,     1,     1,
       4,     1,     2,     3,     3,     3,     3,     2,     1,     3,
       0,     3,     0,     4,     0,     2,     3,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     2,     2,     3,     4,     3,
       2,     2,     2,     2,     2,     3,     3,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     3,     0,
       5,     0,     0,     0,     6,     0,     0,     6,     2,     1,
       2,     2,     1,     1,     1,     1,     2,     1,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     0,     2,
       2,     0,     2,     0,     2,     1,     3,     1,     3,     2,
       2,     3,     0,     0,     5,     1,     2,     5,     5,     5,
       6,     2,     1,     1,     1,     2,     3,     2,     3,     4,
       1,     1,     0,     1,     1,     1,     0,     1,     3,     8,
       7,     3,     3,     5,     0,     0,     7,     0,     0,     7,
       0,     0,     7,     0,     0,     6,     5,     8,    10,     1,
       3,     1,     2,     3,     1,     1,     2,     2,     2,     2,
       2,     4,     1,     3,     0,     4,     7,     7,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     8,     5,     6,     1,
       4,     3,     0,     0,     8,     0,     0,     9,     3,     4,
       5,     6,     5,     6,     0,     0,     5,     3,     4,     4,
       5,     4,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     4,     4,     5,     4,     5,     3,
       4,     1,     1,     2,     4,     4,     1,     3,     5,     0,
       0,     8,     3,     3,     3,     0,     0,     8,     3,     4,
       0,     0,     9,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     4,     7,     8,     7,     4,
       4,     4,     4,     4,     1,     6,     7,     6,     6,     7,
       7,     6,     7,     6,     6,     0,     1,     0,     1,     1,
       0,     1,     0,     1,     1,     0,     1,     5,     0,     2,
       0,     4,     0,     9,     0,    11,     3,     4,     1,     3,
       1,     3,     1,     3,     0,     1,     3,     3,     1,     3,
       0,     1,     3,     1,     1,     1,     2,     3,     5,     3,
       1,     1,     1,     0,     1,     1,     4,     3,     3,     5,
       1,     3,     0,     2,     2,     4,     6,     5,     4,     6,
       5,     0,     1,     0,     1,     1,     0,     2,     0,     4,
       6,     0,     6,     1,     3,     1,     2,     0,     1,     3,
       0,     1,     1,     0,     5,     3,     0,     1,     1,     1,
       0,     2,     0,     1,     1,     2,     0,     1,     0,     0,
       0,    13,     0,     2,     0,     1,     3,     1,     1,     0,
       1,     1,     1,     3,     0,     0,     0,     9,     1,     4,
       3,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     3,     0,     1,     3,     0,     0,     6,
       1,     1,     1,     3,     3,     2,     4,     3,     1,     2,
       1,     1,     1,     1,     0,     0,     6,     4,     5,     0,
       9,     4,     2,     2,     3,     2,     3,     2,     2,     3,
       3,     3,     2,     0,     0,     6,     2,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     1,     0,     0,     6,
       0,     0,     7,     1,     0,     0,     6,     0,     0,     7,
       1,     0,     0,     6,     0,     0,     7,     0,     0,     6,
       0,     0,     6,     1,     3,     3,     0,     0,     0,     0,
      12,     0,     0,     0,     0,    12,     0,     0,     0,     0,
      12,     1,     1,     1,     1,     1,     3,     3,     5,     5,
       6,     6,     8,     8,     1,     1,     3,     5,     1,     2,
       1,     0,     0,     1,     0,     0,    10,     0,     0,    10,
       0,     0,     9,     0,     0,     7,     3,     1,     5,     0,
       0,    10,     4,     0,     0,    11,     0,     0,    11,     0,
       0,    10,     5,     0,     0,     9,     5,     0,     0,    10,
       1,     3,     4,     5,     7,     9,     0,     3,     0,     1,
      11,    12,    11
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = DAS2_YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == DAS2_YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use DAS2_YYerror or DAS2_YYUNDEF. */
#define YYERRCODE DAS2_YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if DAS2_YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined DAS2_YYLTYPE_IS_TRIVIAL && DAS2_YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, yyscan_t scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !DAS2_YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !DAS2_YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_NAME: /* "name"  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_module_name: /* module_name  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_character_sequence: /* character_sequence  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_string_constant: /* string_constant  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_string_builder_body: /* string_builder_body  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_string_builder: /* string_builder  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_reader: /* expr_reader  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_require_module_name: /* require_module_name  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_expression_label: /* expression_label  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_goto: /* expression_goto  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_else: /* expression_else  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_else_one_liner: /* expression_else_one_liner  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_if_one_liner: /* expression_if_one_liner  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_if_then_else: /* expression_if_then_else  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_if_then_else_oneliner: /* expression_if_then_else_oneliner  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_for_loop: /* expression_for_loop  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_unsafe: /* expression_unsafe  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_while_loop: /* expression_while_loop  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_with: /* expression_with  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_with_alias: /* expression_with_alias  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_annotation_argument_value: /* annotation_argument_value  */
            { delete ((*yyvaluep).aa); }
        break;

    case YYSYMBOL_annotation_argument_value_list: /* annotation_argument_value_list  */
            { delete ((*yyvaluep).aaList); }
        break;

    case YYSYMBOL_annotation_argument_name: /* annotation_argument_name  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_annotation_argument: /* annotation_argument  */
            { delete ((*yyvaluep).aa); }
        break;

    case YYSYMBOL_annotation_argument_list: /* annotation_argument_list  */
            { delete ((*yyvaluep).aaList); }
        break;

    case YYSYMBOL_metadata_argument_list: /* metadata_argument_list  */
            { delete ((*yyvaluep).aaList); }
        break;

    case YYSYMBOL_annotation_declaration_name: /* annotation_declaration_name  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_annotation_declaration_basic: /* annotation_declaration_basic  */
            { delete ((*yyvaluep).fa); }
        break;

    case YYSYMBOL_annotation_declaration: /* annotation_declaration  */
            { delete ((*yyvaluep).fa); }
        break;

    case YYSYMBOL_annotation_list: /* annotation_list  */
            { delete ((*yyvaluep).faList); }
        break;

    case YYSYMBOL_optional_annotation_list: /* optional_annotation_list  */
            { delete ((*yyvaluep).faList); }
        break;

    case YYSYMBOL_optional_annotation_list_with_emit_semis: /* optional_annotation_list_with_emit_semis  */
            { delete ((*yyvaluep).faList); }
        break;

    case YYSYMBOL_optional_function_argument_list: /* optional_function_argument_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_optional_function_type: /* optional_function_type  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_function_name: /* function_name  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_function_declaration_header: /* function_declaration_header  */
            { ((*yyvaluep).pFuncDecl)->delRef(); }
        break;

    case YYSYMBOL_function_declaration: /* function_declaration  */
            { ((*yyvaluep).pFuncDecl)->delRef(); }
        break;

    case YYSYMBOL_expression_block_finally: /* expression_block_finally  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_block: /* expression_block  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_call_pipe: /* expr_call_pipe  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_any: /* expression_any  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expressions: /* expressions  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_optional_expr_list: /* optional_expr_list  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_optional_expr_map_tuple_list: /* optional_expr_map_tuple_list  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_type_declaration_no_options_list: /* type_declaration_no_options_list  */
            { deleteTypeDeclarationList(((*yyvaluep).pTypeDeclList)); }
        break;

    case YYSYMBOL_name_in_namespace: /* name_in_namespace  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_expression_delete: /* expression_delete  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_new_type_declaration: /* new_type_declaration  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_expr_new: /* expr_new  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_break: /* expression_break  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_continue: /* expression_continue  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_return: /* expression_return  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_yield: /* expression_yield  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expression_try_catch: /* expression_try_catch  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_tuple_expansion: /* tuple_expansion  */
            { delete ((*yyvaluep).pNameList); }
        break;

    case YYSYMBOL_tuple_expansion_variable_declaration: /* tuple_expansion_variable_declaration  */
            { delete ((*yyvaluep).pVarDecl); }
        break;

    case YYSYMBOL_expression_let: /* expression_let  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_cast: /* expr_cast  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_type_decl: /* expr_type_decl  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_type_info: /* expr_type_info  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_list: /* expr_list  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_block_or_simple_block: /* block_or_simple_block  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_capture_entry: /* capture_entry  */
            { delete ((*yyvaluep).pCapt); }
        break;

    case YYSYMBOL_capture_list: /* capture_list  */
            { delete ((*yyvaluep).pCaptList); }
        break;

    case YYSYMBOL_optional_capture_list: /* optional_capture_list  */
            { delete ((*yyvaluep).pCaptList); }
        break;

    case YYSYMBOL_expr_full_block: /* expr_full_block  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_full_block_assumed_piped: /* expr_full_block_assumed_piped  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_numeric_const: /* expr_numeric_const  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_assign: /* expr_assign  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_named_call: /* expr_named_call  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_method_call: /* expr_method_call  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_func_addr_name: /* func_addr_name  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_func_addr_expr: /* func_addr_expr  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_field: /* expr_field  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_call: /* expr_call  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr: /* expr  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_generator: /* expr_generator  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_mtag: /* expr_mtag  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_optional_field_annotation: /* optional_field_annotation  */
            { delete ((*yyvaluep).aaList); }
        break;

    case YYSYMBOL_structure_variable_declaration: /* structure_variable_declaration  */
            { delete ((*yyvaluep).pVarDecl); }
        break;

    case YYSYMBOL_struct_variable_declaration_list: /* struct_variable_declaration_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_function_argument_declaration: /* function_argument_declaration  */
            { delete ((*yyvaluep).pVarDecl); }
        break;

    case YYSYMBOL_function_argument_list: /* function_argument_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_tuple_type: /* tuple_type  */
            { delete ((*yyvaluep).pVarDecl); }
        break;

    case YYSYMBOL_tuple_type_list: /* tuple_type_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_tuple_alias_type_list: /* tuple_alias_type_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_variant_type: /* variant_type  */
            { delete ((*yyvaluep).pVarDecl); }
        break;

    case YYSYMBOL_variant_type_list: /* variant_type_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_variant_alias_type_list: /* variant_alias_type_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_variable_declaration: /* variable_declaration  */
            { delete ((*yyvaluep).pVarDecl); }
        break;

    case YYSYMBOL_let_variable_name_with_pos_list: /* let_variable_name_with_pos_list  */
            { delete ((*yyvaluep).pNameWithPosList); }
        break;

    case YYSYMBOL_global_let_variable_name_with_pos_list: /* global_let_variable_name_with_pos_list  */
            { delete ((*yyvaluep).pNameWithPosList); }
        break;

    case YYSYMBOL_variable_declaration_list: /* variable_declaration_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_let_variable_declaration: /* let_variable_declaration  */
            { delete ((*yyvaluep).pVarDecl); }
        break;

    case YYSYMBOL_global_let_variable_declaration: /* global_let_variable_declaration  */
            { delete ((*yyvaluep).pVarDecl); }
        break;

    case YYSYMBOL_global_variable_declaration_list: /* global_variable_declaration_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_enum_expression: /* enum_expression  */
            { delete ((*yyvaluep).pEnumPair); }
        break;

    case YYSYMBOL_enum_list: /* enum_list  */
            { if ( ((*yyvaluep).pEnum)->use_count()==1 ) delete ((*yyvaluep).pEnum); }
        break;

    case YYSYMBOL_enum_name: /* enum_name  */
            { if ( ((*yyvaluep).pEnum)->use_count()==1 ) delete ((*yyvaluep).pEnum); }
        break;

    case YYSYMBOL_optional_structure_parent: /* optional_structure_parent  */
            { delete ((*yyvaluep).s); }
        break;

    case YYSYMBOL_optional_struct_variable_declaration_list: /* optional_struct_variable_declaration_list  */
            { deleteVariableDeclarationList(((*yyvaluep).pVarDeclList)); }
        break;

    case YYSYMBOL_variable_name_with_pos_list: /* variable_name_with_pos_list  */
            { delete ((*yyvaluep).pNameWithPosList); }
        break;

    case YYSYMBOL_structure_type_declaration: /* structure_type_declaration  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_auto_type_declaration: /* auto_type_declaration  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_bitfield_bits: /* bitfield_bits  */
            { delete ((*yyvaluep).pNameList); }
        break;

    case YYSYMBOL_bitfield_alias_bits: /* bitfield_alias_bits  */
            { delete ((*yyvaluep).pNameList); }
        break;

    case YYSYMBOL_bitfield_type_declaration: /* bitfield_type_declaration  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_table_type_pair: /* table_type_pair  */
            { delete ((*yyvaluep).aTypePair).firstType; delete ((*yyvaluep).aTypePair).secondType; }
        break;

    case YYSYMBOL_dim_list: /* dim_list  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_type_declaration_no_options: /* type_declaration_no_options  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_type_declaration_no_options_no_dim: /* type_declaration_no_options_no_dim  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_type_declaration: /* type_declaration  */
            { delete ((*yyvaluep).pTypeDecl); }
        break;

    case YYSYMBOL_make_decl: /* make_decl  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_struct_fields: /* make_struct_fields  */
            { delete ((*yyvaluep).pMakeStruct); }
        break;

    case YYSYMBOL_make_variant_dim: /* make_variant_dim  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_struct_single: /* make_struct_single  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_struct_dim_list: /* make_struct_dim_list  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_struct_dim_decl: /* make_struct_dim_decl  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_optional_make_struct_dim_decl: /* optional_make_struct_dim_decl  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_struct_decl: /* make_struct_decl  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_map_tuple: /* make_map_tuple  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_tuple_call: /* make_tuple_call  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_dim_decl: /* make_dim_decl  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_expr_map_tuple_list: /* expr_map_tuple_list  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_make_table_decl: /* make_table_decl  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_array_comprehension_where: /* array_comprehension_where  */
            { delete ((*yyvaluep).pExpression); }
        break;

    case YYSYMBOL_array_comprehension: /* array_comprehension  */
            { delete ((*yyvaluep).pExpression); }
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined DAS2_YYLTYPE_IS_TRIVIAL && DAS2_YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = DAS2_YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == DAS2_YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= DAS2_YYEOF)
    {
      yychar = DAS2_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == DAS2_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = DAS2_YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = DAS2_YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* program: program module_declaration  */
                                   {
            if ( yyextra->das_has_type_declarations ) {
                das2_yyerror(scanner,"module name has to be first declaration",tokAt(scanner,(yylsp[0])), CompilationError::syntax_error);
            }
        }
    break;

  case 4: /* program: program structure_declaration  */
                                                { yyextra->das_has_type_declarations = true; }
    break;

  case 5: /* program: program enum_declaration  */
                                                { yyextra->das_has_type_declarations = true; }
    break;

  case 6: /* program: program global_let  */
                                                { yyextra->das_has_type_declarations = true; }
    break;

  case 7: /* program: program global_function_declaration  */
                                                { yyextra->das_has_type_declarations = true; }
    break;

  case 11: /* program: program alias_declaration  */
                                                { yyextra->das_has_type_declarations = true; }
    break;

  case 12: /* program: program variant_alias_declaration  */
                                                { yyextra->das_has_type_declarations = true; }
    break;

  case 13: /* program: program tuple_alias_declaration  */
                                                { yyextra->das_has_type_declarations = true; }
    break;

  case 14: /* program: program bitfield_alias_declaration  */
                                                { yyextra->das_has_type_declarations = true; }
    break;

  case 21: /* top_level_reader_macro: expr_reader SEMICOLON  */
                                   {
        delete (yyvsp[-1].pExpression);    // we do nothing, we don't even attemp to 'visit'
    }
    break;

  case 22: /* optional_public_or_private_module: %empty  */
                        { (yyval.b) = yyextra->g_Program->policies.default_module_public; }
    break;

  case 23: /* optional_public_or_private_module: "public"  */
                        { (yyval.b) = true; }
    break;

  case 24: /* optional_public_or_private_module: "private"  */
                        { (yyval.b) = false; }
    break;

  case 25: /* module_name: '$'  */
                    { (yyval.s) = new string("$"); }
    break;

  case 26: /* module_name: "name"  */
                    { (yyval.s) = (yyvsp[0].s); }
    break;

  case 27: /* module_declaration: "module" module_name optional_shared optional_public_or_private_module  */
                                                                                                      {
        yyextra->g_Program->thisModuleName = *(yyvsp[-2].s);
        yyextra->g_Program->thisModule->isPublic = (yyvsp[0].b);
        yyextra->g_Program->thisModule->isModule = true;
        if ( yyextra->g_Program->thisModule->name.empty() ) {
            yyextra->g_Program->thisModule->name = *(yyvsp[-2].s);
        } else if ( yyextra->g_Program->thisModule->name != *(yyvsp[-2].s) ){
            das2_yyerror(scanner,"this module already has a name " + yyextra->g_Program->thisModule->name,tokAt(scanner,(yylsp[-2])),
                CompilationError::module_already_has_a_name);
        }
        if ( !yyextra->g_Program->policies.ignore_shared_modules ) {
            yyextra->g_Program->promoteToBuiltin = (yyvsp[-1].b);
        }
        delete (yyvsp[-2].s);
    }
    break;

  case 28: /* character_sequence: STRING_CHARACTER  */
                                                                                  { (yyval.s) = new string(); *(yyval.s) += (yyvsp[0].ch); }
    break;

  case 29: /* character_sequence: STRING_CHARACTER_ESC  */
                                                                                  { (yyval.s) = new string(); *(yyval.s) += "\\\\"; }
    break;

  case 30: /* character_sequence: character_sequence STRING_CHARACTER  */
                                                                                  { (yyval.s) = (yyvsp[-1].s); *(yyvsp[-1].s) += (yyvsp[0].ch); }
    break;

  case 31: /* character_sequence: character_sequence STRING_CHARACTER_ESC  */
                                                                                  { (yyval.s) = (yyvsp[-1].s); *(yyvsp[-1].s) += "\\\\"; }
    break;

  case 32: /* string_constant: "start of the string" character_sequence "end of the string"  */
                                                           { (yyval.s) = (yyvsp[-1].s); }
    break;

  case 33: /* string_constant: "start of the string" "end of the string"  */
                                                           { (yyval.s) = new string(); }
    break;

  case 34: /* string_builder_body: %empty  */
        {
        (yyval.pExpression) = new ExprStringBuilder();
        (yyval.pExpression)->at = LineInfo(yyextra->g_FileAccessStack.back(),
            yylloc.first_column,yylloc.first_line,yylloc.last_column,yylloc.last_line);
    }
    break;

  case 35: /* string_builder_body: string_builder_body character_sequence  */
                                                                                  {
        bool err;
        auto esconst = unescapeString(*(yyvsp[0].s),&err);
        if ( err ) das2_yyerror(scanner,"invalid escape sequence",tokAt(scanner,(yylsp[-1])), CompilationError::invalid_escape_sequence);
        auto sc = make_smart<ExprConstString>(tokAt(scanner,(yylsp[0])),esconst);
        delete (yyvsp[0].s);
        static_cast<ExprStringBuilder *>((yyvsp[-1].pExpression))->elements.push_back(sc);
        (yyval.pExpression) = (yyvsp[-1].pExpression);
    }
    break;

  case 36: /* string_builder_body: string_builder_body "{" expr "}"  */
                                                                                                        {
        auto se = ExpressionPtr((yyvsp[-1].pExpression));
        static_cast<ExprStringBuilder *>((yyvsp[-3].pExpression))->elements.push_back(se);
        (yyval.pExpression) = (yyvsp[-3].pExpression);
    }
    break;

  case 37: /* string_builder: "start of the string" string_builder_body "end of the string"  */
                                                                   {
        auto strb = static_cast<ExprStringBuilder *>((yyvsp[-1].pExpression));
        if ( strb->elements.size()==0 ) {
            (yyval.pExpression) = new ExprConstString(tokRangeAt(scanner,(yylsp[-2]),(yylsp[0])),"");
            delete (yyvsp[-1].pExpression);
        } else if ( strb->elements.size()==1 && strb->elements[0]->rtti_isStringConstant() ) {
            auto sconst = static_pointer_cast<ExprConstString>(strb->elements[0]);
            (yyval.pExpression) = new ExprConstString(tokRangeAt(scanner,(yylsp[-2]),(yylsp[0])),sconst->text);
            delete (yyvsp[-1].pExpression);
        } else {
            (yyval.pExpression) = (yyvsp[-1].pExpression);
        }
    }
    break;

  case 38: /* reader_character_sequence: STRING_CHARACTER  */
                               {
        if ( !yyextra->g_ReaderMacro->accept(yyextra->g_Program.get(), yyextra->g_Program->thisModule.get(), yyextra->g_ReaderExpr, (yyvsp[0].ch), tokAt(scanner,(yylsp[0]))) ) {
            das2_yyend_reader(scanner);
        }
    }
    break;

  case 39: /* reader_character_sequence: reader_character_sequence STRING_CHARACTER  */
                                                                {
        if ( !yyextra->g_ReaderMacro->accept(yyextra->g_Program.get(), yyextra->g_Program->thisModule.get(), yyextra->g_ReaderExpr, (yyvsp[0].ch), tokAt(scanner,(yylsp[0]))) ) {
            das2_yyend_reader(scanner);
        }
    }
    break;

  case 40: /* $@1: %empty  */
                                        {
        auto macros = yyextra->g_Program->getReaderMacro(*(yyvsp[0].s));
        if ( macros.size()==0 ) {
            das2_yyerror(scanner,"reader macro " + *(yyvsp[0].s) + " not found",tokAt(scanner,(yylsp[0])),
                CompilationError::unsupported_read_macro);
        } else if ( macros.size()>1 ) {
            string options;
            for ( auto & x : macros ) {
                options += "\t" + x->module->name + "::" + x->name + "\n";
            }
            das2_yyerror(scanner,"too many options for the reader macro " + *(yyvsp[0].s) +  "\n" + options, tokAt(scanner,(yylsp[0])),
                CompilationError::unsupported_read_macro);
        } else if ( yychar != '~' ) {
            das2_yyerror(scanner,"expecting ~ after the reader macro", tokAt(scanner,(yylsp[0])),
                CompilationError::syntax_error);
        } else {
            yyextra->g_ReaderMacro = macros.back().get();
            yyextra->g_ReaderExpr = new ExprReader(tokAt(scanner,(yylsp[-1])),yyextra->g_ReaderMacro);
            yyclearin ;
            das2_yybegin_reader(scanner);
        }
    }
    break;

  case 41: /* expr_reader: '%' name_in_namespace $@1 reader_character_sequence  */
                                     {
        yyextra->g_ReaderExpr->at = tokRangeAt(scanner,(yylsp[-3]),(yylsp[0]));
        (yyval.pExpression) = yyextra->g_ReaderExpr;
        int thisLine = 0;
        FileInfo * info = nullptr;
        if ( auto seqt = yyextra->g_ReaderMacro->suffix(yyextra->g_Program.get(), yyextra->g_Program->thisModule.get(), yyextra->g_ReaderExpr, thisLine, info, tokAt(scanner,(yylsp[0]))) ) {
            das2_accept_sequence(scanner,seqt,strlen(seqt),thisLine,info);
            yylloc.first_column = (yylsp[0]).first_column;
            yylloc.first_line = (yylsp[0]).first_line;
            yylloc.last_column = (yylsp[0]).last_column;
            yylloc.last_line = (yylsp[0]).last_line;
        }
        delete (yyvsp[-2].s);
        yyextra->g_ReaderMacro = nullptr;
        yyextra->g_ReaderExpr = nullptr;
    }
    break;

  case 42: /* options_declaration: "options" annotation_argument_list  */
                                                   {
        if ( yyextra->g_Program->options.size() ) {
            for ( auto & opt : *(yyvsp[0].aaList) ) {
                if ( yyextra->g_Access->isOptionAllowed(opt.name, yyextra->g_Program->thisModuleName) ) {
                    yyextra->g_Program->options.push_back(opt);
                } else {
                    das2_yyerror(scanner,"option " + opt.name + " is not allowed here",
                        tokAt(scanner,(yylsp[0])), CompilationError::invalid_option);
                }
            }
        } else {
            swap ( yyextra->g_Program->options, *(yyvsp[0].aaList) );
        }
        delete (yyvsp[0].aaList);
    }
    break;

  case 44: /* require_module_name: "name"  */
                   {
        (yyval.s) = (yyvsp[0].s);
    }
    break;

  case 45: /* require_module_name: '%' require_module_name  */
                                     {
        *(yyvsp[0].s) = "%" + *(yyvsp[0].s);
        (yyval.s) = (yyvsp[0].s);
    }
    break;

  case 46: /* require_module_name: require_module_name '.' "name"  */
                                                {
        *(yyvsp[-2].s) += ".";
        *(yyvsp[-2].s) += *(yyvsp[0].s);
        delete (yyvsp[0].s);
        (yyval.s) = (yyvsp[-2].s);
    }
    break;

  case 47: /* require_module_name: require_module_name '/' "name"  */
                                                {
        *(yyvsp[-2].s) += "/";
        *(yyvsp[-2].s) += *(yyvsp[0].s);
        delete (yyvsp[0].s);
        (yyval.s) = (yyvsp[-2].s);
    }
    break;

  case 48: /* require_module: require_module_name is_public_module  */
                                                         {
        ast_requireModule(scanner,(yyvsp[-1].s),nullptr,(yyvsp[0].b),tokAt(scanner,(yylsp[-1])));
    }
    break;

  case 49: /* require_module: require_module_name "as" "name" is_public_module  */
                                                                              {
        ast_requireModule(scanner,(yyvsp[-3].s),(yyvsp[-1].s),(yyvsp[0].b),tokAt(scanner,(yylsp[-3])));
    }
    break;

  case 50: /* is_public_module: %empty  */
                    { (yyval.b) = false; }
    break;

  case 51: /* is_public_module: "public"  */
                    { (yyval.b) = true; }
    break;

  case 55: /* expect_error: "integer constant"  */
                   {
        yyextra->g_Program->expectErrors[CompilationError((yyvsp[0].i))] ++;
    }
    break;

  case 56: /* expect_error: "integer constant" ':' "integer constant"  */
                                      {
        yyextra->g_Program->expectErrors[CompilationError((yyvsp[-2].i))] += (yyvsp[0].i);
    }
    break;

  case 57: /* expression_label: "label" "integer constant" ':'  */
                                          {
        (yyval.pExpression) = new ExprLabel(tokAt(scanner,(yylsp[-2])),(yyvsp[-1].i));
    }
    break;

  case 58: /* expression_goto: "goto" "label" "integer constant"  */
                                                {
        (yyval.pExpression) = new ExprGoto(tokAt(scanner,(yylsp[-2])),(yyvsp[0].i));
    }
    break;

  case 59: /* expression_goto: "goto" expr  */
                               {
        (yyval.pExpression) = new ExprGoto(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[0].pExpression)));
    }
    break;

  case 60: /* elif_or_static_elif: "elif"  */
                          { (yyval.b) = false; }
    break;

  case 61: /* elif_or_static_elif: "static_elif"  */
                          { (yyval.b) = true; }
    break;

  case 66: /* expression_else: %empty  */
                                                           { (yyval.pExpression) = nullptr; }
    break;

  case 67: /* expression_else: "else" optional_emit_semis expression_block  */
                                                                { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 68: /* expression_else: elif_or_static_elif '(' expr ')' optional_emit_semis expression_block expression_else  */
                                                                                                                      {
        auto eite = new ExprIfThenElse(tokAt(scanner,(yylsp[-6])),ExpressionPtr((yyvsp[-4].pExpression)),
            ExpressionPtr((yyvsp[-1].pExpression)),ExpressionPtr((yyvsp[0].pExpression)));
        eite->isStatic = (yyvsp[-6].b);
        (yyval.pExpression) = eite;
    }
    break;

  case 69: /* if_or_static_if: "if"  */
                        { (yyval.b) = false; }
    break;

  case 70: /* if_or_static_if: "static_if"  */
                        { (yyval.b) = true; }
    break;

  case 71: /* expression_else_one_liner: %empty  */
        { (yyval.pExpression) = nullptr; }
    break;

  case 72: /* expression_else_one_liner: "else" expression_if_one_liner  */
                                                      {
            (yyval.pExpression) = (yyvsp[0].pExpression);
    }
    break;

  case 73: /* expression_if_one_liner: expr  */
                                            { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 74: /* expression_if_one_liner: expression_return  */
                                            { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 75: /* expression_if_one_liner: expression_yield  */
                                            { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 76: /* expression_if_one_liner: expression_break  */
                                            { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 77: /* expression_if_one_liner: expression_continue  */
                                            { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 82: /* $@2: %empty  */
        {
        yyextra->das_keyword = true;
    }
    break;

  case 83: /* expression_if_then_else: $@2 if_or_static_if '(' expr ')' optional_emit_semis expression_block expression_else  */
                                                                                                                {
        yyextra->das_keyword = false;
        auto eite = new ExprIfThenElse(tokAt(scanner,(yylsp[-6])),ExpressionPtr((yyvsp[-4].pExpression)),
            ExpressionPtr((yyvsp[-1].pExpression)),ExpressionPtr((yyvsp[0].pExpression)));
        eite->isStatic = (yyvsp[-6].b);
        (yyval.pExpression) = eite;
    }
    break;

  case 84: /* expression_if_then_else_oneliner: expression_if_one_liner "if" '(' expr ')' expression_else_one_liner SEMICOLON  */
                                                                                                                      {
        (yyval.pExpression) = new ExprIfThenElse(tokAt(scanner,(yylsp[-5])),ExpressionPtr((yyvsp[-3].pExpression)),ExpressionPtr(ast_wrapInBlock((yyvsp[-6].pExpression))),(yyvsp[-1].pExpression) ? ExpressionPtr(ast_wrapInBlock((yyvsp[-1].pExpression))) : nullptr);
    }
    break;

  case 85: /* $@3: %empty  */
        {
        yyextra->das_keyword = true;
    }
    break;

  case 86: /* expression_for_loop: $@3 "for" '(' variable_name_with_pos_list "in" expr_list ')' optional_emit_semis expression_block  */
                                                                                                                                 {
        yyextra->das_keyword = false;
        (yyval.pExpression) = ast_forLoop(scanner,(yyvsp[-5].pNameWithPosList),(yyvsp[-3].pExpression),(yyvsp[0].pExpression),tokAt(scanner,(yylsp[-7])),tokAt(scanner,(yylsp[0])));
    }
    break;

  case 87: /* expression_unsafe: "unsafe" optional_emit_semis expression_block  */
                                                                    {
        auto pUnsafe = new ExprUnsafe(tokAt(scanner,(yylsp[-2])));
        pUnsafe->body = ExpressionPtr((yyvsp[0].pExpression));
        (yyval.pExpression) = pUnsafe;
    }
    break;

  case 88: /* $@4: %empty  */
        {
        yyextra->das_keyword = true;
    }
    break;

  case 89: /* expression_while_loop: $@4 "while" '(' expr ')' optional_emit_semis expression_block  */
                                                                                         {
        yyextra->das_keyword = false;
        auto pWhile = new ExprWhile(tokAt(scanner,(yylsp[-5])));
        pWhile->cond = ExpressionPtr((yyvsp[-3].pExpression));
        pWhile->body = ExpressionPtr((yyvsp[0].pExpression));
        ((ExprBlock *)(yyvsp[0].pExpression))->inTheLoop = true;
        (yyval.pExpression) = pWhile;
    }
    break;

  case 90: /* $@5: %empty  */
        {
        yyextra->das_keyword = true;
    }
    break;

  case 91: /* expression_with: $@5 "with" '(' expr ')' optional_emit_semis expression_block  */
                                                                                   {
        yyextra->das_keyword = false;
        auto pWith = new ExprWith(tokAt(scanner,(yylsp[-5])));
        pWith->with = ExpressionPtr((yyvsp[-3].pExpression));
        pWith->body = ExpressionPtr((yyvsp[0].pExpression));
        (yyval.pExpression) = pWith;
    }
    break;

  case 92: /* expression_with_alias: "assume" "name" '=' expr  */
                                                      {
        (yyval.pExpression) = new ExprAssume(tokAt(scanner,(yylsp[-3])), *(yyvsp[-2].s), (yyvsp[0].pExpression) );
        delete (yyvsp[-2].s);
    }
    break;

  case 93: /* annotation_argument_value: string_constant  */
                                 { (yyval.aa) = new AnnotationArgument("",*(yyvsp[0].s)); delete (yyvsp[0].s); }
    break;

  case 94: /* annotation_argument_value: "name"  */
                                 { (yyval.aa) = new AnnotationArgument("",*(yyvsp[0].s)); delete (yyvsp[0].s); }
    break;

  case 95: /* annotation_argument_value: "integer constant"  */
                                 { (yyval.aa) = new AnnotationArgument("",(yyvsp[0].i)); }
    break;

  case 96: /* annotation_argument_value: "floating point constant"  */
                                 { (yyval.aa) = new AnnotationArgument("",float((yyvsp[0].fd))); }
    break;

  case 97: /* annotation_argument_value: "true"  */
                                 { (yyval.aa) = new AnnotationArgument("",true); }
    break;

  case 98: /* annotation_argument_value: "false"  */
                                 { (yyval.aa) = new AnnotationArgument("",false); }
    break;

  case 99: /* annotation_argument_value_list: annotation_argument_value  */
                                       {
        (yyval.aaList) = new AnnotationArgumentList();
        (yyval.aaList)->push_back(*(yyvsp[0].aa));
        delete (yyvsp[0].aa);
    }
    break;

  case 100: /* annotation_argument_value_list: annotation_argument_value_list ',' annotation_argument_value  */
                                                                                {
            (yyval.aaList) = (yyvsp[-2].aaList);
            (yyval.aaList)->push_back(*(yyvsp[0].aa));
            delete (yyvsp[0].aa);
    }
    break;

  case 101: /* annotation_argument_name: "name"  */
                    { (yyval.s) = (yyvsp[0].s); }
    break;

  case 102: /* annotation_argument_name: "type"  */
                    { (yyval.s) = new string("type"); }
    break;

  case 103: /* annotation_argument_name: "in"  */
                    { (yyval.s) = new string("in"); }
    break;

  case 104: /* annotation_argument: annotation_argument_name '=' string_constant  */
                                                                    { (yyval.aa) = new AnnotationArgument(*(yyvsp[-2].s),*(yyvsp[0].s),tokAt(scanner,(yylsp[-2]))); delete (yyvsp[0].s); delete (yyvsp[-2].s); }
    break;

  case 105: /* annotation_argument: annotation_argument_name '=' "name"  */
                                                                    { (yyval.aa) = new AnnotationArgument(*(yyvsp[-2].s),*(yyvsp[0].s),tokAt(scanner,(yylsp[-2]))); delete (yyvsp[0].s); delete (yyvsp[-2].s); }
    break;

  case 106: /* annotation_argument: annotation_argument_name '=' "integer constant"  */
                                                                    { (yyval.aa) = new AnnotationArgument(*(yyvsp[-2].s),(yyvsp[0].i),tokAt(scanner,(yylsp[-2]))); delete (yyvsp[-2].s); }
    break;

  case 107: /* annotation_argument: annotation_argument_name '=' "floating point constant"  */
                                                                    { (yyval.aa) = new AnnotationArgument(*(yyvsp[-2].s),float((yyvsp[0].fd)),tokAt(scanner,(yylsp[-2]))); delete (yyvsp[-2].s); }
    break;

  case 108: /* annotation_argument: annotation_argument_name '=' "true"  */
                                                                    { (yyval.aa) = new AnnotationArgument(*(yyvsp[-2].s),true,tokAt(scanner,(yylsp[-2]))); delete (yyvsp[-2].s); }
    break;

  case 109: /* annotation_argument: annotation_argument_name '=' "false"  */
                                                                    { (yyval.aa) = new AnnotationArgument(*(yyvsp[-2].s),false,tokAt(scanner,(yylsp[-2]))); delete (yyvsp[-2].s); }
    break;

  case 110: /* annotation_argument: annotation_argument_name  */
                                                                    { (yyval.aa) = new AnnotationArgument(*(yyvsp[0].s),true,tokAt(scanner,(yylsp[0]))); delete (yyvsp[0].s); }
    break;

  case 111: /* annotation_argument: annotation_argument_name '=' '(' annotation_argument_value_list ')'  */
                                                                                          {
        { (yyval.aa) = new AnnotationArgument(*(yyvsp[-4].s),(yyvsp[-1].aaList),tokAt(scanner,(yylsp[-4]))); delete (yyvsp[-4].s); }
    }
    break;

  case 112: /* annotation_argument_list: annotation_argument  */
                                  {
        (yyval.aaList) = ast_annotationArgumentListEntry(scanner,new AnnotationArgumentList(),(yyvsp[0].aa));
    }
    break;

  case 113: /* annotation_argument_list: annotation_argument_list ',' annotation_argument  */
                                                                    {
        (yyval.aaList) = ast_annotationArgumentListEntry(scanner,(yyvsp[-2].aaList),(yyvsp[0].aa));
    }
    break;

  case 114: /* metadata_argument_list: '@' annotation_argument optional_emit_semis  */
                                                         {
        (yyval.aaList) = ast_annotationArgumentListEntry(scanner,new AnnotationArgumentList(),(yyvsp[-1].aa));
    }
    break;

  case 115: /* metadata_argument_list: metadata_argument_list '@' annotation_argument optional_emit_semis  */
                                                                                      {
        (yyval.aaList) = ast_annotationArgumentListEntry(scanner,(yyvsp[-3].aaList),(yyvsp[-1].aa));
    }
    break;

  case 116: /* annotation_declaration_name: name_in_namespace  */
                                    { (yyval.s) = (yyvsp[0].s); }
    break;

  case 117: /* annotation_declaration_name: "require"  */
                                    { (yyval.s) = new string("require"); }
    break;

  case 118: /* annotation_declaration_name: "private"  */
                                    { (yyval.s) = new string("private"); }
    break;

  case 119: /* annotation_declaration_basic: annotation_declaration_name  */
                                          {
        (yyval.fa) = new AnnotationDeclaration();
        (yyval.fa)->at = tokAt(scanner,(yylsp[0]));
        if ( yyextra->g_Access->isAnnotationAllowed(*(yyvsp[0].s), yyextra->g_Program->thisModuleName) ) {
            if ( auto ann = findAnnotation(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0]))) ) {
                (yyval.fa)->annotation = ann;
            }
        } else {
            das2_yyerror(scanner,"annotation " + *(yyvsp[0].s) + " is not allowed here",
                        tokAt(scanner,(yylsp[0])), CompilationError::invalid_annotation);
        }
        delete (yyvsp[0].s);
    }
    break;

  case 120: /* annotation_declaration_basic: annotation_declaration_name '(' annotation_argument_list ')'  */
                                                                                 {
        (yyval.fa) = new AnnotationDeclaration();
        (yyval.fa)->at = tokAt(scanner,(yylsp[-3]));
        if ( yyextra->g_Access->isAnnotationAllowed(*(yyvsp[-3].s), yyextra->g_Program->thisModuleName) ) {
            if ( auto ann = findAnnotation(scanner,*(yyvsp[-3].s),tokAt(scanner,(yylsp[-3]))) ) {
                (yyval.fa)->annotation = ann;
            }
        } else {
            das2_yyerror(scanner,"annotation " + *(yyvsp[-3].s) + " is not allowed here",
                        tokAt(scanner,(yylsp[-3])), CompilationError::invalid_annotation);
        }
        swap ( (yyval.fa)->arguments, *(yyvsp[-1].aaList) );
        delete (yyvsp[-1].aaList);
        delete (yyvsp[-3].s);
    }
    break;

  case 121: /* annotation_declaration: annotation_declaration_basic  */
                                          {
        (yyval.fa) = (yyvsp[0].fa);
    }
    break;

  case 122: /* annotation_declaration: '!' annotation_declaration  */
                                              {
        if ( !(yyvsp[0].fa)->annotation->rtti_isFunctionAnnotation() || !((FunctionAnnotation *)((yyvsp[0].fa)->annotation.get()))->isSpecialized() ) {
            das2_yyerror(scanner,"can only run logical operations on contracts", tokAt(scanner, (yylsp[0])),
                CompilationError::invalid_annotation); }
        (yyval.fa) = new AnnotationDeclaration();
        (yyval.fa)->at = tokAt(scanner, (yylsp[-1]));
        (yyval.fa)->annotation = newLogicAnnotation(LogicAnnotationOp::Not,(yyvsp[0].fa),nullptr);
    }
    break;

  case 123: /* annotation_declaration: annotation_declaration "&&" annotation_declaration  */
                                                                              {
        if ( !(yyvsp[-2].fa)->annotation->rtti_isFunctionAnnotation() || !((FunctionAnnotation *)((yyvsp[-2].fa)->annotation.get()))->isSpecialized() ) {
            das2_yyerror(scanner,"can only run logical operations on contracts", tokAt(scanner, (yylsp[-2])),
                CompilationError::invalid_annotation); }
        if ( !(yyvsp[0].fa)->annotation->rtti_isFunctionAnnotation() || !((FunctionAnnotation *)((yyvsp[0].fa)->annotation.get()))->isSpecialized() ) {
            das2_yyerror(scanner,"can only run logical operations on contracts", tokAt(scanner, (yylsp[0])),
                CompilationError::invalid_annotation); }
        (yyval.fa) = new AnnotationDeclaration();
        (yyval.fa)->at = tokAt(scanner, (yylsp[-1]));
        (yyval.fa)->annotation = newLogicAnnotation(LogicAnnotationOp::And,(yyvsp[-2].fa),(yyvsp[0].fa));
    }
    break;

  case 124: /* annotation_declaration: annotation_declaration "||" annotation_declaration  */
                                                                            {
        if ( !(yyvsp[-2].fa)->annotation || !(yyvsp[-2].fa)->annotation->rtti_isFunctionAnnotation() || !((FunctionAnnotation *)((yyvsp[-2].fa)->annotation.get()))->isSpecialized() ) {
            das2_yyerror(scanner,"can only run logical operations on contracts", tokAt(scanner, (yylsp[-2])),
                CompilationError::invalid_annotation); }
        if ( !(yyvsp[0].fa)->annotation || !(yyvsp[0].fa)->annotation->rtti_isFunctionAnnotation() || !((FunctionAnnotation *)((yyvsp[0].fa)->annotation.get()))->isSpecialized() ) {
            das2_yyerror(scanner,"can only run logical operations on contracts", tokAt(scanner, (yylsp[0])),
                CompilationError::invalid_annotation); }
        (yyval.fa) = new AnnotationDeclaration();
        (yyval.fa)->at = tokAt(scanner, (yylsp[-1]));
        (yyval.fa)->annotation = newLogicAnnotation(LogicAnnotationOp::Or,(yyvsp[-2].fa),(yyvsp[0].fa));
    }
    break;

  case 125: /* annotation_declaration: annotation_declaration "^^" annotation_declaration  */
                                                                              {
        if ( !(yyvsp[-2].fa)->annotation->rtti_isFunctionAnnotation() || !((FunctionAnnotation *)((yyvsp[-2].fa)->annotation.get()))->isSpecialized() ) {
            das2_yyerror(scanner,"can only run logical operations on contracts", tokAt(scanner, (yylsp[-2])),
                CompilationError::invalid_annotation); }
        if ( !(yyvsp[0].fa)->annotation->rtti_isFunctionAnnotation() || !((FunctionAnnotation *)((yyvsp[0].fa)->annotation.get()))->isSpecialized() ) {
            das2_yyerror(scanner,"can only run logical operations on contracts", tokAt(scanner, (yylsp[0])),
                CompilationError::invalid_annotation); }
        (yyval.fa) = new AnnotationDeclaration();
        (yyval.fa)->at = tokAt(scanner, (yylsp[-1]));
        (yyval.fa)->annotation = newLogicAnnotation(LogicAnnotationOp::Xor,(yyvsp[-2].fa),(yyvsp[0].fa));
    }
    break;

  case 126: /* annotation_declaration: '(' annotation_declaration ')'  */
                                            {
        (yyval.fa) = (yyvsp[-1].fa);
    }
    break;

  case 127: /* annotation_declaration: "|>" annotation_declaration  */
                                          {
        (yyval.fa) = (yyvsp[0].fa);
        (yyvsp[0].fa)->inherited = true;
    }
    break;

  case 128: /* annotation_list: annotation_declaration  */
                                    {
            (yyval.faList) = new AnnotationList();
            (yyval.faList)->push_back(AnnotationDeclarationPtr((yyvsp[0].fa)));
    }
    break;

  case 129: /* annotation_list: annotation_list ',' annotation_declaration  */
                                                              {
        (yyval.faList) = (yyvsp[-2].faList);
        (yyval.faList)->push_back(AnnotationDeclarationPtr((yyvsp[0].fa)));
    }
    break;

  case 130: /* optional_annotation_list: %empty  */
                                       { (yyval.faList) = nullptr; }
    break;

  case 131: /* optional_annotation_list: '[' annotation_list ']'  */
                                       { (yyval.faList) = (yyvsp[-1].faList); }
    break;

  case 132: /* optional_annotation_list_with_emit_semis: %empty  */
                                       { (yyval.faList) = nullptr; }
    break;

  case 133: /* optional_annotation_list_with_emit_semis: '[' annotation_list ']' optional_emit_semis  */
                                                          { (yyval.faList) = (yyvsp[-2].faList); }
    break;

  case 134: /* optional_function_argument_list: %empty  */
                                                { (yyval.pVarDeclList) = nullptr; }
    break;

  case 135: /* optional_function_argument_list: '(' ')'  */
                                                { (yyval.pVarDeclList) = nullptr; }
    break;

  case 136: /* optional_function_argument_list: '(' function_argument_list ')'  */
                                                { (yyval.pVarDeclList) = (yyvsp[-1].pVarDeclList); }
    break;

  case 137: /* optional_function_type: %empty  */
        {
        (yyval.pTypeDecl) = new TypeDecl(Type::autoinfer);
    }
    break;

  case 138: /* optional_function_type: ':' type_declaration  */
                                        {
        (yyval.pTypeDecl) = (yyvsp[0].pTypeDecl);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[0]));
    }
    break;

  case 139: /* function_name: "name"  */
                          {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyval.s) = (yyvsp[0].s);
    }
    break;

  case 140: /* function_name: "operator" '!'  */
                             { (yyval.s) = new string("!"); }
    break;

  case 141: /* function_name: "operator" '~'  */
                             { (yyval.s) = new string("~"); }
    break;

  case 142: /* function_name: "operator" "+="  */
                             { (yyval.s) = new string("+="); }
    break;

  case 143: /* function_name: "operator" "-="  */
                             { (yyval.s) = new string("-="); }
    break;

  case 144: /* function_name: "operator" "*="  */
                             { (yyval.s) = new string("*="); }
    break;

  case 145: /* function_name: "operator" "/="  */
                             { (yyval.s) = new string("/="); }
    break;

  case 146: /* function_name: "operator" "%="  */
                             { (yyval.s) = new string("%="); }
    break;

  case 147: /* function_name: "operator" "&="  */
                             { (yyval.s) = new string("&="); }
    break;

  case 148: /* function_name: "operator" "|="  */
                             { (yyval.s) = new string("|="); }
    break;

  case 149: /* function_name: "operator" "^="  */
                             { (yyval.s) = new string("^="); }
    break;

  case 150: /* function_name: "operator" "&&="  */
                                { (yyval.s) = new string("&&="); }
    break;

  case 151: /* function_name: "operator" "||="  */
                                { (yyval.s) = new string("||="); }
    break;

  case 152: /* function_name: "operator" "^^="  */
                                { (yyval.s) = new string("^^="); }
    break;

  case 153: /* function_name: "operator" "&&"  */
                             { (yyval.s) = new string("&&"); }
    break;

  case 154: /* function_name: "operator" "||"  */
                             { (yyval.s) = new string("||"); }
    break;

  case 155: /* function_name: "operator" "^^"  */
                             { (yyval.s) = new string("^^"); }
    break;

  case 156: /* function_name: "operator" '+'  */
                             { (yyval.s) = new string("+"); }
    break;

  case 157: /* function_name: "operator" '-'  */
                             { (yyval.s) = new string("-"); }
    break;

  case 158: /* function_name: "operator" '*'  */
                             { (yyval.s) = new string("*"); }
    break;

  case 159: /* function_name: "operator" '/'  */
                             { (yyval.s) = new string("/"); }
    break;

  case 160: /* function_name: "operator" '%'  */
                             { (yyval.s) = new string("%"); }
    break;

  case 161: /* function_name: "operator" '<'  */
                             { (yyval.s) = new string("<"); }
    break;

  case 162: /* function_name: "operator" '>'  */
                             { (yyval.s) = new string(">"); }
    break;

  case 163: /* function_name: "operator" ".."  */
                             { (yyval.s) = new string("interval"); }
    break;

  case 164: /* function_name: "operator" "=="  */
                             { (yyval.s) = new string("=="); }
    break;

  case 165: /* function_name: "operator" "!="  */
                             { (yyval.s) = new string("!="); }
    break;

  case 166: /* function_name: "operator" "<="  */
                             { (yyval.s) = new string("<="); }
    break;

  case 167: /* function_name: "operator" ">="  */
                             { (yyval.s) = new string(">="); }
    break;

  case 168: /* function_name: "operator" '&'  */
                             { (yyval.s) = new string("&"); }
    break;

  case 169: /* function_name: "operator" '|'  */
                             { (yyval.s) = new string("|"); }
    break;

  case 170: /* function_name: "operator" '^'  */
                             { (yyval.s) = new string("^"); }
    break;

  case 171: /* function_name: "++" "operator"  */
                             { (yyval.s) = new string("++"); }
    break;

  case 172: /* function_name: "--" "operator"  */
                             { (yyval.s) = new string("--"); }
    break;

  case 173: /* function_name: "operator" "++"  */
                             { (yyval.s) = new string("+++"); }
    break;

  case 174: /* function_name: "operator" "--"  */
                             { (yyval.s) = new string("---"); }
    break;

  case 175: /* function_name: "operator" "<<"  */
                             { (yyval.s) = new string("<<"); }
    break;

  case 176: /* function_name: "operator" ">>"  */
                             { (yyval.s) = new string(">>"); }
    break;

  case 177: /* function_name: "operator" "<<="  */
                             { (yyval.s) = new string("<<="); }
    break;

  case 178: /* function_name: "operator" ">>="  */
                             { (yyval.s) = new string(">>="); }
    break;

  case 179: /* function_name: "operator" "<<<"  */
                             { (yyval.s) = new string("<<<"); }
    break;

  case 180: /* function_name: "operator" ">>>"  */
                             { (yyval.s) = new string(">>>"); }
    break;

  case 181: /* function_name: "operator" "<<<="  */
                             { (yyval.s) = new string("<<<="); }
    break;

  case 182: /* function_name: "operator" ">>>="  */
                             { (yyval.s) = new string(">>>="); }
    break;

  case 183: /* function_name: "operator" '[' ']'  */
                             { (yyval.s) = new string("[]"); }
    break;

  case 184: /* function_name: "operator" "?[" ']'  */
                                { (yyval.s) = new string("?[]"); }
    break;

  case 185: /* function_name: "operator" '.'  */
                             { (yyval.s) = new string("."); }
    break;

  case 186: /* function_name: "operator" "?."  */
                             { (yyval.s) = new string("?."); }
    break;

  case 187: /* function_name: "operator" '.' "name"  */
                                       { (yyval.s) = new string(".`"+*(yyvsp[0].s)); delete (yyvsp[0].s); }
    break;

  case 188: /* function_name: "operator" '.' "name" ":="  */
                                             { (yyval.s) = new string(".`"+*(yyvsp[-1].s)+"`clone"); delete (yyvsp[-1].s); }
    break;

  case 189: /* function_name: "operator" "?." "name"  */
                                       { (yyval.s) = new string("?.`"+*(yyvsp[0].s)); delete (yyvsp[0].s);}
    break;

  case 190: /* function_name: "operator" ":="  */
                                { (yyval.s) = new string("clone"); }
    break;

  case 191: /* function_name: "operator" "delete"  */
                                { (yyval.s) = new string("finalize"); }
    break;

  case 192: /* function_name: "operator" "??"  */
                           { (yyval.s) = new string("??"); }
    break;

  case 193: /* function_name: "operator" "is"  */
                            { (yyval.s) = new string("`is"); }
    break;

  case 194: /* function_name: "operator" "as"  */
                            { (yyval.s) = new string("`as"); }
    break;

  case 195: /* function_name: "operator" "is" "name"  */
                                       { (yyval.s) = (yyvsp[0].s); *(yyvsp[0].s) = "`is`" + *(yyvsp[0].s); }
    break;

  case 196: /* function_name: "operator" "as" "name"  */
                                       { (yyval.s) = (yyvsp[0].s); *(yyvsp[0].s) = "`as`" + *(yyvsp[0].s); }
    break;

  case 197: /* function_name: "operator" '?' "as"  */
                                { (yyval.s) = new string("?as"); }
    break;

  case 198: /* function_name: "operator" '?' "as" "name"  */
                                           { (yyval.s) = (yyvsp[0].s); *(yyvsp[0].s) = "?as`" + *(yyvsp[0].s); }
    break;

  case 199: /* function_name: "bool"  */
                     { (yyval.s) = new string("bool"); }
    break;

  case 200: /* function_name: "string"  */
                     { (yyval.s) = new string("string"); }
    break;

  case 201: /* function_name: "int"  */
                     { (yyval.s) = new string("int"); }
    break;

  case 202: /* function_name: "int2"  */
                     { (yyval.s) = new string("int2"); }
    break;

  case 203: /* function_name: "int3"  */
                     { (yyval.s) = new string("int3"); }
    break;

  case 204: /* function_name: "int4"  */
                     { (yyval.s) = new string("int4"); }
    break;

  case 205: /* function_name: "uint"  */
                     { (yyval.s) = new string("uint"); }
    break;

  case 206: /* function_name: "uint2"  */
                     { (yyval.s) = new string("uint2"); }
    break;

  case 207: /* function_name: "uint3"  */
                     { (yyval.s) = new string("uint3"); }
    break;

  case 208: /* function_name: "uint4"  */
                     { (yyval.s) = new string("uint4"); }
    break;

  case 209: /* function_name: "float"  */
                     { (yyval.s) = new string("float"); }
    break;

  case 210: /* function_name: "float2"  */
                     { (yyval.s) = new string("float2"); }
    break;

  case 211: /* function_name: "float3"  */
                     { (yyval.s) = new string("float3"); }
    break;

  case 212: /* function_name: "float4"  */
                     { (yyval.s) = new string("float4"); }
    break;

  case 213: /* function_name: "range"  */
                     { (yyval.s) = new string("range"); }
    break;

  case 214: /* function_name: "urange"  */
                     { (yyval.s) = new string("urange"); }
    break;

  case 215: /* function_name: "range64"  */
                     { (yyval.s) = new string("range64"); }
    break;

  case 216: /* function_name: "urange64"  */
                     { (yyval.s) = new string("urange64"); }
    break;

  case 217: /* function_name: "int64"  */
                     { (yyval.s) = new string("int64"); }
    break;

  case 218: /* function_name: "uint64"  */
                     { (yyval.s) = new string("uint64"); }
    break;

  case 219: /* function_name: "double"  */
                     { (yyval.s) = new string("double"); }
    break;

  case 220: /* function_name: "int8"  */
                     { (yyval.s) = new string("int8"); }
    break;

  case 221: /* function_name: "uint8"  */
                     { (yyval.s) = new string("uint8"); }
    break;

  case 222: /* function_name: "int16"  */
                     { (yyval.s) = new string("int16"); }
    break;

  case 223: /* function_name: "uint16"  */
                     { (yyval.s) = new string("uint16"); }
    break;

  case 224: /* global_function_declaration: optional_annotation_list_with_emit_semis "def" function_declaration  */
                                                                                                {
        (yyvsp[0].pFuncDecl)->atDecl = tokRangeAt(scanner,(yylsp[-1]),(yylsp[0]));
        assignDefaultArguments((yyvsp[0].pFuncDecl));
        runFunctionAnnotations(scanner, yyextra, (yyvsp[0].pFuncDecl), (yyvsp[-2].faList), tokAt(scanner,(yylsp[-2])));
        if ( (yyvsp[0].pFuncDecl)->isGeneric() ) {
            implAddGenericFunction(scanner,(yyvsp[0].pFuncDecl));
        } else {
            if ( !yyextra->g_Program->addFunction((yyvsp[0].pFuncDecl)) ) {
                das2_yyerror(scanner,"function is already defined " +
                    (yyvsp[0].pFuncDecl)->getMangledName(),(yyvsp[0].pFuncDecl)->at,
                        CompilationError::function_already_declared);
            }
        }
        (yyvsp[0].pFuncDecl)->delRef();
    }
    break;

  case 225: /* optional_public_or_private_function: %empty  */
                        { (yyval.b) = yyextra->g_thisStructure ? !yyextra->g_thisStructure->privateStructure : yyextra->g_Program->thisModule->isPublic; }
    break;

  case 226: /* optional_public_or_private_function: "private"  */
                        { (yyval.b) = false; }
    break;

  case 227: /* optional_public_or_private_function: "public"  */
                        { (yyval.b) = true; }
    break;

  case 228: /* function_declaration_header: function_name optional_function_argument_list optional_function_type  */
                                                                                                {
        (yyval.pFuncDecl) = ast_functionDeclarationHeader(scanner,(yyvsp[-2].s),(yyvsp[-1].pVarDeclList),(yyvsp[0].pTypeDecl),tokAt(scanner,(yylsp[-2])));
    }
    break;

  case 229: /* $@6: %empty  */
                                                     {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeFunction(tak);
        }
    }
    break;

  case 230: /* function_declaration: optional_public_or_private_function $@6 function_declaration_header optional_emit_semis expression_block  */
                                                                                    {
        (yyvsp[-2].pFuncDecl)->body = ExpressionPtr((yyvsp[0].pExpression));
        (yyvsp[-2].pFuncDecl)->privateFunction = !(yyvsp[-4].b);
        (yyval.pFuncDecl) = (yyvsp[-2].pFuncDecl);
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterFunction((yyvsp[-2].pFuncDecl),tak);
        }
    }
    break;

  case 231: /* expression_block_finally: %empty  */
        {
        (yyval.pExpression) = nullptr;
    }
    break;

  case 232: /* $@7: %empty  */
                  {
        yyextra->push_nesteds(DAS_EMIT_SEMICOLON);
    }
    break;

  case 233: /* $@8: %empty  */
                             {
        yyextra->pop_nesteds();
    }
    break;

  case 234: /* expression_block_finally: "finally" $@7 '{' expressions $@8 '}'  */
          {
        (yyval.pExpression) = (yyvsp[-2].pExpression);
    }
    break;

  case 235: /* $@9: %empty  */
        {
        yyextra->push_nesteds(DAS_EMIT_SEMICOLON);
    }
    break;

  case 236: /* $@10: %empty  */
                                      {
        yyextra->pop_nesteds();
    }
    break;

  case 237: /* expression_block: $@9 '{' expressions $@10 '}' expression_block_finally  */
                                        {
        (yyval.pExpression) = (yyvsp[-3].pExpression);
        (yyval.pExpression)->at = tokRangeAt(scanner,(yylsp[-4]),(yylsp[0]));
        if ( (yyvsp[0].pExpression) ) {
            auto pF = (ExprBlock *) (yyvsp[0].pExpression);
            auto pB = (ExprBlock *) (yyval.pExpression);
            swap ( pB->finalList, pF->list );
            delete pF;
        }
    }
    break;

  case 238: /* expr_call_pipe: expr_call expr_full_block_assumed_piped  */
                                                           {
        if ( (yyvsp[-1].pExpression)->rtti_isCallLikeExpr() ) {
            ((ExprLooksLikeCall *)(yyvsp[-1].pExpression))->arguments.push_back(ExpressionPtr((yyvsp[0].pExpression)));
            (yyval.pExpression) = (yyvsp[-1].pExpression);
        } else {
            (yyval.pExpression) = (yyvsp[-1].pExpression);
            delete (yyvsp[0].pExpression);
        }
    }
    break;

  case 239: /* expression_any: SEMICOLON  */
                                                  { (yyval.pExpression) = nullptr; }
    break;

  case 240: /* expression_any: expr_assign SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 241: /* expression_any: expression_delete SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 242: /* expression_any: expression_let  */
                                                  { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 243: /* expression_any: expression_while_loop  */
                                                  { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 244: /* expression_any: expression_unsafe  */
                                                  { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 245: /* expression_any: expression_with  */
                                                  { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 246: /* expression_any: expression_with_alias SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 247: /* expression_any: expression_for_loop  */
                                                  { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 248: /* expression_any: expression_break SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 249: /* expression_any: expression_continue SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 250: /* expression_any: expression_return SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 251: /* expression_any: expression_yield SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 252: /* expression_any: expression_if_then_else  */
                                                  { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 253: /* expression_any: expression_if_then_else_oneliner  */
                                                  { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 254: /* expression_any: expression_try_catch  */
                                                  { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 255: /* expression_any: expression_label SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 256: /* expression_any: expression_goto SEMICOLON  */
                                                  { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 257: /* expression_any: "pass" SEMICOLON  */
                                                  { (yyval.pExpression) = nullptr; }
    break;

  case 258: /* expressions: %empty  */
        {
        (yyval.pExpression) = new ExprBlock();
        (yyval.pExpression)->at = LineInfo(yyextra->g_FileAccessStack.back(),
            yylloc.first_column,yylloc.first_line,yylloc.last_column,yylloc.last_line);
    }
    break;

  case 259: /* expressions: expressions expression_any  */
                                                        {
        (yyval.pExpression) = (yyvsp[-1].pExpression);
        if ( (yyvsp[0].pExpression) ) {
            static_cast<ExprBlock*>((yyvsp[-1].pExpression))->list.push_back(ExpressionPtr((yyvsp[0].pExpression)));
        }
    }
    break;

  case 260: /* expressions: expressions error  */
                                 {
        delete (yyvsp[-1].pExpression); (yyval.pExpression) = nullptr; YYABORT;
    }
    break;

  case 261: /* optional_expr_list: %empty  */
        { (yyval.pExpression) = nullptr; }
    break;

  case 262: /* optional_expr_list: expr_list optional_comma  */
                                            { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 263: /* optional_expr_map_tuple_list: %empty  */
        { (yyval.pExpression) = nullptr; }
    break;

  case 264: /* optional_expr_map_tuple_list: expr_map_tuple_list optional_comma  */
                                                      { (yyval.pExpression) = (yyvsp[-1].pExpression); }
    break;

  case 265: /* type_declaration_no_options_list: type_declaration  */
                               {
        (yyval.pTypeDeclList) = new vector<Expression *>();
        (yyval.pTypeDeclList)->push_back(new ExprTypeDecl(tokAt(scanner,(yylsp[0])),(yyvsp[0].pTypeDecl)));
    }
    break;

  case 266: /* type_declaration_no_options_list: type_declaration_no_options_list c_or_s type_declaration  */
                                                                              {
        (yyval.pTypeDeclList) = (yyvsp[-2].pTypeDeclList);
        (yyval.pTypeDeclList)->push_back(new ExprTypeDecl(tokAt(scanner,(yylsp[0])),(yyvsp[0].pTypeDecl)));
    }
    break;

  case 267: /* name_in_namespace: "name"  */
                                               { (yyval.s) = (yyvsp[0].s); }
    break;

  case 268: /* name_in_namespace: "name" "::" "name"  */
                                               {
            auto ita = yyextra->das_module_alias.find(*(yyvsp[-2].s));
            if ( ita == yyextra->das_module_alias.end() ) {
                *(yyvsp[-2].s) += "::";
            } else {
                *(yyvsp[-2].s) = ita->second + "::";
            }
            *(yyvsp[-2].s) += *(yyvsp[0].s);
            delete (yyvsp[0].s);
            (yyval.s) = (yyvsp[-2].s);
        }
    break;

  case 269: /* name_in_namespace: "::" "name"  */
                                               { *(yyvsp[0].s) = "::" + *(yyvsp[0].s); (yyval.s) = (yyvsp[0].s); }
    break;

  case 270: /* expression_delete: "delete" expr  */
                                      {
        (yyval.pExpression) = new ExprDelete(tokAt(scanner,(yylsp[-1])), ExpressionPtr((yyvsp[0].pExpression)));
    }
    break;

  case 271: /* expression_delete: "delete" "explicit" expr  */
                                                   {
        auto delExpr = new ExprDelete(tokAt(scanner,(yylsp[-2])), ExpressionPtr((yyvsp[0].pExpression)));
        delExpr->native = true;
        (yyval.pExpression) = delExpr;
    }
    break;

  case 272: /* $@11: %empty  */
           { yyextra->das_arrow_depth ++; }
    break;

  case 273: /* $@12: %empty  */
                                                                           { yyextra->das_arrow_depth --; }
    break;

  case 274: /* new_type_declaration: '<' $@11 type_declaration '>' $@12  */
                                                                                                            {
        (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
    }
    break;

  case 275: /* new_type_declaration: structure_type_declaration  */
                                               {
        (yyval.pTypeDecl) = (yyvsp[0].pTypeDecl);
    }
    break;

  case 276: /* expr_new: "new" new_type_declaration  */
                                                       {
        (yyval.pExpression) = new ExprNew(tokAt(scanner,(yylsp[-1])),TypeDeclPtr((yyvsp[0].pTypeDecl)),false);
    }
    break;

  case 277: /* expr_new: "new" new_type_declaration '(' use_initializer ')'  */
                                                                                     {
        (yyval.pExpression) = new ExprNew(tokAt(scanner,(yylsp[-4])),TypeDeclPtr((yyvsp[-3].pTypeDecl)),true);
        ((ExprNew *)(yyval.pExpression))->initializer = (yyvsp[-1].b);
    }
    break;

  case 278: /* expr_new: "new" new_type_declaration '(' expr_list ')'  */
                                                                                    {
        auto pNew = new ExprNew(tokAt(scanner,(yylsp[-4])),TypeDeclPtr((yyvsp[-3].pTypeDecl)),true);
        (yyval.pExpression) = parseFunctionArguments(pNew,(yyvsp[-1].pExpression));
    }
    break;

  case 279: /* expr_new: "new" new_type_declaration '(' make_struct_single ')'  */
                                                                                      {
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->at = tokAt(scanner,(yylsp[-3]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = (yyvsp[-3].pTypeDecl);
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = true; // $init;
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->alwaysUseInitializer = true;
        (yyval.pExpression) = new ExprAscend(tokAt(scanner,(yylsp[-4])),ExpressionPtr((yyvsp[-1].pExpression)));
    }
    break;

  case 280: /* expr_new: "new" new_type_declaration '(' "uninitialized" make_struct_single ')'  */
                                                                                                        {
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->at = tokAt(scanner,(yylsp[-4]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = (yyvsp[-4].pTypeDecl);
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = false; // $init;
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->alwaysUseInitializer = true;
        (yyval.pExpression) = new ExprAscend(tokAt(scanner,(yylsp[-5])),ExpressionPtr((yyvsp[-1].pExpression)));
    }
    break;

  case 281: /* expr_new: "new" make_decl  */
                                    {
        (yyval.pExpression) = new ExprAscend(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[0].pExpression)));
    }
    break;

  case 282: /* expression_break: "break"  */
                       { (yyval.pExpression) = new ExprBreak(tokAt(scanner,(yylsp[0]))); }
    break;

  case 283: /* expression_continue: "continue"  */
                          { (yyval.pExpression) = new ExprContinue(tokAt(scanner,(yylsp[0]))); }
    break;

  case 284: /* expression_return: "return"  */
                        {
        (yyval.pExpression) = new ExprReturn(tokAt(scanner,(yylsp[0])),nullptr);
    }
    break;

  case 285: /* expression_return: "return" expr  */
                                      {
        (yyval.pExpression) = new ExprReturn(tokAt(scanner,(yylsp[-1])),(yyvsp[0].pExpression));
    }
    break;

  case 286: /* expression_return: "return" "<-" expr  */
                                             {
        auto pRet = new ExprReturn(tokAt(scanner,(yylsp[-2])),(yyvsp[0].pExpression));
        pRet->moveSemantics = true;
        (yyval.pExpression) = pRet;
    }
    break;

  case 287: /* expression_yield: "yield" expr  */
                                     {
        (yyval.pExpression) = new ExprYield(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[0].pExpression)));
    }
    break;

  case 288: /* expression_yield: "yield" "<-" expr  */
                                            {
        auto pRet = new ExprYield(tokAt(scanner,(yylsp[-2])),ExpressionPtr((yyvsp[0].pExpression)));
        pRet->moveSemantics = true;
        (yyval.pExpression) = pRet;
    }
    break;

  case 289: /* expression_try_catch: "try" expression_block "recover" expression_block  */
                                                                                       {
        (yyval.pExpression) = new ExprTryCatch(tokAt(scanner,(yylsp[-3])),ExpressionPtr((yyvsp[-2].pExpression)),ExpressionPtr((yyvsp[0].pExpression)));
    }
    break;

  case 290: /* kwd_let_var_or_nothing: "let"  */
                 { (yyval.b) = true; }
    break;

  case 291: /* kwd_let_var_or_nothing: "var"  */
                 { (yyval.b) = false; }
    break;

  case 292: /* kwd_let_var_or_nothing: %empty  */
                    { (yyval.b) = true; }
    break;

  case 293: /* kwd_let: "let"  */
                 { (yyval.b) = true; }
    break;

  case 294: /* kwd_let: "var"  */
                 { (yyval.b) = false; }
    break;

  case 295: /* optional_in_scope: "inscope"  */
                    { (yyval.b) = true; }
    break;

  case 296: /* optional_in_scope: %empty  */
                     { (yyval.b) = false; }
    break;

  case 297: /* tuple_expansion: "name"  */
                    {
        (yyval.pNameList) = new vector<string>();
        (yyval.pNameList)->push_back(*(yyvsp[0].s));
        delete (yyvsp[0].s);
    }
    break;

  case 298: /* tuple_expansion: tuple_expansion ',' "name"  */
                                             {
        (yyvsp[-2].pNameList)->push_back(*(yyvsp[0].s));
        delete (yyvsp[0].s);
        (yyval.pNameList) = (yyvsp[-2].pNameList);
    }
    break;

  case 299: /* tuple_expansion_variable_declaration: '(' tuple_expansion ')' ':' type_declaration_no_options copy_or_move_or_clone expr SEMICOLON  */
                                                                                                                                {
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-6].pNameList),tokAt(scanner,(yylsp[-6])),(yyvsp[-3].pTypeDecl),(yyvsp[-1].pExpression));
        (yyval.pVarDecl)->init_via_move  = ((yyvsp[-2].i) & CorM_MOVE) !=0;
        (yyval.pVarDecl)->init_via_clone = ((yyvsp[-2].i) & CorM_CLONE) !=0;
        (yyval.pVarDecl)->isTupleExpansion = true;
    }
    break;

  case 300: /* tuple_expansion_variable_declaration: '(' tuple_expansion ')' optional_ref copy_or_move_or_clone expr SEMICOLON  */
                                                                                                        {
        auto typeDecl = new TypeDecl(Type::autoinfer);
        typeDecl->at = tokAt(scanner,(yylsp[-5]));
        typeDecl->ref = (yyvsp[-3].b);
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-5].pNameList),tokAt(scanner,(yylsp[-5])),typeDecl,(yyvsp[-1].pExpression));
        (yyval.pVarDecl)->init_via_move  = ((yyvsp[-2].i) & CorM_MOVE) !=0;
        (yyval.pVarDecl)->init_via_clone = ((yyvsp[-2].i) & CorM_CLONE) !=0;
        (yyval.pVarDecl)->isTupleExpansion = true;
    }
    break;

  case 301: /* expression_let: kwd_let optional_in_scope let_variable_declaration  */
                                                                 {
        (yyval.pExpression) = ast_Let(scanner,(yyvsp[-2].b),(yyvsp[-1].b),(yyvsp[0].pVarDecl),tokAt(scanner,(yylsp[-2])),tokAt(scanner,(yylsp[0])));
    }
    break;

  case 302: /* expression_let: kwd_let optional_in_scope tuple_expansion_variable_declaration  */
                                                                             {
        (yyval.pExpression) = ast_Let(scanner,(yyvsp[-2].b),(yyvsp[-1].b),(yyvsp[0].pVarDecl),tokAt(scanner,(yylsp[-2])),tokAt(scanner,(yylsp[0])));
    }
    break;

  case 303: /* expression_let: kwd_let optional_in_scope '{' variable_declaration_list '}'  */
                                                                               {
        (yyval.pExpression) = ast_LetList(scanner,(yyvsp[-4].b),(yyvsp[-3].b),*(yyvsp[-1].pVarDeclList),tokAt(scanner,(yylsp[-4])),tokAt(scanner,(yylsp[-1])));
    }
    break;

  case 304: /* $@13: %empty  */
                          { yyextra->das_arrow_depth ++; }
    break;

  case 305: /* $@14: %empty  */
                                                                                                 { yyextra->das_arrow_depth --; }
    break;

  case 306: /* expr_cast: "cast" '<' $@13 type_declaration_no_options '>' $@14 expr  */
                                                                                                                                                {
        (yyval.pExpression) = new ExprCast(tokAt(scanner,(yylsp[-6])),ExpressionPtr((yyvsp[0].pExpression)),TypeDeclPtr((yyvsp[-3].pTypeDecl)));
    }
    break;

  case 307: /* $@15: %empty  */
                            { yyextra->das_arrow_depth ++; }
    break;

  case 308: /* $@16: %empty  */
                                                                                                   { yyextra->das_arrow_depth --; }
    break;

  case 309: /* expr_cast: "upcast" '<' $@15 type_declaration_no_options '>' $@16 expr  */
                                                                                                                                                  {
        auto pCast = new ExprCast(tokAt(scanner,(yylsp[-6])),ExpressionPtr((yyvsp[0].pExpression)),TypeDeclPtr((yyvsp[-3].pTypeDecl)));
        pCast->upcast = true;
        (yyval.pExpression) = pCast;
    }
    break;

  case 310: /* $@17: %empty  */
                                 { yyextra->das_arrow_depth ++; }
    break;

  case 311: /* $@18: %empty  */
                                                                                                        { yyextra->das_arrow_depth --; }
    break;

  case 312: /* expr_cast: "reinterpret" '<' $@17 type_declaration_no_options '>' $@18 expr  */
                                                                                                                                                       {
        auto pCast = new ExprCast(tokAt(scanner,(yylsp[-6])),ExpressionPtr((yyvsp[0].pExpression)),TypeDeclPtr((yyvsp[-3].pTypeDecl)));
        pCast->reinterpret = true;
        (yyval.pExpression) = pCast;
    }
    break;

  case 313: /* $@19: %empty  */
                         { yyextra->das_arrow_depth ++; }
    break;

  case 314: /* $@20: %empty  */
                                                                                     { yyextra->das_arrow_depth --; }
    break;

  case 315: /* expr_type_decl: "type" '<' $@19 type_declaration '>' $@20  */
                                                                                                                      {
        (yyval.pExpression) = new ExprTypeDecl(tokAt(scanner,(yylsp[-5])),TypeDeclPtr((yyvsp[-2].pTypeDecl)));
    }
    break;

  case 316: /* expr_type_info: "typeinfo" name_in_namespace '(' expr ')'  */
                                                                          {
            if ( (yyvsp[-1].pExpression)->rtti_isTypeDecl() ) {
                auto ptd = (ExprTypeDecl *)(yyvsp[-1].pExpression);
                (yyval.pExpression) = new ExprTypeInfo(tokAt(scanner,(yylsp[-4])),*(yyvsp[-3].s),ptd->typeexpr);
                delete (yyvsp[-1].pExpression);
            } else {
                (yyval.pExpression) = new ExprTypeInfo(tokAt(scanner,(yylsp[-4])),*(yyvsp[-3].s),ExpressionPtr((yyvsp[-1].pExpression)));
            }
            delete (yyvsp[-3].s);
    }
    break;

  case 317: /* expr_type_info: "typeinfo" name_in_namespace '<' "name" '>' '(' expr ')'  */
                                                                                                {
            if ( (yyvsp[-1].pExpression)->rtti_isTypeDecl() ) {
                auto ptd = (ExprTypeDecl *)(yyvsp[-1].pExpression);
                (yyval.pExpression) = new ExprTypeInfo(tokAt(scanner,(yylsp[-7])),*(yyvsp[-6].s),ptd->typeexpr,*(yyvsp[-4].s));
                delete (yyvsp[-1].pExpression);
            } else {
                (yyval.pExpression) = new ExprTypeInfo(tokAt(scanner,(yylsp[-7])),*(yyvsp[-6].s),ExpressionPtr((yyvsp[-1].pExpression)),*(yyvsp[-4].s));
            }
            delete (yyvsp[-6].s);
            delete (yyvsp[-4].s);
    }
    break;

  case 318: /* expr_type_info: "typeinfo" name_in_namespace '<' "name" c_or_s "name" '>' '(' expr ')'  */
                                                                                                                        {
            if ( (yyvsp[-1].pExpression)->rtti_isTypeDecl() ) {
                auto ptd = (ExprTypeDecl *)(yyvsp[-1].pExpression);
                (yyval.pExpression) = new ExprTypeInfo(tokAt(scanner,(yylsp[-9])),*(yyvsp[-8].s),ptd->typeexpr,*(yyvsp[-6].s),*(yyvsp[-4].s));
                delete (yyvsp[-1].pExpression);
            } else {
                (yyval.pExpression) = new ExprTypeInfo(tokAt(scanner,(yylsp[-9])),*(yyvsp[-8].s),ExpressionPtr((yyvsp[-1].pExpression)),*(yyvsp[-6].s),*(yyvsp[-4].s));
            }
            delete (yyvsp[-8].s);
            delete (yyvsp[-6].s);
            delete (yyvsp[-4].s);
    }
    break;

  case 319: /* expr_list: expr  */
                      {
        (yyval.pExpression) = (yyvsp[0].pExpression);
    }
    break;

  case 320: /* expr_list: expr_list ',' expr  */
                                            {
            (yyval.pExpression) = new ExprSequence(tokAt(scanner,(yylsp[-2])),ExpressionPtr((yyvsp[-2].pExpression)),ExpressionPtr((yyvsp[0].pExpression)));
    }
    break;

  case 321: /* block_or_simple_block: expression_block  */
                                    { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 322: /* block_or_simple_block: "=>" expr  */
                                        {
            auto retE = make_smart<ExprReturn>(tokAt(scanner,(yylsp[-1])), ExpressionPtr((yyvsp[0].pExpression)));
            auto blkE = new ExprBlock();
            blkE->at = tokAt(scanner,(yylsp[-1]));
            blkE->list.push_back(retE);
            (yyval.pExpression) = blkE;
    }
    break;

  case 323: /* block_or_simple_block: "=>" "<-" expr  */
                                               {
            auto retE = make_smart<ExprReturn>(tokAt(scanner,(yylsp[-2])), ExpressionPtr((yyvsp[0].pExpression)));
            retE->moveSemantics = true;
            auto blkE = new ExprBlock();
            blkE->at = tokAt(scanner,(yylsp[-2]));
            blkE->list.push_back(retE);
            (yyval.pExpression) = blkE;
    }
    break;

  case 324: /* block_or_lambda: '$'  */
                { (yyval.i) = 0;   /* block */  }
    break;

  case 325: /* block_or_lambda: '@'  */
                { (yyval.i) = 1;   /* lambda */ }
    break;

  case 326: /* block_or_lambda: '@' '@'  */
                { (yyval.i) = 2;   /* local function */ }
    break;

  case 327: /* capture_entry: '&' "name"  */
                                    { (yyval.pCapt) = new CaptureEntry(*(yyvsp[0].s),CaptureMode::capture_by_reference); delete (yyvsp[0].s); }
    break;

  case 328: /* capture_entry: '=' "name"  */
                                    { (yyval.pCapt) = new CaptureEntry(*(yyvsp[0].s),CaptureMode::capture_by_copy); delete (yyvsp[0].s); }
    break;

  case 329: /* capture_entry: "<-" "name"  */
                                    { (yyval.pCapt) = new CaptureEntry(*(yyvsp[0].s),CaptureMode::capture_by_move); delete (yyvsp[0].s); }
    break;

  case 330: /* capture_entry: ":=" "name"  */
                                    { (yyval.pCapt) = new CaptureEntry(*(yyvsp[0].s),CaptureMode::capture_by_clone); delete (yyvsp[0].s); }
    break;

  case 331: /* capture_entry: "name" '(' "name" ')'  */
                                    { (yyval.pCapt) = ast_makeCaptureEntry(scanner,tokAt(scanner,(yylsp[-3])),*(yyvsp[-3].s),*(yyvsp[-1].s)); delete (yyvsp[-3].s); delete (yyvsp[-1].s); }
    break;

  case 332: /* capture_list: capture_entry  */
                         {
        (yyval.pCaptList) = new vector<CaptureEntry>();
        (yyval.pCaptList)->push_back(*(yyvsp[0].pCapt));
        delete (yyvsp[0].pCapt);
    }
    break;

  case 333: /* capture_list: capture_list ',' capture_entry  */
                                               {
        (yyvsp[-2].pCaptList)->push_back(*(yyvsp[0].pCapt));
        delete (yyvsp[0].pCapt);
        (yyval.pCaptList) = (yyvsp[-2].pCaptList);
    }
    break;

  case 334: /* optional_capture_list: %empty  */
        { (yyval.pCaptList) = nullptr; }
    break;

  case 335: /* optional_capture_list: "capture" '(' capture_list ')'  */
                                             { (yyval.pCaptList) = (yyvsp[-1].pCaptList); }
    break;

  case 336: /* expr_full_block: block_or_lambda optional_annotation_list optional_capture_list optional_function_argument_list optional_function_type optional_emit_semis block_or_simple_block  */
                                                                                                                {
        (yyval.pExpression) = ast_makeBlock(scanner,(yyvsp[-6].i),(yyvsp[-5].faList),(yyvsp[-4].pCaptList),(yyvsp[-3].pVarDeclList),(yyvsp[-2].pTypeDecl),(yyvsp[0].pExpression),tokAt(scanner,(yylsp[0])),tokAt(scanner,(yylsp[-5])));
    }
    break;

  case 337: /* expr_full_block_assumed_piped: block_or_lambda optional_annotation_list optional_capture_list optional_function_argument_list optional_function_type optional_emit_semis expression_block  */
                                                                                                           {
        (yyval.pExpression) = ast_makeBlock(scanner,(yyvsp[-6].i),(yyvsp[-5].faList),(yyvsp[-4].pCaptList),(yyvsp[-3].pVarDeclList),(yyvsp[-2].pTypeDecl),(yyvsp[0].pExpression),tokAt(scanner,(yylsp[0])),tokAt(scanner,(yylsp[-5])));
    }
    break;

  case 338: /* expr_full_block_assumed_piped: '{' expressions '}'  */
                                   {
        (yyval.pExpression) = ast_makeBlock(scanner,0,nullptr,nullptr,nullptr,new TypeDecl(Type::autoinfer),(yyvsp[-1].pExpression),tokAt(scanner,(yylsp[-1])),tokAt(scanner,(yylsp[-1])));
    }
    break;

  case 339: /* expr_numeric_const: "integer constant"  */
                                              { (yyval.pExpression) = new ExprConstInt(tokAt(scanner,(yylsp[0])),(int32_t)(yyvsp[0].i)); }
    break;

  case 340: /* expr_numeric_const: "unsigned integer constant"  */
                                              { (yyval.pExpression) = new ExprConstUInt(tokAt(scanner,(yylsp[0])),(uint32_t)(yyvsp[0].ui)); }
    break;

  case 341: /* expr_numeric_const: "long integer constant"  */
                                              { (yyval.pExpression) = new ExprConstInt64(tokAt(scanner,(yylsp[0])),(int64_t)(yyvsp[0].i64)); }
    break;

  case 342: /* expr_numeric_const: "unsigned long integer constant"  */
                                              { (yyval.pExpression) = new ExprConstUInt64(tokAt(scanner,(yylsp[0])),(uint64_t)(yyvsp[0].ui64)); }
    break;

  case 343: /* expr_numeric_const: "unsigned int8 constant"  */
                                              { (yyval.pExpression) = new ExprConstUInt8(tokAt(scanner,(yylsp[0])),(uint8_t)(yyvsp[0].ui)); }
    break;

  case 344: /* expr_numeric_const: "floating point constant"  */
                                              { (yyval.pExpression) = new ExprConstFloat(tokAt(scanner,(yylsp[0])),(float)(yyvsp[0].fd)); }
    break;

  case 345: /* expr_numeric_const: "double constant"  */
                                              { (yyval.pExpression) = new ExprConstDouble(tokAt(scanner,(yylsp[0])),(double)(yyvsp[0].d)); }
    break;

  case 346: /* expr_assign: expr  */
                                             { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 347: /* expr_assign: expr '=' expr  */
                                             { (yyval.pExpression) = new ExprCopy(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-2].pExpression)),ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 348: /* expr_assign: expr "<-" expr  */
                                             { (yyval.pExpression) = new ExprMove(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 349: /* expr_assign: expr ":=" expr  */
                                             { (yyval.pExpression) = new ExprClone(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 350: /* expr_assign: expr "&=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"&=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 351: /* expr_assign: expr "|=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"|=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 352: /* expr_assign: expr "^=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"^=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 353: /* expr_assign: expr "&&=" expr  */
                                                { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"&&=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 354: /* expr_assign: expr "||=" expr  */
                                                { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"||=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 355: /* expr_assign: expr "^^=" expr  */
                                                { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"^^=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 356: /* expr_assign: expr "+=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"+=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 357: /* expr_assign: expr "-=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"-=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 358: /* expr_assign: expr "*=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"*=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 359: /* expr_assign: expr "/=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"/=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 360: /* expr_assign: expr "%=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"%=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 361: /* expr_assign: expr "<<=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"<<=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 362: /* expr_assign: expr ">>=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),">>=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 363: /* expr_assign: expr "<<<=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"<<<=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 364: /* expr_assign: expr ">>>=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),">>>=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 365: /* expr_named_call: name_in_namespace '(' '[' make_struct_fields ']' ')'  */
                                                                         {
        auto nc = new ExprNamedCall(tokAt(scanner,(yylsp[-5])),*(yyvsp[-5].s));
        nc->arguments = *(yyvsp[-2].pMakeStruct);
        delete (yyvsp[-2].pMakeStruct);
        delete (yyvsp[-5].s);
        (yyval.pExpression) = nc;
    }
    break;

  case 366: /* expr_named_call: name_in_namespace '(' expr_list ',' '[' make_struct_fields ']' ')'  */
                                                                                                  {
        auto nc = new ExprNamedCall(tokAt(scanner,(yylsp[-7])),*(yyvsp[-7].s));
        nc->nonNamedArguments = sequenceToList((yyvsp[-5].pExpression));
        nc->arguments = *(yyvsp[-2].pMakeStruct);
        delete (yyvsp[-2].pMakeStruct);
        delete (yyvsp[-7].s);
        (yyval.pExpression) = nc;
    }
    break;

  case 367: /* expr_method_call: expr "->" "name" '(' ')'  */
                                                         {
        auto pInvoke = makeInvokeMethod(tokAt(scanner,(yylsp[-3])), (yyvsp[-4].pExpression), *(yyvsp[-2].s));
        delete (yyvsp[-2].s);
        (yyval.pExpression) = pInvoke;
    }
    break;

  case 368: /* expr_method_call: expr "->" "name" '(' expr_list ')'  */
                                                                              {
        auto pInvoke = makeInvokeMethod(tokAt(scanner,(yylsp[-4])), (yyvsp[-5].pExpression), *(yyvsp[-3].s));
        auto callArgs = sequenceToList((yyvsp[-1].pExpression));
        pInvoke->arguments.insert ( pInvoke->arguments.end(), callArgs.begin(), callArgs.end() );
        delete (yyvsp[-3].s);
        (yyval.pExpression) = pInvoke;
    }
    break;

  case 369: /* func_addr_name: name_in_namespace  */
                                    {
        (yyval.pExpression) = new ExprAddr(tokAt(scanner,(yylsp[0])),*(yyvsp[0].s));
        delete (yyvsp[0].s);
    }
    break;

  case 370: /* func_addr_name: "$i" '(' expr ')'  */
                                          {
        auto expr = new ExprAddr(tokAt(scanner,(yylsp[-3])),"``MACRO``TAG``ADDR``");
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression), expr, "i");
    }
    break;

  case 371: /* func_addr_expr: '@' '@' func_addr_name  */
                                          {
        (yyval.pExpression) = (yyvsp[0].pExpression);
    }
    break;

  case 372: /* $@21: %empty  */
                    { yyextra->das_arrow_depth ++; }
    break;

  case 373: /* $@22: %empty  */
                                                                                                { yyextra->das_arrow_depth --; }
    break;

  case 374: /* func_addr_expr: '@' '@' '<' $@21 type_declaration_no_options '>' $@22 func_addr_name  */
                                                                                                                                                       {
        auto expr = (ExprAddr *) ((yyvsp[0].pExpression)->rtti_isAddr() ? (yyvsp[0].pExpression) : (((ExprTag *) (yyvsp[0].pExpression))->value.get()));
        expr->funcType = TypeDeclPtr((yyvsp[-3].pTypeDecl));
        (yyval.pExpression) = (yyvsp[0].pExpression);
    }
    break;

  case 375: /* $@23: %empty  */
                    { yyextra->das_arrow_depth ++; }
    break;

  case 376: /* $@24: %empty  */
                                                                                                                              { yyextra->das_arrow_depth --; }
    break;

  case 377: /* func_addr_expr: '@' '@' '<' $@23 optional_function_argument_list optional_function_type '>' $@24 func_addr_name  */
                                                                                                                                                                                     {
        auto expr = (ExprAddr *) ((yyvsp[0].pExpression)->rtti_isAddr() ? (yyvsp[0].pExpression) : (((ExprTag *) (yyvsp[0].pExpression))->value.get()));
        expr->funcType = make_smart<TypeDecl>(Type::tFunction);
        expr->funcType->firstType = TypeDeclPtr((yyvsp[-3].pTypeDecl));
        if ( (yyvsp[-4].pVarDeclList) ) {
            varDeclToTypeDecl(scanner, expr->funcType.get(), (yyvsp[-4].pVarDeclList));
            deleteVariableDeclarationList((yyvsp[-4].pVarDeclList));
        }
        (yyval.pExpression) = (yyvsp[0].pExpression);
    }
    break;

  case 378: /* expr_field: expr '.' "name"  */
                                              {
        (yyval.pExpression) = new ExprField(tokAt(scanner,(yylsp[-1])), tokAt(scanner,(yylsp[0])), ExpressionPtr((yyvsp[-2].pExpression)), *(yyvsp[0].s));
        delete (yyvsp[0].s);
    }
    break;

  case 379: /* expr_field: expr '.' '.' "name"  */
                                                  {
        (yyval.pExpression) = new ExprField(tokAt(scanner,(yylsp[-1])), tokAt(scanner,(yylsp[0])), ExpressionPtr((yyvsp[-3].pExpression)), *(yyvsp[0].s), true);
        delete (yyvsp[0].s);
    }
    break;

  case 380: /* expr_field: expr '.' "name" '(' ')'  */
                                                      {
        auto pInvoke = makeInvokeMethod(tokAt(scanner,(yylsp[-3])), (yyvsp[-4].pExpression), *(yyvsp[-2].s));
        delete (yyvsp[-2].s);
        (yyval.pExpression) = pInvoke;
    }
    break;

  case 381: /* expr_field: expr '.' "name" '(' expr_list ')'  */
                                                                           {
        auto pInvoke = makeInvokeMethod(tokAt(scanner,(yylsp[-4])), (yyvsp[-5].pExpression), *(yyvsp[-3].s));
        auto callArgs = sequenceToList((yyvsp[-1].pExpression));
        pInvoke->arguments.insert ( pInvoke->arguments.end(), callArgs.begin(), callArgs.end() );
        delete (yyvsp[-3].s);
        (yyval.pExpression) = pInvoke;
    }
    break;

  case 382: /* expr_field: expr '.' basic_type_declaration '(' ')'  */
                                                                        {
        auto method_name = das_to_string((yyvsp[-2].type));
        auto pInvoke = makeInvokeMethod(tokAt(scanner,(yylsp[-3])), (yyvsp[-4].pExpression), method_name);
        (yyval.pExpression) = pInvoke;
    }
    break;

  case 383: /* expr_field: expr '.' basic_type_declaration '(' expr_list ')'  */
                                                                                             {
        auto method_name = das_to_string((yyvsp[-3].type));
        auto pInvoke = makeInvokeMethod(tokAt(scanner,(yylsp[-4])), (yyvsp[-5].pExpression), method_name);
        auto callArgs = sequenceToList((yyvsp[-1].pExpression));
        pInvoke->arguments.insert ( pInvoke->arguments.end(), callArgs.begin(), callArgs.end() );
        (yyval.pExpression) = pInvoke;
    }
    break;

  case 384: /* $@25: %empty  */
                               { yyextra->das_suppress_errors=true; }
    break;

  case 385: /* $@26: %empty  */
                                                                            { yyextra->das_suppress_errors=false; }
    break;

  case 386: /* expr_field: expr '.' $@25 error $@26  */
                                                                                                                    {
        (yyval.pExpression) = new ExprField(tokAt(scanner,(yylsp[-3])), tokAt(scanner,(yylsp[-3])), ExpressionPtr((yyvsp[-4].pExpression)), "");
        yyerrok;
    }
    break;

  case 387: /* expr_call: name_in_namespace '(' ')'  */
                                               {
            (yyval.pExpression) = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-2])),tokAt(scanner,(yylsp[0])),*(yyvsp[-2].s));
            delete (yyvsp[-2].s);
    }
    break;

  case 388: /* expr_call: name_in_namespace '(' "uninitialized" ')'  */
                                                          {
            auto dd = new ExprMakeStruct(tokAt(scanner,(yylsp[-3])));
            dd->at = tokAt(scanner,(yylsp[-3]));
            dd->makeType = new TypeDecl(Type::alias);
            dd->makeType->alias = *(yyvsp[-3].s);
            dd->useInitializer = false;
            dd->alwaysUseInitializer = true;
            delete (yyvsp[-3].s);
            (yyval.pExpression) = dd;
    }
    break;

  case 389: /* expr_call: name_in_namespace '(' make_struct_single ')'  */
                                                               {
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->at = tokAt(scanner,(yylsp[-3]));
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = new TypeDecl(Type::alias);
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType->alias = *(yyvsp[-3].s);
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = true;
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->alwaysUseInitializer = true;
            delete (yyvsp[-3].s);
            (yyval.pExpression) = (yyvsp[-1].pExpression);
    }
    break;

  case 390: /* expr_call: name_in_namespace '(' "uninitialized" make_struct_single ')'  */
                                                                                 {
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->at = tokAt(scanner,(yylsp[-4]));
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = new TypeDecl(Type::alias);
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType->alias = *(yyvsp[-4].s);
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = false;
            ((ExprMakeStruct *)(yyvsp[-1].pExpression))->alwaysUseInitializer = true;
            delete (yyvsp[-4].s);
            (yyval.pExpression) = (yyvsp[-1].pExpression);
    }
    break;

  case 391: /* expr_call: name_in_namespace '(' expr_list ')'  */
                                                                    {
            (yyval.pExpression) = parseFunctionArguments(yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-3])),tokAt(scanner,(yylsp[0])),*(yyvsp[-3].s)),(yyvsp[-1].pExpression));
            delete (yyvsp[-3].s);
    }
    break;

  case 392: /* expr_call: basic_type_declaration '(' ')'  */
                                                    {
        (yyval.pExpression) = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-2])),tokAt(scanner,(yylsp[0])),das_to_string((yyvsp[-2].type)));
    }
    break;

  case 393: /* expr_call: basic_type_declaration '(' expr_list ')'  */
                                                                         {
        (yyval.pExpression) = parseFunctionArguments(yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-3])),tokAt(scanner,(yylsp[0])),das_to_string((yyvsp[-3].type))),(yyvsp[-1].pExpression));
    }
    break;

  case 394: /* expr: "null"  */
                                              { (yyval.pExpression) = new ExprConstPtr(tokAt(scanner,(yylsp[0])),nullptr); }
    break;

  case 395: /* expr: name_in_namespace  */
                                              { (yyval.pExpression) = new ExprVar(tokAt(scanner,(yylsp[0])),*(yyvsp[0].s)); delete (yyvsp[0].s); }
    break;

  case 396: /* expr: expr_numeric_const  */
                                              { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 397: /* expr: expr_reader  */
                                              { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 398: /* expr: string_builder  */
                                              { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 399: /* expr: make_decl  */
                                              { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 400: /* expr: "true"  */
                                              { (yyval.pExpression) = new ExprConstBool(tokAt(scanner,(yylsp[0])),true); }
    break;

  case 401: /* expr: "false"  */
                                              { (yyval.pExpression) = new ExprConstBool(tokAt(scanner,(yylsp[0])),false); }
    break;

  case 402: /* expr: expr_field  */
                                              { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 403: /* expr: expr_mtag  */
                                              { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 404: /* expr: '!' expr  */
                                              { (yyval.pExpression) = new ExprOp1(tokAt(scanner,(yylsp[-1])),"!",ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 405: /* expr: '~' expr  */
                                              { (yyval.pExpression) = new ExprOp1(tokAt(scanner,(yylsp[-1])),"~",ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 406: /* expr: '+' expr  */
                                                  { (yyval.pExpression) = new ExprOp1(tokAt(scanner,(yylsp[-1])),"+",ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 407: /* expr: '-' expr  */
                                                  { (yyval.pExpression) = new ExprOp1(tokAt(scanner,(yylsp[-1])),"-",ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 408: /* expr: expr "<<" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"<<", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 409: /* expr: expr ">>" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),">>", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 410: /* expr: expr "<<<" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"<<<", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 411: /* expr: expr ">>>" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),">>>", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 412: /* expr: expr '+' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"+", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 413: /* expr: expr '-' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"-", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 414: /* expr: expr '*' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"*", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 415: /* expr: expr '/' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"/", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 416: /* expr: expr '%' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"%", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 417: /* expr: expr '<' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"<", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 418: /* expr: expr '>' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),">", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 419: /* expr: expr "==" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"==", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 420: /* expr: expr "!=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"!=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 421: /* expr: expr "<=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"<=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 422: /* expr: expr ">=" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),">=", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 423: /* expr: expr '&' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"&", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 424: /* expr: expr '|' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"|", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 425: /* expr: expr '^' expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"^", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 426: /* expr: expr "&&" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"&&", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 427: /* expr: expr "||" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"||", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 428: /* expr: expr "^^" expr  */
                                             { (yyval.pExpression) = new ExprOp2(tokAt(scanner,(yylsp[-1])),"^^", ExpressionPtr((yyvsp[-2].pExpression)), ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 429: /* expr: expr ".." expr  */
                                             {
        auto itv = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-1])),"interval");
        itv->arguments.push_back(ExpressionPtr((yyvsp[-2].pExpression)));
        itv->arguments.push_back(ExpressionPtr((yyvsp[0].pExpression)));
        (yyval.pExpression) = itv;
    }
    break;

  case 430: /* expr: "++" expr  */
                                                 { (yyval.pExpression) = new ExprOp1(tokAt(scanner,(yylsp[-1])),"++", ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 431: /* expr: "--" expr  */
                                                 { (yyval.pExpression) = new ExprOp1(tokAt(scanner,(yylsp[-1])),"--", ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 432: /* expr: expr "++"  */
                                                 { (yyval.pExpression) = new ExprOp1(tokAt(scanner,(yylsp[0])),"+++", ExpressionPtr((yyvsp[-1].pExpression))); }
    break;

  case 433: /* expr: expr "--"  */
                                                 { (yyval.pExpression) = new ExprOp1(tokAt(scanner,(yylsp[0])),"---", ExpressionPtr((yyvsp[-1].pExpression))); }
    break;

  case 434: /* expr: '(' expr_list optional_comma ')'  */
                                                         {
            if ( (yyvsp[-2].pExpression)->rtti_isSequence() ) {
                auto mkt = new ExprMakeTuple(tokAt(scanner,(yylsp[-2])));
                mkt->values = sequenceToList((yyvsp[-2].pExpression));
                (yyval.pExpression) = mkt;
            } else if ( (yyvsp[-1].b) ) {
                auto mkt = new ExprMakeTuple(tokAt(scanner,(yylsp[-2])));
                mkt->values.push_back((yyvsp[-2].pExpression));
                (yyval.pExpression) = mkt;
            } else {
                (yyval.pExpression) = (yyvsp[-2].pExpression);
            }
        }
    break;

  case 435: /* expr: expr '[' expr ']'  */
                                                 { (yyval.pExpression) = new ExprAt(tokAt(scanner,(yylsp[-2])), ExpressionPtr((yyvsp[-3].pExpression)), ExpressionPtr((yyvsp[-1].pExpression))); }
    break;

  case 436: /* expr: expr '.' '[' expr ']'  */
                                                     { (yyval.pExpression) = new ExprAt(tokAt(scanner,(yylsp[-2])), ExpressionPtr((yyvsp[-4].pExpression)), ExpressionPtr((yyvsp[-1].pExpression)), true); }
    break;

  case 437: /* expr: expr "?[" expr ']'  */
                                                 { (yyval.pExpression) = new ExprSafeAt(tokAt(scanner,(yylsp[-2])), ExpressionPtr((yyvsp[-3].pExpression)), ExpressionPtr((yyvsp[-1].pExpression))); }
    break;

  case 438: /* expr: expr '.' "?[" expr ']'  */
                                                     { (yyval.pExpression) = new ExprSafeAt(tokAt(scanner,(yylsp[-2])), ExpressionPtr((yyvsp[-4].pExpression)), ExpressionPtr((yyvsp[-1].pExpression)), true); }
    break;

  case 439: /* expr: expr "?." "name"  */
                                                 { (yyval.pExpression) = new ExprSafeField(tokAt(scanner,(yylsp[-1])), tokAt(scanner,(yylsp[0])), ExpressionPtr((yyvsp[-2].pExpression)), *(yyvsp[0].s)); delete (yyvsp[0].s); }
    break;

  case 440: /* expr: expr '.' "?." "name"  */
                                                     { (yyval.pExpression) = new ExprSafeField(tokAt(scanner,(yylsp[-1])), tokAt(scanner,(yylsp[0])), ExpressionPtr((yyvsp[-3].pExpression)), *(yyvsp[0].s), true); delete (yyvsp[0].s); }
    break;

  case 441: /* expr: func_addr_expr  */
                                                 { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 442: /* expr: expr_call  */
                        { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 443: /* expr: '*' expr  */
                                                   { (yyval.pExpression) = new ExprPtr2Ref(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 444: /* expr: "deref" '(' expr ')'  */
                                                   { (yyval.pExpression) = new ExprPtr2Ref(tokAt(scanner,(yylsp[-3])),ExpressionPtr((yyvsp[-1].pExpression))); }
    break;

  case 445: /* expr: "addr" '(' expr ')'  */
                                                   { (yyval.pExpression) = new ExprRef2Ptr(tokAt(scanner,(yylsp[-3])),ExpressionPtr((yyvsp[-1].pExpression))); }
    break;

  case 446: /* expr: expr_generator  */
                                                   { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 447: /* expr: expr "??" expr  */
                                                   { (yyval.pExpression) = new ExprNullCoalescing(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-2].pExpression)),ExpressionPtr((yyvsp[0].pExpression))); }
    break;

  case 448: /* expr: expr '?' expr ':' expr  */
                                                          {
            (yyval.pExpression) = new ExprOp3(tokAt(scanner,(yylsp[-3])),"?",ExpressionPtr((yyvsp[-4].pExpression)),ExpressionPtr((yyvsp[-2].pExpression)),ExpressionPtr((yyvsp[0].pExpression)));
        }
    break;

  case 449: /* $@27: %empty  */
                                               { yyextra->das_arrow_depth ++; }
    break;

  case 450: /* $@28: %empty  */
                                                                                                                      { yyextra->das_arrow_depth --; }
    break;

  case 451: /* expr: expr "is" "type" '<' $@27 type_declaration_no_options '>' $@28  */
                                                                                                                                                       {
        (yyval.pExpression) = new ExprIs(tokAt(scanner,(yylsp[-6])),ExpressionPtr((yyvsp[-7].pExpression)),TypeDeclPtr((yyvsp[-2].pTypeDecl)));
    }
    break;

  case 452: /* expr: expr "is" basic_type_declaration  */
                                                               {
        auto vdecl = new TypeDecl((yyvsp[0].type));
        vdecl->at = tokAt(scanner,(yylsp[0]));
        (yyval.pExpression) = new ExprIs(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-2].pExpression)),vdecl);
    }
    break;

  case 453: /* expr: expr "is" "name"  */
                                              {
        (yyval.pExpression) = new ExprIsVariant(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-2].pExpression)),*(yyvsp[0].s));
        delete (yyvsp[0].s);
    }
    break;

  case 454: /* expr: expr "as" "name"  */
                                              {
        (yyval.pExpression) = new ExprAsVariant(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-2].pExpression)),*(yyvsp[0].s));
        delete (yyvsp[0].s);
    }
    break;

  case 455: /* $@29: %empty  */
                                               { yyextra->das_arrow_depth ++; }
    break;

  case 456: /* $@30: %empty  */
                                                                                                           { yyextra->das_arrow_depth --; }
    break;

  case 457: /* expr: expr "as" "type" '<' $@29 type_declaration '>' $@30  */
                                                                                                                                            {
        auto vname = (yyvsp[-2].pTypeDecl)->describe();
        (yyval.pExpression) = new ExprAsVariant(tokAt(scanner,(yylsp[-6])),ExpressionPtr((yyvsp[-7].pExpression)),vname);
        delete (yyvsp[-2].pTypeDecl);
    }
    break;

  case 458: /* expr: expr "as" basic_type_declaration  */
                                                               {
        (yyval.pExpression) = new ExprAsVariant(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-2].pExpression)),das_to_string((yyvsp[0].type)));
    }
    break;

  case 459: /* expr: expr '?' "as" "name"  */
                                                  {
        (yyval.pExpression) = new ExprSafeAsVariant(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-3].pExpression)),*(yyvsp[0].s));
        delete (yyvsp[0].s);
    }
    break;

  case 460: /* $@31: %empty  */
                                                   { yyextra->das_arrow_depth ++; }
    break;

  case 461: /* $@32: %empty  */
                                                                                                               { yyextra->das_arrow_depth --; }
    break;

  case 462: /* expr: expr '?' "as" "type" '<' $@31 type_declaration '>' $@32  */
                                                                                                                                                {
        auto vname = (yyvsp[-2].pTypeDecl)->describe();
        (yyval.pExpression) = new ExprSafeAsVariant(tokAt(scanner,(yylsp[-6])),ExpressionPtr((yyvsp[-8].pExpression)),vname);
        delete (yyvsp[-2].pTypeDecl);
    }
    break;

  case 463: /* expr: expr '?' "as" basic_type_declaration  */
                                                                   {
        (yyval.pExpression) = new ExprSafeAsVariant(tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-3].pExpression)),das_to_string((yyvsp[0].type)));
    }
    break;

  case 464: /* expr: expr_type_info  */
                                                { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 465: /* expr: expr_type_decl  */
                                                { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 466: /* expr: expr_cast  */
                                                { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 467: /* expr: expr_new  */
                                                { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 468: /* expr: expr_method_call  */
                                                { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 469: /* expr: expr_named_call  */
                                                { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 470: /* expr: expr_full_block  */
                                                { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 471: /* expr: expr "<|" expr  */
                                                { (yyval.pExpression) = ast_lpipe(scanner,(yyvsp[-2].pExpression),(yyvsp[0].pExpression),tokAt(scanner,(yylsp[-1]))); }
    break;

  case 472: /* expr: expr "|>" expr  */
                                                { (yyval.pExpression) = ast_rpipe(scanner,(yyvsp[-2].pExpression),(yyvsp[0].pExpression),tokAt(scanner,(yylsp[-1]))); }
    break;

  case 473: /* expr: expr "|>" basic_type_declaration  */
                                                          {
        auto fncall = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[0])),tokAt(scanner,(yylsp[0])),das_to_string((yyvsp[0].type)));
        (yyval.pExpression) = ast_rpipe(scanner,(yyvsp[-2].pExpression),fncall,tokAt(scanner,(yylsp[-1])));
    }
    break;

  case 474: /* expr: expr_call_pipe  */
                             { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 475: /* expr: "unsafe" '(' expr ')'  */
                                         {
            (yyvsp[-1].pExpression)->alwaysSafe = true;
            (yyvsp[-1].pExpression)->userSaidItsSafe = true;
            (yyval.pExpression) = (yyvsp[-1].pExpression);
        }
    break;

  case 476: /* expr_generator: "generator" '<' type_declaration_no_options '>' optional_capture_list '(' ')'  */
                                                                                                              {
        (yyval.pExpression) = ast_makeGenerator(scanner,(yyvsp[-4].pTypeDecl),(yyvsp[-2].pCaptList),nullptr,tokAt(scanner,(yylsp[-6])));
    }
    break;

  case 477: /* expr_generator: "generator" '<' type_declaration_no_options '>' optional_capture_list '(' expr ')'  */
                                                                                                                            {
        (yyval.pExpression) = ast_makeGenerator(scanner,(yyvsp[-5].pTypeDecl),(yyvsp[-3].pCaptList),(yyvsp[-1].pExpression),tokAt(scanner,(yylsp[-7])));
    }
    break;

  case 478: /* expr_generator: "generator" '<' type_declaration_no_options '>' optional_capture_list optional_emit_semis expression_block  */
                                                                                                                                                  {
        auto closure = new ExprMakeBlock(tokAt(scanner,(yylsp[0])),ExpressionPtr((yyvsp[0].pExpression)));
        ((ExprBlock *)(yyvsp[0].pExpression))->returnType = make_smart<TypeDecl>(Type::autoinfer);
        (yyval.pExpression) = ast_makeGenerator(scanner,(yyvsp[-4].pTypeDecl),(yyvsp[-2].pCaptList),closure,tokAt(scanner,(yylsp[-6])));
    }
    break;

  case 479: /* expr_mtag: "$$" '(' expr ')'  */
                                                     { (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),"e"); }
    break;

  case 480: /* expr_mtag: "$i" '(' expr ')'  */
                                                     { (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),"i"); }
    break;

  case 481: /* expr_mtag: "$v" '(' expr ')'  */
                                                     { (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),"v"); }
    break;

  case 482: /* expr_mtag: "$b" '(' expr ')'  */
                                                     { (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),"b"); }
    break;

  case 483: /* expr_mtag: "$a" '(' expr ')'  */
                                                     { (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),"a"); }
    break;

  case 484: /* expr_mtag: "..."  */
                                                     { (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[0])),nullptr,"..."); }
    break;

  case 485: /* expr_mtag: "$c" '(' expr ')' '(' ')'  */
                                                            {
            auto ccall = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-5])),tokAt(scanner,(yylsp[0])),"``MACRO``TAG``CALL``");
            (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-5])),(yyvsp[-3].pExpression),ccall,"c");
        }
    break;

  case 486: /* expr_mtag: "$c" '(' expr ')' '(' expr_list ')'  */
                                                                                {
            auto ccall = parseFunctionArguments(yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-6])),tokAt(scanner,(yylsp[0])),"``MACRO``TAG``CALL``"),(yyvsp[-1].pExpression));
            (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-6])),(yyvsp[-4].pExpression),ccall,"c");
        }
    break;

  case 487: /* expr_mtag: expr '.' "$f" '(' expr ')'  */
                                                                {
        auto cfield = new ExprField(tokAt(scanner,(yylsp[-4])), tokAt(scanner,(yylsp[-1])), ExpressionPtr((yyvsp[-5].pExpression)), "``MACRO``TAG``FIELD``");
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),cfield,"f");
    }
    break;

  case 488: /* expr_mtag: expr "?." "$f" '(' expr ')'  */
                                                                 {
        auto cfield = new ExprSafeField(tokAt(scanner,(yylsp[-4])), tokAt(scanner,(yylsp[-1])), ExpressionPtr((yyvsp[-5].pExpression)), "``MACRO``TAG``FIELD``");
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),cfield,"f");
    }
    break;

  case 489: /* expr_mtag: expr '.' '.' "$f" '(' expr ')'  */
                                                                    {
        auto cfield = new ExprField(tokAt(scanner,(yylsp[-4])), tokAt(scanner,(yylsp[-1])), ExpressionPtr((yyvsp[-6].pExpression)), "``MACRO``TAG``FIELD``", true);
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),cfield,"f");
    }
    break;

  case 490: /* expr_mtag: expr '.' "?." "$f" '(' expr ')'  */
                                                                     {
        auto cfield = new ExprSafeField(tokAt(scanner,(yylsp[-4])), tokAt(scanner,(yylsp[-1])), ExpressionPtr((yyvsp[-6].pExpression)), "``MACRO``TAG``FIELD``", true);
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),cfield,"f");
    }
    break;

  case 491: /* expr_mtag: expr "as" "$f" '(' expr ')'  */
                                                                   {
        auto cfield = new ExprAsVariant(tokAt(scanner,(yylsp[-4])),ExpressionPtr((yyvsp[-5].pExpression)),"``MACRO``TAG``FIELD``");
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),cfield,"f");
    }
    break;

  case 492: /* expr_mtag: expr '?' "as" "$f" '(' expr ')'  */
                                                                       {
        auto cfield = new ExprSafeAsVariant(tokAt(scanner,(yylsp[-4])),ExpressionPtr((yyvsp[-6].pExpression)),"``MACRO``TAG``FIELD``");
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),cfield,"f");
    }
    break;

  case 493: /* expr_mtag: expr "is" "$f" '(' expr ')'  */
                                                                   {
        auto cfield = new ExprIsVariant(tokAt(scanner,(yylsp[-4])),ExpressionPtr((yyvsp[-5].pExpression)),"``MACRO``TAG``FIELD``");
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression),cfield,"f");
    }
    break;

  case 494: /* expr_mtag: '@' '@' "$c" '(' expr ')'  */
                                                         {
        auto ccall = new ExprAddr(tokAt(scanner,(yylsp[-4])),"``MACRO``TAG``ADDR``");
        (yyval.pExpression) = new ExprTag(tokAt(scanner,(yylsp[-3])),(yyvsp[-1].pExpression),ccall,"c");
    }
    break;

  case 495: /* optional_field_annotation: %empty  */
                                      { (yyval.aaList) = nullptr; }
    break;

  case 496: /* optional_field_annotation: metadata_argument_list  */
                                      { (yyval.aaList) = (yyvsp[0].aaList); }
    break;

  case 497: /* optional_override: %empty  */
                      { (yyval.i) = OVERRIDE_NONE; }
    break;

  case 498: /* optional_override: "override"  */
                      { (yyval.i) = OVERRIDE_OVERRIDE; }
    break;

  case 499: /* optional_override: "sealed"  */
                      { (yyval.i) = OVERRIDE_SEALED; }
    break;

  case 500: /* optional_constant: %empty  */
                        { (yyval.b) = false; }
    break;

  case 501: /* optional_constant: "const"  */
                        { (yyval.b) = true; }
    break;

  case 502: /* optional_public_or_private_member_variable: %empty  */
                        { (yyval.b) = false; }
    break;

  case 503: /* optional_public_or_private_member_variable: "public"  */
                        { (yyval.b) = false; }
    break;

  case 504: /* optional_public_or_private_member_variable: "private"  */
                        { (yyval.b) = true; }
    break;

  case 505: /* optional_static_member_variable: %empty  */
                        { (yyval.b) = false; }
    break;

  case 506: /* optional_static_member_variable: "static"  */
                        { (yyval.b) = true; }
    break;

  case 507: /* structure_variable_declaration: optional_field_annotation optional_static_member_variable optional_override optional_public_or_private_member_variable variable_declaration  */
                                                                                                                                                                                      {
        (yyvsp[0].pVarDecl)->override = (yyvsp[-2].i) == OVERRIDE_OVERRIDE;
        (yyvsp[0].pVarDecl)->sealed = (yyvsp[-2].i) == OVERRIDE_SEALED;
        (yyvsp[0].pVarDecl)->annotation = (yyvsp[-4].aaList);
        (yyvsp[0].pVarDecl)->isPrivate = (yyvsp[-1].b);
        (yyvsp[0].pVarDecl)->isStatic = (yyvsp[-3].b);
        (yyval.pVarDecl) = (yyvsp[0].pVarDecl);
    }
    break;

  case 508: /* struct_variable_declaration_list: %empty  */
        {
        (yyval.pVarDeclList) = new vector<VariableDeclaration*>();
    }
    break;

  case 509: /* struct_variable_declaration_list: struct_variable_declaration_list "emitted ;"  */
                                                                 { (yyval.pVarDeclList) = (yyvsp[-1].pVarDeclList); }
    break;

  case 510: /* $@33: %empty  */
                                               {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeStructureFields(tak);
        }
    }
    break;

  case 511: /* struct_variable_declaration_list: struct_variable_declaration_list $@33 structure_variable_declaration SEMICOLON  */
                                                     {
        (yyval.pVarDeclList) = (yyvsp[-3].pVarDeclList);
        if ( (yyvsp[-1].pVarDecl) ) (yyvsp[-3].pVarDeclList)->push_back((yyvsp[-1].pVarDecl));
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[-3]));
            for ( auto & crd : yyextra->g_CommentReaders ) {
                for ( const auto & nl : *((yyvsp[-1].pVarDecl)->pNameList) ) {
                    crd->afterStructureField(nl.name.c_str(), nl.at);
                }
            }
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterStructureFields(tak);
        }
    }
    break;

  case 512: /* $@34: %empty  */
                                                                                                                     {
                if ( !yyextra->g_CommentReaders.empty() ) {
                    auto tak = tokAt(scanner,(yylsp[-2]));
                    for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeFunction(tak);
                }
            }
    break;

  case 513: /* struct_variable_declaration_list: struct_variable_declaration_list optional_annotation_list_with_emit_semis "def" optional_public_or_private_member_variable "abstract" optional_constant $@34 function_declaration_header SEMICOLON  */
                                                          {
                if ( !yyextra->g_CommentReaders.empty() ) {
                    auto tak = tokAt(scanner,(yylsp[-1]));
                    for ( auto & crd : yyextra->g_CommentReaders ) crd->afterFunction((yyvsp[-1].pFuncDecl),tak);
                }
                (yyval.pVarDeclList) = ast_structVarDefAbstract(scanner,(yyvsp[-8].pVarDeclList),(yyvsp[-7].faList),(yyvsp[-5].b),(yyvsp[-3].b), (yyvsp[-1].pFuncDecl));
            }
    break;

  case 514: /* $@35: %empty  */
                                                                                                                                                                         {
                if ( !yyextra->g_CommentReaders.empty() ) {
                    auto tak = tokAt(scanner,(yylsp[0]));
                    for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeFunction(tak);
                }
            }
    break;

  case 515: /* struct_variable_declaration_list: struct_variable_declaration_list optional_annotation_list_with_emit_semis "def" optional_public_or_private_member_variable optional_static_member_variable optional_override optional_constant $@35 function_declaration_header optional_emit_semis expression_block  */
                                                                                            {
                if ( !yyextra->g_CommentReaders.empty() ) {
                    auto tak = tokAt(scanner,(yylsp[0]));
                    for ( auto & crd : yyextra->g_CommentReaders ) crd->afterFunction((yyvsp[-2].pFuncDecl),tak);
                }
                (yyval.pVarDeclList) = ast_structVarDef(scanner,(yyvsp[-10].pVarDeclList),(yyvsp[-9].faList),(yyvsp[-6].b),(yyvsp[-7].b),(yyvsp[-5].i),(yyvsp[-4].b),(yyvsp[-2].pFuncDecl),(yyvsp[0].pExpression),tokRangeAt(scanner,(yylsp[-8]),(yylsp[0])),tokAt(scanner,(yylsp[-9])));
            }
    break;

  case 516: /* function_argument_declaration: optional_field_annotation kwd_let_var_or_nothing variable_declaration  */
                                                                                                  {
            (yyval.pVarDecl) = (yyvsp[0].pVarDecl);
            if ( (yyvsp[-1].b) ) {
                (yyvsp[0].pVarDecl)->pTypeDecl->constant = true;
            } else {
                (yyvsp[0].pVarDecl)->pTypeDecl->removeConstant = true;
            }
            (yyvsp[0].pVarDecl)->annotation = (yyvsp[-2].aaList);
        }
    break;

  case 517: /* function_argument_declaration: "$a" '(' expr ')'  */
                                     {
            auto na = new vector<VariableNameAndPosition>();
            na->push_back(VariableNameAndPosition{"``MACRO``TAG``","",tokAt(scanner,(yylsp[-1]))});
            auto decl = new VariableDeclaration(na, new TypeDecl(Type::none), (yyvsp[-1].pExpression));
            decl->pTypeDecl->isTag = true;
            (yyval.pVarDecl) = decl;
        }
    break;

  case 518: /* function_argument_list: function_argument_declaration  */
                                                                                 { (yyval.pVarDeclList) = new vector<VariableDeclaration*>(); (yyval.pVarDeclList)->push_back((yyvsp[0].pVarDecl)); }
    break;

  case 519: /* function_argument_list: function_argument_list ';' function_argument_declaration  */
                                                                                 { (yyval.pVarDeclList) = (yyvsp[-2].pVarDeclList); (yyvsp[-2].pVarDeclList)->push_back((yyvsp[0].pVarDecl)); }
    break;

  case 520: /* tuple_type: type_declaration  */
                                    {
        (yyval.pVarDecl) = new VariableDeclaration(nullptr,(yyvsp[0].pTypeDecl),nullptr);
    }
    break;

  case 521: /* tuple_type: "name" ':' type_declaration  */
                                                   {
        auto na = new vector<VariableNameAndPosition>();
        na->push_back(VariableNameAndPosition{*(yyvsp[-2].s),"",tokAt(scanner,(yylsp[-2]))});
        (yyval.pVarDecl) = new VariableDeclaration(na,(yyvsp[0].pTypeDecl),nullptr);
        delete (yyvsp[-2].s);
    }
    break;

  case 522: /* tuple_type_list: tuple_type  */
                                                       { (yyval.pVarDeclList) = new vector<VariableDeclaration*>(); (yyval.pVarDeclList)->push_back((yyvsp[0].pVarDecl)); }
    break;

  case 523: /* tuple_type_list: tuple_type_list c_or_s tuple_type  */
                                                       { (yyval.pVarDeclList) = (yyvsp[-2].pVarDeclList); (yyvsp[-2].pVarDeclList)->push_back((yyvsp[0].pVarDecl)); }
    break;

  case 524: /* tuple_alias_type_list: %empty  */
      {
        (yyval.pVarDeclList) = new vector<VariableDeclaration*>();
    }
    break;

  case 525: /* tuple_alias_type_list: tuple_type  */
                       {
        (yyval.pVarDeclList) = new vector<VariableDeclaration*>();
        (yyval.pVarDeclList)->push_back((yyvsp[0].pVarDecl));
    }
    break;

  case 526: /* tuple_alias_type_list: tuple_alias_type_list semis tuple_type  */
                                                         {
        (yyval.pVarDeclList) = (yyvsp[-2].pVarDeclList); (yyvsp[-2].pVarDeclList)->push_back((yyvsp[0].pVarDecl));
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tokName = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) {
                for ( const auto & nl : *((yyvsp[0].pVarDecl)->pNameList) ) {
                    crd->afterTupleEntry(nl.name.c_str(), nl.at);
                }
            }
        }
    }
    break;

  case 527: /* variant_type: "name" ':' type_declaration  */
                                                   {
        auto na = new vector<VariableNameAndPosition>();
        na->push_back(VariableNameAndPosition{*(yyvsp[-2].s),"",tokAt(scanner,(yylsp[-2]))});
        (yyval.pVarDecl) = new VariableDeclaration(na,(yyvsp[0].pTypeDecl),nullptr);
        delete (yyvsp[-2].s);
    }
    break;

  case 528: /* variant_type_list: variant_type  */
                                                         { (yyval.pVarDeclList) = new vector<VariableDeclaration*>(); (yyval.pVarDeclList)->push_back((yyvsp[0].pVarDecl)); }
    break;

  case 529: /* variant_type_list: variant_type_list c_or_s variant_type  */
                                                            { (yyval.pVarDeclList) = (yyvsp[-2].pVarDeclList); (yyvsp[-2].pVarDeclList)->push_back((yyvsp[0].pVarDecl)); }
    break;

  case 530: /* variant_alias_type_list: %empty  */
        {
        (yyval.pVarDeclList) = new vector<VariableDeclaration*>();
    }
    break;

  case 531: /* variant_alias_type_list: variant_type  */
                         {
        (yyval.pVarDeclList) = new vector<VariableDeclaration*>();
        (yyval.pVarDeclList)->push_back((yyvsp[0].pVarDecl));
    }
    break;

  case 532: /* variant_alias_type_list: variant_alias_type_list semis variant_type  */
                                                               {
        (yyval.pVarDeclList) = (yyvsp[-2].pVarDeclList); (yyvsp[-2].pVarDeclList)->push_back((yyvsp[0].pVarDecl));
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tokName = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) {
                for ( const auto & nl : *((yyvsp[0].pVarDecl)->pNameList) ) {
                    crd->afterVariantEntry(nl.name.c_str(), nl.at);
                }
            }
        }
    }
    break;

  case 533: /* copy_or_move: '='  */
                    { (yyval.b) = false; }
    break;

  case 534: /* copy_or_move: "<-"  */
                    { (yyval.b) = true; }
    break;

  case 535: /* variable_declaration: variable_name_with_pos_list  */
                                          {
        auto autoT = new TypeDecl(Type::autoinfer);
        autoT->at = tokAt(scanner,(yylsp[0]));
        autoT->ref = false;
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[0].pNameWithPosList),autoT,nullptr);
    }
    break;

  case 536: /* variable_declaration: variable_name_with_pos_list '&'  */
                                              {
        auto autoT = new TypeDecl(Type::autoinfer);
        autoT->at = tokAt(scanner,(yylsp[-1]));
        autoT->ref = true;
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-1].pNameWithPosList),autoT,nullptr);
    }
    break;

  case 537: /* variable_declaration: variable_name_with_pos_list ':' type_declaration  */
                                                                          {
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-2].pNameWithPosList),(yyvsp[0].pTypeDecl),nullptr);
    }
    break;

  case 538: /* variable_declaration: variable_name_with_pos_list ':' type_declaration copy_or_move expr  */
                                                                                                      {
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-4].pNameWithPosList),(yyvsp[-2].pTypeDecl),(yyvsp[0].pExpression));
        (yyval.pVarDecl)->init_via_move = (yyvsp[-1].b);
    }
    break;

  case 539: /* variable_declaration: variable_name_with_pos_list copy_or_move expr  */
                                                                       {
        auto typeDecl = new TypeDecl(Type::autoinfer);
        typeDecl->at = tokAt(scanner,(yylsp[-2]));
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-2].pNameWithPosList),typeDecl,(yyvsp[0].pExpression));
        (yyval.pVarDecl)->init_via_move = (yyvsp[-1].b);
    }
    break;

  case 540: /* copy_or_move_or_clone: '='  */
                    { (yyval.i) = CorM_COPY; }
    break;

  case 541: /* copy_or_move_or_clone: "<-"  */
                    { (yyval.i) = CorM_MOVE; }
    break;

  case 542: /* copy_or_move_or_clone: ":="  */
                    { (yyval.i) = CorM_CLONE; }
    break;

  case 543: /* optional_ref: %empty  */
            { (yyval.b) = false; }
    break;

  case 544: /* optional_ref: '&'  */
            { (yyval.b) = true; }
    break;

  case 545: /* let_variable_name_with_pos_list: "name"  */
                    {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        auto pSL = new vector<VariableNameAndPosition>();
        pSL->push_back(VariableNameAndPosition{*(yyvsp[0].s),"",tokAt(scanner,(yylsp[0]))});
        (yyval.pNameWithPosList) = pSL;
        delete (yyvsp[0].s);
    }
    break;

  case 546: /* let_variable_name_with_pos_list: "$i" '(' expr ')'  */
                                     {
        auto pSL = new vector<VariableNameAndPosition>();
        pSL->push_back(VariableNameAndPosition{"``MACRO``TAG``","",tokAt(scanner,(yylsp[-1])),ExpressionPtr((yyvsp[-1].pExpression))});
        (yyval.pNameWithPosList) = pSL;
    }
    break;

  case 547: /* let_variable_name_with_pos_list: "name" "aka" "name"  */
                                         {
        das_checkName(scanner,*(yyvsp[-2].s),tokAt(scanner,(yylsp[-2])));
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        auto pSL = new vector<VariableNameAndPosition>();
        pSL->push_back(VariableNameAndPosition{*(yyvsp[-2].s),*(yyvsp[0].s),tokAt(scanner,(yylsp[-2]))});
        (yyval.pNameWithPosList) = pSL;
        delete (yyvsp[-2].s);
        delete (yyvsp[0].s);
    }
    break;

  case 548: /* let_variable_name_with_pos_list: let_variable_name_with_pos_list ',' "name"  */
                                                             {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyvsp[-2].pNameWithPosList)->push_back(VariableNameAndPosition{*(yyvsp[0].s),"",tokAt(scanner,(yylsp[0]))});
        (yyval.pNameWithPosList) = (yyvsp[-2].pNameWithPosList);
        delete (yyvsp[0].s);
    }
    break;

  case 549: /* let_variable_name_with_pos_list: let_variable_name_with_pos_list ',' "name" "aka" "name"  */
                                                                                   {
        das_checkName(scanner,*(yyvsp[-2].s),tokAt(scanner,(yylsp[-2])));
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyvsp[-4].pNameWithPosList)->push_back(VariableNameAndPosition{*(yyvsp[-2].s),*(yyvsp[0].s),tokAt(scanner,(yylsp[-2]))});
        (yyval.pNameWithPosList) = (yyvsp[-4].pNameWithPosList);
        delete (yyvsp[-2].s);
        delete (yyvsp[0].s);
    }
    break;

  case 550: /* global_let_variable_name_with_pos_list: "name"  */
                    {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        auto pSL = new vector<VariableNameAndPosition>();
        pSL->push_back(VariableNameAndPosition{*(yyvsp[0].s),"",tokAt(scanner,(yylsp[0]))});
        (yyval.pNameWithPosList) = pSL;
        delete (yyvsp[0].s);
    }
    break;

  case 551: /* global_let_variable_name_with_pos_list: global_let_variable_name_with_pos_list ',' "name"  */
                                                                    {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyvsp[-2].pNameWithPosList)->push_back(VariableNameAndPosition{*(yyvsp[0].s),"",tokAt(scanner,(yylsp[0]))});
        (yyval.pNameWithPosList) = (yyvsp[-2].pNameWithPosList);
        delete (yyvsp[0].s);
    }
    break;

  case 552: /* variable_declaration_list: %empty  */
        {
        (yyval.pVarDeclList) = new vector<VariableDeclaration*>();
    }
    break;

  case 553: /* variable_declaration_list: variable_declaration_list SEMICOLON  */
                                                  {
        (yyval.pVarDeclList) = (yyvsp[-1].pVarDeclList);
    }
    break;

  case 554: /* variable_declaration_list: variable_declaration_list let_variable_declaration  */
                                                                       {
        (yyval.pVarDeclList) = (yyvsp[-1].pVarDeclList);
        (yyvsp[-1].pVarDeclList)->push_back((yyvsp[0].pVarDecl));
    }
    break;

  case 555: /* let_variable_declaration: let_variable_name_with_pos_list ':' type_declaration_no_options SEMICOLON  */
                                                                                                  {
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-3].pNameWithPosList),(yyvsp[-1].pTypeDecl),nullptr);
    }
    break;

  case 556: /* let_variable_declaration: let_variable_name_with_pos_list ':' type_declaration_no_options copy_or_move_or_clone expr SEMICOLON  */
                                                                                                                                        {
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-5].pNameWithPosList),(yyvsp[-3].pTypeDecl),(yyvsp[-1].pExpression));
        (yyval.pVarDecl)->init_via_move  = ((yyvsp[-2].i) & CorM_MOVE) !=0;
        (yyval.pVarDecl)->init_via_clone = ((yyvsp[-2].i) & CorM_CLONE) !=0;
    }
    break;

  case 557: /* let_variable_declaration: let_variable_name_with_pos_list optional_ref copy_or_move_or_clone expr SEMICOLON  */
                                                                                                                {
        auto typeDecl = new TypeDecl(Type::autoinfer);
        typeDecl->at = tokAt(scanner,(yylsp[-4]));
        typeDecl->ref = (yyvsp[-3].b);
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-4].pNameWithPosList),typeDecl,(yyvsp[-1].pExpression));
        (yyval.pVarDecl)->init_via_move  = ((yyvsp[-2].i) & CorM_MOVE) !=0;
        (yyval.pVarDecl)->init_via_clone = ((yyvsp[-2].i) & CorM_CLONE) !=0;
    }
    break;

  case 558: /* global_let_variable_declaration: global_let_variable_name_with_pos_list ':' type_declaration_no_options SEMICOLON  */
                                                                                                         {
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-3].pNameWithPosList),(yyvsp[-1].pTypeDecl),nullptr);
    }
    break;

  case 559: /* global_let_variable_declaration: global_let_variable_name_with_pos_list ':' type_declaration_no_options copy_or_move_or_clone expr SEMICOLON  */
                                                                                                                                               {
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-5].pNameWithPosList),(yyvsp[-3].pTypeDecl),(yyvsp[-1].pExpression));
        (yyval.pVarDecl)->init_via_move  = ((yyvsp[-2].i) & CorM_MOVE) !=0;
        (yyval.pVarDecl)->init_via_clone = ((yyvsp[-2].i) & CorM_CLONE) !=0;
    }
    break;

  case 560: /* global_let_variable_declaration: global_let_variable_name_with_pos_list optional_ref copy_or_move_or_clone expr SEMICOLON  */
                                                                                                                       {
        auto typeDecl = new TypeDecl(Type::autoinfer);
        typeDecl->at = tokAt(scanner,(yylsp[-4]));
        typeDecl->ref = (yyvsp[-3].b);
        (yyval.pVarDecl) = new VariableDeclaration((yyvsp[-4].pNameWithPosList),typeDecl,(yyvsp[-1].pExpression));
        (yyval.pVarDecl)->init_via_move  = ((yyvsp[-2].i) & CorM_MOVE) !=0;
        (yyval.pVarDecl)->init_via_clone = ((yyvsp[-2].i) & CorM_CLONE) !=0;
    }
    break;

  case 561: /* optional_shared: %empty  */
                     { (yyval.b) = false; }
    break;

  case 562: /* optional_shared: "shared"  */
                     { (yyval.b) = true; }
    break;

  case 563: /* optional_public_or_private_variable: %empty  */
                     { (yyval.b) = yyextra->g_Program->thisModule->isPublic; }
    break;

  case 564: /* optional_public_or_private_variable: "private"  */
                     { (yyval.b) = false; }
    break;

  case 565: /* optional_public_or_private_variable: "public"  */
                     { (yyval.b) = true; }
    break;

  case 566: /* global_variable_declaration_list: %empty  */
        {
        (yyval.pVarDeclList) = new vector<VariableDeclaration*>();
    }
    break;

  case 567: /* global_variable_declaration_list: global_variable_declaration_list SEMICOLON  */
                                                         {
        (yyval.pVarDeclList) = (yyvsp[-1].pVarDeclList);
    }
    break;

  case 568: /* $@36: %empty  */
                                               {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeGlobalVariables(tak);
        }
    }
    break;

  case 569: /* global_variable_declaration_list: global_variable_declaration_list $@36 optional_field_annotation let_variable_declaration  */
                                                                      {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders )
                for ( auto & nl : *((yyvsp[0].pVarDecl)->pNameList) )
                    crd->afterGlobalVariable(nl.name.c_str(),tak);
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterGlobalVariables(tak);
        }
        (yyval.pVarDeclList) = (yyvsp[-3].pVarDeclList);
        (yyvsp[0].pVarDecl)->annotation = (yyvsp[-1].aaList);
        (yyvsp[-3].pVarDeclList)->push_back((yyvsp[0].pVarDecl));
    }
    break;

  case 570: /* global_let: kwd_let optional_shared optional_public_or_private_variable '{' global_variable_declaration_list '}'  */
                                                                                                                                       {
        ast_globalLetList(scanner,(yyvsp[-5].b),(yyvsp[-4].b),(yyvsp[-3].b),(yyvsp[-1].pVarDeclList));
    }
    break;

  case 571: /* $@37: %empty  */
                                                                                        {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeGlobalVariables(tak);
        }
    }
    break;

  case 572: /* global_let: kwd_let optional_shared optional_public_or_private_variable $@37 optional_field_annotation global_let_variable_declaration  */
                                                                           {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders )
                for ( auto & nl : *((yyvsp[0].pVarDecl)->pNameList) )
                    crd->afterGlobalVariable(nl.name.c_str(),tak);
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterGlobalVariables(tak);
        }
        ast_globalLet(scanner,(yyvsp[-5].b),(yyvsp[-4].b),(yyvsp[-3].b),(yyvsp[-1].aaList),(yyvsp[0].pVarDecl));
    }
    break;

  case 573: /* enum_expression: "name"  */
                   {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyval.pEnumPair) = new EnumPair((yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        delete (yyvsp[0].s);
    }
    break;

  case 574: /* enum_expression: "name" '=' expr  */
                                   {
        das_checkName(scanner,*(yyvsp[-2].s),tokAt(scanner,(yylsp[-2])));
        (yyval.pEnumPair) = new EnumPair((yyvsp[-2].s),(yyvsp[0].pExpression),tokAt(scanner,(yylsp[-2])));
        delete (yyvsp[-2].s);
    }
    break;

  case 577: /* enum_list: %empty  */
        {
        (yyval.pEnum) = new Enumeration();
    }
    break;

  case 578: /* enum_list: enum_expression  */
                            {
        (yyval.pEnum) = new Enumeration();
        if ( !(yyval.pEnum)->add((yyvsp[0].pEnumPair)->name,(yyvsp[0].pEnumPair)->expr,(yyvsp[0].pEnumPair)->at) ) {
            das2_yyerror(scanner,"enumeration already declared " + (yyvsp[0].pEnumPair)->name, (yyvsp[0].pEnumPair)->at,
                CompilationError::enumeration_value_already_declared);
        }
        if ( !yyextra->g_CommentReaders.empty() ) {
            for ( auto & crd : yyextra->g_CommentReaders ) {
                crd->afterEnumerationEntry((yyvsp[0].pEnumPair)->name.c_str(), (yyvsp[0].pEnumPair)->at);
            }
        }
        delete (yyvsp[0].pEnumPair);
    }
    break;

  case 579: /* enum_list: enum_list commas enum_expression  */
                                                 {
        if ( !(yyvsp[-2].pEnum)->add((yyvsp[0].pEnumPair)->name,(yyvsp[0].pEnumPair)->expr,(yyvsp[0].pEnumPair)->at) ) {
            das2_yyerror(scanner,"enumeration already declared " + (yyvsp[0].pEnumPair)->name, (yyvsp[0].pEnumPair)->at,
                CompilationError::enumeration_value_already_declared);
        }
        if ( !yyextra->g_CommentReaders.empty() ) {
            for ( auto & crd : yyextra->g_CommentReaders ) {
                crd->afterEnumerationEntry((yyvsp[0].pEnumPair)->name.c_str(), (yyvsp[0].pEnumPair)->at);
            }
        }
        delete (yyvsp[0].pEnumPair);
        (yyval.pEnum) = (yyvsp[-2].pEnum);
    }
    break;

  case 580: /* optional_public_or_private_alias: %empty  */
                     { (yyval.b) = yyextra->g_Program->thisModule->isPublic; }
    break;

  case 581: /* optional_public_or_private_alias: "private"  */
                     { (yyval.b) = false; }
    break;

  case 582: /* optional_public_or_private_alias: "public"  */
                     { (yyval.b) = true; }
    break;

  case 583: /* $@38: %empty  */
                                                         {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto pubename = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeAlias(pubename);
        }
    }
    break;

  case 584: /* single_alias: optional_public_or_private_alias "name" $@38 '=' type_declaration  */
                                  {
        das_checkName(scanner,*(yyvsp[-3].s),tokAt(scanner,(yylsp[-3])));
        (yyvsp[0].pTypeDecl)->isPrivateAlias = !(yyvsp[-4].b);
        if ( (yyvsp[0].pTypeDecl)->baseType == Type::alias ) {
            das2_yyerror(scanner,"alias cannot be defined in terms of another alias "+*(yyvsp[-3].s),tokAt(scanner,(yylsp[-3])),
                CompilationError::invalid_type);
        }
        (yyvsp[0].pTypeDecl)->alias = *(yyvsp[-3].s);
        if ( !yyextra->g_Program->addAlias(TypeDeclPtr((yyvsp[0].pTypeDecl))) ) {
            das2_yyerror(scanner,"type alias is already defined "+*(yyvsp[-3].s),tokAt(scanner,(yylsp[-3])),
                CompilationError::type_alias_already_declared);
        }
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto pubename = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterAlias((yyvsp[-3].s)->c_str(),pubename);
        }
        delete (yyvsp[-3].s);
    }
    break;

  case 586: /* optional_public_or_private_enum: %empty  */
                     { (yyval.b) = yyextra->g_Program->thisModule->isPublic; }
    break;

  case 587: /* optional_public_or_private_enum: "private"  */
                     { (yyval.b) = false; }
    break;

  case 588: /* optional_public_or_private_enum: "public"  */
                     { (yyval.b) = true; }
    break;

  case 589: /* enum_name: "name"  */
                   {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto pubename = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeEnumeration(pubename);
        }
        (yyval.pEnum) = ast_addEmptyEnum(scanner, (yyvsp[0].s), tokAt(scanner,(yylsp[0])));
    }
    break;

  case 590: /* optional_enum_basic_type_declaration: %empty  */
        {
        (yyval.type) = Type::tInt;
    }
    break;

  case 591: /* optional_enum_basic_type_declaration: ':' enum_basic_type_declaration  */
                                              {
        (yyval.type) = (yyvsp[0].type);
    }
    break;

  case 598: /* $@39: %empty  */
                                                     {
        yyextra->push_nesteds(DAS_EMIT_COMMA);
    }
    break;

  case 599: /* $@40: %empty  */
                                                                                                                                {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[-3]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeEnumerationEntries(tak);
        }
    }
    break;

  case 600: /* $@41: %empty  */
                                    {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[-1]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterEnumerationEntries(tak);
        }
        yyextra->pop_nesteds();
    }
    break;

  case 601: /* enum_declaration: optional_annotation_list "enum" $@39 optional_public_or_private_enum enum_name optional_enum_basic_type_declaration optional_emit_commas '{' $@40 enum_list optional_commas $@41 '}'  */
          {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto pubename = tokAt(scanner,(yylsp[-3]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterEnumeration((yyvsp[-8].pEnum)->name.c_str(),pubename);
        }
        ast_enumDeclaration(scanner,(yyvsp[-12].faList),tokAt(scanner,(yylsp[-12])),(yyvsp[-9].b),(yyvsp[-8].pEnum),(yyvsp[-3].pEnum),(yyvsp[-7].type));
    }
    break;

  case 602: /* optional_structure_parent: %empty  */
                                        { (yyval.s) = nullptr; }
    break;

  case 603: /* optional_structure_parent: ':' name_in_namespace  */
                                        { (yyval.s) = (yyvsp[0].s); }
    break;

  case 604: /* optional_sealed: %empty  */
                        { (yyval.b) = false; }
    break;

  case 605: /* optional_sealed: "sealed"  */
                        { (yyval.b) = true; }
    break;

  case 606: /* structure_name: optional_sealed "name" optional_structure_parent  */
                                                                           {
        (yyval.pStructure) = ast_structureName(scanner,(yyvsp[-2].b),(yyvsp[-1].s),tokAt(scanner,(yylsp[-1])),(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
    }
    break;

  case 607: /* class_or_struct: "class"  */
                    { (yyval.b) = true; }
    break;

  case 608: /* class_or_struct: "struct"  */
                    { (yyval.b) = false; }
    break;

  case 609: /* optional_public_or_private_structure: %empty  */
                     { (yyval.b) = yyextra->g_Program->thisModule->isPublic; }
    break;

  case 610: /* optional_public_or_private_structure: "private"  */
                     { (yyval.b) = false; }
    break;

  case 611: /* optional_public_or_private_structure: "public"  */
                     { (yyval.b) = true; }
    break;

  case 612: /* optional_struct_variable_declaration_list: ';'  */
            {
        (yyval.pVarDeclList) = new vector<VariableDeclaration*>();
    }
    break;

  case 613: /* optional_struct_variable_declaration_list: '{' struct_variable_declaration_list '}'  */
                                                       {
        (yyval.pVarDeclList) = (yyvsp[-1].pVarDeclList);
    }
    break;

  case 614: /* $@42: %empty  */
                                                     {
        yyextra->push_nesteds(DAS_EMIT_SEMICOLON);
    }
    break;

  case 615: /* $@43: %empty  */
                                                                         {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto tak = tokAt(scanner,(yylsp[-1]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeStructure(tak);
        }
    }
    break;

  case 616: /* $@44: %empty  */
                                             { if ( (yyvsp[-1].pStructure) ) { (yyvsp[-1].pStructure)->isClass = (yyvsp[-4].b); (yyvsp[-1].pStructure)->privateStructure = !(yyvsp[-3].b); } }
    break;

  case 617: /* structure_declaration: optional_annotation_list_with_emit_semis $@42 class_or_struct optional_public_or_private_structure $@43 structure_name optional_emit_semis $@44 optional_struct_variable_declaration_list  */
                                                                                                                                                                        {
        yyextra->pop_nesteds();
        if ( (yyvsp[-3].pStructure) ) {
            ast_structureDeclaration ( scanner, (yyvsp[-8].faList), tokAt(scanner,(yylsp[-6])), (yyvsp[-3].pStructure), tokAt(scanner,(yylsp[-3])), (yyvsp[0].pVarDeclList) );
            if ( !yyextra->g_CommentReaders.empty() ) {
                auto tak = tokAt(scanner,(yylsp[-6]));
                for ( auto & crd : yyextra->g_CommentReaders ) crd->afterStructure((yyvsp[-3].pStructure),tak);
            }
        } else {
            deleteVariableDeclarationList((yyvsp[0].pVarDeclList));
        }
    }
    break;

  case 618: /* variable_name_with_pos_list: "name"  */
                    {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        auto pSL = new vector<VariableNameAndPosition>();
        pSL->push_back(VariableNameAndPosition{*(yyvsp[0].s),"",tokAt(scanner,(yylsp[0]))});
        (yyval.pNameWithPosList) = pSL;
        delete (yyvsp[0].s);
    }
    break;

  case 619: /* variable_name_with_pos_list: "$i" '(' expr ')'  */
                                     {
        auto pSL = new vector<VariableNameAndPosition>();
        pSL->push_back(VariableNameAndPosition{"``MACRO``TAG``","",tokAt(scanner,(yylsp[-1])),(yyvsp[-1].pExpression)});
        (yyval.pNameWithPosList) = pSL;
    }
    break;

  case 620: /* variable_name_with_pos_list: "name" "aka" "name"  */
                                         {
        das_checkName(scanner,*(yyvsp[-2].s),tokAt(scanner,(yylsp[-2])));
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        auto pSL = new vector<VariableNameAndPosition>();
        pSL->push_back(VariableNameAndPosition{*(yyvsp[-2].s),*(yyvsp[0].s),tokAt(scanner,(yylsp[-2]))});
        (yyval.pNameWithPosList) = pSL;
        delete (yyvsp[-2].s);
        delete (yyvsp[0].s);
    }
    break;

  case 621: /* variable_name_with_pos_list: variable_name_with_pos_list ',' "name"  */
                                                         {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyvsp[-2].pNameWithPosList)->push_back(VariableNameAndPosition{*(yyvsp[0].s),"",tokAt(scanner,(yylsp[0]))});
        (yyval.pNameWithPosList) = (yyvsp[-2].pNameWithPosList);
        delete (yyvsp[0].s);
    }
    break;

  case 622: /* variable_name_with_pos_list: variable_name_with_pos_list ',' "name" "aka" "name"  */
                                                                               {
        das_checkName(scanner,*(yyvsp[-2].s),tokAt(scanner,(yylsp[-2])));
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyvsp[-4].pNameWithPosList)->push_back(VariableNameAndPosition{*(yyvsp[-2].s),*(yyvsp[0].s),tokAt(scanner,(yylsp[-2]))});
        (yyval.pNameWithPosList) = (yyvsp[-4].pNameWithPosList);
        delete (yyvsp[-2].s);
        delete (yyvsp[0].s);
    }
    break;

  case 623: /* basic_type_declaration: "bool"  */
                        { (yyval.type) = Type::tBool; }
    break;

  case 624: /* basic_type_declaration: "string"  */
                        { (yyval.type) = Type::tString; }
    break;

  case 625: /* basic_type_declaration: "int"  */
                        { (yyval.type) = Type::tInt; }
    break;

  case 626: /* basic_type_declaration: "int8"  */
                        { (yyval.type) = Type::tInt8; }
    break;

  case 627: /* basic_type_declaration: "int16"  */
                        { (yyval.type) = Type::tInt16; }
    break;

  case 628: /* basic_type_declaration: "int64"  */
                        { (yyval.type) = Type::tInt64; }
    break;

  case 629: /* basic_type_declaration: "int2"  */
                        { (yyval.type) = Type::tInt2; }
    break;

  case 630: /* basic_type_declaration: "int3"  */
                        { (yyval.type) = Type::tInt3; }
    break;

  case 631: /* basic_type_declaration: "int4"  */
                        { (yyval.type) = Type::tInt4; }
    break;

  case 632: /* basic_type_declaration: "uint"  */
                        { (yyval.type) = Type::tUInt; }
    break;

  case 633: /* basic_type_declaration: "uint8"  */
                        { (yyval.type) = Type::tUInt8; }
    break;

  case 634: /* basic_type_declaration: "uint16"  */
                        { (yyval.type) = Type::tUInt16; }
    break;

  case 635: /* basic_type_declaration: "uint64"  */
                        { (yyval.type) = Type::tUInt64; }
    break;

  case 636: /* basic_type_declaration: "uint2"  */
                        { (yyval.type) = Type::tUInt2; }
    break;

  case 637: /* basic_type_declaration: "uint3"  */
                        { (yyval.type) = Type::tUInt3; }
    break;

  case 638: /* basic_type_declaration: "uint4"  */
                        { (yyval.type) = Type::tUInt4; }
    break;

  case 639: /* basic_type_declaration: "float"  */
                        { (yyval.type) = Type::tFloat; }
    break;

  case 640: /* basic_type_declaration: "float2"  */
                        { (yyval.type) = Type::tFloat2; }
    break;

  case 641: /* basic_type_declaration: "float3"  */
                        { (yyval.type) = Type::tFloat3; }
    break;

  case 642: /* basic_type_declaration: "float4"  */
                        { (yyval.type) = Type::tFloat4; }
    break;

  case 643: /* basic_type_declaration: "void"  */
                        { (yyval.type) = Type::tVoid; }
    break;

  case 644: /* basic_type_declaration: "range"  */
                        { (yyval.type) = Type::tRange; }
    break;

  case 645: /* basic_type_declaration: "urange"  */
                        { (yyval.type) = Type::tURange; }
    break;

  case 646: /* basic_type_declaration: "range64"  */
                        { (yyval.type) = Type::tRange64; }
    break;

  case 647: /* basic_type_declaration: "urange64"  */
                        { (yyval.type) = Type::tURange64; }
    break;

  case 648: /* basic_type_declaration: "double"  */
                        { (yyval.type) = Type::tDouble; }
    break;

  case 649: /* basic_type_declaration: "bitfield"  */
                        { (yyval.type) = Type::tBitfield; }
    break;

  case 650: /* enum_basic_type_declaration: "int"  */
                        { (yyval.type) = Type::tInt; }
    break;

  case 651: /* enum_basic_type_declaration: "int8"  */
                        { (yyval.type) = Type::tInt8; }
    break;

  case 652: /* enum_basic_type_declaration: "int16"  */
                        { (yyval.type) = Type::tInt16; }
    break;

  case 653: /* enum_basic_type_declaration: "uint"  */
                        { (yyval.type) = Type::tUInt; }
    break;

  case 654: /* enum_basic_type_declaration: "uint8"  */
                        { (yyval.type) = Type::tUInt8; }
    break;

  case 655: /* enum_basic_type_declaration: "uint16"  */
                        { (yyval.type) = Type::tUInt16; }
    break;

  case 656: /* enum_basic_type_declaration: "int64"  */
                        { (yyval.type) = Type::tInt64; }
    break;

  case 657: /* enum_basic_type_declaration: "uint64"  */
                        { (yyval.type) = Type::tUInt64; }
    break;

  case 658: /* structure_type_declaration: name_in_namespace  */
                                 {
        (yyval.pTypeDecl) = yyextra->g_Program->makeTypeDeclaration(tokAt(scanner,(yylsp[0])),*(yyvsp[0].s));
        if ( !(yyval.pTypeDecl) ) {
            (yyval.pTypeDecl) = new TypeDecl(Type::tVoid);
            (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[0]));
        }
        delete (yyvsp[0].s);
    }
    break;

  case 659: /* auto_type_declaration: "auto"  */
                       {
        (yyval.pTypeDecl) = new TypeDecl(Type::autoinfer);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[0]));
    }
    break;

  case 660: /* auto_type_declaration: "auto" '(' "name" ')'  */
                                            {
        das_checkName(scanner,*(yyvsp[-1].s),tokAt(scanner,(yylsp[-1])));
        (yyval.pTypeDecl) = new TypeDecl(Type::autoinfer);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-3]));
        (yyval.pTypeDecl)->alias = *(yyvsp[-1].s);
        delete (yyvsp[-1].s);
    }
    break;

  case 661: /* auto_type_declaration: "$t" '(' expr ')'  */
                                          {
        (yyval.pTypeDecl) = new TypeDecl(Type::alias);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-3]));
        (yyval.pTypeDecl)->alias = "``MACRO``TAG``";
        (yyval.pTypeDecl)->isTag = true;
        (yyval.pTypeDecl)->firstType = new TypeDecl(Type::autoinfer);
        (yyval.pTypeDecl)->firstType->at = tokAt(scanner, (yylsp[-1]));
        (yyval.pTypeDecl)->firstType->dimExpr.push_back((yyvsp[-1].pExpression));
    }
    break;

  case 662: /* bitfield_bits: "name"  */
                    {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        auto pSL = new vector<string>();
        pSL->push_back(*(yyvsp[0].s));
        (yyval.pNameList) = pSL;
        delete (yyvsp[0].s);
    }
    break;

  case 663: /* bitfield_bits: bitfield_bits ';' "name"  */
                                           {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyvsp[-2].pNameList)->push_back(*(yyvsp[0].s));
        (yyval.pNameList) = (yyvsp[-2].pNameList);
        delete (yyvsp[0].s);
    }
    break;

  case 664: /* bitfield_alias_bits: %empty  */
        {
        auto pSL = new vector<string>();
        (yyval.pNameList) = pSL;

    }
    break;

  case 665: /* bitfield_alias_bits: "name"  */
                   {
        (yyval.pNameList) = new vector<string>();
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyval.pNameList)->push_back(*(yyvsp[0].s));
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterBitfieldEntry((yyvsp[0].s)->c_str(),atvname);
        }
        delete (yyvsp[0].s);
    }
    break;

  case 666: /* bitfield_alias_bits: bitfield_alias_bits commas "name"  */
                                                    {
        das_checkName(scanner,*(yyvsp[0].s),tokAt(scanner,(yylsp[0])));
        (yyvsp[-2].pNameList)->push_back(*(yyvsp[0].s));
        (yyval.pNameList) = (yyvsp[-2].pNameList);
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[0]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterBitfieldEntry((yyvsp[0].s)->c_str(),atvname);
        }
        delete (yyvsp[0].s);
    }
    break;

  case 667: /* $@45: %empty  */
                                     { yyextra->das_arrow_depth ++; }
    break;

  case 668: /* $@46: %empty  */
                                                                                            { yyextra->das_arrow_depth --; }
    break;

  case 669: /* bitfield_type_declaration: "bitfield" '<' $@45 bitfield_bits '>' $@46  */
                                                                                                                             {
            (yyval.pTypeDecl) = new TypeDecl(Type::tBitfield);
            (yyval.pTypeDecl)->argNames = *(yyvsp[-2].pNameList);
            if ( (yyval.pTypeDecl)->argNames.size()>32 ) {
                das2_yyerror(scanner,"only 32 different bits are allowed in a bitfield",tokAt(scanner,(yylsp[-5])),
                    CompilationError::invalid_type);
            }
            (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
            delete (yyvsp[-2].pNameList);
    }
    break;

  case 672: /* table_type_pair: type_declaration  */
                                      {
        (yyval.aTypePair).firstType = (yyvsp[0].pTypeDecl);
        (yyval.aTypePair).secondType = new TypeDecl(Type::tVoid);
    }
    break;

  case 673: /* table_type_pair: type_declaration c_or_s type_declaration  */
                                                                             {
        (yyval.aTypePair).firstType = (yyvsp[-2].pTypeDecl);
        (yyval.aTypePair).secondType = (yyvsp[0].pTypeDecl);
    }
    break;

  case 674: /* dim_list: '[' expr ']'  */
                             {
        (yyval.pTypeDecl) = new TypeDecl(Type::autoinfer);
        appendDimExpr((yyval.pTypeDecl), (yyvsp[-1].pExpression));
    }
    break;

  case 675: /* dim_list: '[' ']'  */
                {
        (yyval.pTypeDecl) = new TypeDecl(Type::autoinfer);
        appendDimExpr((yyval.pTypeDecl), nullptr);
    }
    break;

  case 676: /* dim_list: dim_list '[' expr ']'  */
                                            {
        (yyval.pTypeDecl) = (yyvsp[-3].pTypeDecl);
        appendDimExpr((yyval.pTypeDecl), (yyvsp[-1].pExpression));
    }
    break;

  case 677: /* dim_list: dim_list '[' ']'  */
                              {
        (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
        appendDimExpr((yyval.pTypeDecl), nullptr);
    }
    break;

  case 678: /* type_declaration_no_options: type_declaration_no_options_no_dim  */
                                                     {
        (yyval.pTypeDecl) = (yyvsp[0].pTypeDecl);
    }
    break;

  case 679: /* type_declaration_no_options: type_declaration_no_options_no_dim dim_list  */
                                                                       {
        if ( (yyvsp[-1].pTypeDecl)->baseType==Type::typeDecl ) {
            das2_yyerror(scanner,"type declaration can`t be used as array base type",tokAt(scanner,(yylsp[-1])),
                CompilationError::invalid_type);
        } else if ( (yyvsp[-1].pTypeDecl)->baseType==Type::typeMacro ) {
            das2_yyerror(scanner,"macro can`t be used as array base type",tokAt(scanner,(yylsp[-1])),
                CompilationError::invalid_type);
        }
        (yyvsp[-1].pTypeDecl)->dim.insert((yyvsp[-1].pTypeDecl)->dim.begin(), (yyvsp[0].pTypeDecl)->dim.begin(), (yyvsp[0].pTypeDecl)->dim.end());
        (yyvsp[-1].pTypeDecl)->dimExpr.insert((yyvsp[-1].pTypeDecl)->dimExpr.begin(), (yyvsp[0].pTypeDecl)->dimExpr.begin(), (yyvsp[0].pTypeDecl)->dimExpr.end());
        (yyvsp[-1].pTypeDecl)->removeDim = false;
        (yyval.pTypeDecl) = (yyvsp[-1].pTypeDecl);
        (yyvsp[0].pTypeDecl)->dimExpr.clear();
        delete (yyvsp[0].pTypeDecl);
    }
    break;

  case 680: /* type_declaration_no_options_no_dim: basic_type_declaration  */
                                                            { (yyval.pTypeDecl) = new TypeDecl((yyvsp[0].type)); (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[0])); }
    break;

  case 681: /* type_declaration_no_options_no_dim: auto_type_declaration  */
                                                            { (yyval.pTypeDecl) = (yyvsp[0].pTypeDecl); }
    break;

  case 682: /* type_declaration_no_options_no_dim: bitfield_type_declaration  */
                                                            { (yyval.pTypeDecl) = (yyvsp[0].pTypeDecl); }
    break;

  case 683: /* type_declaration_no_options_no_dim: structure_type_declaration  */
                                                            { (yyval.pTypeDecl) = (yyvsp[0].pTypeDecl); }
    break;

  case 684: /* $@47: %empty  */
                     { yyextra->das_arrow_depth ++; }
    break;

  case 685: /* $@48: %empty  */
                                                                                     { yyextra->das_arrow_depth --; }
    break;

  case 686: /* type_declaration_no_options_no_dim: "type" '<' $@47 type_declaration '>' $@48  */
                                                                                                                      {
        (yyvsp[-2].pTypeDecl)->autoToAlias = true;
        (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
    }
    break;

  case 687: /* type_declaration_no_options_no_dim: "typedecl" '(' expr ')'  */
                                               {
        (yyval.pTypeDecl) = new TypeDecl(Type::typeDecl);
        (yyval.pTypeDecl)->at = tokRangeAt(scanner,(yylsp[-3]),(yylsp[-1]));
        (yyval.pTypeDecl)->dimExpr.push_back((yyvsp[-1].pExpression));
    }
    break;

  case 688: /* type_declaration_no_options_no_dim: '$' name_in_namespace '(' optional_expr_list ')'  */
                                                                          {
        (yyval.pTypeDecl) = new TypeDecl(Type::typeMacro);
        (yyval.pTypeDecl)->at = tokRangeAt(scanner,(yylsp[-3]), (yylsp[-1]));
        (yyval.pTypeDecl)->dimExpr = sequenceToList((yyvsp[-1].pExpression));
        (yyval.pTypeDecl)->dimExpr.insert((yyval.pTypeDecl)->dimExpr.begin(), new ExprConstString(tokAt(scanner,(yylsp[-3])), *(yyvsp[-3].s)));
        delete (yyvsp[-3].s);
    }
    break;

  case 689: /* $@49: %empty  */
                                        { yyextra->das_arrow_depth ++; }
    break;

  case 690: /* type_declaration_no_options_no_dim: '$' name_in_namespace '<' $@49 type_declaration_no_options_list '>' '(' optional_expr_list ')'  */
                                                                                                                                                           {
        (yyval.pTypeDecl) = new TypeDecl(Type::typeMacro);
        (yyval.pTypeDecl)->at = tokRangeAt(scanner,(yylsp[-7]), (yylsp[-1]));
        (yyval.pTypeDecl)->dimExpr = typesAndSequenceToList((yyvsp[-4].pTypeDeclList),(yyvsp[-1].pExpression));
        (yyval.pTypeDecl)->dimExpr.insert((yyval.pTypeDecl)->dimExpr.begin(), new ExprConstString(tokAt(scanner,(yylsp[-7])), *(yyvsp[-7].s)));
        delete (yyvsp[-7].s);
    }
    break;

  case 691: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim '-' '[' ']'  */
                                                                 {
        (yyvsp[-3].pTypeDecl)->removeDim = true;
        (yyval.pTypeDecl) = (yyvsp[-3].pTypeDecl);
    }
    break;

  case 692: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim "explicit"  */
                                                                  {
        (yyvsp[-1].pTypeDecl)->isExplicit = true;
        (yyval.pTypeDecl) = (yyvsp[-1].pTypeDecl);
    }
    break;

  case 693: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim "const"  */
                                                               {
        (yyvsp[-1].pTypeDecl)->constant = true;
        (yyvsp[-1].pTypeDecl)->removeConstant = false;
        (yyval.pTypeDecl) = (yyvsp[-1].pTypeDecl);
    }
    break;

  case 694: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim '-' "const"  */
                                                                   {
        (yyvsp[-2].pTypeDecl)->constant = false;
        (yyvsp[-2].pTypeDecl)->removeConstant = true;
        (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
    }
    break;

  case 695: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim '&'  */
                                                         {
        (yyvsp[-1].pTypeDecl)->ref = true;
        (yyvsp[-1].pTypeDecl)->removeRef = false;
        (yyval.pTypeDecl) = (yyvsp[-1].pTypeDecl);
    }
    break;

  case 696: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim '-' '&'  */
                                                             {
        (yyvsp[-2].pTypeDecl)->ref = false;
        (yyvsp[-2].pTypeDecl)->removeRef = true;
        (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
    }
    break;

  case 697: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim '#'  */
                                                         {
        (yyval.pTypeDecl) = (yyvsp[-1].pTypeDecl);
        (yyval.pTypeDecl)->temporary = true;
    }
    break;

  case 698: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim "implicit"  */
                                                                  {
        (yyval.pTypeDecl) = (yyvsp[-1].pTypeDecl);
        (yyval.pTypeDecl)->implicit = true;
    }
    break;

  case 699: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim '-' '#'  */
                                                             {
        (yyvsp[-2].pTypeDecl)->temporary = false;
        (yyvsp[-2].pTypeDecl)->removeTemporary = true;
        (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
    }
    break;

  case 700: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim "==" "const"  */
                                                                      {
        (yyvsp[-2].pTypeDecl)->explicitConst = true;
        (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
    }
    break;

  case 701: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim "==" '&'  */
                                                                {
        (yyvsp[-2].pTypeDecl)->explicitRef = true;
        (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
    }
    break;

  case 702: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim '?'  */
                                                         {
        (yyval.pTypeDecl) = new TypeDecl(Type::tPointer);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-1]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-1].pTypeDecl));
    }
    break;

  case 703: /* $@50: %empty  */
                               { yyextra->das_arrow_depth ++; }
    break;

  case 704: /* $@51: %empty  */
                                                                                               { yyextra->das_arrow_depth --; }
    break;

  case 705: /* type_declaration_no_options_no_dim: "smart_ptr" '<' $@50 type_declaration '>' $@51  */
                                                                                                                                {
        (yyval.pTypeDecl) = new TypeDecl(Type::tPointer);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        (yyval.pTypeDecl)->smartPtr = true;
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
    }
    break;

  case 706: /* type_declaration_no_options_no_dim: type_declaration_no_options_no_dim "??"  */
                                                        {
        (yyval.pTypeDecl) = new TypeDecl(Type::tPointer);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-1]));
        (yyval.pTypeDecl)->firstType = make_smart<TypeDecl>(Type::tPointer);
        (yyval.pTypeDecl)->firstType->at = tokAt(scanner,(yylsp[-1]));
        (yyval.pTypeDecl)->firstType->firstType = TypeDeclPtr((yyvsp[-1].pTypeDecl));
    }
    break;

  case 707: /* $@52: %empty  */
                           { yyextra->das_arrow_depth ++; }
    break;

  case 708: /* $@53: %empty  */
                                                                                           { yyextra->das_arrow_depth --; }
    break;

  case 709: /* type_declaration_no_options_no_dim: "array" '<' $@52 type_declaration '>' $@53  */
                                                                                                                            {
        (yyval.pTypeDecl) = new TypeDecl(Type::tArray);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
    }
    break;

  case 710: /* $@54: %empty  */
                           { yyextra->das_arrow_depth ++; }
    break;

  case 711: /* $@55: %empty  */
                                                                                     { yyextra->das_arrow_depth --; }
    break;

  case 712: /* type_declaration_no_options_no_dim: "table" '<' $@54 table_type_pair '>' $@55  */
                                                                                                                      {
        (yyval.pTypeDecl) = new TypeDecl(Type::tTable);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].aTypePair).firstType);
        (yyval.pTypeDecl)->secondType = TypeDeclPtr((yyvsp[-2].aTypePair).secondType);
    }
    break;

  case 713: /* $@56: %empty  */
                               { yyextra->das_arrow_depth ++; }
    break;

  case 714: /* $@57: %empty  */
                                                                                                 { yyextra->das_arrow_depth --; }
    break;

  case 715: /* type_declaration_no_options_no_dim: "iterator" '<' $@56 type_declaration '>' $@57  */
                                                                                                                                  {
        (yyval.pTypeDecl) = new TypeDecl(Type::tIterator);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
    }
    break;

  case 716: /* type_declaration_no_options_no_dim: "block"  */
                        {
        (yyval.pTypeDecl) = new TypeDecl(Type::tBlock);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[0]));
    }
    break;

  case 717: /* $@58: %empty  */
                             { yyextra->das_arrow_depth ++; }
    break;

  case 718: /* $@59: %empty  */
                                                                                              { yyextra->das_arrow_depth --; }
    break;

  case 719: /* type_declaration_no_options_no_dim: "block" '<' $@58 type_declaration '>' $@59  */
                                                                                                                               {
        (yyval.pTypeDecl) = new TypeDecl(Type::tBlock);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
    }
    break;

  case 720: /* $@60: %empty  */
                             { yyextra->das_arrow_depth ++; }
    break;

  case 721: /* $@61: %empty  */
                                                                                                                                       { yyextra->das_arrow_depth --; }
    break;

  case 722: /* type_declaration_no_options_no_dim: "block" '<' $@60 optional_function_argument_list optional_function_type '>' $@61  */
                                                                                                                                                                        {
        (yyval.pTypeDecl) = new TypeDecl(Type::tBlock);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-6]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
        if ( (yyvsp[-3].pVarDeclList) ) {
            varDeclToTypeDecl(scanner, (yyval.pTypeDecl), (yyvsp[-3].pVarDeclList));
            deleteVariableDeclarationList((yyvsp[-3].pVarDeclList));
        }
    }
    break;

  case 723: /* type_declaration_no_options_no_dim: "function"  */
                           {
        (yyval.pTypeDecl) = new TypeDecl(Type::tFunction);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[0]));
    }
    break;

  case 724: /* $@62: %empty  */
                               { yyextra->das_arrow_depth ++; }
    break;

  case 725: /* $@63: %empty  */
                                                                                                { yyextra->das_arrow_depth --; }
    break;

  case 726: /* type_declaration_no_options_no_dim: "function" '<' $@62 type_declaration '>' $@63  */
                                                                                                                                 {
        (yyval.pTypeDecl) = new TypeDecl(Type::tFunction);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
    }
    break;

  case 727: /* $@64: %empty  */
                               { yyextra->das_arrow_depth ++; }
    break;

  case 728: /* $@65: %empty  */
                                                                                                                                         { yyextra->das_arrow_depth --; }
    break;

  case 729: /* type_declaration_no_options_no_dim: "function" '<' $@64 optional_function_argument_list optional_function_type '>' $@65  */
                                                                                                                                                                          {
        (yyval.pTypeDecl) = new TypeDecl(Type::tFunction);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-6]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
        if ( (yyvsp[-3].pVarDeclList) ) {
            varDeclToTypeDecl(scanner, (yyval.pTypeDecl), (yyvsp[-3].pVarDeclList));
            deleteVariableDeclarationList((yyvsp[-3].pVarDeclList));
        }
    }
    break;

  case 730: /* type_declaration_no_options_no_dim: "lambda"  */
                         {
        (yyval.pTypeDecl) = new TypeDecl(Type::tLambda);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[0]));
    }
    break;

  case 731: /* $@66: %empty  */
                             { yyextra->das_arrow_depth ++; }
    break;

  case 732: /* $@67: %empty  */
                                                                                              { yyextra->das_arrow_depth --; }
    break;

  case 733: /* type_declaration_no_options_no_dim: "lambda" '<' $@66 type_declaration '>' $@67  */
                                                                                                                               {
        (yyval.pTypeDecl) = new TypeDecl(Type::tLambda);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
    }
    break;

  case 734: /* $@68: %empty  */
                             { yyextra->das_arrow_depth ++; }
    break;

  case 735: /* $@69: %empty  */
                                                                                                                                       { yyextra->das_arrow_depth --; }
    break;

  case 736: /* type_declaration_no_options_no_dim: "lambda" '<' $@68 optional_function_argument_list optional_function_type '>' $@69  */
                                                                                                                                                                        {
        (yyval.pTypeDecl) = new TypeDecl(Type::tLambda);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-6]));
        (yyval.pTypeDecl)->firstType = TypeDeclPtr((yyvsp[-2].pTypeDecl));
        if ( (yyvsp[-3].pVarDeclList) ) {
            varDeclToTypeDecl(scanner, (yyval.pTypeDecl), (yyvsp[-3].pVarDeclList));
            deleteVariableDeclarationList((yyvsp[-3].pVarDeclList));
        }
    }
    break;

  case 737: /* $@70: %empty  */
                            { yyextra->das_arrow_depth ++; }
    break;

  case 738: /* $@71: %empty  */
                                                                                       { yyextra->das_arrow_depth --; }
    break;

  case 739: /* type_declaration_no_options_no_dim: "tuple" '<' $@70 tuple_type_list '>' $@71  */
                                                                                                                        {
        (yyval.pTypeDecl) = new TypeDecl(Type::tTuple);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        varDeclToTypeDecl(scanner, (yyval.pTypeDecl), (yyvsp[-2].pVarDeclList), true);
        deleteVariableDeclarationList((yyvsp[-2].pVarDeclList));
    }
    break;

  case 740: /* $@72: %empty  */
                              { yyextra->das_arrow_depth ++; }
    break;

  case 741: /* $@73: %empty  */
                                                                                           { yyextra->das_arrow_depth --; }
    break;

  case 742: /* type_declaration_no_options_no_dim: "variant" '<' $@72 variant_type_list '>' $@73  */
                                                                                                                            {
        (yyval.pTypeDecl) = new TypeDecl(Type::tVariant);
        (yyval.pTypeDecl)->at = tokAt(scanner,(yylsp[-5]));
        varDeclToTypeDecl(scanner, (yyval.pTypeDecl), (yyvsp[-2].pVarDeclList), true);
        deleteVariableDeclarationList((yyvsp[-2].pVarDeclList));
    }
    break;

  case 743: /* type_declaration: type_declaration_no_options  */
                                        {
        (yyval.pTypeDecl) = (yyvsp[0].pTypeDecl);
    }
    break;

  case 744: /* type_declaration: type_declaration '|' type_declaration_no_options  */
                                                                     {
        if ( (yyvsp[-2].pTypeDecl)->baseType==Type::option ) {
            (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
            (yyval.pTypeDecl)->argTypes.push_back((yyvsp[0].pTypeDecl));
        } else {
            (yyval.pTypeDecl) = new TypeDecl(Type::option);
            (yyval.pTypeDecl)->at = tokRangeAt(scanner,(yylsp[-2]),(yylsp[0]));
            (yyval.pTypeDecl)->argTypes.push_back((yyvsp[-2].pTypeDecl));
            (yyval.pTypeDecl)->argTypes.push_back((yyvsp[0].pTypeDecl));
        }
    }
    break;

  case 745: /* type_declaration: type_declaration '|' '#'  */
                                             {
        if ( (yyvsp[-2].pTypeDecl)->baseType==Type::option ) {
            (yyval.pTypeDecl) = (yyvsp[-2].pTypeDecl);
            (yyval.pTypeDecl)->argTypes.push_back(make_smart<TypeDecl>(*(yyvsp[-2].pTypeDecl)->argTypes.back()));
            (yyvsp[-2].pTypeDecl)->argTypes.back()->temporary ^= true;
        } else {
            (yyval.pTypeDecl) = new TypeDecl(Type::option);
            (yyval.pTypeDecl)->at = tokRangeAt(scanner,(yylsp[-2]),(yylsp[0]));
            (yyval.pTypeDecl)->argTypes.push_back((yyvsp[-2].pTypeDecl));
            (yyval.pTypeDecl)->argTypes.push_back(make_smart<TypeDecl>(*(yyvsp[-2].pTypeDecl)));
            (yyval.pTypeDecl)->argTypes.back()->temporary ^= true;
        }
    }
    break;

  case 746: /* $@74: %empty  */
                   {
        yyextra->push_nesteds(DAS_EMIT_SEMICOLON);
    }
    break;

  case 747: /* $@75: %empty  */
                                                                             {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-1]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeTuple(atvname);
        }
    }
    break;

  case 748: /* $@76: %empty  */
          {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-3]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeTupleEntries(atvname);
        }
    }
    break;

  case 749: /* $@77: %empty  */
                                                 {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-6]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterTupleEntries(atvname);
        }
        yyextra->pop_nesteds();
    }
    break;

  case 750: /* tuple_alias_declaration: "tuple" $@74 optional_public_or_private_alias "name" optional_emit_semis $@75 '{' $@76 tuple_alias_type_list optional_semis $@77 '}'  */
          {
        auto vtype = make_smart<TypeDecl>(Type::tTuple);
        vtype->alias = *(yyvsp[-8].s);
        vtype->at = tokAt(scanner,(yylsp[-8]));
        vtype->isPrivateAlias = !(yyvsp[-9].b);
        varDeclToTypeDecl(scanner, vtype.get(), (yyvsp[-3].pVarDeclList), true);
        deleteVariableDeclarationList((yyvsp[-3].pVarDeclList));
        if ( !yyextra->g_Program->addAlias(vtype) ) {
            das2_yyerror(scanner,"type alias is already defined "+*(yyvsp[-8].s),tokAt(scanner,(yylsp[-8])),
                CompilationError::type_alias_already_declared);
        }
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-8]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterTuple((yyvsp[-8].s)->c_str(),atvname);
        }
        delete (yyvsp[-8].s);
    }
    break;

  case 751: /* $@78: %empty  */
                     {
        yyextra->push_nesteds(DAS_EMIT_SEMICOLON);
    }
    break;

  case 752: /* $@79: %empty  */
                                                                             {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-1]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeVariant(atvname);
        }
    }
    break;

  case 753: /* $@80: %empty  */
          {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-3]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeVariantEntries(atvname);
        }

    }
    break;

  case 754: /* $@81: %empty  */
                                                   {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-6]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterVariantEntries(atvname);
        }
        yyextra->pop_nesteds();
    }
    break;

  case 755: /* variant_alias_declaration: "variant" $@78 optional_public_or_private_alias "name" optional_emit_semis $@79 '{' $@80 variant_alias_type_list optional_semis $@81 '}'  */
          {
        auto vtype = make_smart<TypeDecl>(Type::tVariant);
        vtype->alias = *(yyvsp[-8].s);
        vtype->at = tokAt(scanner,(yylsp[-8]));
        vtype->isPrivateAlias = !(yyvsp[-9].b);
        varDeclToTypeDecl(scanner, vtype.get(), (yyvsp[-3].pVarDeclList), true);
        deleteVariableDeclarationList((yyvsp[-3].pVarDeclList));
        if ( !yyextra->g_Program->addAlias(vtype) ) {
            das2_yyerror(scanner,"type alias is already defined "+*(yyvsp[-8].s),tokAt(scanner,(yylsp[-8])),
                CompilationError::type_alias_already_declared);
        }
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-8]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterVariant((yyvsp[-8].s)->c_str(),atvname);
        }
        delete (yyvsp[-8].s);
    }
    break;

  case 756: /* $@82: %empty  */
                      {
        yyextra->push_nesteds(DAS_EMIT_COMMA);
    }
    break;

  case 757: /* $@83: %empty  */
                                                                              {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-1]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeBitfield(atvname);
        }
    }
    break;

  case 758: /* $@84: %empty  */
          {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-3]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->beforeBitfieldEntries(atvname);
        }
    }
    break;

  case 759: /* $@85: %empty  */
                                                {
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-6]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterBitfieldEntries(atvname);
        }
        yyextra->pop_nesteds();
    }
    break;

  case 760: /* bitfield_alias_declaration: "bitfield" $@82 optional_public_or_private_alias "name" optional_emit_commas $@83 '{' $@84 bitfield_alias_bits optional_commas $@85 '}'  */
          {
        auto btype = make_smart<TypeDecl>(Type::tBitfield);
        btype->alias = *(yyvsp[-8].s);
        btype->at = tokAt(scanner,(yylsp[-8]));
        btype->argNames = *(yyvsp[-3].pNameList);
        btype->isPrivateAlias = !(yyvsp[-9].b);
        if ( btype->argNames.size()>32 ) {
            das2_yyerror(scanner,"only 32 different bits are allowed in a bitfield",tokAt(scanner,(yylsp[-8])),
                CompilationError::invalid_type);
        }
        if ( !yyextra->g_Program->addAlias(btype) ) {
            das2_yyerror(scanner,"type alias is already defined "+*(yyvsp[-8].s),tokAt(scanner,(yylsp[-8])),
                CompilationError::type_alias_already_declared);
        }
        if ( !yyextra->g_CommentReaders.empty() ) {
            auto atvname = tokAt(scanner,(yylsp[-8]));
            for ( auto & crd : yyextra->g_CommentReaders ) crd->afterBitfield((yyvsp[-8].s)->c_str(),atvname);
        }
        delete (yyvsp[-8].s);
        delete (yyvsp[-3].pNameList);
    }
    break;

  case 761: /* make_decl: make_struct_decl  */
                                 { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 762: /* make_decl: make_dim_decl  */
                                 { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 763: /* make_decl: make_table_decl  */
                                 { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 764: /* make_decl: array_comprehension  */
                                 { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 765: /* make_decl: make_tuple_call  */
                                 { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 766: /* make_struct_fields: "name" copy_or_move expr  */
                                               {
        auto mfd = make_smart<MakeFieldDecl>(tokAt(scanner,(yylsp[-2])),*(yyvsp[-2].s),ExpressionPtr((yyvsp[0].pExpression)),(yyvsp[-1].b),false);
        delete (yyvsp[-2].s);
        auto msd = new MakeStruct();
        msd->push_back(mfd);
        (yyval.pMakeStruct) = msd;
    }
    break;

  case 767: /* make_struct_fields: "name" ":=" expr  */
                                      {
        auto mfd = make_smart<MakeFieldDecl>(tokAt(scanner,(yylsp[-2])),*(yyvsp[-2].s),ExpressionPtr((yyvsp[0].pExpression)),false,true);
        delete (yyvsp[-2].s);
        auto msd = new MakeStruct();
        msd->push_back(mfd);
        (yyval.pMakeStruct) = msd;
    }
    break;

  case 768: /* make_struct_fields: make_struct_fields ',' "name" copy_or_move expr  */
                                                                           {
        auto mfd = make_smart<MakeFieldDecl>(tokAt(scanner,(yylsp[-2])),*(yyvsp[-2].s),ExpressionPtr((yyvsp[0].pExpression)),(yyvsp[-1].b),false);
        delete (yyvsp[-2].s);
        ((MakeStruct *)(yyvsp[-4].pMakeStruct))->push_back(mfd);
        (yyval.pMakeStruct) = (yyvsp[-4].pMakeStruct);
    }
    break;

  case 769: /* make_struct_fields: make_struct_fields ',' "name" ":=" expr  */
                                                                  {
        auto mfd = make_smart<MakeFieldDecl>(tokAt(scanner,(yylsp[-2])),*(yyvsp[-2].s),ExpressionPtr((yyvsp[0].pExpression)),false,true);
        delete (yyvsp[-2].s);
        ((MakeStruct *)(yyvsp[-4].pMakeStruct))->push_back(mfd);
        (yyval.pMakeStruct) = (yyvsp[-4].pMakeStruct);
    }
    break;

  case 770: /* make_struct_fields: "$f" '(' expr ')' copy_or_move expr  */
                                                                   {
        auto mfd = make_smart<MakeFieldDecl>(tokAt(scanner,(yylsp[-3])),"``MACRO``TAG``FIELD``",ExpressionPtr((yyvsp[0].pExpression)),(yyvsp[-1].b),false);
        mfd->tag = ExpressionPtr((yyvsp[-3].pExpression));
        auto msd = new MakeStruct();
        msd->push_back(mfd);
        (yyval.pMakeStruct) = msd;
    }
    break;

  case 771: /* make_struct_fields: "$f" '(' expr ')' ":=" expr  */
                                                          {
        auto mfd = make_smart<MakeFieldDecl>(tokAt(scanner,(yylsp[-3])),"``MACRO``TAG``FIELD``",ExpressionPtr((yyvsp[0].pExpression)),false,true);
        mfd->tag = ExpressionPtr((yyvsp[-3].pExpression));
        auto msd = new MakeStruct();
        msd->push_back(mfd);
        (yyval.pMakeStruct) = msd;
    }
    break;

  case 772: /* make_struct_fields: make_struct_fields ',' "$f" '(' expr ')' copy_or_move expr  */
                                                                                               {
        auto mfd = make_smart<MakeFieldDecl>(tokAt(scanner,(yylsp[-3])),"``MACRO``TAG``FIELD``",ExpressionPtr((yyvsp[0].pExpression)),(yyvsp[-1].b),false);
        mfd->tag = ExpressionPtr((yyvsp[-3].pExpression));
        ((MakeStruct *)(yyvsp[-7].pMakeStruct))->push_back(mfd);
        (yyval.pMakeStruct) = (yyvsp[-7].pMakeStruct);
    }
    break;

  case 773: /* make_struct_fields: make_struct_fields ',' "$f" '(' expr ')' ":=" expr  */
                                                                                      {
        auto mfd = make_smart<MakeFieldDecl>(tokAt(scanner,(yylsp[-3])),"``MACRO``TAG``FIELD``",ExpressionPtr((yyvsp[0].pExpression)),false,true);
        mfd->tag = ExpressionPtr((yyvsp[-3].pExpression));
        ((MakeStruct *)(yyvsp[-7].pMakeStruct))->push_back(mfd);
        (yyval.pMakeStruct) = (yyvsp[-7].pMakeStruct);
    }
    break;

  case 774: /* make_variant_dim: make_struct_fields  */
                                {
        (yyval.pExpression) = ast_makeStructToMakeVariant((yyvsp[0].pMakeStruct), tokAt(scanner,(yylsp[0])));
    }
    break;

  case 775: /* make_struct_single: make_struct_fields  */
                                {
        auto msd = new ExprMakeStruct();
        msd->structs.push_back(MakeStructPtr((yyvsp[0].pMakeStruct)));
        (yyval.pExpression) = msd;
    }
    break;

  case 776: /* make_struct_dim_list: '(' make_struct_fields ')'  */
                                        {
        auto msd = new ExprMakeStruct();
        msd->structs.push_back(MakeStructPtr((yyvsp[-1].pMakeStruct)));
        (yyval.pExpression) = msd;
    }
    break;

  case 777: /* make_struct_dim_list: make_struct_dim_list ',' '(' make_struct_fields ')'  */
                                                                     {
        ((ExprMakeStruct *) (yyvsp[-4].pExpression))->structs.push_back(MakeStructPtr((yyvsp[-1].pMakeStruct)));
        (yyval.pExpression) = (yyvsp[-4].pExpression);
    }
    break;

  case 778: /* make_struct_dim_decl: make_struct_fields  */
                                {
        auto msd = new ExprMakeStruct();
        msd->structs.push_back(MakeStructPtr((yyvsp[0].pMakeStruct)));
        (yyval.pExpression) = msd;
    }
    break;

  case 779: /* make_struct_dim_decl: make_struct_dim_list optional_comma  */
                                                 {
        (yyval.pExpression) = (yyvsp[-1].pExpression);
    }
    break;

  case 780: /* optional_make_struct_dim_decl: make_struct_dim_decl  */
                                  { (yyval.pExpression) = (yyvsp[0].pExpression);  }
    break;

  case 781: /* optional_make_struct_dim_decl: %empty  */
        {   (yyval.pExpression) = new ExprMakeStruct(); }
    break;

  case 782: /* use_initializer: %empty  */
                            { (yyval.b) = true; }
    break;

  case 783: /* use_initializer: "uninitialized"  */
                            { (yyval.b) = false; }
    break;

  case 784: /* $@86: %empty  */
                             { yyextra->das_arrow_depth ++; }
    break;

  case 785: /* $@87: %empty  */
                                                                                                   { yyextra->das_arrow_depth --; }
    break;

  case 786: /* make_struct_decl: "struct" '<' $@86 type_declaration_no_options '>' $@87 '(' use_initializer optional_make_struct_dim_decl ')'  */
                                                                                                                                                                                                      {
        (yyvsp[-1].pExpression)->at = tokAt(scanner,(yylsp[-9]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = TypeDeclPtr((yyvsp[-6].pTypeDecl));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = (yyvsp[-2].b);
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->forceStruct = true;
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->alwaysUseInitializer = true;
        (yyval.pExpression) = (yyvsp[-1].pExpression);
    }
    break;

  case 787: /* $@88: %empty  */
                            { yyextra->das_arrow_depth ++; }
    break;

  case 788: /* $@89: %empty  */
                                                                                                  { yyextra->das_arrow_depth --; }
    break;

  case 789: /* make_struct_decl: "class" '<' $@88 type_declaration_no_options '>' $@89 '(' use_initializer optional_make_struct_dim_decl ')'  */
                                                                                                                                                                                                     {
        (yyvsp[-1].pExpression)->at = tokAt(scanner,(yylsp[-9]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = TypeDeclPtr((yyvsp[-6].pTypeDecl));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = (yyvsp[-2].b);
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->forceClass = true;
        (yyval.pExpression) = (yyvsp[-1].pExpression);
    }
    break;

  case 790: /* $@90: %empty  */
                               { yyextra->das_arrow_depth ++; }
    break;

  case 791: /* $@91: %empty  */
                                                                                                     { yyextra->das_arrow_depth --; }
    break;

  case 792: /* make_struct_decl: "variant" '<' $@90 type_declaration_no_options '>' $@91 '(' make_variant_dim ')'  */
                                                                                                                                                                     {
        (yyvsp[-1].pExpression)->at = tokAt(scanner,(yylsp[-8]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = TypeDeclPtr((yyvsp[-5].pTypeDecl));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = true;
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->forceVariant = true;
        (yyval.pExpression) = (yyvsp[-1].pExpression);
    }
    break;

  case 793: /* $@92: %empty  */
                              { yyextra->das_arrow_depth ++; }
    break;

  case 794: /* $@93: %empty  */
                                                                                                    { yyextra->das_arrow_depth --; }
    break;

  case 795: /* make_struct_decl: "default" '<' $@92 type_declaration_no_options '>' $@93 use_initializer  */
                                                                                                                                                           {
        auto msd = new ExprMakeStruct();
        msd->at = tokAt(scanner,(yylsp[-6]));
        msd->makeType = TypeDeclPtr((yyvsp[-3].pTypeDecl));
        msd->useInitializer = (yyvsp[0].b);
        msd->alwaysUseInitializer = true;
        (yyval.pExpression) = msd;
    }
    break;

  case 796: /* make_map_tuple: expr "=>" expr  */
                                         {
        ExprMakeTuple * mt = new ExprMakeTuple(tokAt(scanner,(yylsp[-1])));
        mt->values.push_back(ExpressionPtr((yyvsp[-2].pExpression)));
        mt->values.push_back(ExpressionPtr((yyvsp[0].pExpression)));
        (yyval.pExpression) = mt;
    }
    break;

  case 797: /* make_map_tuple: expr  */
                 {
        (yyval.pExpression) = (yyvsp[0].pExpression);
    }
    break;

  case 798: /* make_tuple_call: "tuple" '(' expr_list optional_comma ')'  */
                                                                    {
        auto mkt = new ExprMakeTuple(tokAt(scanner,(yylsp[-4])));
        mkt->values = sequenceToList((yyvsp[-2].pExpression));
        mkt->makeType = make_smart<TypeDecl>(Type::autoinfer);
        (yyval.pExpression) = mkt;
    }
    break;

  case 799: /* $@94: %empty  */
                             { yyextra->das_arrow_depth ++; }
    break;

  case 800: /* $@95: %empty  */
                                                                                                   { yyextra->das_arrow_depth --; }
    break;

  case 801: /* make_tuple_call: "tuple" '<' $@94 type_declaration_no_options '>' $@95 '(' use_initializer optional_make_struct_dim_decl ')'  */
                                                                                                                                                                                                      {
        (yyvsp[-1].pExpression)->at = tokAt(scanner,(yylsp[-9]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = TypeDeclPtr((yyvsp[-6].pTypeDecl));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = (yyvsp[-2].b);
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->forceTuple = true;
        (yyval.pExpression) = (yyvsp[-1].pExpression);
    }
    break;

  case 802: /* make_dim_decl: '[' expr_list optional_comma ']'  */
                                                          {
        auto mka = make_smart<ExprMakeArray>(tokAt(scanner,(yylsp[-3])));
        mka->values = sequenceToList((yyvsp[-2].pExpression));
        mka->makeType = make_smart<TypeDecl>(Type::autoinfer);
        mka->gen2 = true;
        auto tam = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-3])),"to_array_move");
        tam->arguments.push_back(mka);
        (yyval.pExpression) = tam;
    }
    break;

  case 803: /* $@96: %empty  */
                                       { yyextra->das_arrow_depth ++; }
    break;

  case 804: /* $@97: %empty  */
                                                                                                             { yyextra->das_arrow_depth --; }
    break;

  case 805: /* make_dim_decl: "array" "struct" '<' $@96 type_declaration_no_options '>' $@97 '(' use_initializer optional_make_struct_dim_decl ')'  */
                                                                                                                                                                                                                {
        (yyvsp[-1].pExpression)->at = tokAt(scanner,(yylsp[-10]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = TypeDeclPtr((yyvsp[-6].pTypeDecl));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = (yyvsp[-2].b);
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->forceStruct = true;
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->alwaysUseInitializer = true;
        auto tam = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-10])),"to_array_move");
        tam->arguments.push_back((yyvsp[-1].pExpression));
        (yyval.pExpression) = tam;
    }
    break;

  case 806: /* $@98: %empty  */
                                       { yyextra->das_arrow_depth ++; }
    break;

  case 807: /* $@99: %empty  */
                                                                                                             { yyextra->das_arrow_depth --; }
    break;

  case 808: /* make_dim_decl: "array" "tuple" '<' $@98 type_declaration_no_options '>' $@99 '(' use_initializer optional_make_struct_dim_decl ')'  */
                                                                                                                                                                                                                {
        (yyvsp[-1].pExpression)->at = tokAt(scanner,(yylsp[-10]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = TypeDeclPtr((yyvsp[-6].pTypeDecl));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = (yyvsp[-2].b);
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->forceTuple = true;
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->alwaysUseInitializer = true;
        auto tam = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-10])),"to_array_move");
        tam->arguments.push_back((yyvsp[-1].pExpression));
        (yyval.pExpression) = tam;
    }
    break;

  case 809: /* $@100: %empty  */
                                         { yyextra->das_arrow_depth ++; }
    break;

  case 810: /* $@101: %empty  */
                                                                                                               { yyextra->das_arrow_depth --; }
    break;

  case 811: /* make_dim_decl: "array" "variant" '<' $@100 type_declaration_no_options '>' $@101 '(' make_variant_dim ')'  */
                                                                                                                                                                               {
        (yyvsp[-1].pExpression)->at = tokAt(scanner,(yylsp[-9]));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->makeType = TypeDeclPtr((yyvsp[-5].pTypeDecl));
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->useInitializer = true;
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->forceVariant = true;
        ((ExprMakeStruct *)(yyvsp[-1].pExpression))->alwaysUseInitializer = true;
        auto tam = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-9])),"to_array_move");
        tam->arguments.push_back((yyvsp[-1].pExpression));
        (yyval.pExpression) = tam;
    }
    break;

  case 812: /* make_dim_decl: "array" '(' expr_list optional_comma ')'  */
                                                                   {
        auto mka = make_smart<ExprMakeArray>(tokAt(scanner,(yylsp[-4])));
        mka->values = sequenceToList((yyvsp[-2].pExpression));
        mka->makeType = make_smart<TypeDecl>(Type::autoinfer);
        mka->gen2 = true;
        auto tam = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-4])),"to_array_move");
        tam->arguments.push_back(mka);
        (yyval.pExpression) = tam;
    }
    break;

  case 813: /* $@102: %empty  */
                           { yyextra->das_arrow_depth ++; }
    break;

  case 814: /* $@103: %empty  */
                                                                                                 { yyextra->das_arrow_depth --; }
    break;

  case 815: /* make_dim_decl: "array" '<' $@102 type_declaration_no_options '>' $@103 '(' optional_expr_list ')'  */
                                                                                                                                                                        {
        if ( (yyvsp[-1].pExpression) ) {
            auto mka = make_smart<ExprMakeArray>(tokAt(scanner,(yylsp[-8])));
            mka->values = sequenceToList((yyvsp[-1].pExpression));
            mka->makeType = TypeDeclPtr((yyvsp[-5].pTypeDecl));
            mka->gen2 = true;
            auto tam = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-8])),"to_array_move");
            tam->arguments.push_back(mka);
            (yyval.pExpression) = tam;
        } else {
            auto msd = new ExprMakeStruct();
            msd->at = tokAt(scanner,(yylsp[-8]));
            msd->makeType = make_smart<TypeDecl>(Type::tArray);
            msd->makeType->firstType = TypeDeclPtr((yyvsp[-5].pTypeDecl));
            msd->at = tokAt(scanner,(yylsp[-5]));
            msd->useInitializer = true;
            msd->alwaysUseInitializer = true;
            (yyval.pExpression) = msd;
        }
    }
    break;

  case 816: /* make_dim_decl: "fixed_array" '(' expr_list optional_comma ')'  */
                                                                         {
        auto mka = new ExprMakeArray(tokAt(scanner,(yylsp[-4])));
        mka->values = sequenceToList((yyvsp[-2].pExpression));
        mka->makeType = make_smart<TypeDecl>(Type::autoinfer);
        mka->gen2 = true;
        (yyval.pExpression) = mka;
    }
    break;

  case 817: /* $@104: %empty  */
                                 { yyextra->das_arrow_depth ++; }
    break;

  case 818: /* $@105: %empty  */
                                                                                                       { yyextra->das_arrow_depth --; }
    break;

  case 819: /* make_dim_decl: "fixed_array" '<' $@104 type_declaration_no_options '>' $@105 '(' expr_list optional_comma ')'  */
                                                                                                                                                                                    {
        auto mka = new ExprMakeArray(tokAt(scanner,(yylsp[-9])));
        mka->values = sequenceToList((yyvsp[-2].pExpression));
        mka->makeType = TypeDeclPtr((yyvsp[-6].pTypeDecl));
        mka->gen2 = true;
        (yyval.pExpression) = mka;
    }
    break;

  case 820: /* expr_map_tuple_list: make_map_tuple  */
                                {
        (yyval.pExpression) = (yyvsp[0].pExpression);
    }
    break;

  case 821: /* expr_map_tuple_list: expr_map_tuple_list ',' make_map_tuple  */
                                                                {
            (yyval.pExpression) = new ExprSequence(tokAt(scanner,(yylsp[-2])),ExpressionPtr((yyvsp[-2].pExpression)),ExpressionPtr((yyvsp[0].pExpression)));
    }
    break;

  case 822: /* make_table_decl: '{' expr_map_tuple_list optional_comma '}'  */
                                                                    {
        auto mka = make_smart<ExprMakeArray>(tokAt(scanner,(yylsp[-3])));
        mka->values = sequenceToList((yyvsp[-2].pExpression));
        mka->makeType = make_smart<TypeDecl>(Type::autoinfer);
        auto ttm = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-3])),"to_table_move");
        ttm->arguments.push_back(mka);
        (yyval.pExpression) = ttm;
    }
    break;

  case 823: /* make_table_decl: "table" '(' expr_map_tuple_list optional_comma ')'  */
                                                                             {
        auto mka = make_smart<ExprMakeArray>(tokAt(scanner,(yylsp[-4])));
        mka->values = sequenceToList((yyvsp[-2].pExpression));
        mka->makeType = make_smart<TypeDecl>(Type::autoinfer);
        auto ttm = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-4])),"to_table_move");
        ttm->arguments.push_back(mka);
        (yyval.pExpression) = ttm;
    }
    break;

  case 824: /* make_table_decl: "table" '<' type_declaration_no_options '>' '(' optional_expr_map_tuple_list ')'  */
                                                                                                                 {
        if ( (yyvsp[-1].pExpression) ) {
            auto mka = make_smart<ExprMakeArray>(tokAt(scanner,(yylsp[-6])));
            mka->values = sequenceToList((yyvsp[-1].pExpression));
            mka->makeType = TypeDeclPtr((yyvsp[-4].pTypeDecl));
            auto ttm = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-6])),"to_table_move");
            ttm->arguments.push_back(mka);
            (yyval.pExpression) = ttm;
        } else {
            auto msd = new ExprMakeStruct();
            msd->at = tokAt(scanner,(yylsp[-6]));
            msd->makeType = make_smart<TypeDecl>(Type::tTable);
            msd->makeType->firstType = TypeDeclPtr((yyvsp[-4].pTypeDecl));
            msd->makeType->secondType = make_smart<TypeDecl>(Type::tVoid);
            msd->at = tokAt(scanner,(yylsp[-6]));
            msd->useInitializer = true;
            msd->alwaysUseInitializer = true;
            (yyval.pExpression) = msd;
        }
    }
    break;

  case 825: /* make_table_decl: "table" '<' type_declaration_no_options c_or_s type_declaration_no_options '>' '(' optional_expr_map_tuple_list ')'  */
                                                                                                                                                             {
        if ( (yyvsp[-1].pExpression) ) {
            auto mka = make_smart<ExprMakeArray>(tokAt(scanner,(yylsp[-8])));
            mka->values = sequenceToList((yyvsp[-1].pExpression));
            mka->makeType = make_smart<TypeDecl>(Type::tTuple);
            mka->makeType->argTypes.push_back((yyvsp[-6].pTypeDecl));
            mka->makeType->argTypes.push_back((yyvsp[-4].pTypeDecl));
            auto ttm = yyextra->g_Program->makeCall(tokAt(scanner,(yylsp[-8])),"to_table_move");
            ttm->arguments.push_back(mka);
            (yyval.pExpression) = ttm;
        } else {
            auto msd = new ExprMakeStruct();
            msd->at = tokAt(scanner,(yylsp[-8]));
            msd->makeType = make_smart<TypeDecl>(Type::tTable);
            msd->makeType->firstType = TypeDeclPtr((yyvsp[-6].pTypeDecl));
            msd->makeType->secondType = TypeDeclPtr((yyvsp[-4].pTypeDecl));
            msd->at = tokAt(scanner,(yylsp[-8]));
            msd->useInitializer = true;
            msd->alwaysUseInitializer = true;
            (yyval.pExpression) = msd;
        }
    }
    break;

  case 826: /* array_comprehension_where: %empty  */
                                    { (yyval.pExpression) = nullptr; }
    break;

  case 827: /* array_comprehension_where: ';' "where" expr  */
                                    { (yyval.pExpression) = (yyvsp[0].pExpression); }
    break;

  case 828: /* optional_comma: %empty  */
                { (yyval.b) = false; }
    break;

  case 829: /* optional_comma: ','  */
                { (yyval.b) = true; }
    break;

  case 830: /* array_comprehension: '[' "for" '(' variable_name_with_pos_list "in" expr_list ')' ';' expr array_comprehension_where ']'  */
                                                                                                                                                           {
        (yyval.pExpression) = ast_arrayComprehension(scanner,tokAt(scanner,(yylsp[-9])),(yyvsp[-7].pNameWithPosList),(yyvsp[-5].pExpression),(yyvsp[-2].pExpression),(yyvsp[-1].pExpression),tokRangeAt(scanner,(yylsp[-2]),(yylsp[0])),false,false);
    }
    break;

  case 831: /* array_comprehension: '[' "iterator" "for" '(' variable_name_with_pos_list "in" expr_list ')' ';' expr array_comprehension_where ']'  */
                                                                                                                                                                        {
        (yyval.pExpression) = ast_arrayComprehension(scanner,tokAt(scanner,(yylsp[-9])),(yyvsp[-7].pNameWithPosList),(yyvsp[-5].pExpression),(yyvsp[-2].pExpression),(yyvsp[-1].pExpression),tokRangeAt(scanner,(yylsp[-2]),(yylsp[0])),true,false);
    }
    break;

  case 832: /* array_comprehension: '{' "for" '(' variable_name_with_pos_list "in" expr_list ')' ';' make_map_tuple array_comprehension_where '}'  */
                                                                                                                                                                     {
        (yyval.pExpression) = ast_arrayComprehension(scanner,tokAt(scanner,(yylsp[-9])),(yyvsp[-7].pNameWithPosList),(yyvsp[-5].pExpression),(yyvsp[-2].pExpression),(yyvsp[-1].pExpression),tokRangeAt(scanner,(yylsp[-2]),(yylsp[0])),false,true);
    }
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == DAS2_YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= DAS2_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == DAS2_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner);
          yychar = DAS2_YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != DAS2_YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}



void das2_yyfatalerror ( DAS2_YYLTYPE * lloc, yyscan_t scanner, const string & error, CompilationError cerr ) {
    yyextra->g_Program->error(error,"","",LineInfo(yyextra->g_FileAccessStack.back(),
        lloc->first_column,lloc->first_line,lloc->last_column,lloc->last_line),cerr);
}

void das2_yyerror ( DAS2_YYLTYPE * lloc, yyscan_t scanner, const string & error ) {
    if ( !yyextra->das_suppress_errors ) {
        yyextra->g_Program->error(error,"","",LineInfo(yyextra->g_FileAccessStack.back(),
            lloc->first_column,lloc->first_line,lloc->last_column,lloc->last_line),
                CompilationError::syntax_error);
    }
}

LineInfo tokAt ( yyscan_t scanner, const struct DAS2_YYLTYPE & li ) {
    return LineInfo(yyextra->g_FileAccessStack.back(),
        li.first_column,li.first_line,
        li.last_column,li.last_line);
}

LineInfo tokRangeAt ( yyscan_t scanner, const struct DAS2_YYLTYPE & li, const struct DAS2_YYLTYPE & lie ) {
    return LineInfo(yyextra->g_FileAccessStack.back(),
        li.first_column,li.first_line,
        lie.last_column,lie.last_line);
}



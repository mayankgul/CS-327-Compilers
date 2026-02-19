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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yapl.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern char *yytext;
int yylex(void);
void yyerror(const char *);
int global_declarations=0;
int func_definitions=0;
int int_consts=0;
int pointer_decls=0;
int ifs_wo_else=0;
int ladder_len=0,hold=0;
int max=-1;

#line 87 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    I_CONSTANT = 259,              /* I_CONSTANT  */
    F_CONSTANT = 260,              /* F_CONSTANT  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    FUNC_NAME = 262,               /* FUNC_NAME  */
    SIZEOF = 263,                  /* SIZEOF  */
    PTR_OP = 264,                  /* PTR_OP  */
    INC_OP = 265,                  /* INC_OP  */
    DEC_OP = 266,                  /* DEC_OP  */
    LEFT_OP = 267,                 /* LEFT_OP  */
    RIGHT_OP = 268,                /* RIGHT_OP  */
    LE_OP = 269,                   /* LE_OP  */
    GE_OP = 270,                   /* GE_OP  */
    EQ_OP = 271,                   /* EQ_OP  */
    NE_OP = 272,                   /* NE_OP  */
    TH_OP = 273,                   /* TH_OP  */
    PEQ_OP = 274,                  /* PEQ_OP  */
    MEQ_OP = 275,                  /* MEQ_OP  */
    STREQ_OP = 276,                /* STREQ_OP  */
    DEQ_OP = 277,                  /* DEQ_OP  */
    MODEQ_OP = 278,                /* MODEQ_OP  */
    TER_OP = 279,                  /* TER_OP  */
    AND_OP = 280,                  /* AND_OP  */
    OR_OP = 281,                   /* OR_OP  */
    MUL_ASSIGN = 282,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 283,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 284,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 285,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 286,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 287,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 288,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 289,              /* AND_ASSIGN  */
    XOR_ASSIGN = 290,              /* XOR_ASSIGN  */
    OR_ASSIGN = 291,               /* OR_ASSIGN  */
    TYPEDEF_NAME = 292,            /* TYPEDEF_NAME  */
    ENUMERATION_CONSTANT = 293,    /* ENUMERATION_CONSTANT  */
    TYPEDEF = 294,                 /* TYPEDEF  */
    EXTERN = 295,                  /* EXTERN  */
    STATIC = 296,                  /* STATIC  */
    AUTO = 297,                    /* AUTO  */
    REGISTER = 298,                /* REGISTER  */
    INLINE = 299,                  /* INLINE  */
    CONST = 300,                   /* CONST  */
    RESTRICT = 301,                /* RESTRICT  */
    VOLATILE = 302,                /* VOLATILE  */
    BOOL = 303,                    /* BOOL  */
    CHAR = 304,                    /* CHAR  */
    SHORT = 305,                   /* SHORT  */
    INT = 306,                     /* INT  */
    LONG = 307,                    /* LONG  */
    SIGNED = 308,                  /* SIGNED  */
    UNSIGNED = 309,                /* UNSIGNED  */
    FLOAT = 310,                   /* FLOAT  */
    DOUBLE = 311,                  /* DOUBLE  */
    VOID = 312,                    /* VOID  */
    COMPLEX = 313,                 /* COMPLEX  */
    IMAGINARY = 314,               /* IMAGINARY  */
    STRUCT = 315,                  /* STRUCT  */
    UNION = 316,                   /* UNION  */
    ENUM = 317,                    /* ENUM  */
    ELLIPSIS = 318,                /* ELLIPSIS  */
    CASE = 319,                    /* CASE  */
    DEFAULT = 320,                 /* DEFAULT  */
    IF = 321,                      /* IF  */
    ELSE = 322,                    /* ELSE  */
    SWITCH = 323,                  /* SWITCH  */
    WHILE = 324,                   /* WHILE  */
    DO = 325,                      /* DO  */
    FOR = 326,                     /* FOR  */
    GOTO = 327,                    /* GOTO  */
    CONTINUE = 328,                /* CONTINUE  */
    BREAK = 329,                   /* BREAK  */
    RETURN = 330,                  /* RETURN  */
    ALIGNAS = 331,                 /* ALIGNAS  */
    ALIGNOF = 332,                 /* ALIGNOF  */
    ATOMIC = 333,                  /* ATOMIC  */
    GENERIC = 334,                 /* GENERIC  */
    NORETURN = 335,                /* NORETURN  */
    STATIC_ASSERT = 336,           /* STATIC_ASSERT  */
    THREAD_LOCAL = 337             /* THREAD_LOCAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define I_CONSTANT 259
#define F_CONSTANT 260
#define STRING_LITERAL 261
#define FUNC_NAME 262
#define SIZEOF 263
#define PTR_OP 264
#define INC_OP 265
#define DEC_OP 266
#define LEFT_OP 267
#define RIGHT_OP 268
#define LE_OP 269
#define GE_OP 270
#define EQ_OP 271
#define NE_OP 272
#define TH_OP 273
#define PEQ_OP 274
#define MEQ_OP 275
#define STREQ_OP 276
#define DEQ_OP 277
#define MODEQ_OP 278
#define TER_OP 279
#define AND_OP 280
#define OR_OP 281
#define MUL_ASSIGN 282
#define DIV_ASSIGN 283
#define MOD_ASSIGN 284
#define ADD_ASSIGN 285
#define SUB_ASSIGN 286
#define LEFT_ASSIGN 287
#define RIGHT_ASSIGN 288
#define AND_ASSIGN 289
#define XOR_ASSIGN 290
#define OR_ASSIGN 291
#define TYPEDEF_NAME 292
#define ENUMERATION_CONSTANT 293
#define TYPEDEF 294
#define EXTERN 295
#define STATIC 296
#define AUTO 297
#define REGISTER 298
#define INLINE 299
#define CONST 300
#define RESTRICT 301
#define VOLATILE 302
#define BOOL 303
#define CHAR 304
#define SHORT 305
#define INT 306
#define LONG 307
#define SIGNED 308
#define UNSIGNED 309
#define FLOAT 310
#define DOUBLE 311
#define VOID 312
#define COMPLEX 313
#define IMAGINARY 314
#define STRUCT 315
#define UNION 316
#define ENUM 317
#define ELLIPSIS 318
#define CASE 319
#define DEFAULT 320
#define IF 321
#define ELSE 322
#define SWITCH 323
#define WHILE 324
#define DO 325
#define FOR 326
#define GOTO 327
#define CONTINUE 328
#define BREAK 329
#define RETURN 330
#define ALIGNAS 331
#define ALIGNOF 332
#define ATOMIC 333
#define GENERIC 334
#define NORETURN 335
#define STATIC_ASSERT 336
#define THREAD_LOCAL 337

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "yapl.y"

	int val;
	struct symtab *symp;

#line 309 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_I_CONSTANT = 4,                 /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 5,                 /* F_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 7,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 8,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_TH_OP = 18,                     /* TH_OP  */
  YYSYMBOL_PEQ_OP = 19,                    /* PEQ_OP  */
  YYSYMBOL_MEQ_OP = 20,                    /* MEQ_OP  */
  YYSYMBOL_STREQ_OP = 21,                  /* STREQ_OP  */
  YYSYMBOL_DEQ_OP = 22,                    /* DEQ_OP  */
  YYSYMBOL_MODEQ_OP = 23,                  /* MODEQ_OP  */
  YYSYMBOL_TER_OP = 24,                    /* TER_OP  */
  YYSYMBOL_AND_OP = 25,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 26,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 27,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 28,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 29,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 30,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 31,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 32,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 33,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 34,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 35,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 36,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF_NAME = 37,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUMERATION_CONSTANT = 38,      /* ENUMERATION_CONSTANT  */
  YYSYMBOL_TYPEDEF = 39,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 40,                    /* EXTERN  */
  YYSYMBOL_STATIC = 41,                    /* STATIC  */
  YYSYMBOL_AUTO = 42,                      /* AUTO  */
  YYSYMBOL_REGISTER = 43,                  /* REGISTER  */
  YYSYMBOL_INLINE = 44,                    /* INLINE  */
  YYSYMBOL_CONST = 45,                     /* CONST  */
  YYSYMBOL_RESTRICT = 46,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 47,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 48,                      /* BOOL  */
  YYSYMBOL_CHAR = 49,                      /* CHAR  */
  YYSYMBOL_SHORT = 50,                     /* SHORT  */
  YYSYMBOL_INT = 51,                       /* INT  */
  YYSYMBOL_LONG = 52,                      /* LONG  */
  YYSYMBOL_SIGNED = 53,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 54,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 55,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 56,                    /* DOUBLE  */
  YYSYMBOL_VOID = 57,                      /* VOID  */
  YYSYMBOL_COMPLEX = 58,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 59,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 60,                    /* STRUCT  */
  YYSYMBOL_UNION = 61,                     /* UNION  */
  YYSYMBOL_ENUM = 62,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 63,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 64,                      /* CASE  */
  YYSYMBOL_DEFAULT = 65,                   /* DEFAULT  */
  YYSYMBOL_IF = 66,                        /* IF  */
  YYSYMBOL_ELSE = 67,                      /* ELSE  */
  YYSYMBOL_SWITCH = 68,                    /* SWITCH  */
  YYSYMBOL_WHILE = 69,                     /* WHILE  */
  YYSYMBOL_DO = 70,                        /* DO  */
  YYSYMBOL_FOR = 71,                       /* FOR  */
  YYSYMBOL_GOTO = 72,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 73,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 74,                     /* BREAK  */
  YYSYMBOL_RETURN = 75,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 76,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 77,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 78,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 79,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 80,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 81,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 82,              /* THREAD_LOCAL  */
  YYSYMBOL_83_ = 83,                       /* '('  */
  YYSYMBOL_84_ = 84,                       /* ')'  */
  YYSYMBOL_85_ = 85,                       /* ','  */
  YYSYMBOL_86_ = 86,                       /* ':'  */
  YYSYMBOL_87_ = 87,                       /* '['  */
  YYSYMBOL_88_ = 88,                       /* ']'  */
  YYSYMBOL_89_ = 89,                       /* '.'  */
  YYSYMBOL_90_ = 90,                       /* '{'  */
  YYSYMBOL_91_ = 91,                       /* '}'  */
  YYSYMBOL_92_ = 92,                       /* '&'  */
  YYSYMBOL_93_ = 93,                       /* '*'  */
  YYSYMBOL_94_ = 94,                       /* '+'  */
  YYSYMBOL_95_ = 95,                       /* '-'  */
  YYSYMBOL_96_ = 96,                       /* '~'  */
  YYSYMBOL_97_ = 97,                       /* '!'  */
  YYSYMBOL_98_ = 98,                       /* '/'  */
  YYSYMBOL_99_ = 99,                       /* '%'  */
  YYSYMBOL_100_ = 100,                     /* '<'  */
  YYSYMBOL_101_ = 101,                     /* '>'  */
  YYSYMBOL_102_ = 102,                     /* '^'  */
  YYSYMBOL_103_ = 103,                     /* '|'  */
  YYSYMBOL_104_ = 104,                     /* '?'  */
  YYSYMBOL_105_ = 105,                     /* '='  */
  YYSYMBOL_106_ = 106,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 107,                 /* $accept  */
  YYSYMBOL_primary_expression = 108,       /* primary_expression  */
  YYSYMBOL_constant = 109,                 /* constant  */
  YYSYMBOL_enumeration_constant = 110,     /* enumeration_constant  */
  YYSYMBOL_string = 111,                   /* string  */
  YYSYMBOL_generic_selection = 112,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 113,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 114,      /* generic_association  */
  YYSYMBOL_postfix_expression = 115,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 116, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 117,         /* unary_expression  */
  YYSYMBOL_unary_operator = 118,           /* unary_operator  */
  YYSYMBOL_cast_expression = 119,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 120, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 121,      /* additive_expression  */
  YYSYMBOL_shift_expression = 122,         /* shift_expression  */
  YYSYMBOL_relational_expression = 123,    /* relational_expression  */
  YYSYMBOL_equality_expression = 124,      /* equality_expression  */
  YYSYMBOL_and_expression = 125,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 126,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 127,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 128,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 129,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 130,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 131,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 132,      /* assignment_operator  */
  YYSYMBOL_expression = 133,               /* expression  */
  YYSYMBOL_constant_expression = 134,      /* constant_expression  */
  YYSYMBOL_declaration = 135,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 136,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 137,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 138,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 139,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 140,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 141, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 142,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 143,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 144,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 145, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 146,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 147,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 148,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 149,          /* enumerator_list  */
  YYSYMBOL_enumerator = 150,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 151,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 152,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 153,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 154,      /* alignment_specifier  */
  YYSYMBOL_declarator = 155,               /* declarator  */
  YYSYMBOL_156_1 = 156,                    /* $@1  */
  YYSYMBOL_direct_declarator = 157,        /* direct_declarator  */
  YYSYMBOL_pointer = 158,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 159,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 160,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 161,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 162,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 163,          /* identifier_list  */
  YYSYMBOL_type_name = 164,                /* type_name  */
  YYSYMBOL_abstract_declarator = 165,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 166, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 167,              /* initializer  */
  YYSYMBOL_initializer_list = 168,         /* initializer_list  */
  YYSYMBOL_designation = 169,              /* designation  */
  YYSYMBOL_designator_list = 170,          /* designator_list  */
  YYSYMBOL_designator = 171,               /* designator  */
  YYSYMBOL_static_assert_declaration = 172, /* static_assert_declaration  */
  YYSYMBOL_statement = 173,                /* statement  */
  YYSYMBOL_labeled_statement = 174,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 175,       /* compound_statement  */
  YYSYMBOL_block_item_list = 176,          /* block_item_list  */
  YYSYMBOL_block_item = 177,               /* block_item  */
  YYSYMBOL_expression_statement = 178,     /* expression_statement  */
  YYSYMBOL_selection_statement = 179,      /* selection_statement  */
  YYSYMBOL_180_2 = 180,                    /* $@2  */
  YYSYMBOL_iteration_statement = 181,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 182,           /* jump_statement  */
  YYSYMBOL_translation_unit = 183,         /* translation_unit  */
  YYSYMBOL_external_declaration = 184,     /* external_declaration  */
  YYSYMBOL_function_definition = 185,      /* function_definition  */
  YYSYMBOL_declaration_list = 186          /* declaration_list  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2632

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  283
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  489

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   337


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    97,     2,     2,     2,    99,    92,     2,
      83,    84,    93,    94,    85,    95,    89,    98,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,   106,
     100,   105,   101,   104,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    87,     2,    88,   102,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,   103,    91,    96,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    50,    51,    52,    53,    57,    58,    59,
      63,    67,    68,    72,    76,    77,    81,    82,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    99,   100,
     104,   105,   106,   107,   108,   109,   110,   114,   115,   116,
     117,   118,   119,   123,   124,   128,   129,   130,   131,   135,
     136,   137,   141,   142,   143,   147,   148,   149,   150,   151,
     152,   156,   157,   158,   162,   163,   167,   168,   172,   173,
     177,   178,   182,   183,   187,   188,   192,   193,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   216,   217,   221,   225,   226,   227,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     244,   245,   249,   250,   254,   255,   256,   257,   258,   259,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   282,   283,   284,   288,
     289,   293,   294,   298,   299,   300,   304,   305,   306,   307,
     311,   312,   316,   317,   318,   322,   323,   324,   325,   326,
     330,   331,   335,   336,   340,   344,   345,   346,   347,   351,
     352,   356,   357,   361,   361,   362,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     383,   384,   385,   386,   390,   391,   396,   397,   401,   402,
     406,   407,   408,   412,   413,   417,   418,   422,   423,   424,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   452,   453,   454,   458,   459,   460,   461,   465,   469,
     470,   474,   475,   479,   483,   484,   485,   486,   487,   488,
     492,   493,   494,   498,   499,   503,   504,   508,   509,   513,
     514,   518,   518,   519,   520,   524,   525,   526,   527,   528,
     529,   533,   534,   535,   536,   537,   541,   542,   546,   547,
     551,   552,   556,   557
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "I_CONSTANT", "F_CONSTANT", "STRING_LITERAL", "FUNC_NAME", "SIZEOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "TH_OP", "PEQ_OP", "MEQ_OP", "STREQ_OP", "DEQ_OP",
  "MODEQ_OP", "TER_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME",
  "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID",
  "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'('", "')'", "','", "':'",
  "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'",
  "$accept", "primary_expression", "constant", "enumeration_constant",
  "string", "generic_selection", "generic_assoc_list",
  "generic_association", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "$@1", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "static_assert_declaration", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement", "$@2",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-381)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-174)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2355,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,  -381,  -381,    35,   -56,   -33,  -381,   -25,
    -381,  -381,    28,  2445,  2445,  -381,    37,  -381,  -381,  2445,
    2445,  2445,  -381,  1935,  -381,  -381,   -60,    32,   874,  2554,
    1716,  -381,    53,   129,  -381,   -52,  -381,  2041,    57,  -381,
    -381,  -381,   -22,  2483,  -381,  -381,  -381,  -381,  -381,    32,
    -381,   -28,   -57,  -381,  -381,  -381,  -381,  -381,  -381,  1764,
    1811,  1811,  -381,   -20,     5,   874,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,  -381,  -381,  -381,   266,  -381,  1716,  -381,
     110,    47,   170,   147,   207,    10,    49,    51,   106,    45,
    -381,    82,  2554,   102,  2554,    84,    94,   105,   118,  -381,
    -381,  -381,   129,    53,  -381,   432,  1479,  -381,    28,  -381,
    2257,  1995,   934,    29,  2483,  2157,  -381,    52,  -381,   -12,
    1716,    26,  -381,   874,  -381,   874,  -381,  -381,  2554,  1716,
     425,  -381,  -381,   141,   135,   230,  -381,  -381,  1525,  1716,
     232,  -381,  1716,  1716,  1716,  1716,  1716,  1716,  1716,  1716,
    1716,  1716,  1716,  1716,  1716,  1716,  1716,  1716,  1716,  1716,
    1716,  1716,  -381,  -381,  2108,   994,   133,  -381,   134,  -381,
    -381,  -381,   234,  -381,  -381,  -381,  -381,   157,   160,  1716,
     181,   186,   196,   199,   715,   211,   288,   201,   206,   759,
    -381,  -381,   -41,  -381,  -381,  -381,  -381,   558,  -381,  -381,
    -381,  -381,  -381,  1429,  -381,  -381,  -381,  -381,  -381,  -381,
      36,   221,   239,  -381,   144,  1287,  -381,   231,   238,  1054,
      57,  2204,  -381,  -381,  1716,  -381,    63,  -381,   241,    42,
    -381,  -381,  -381,  -381,   245,   246,   247,   249,  -381,  -381,
    -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,  -381,  1716,  -381,  1716,  1574,  -381,  -381,
     165,  -381,   -68,  -381,  -381,  -381,  -381,   110,   110,    47,
      47,   170,   170,   170,   170,   170,   147,   147,   207,    10,
      49,    51,   106,   166,  -381,   251,   253,  1287,  -381,   254,
     255,  1114,   134,  2309,  1174,   257,   715,   258,   715,  1716,
    1716,  1716,   276,   655,   242,  -381,  -381,  -381,    71,  -381,
    -381,  -381,  1716,   347,  -381,    95,  1479,    92,  -381,  1872,
    -381,    80,  -381,  -381,  2401,  -381,   353,   269,  1287,  -381,
    -381,  1716,  -381,   270,   275,  -381,  -381,    64,  -381,  1716,
    -381,   274,   274,  -381,  2520,  -381,  -381,  1429,  -381,  -381,
    1716,  -381,  1716,  -381,  -381,   277,  1287,  -381,  -381,  1716,
    -381,   278,  -381,   283,  1287,  -381,   281,   282,  1234,   267,
    -381,   715,  -381,   173,   176,   180,   289,   812,   812,  -381,
    -381,   290,  -381,  1333,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,   291,   292,  -381,  -381,  -381,  -381,   295,   189,
    -381,   296,   115,  -381,  -381,  -381,   315,   316,  -381,  -381,
     318,  1287,  -381,  -381,  1716,  -381,   319,  -381,  -381,   715,
     715,   715,  1716,  1620,  1669,  -381,  -381,  -381,  1479,  -381,
    -381,  1716,  -381,  2520,  1716,  1383,  -381,  -381,  -381,  -381,
     320,   321,  -381,   309,  -381,  -381,   200,   715,   204,   715,
     208,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,   271,
    -381,   715,  -381,   715,   715,  -381,  -381,  -381,  -381
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   135,   114,   115,   116,   118,   119,   169,   165,   166,
     167,   129,   121,   122,   123,   124,   127,   128,   125,   126,
     120,   130,   131,   139,   140,     0,     0,   168,   170,     0,
     117,   279,     0,   101,   103,   133,     0,   134,   132,   105,
     107,   109,    99,     0,   276,   278,   159,     0,     0,     0,
       0,   176,     0,   193,    97,     0,   110,   113,   175,   173,
     100,   102,   138,     0,   104,   106,   108,     1,   277,     0,
      10,   163,     0,   160,     2,     7,     8,    11,    12,     0,
       0,     0,     9,     0,     0,     0,    37,    38,    39,    40,
      41,    42,    18,     3,     4,     6,    30,    43,     0,    45,
      49,    52,    55,    61,    64,    66,    68,    70,    72,    74,
      96,     0,   147,   206,   149,     0,     0,     0,     0,   168,
     194,   192,   191,     0,    98,     0,     0,   282,     0,   281,
       0,     0,     0,     0,     0,     0,   141,     0,   145,     0,
       0,     0,   155,     0,    34,     0,    31,    32,     0,     0,
      43,    76,    94,     0,     0,     0,    24,    25,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   146,     0,     0,   208,   205,   209,   148,
     171,   164,     0,   177,   195,   190,   111,   113,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   259,     0,   257,   258,   244,   245,     0,   255,   246,
     247,   248,   249,     0,   233,   112,   283,   280,   203,   188,
     202,     0,   197,   198,     0,     0,   178,    38,     0,     0,
     174,     0,   136,   142,     0,   143,     0,   150,   154,     0,
     157,   162,   156,   161,     0,     0,     0,     0,    89,    90,
      91,    92,    93,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    78,     0,     5,     0,     0,    23,    20,
       0,    28,     0,    22,    46,    47,    48,    50,    51,    53,
      54,    58,    59,    60,    56,    57,    62,    63,    65,    67,
      69,    71,    73,     0,   227,     0,     0,     0,   211,    38,
       0,     0,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,   273,   274,     0,   260,
     254,   256,     0,     0,   235,     0,     0,     0,   239,     0,
     200,   208,   201,   187,     0,   189,     0,     0,     0,   179,
     186,     0,   185,    38,     0,   137,   152,     0,   144,     0,
     158,    35,     0,    36,     0,    77,    95,     0,    44,    21,
       0,    19,     0,   228,   210,     0,     0,   212,   218,     0,
     217,     0,   229,     0,     0,   219,    38,     0,     0,     0,
     250,     0,   252,     0,     0,     0,     0,     0,     0,   271,
     275,     0,   242,     0,   231,   234,   238,   240,   196,   199,
     204,   181,     0,     0,   182,   184,   151,   153,     0,     0,
      14,     0,     0,    29,    75,   214,     0,     0,   216,   230,
       0,     0,   220,   226,     0,   225,     0,   243,   251,     0,
       0,     0,     0,     0,     0,   241,   232,   237,     0,   180,
     183,     0,    13,     0,     0,     0,    26,   213,   215,   222,
       0,     0,   223,   263,   264,   265,     0,     0,     0,     0,
       0,   236,    17,    15,    16,    27,   221,   224,   261,     0,
     269,     0,   267,     0,     0,   266,   270,   268,   262
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -381,  -381,  -381,  -381,  -381,  -381,  -381,   -43,  -381,  -381,
     222,  -381,   -73,   145,   150,    72,   140,   236,   237,   235,
     240,   243,  -381,   -26,   -80,  -381,   -83,   -46,   -45,     8,
    -381,   293,  -381,   -42,  -381,  -381,   284,  -121,   -53,  -381,
      58,  -381,   348,  -125,  -381,   -48,  -381,  -381,   -19,  -381,
     287,     0,   -75,  -112,  -381,    78,  -381,    67,  -102,  -177,
    -123,    59,  -380,  -381,    87,   -27,  -186,  -381,   -31,  -381,
     210,  -227,  -381,  -381,  -381,  -381,  -381,   382,  -381,  -381
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    71,    94,    95,   419,   420,    96,   280,
     150,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   151,   152,   274,   212,   111,    31,   128,
      55,    56,    33,    34,    35,    36,   135,   136,   113,   246,
     247,    37,    72,    73,    38,    39,    40,    41,   118,   133,
      58,    59,   122,   305,   232,   233,   234,   421,   306,   188,
     334,   335,   336,   337,   338,    42,   214,   215,   216,   217,
     218,   219,   220,   484,   221,   222,    43,    44,    45,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   114,   153,   225,   117,   120,   112,   112,    32,   312,
     137,   187,   127,    57,   243,   114,   253,   276,   322,   231,
     371,   112,   110,   448,   110,   161,   129,    48,   141,    70,
      69,    51,    51,   123,   142,    70,   138,   114,    46,    51,
      62,    60,    61,   112,   276,    70,   224,    64,    65,    66,
      49,    32,   238,   121,   124,    51,    51,   239,    50,   183,
     153,   189,   153,   148,   114,   329,   114,    51,   134,   257,
     112,   180,   112,   249,   194,   448,   282,   140,   281,   250,
     213,   137,   137,  -173,   120,   226,   114,   114,   149,   284,
     285,   286,   112,   112,   251,   114,   398,   114,   303,   227,
     114,   112,   176,   112,   197,   310,   112,   138,   138,   197,
     311,    52,    52,   186,   110,   115,   116,   252,   248,   339,
     243,    53,   195,   185,   253,    47,   328,    63,   342,    53,
     390,   179,   392,   360,    54,    52,    52,   120,   244,   230,
     131,   165,   166,   224,   132,    53,    53,    52,   357,   181,
     244,   177,   154,   317,   178,   347,   276,    53,   245,   354,
     348,   169,   170,   184,   312,   171,   182,   185,   190,   358,
     443,   444,   213,   110,     8,     9,    10,   400,   191,   332,
     403,   333,   167,   168,   186,   184,   404,   120,   137,   185,
     192,   194,   230,   114,   365,    53,   366,   406,   356,   112,
     455,   383,   193,   162,   368,   438,   456,   119,   163,   164,
     254,   340,   255,   405,   138,   256,   184,   313,   110,   277,
     185,   314,    53,   174,   175,   275,   276,   375,   345,   346,
     341,   381,   376,   278,   387,   283,   393,   394,   395,   388,
     315,   291,   292,   293,   294,   295,   316,   172,   173,   369,
     370,   276,   372,   463,   464,   465,   224,   439,   276,   120,
     440,   276,   126,   194,   441,   276,   120,   318,   412,   319,
      97,   413,    97,   452,   453,   155,   156,   157,   397,   320,
     447,   480,   321,   482,   479,   276,   401,   224,   481,   276,
     423,   324,   483,   276,   323,   486,   426,   487,   488,   427,
     194,   144,   146,   147,   430,   343,   110,   325,   436,   431,
     287,   288,   326,   417,   296,   297,   114,   289,   290,   349,
      97,   230,   112,   224,   344,   471,   350,   359,   194,   361,
     362,   363,   447,   110,   364,   373,   120,   374,   248,   341,
     194,   389,   377,   378,   391,   396,   424,   230,   399,   158,
     402,   460,   230,   159,   461,   160,   410,   411,   414,   466,
     468,   470,    97,   415,   367,   425,   428,   429,   224,   432,
     433,   472,   442,   437,   474,   224,   478,   485,   445,   449,
     450,   451,   454,   194,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,   457,   458,   114,   459,   462,   476,   477,
     473,   112,   298,   300,   299,   416,   196,   139,   241,   301,
     240,    97,   409,   302,   407,    68,   422,   331,     0,     0,
       0,     0,     0,     0,     0,   198,    75,    76,    77,    78,
      79,     0,    80,    81,   258,   259,   260,   261,   262,     0,
       0,     0,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,     0,     0,     0,     0,    97,     0,     0,     1,
      82,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,   199,   200,   201,    97,
     202,   203,   204,   205,   206,   207,   208,   209,    26,    83,
      27,    84,    28,    29,    30,    85,     0,     0,     0,     0,
       0,     0,   125,   210,    86,    87,    88,    89,    90,    91,
     273,     0,     0,     0,     0,     0,     0,     0,   211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,   198,    75,    76,    77,    78,    79,     0,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     1,    82,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,   199,   200,   201,     0,   202,   203,   204,   205,
     206,   207,   208,   209,    26,    83,    27,    84,    28,    29,
      30,    85,     0,     0,     0,     0,     0,     0,   125,   330,
      86,    87,    88,    89,    90,    91,     0,     0,    74,    75,
      76,    77,    78,    79,   211,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    82,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   198,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,    26,    83,    27,    84,    28,    29,    30,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    82,     0,     0,     0,     0,     0,     0,
       0,   211,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,   199,
     200,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,     0,    83,     0,    84,     0,     0,    82,    85,     0,
       0,     0,     0,     0,     0,   125,     0,    86,    87,    88,
      89,    90,    91,     0,     0,    74,    75,    76,    77,    78,
      79,   211,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    84,     0,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
      82,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,   327,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,    83,
       0,    84,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
       0,     1,    82,     0,     0,     0,     0,     0,   211,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    83,    27,    84,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    82,     0,     0,   235,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   236,     0,     0,     0,    86,   237,    88,    89,
      90,    91,    82,     0,     0,   307,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   308,     0,     0,     0,    86,   309,    88,    89,
      90,    91,    82,     0,     0,   351,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   352,     0,     0,     0,    86,   353,    88,    89,
      90,    91,    82,     0,     0,   379,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   380,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    82,     0,     0,   384,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   385,     0,     0,     0,    86,   386,    88,    89,
      90,    91,    82,     0,     0,   434,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   435,     0,     0,    82,    86,    87,    88,    89,
      90,    91,     8,     9,    10,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,   119,    84,     0,     0,     0,
      85,    82,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    84,     0,     0,     0,    85,     0,     0,     0,
     332,    82,   333,   223,   446,    86,    87,    88,    89,    90,
      91,     0,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,    84,     0,     0,     0,    85,    82,     0,     0,
     332,     0,   333,   223,   475,    86,    87,    88,    89,    90,
      91,     0,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    84,     0,
       0,     0,    85,     0,     0,     0,   332,    82,   333,   223,
       0,    86,    87,    88,    89,    90,    91,     0,    74,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    84,     0,
       0,     0,    85,    82,     0,     0,     0,     0,     0,   223,
       0,    86,    87,    88,    89,    90,    91,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,    84,     0,     0,     0,    85,   279,
       0,     0,    82,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    74,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,    84,     0,     0,     0,    85,    82,     0,
       0,     0,     0,     0,   367,     0,    86,    87,    88,    89,
      90,    91,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,    84,
       0,     0,     0,    85,   467,     0,     0,    82,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,     0,    74,
      75,    76,    77,    78,    79,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    84,     0,
       0,     0,    85,   469,    82,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,    84,     0,     0,     0,    85,
       0,     0,    82,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    74,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,    84,     0,     0,     0,   143,     0,    82,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
      84,     0,     0,     0,   145,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,   339,   304,     0,     0,   185,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,    29,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     1,   229,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
       0,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,   126,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,     0,
      30,   184,   304,     0,     1,   185,     0,     0,     0,     0,
       0,    53,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,    29,     0,
       0,     1,     0,     0,     0,     0,     0,     0,   242,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     1,   355,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     1,   125,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
       0,    30,     1,   382,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,    29,    30,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   408,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
       0,    28,     1,    30,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    26,     0,    27,     0,    28,     0,    30,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,    27,     0,     0,    29,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,   418,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,    27,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      48,    49,    85,   126,    50,    53,    48,    49,     0,   186,
      63,   113,    57,    32,   135,    63,   141,    85,   204,   131,
      88,    63,    48,   403,    50,    98,    57,    83,    85,     3,
      90,     3,     3,    85,    91,     3,    63,    85,     3,     3,
       3,    33,    34,    85,    85,     3,   126,    39,    40,    41,
      83,    43,   132,    53,   106,     3,     3,   132,    83,   112,
     143,   114,   145,    83,   112,   106,   114,     3,    90,   149,
     112,    26,   114,    85,   122,   455,   159,   105,   158,    91,
     125,   134,   135,     3,   132,   130,   134,   135,    83,   162,
     163,   164,   134,   135,   140,   143,   323,   145,   181,   130,
     148,   143,    92,   145,   123,   185,   148,   134,   135,   128,
     185,    83,    83,   113,   140,    48,    49,    91,   137,    83,
     241,    93,   122,    87,   249,    90,   209,    90,   230,    93,
     316,    25,   318,    91,   106,    83,    83,   185,    86,   131,
      83,    94,    95,   223,    87,    93,    93,    83,    85,   104,
      86,   102,    85,   199,   103,   235,    85,    93,   106,   239,
     235,    14,    15,    83,   341,    18,    84,    87,    84,   106,
     397,   398,   217,   199,    45,    46,    47,   106,    84,    87,
      85,    89,    12,    13,   184,    83,    91,   235,   241,    87,
      85,   239,   184,   241,   274,    93,   276,   105,   244,   241,
      85,   313,    84,    93,   277,   391,    91,    78,    98,    99,
     143,   230,   145,   336,   241,   148,    83,    83,   244,    84,
      87,    87,    93,    16,    17,    84,    85,   307,    84,    85,
     230,   311,   307,     3,   314,     3,   319,   320,   321,   314,
       6,   169,   170,   171,   172,   173,    86,   100,   101,    84,
      85,    85,    86,   439,   440,   441,   336,    84,    85,   307,
      84,    85,   105,   311,    84,    85,   314,    86,   348,    83,
      48,   351,    50,    84,    85,     9,    10,    11,   323,    83,
     403,   467,    83,   469,    84,    85,   332,   367,    84,    85,
     370,     3,    84,    85,    83,   481,   376,   483,   484,   379,
     348,    79,    80,    81,   384,    84,   332,   106,   388,   384,
     165,   166,   106,   359,   174,   175,   364,   167,   168,    88,
      98,   313,   364,   403,    85,   448,    88,    86,   376,    84,
      84,    84,   455,   359,    85,    84,   384,    84,   357,   339,
     388,    84,    88,    88,    86,    69,   372,   339,   106,    83,
       3,   431,   344,    87,   434,    89,     3,    88,    88,   442,
     443,   444,   140,    88,    90,    88,    88,    84,   448,    88,
      88,   451,    83,   106,   454,   455,    67,   106,    88,    88,
      88,    86,    86,   431,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    88,    88,   453,    88,    88,    88,    88,
     453,   453,   176,   178,   177,   357,   123,    69,   134,   179,
     133,   199,   344,   180,   337,    43,   367,   217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,   244,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,   277,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    -1,     3,     4,
       5,     6,     7,     8,   106,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    -1,    79,    -1,    -1,    38,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,     3,     4,     5,     6,     7,
       8,   106,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    77,
      -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,   106,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    38,    92,    93,    94,    95,
      96,    97,    45,    46,    47,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      83,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      87,    38,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    83,    38,    -1,    -1,
      87,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    87,    38,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    83,    38,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    92,    93,    94,    95,    96,    97,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    83,    84,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    83,    38,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,
      96,    97,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,    -1,    -1,    83,    84,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    83,    84,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    83,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      78,    -1,    80,    -1,    82,    83,    84,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    81,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    -1,    82,    37,    84,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,
      -1,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,   105,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      82,    83,    84,    -1,    37,    87,    -1,    -1,    -1,    -1,
      -1,    93,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    91,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    91,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    78,    -1,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    90,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      -1,    82,    37,    84,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    81,    82,    37,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,
      -1,    80,    37,    82,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    76,    -1,    78,    -1,    80,    -1,    82,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    78,    -1,    -1,    81,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    78,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    76,    78,    80,    81,
      82,   135,   136,   139,   140,   141,   142,   148,   151,   152,
     153,   154,   172,   183,   184,   185,     3,    90,    83,    83,
      83,     3,    83,    93,   106,   137,   138,   155,   157,   158,
     136,   136,     3,    90,   136,   136,   136,     0,   184,    90,
       3,   110,   149,   150,     3,     4,     5,     6,     7,     8,
      10,    11,    38,    77,    79,    83,    92,    93,    94,    95,
      96,    97,   108,   109,   111,   112,   115,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   134,   140,   145,   152,   164,   164,   134,   155,    78,
     152,   158,   159,    85,   106,    90,   105,   135,   136,   175,
     186,    83,    87,   156,    90,   143,   144,   145,   172,   149,
     105,    85,    91,    83,   117,    83,   117,   117,    83,    83,
     117,   130,   131,   133,   164,     9,    10,    11,    83,    87,
      89,   119,    93,    98,    99,    94,    95,    12,    13,    14,
      15,    18,   100,   101,    16,    17,    92,   102,   103,    25,
      26,   104,    84,   145,    83,    87,   158,   165,   166,   145,
      84,    84,    85,    84,   152,   158,   138,   155,     3,    64,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    75,
      91,   106,   133,   135,   173,   174,   175,   176,   177,   178,
     179,   181,   182,    90,   131,   167,   135,   175,     3,    84,
     136,   160,   161,   162,   163,    41,    88,    93,   131,   159,
     157,   143,    91,   144,    86,   106,   146,   147,   155,    85,
      91,   134,    91,   150,   164,   164,   164,   131,    19,    20,
      21,    22,    23,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,   105,   132,    84,    85,    84,     3,    84,
     116,   131,   133,     3,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   122,   122,   122,   123,   123,   124,   125,
     126,   127,   128,   133,    84,   160,   165,    41,    88,    93,
     131,   159,   166,    83,    87,     6,    86,   134,    86,    83,
      83,    83,   173,    83,     3,   106,   106,   106,   133,   106,
      91,   177,    87,    89,   167,   168,   169,   170,   171,    83,
     155,   158,   165,    84,    85,    84,    85,   131,   159,    88,
      88,    41,    88,    93,   131,    91,   134,    85,   106,    86,
      91,    84,    84,    84,    85,   131,   131,    90,   119,    84,
      85,    88,    86,    84,    84,   131,   159,    88,    88,    41,
      88,   131,    84,   160,    41,    88,    93,   131,   159,    84,
     173,    86,   173,   133,   133,   133,    69,   135,   178,   106,
     106,   134,     3,    85,    91,   167,   105,   171,    63,   162,
       3,    88,   131,   131,    88,    88,   147,   134,    65,   113,
     114,   164,   168,   131,   130,    88,   131,   131,    88,    84,
     131,   159,    88,    88,    41,    88,   131,   106,   173,    84,
      84,    84,    83,   178,   178,    88,    91,   167,   169,    88,
      88,    86,    84,    85,    86,    85,    91,    88,    88,    88,
     131,   131,    88,   173,   173,   173,   133,    84,   133,    84,
     133,   167,   131,   114,   131,    91,    88,    88,    67,    84,
     173,    84,   173,    84,   180,   106,   173,   173,   173
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   108,   108,   108,   109,   109,   109,
     110,   111,   111,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   120,   120,   120,   121,
     121,   121,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   124,   124,   124,   125,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   134,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   138,   138,   139,   139,   139,   139,   139,   139,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   141,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   145,   145,   145,   145,
     146,   146,   147,   147,   147,   148,   148,   148,   148,   148,
     149,   149,   150,   150,   151,   152,   152,   152,   152,   153,
     153,   154,   154,   156,   155,   155,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     158,   158,   158,   158,   159,   159,   160,   160,   161,   161,
     162,   162,   162,   163,   163,   164,   164,   165,   165,   165,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   167,   167,   167,   168,   168,   168,   168,   169,   170,
     170,   171,   171,   172,   173,   173,   173,   173,   173,   173,
     174,   174,   174,   175,   175,   176,   176,   177,   177,   178,
     178,   180,   179,   179,   179,   181,   181,   181,   181,   181,
     181,   182,   182,   182,   182,   182,   183,   183,   184,   184,
     185,   185,   186,   186
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     2,     1,
       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
       1,     3,     2,     3,     1,     4,     5,     5,     6,     2,
       1,     3,     3,     1,     4,     1,     1,     1,     1,     1,
       1,     4,     4,     0,     3,     1,     1,     3,     3,     4,
       6,     5,     5,     6,     5,     4,     4,     4,     3,     4,
       3,     2,     2,     1,     1,     2,     3,     1,     1,     3,
       2,     2,     1,     1,     3,     2,     1,     2,     1,     1,
       3,     2,     3,     5,     4,     5,     4,     3,     3,     3,
       4,     6,     5,     5,     6,     4,     4,     2,     3,     3,
       4,     3,     4,     1,     2,     1,     4,     3,     2,     1,
       2,     3,     2,     7,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     1,     2,     1,     1,     1,
       2,     0,     8,     5,     5,     5,     7,     6,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7: /* constant: I_CONSTANT  */
#line 57 "yapl.y"
                     {int_consts++;}
#line 2276 "y.tab.c"
    break;

  case 173: /* $@1: %empty  */
#line 361 "yapl.y"
                  {pointer_decls++;}
#line 2282 "y.tab.c"
    break;

  case 261: /* $@2: %empty  */
#line 518 "yapl.y"
                                               {ladder_len++;(yyvsp[0].val)=(ladder_len-1);}
#line 2288 "y.tab.c"
    break;

  case 262: /* selection_statement: IF '(' expression ')' statement ELSE $@2 statement  */
#line 518 "yapl.y"
                                                                                           {if(ladder_len>=max){max=ladder_len;} /*printf("ladder_len=%d\n",ladder_len);*/ladder_len=(yyvsp[-2].val);}
#line 2294 "y.tab.c"
    break;

  case 263: /* selection_statement: IF '(' expression ')' statement  */
#line 519 "yapl.y"
                                          {ifs_wo_else++;}
#line 2300 "y.tab.c"
    break;

  case 276: /* translation_unit: external_declaration  */
#line 541 "yapl.y"
                               {global_declarations++;}
#line 2306 "y.tab.c"
    break;

  case 277: /* translation_unit: translation_unit external_declaration  */
#line 542 "yapl.y"
                                                {global_declarations++;}
#line 2312 "y.tab.c"
    break;

  case 278: /* external_declaration: function_definition  */
#line 546 "yapl.y"
                              {func_definitions++;}
#line 2318 "y.tab.c"
    break;


#line 2322 "y.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 560 "yapl.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buff[2048];

int yylex(void);
int mode=-1;

void yyerror(const char *s)
{
	fflush(stdout);
	
	if(mode==-1)
		printf("***parsing terminated*** [syntax error]\n");
	else if(mode==0 || mode==1)
		printf("%s\n",s);
		
	exit(-1);
}

int main(int argc, char **argv)
{
    extern FILE *yyin;

	if(argc<2)
	{
		sprintf(buff,"***process terminated*** [input error]: invalid number of command-line arguments");
		mode=1;
		yyerror(buff);
		exit(1);
	}

	yyin=fopen(argv[1],"r");

	if(yyin==NULL)
	{
		sprintf(buff,"***process terminated*** [input error]: no such file \"%s\" exists",argv[1]);
		mode=1;
		yyerror(buff);
		exit(1);
	}
	else
	{
		do
		{
			yyparse();
		}
		while(!feof(yyin));
	}

	printf("***parsing successful***\n");
	printf("#global_declarations = %d\n",global_declarations);
	printf("#function_definitions = %d\n",func_definitions);
	printf("#integer_constants = %d\n",int_consts);
	printf("#pointers_declarations = %d\n",pointer_decls);
	printf("#ifs_without_else = %d\n",ifs_wo_else);
	printf("if-else max-depth = %d\n",((max<0)?0:max));

	return(0);
}

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


//  TAC (Quadruple) structure
int temp_count = 0;

typedef struct {
    char op[10];
    char arg1[20];
    char arg2[20];
    char result[20];
} quad;

quad quads[1000];
int quad_index = 0;
int label_count = 0;
char *last_false_label;
char *last_start_label;
char *last_end_label;

//  Generate temporary variables (t1, t2, ...)
char* new_temp() {
    char *temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

//  Generate labels (L0, L1, ...)
char* new_label() {
    char *label = (char*)malloc(20);
    sprintf(label, "L%d", label_count++);
    return label;
}

//  Add a quadruple
void add_quad(char *op, char *arg1, char *arg2, char *result) {
    strcpy(quads[quad_index].op, op);
    strcpy(quads[quad_index].arg1, arg1);
    strcpy(quads[quad_index].arg2, arg2);
    strcpy(quads[quad_index].result, result);
    quad_index++;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "table_data.h"

char derivations[1000][200];
int dtop = 0;

extern int line_no;
extern char *yytext;
int yylex(void);
void yyerror(const char *s)
{
    fprintf(stderr, "\nSyntax Error at line %d near token '%s'\n", line_no, yytext);
    exit(1);
}
int global_declarations=0;
int func_definitions=0;
int int_consts=0;
int pointer_decls=0;
int ifs_wo_else=0;
int ladder_len=0,hold=0;
int max=-1;

#line 139 "yapl.tab.c"

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

#include "yapl.tab.h"
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
  YYSYMBOL_IFX = 83,                       /* IFX  */
  YYSYMBOL_84_ = 84,                       /* '='  */
  YYSYMBOL_85_ = 85,                       /* ','  */
  YYSYMBOL_86_ = 86,                       /* '('  */
  YYSYMBOL_87_ = 87,                       /* ')'  */
  YYSYMBOL_88_ = 88,                       /* ':'  */
  YYSYMBOL_89_ = 89,                       /* '['  */
  YYSYMBOL_90_ = 90,                       /* ']'  */
  YYSYMBOL_91_ = 91,                       /* '.'  */
  YYSYMBOL_92_ = 92,                       /* '{'  */
  YYSYMBOL_93_ = 93,                       /* '}'  */
  YYSYMBOL_94_ = 94,                       /* '-'  */
  YYSYMBOL_95_ = 95,                       /* '&'  */
  YYSYMBOL_96_ = 96,                       /* '*'  */
  YYSYMBOL_97_ = 97,                       /* '+'  */
  YYSYMBOL_98_ = 98,                       /* '~'  */
  YYSYMBOL_99_ = 99,                       /* '!'  */
  YYSYMBOL_100_ = 100,                     /* '/'  */
  YYSYMBOL_101_ = 101,                     /* '%'  */
  YYSYMBOL_102_ = 102,                     /* '<'  */
  YYSYMBOL_103_ = 103,                     /* '>'  */
  YYSYMBOL_104_ = 104,                     /* '^'  */
  YYSYMBOL_105_ = 105,                     /* '|'  */
  YYSYMBOL_106_ = 106,                     /* '?'  */
  YYSYMBOL_107_ = 107,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 108,                 /* $accept  */
  YYSYMBOL_primary_expression = 109,       /* primary_expression  */
  YYSYMBOL_constant = 110,                 /* constant  */
  YYSYMBOL_enumeration_constant = 111,     /* enumeration_constant  */
  YYSYMBOL_string = 112,                   /* string  */
  YYSYMBOL_generic_selection = 113,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 114,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 115,      /* generic_association  */
  YYSYMBOL_postfix_expression = 116,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 117, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 118, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 119,         /* unary_expression  */
  YYSYMBOL_unary_operator = 120,           /* unary_operator  */
  YYSYMBOL_cast_expression = 121,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 122, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 123,      /* additive_expression  */
  YYSYMBOL_shift_expression = 124,         /* shift_expression  */
  YYSYMBOL_relational_expression = 125,    /* relational_expression  */
  YYSYMBOL_equality_expression = 126,      /* equality_expression  */
  YYSYMBOL_and_expression = 127,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 128,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 129,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 130,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 131,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 132,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 133,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 134,      /* assignment_operator  */
  YYSYMBOL_expression = 135,               /* expression  */
  YYSYMBOL_constant_expression = 136,      /* constant_expression  */
  YYSYMBOL_declaration = 137,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 138,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 139,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 140,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 141,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 142,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 143, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 144,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 145,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 146,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 147, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 148,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 149,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 150,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 151,          /* enumerator_list  */
  YYSYMBOL_enumerator = 152,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 153,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 154,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 155,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 156,      /* alignment_specifier  */
  YYSYMBOL_declarator = 157,               /* declarator  */
  YYSYMBOL_direct_declarator = 158,        /* direct_declarator  */
  YYSYMBOL_pointer = 159,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 160,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 161,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 162,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 163,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 164,          /* identifier_list  */
  YYSYMBOL_type_name = 165,                /* type_name  */
  YYSYMBOL_abstract_declarator = 166,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 167, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 168,              /* initializer  */
  YYSYMBOL_initializer_list = 169,         /* initializer_list  */
  YYSYMBOL_designation = 170,              /* designation  */
  YYSYMBOL_designator_list = 171,          /* designator_list  */
  YYSYMBOL_designator = 172,               /* designator  */
  YYSYMBOL_static_assert_declaration = 173, /* static_assert_declaration  */
  YYSYMBOL_statement = 174,                /* statement  */
  YYSYMBOL_labeled_statement = 175,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 176,       /* compound_statement  */
  YYSYMBOL_block_item_list = 177,          /* block_item_list  */
  YYSYMBOL_block_item = 178,               /* block_item  */
  YYSYMBOL_expression_statement = 179,     /* expression_statement  */
  YYSYMBOL_selection_statement = 180,      /* selection_statement  */
  YYSYMBOL_181_1 = 181,                    /* $@1  */
  YYSYMBOL_182_2 = 182,                    /* $@2  */
  YYSYMBOL_183_3 = 183,                    /* $@3  */
  YYSYMBOL_iteration_statement = 184,      /* iteration_statement  */
  YYSYMBOL_185_4 = 185,                    /* $@4  */
  YYSYMBOL_186_5 = 186,                    /* $@5  */
  YYSYMBOL_187_6 = 187,                    /* $@6  */
  YYSYMBOL_jump_statement = 188,           /* jump_statement  */
  YYSYMBOL_translation_unit = 189,         /* translation_unit  */
  YYSYMBOL_external_declaration = 190,     /* external_declaration  */
  YYSYMBOL_function_definition = 191,      /* function_definition  */
  YYSYMBOL_declaration_list = 192          /* declaration_list  */
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
#define YYLAST   2106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  283
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  481

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


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
       2,     2,     2,    99,     2,     2,     2,   101,    95,     2,
      86,    87,    96,    97,    85,    94,    91,   100,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,   107,
     102,    84,   103,   106,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,   104,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    92,   105,    93,    98,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   112,   112,   115,   116,   117,   118,   122,   126,   129,
     135,   139,   145,   149,   150,   154,   157,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   174,   175,   179,   180,
     184,   185,   186,   187,   188,   189,   190,   191,   197,   198,
     199,   200,   201,   205,   206,   210,   211,   215,   219,   226,
     227,   231,   238,   239,   243,   250,   251,   255,   259,   263,
     267,   274,   275,   279,   286,   287,   294,   295,   302,   303,
     310,   311,   318,   319,   326,   327,   331,   335,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   368,   372,   379,   383,   386,   389,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     408,   409,   413,   414,   418,   419,   420,   421,   422,   423,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   446,   447,   448,   452,
     453,   457,   458,   462,   463,   464,   468,   469,   470,   471,
     475,   476,   480,   481,   482,   486,   487,   488,   489,   490,
     494,   495,   499,   500,   504,   508,   509,   510,   515,   516,
     520,   521,   525,   526,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   547,   548,
     549,   550,   554,   555,   560,   561,   565,   566,   570,   571,
     572,   576,   577,   581,   582,   586,   587,   588,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   616,
     617,   618,   622,   623,   624,   625,   629,   633,   634,   638,
     639,   643,   647,   651,   654,   657,   660,   663,   666,   672,
     673,   674,   678,   681,   687,   690,   696,   699,   705,   709,
     717,   716,   727,   732,   726,   746,   745,   759,   758,   769,
     768,   787,   788,   789,   790,   791,   795,   799,   806,   807,
     811,   814,   820,   821
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
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "IFX", "'='", "','", "'('",
  "')'", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'-'", "'&'", "'*'",
  "'+'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "';'", "$accept", "primary_expression", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
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
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "$@1", "$@2", "$@3",
  "iteration_statement", "$@4", "$@5", "$@6", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-377)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1829,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,    29,   -47,    33,  -377,    48,
    -377,  -377,    61,  1919,  1919,  -377,    43,  -377,  -377,  1919,
    1919,  1919,  -377,  1469,  -377,  -377,   -51,    50,   764,  2028,
    1206,  -377,    64,   173,  -377,   -37,  -377,  1672,    75,    21,
    -377,  -377,   -30,  1957,  -377,  -377,  -377,  -377,  -377,    50,
    -377,    70,   -17,  -377,  -377,  -377,  -377,  -377,  1259,  1283,
    1283,  -377,    60,    84,   764,  1283,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,   162,  -377,  1206,  -377,   -44,
     106,    96,   163,   197,   112,    85,   121,   212,    23,  -377,
     153,  2028,    66,  2028,   159,   168,   182,   171,  -377,  -377,
     173,    64,  -377,  1159,   402,  -377,    61,  -377,  1726,  1406,
     789,    75,  1957,  1568,  -377,    52,  -377,   100,  1206,    13,
    -377,   764,  -377,   764,  -377,  -377,  2028,  1206,   527,  -377,
    -377,   156,   188,  -377,   280,  -377,  -377,  1206,  1206,   289,
    -377,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,
    1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,
    1206,  -377,  -377,  1515,   866,   138,  -377,   149,  -377,  -377,
    -377,   290,  -377,  -377,  -377,  -377,   220,  1059,  -377,  -377,
     198,   218,  1206,   219,   222,   223,  -377,   224,   308,   205,
     206,   642,  -377,  -377,   -19,  -377,  -377,  -377,  -377,   528,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,    24,
     228,   231,  -377,   160,  1136,  -377,   229,   232,   889,  1617,
    -377,  -377,  1206,  -377,    73,  -377,   230,    19,  -377,  -377,
    -377,  -377,   234,   236,   238,   242,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  1206,  1206,  -377,  1182,  -377,   241,   250,  -377,
     126,  -377,  -377,  -377,  -377,   -44,   -44,   106,   106,    96,
      96,    96,    96,    96,   163,   163,   197,   112,    85,   121,
     212,   151,  -377,   249,   252,  1136,  -377,   251,   253,   912,
     149,  1780,   989,   255,  1206,   341,  -377,   103,  1159,   115,
    -377,  -377,   628,   257,   628,  1206,  1206,   628,   666,   239,
    -377,  -377,  -377,    94,  -377,  -377,  -377,  1346,  -377,   139,
    -377,  -377,  1875,   344,  -377,   259,  1136,  -377,  -377,  1206,
    -377,   263,   264,  -377,  -377,    37,  -377,  1206,  -377,   282,
     282,  -377,  1994,  -377,  -377,  1059,  -377,  -377,  1206,  -377,
    1206,  -377,  -377,   285,  1136,  -377,  -377,  1206,  -377,   287,
    -377,   291,  1136,  -377,   292,   293,  1012,   273,   294,  -377,
     427,  -377,  -377,  -377,  -377,  -377,   628,  -377,   169,   191,
     312,   666,  -377,  -377,  -377,  -377,  -377,  -377,   295,   296,
    -377,  -377,  -377,  -377,   299,   199,  -377,   300,   109,  -377,
    -377,  -377,   301,   302,  -377,  -377,   303,  1136,  -377,  -377,
    1206,  -377,   304,  -377,  -377,  -377,  -377,  1159,  -377,  -377,
    -377,   311,  1206,  -377,  -377,  1206,  1994,  -377,  1206,  1035,
    -377,  -377,  -377,  -377,   309,   310,  -377,  -377,   628,   628,
     628,  1206,   203,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,   210,  -377,   322,   283,   628,   628,  -377,  -377,
    -377
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   135,   114,   115,   116,   118,   119,   168,   165,   166,
     167,   129,   121,   122,   123,   124,   127,   128,   125,   126,
     120,   130,   131,   139,   140,     0,     0,     0,   169,     0,
     117,   279,     0,   101,   103,   133,     0,   134,   132,   105,
     107,   109,    99,     0,   276,   278,   159,     0,     0,     0,
       0,   174,     0,   191,    97,     0,   110,   113,   173,     0,
     100,   102,   138,     0,   104,   106,   108,     1,   277,     0,
      10,   163,     0,   160,     2,     7,     8,    11,     0,     0,
       0,     9,     0,     0,     0,     0,    38,    39,    40,    41,
      42,    17,     3,     4,     6,    30,    43,     0,    45,    49,
      52,    55,    61,    64,    66,    68,    70,    72,    74,    96,
       0,   147,   204,   149,     0,     0,     0,     0,   192,   190,
     189,     0,    98,     0,     0,   282,     0,   281,     0,     0,
       0,   172,     0,     0,   141,     0,   145,     0,     0,     0,
     155,     0,    34,     0,    31,    32,     0,     0,    43,    76,
      94,     0,     0,    37,     0,    22,    23,    26,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   146,     0,     0,   206,   203,   207,   148,   170,
     164,     0,   175,   193,   188,   111,   113,     0,   231,   112,
       0,     2,     0,     0,     0,     0,   267,     0,     0,     0,
       0,     0,   252,   258,     0,   256,   257,   243,   244,     0,
     254,   245,   246,   247,   248,   283,   280,   201,   186,   200,
       0,   195,   196,     0,     0,   176,    39,     0,     0,     0,
     136,   142,     0,   143,     0,   150,   154,     0,   157,   162,
     156,   161,     0,     0,     0,     0,    89,    90,    91,    92,
      93,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    78,     0,     0,     5,     0,    21,     0,    27,    28,
       0,    20,    46,    47,    48,    51,    50,    53,    54,    58,
      59,    60,    56,    57,    62,    63,    65,    67,    69,    71,
      73,     0,   225,     0,     0,     0,   209,    39,     0,     0,
     205,     0,     0,     0,     0,     0,   233,     0,     0,     0,
     237,   242,     0,     0,     0,     0,     0,     0,     0,     0,
     272,   273,   274,     0,   259,   253,   255,     0,   198,   206,
     199,   185,     0,     0,   187,     0,     0,   177,   184,     0,
     183,    39,     0,   137,   152,     0,   144,     0,   158,    35,
       0,    36,     0,    77,    95,     0,    44,    19,     0,    18,
       0,   226,   208,     0,     0,   210,   216,     0,   215,     0,
     227,     0,     0,   217,    39,     0,     0,     0,     0,   240,
       0,   229,   232,   236,   238,   249,     0,   251,     0,     0,
       0,     0,   271,   275,   194,   197,   202,   179,     0,     0,
     180,   182,   151,   153,     0,     0,    13,     0,     0,    29,
      75,   212,     0,     0,   214,   228,     0,     0,   218,   224,
       0,   223,     0,   241,   239,   230,   235,     0,   250,   260,
     265,     0,     0,   178,   181,     0,     0,    12,     0,     0,
      24,   211,   213,   220,     0,     0,   221,   234,     0,     0,
       0,     0,     0,    16,    14,    15,    25,   219,   222,   261,
     263,   266,     0,   269,     0,     0,     0,     0,   268,   270,
     264
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -377,  -377,  -377,  -377,  -377,  -377,  -377,   -35,  -377,  -377,
    -377,   194,  -377,   -46,    98,   133,    62,   128,   226,   233,
     225,   237,   235,  -377,   -20,   -97,  -377,   -66,   -33,   -45,
       4,  -377,   297,  -377,   -42,  -377,  -377,   284,  -113,    11,
    -377,    65,  -377,   348,  -116,  -377,   -48,  -377,  -377,   -24,
     -57,   -34,   -95,  -119,  -377,    77,  -377,    10,   -99,  -176,
    -120,    56,  -376,  -377,   104,   -52,  -293,  -377,   -32,  -377,
     207,  -274,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,   379,  -377,  -377
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    91,    92,    71,    93,    94,   415,   416,    95,   277,
     278,   148,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   149,   150,   272,   214,   110,    31,
     229,    55,    56,    33,    34,    35,    36,   133,   134,   112,
     244,   245,    37,    72,    73,    38,    39,    40,    41,   117,
      58,    59,   120,   303,   231,   232,   233,   417,   304,   187,
     316,   317,   318,   319,   320,    42,   216,   217,   218,   219,
     220,   221,   222,   458,   459,   474,   223,   460,   327,   476,
     224,    43,    44,    45,   128
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     113,   113,   131,   199,    32,   118,   111,   111,    57,   310,
     230,   136,   125,   186,   437,   113,    70,   116,   151,   119,
     241,   111,    70,   251,    51,   127,   198,    51,   109,   395,
     109,   397,    46,   237,   400,   238,   113,    60,    61,    48,
      51,    69,   111,    64,    65,    66,    62,    32,   121,   179,
     255,   160,   161,    70,   401,    51,   162,   163,   114,   115,
     279,   126,   132,   113,    51,   113,   273,    51,   139,   111,
     122,   111,   193,   437,   135,   151,   140,   151,   185,   215,
     136,   136,   118,   225,   113,   113,   194,   308,   334,   309,
     111,   111,   280,   113,   152,   113,   226,   196,   113,   111,
     198,   111,   196,   438,   111,   249,   250,    52,   166,   167,
     337,   246,   358,   184,   301,   282,   283,   284,   109,    49,
      53,    47,   182,    52,   188,   242,   241,   442,   126,   180,
     340,   251,   126,    53,    50,    63,   118,   345,    52,   346,
     242,   352,    51,   135,   135,   333,   146,    52,    53,   185,
      52,   252,   183,   253,   138,   184,   254,    53,   355,   243,
      53,   129,    53,   310,   130,   469,   470,   471,    54,   323,
     147,   154,   155,   156,   215,   363,   364,   168,   169,   273,
     356,   170,   109,   479,   480,   247,   118,   136,   390,   176,
     193,   113,   381,   248,   449,   339,   391,   111,   392,   393,
     164,   403,   450,   165,   314,   338,   315,   175,   373,   354,
     374,   273,   379,   173,   174,   385,   369,   386,     8,     9,
      10,   198,   109,   126,   183,   337,   177,   184,   184,   366,
     289,   290,   291,   292,   293,   311,   273,   178,   312,   370,
     181,   273,    96,   274,    96,   343,   189,   344,   157,   408,
     135,   158,   409,   159,   273,   190,   439,   118,   192,   398,
     399,   193,   285,   286,   118,   171,   172,   191,   198,    53,
     436,   419,   142,   144,   145,   275,   273,   422,   440,   153,
     423,   388,   131,   276,   446,   426,   447,   427,   273,   432,
     473,    96,   281,   198,   109,   273,   313,   475,   193,   287,
     288,   294,   295,   339,   123,   321,   322,   324,   325,   326,
     328,   329,   330,   331,   113,   341,   342,   457,   357,   347,
     111,   359,   348,   360,   413,   361,   193,   362,   367,   436,
     454,   246,    96,   455,   118,   368,   371,   109,   193,   372,
     198,   375,   387,   376,   389,   396,   402,   406,   463,   407,
     420,   465,   198,   410,   411,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,   365,   421,   462,   424,   425,   193,
     433,   441,   428,   429,   434,   443,   444,   445,   448,   477,
     478,   451,   452,   453,   456,   472,    96,   461,   113,   467,
     468,   296,   298,   200,   111,   201,    75,    76,    77,   297,
      78,   464,    79,    80,   300,   299,   239,   137,   195,   405,
     412,   418,    68,   394,     0,     0,   336,     0,     0,     0,
      74,    75,    76,    77,     0,    78,    96,    79,    80,     1,
      81,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    81,   202,   203,   204,    96,
       0,   205,   206,   207,   208,   209,   210,   211,    26,    82,
      27,    83,    28,    29,    30,     0,     0,     0,    84,     0,
       0,     0,     0,     0,   124,   212,    85,    86,    87,    88,
      89,    90,     0,     0,    82,     0,    83,     0,    96,   213,
       0,     0,     0,    84,     0,     0,   314,     0,   315,   197,
     435,    85,    86,    87,    88,    89,    90,     0,     0,   200,
       0,   201,    75,    76,    77,     0,    78,     0,    79,    80,
       0,     0,     0,     0,     0,     0,   256,   257,   258,   259,
     260,    96,     0,     0,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,    96,     1,    81,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   209,   210,   211,    26,    82,    27,    83,    28,    29,
      30,   271,     0,     0,    84,     0,     0,     0,     0,     0,
     124,   335,    85,    86,    87,    88,    89,    90,     0,   200,
       0,   201,    75,    76,    77,   213,    78,     0,    79,    80,
       0,     0,     0,     0,     0,    74,    75,    76,    77,     0,
      78,     0,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,    74,
      75,    76,    77,     0,    78,     0,    79,    80,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   209,   210,   211,    81,    82,     0,    83,     0,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,    82,
     124,    83,    85,    86,    87,    88,    89,    90,    84,     0,
       0,     0,     0,     0,     0,   213,    85,    86,    87,    88,
      89,    90,     0,    82,     0,    83,     0,     0,     0,   332,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,     0,    74,    75,    76,
      77,     0,    78,   213,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,     0,    78,     0,    79,
      80,     1,    81,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    81,     0,     0,
     234,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,    82,    27,    83,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,     0,     0,    82,     0,    83,    74,
      75,    76,    77,     0,    78,    84,    79,    80,     0,   235,
       0,     0,     0,    85,    86,   236,    88,    89,    90,     0,
       0,     0,    74,    75,    76,    77,     0,    78,     0,    79,
      80,     0,     0,     0,    81,     0,     0,   305,     0,     0,
       0,     8,     9,    10,     0,    74,    75,    76,    77,     0,
      78,     0,    79,    80,     0,     0,     0,    81,     0,     0,
     349,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,     0,     0,    82,     0,    83,     0,     0,     0,     0,
      81,     0,    84,   377,     0,     0,   306,     8,     9,    10,
      85,    86,   307,    88,    89,    90,    82,     0,    83,     0,
       0,     0,     0,     0,     0,    84,     0,     0,     0,   350,
       0,     0,     0,    85,    86,   351,    88,    89,    90,    82,
       0,    83,    74,    75,    76,    77,     0,    78,    84,    79,
      80,     0,   378,     0,     0,     0,    85,    86,    87,    88,
      89,    90,     0,     0,     0,    74,    75,    76,    77,     0,
      78,     0,    79,    80,     0,     0,     0,    81,     0,     0,
     382,     0,     0,     0,     8,     9,    10,     0,    74,    75,
      76,    77,     0,    78,     0,    79,    80,     0,     0,     0,
      81,     0,     0,   430,     0,     0,     0,     8,     9,    10,
       0,     0,    74,    75,    76,    77,    82,    78,    83,    79,
      80,     0,     0,    81,     0,    84,     0,     0,     0,   383,
       0,     0,     0,    85,    86,   384,    88,    89,    90,    82,
       0,    83,     0,     0,     0,     0,     0,    81,    84,     0,
       0,     0,   431,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    82,     0,    83,     0,     0,     0,     0,     0,
       0,    84,     0,     0,   314,     0,   315,   197,   466,    85,
      86,    87,    88,    89,    90,     0,    82,     0,    83,    74,
      75,    76,    77,     0,    78,    84,    79,    80,   314,     0,
     315,   197,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,    74,    75,    76,    77,     0,    78,     0,    79,
      80,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     8,     9,    10,     0,    74,    75,    76,    77,     0,
      78,     0,    79,    80,     0,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    82,    78,    83,    79,    80,     0,     0,
      81,     0,    84,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    82,     0,    83,     0,
       0,     0,     0,     0,    81,    84,     0,     0,     0,     0,
       0,   197,     0,    85,    86,    87,    88,    89,    90,    82,
       0,    83,    74,    75,    76,    77,     0,    78,    84,    79,
      80,     0,     0,     0,   365,     0,    85,    86,    87,    88,
      89,    90,     0,    82,     0,    83,    74,    75,    76,    77,
       0,    78,    84,    79,    80,     0,     0,    81,     0,     0,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,    83,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,    51,
       0,     0,     0,    85,    86,    87,    88,    89,    90,     0,
      82,     0,    83,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,     0,    30,     0,
       0,     0,   337,   302,     0,   184,     0,     0,     0,     0,
       0,     0,    53,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,     0,    30,     0,
       0,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
      29,    30,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,     0,
       0,   183,   302,     0,   184,     1,     0,     0,     0,     0,
       0,    53,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,    29,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,   240,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
     353,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,    29,    30,     0,   123,     0,     0,     0,
       0,     0,     0,     1,   124,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     1,   124,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,     0,
      28,     0,    30,     0,     0,     0,     1,   380,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
      29,    30,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   404,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     1,    30,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,    26,     0,    27,     0,    28,
       0,    30,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,    27,     0,     0,    29,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,   414,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,    27,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      48,    49,    59,   123,     0,    53,    48,    49,    32,   185,
     129,    63,    57,   112,   390,    63,     3,    50,    84,    53,
     133,    63,     3,   139,     3,    57,   123,     3,    48,   322,
      50,   324,     3,   130,   327,   130,    84,    33,    34,    86,
       3,    92,    84,    39,    40,    41,     3,    43,    85,    26,
     147,    97,    96,     3,   328,     3,   100,   101,    48,    49,
     157,    57,    92,   111,     3,   113,    85,     3,    85,   111,
     107,   113,   120,   449,    63,   141,    93,   143,   112,   124,
     132,   133,   130,   128,   132,   133,   120,   184,   107,   184,
     132,   133,   158,   141,    84,   143,   128,   121,   146,   141,
     197,   143,   126,   396,   146,   138,    93,    86,    12,    13,
      86,   135,    93,    89,   180,   161,   162,   163,   138,    86,
      96,    92,   111,    86,   113,    88,   239,   401,   124,   106,
     229,   247,   128,    96,    86,    92,   184,   234,    86,   234,
      88,   238,     3,   132,   133,   211,    86,    86,    96,   183,
      86,   141,    86,   143,    84,    89,   146,    96,    85,   107,
      96,    86,    96,   339,    89,   458,   459,   460,   107,   202,
      86,     9,    10,    11,   219,   272,   273,    14,    15,    85,
     107,    18,   202,   476,   477,    85,   234,   239,    85,   104,
     238,   239,   311,    93,    85,   229,    93,   239,   318,    84,
      94,   107,    93,    97,    89,   229,    91,    95,   305,   242,
     305,    85,   309,    16,    17,   312,    90,   312,    45,    46,
      47,   318,   242,   219,    86,    86,   105,    89,    89,   275,
     168,   169,   170,   171,   172,    86,    85,    25,    89,    88,
      87,    85,    48,    87,    50,    85,    87,    87,    86,   346,
     239,    89,   349,    91,    85,    87,    87,   305,    87,   325,
     326,   309,   164,   165,   312,   102,   103,    85,   365,    96,
     390,   368,    78,    79,    80,    87,    85,   374,    87,    85,
     377,   314,   339,     3,    85,   382,    87,   382,    85,   386,
      87,    97,     3,   390,   314,    85,     6,    87,   346,   166,
     167,   173,   174,   337,    84,   107,    88,    88,    86,    86,
      86,     3,   107,   107,   362,    87,    85,   437,    88,    90,
     362,    87,    90,    87,   357,    87,   374,    85,    87,   449,
     427,   355,   138,   430,   382,    85,    87,   357,   386,    87,
     437,    90,    87,    90,     3,    88,   107,     3,   445,    90,
     370,   448,   449,    90,    90,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,    92,    90,   442,    90,    87,   427,
     107,    69,    90,    90,    90,    90,    90,    88,    88,    67,
     107,    90,    90,    90,    90,   461,   202,    86,   446,    90,
      90,   175,   177,     1,   446,     3,     4,     5,     6,   176,
       8,   446,    10,    11,   179,   178,   132,    69,   121,   342,
     355,   365,    43,   319,    -1,    -1,   219,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,   242,    10,    11,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    38,    64,    65,    66,   275,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    77,    -1,    79,    -1,   314,   107,
      -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,   357,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,   370,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    84,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,     1,
      -1,     3,     4,     5,     6,   107,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    38,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    77,
      92,    79,    94,    95,    96,    97,    98,    99,    86,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    94,    95,    96,    97,
      98,    99,    -1,    77,    -1,    79,    -1,    -1,    -1,   107,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    -1,     3,     4,     5,
       6,    -1,     8,   107,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    10,
      11,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    -1,    -1,    77,    -1,    79,     3,
       4,     5,     6,    -1,     8,    86,    10,    11,    -1,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    10,
      11,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      -1,    45,    46,    47,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    10,    11,    -1,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,
      38,    -1,    86,    41,    -1,    -1,    90,    45,    46,    47,
      94,    95,    96,    97,    98,    99,    77,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    77,
      -1,    79,     3,     4,     5,     6,    -1,     8,    86,    10,
      11,    -1,    90,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    10,    11,    -1,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,     3,     4,     5,     6,    77,     8,    79,    10,
      11,    -1,    -1,    38,    -1,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    77,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    38,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    89,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    77,    -1,    79,     3,
       4,     5,     6,    -1,     8,    86,    10,    11,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    10,
      11,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    10,    11,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    77,     8,    79,    10,    11,    -1,    -1,
      38,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    77,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    38,    86,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    94,    95,    96,    97,    98,    99,    77,
      -1,    79,     3,     4,     5,     6,    -1,     8,    86,    10,
      11,    -1,    -1,    -1,    92,    -1,    94,    95,    96,    97,
      98,    99,    -1,    77,    -1,    79,     3,     4,     5,     6,
      -1,     8,    86,    10,    11,    -1,    -1,    38,    -1,    -1,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    78,    -1,    80,    -1,    82,    -1,
      -1,    -1,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    78,    -1,    80,    -1,    82,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      81,    82,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    -1,    82,    -1,    -1,
      -1,    86,    87,    -1,    89,    37,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      93,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      78,    -1,    80,    81,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    92,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    78,    -1,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    92,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,
      80,    -1,    82,    -1,    -1,    -1,    37,    87,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      81,    82,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    37,    82,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    76,    -1,    78,    -1,    80,
      -1,    82,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    78,    -1,    -1,    81,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    76,    78,    80,    81,
      82,   137,   138,   141,   142,   143,   144,   150,   153,   154,
     155,   156,   173,   189,   190,   191,     3,    92,    86,    86,
      86,     3,    86,    96,   107,   139,   140,   157,   158,   159,
     138,   138,     3,    92,   138,   138,   138,     0,   190,    92,
       3,   111,   151,   152,     3,     4,     5,     6,     8,    10,
      11,    38,    77,    79,    86,    94,    95,    96,    97,    98,
      99,   109,   110,   112,   113,   116,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     136,   142,   147,   154,   165,   165,   136,   157,   154,   159,
     160,    85,   107,    84,    92,   137,   138,   176,   192,    86,
      89,   158,    92,   145,   146,   147,   173,   151,    84,    85,
      93,    86,   119,    86,   119,   119,    86,    86,   119,   132,
     133,   135,   165,   119,     9,    10,    11,    86,    89,    91,
     121,    96,   100,   101,    94,    97,    12,    13,    14,    15,
      18,   102,   103,    16,    17,    95,   104,   105,    25,    26,
     106,    87,   147,    86,    89,   159,   166,   167,   147,    87,
      87,    85,    87,   154,   159,   140,   157,    92,   133,   168,
       1,     3,    64,    65,    66,    69,    70,    71,    72,    73,
      74,    75,    93,   107,   135,   137,   174,   175,   176,   177,
     178,   179,   180,   184,   188,   137,   176,     3,    87,   138,
     161,   162,   163,   164,    41,    90,    96,   133,   160,   145,
      93,   146,    88,   107,   148,   149,   157,    85,    93,   136,
      93,   152,   165,   165,   165,   133,    19,    20,    21,    22,
      23,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    84,   134,    85,    87,    87,     3,   117,   118,   133,
     135,     3,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   125,   125,   126,   127,   128,   129,
     130,   135,    87,   161,   166,    41,    90,    96,   133,   160,
     167,    86,    89,     6,    89,    91,   168,   169,   170,   171,
     172,   107,    88,   136,    88,    86,    86,   186,    86,     3,
     107,   107,   107,   135,   107,    93,   178,    86,   157,   159,
     166,    87,    85,    85,    87,   133,   160,    90,    90,    41,
      90,    96,   133,    93,   136,    85,   107,    88,    93,    87,
      87,    87,    85,   133,   133,    92,   121,    87,    85,    90,
      88,    87,    87,   133,   160,    90,    90,    41,    90,   133,
      87,   161,    41,    90,    96,   133,   160,    87,   136,     3,
      85,    93,   168,    84,   172,   174,    88,   174,   135,   135,
     174,   179,   107,   107,    63,   163,     3,    90,   133,   133,
      90,    90,   149,   136,    65,   114,   115,   165,   169,   133,
     132,    90,   133,   133,    90,    87,   133,   160,    90,    90,
      41,    90,   133,   107,    90,    93,   168,   170,   174,    87,
      87,    69,   179,    90,    90,    88,    85,    87,    88,    85,
      93,    90,    90,    90,   133,   133,    90,   168,   181,   182,
     185,    86,   135,   133,   115,   133,    93,    90,    90,   174,
     174,   174,   135,    87,   183,    87,   187,    67,   107,   174,
     174
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     111,   112,   113,   114,   114,   115,   115,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   117,   117,   118,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     120,   120,   120,   121,   121,   122,   122,   122,   122,   123,
     123,   123,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   135,   135,   136,   137,   137,   137,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     139,   139,   140,   140,   141,   141,   141,   141,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   143,   143,   143,   144,
     144,   145,   145,   146,   146,   146,   147,   147,   147,   147,
     148,   148,   149,   149,   149,   150,   150,   150,   150,   150,
     151,   151,   152,   152,   153,   154,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   159,   159,
     159,   159,   160,   160,   161,   161,   162,   162,   163,   163,
     163,   164,   164,   165,   165,   166,   166,   166,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   168,
     168,   168,   169,   169,   169,   169,   170,   171,   171,   172,
     172,   173,   174,   174,   174,   174,   174,   174,   174,   175,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     181,   180,   182,   183,   180,   185,   184,   186,   184,   187,
     184,   188,   188,   188,   188,   188,   189,   189,   190,   190,
     191,   191,   192,   192
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     6,     1,     3,     3,     3,     1,     4,     4,
       3,     3,     2,     2,     6,     7,     0,     1,     1,     3,
       1,     2,     2,     2,     2,     4,     4,     2,     1,     1,
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
       4,     4,     2,     1,     1,     3,     3,     4,     6,     5,
       5,     6,     5,     4,     4,     4,     3,     4,     3,     2,
       2,     1,     1,     2,     3,     1,     1,     3,     2,     2,
       1,     1,     3,     2,     1,     2,     1,     1,     3,     2,
       3,     5,     4,     5,     4,     3,     3,     3,     4,     6,
       5,     5,     6,     4,     4,     2,     3,     3,     4,     3,
       4,     1,     2,     1,     4,     3,     2,     1,     2,     3,
       2,     7,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     1,     2,     1,     1,     1,     2,
       0,     6,     0,     0,     9,     0,     6,     0,     8,     0,
       8,     3,     2,     2,     2,     3,     1,     2,     1,     1,
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
  case 2: /* primary_expression: IDENTIFIER  */
#line 112 "yapl.y"
                     {
		(yyval.place) = (yyvsp[0].place);
	}
#line 2020 "yapl.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 117 "yapl.y"
                     { (yyval.place) = (yyvsp[-1].place); }
#line 2026 "yapl.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 122 "yapl.y"
                     {
		int_consts++;
		(yyval.place) = strdup(yytext);
	}
#line 2035 "yapl.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 126 "yapl.y"
                     {
		(yyval.place) = strdup(yytext);
	}
#line 2043 "yapl.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 129 "yapl.y"
                               {
    	(yyval.place) = strdup(yytext);
	}
#line 2051 "yapl.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 139 "yapl.y"
                         {
		(yyval.place) = strdup(yytext);
	}
#line 2059 "yapl.tab.c"
    break;

  case 12: /* generic_selection: GENERIC '(' assignment_expression ',' generic_assoc_list ')'  */
#line 145 "yapl.y"
                                                                       { (yyval.place) = (yyvsp[-3].place); }
#line 2065 "yapl.tab.c"
    break;

  case 15: /* generic_association: type_name ':' assignment_expression  */
#line 154 "yapl.y"
                                          {
        (yyval.place) = (yyvsp[0].place);
    }
#line 2073 "yapl.tab.c"
    break;

  case 16: /* generic_association: DEFAULT ':' assignment_expression  */
#line 157 "yapl.y"
                                        {
        (yyval.place) = (yyvsp[0].place);
    }
#line 2081 "yapl.tab.c"
    break;

  case 17: /* postfix_expression: primary_expression  */
#line 162 "yapl.y"
                             { (yyval.place) = (yyvsp[0].place); }
#line 2087 "yapl.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 163 "yapl.y"
                                                { (yyval.place) = (yyvsp[-3].place); }
#line 2093 "yapl.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '(' argument_expression_list_opt ')'  */
#line 164 "yapl.y"
                                                                  { (yyval.place) = (yyvsp[-3].place); }
#line 2099 "yapl.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 165 "yapl.y"
                                            { (yyval.place) = (yyvsp[-2].place); }
#line 2105 "yapl.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 166 "yapl.y"
                                               { (yyval.place) = (yyvsp[-2].place); }
#line 2111 "yapl.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression INC_OP  */
#line 167 "yapl.y"
                                    { (yyval.place) = (yyvsp[-1].place); }
#line 2117 "yapl.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression DEC_OP  */
#line 168 "yapl.y"
                                    { (yyval.place) = (yyvsp[-1].place); }
#line 2123 "yapl.tab.c"
    break;

  case 24: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 169 "yapl.y"
                                                     { (yyval.place) = NULL; }
#line 2129 "yapl.tab.c"
    break;

  case 25: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 170 "yapl.y"
                                                         { (yyval.place) = NULL; }
#line 2135 "yapl.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 184 "yapl.y"
                             { (yyval.place) = (yyvsp[0].place); }
#line 2141 "yapl.tab.c"
    break;

  case 31: /* unary_expression: INC_OP unary_expression  */
#line 185 "yapl.y"
                                  { (yyval.place) = (yyvsp[0].place); }
#line 2147 "yapl.tab.c"
    break;

  case 32: /* unary_expression: DEC_OP unary_expression  */
#line 186 "yapl.y"
                                  { (yyval.place) = (yyvsp[0].place); }
#line 2153 "yapl.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 187 "yapl.y"
                                         { (yyval.place) = (yyvsp[0].place); }
#line 2159 "yapl.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 188 "yapl.y"
                                  { (yyval.place) = NULL; }
#line 2165 "yapl.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 189 "yapl.y"
                                   { (yyval.place) = NULL; }
#line 2171 "yapl.tab.c"
    break;

  case 36: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 190 "yapl.y"
                                    { (yyval.place) = NULL; }
#line 2177 "yapl.tab.c"
    break;

  case 37: /* unary_expression: '-' unary_expression  */
#line 191 "yapl.y"
                               {
		(yyval.place) = new_temp();
		add_quad("uminus", (yyvsp[0].place), "", (yyval.place));}
#line 2185 "yapl.tab.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 205 "yapl.y"
                           { (yyval.place) = (yyvsp[0].place); }
#line 2191 "yapl.tab.c"
    break;

  case 44: /* cast_expression: '(' type_name ')' cast_expression  */
#line 206 "yapl.y"
                                            { (yyval.place) = (yyvsp[0].place); }
#line 2197 "yapl.tab.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 210 "yapl.y"
                          { (yyval.place) = (yyvsp[0].place); }
#line 2203 "yapl.tab.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 211 "yapl.y"
                                                        {
		(yyval.place) = new_temp();
		add_quad("*", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2212 "yapl.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 215 "yapl.y"
                                                        {
		(yyval.place) = new_temp();
		add_quad("/", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2221 "yapl.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 219 "yapl.y"
                                                        {
		(yyval.place) = new_temp();
		add_quad("%", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2230 "yapl.tab.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 226 "yapl.y"
                                    { (yyval.place) = (yyvsp[0].place); }
#line 2236 "yapl.tab.c"
    break;

  case 50: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 227 "yapl.y"
                                                            {
		(yyval.place) = new_temp();
		add_quad("+", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2245 "yapl.tab.c"
    break;

  case 51: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 231 "yapl.y"
                                                            {
		(yyval.place) = new_temp();
		add_quad("-", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2254 "yapl.tab.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 238 "yapl.y"
                              { (yyval.place) = (yyvsp[0].place); }
#line 2260 "yapl.tab.c"
    break;

  case 53: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 239 "yapl.y"
                                                       {
		(yyval.place) = new_temp();
		add_quad("<<", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2269 "yapl.tab.c"
    break;

  case 54: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 243 "yapl.y"
                                                        {
		(yyval.place) = new_temp();
		add_quad(">>", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2278 "yapl.tab.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 250 "yapl.y"
                           { (yyval.place) = (yyvsp[0].place); }
#line 2284 "yapl.tab.c"
    break;

  case 56: /* relational_expression: relational_expression '<' shift_expression  */
#line 251 "yapl.y"
                                                 {
        (yyval.place) = new_temp();
        add_quad("<", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2293 "yapl.tab.c"
    break;

  case 57: /* relational_expression: relational_expression '>' shift_expression  */
#line 255 "yapl.y"
                                                 {
        (yyval.place) = new_temp();
        add_quad(">", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2302 "yapl.tab.c"
    break;

  case 58: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 259 "yapl.y"
                                                   {
        (yyval.place) = new_temp();
        add_quad("<=", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2311 "yapl.tab.c"
    break;

  case 59: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 263 "yapl.y"
                                                   {
        (yyval.place) = new_temp();
        add_quad(">=", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2320 "yapl.tab.c"
    break;

  case 60: /* relational_expression: relational_expression TH_OP shift_expression  */
#line 267 "yapl.y"
                                                   {
        (yyval.place) = new_temp();
        add_quad("<=>", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2329 "yapl.tab.c"
    break;

  case 61: /* equality_expression: relational_expression  */
#line 274 "yapl.y"
                                { (yyval.place) = (yyvsp[0].place); }
#line 2335 "yapl.tab.c"
    break;

  case 62: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 275 "yapl.y"
                                                      {
        (yyval.place) = new_temp();
        add_quad("==", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2344 "yapl.tab.c"
    break;

  case 63: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 279 "yapl.y"
                                                      {
        (yyval.place) = new_temp();
        add_quad("!=", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2353 "yapl.tab.c"
    break;

  case 64: /* and_expression: equality_expression  */
#line 286 "yapl.y"
                              { (yyval.place) = (yyvsp[0].place); }
#line 2359 "yapl.tab.c"
    break;

  case 65: /* and_expression: and_expression '&' equality_expression  */
#line 287 "yapl.y"
                                                 {
		(yyval.place) = new_temp();
		add_quad("&", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2368 "yapl.tab.c"
    break;

  case 66: /* exclusive_or_expression: and_expression  */
#line 294 "yapl.y"
                         { (yyval.place) = (yyvsp[0].place); }
#line 2374 "yapl.tab.c"
    break;

  case 67: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 295 "yapl.y"
                                                     {
		(yyval.place) = new_temp();
		add_quad("^", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2383 "yapl.tab.c"
    break;

  case 68: /* inclusive_or_expression: exclusive_or_expression  */
#line 302 "yapl.y"
                                  { (yyval.place) = (yyvsp[0].place); }
#line 2389 "yapl.tab.c"
    break;

  case 69: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 303 "yapl.y"
                                                              {
		(yyval.place) = new_temp();
		add_quad("|", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
	}
#line 2398 "yapl.tab.c"
    break;

  case 70: /* logical_and_expression: inclusive_or_expression  */
#line 310 "yapl.y"
                                  { (yyval.place) = (yyvsp[0].place); }
#line 2404 "yapl.tab.c"
    break;

  case 71: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 311 "yapl.y"
                                                            {
        (yyval.place) = new_temp();
        add_quad("&&", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2413 "yapl.tab.c"
    break;

  case 72: /* logical_or_expression: logical_and_expression  */
#line 318 "yapl.y"
                                 { (yyval.place) = (yyvsp[0].place); }
#line 2419 "yapl.tab.c"
    break;

  case 73: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 319 "yapl.y"
                                                             {
        (yyval.place) = new_temp();
        add_quad("||", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));
    }
#line 2428 "yapl.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression  */
#line 326 "yapl.y"
                                { (yyval.place) = (yyvsp[0].place); }
#line 2434 "yapl.tab.c"
    break;

  case 75: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 327 "yapl.y"
                                                                          { (yyval.place) = (yyvsp[-4].place); }
#line 2440 "yapl.tab.c"
    break;

  case 76: /* assignment_expression: conditional_expression  */
#line 331 "yapl.y"
                             {
        (yyval.place) = (yyvsp[0].place);
        sprintf(derivations[dtop++], "assignment_expression -> conditional_expression");
    }
#line 2449 "yapl.tab.c"
    break;

  case 77: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 335 "yapl.y"
                                                                 {
        if (strcmp((yyvsp[-1].op), "=") == 0) {
            add_quad("=", (yyvsp[0].place), "", (yyvsp[-2].place));
        } else {
            char *tmp = new_temp();
            add_quad((yyvsp[-1].op), (yyvsp[-2].place), (yyvsp[0].place), tmp);
            add_quad("=", tmp, "", (yyvsp[-2].place));
        }
        (yyval.place) = (yyvsp[-2].place);
        sprintf(derivations[dtop++], "assignment_expression -> IDENTIFIER assignment_operator assignment_expression");
    }
#line 2465 "yapl.tab.c"
    break;

  case 78: /* assignment_operator: '='  */
#line 349 "yapl.y"
              { (yyval.op) = strdup("="); }
#line 2471 "yapl.tab.c"
    break;

  case 79: /* assignment_operator: MUL_ASSIGN  */
#line 350 "yapl.y"
                     { (yyval.op) = strdup("*"); }
#line 2477 "yapl.tab.c"
    break;

  case 80: /* assignment_operator: DIV_ASSIGN  */
#line 351 "yapl.y"
                     { (yyval.op) = strdup("/"); }
#line 2483 "yapl.tab.c"
    break;

  case 81: /* assignment_operator: MOD_ASSIGN  */
#line 352 "yapl.y"
                     { (yyval.op) = strdup("%"); }
#line 2489 "yapl.tab.c"
    break;

  case 82: /* assignment_operator: ADD_ASSIGN  */
#line 353 "yapl.y"
                     { (yyval.op) = strdup("+"); }
#line 2495 "yapl.tab.c"
    break;

  case 83: /* assignment_operator: SUB_ASSIGN  */
#line 354 "yapl.y"
                     { (yyval.op) = strdup("-"); }
#line 2501 "yapl.tab.c"
    break;

  case 84: /* assignment_operator: LEFT_ASSIGN  */
#line 355 "yapl.y"
                      { (yyval.op) = strdup("<<"); }
#line 2507 "yapl.tab.c"
    break;

  case 85: /* assignment_operator: RIGHT_ASSIGN  */
#line 356 "yapl.y"
                       { (yyval.op) = strdup(">>"); }
#line 2513 "yapl.tab.c"
    break;

  case 86: /* assignment_operator: AND_ASSIGN  */
#line 357 "yapl.y"
                     { (yyval.op) = strdup("&"); }
#line 2519 "yapl.tab.c"
    break;

  case 87: /* assignment_operator: XOR_ASSIGN  */
#line 358 "yapl.y"
                     { (yyval.op) = strdup("^"); }
#line 2525 "yapl.tab.c"
    break;

  case 88: /* assignment_operator: OR_ASSIGN  */
#line 359 "yapl.y"
                    { (yyval.op) = strdup("|"); }
#line 2531 "yapl.tab.c"
    break;

  case 89: /* assignment_operator: PEQ_OP  */
#line 360 "yapl.y"
                 { (yyval.op) = strdup("+"); }
#line 2537 "yapl.tab.c"
    break;

  case 90: /* assignment_operator: MEQ_OP  */
#line 361 "yapl.y"
                 { (yyval.op) = strdup("-"); }
#line 2543 "yapl.tab.c"
    break;

  case 91: /* assignment_operator: STREQ_OP  */
#line 362 "yapl.y"
                   { (yyval.op) = strdup("*"); }
#line 2549 "yapl.tab.c"
    break;

  case 92: /* assignment_operator: DEQ_OP  */
#line 363 "yapl.y"
                 { (yyval.op) = strdup("/"); }
#line 2555 "yapl.tab.c"
    break;

  case 93: /* assignment_operator: MODEQ_OP  */
#line 364 "yapl.y"
                   { (yyval.op) = strdup("%"); }
#line 2561 "yapl.tab.c"
    break;

  case 94: /* expression: assignment_expression  */
#line 368 "yapl.y"
                                {
		(yyval.place) = (yyvsp[0].place);
		sprintf(derivations[dtop++], "expression -> assignment_expression");
	}
#line 2570 "yapl.tab.c"
    break;

  case 95: /* expression: expression ',' assignment_expression  */
#line 372 "yapl.y"
                                               {
		(yyval.place) = (yyvsp[0].place);
		sprintf(derivations[dtop++], "expression -> expression , assignment_expression");
	}
#line 2579 "yapl.tab.c"
    break;

  case 97: /* declaration: declaration_specifiers ';'  */
#line 383 "yapl.y"
                                     {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers ;");
	}
#line 2587 "yapl.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 386 "yapl.y"
                                                          {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers init_declarator_list ;");
	}
#line 2595 "yapl.tab.c"
    break;

  case 99: /* declaration: static_assert_declaration  */
#line 389 "yapl.y"
                                    {
		sprintf(derivations[dtop++], "declaration -> static_assert_declaration");
	}
#line 2603 "yapl.tab.c"
    break;

  case 172: /* declarator: pointer direct_declarator  */
#line 525 "yapl.y"
                                    {pointer_decls++;}
#line 2609 "yapl.tab.c"
    break;

  case 242: /* statement: error ';'  */
#line 647 "yapl.y"
                    {
        printf("Recovered from error at line %d near token '%s'\n", line_no, yytext);
        yyerrok;
    }
#line 2618 "yapl.tab.c"
    break;

  case 243: /* statement: labeled_statement  */
#line 651 "yapl.y"
                            {
		sprintf(derivations[dtop++], "statement -> labeled_statement");
	}
#line 2626 "yapl.tab.c"
    break;

  case 244: /* statement: compound_statement  */
#line 654 "yapl.y"
                             {
		sprintf(derivations[dtop++], "statement -> compound_statement");
	}
#line 2634 "yapl.tab.c"
    break;

  case 245: /* statement: expression_statement  */
#line 657 "yapl.y"
                               {
		sprintf(derivations[dtop++], "statement -> expression_statement");
	}
#line 2642 "yapl.tab.c"
    break;

  case 246: /* statement: selection_statement  */
#line 660 "yapl.y"
                              {
		sprintf(derivations[dtop++], "statement -> selection_statement");
	}
#line 2650 "yapl.tab.c"
    break;

  case 247: /* statement: iteration_statement  */
#line 663 "yapl.y"
                              {
		sprintf(derivations[dtop++], "statement -> iteration_statement");
	}
#line 2658 "yapl.tab.c"
    break;

  case 248: /* statement: jump_statement  */
#line 666 "yapl.y"
                         {
		sprintf(derivations[dtop++], "statement -> jump_statement");
	}
#line 2666 "yapl.tab.c"
    break;

  case 252: /* compound_statement: '{' '}'  */
#line 678 "yapl.y"
                  {
		sprintf(derivations[dtop++], "compound_statement -> { }");
	}
#line 2674 "yapl.tab.c"
    break;

  case 253: /* compound_statement: '{' block_item_list '}'  */
#line 681 "yapl.y"
                                  {
		sprintf(derivations[dtop++], "compound_statement -> { block_item_list }");
	}
#line 2682 "yapl.tab.c"
    break;

  case 254: /* block_item_list: block_item  */
#line 687 "yapl.y"
                     {
		sprintf(derivations[dtop++], "block_item_list -> block_item");
	}
#line 2690 "yapl.tab.c"
    break;

  case 255: /* block_item_list: block_item_list block_item  */
#line 690 "yapl.y"
                                     {
		sprintf(derivations[dtop++], "block_item_list -> block_item_list block_item");
	}
#line 2698 "yapl.tab.c"
    break;

  case 256: /* block_item: declaration  */
#line 696 "yapl.y"
                      {
		sprintf(derivations[dtop++], "block_item -> declaration");
	}
#line 2706 "yapl.tab.c"
    break;

  case 257: /* block_item: statement  */
#line 699 "yapl.y"
                    {
		sprintf(derivations[dtop++], "block_item -> statement");
	}
#line 2714 "yapl.tab.c"
    break;

  case 258: /* expression_statement: ';'  */
#line 705 "yapl.y"
              {
		(yyval.place) = NULL;
		sprintf(derivations[dtop++], "expression_statement -> ;");
	}
#line 2723 "yapl.tab.c"
    break;

  case 259: /* expression_statement: expression ';'  */
#line 709 "yapl.y"
                         {
		(yyval.place) = (yyvsp[-1].place);
		sprintf(derivations[dtop++], "expression_statement -> expression ;");
	}
#line 2732 "yapl.tab.c"
    break;

  case 260: /* $@1: %empty  */
#line 717 "yapl.y"
        {
		last_false_label = new_label();
		add_quad("iffalse", (yyvsp[-1].place), "", last_false_label);
	}
#line 2741 "yapl.tab.c"
    break;

  case 261: /* selection_statement: IF '(' expression ')' $@1 statement  */
#line 722 "yapl.y"
        {
		add_quad("label", "", "", last_false_label);
	}
#line 2749 "yapl.tab.c"
    break;

  case 262: /* $@2: %empty  */
#line 727 "yapl.y"
        {
		last_false_label = new_label();
		add_quad("iffalse", (yyvsp[-1].place), "", last_false_label);
	}
#line 2758 "yapl.tab.c"
    break;

  case 263: /* $@3: %empty  */
#line 732 "yapl.y"
        {
		last_end_label = new_label();
		add_quad("goto", "", "", last_end_label);
		add_quad("label", "", "", last_false_label);
	}
#line 2768 "yapl.tab.c"
    break;

  case 264: /* selection_statement: IF '(' expression ')' $@2 statement $@3 ELSE statement  */
#line 739 "yapl.y"
        {
		add_quad("label", "", "", last_end_label);
	}
#line 2776 "yapl.tab.c"
    break;

  case 265: /* $@4: %empty  */
#line 746 "yapl.y"
                {
			last_start_label = new_label();
			last_end_label = new_label();

			add_quad("label", "", "", last_start_label);
			add_quad("iffalse", (yyvsp[-1].place), "", last_end_label);
		}
#line 2788 "yapl.tab.c"
    break;

  case 266: /* iteration_statement: WHILE '(' expression ')' $@4 statement  */
#line 754 "yapl.y"
                {
			add_quad("goto", "", "", last_start_label);
			add_quad("label", "", "", last_end_label);
		}
#line 2797 "yapl.tab.c"
    break;

  case 267: /* $@5: %empty  */
#line 759 "yapl.y"
        {
		last_start_label = new_label();
		add_quad("label", "", "", last_start_label);
	}
#line 2806 "yapl.tab.c"
    break;

  case 268: /* iteration_statement: DO $@5 statement WHILE '(' expression ')' ';'  */
#line 765 "yapl.y"
        {
		add_quad("ifgoto", (yyvsp[-2].place), "", last_start_label);
	}
#line 2814 "yapl.tab.c"
    break;

  case 269: /* $@6: %empty  */
#line 769 "yapl.y"
        {
		last_start_label = new_label();
		last_end_label = new_label();

		add_quad("label", "", "", last_start_label);
		add_quad("iffalse", (yyvsp[-2].place), "", last_end_label);
	}
#line 2826 "yapl.tab.c"
    break;

  case 270: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' $@6 statement  */
#line 777 "yapl.y"
        {
		// update expression (3rd expression)
		add_quad("eval", (yyvsp[-3].place), "", "");

		add_quad("goto", "", "", last_start_label);
		add_quad("label", "", "", last_end_label);
	}
#line 2838 "yapl.tab.c"
    break;

  case 276: /* translation_unit: external_declaration  */
#line 795 "yapl.y"
                               {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> external_declaration");
	}
#line 2847 "yapl.tab.c"
    break;

  case 277: /* translation_unit: translation_unit external_declaration  */
#line 799 "yapl.y"
                                                {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> translation_unit external_declaration");
	}
#line 2856 "yapl.tab.c"
    break;

  case 278: /* external_declaration: function_definition  */
#line 806 "yapl.y"
                              {func_definitions++;}
#line 2862 "yapl.tab.c"
    break;

  case 280: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 811 "yapl.y"
                                                                                {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator declaration_list compound_statement");
	}
#line 2870 "yapl.tab.c"
    break;

  case 281: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 814 "yapl.y"
                                                               {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator compound_statement");
	}
#line 2878 "yapl.tab.c"
    break;


#line 2882 "yapl.tab.c"

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

#line 824 "yapl.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buff[2048];

int yylex(void);
int mode=-1;

/*
void yyerror(const char *s)
{
	fflush(stdout);
	
	if(mode==-1)
		printf("***parsing terminated*** [syntax error]\n");
	else if(mode==0 || mode==1)
		printf("%s\n",s);
		
	exit(-1);
}
*/

void print_parsing_table() {
    printf("\nLALR(1) PARSING TABLE (Sparse Format)\n");
    printf("======================================\n");
    printf("%-10s | %-s\n", "State", "Actions / Transitions");
    printf("-----------|----------------------------------\n");

    for (int i = 0; i < NUM_STATES; i++) {
        printf("State %-4d | ", i);
        int transitions_found = 0;
        for (int j = 0; j < (NUM_TERMS + NUM_NON_TERMS); j++) {
            if (strlen(parsing_table[i][j]) > 0) {
                const char* sym_name = (j < NUM_TERMS) ? terminals[j] : non_terminals[j - NUM_TERMS];
                printf("[%s: %s] ", sym_name, parsing_table[i][j]);
                transitions_found = 1;
            }
        }
        if (!transitions_found) printf("-");
        printf("\n");
    }
}

void export_parsing_table_to_csv() {
    FILE *fp = fopen("parsing_table.csv", "w");
    if (fp == NULL) {
        printf("Error opening file for CSV export!\n");
        return;
    }

    // Write Header: State, then all terminal names, then all non-terminal names
    fprintf(fp, "State");
    for (int i = 0; i < NUM_TERMS; i++) {
        fprintf(fp, ",%s", terminals[i]);
    }
    for (int i = 0; i < NUM_NON_TERMS; i++) {
        fprintf(fp, ",%s", non_terminals[i]);
    }
    fprintf(fp, "\n");

    // Write Data Rows
    for (int i = 0; i < NUM_STATES; i++) {
        fprintf(fp, "%d", i); // State number
        for (int j = 0; j < (NUM_TERMS + NUM_NON_TERMS); j++) {
            // Check if the cell has an action
            if (parsing_table[i][j] && strlen(parsing_table[i][j]) > 0) {
                fprintf(fp, ",%s", parsing_table[i][j]);
            } else {
                fprintf(fp, ",-"); // Empty cell
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("\nSuccessfully exported LALR(1) table to 'parsing_table.csv'\n");
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


    export_parsing_table_to_csv();

    printf("\nReverse Derivation:\n");
	for(int i = dtop - 1; i >= 0; i--)
	{
		printf("%s\n", derivations[i]);
	}

    int indent = 0;

    printf("\nTree-like Reverse Derivation:\n");

    for(int i = dtop - 1; i >= 0; i--)
    {
        // print indentation
        for(int j = 0; j < indent; j++)
            printf("  ");

        printf("%s\n", derivations[i]);

        // increase indent for deeper levels
        if (strstr(derivations[i], "translation_unit") ||
            strstr(derivations[i], "function_definition") ||
            strstr(derivations[i], "compound_statement") ||
            strstr(derivations[i], "statement") ||
            strstr(derivations[i], "expression"))
        {
            indent++;
        }

        // limit indent (avoid going too deep)
        if(indent > 10) indent = 10;
    }

	printf("\nQuadruple Table:\n");
	printf("Op\tArg1\tArg2\tResult\n");

	for(int i = 0; i < quad_index; i++) {
		printf("%s\t%s\t%s\t%s\n",
			quads[i].op,
			quads[i].arg1,
			quads[i].arg2,
			quads[i].result);
	}

	return(0);
}



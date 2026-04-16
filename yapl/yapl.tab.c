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


/* ===== INCLUDES MUST COME FIRST (before any function that uses them) ===== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_data.h"

char *last_false_label;
char *last_start_label;
char *last_end_label;

/* Label stack for nested if-else */
#define STACK_SIZE 10000
char *false_label_stack[STACK_SIZE];
char *end_label_stack[STACK_SIZE];
int false_stack_top = 0;   /* separate counter */
int end_stack_top   = 0;   /* separate counter */

void push_false(char *l) {
    if (false_stack_top < STACK_SIZE)
        false_label_stack[false_stack_top++] = l;
    else { fprintf(stderr, "FATAL: false_label_stack overflow\n"); exit(1); }
}
char* pop_false() {
    if (false_stack_top > 0) return false_label_stack[--false_stack_top];
    fprintf(stderr, "FATAL: false_label_stack underflow\n"); return NULL;
}
void push_end(char *l) {
    if (end_stack_top < STACK_SIZE)
        end_label_stack[end_stack_top++] = l;
    else { fprintf(stderr, "FATAL: end_label_stack overflow\n"); exit(1); }
}
char* pop_end() {
    if (end_stack_top > 0) return end_label_stack[--end_stack_top];
    fprintf(stderr, "FATAL: end_label_stack underflow\n"); return NULL;
}

/* ===== TAC (Quadruple) structure ===== */
int temp_count = 1;

typedef struct {
    char op[20];
    char arg1[50];
    char arg2[50];
    char result[50];
} quad;

quad quads[1000];
int quad_index = 0;
int label_count = 1;


/* Generate temporary variables (t0, t1, t2, ...) */
char* new_temp() {
    char *temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

/* Generate labels (L0, L1, ...) */
char* new_label() {
    char *label = (char*)malloc(20);
    sprintf(label, "L%d", label_count++);
    return label;
}

/* Add a quadruple entry */
void add_quad(char *op, char *arg1, char *arg2, char *result) {
    strcpy(quads[quad_index].op,     op);
    strcpy(quads[quad_index].arg1,   arg1);
    strcpy(quads[quad_index].arg2,   arg2);
    strcpy(quads[quad_index].result, result);
    quad_index++;
}

/* ===== Parser support variables ===== */
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

int global_declarations = 0;
int func_definitions    = 0;
int int_consts          = 0;
int pointer_decls       = 0;
int ifs_wo_else         = 0;
int ladder_len = 0;
int  hold = 0;
int max = -1;
int if_depth =0;

#line 172 "yapl.tab.c"

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
  YYSYMBOL_83_ = 83,                       /* '|'  */
  YYSYMBOL_84_ = 84,                       /* '^'  */
  YYSYMBOL_85_ = 85,                       /* '&'  */
  YYSYMBOL_86_ = 86,                       /* '<'  */
  YYSYMBOL_87_ = 87,                       /* '>'  */
  YYSYMBOL_88_ = 88,                       /* '+'  */
  YYSYMBOL_89_ = 89,                       /* '-'  */
  YYSYMBOL_90_ = 90,                       /* '*'  */
  YYSYMBOL_91_ = 91,                       /* '/'  */
  YYSYMBOL_92_ = 92,                       /* '%'  */
  YYSYMBOL_UMINUS = 93,                    /* UMINUS  */
  YYSYMBOL_IFX = 94,                       /* IFX  */
  YYSYMBOL_95_ = 95,                       /* '='  */
  YYSYMBOL_96_ = 96,                       /* ','  */
  YYSYMBOL_97_ = 97,                       /* '('  */
  YYSYMBOL_98_ = 98,                       /* ')'  */
  YYSYMBOL_99_ = 99,                       /* ':'  */
  YYSYMBOL_100_ = 100,                     /* '['  */
  YYSYMBOL_101_ = 101,                     /* ']'  */
  YYSYMBOL_102_ = 102,                     /* '.'  */
  YYSYMBOL_103_ = 103,                     /* '{'  */
  YYSYMBOL_104_ = 104,                     /* '}'  */
  YYSYMBOL_105_ = 105,                     /* '~'  */
  YYSYMBOL_106_ = 106,                     /* '!'  */
  YYSYMBOL_107_ = 107,                     /* '?'  */
  YYSYMBOL_108_ = 108,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 109,                 /* $accept  */
  YYSYMBOL_primary_expression = 110,       /* primary_expression  */
  YYSYMBOL_constant = 111,                 /* constant  */
  YYSYMBOL_enumeration_constant = 112,     /* enumeration_constant  */
  YYSYMBOL_string = 113,                   /* string  */
  YYSYMBOL_generic_selection = 114,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 115,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 116,      /* generic_association  */
  YYSYMBOL_postfix_expression = 117,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 118, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 119, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 120,         /* unary_expression  */
  YYSYMBOL_unary_operator = 121,           /* unary_operator  */
  YYSYMBOL_cast_expression = 122,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 123, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 124,      /* additive_expression  */
  YYSYMBOL_shift_expression = 125,         /* shift_expression  */
  YYSYMBOL_relational_expression = 126,    /* relational_expression  */
  YYSYMBOL_equality_expression = 127,      /* equality_expression  */
  YYSYMBOL_and_expression = 128,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 129,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 130,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 131,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 132,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 133,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 134,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 135,      /* assignment_operator  */
  YYSYMBOL_expression = 136,               /* expression  */
  YYSYMBOL_constant_expression = 137,      /* constant_expression  */
  YYSYMBOL_declaration = 138,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 139,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 140,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 141,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 142,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 143,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 144, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 145,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 146,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 147,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 148, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 149,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 150,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 151,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 152,          /* enumerator_list  */
  YYSYMBOL_enumerator = 153,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 154,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 155,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 156,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 157,      /* alignment_specifier  */
  YYSYMBOL_declarator = 158,               /* declarator  */
  YYSYMBOL_direct_declarator = 159,        /* direct_declarator  */
  YYSYMBOL_pointer = 160,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 161,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 162,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 163,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 164,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 165,          /* identifier_list  */
  YYSYMBOL_type_name = 166,                /* type_name  */
  YYSYMBOL_abstract_declarator = 167,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 168, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 169,              /* initializer  */
  YYSYMBOL_initializer_list = 170,         /* initializer_list  */
  YYSYMBOL_designation = 171,              /* designation  */
  YYSYMBOL_designator_list = 172,          /* designator_list  */
  YYSYMBOL_designator = 173,               /* designator  */
  YYSYMBOL_static_assert_declaration = 174, /* static_assert_declaration  */
  YYSYMBOL_statement = 175,                /* statement  */
  YYSYMBOL_labeled_statement = 176,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 177,       /* compound_statement  */
  YYSYMBOL_block_item_list = 178,          /* block_item_list  */
  YYSYMBOL_block_item = 179,               /* block_item  */
  YYSYMBOL_expression_statement = 180,     /* expression_statement  */
  YYSYMBOL_else_part = 181,                /* else_part  */
  YYSYMBOL_182_1 = 182,                    /* $@1  */
  YYSYMBOL_selection_statement = 183,      /* selection_statement  */
  YYSYMBOL_184_2 = 184,                    /* $@2  */
  YYSYMBOL_iteration_statement = 185,      /* iteration_statement  */
  YYSYMBOL_186_3 = 186,                    /* $@3  */
  YYSYMBOL_187_4 = 187,                    /* $@4  */
  YYSYMBOL_188_5 = 188,                    /* $@5  */
  YYSYMBOL_189_6 = 189,                    /* $@6  */
  YYSYMBOL_190_7 = 190,                    /* $@7  */
  YYSYMBOL_jump_statement = 191,           /* jump_statement  */
  YYSYMBOL_translation_unit = 192,         /* translation_unit  */
  YYSYMBOL_external_declaration = 193,     /* external_declaration  */
  YYSYMBOL_function_definition = 194,      /* function_definition  */
  YYSYMBOL_declaration_list = 195          /* declaration_list  */
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
#define YYLAST   2288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  286
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  487

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   339


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
       2,     2,     2,   106,     2,     2,     2,    92,    85,     2,
      97,    98,    90,    88,    96,    89,   102,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    99,   108,
      86,    95,    87,   107,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   100,     2,   101,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   103,    83,   104,   105,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    93,    94
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   163,   163,   164,   165,   166,   167,   171,   175,   176,
     180,   184,   188,   192,   193,   197,   198,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   214,   215,   219,   223,
     230,   231,   232,   233,   234,   235,   236,   237,   244,   244,
     244,   244,   244,   248,   249,   253,   254,   256,   258,   263,
     264,   266,   271,   272,   274,   279,   280,   282,   284,   286,
     288,   293,   294,   296,   301,   302,   307,   308,   313,   314,
     319,   320,   325,   326,   331,   332,   336,   340,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   373,   377,   384,   388,   391,   394,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     413,   414,   418,   419,   423,   423,   423,   423,   423,   423,
     427,   427,   427,   427,   427,   427,   427,   428,   428,   428,
     428,   428,   429,   430,   431,   432,   436,   437,   438,   442,
     442,   446,   447,   451,   452,   453,   457,   458,   459,   460,
     464,   465,   469,   470,   471,   475,   476,   477,   478,   479,
     483,   484,   488,   489,   493,   497,   497,   497,   501,   501,
     505,   506,   510,   511,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   532,   533,
     534,   535,   539,   540,   544,   545,   549,   550,   554,   555,
     556,   560,   561,   565,   566,   570,   571,   572,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   600,
     601,   602,   606,   607,   608,   609,   613,   617,   618,   622,
     623,   627,   631,   635,   636,   637,   638,   639,   640,   644,
     645,   646,   650,   653,   659,   660,   664,   665,   669,   673,
     680,   689,   688,   707,   706,   718,   727,   733,   726,   748,
     747,   762,   768,   761,   786,   787,   788,   789,   790,   794,
     798,   805,   806,   810,   813,   819,   820
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
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'|'", "'^'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "IFX", "'='", "','",
  "'('", "')'", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'~'", "'!'",
  "'?'", "';'", "$accept", "primary_expression", "constant",
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
  "expression_statement", "else_part", "$@1", "selection_statement", "$@2",
  "iteration_statement", "$@3", "$@4", "$@5", "$@6", "$@7",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-358)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2011,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,  -358,    23,   -69,   -14,  -358,     0,
    -358,  -358,    77,  2101,  2101,  -358,    34,  -358,  -358,  2101,
    2101,  2101,  -358,  1568,  -358,  -358,   -64,    43,   721,  2210,
    1335,  -358,   112,    74,  -358,   -65,  -358,  1759,   -45,    41,
    -358,  -358,   -29,  2139,  -358,  -358,  -358,  -358,  -358,    43,
    -358,    26,   -55,  -358,  -358,  -358,  -358,  -358,  1354,  1373,
    1373,  -358,    10,    45,  -358,  -358,  1373,  -358,   721,  -358,
    -358,  -358,  -358,  -358,  -358,   266,  -358,  1335,  -358,   128,
     165,   148,   233,   270,    28,    67,    83,   154,    -1,  -358,
      90,  2210,    86,  2210,    98,   102,   120,  -358,  -358,   112,
     110,    74,  -358,  1228,   409,  -358,    77,  -358,  1824,  1505,
     746,   -45,  2139,  1633,  -358,    33,  -358,   -37,  1335,    18,
    -358,   721,  -358,   721,  -358,  -358,  2210,  1335,  -358,  1632,
    -358,  -358,   -40,   123,   221,  -358,  -358,  1335,  1335,   223,
    -358,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,
    1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,  1335,
    1335,  -358,  -358,  1889,   834,    12,  -358,   101,  -358,  -358,
    -358,   257,  -358,  -358,  -358,  -358,   172,  1173,  -358,  -358,
     162,   174,  1335,   191,   198,   201,  -358,  -358,   210,   311,
     213,   219,   611,  -358,  -358,   -58,  -358,  -358,  -358,  -358,
     499,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
      72,   237,   235,  -358,   117,  1209,   242,  -358,   249,   853,
    1693,  -358,  -358,  1335,  -358,   -54,  -358,   252,    20,  -358,
    -358,  -358,  -358,   254,   260,   261,   259,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,  1335,  1335,  -358,  1316,  -358,   262,   265,
    -358,   -23,  -358,  -358,  -358,  -358,   128,   128,   165,   165,
     148,   148,   148,   148,   148,   233,   233,   270,    28,    67,
      83,   154,   113,  -358,   264,   267,  1209,   263,  -358,   268,
     941,   101,  1951,   960,   269,  1335,   367,  -358,   -28,  1228,
      95,  -358,  -358,   589,   273,   589,  1335,  1335,   274,   589,
     633,   271,  -358,  -358,  -358,   -51,  -358,  -358,  -358,  1443,
    -358,    50,  -358,  -358,  2057,   370,  -358,   275,  1209,  -358,
    -358,  1335,   276,  -358,   277,  -358,  -358,   167,  -358,  1335,
    -358,   280,   280,  -358,  2176,  -358,  -358,  1173,  -358,  -358,
    1335,  -358,  1335,  -358,  -358,   279,  1209,  -358,  -358,  1335,
    -358,   283,  -358,   287,  1209,   285,  -358,   286,  1048,   281,
     289,  -358,  1067,  -358,  -358,  -358,  -358,  -358,   589,  -358,
     163,   183,  1335,   305,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,   290,   291,  -358,  -358,  -358,  -358,   294,   186,  -358,
     295,    14,  -358,  -358,  -358,   296,   297,  -358,  -358,   300,
    1209,  -358,  -358,  1335,  -358,   302,  -358,  -358,  -358,  -358,
    1228,  -358,  -358,   589,   195,   278,   633,  -358,  -358,  1335,
    2176,  -358,  1335,  1103,  -358,  -358,  -358,  -358,   303,   304,
    -358,  -358,   589,  -358,  -358,  1335,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,   328,   589,   212,  1335,  -358,  -358,  -358,
     298,   226,   589,  -358,   589,  -358,  -358
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   135,   114,   115,   116,   118,   119,   168,   165,   166,
     167,   129,   121,   122,   123,   124,   127,   128,   125,   126,
     120,   130,   131,   139,   140,     0,     0,     0,   169,     0,
     117,   282,     0,   101,   103,   133,     0,   134,   132,   105,
     107,   109,    99,     0,   279,   281,   159,     0,     0,     0,
       0,   174,   191,     0,    97,     0,   110,   113,   173,     0,
     100,   102,   138,     0,   104,   106,   108,     1,   280,     0,
      10,   163,     0,   160,     2,     7,     8,    11,     0,     0,
       0,     9,     0,     0,    38,    40,     0,    39,     0,    41,
      42,    17,     3,     4,     6,    30,    43,     0,    45,    49,
      52,    55,    61,    64,    66,    68,    70,    72,    74,    96,
       0,   147,   204,   149,     0,     0,     0,   192,   190,   189,
       0,     0,    98,     0,     0,   285,     0,   284,     0,     0,
       0,   172,     0,     0,   141,     0,   145,     0,     0,     0,
     155,     0,    34,     0,    31,    32,     0,     0,    37,    43,
      76,    94,     0,     0,     0,    22,    23,    26,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   146,     0,     0,   206,   203,   207,   148,   170,
     164,     0,   193,   188,   175,   111,   113,     0,   231,   112,
       0,     2,     0,     0,     0,     0,   266,   269,     0,     0,
       0,     0,     0,   252,   258,     0,   256,   257,   243,   244,
       0,   254,   245,   246,   247,   248,   286,   283,   201,   186,
     200,     0,   195,   196,     0,     0,    39,   176,     0,     0,
       0,   136,   142,     0,   143,     0,   150,   154,     0,   157,
     162,   156,   161,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    78,     0,     0,     5,     0,    21,     0,    27,
      28,     0,    20,    46,    47,    48,    50,    51,    53,    54,
      58,    59,    60,    56,    57,    62,    63,    65,    67,    69,
      71,    73,     0,   225,     0,     0,     0,    39,   209,     0,
       0,   205,     0,     0,     0,     0,     0,   233,     0,     0,
       0,   237,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,   276,   277,     0,   259,   253,   255,     0,
     198,   206,   199,   185,     0,     0,   187,     0,     0,   177,
     184,     0,    39,   183,     0,   137,   152,     0,   144,     0,
     158,    35,     0,    36,     0,    77,    95,     0,    44,    19,
       0,    18,     0,   226,   208,     0,     0,   210,   216,     0,
     215,     0,   227,     0,     0,    39,   217,     0,     0,     0,
       0,   240,     0,   229,   232,   236,   238,   249,     0,   251,
       0,     0,     0,     0,   271,   274,   278,   194,   197,   202,
     179,     0,     0,   180,   182,   151,   153,     0,     0,    13,
       0,     0,    29,    75,   212,     0,     0,   214,   228,     0,
       0,   218,   224,     0,   223,     0,   241,   239,   230,   235,
       0,   250,   263,     0,     0,     0,     0,   178,   181,     0,
       0,    12,     0,     0,    24,   211,   213,   220,     0,     0,
     221,   234,     0,   265,   267,     0,   272,    16,    14,    15,
      25,   219,   222,   260,     0,     0,     0,   261,   264,   268,
       0,     0,     0,   270,     0,   262,   273
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -358,  -358,  -358,  -358,  -358,  -358,  -358,   -43,  -358,  -358,
    -358,    66,  -358,    -7,   138,   151,   177,   159,   236,   232,
     239,   240,   243,  -358,   -18,   -96,  -358,   -77,   -21,    -9,
     272,  -358,   306,  -358,   -41,  -358,  -358,   292,  -115,    16,
    -358,    64,  -358,   354,  -120,  -358,   -48,  -358,  -358,   -27,
     -56,   -50,  -124,  -119,  -358,    82,  -358,   158,   -99,  -173,
    -114,    61,  -357,  -358,   109,   -46,  -309,  -358,   -24,  -358,
     211,  -306,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,   387,  -358,  -358
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    91,    92,    71,    93,    94,   418,   419,    95,   278,
     279,   149,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   150,   151,   273,   215,   110,    31,
     230,    55,    56,    33,    34,    35,    36,   133,   134,   112,
     245,   246,    37,    72,    73,    38,    39,    40,    41,   120,
      58,    59,   119,   304,   232,   233,   234,   420,   305,   187,
     317,   318,   319,   320,   321,    42,   217,   218,   219,   220,
     221,   222,   478,   482,   223,   462,   224,   328,   474,   329,
     446,   476,   225,    43,    44,    45,   128
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     113,   113,   118,   131,   117,    57,   239,   111,   111,   199,
     231,   152,   311,   186,   397,   113,   399,   136,   242,   252,
     403,    70,   111,    70,   404,   179,    46,   198,    48,   116,
     109,   121,   109,   127,   238,   440,    51,    62,   274,    69,
     113,   139,   357,   122,    51,   274,    70,   111,   125,   140,
     336,   256,   129,    51,   358,   130,   274,   406,   275,   248,
     310,   280,   185,   113,   152,   113,   152,   249,   392,   193,
     111,   192,   111,   274,   132,    51,   393,    51,   371,   135,
      51,   281,   117,    49,   113,   113,   136,   136,   309,   441,
     160,   111,   111,   113,   196,   113,   440,    50,   113,   196,
     111,   198,   111,   302,   227,   111,   180,   146,   247,   183,
     453,   348,   184,   175,    96,   216,    96,   250,   454,   226,
     109,   138,   251,    52,   360,   242,    47,   182,   252,   188,
      53,   342,   243,   185,   463,   335,   117,    63,    53,   347,
     466,   244,   147,   354,   142,   144,   145,   339,   135,   135,
     184,   176,   148,   473,   283,   284,   285,     8,     9,    10,
     166,   167,    52,    96,    52,   479,   177,    52,   311,   339,
      51,    53,   184,   485,    53,   486,    52,   365,   366,   178,
     341,   324,   376,   183,   109,    54,   184,   117,   181,   388,
     395,   192,   113,   383,   136,   315,   189,   316,   312,   111,
     190,   313,    52,   340,    96,   394,   114,   115,   194,   274,
     375,   216,   372,   345,   381,   346,   191,   387,   161,   162,
     163,   276,   356,   198,   277,   109,   282,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,   153,   168,   169,   400,
     401,   170,   411,   164,   165,   412,   135,    52,   117,   274,
     430,   442,   192,   314,    53,   117,   243,   123,    96,   368,
     322,   198,    32,   323,   422,   154,   155,   156,   439,   274,
     425,   443,   450,   426,   451,   131,   173,   174,   429,   341,
     325,   274,   435,   464,   390,   326,   198,   109,   327,   253,
     192,   254,   286,   287,   255,    60,    61,   330,   274,    96,
     480,    64,    65,    66,   331,    32,   113,   288,   289,   171,
     172,   332,   274,   111,   484,   444,   461,   333,   192,   126,
     247,   344,   295,   296,   458,   343,   117,   459,   416,   439,
     192,   109,    96,   349,   198,   290,   291,   292,   293,   294,
     350,   359,   361,   467,   423,   364,   469,   198,   362,   363,
     369,   370,   373,   157,   377,   374,   158,   389,   159,   378,
     391,   402,   398,   409,   445,   465,   410,   413,   414,   405,
     424,    96,   192,   367,   427,   428,   431,   432,   475,   436,
     437,   447,   448,   449,   452,   477,   126,   455,   456,   481,
     126,   457,   113,   460,   471,   472,   483,   468,   298,   111,
     200,   297,   201,    75,    76,    77,   299,    78,   300,    79,
      80,   415,   301,   137,   240,    96,   408,   195,   421,   396,
      68,   338,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     1,    81,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,    26,    82,    27,    83,    28,
      29,    30,   126,     0,    84,     0,     0,    85,    86,    87,
     200,     0,   201,    75,    76,    77,    88,    78,     0,    79,
      80,     0,   124,   213,    89,    90,     0,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,    81,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,    26,    82,    27,    83,    28,
      29,    30,     0,     0,    84,     0,     0,    85,    86,    87,
     200,     0,   201,    75,    76,    77,    88,    78,     0,    79,
      80,     0,   124,   337,    89,    90,     0,   214,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,     0,    78,
       0,    79,    80,     0,     0,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
       0,    78,     0,    79,    80,     0,     0,     0,     0,    81,
       0,     0,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,     0,    82,     0,    83,     0,
       0,    81,     0,     0,    84,     0,     0,    85,    86,    87,
       0,     0,     0,     0,     0,     0,    88,     0,    82,     0,
      83,     0,   124,     0,    89,    90,    84,   214,     0,    85,
      86,    87,     0,     0,     0,     0,     0,     0,    88,     0,
      82,     0,    83,     0,     0,     0,    89,    90,    84,   334,
       0,    85,    86,    87,    74,    75,    76,    77,     0,    78,
      88,    79,    80,     0,     0,     0,     0,     0,    89,    90,
       0,   214,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,     0,    78,     0,    79,    80,     1,    81,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    81,     0,     0,   235,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,    82,    27,
      83,     0,     0,     0,     0,     0,    84,     0,     0,    85,
      86,    87,     0,     0,     0,     0,     0,     0,    88,     0,
       0,     0,     0,    82,     0,    83,    89,    90,     0,     0,
       0,    84,     0,     0,    85,    86,   236,    74,    75,    76,
      77,     0,    78,    88,    79,    80,     0,   237,     0,     0,
       0,    89,    90,     0,     0,     0,    74,    75,    76,    77,
       0,    78,     0,    79,    80,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,   306,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,   351,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,    83,     0,     0,     0,     0,     0,    84,
       0,     0,    85,    86,   307,     0,     0,     0,     0,     0,
      82,    88,    83,     0,     0,   308,     0,     0,    84,    89,
      90,    85,    86,   352,    74,    75,    76,    77,     0,    78,
      88,    79,    80,     0,   353,     0,     0,     0,    89,    90,
       0,     0,     0,    74,    75,    76,    77,     0,    78,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,   379,     0,     0,     0,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,   384,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
      83,     0,     0,     0,     0,     0,    84,     0,     0,    85,
      86,    87,     0,     0,     0,     0,     0,    82,    88,    83,
       0,     0,   380,     0,     0,    84,    89,    90,    85,    86,
     385,    74,    75,    76,    77,     0,    78,    88,    79,    80,
       0,   386,     0,     0,     0,    89,    90,     0,     0,     0,
      74,    75,    76,    77,     0,    78,     0,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,   433,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    74,    75,    76,    77,
       0,    78,     0,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,    83,     0,     0,
       0,     0,     0,    84,     0,     0,    85,    86,    87,     0,
       0,    81,     0,     0,    82,    88,    83,     0,     0,   434,
       0,     0,    84,    89,    90,    85,    86,    87,     0,     0,
       0,     0,     0,     0,    88,     0,     0,   315,     0,   316,
     197,   438,    89,    90,     0,     0,    74,    75,    76,    77,
      82,    78,    83,    79,    80,     0,     0,     0,    84,     0,
       0,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,     0,     0,   315,     0,   316,   197,   470,    89,    90,
       0,    81,    74,    75,    76,    77,     0,    78,     0,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,     0,    78,     0,    79,    80,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
      82,     0,    83,     0,     8,     9,    10,     0,    84,     0,
       0,    85,    86,    87,     0,     0,    81,     0,     0,     0,
      88,     0,     0,   315,     0,   316,   197,     0,    89,    90,
       0,     0,     0,     0,     0,     0,    82,     0,    83,     0,
       0,     0,     0,     0,    84,     0,     0,    85,    86,    87,
       0,     0,     0,     0,     0,    82,    88,    83,     0,     0,
       0,     0,     0,    84,    89,    90,    85,    86,    87,    74,
      75,    76,    77,     0,    78,    88,    79,    80,     0,     0,
       0,   197,     0,    89,    90,     0,     0,     0,    74,    75,
      76,    77,     0,    78,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    74,    75,    76,
      77,     0,    78,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,    74,    75,    76,    77,
       0,    78,     0,    79,    80,     0,     0,     0,     0,     0,
       0,     0,    81,    82,     0,    83,     0,     0,     0,     0,
       0,    84,     0,     0,    85,    86,    87,     0,     0,     0,
       0,    81,    82,    88,    83,     0,     0,     0,     0,   367,
      84,    89,    90,    85,    86,    87,     0,     0,     0,     0,
       0,    82,    88,    83,     0,     0,     0,     0,     0,    84,
      89,    90,    85,    86,    87,     0,    51,     0,     0,     0,
      82,   141,    83,     0,     0,     0,     0,     0,    84,    89,
      90,    85,    86,    87,     0,     0,     0,     0,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,    89,    90,
       1,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,     0,    30,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
     339,   303,     1,   184,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,    29,
      30,   257,   258,   259,   260,   261,     0,     0,     0,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       1,     0,     0,     0,     0,     0,     0,   241,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,   355,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     1,   124,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,   124,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
       0,    30,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,   183,   303,     1,   184,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
       0,    28,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   382,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
       0,    28,    29,    30,     1,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     407,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,     1,    30,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,    26,     0,    27,
       0,    28,     0,    30,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,    27,     0,     0,
      29,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,   417,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,    27,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      48,    49,    52,    59,    52,    32,   130,    48,    49,   123,
     129,    88,   185,   112,   323,    63,   325,    63,   133,   139,
     329,     3,    63,     3,   330,    26,     3,   123,    97,    50,
      48,    96,    50,    57,   130,   392,     3,     3,    96,   103,
      88,    96,    96,   108,     3,    96,     3,    88,    57,   104,
     108,   147,    97,     3,   108,   100,    96,   108,    98,    96,
     184,   157,   112,   111,   141,   113,   143,   104,    96,   119,
     111,   119,   113,    96,   103,     3,   104,     3,   101,    63,
       3,   158,   130,    97,   132,   133,   132,   133,   184,   398,
      97,   132,   133,   141,   121,   143,   453,    97,   146,   126,
     141,   197,   143,   180,   128,   146,   107,    97,   135,    97,
      96,   235,   100,    85,    48,   124,    50,   138,   104,   128,
     138,    95,   104,    90,   104,   240,   103,   111,   248,   113,
      97,   230,    99,   183,   443,   212,   184,   103,    97,   235,
     446,   108,    97,   239,    78,    79,    80,    97,   132,   133,
     100,    84,    86,   462,   161,   162,   163,    45,    46,    47,
      12,    13,    90,    97,    90,   474,    83,    90,   341,    97,
       3,    97,   100,   482,    97,   484,    90,   273,   274,    25,
     230,   202,   306,    97,   202,   108,   100,   235,    98,   313,
      95,   239,   240,   312,   240,   100,    98,   102,    97,   240,
      98,   100,    90,   230,   138,   319,    48,    49,    98,    96,
     306,   220,    99,    96,   310,    98,    96,   313,    90,    91,
      92,    98,   243,   319,     3,   243,     3,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,    88,    14,    15,   326,
     327,    18,   348,    88,    89,   351,   240,    90,   306,    96,
     384,    98,   310,     6,    97,   313,    99,    95,   202,   276,
     108,   367,     0,    99,   370,     9,    10,    11,   392,    96,
     376,    98,    96,   379,    98,   341,    16,    17,   384,   339,
      99,    96,   388,    98,   315,    97,   392,   315,    97,   141,
     348,   143,   164,   165,   146,    33,    34,    97,    96,   243,
      98,    39,    40,    41,     3,    43,   364,   166,   167,    86,
      87,   108,    96,   364,    98,   402,   440,   108,   376,    57,
     357,    96,   173,   174,   430,    98,   384,   433,   359,   453,
     388,   359,   276,   101,   440,   168,   169,   170,   171,   172,
     101,    99,    98,   449,   372,    96,   452,   453,    98,    98,
      98,    96,    98,    97,   101,    98,   100,    98,   102,   101,
       3,    97,    99,     3,    69,    97,   101,   101,   101,   108,
     101,   315,   430,   103,   101,    98,   101,   101,   465,   108,
     101,   101,   101,    99,    99,    67,   124,   101,   101,   476,
     128,   101,   450,   101,   101,   101,   108,   450,   176,   450,
       1,   175,     3,     4,     5,     6,   177,     8,   178,    10,
      11,   357,   179,    69,   132,   359,   344,   121,   367,   320,
      43,   220,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,   220,    -1,    85,    -1,    -1,    88,    89,    90,
       1,    -1,     3,     4,     5,     6,    97,     8,    -1,    10,
      11,    -1,   103,   104,   105,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    -1,    -1,    88,    89,    90,
       1,    -1,     3,     4,     5,     6,    97,     8,    -1,    10,
      11,    -1,   103,   104,   105,   106,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    -1,    79,    -1,
      -1,    38,    -1,    -1,    85,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    77,    -1,
      79,    -1,   103,    -1,   105,   106,    85,   108,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      77,    -1,    79,    -1,    -1,    -1,   105,   106,    85,   108,
      -1,    88,    89,    90,     3,     4,     5,     6,    -1,     8,
      97,    10,    11,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    10,    11,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    38,    -1,    -1,    41,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    77,    -1,    79,   105,   106,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    90,     3,     4,     5,
       6,    -1,     8,    97,    10,    11,    -1,   101,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      77,    97,    79,    -1,    -1,   101,    -1,    -1,    85,   105,
     106,    88,    89,    90,     3,     4,     5,     6,    -1,     8,
      97,    10,    11,    -1,   101,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    77,    97,    79,
      -1,    -1,   101,    -1,    -1,    85,   105,   106,    88,    89,
      90,     3,     4,     5,     6,    -1,     8,    97,    10,    11,
      -1,   101,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    90,    -1,
      -1,    38,    -1,    -1,    77,    97,    79,    -1,    -1,   101,
      -1,    -1,    85,   105,   106,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,   102,
     103,   104,   105,   106,    -1,    -1,     3,     4,     5,     6,
      77,     8,    79,    10,    11,    -1,    -1,    -1,    85,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,   102,   103,   104,   105,   106,
      -1,    38,     3,     4,     5,     6,    -1,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      77,    -1,    79,    -1,    45,    46,    47,    -1,    85,    -1,
      -1,    88,    89,    90,    -1,    -1,    38,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,   102,   103,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    77,    97,    79,    -1,    -1,
      -1,    -1,    -1,    85,   105,   106,    88,    89,    90,     3,
       4,     5,     6,    -1,     8,    97,    10,    11,    -1,    -1,
      -1,   103,    -1,   105,   106,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      -1,    38,    77,    97,    79,    -1,    -1,    -1,    -1,   103,
      85,   105,   106,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    77,    97,    79,    -1,    -1,    -1,    -1,    -1,    85,
     105,   106,    88,    89,    90,    -1,     3,    -1,    -1,    -1,
      77,    97,    79,    -1,    -1,    -1,    -1,    -1,    85,   105,
     106,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      37,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    78,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    37,   100,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    81,
      82,    19,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,   104,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,   104,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    37,   103,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    78,    -1,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,   103,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    37,   100,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    98,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,
      -1,    80,    81,    82,    37,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    78,    -1,    80,    37,    82,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    76,    -1,    78,
      -1,    80,    -1,    82,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    78,    -1,    -1,
      81,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    76,    78,    80,    81,
      82,   138,   139,   142,   143,   144,   145,   151,   154,   155,
     156,   157,   174,   192,   193,   194,     3,   103,    97,    97,
      97,     3,    90,    97,   108,   140,   141,   158,   159,   160,
     139,   139,     3,   103,   139,   139,   139,     0,   193,   103,
       3,   112,   152,   153,     3,     4,     5,     6,     8,    10,
      11,    38,    77,    79,    85,    88,    89,    90,    97,   105,
     106,   110,   111,   113,   114,   117,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     137,   143,   148,   155,   166,   166,   137,   155,   160,   161,
     158,    96,   108,    95,   103,   138,   139,   177,   195,    97,
     100,   159,   103,   146,   147,   148,   174,   152,    95,    96,
     104,    97,   120,    97,   120,   120,    97,    97,   120,   120,
     133,   134,   136,   166,     9,    10,    11,    97,   100,   102,
     122,    90,    91,    92,    88,    89,    12,    13,    14,    15,
      18,    86,    87,    16,    17,    85,    84,    83,    25,    26,
     107,    98,   148,    97,   100,   160,   167,   168,   148,    98,
      98,    96,   155,   160,    98,   141,   158,   103,   134,   169,
       1,     3,    64,    65,    66,    68,    69,    70,    71,    72,
      73,    74,    75,   104,   108,   136,   138,   175,   176,   177,
     178,   179,   180,   183,   185,   191,   138,   177,     3,    98,
     139,   162,   163,   164,   165,    41,    90,   101,   134,   161,
     146,   104,   147,    99,   108,   149,   150,   158,    96,   104,
     137,   104,   153,   166,   166,   166,   134,    19,    20,    21,
      22,    23,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    95,   135,    96,    98,    98,     3,   118,   119,
     134,   136,     3,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   126,   126,   127,   128,   129,
     130,   131,   136,    98,   162,   167,    41,    90,   101,   134,
     161,   168,    97,   100,     6,   100,   102,   169,   170,   171,
     172,   173,   108,    99,   137,    99,    97,    97,   186,   188,
      97,     3,   108,   108,   108,   136,   108,   104,   179,    97,
     158,   160,   167,    98,    96,    96,    98,   134,   161,   101,
     101,    41,    90,   101,   134,   104,   137,    96,   108,    99,
     104,    98,    98,    98,    96,   134,   134,   103,   122,    98,
      96,   101,    99,    98,    98,   134,   161,   101,   101,    41,
     101,   134,    98,   162,    41,    90,   101,   134,   161,    98,
     137,     3,    96,   104,   169,    95,   173,   175,    99,   175,
     136,   136,    97,   175,   180,   108,   108,    63,   164,     3,
     101,   134,   134,   101,   101,   150,   137,    65,   115,   116,
     166,   170,   134,   133,   101,   134,   134,   101,    98,   134,
     161,   101,   101,    41,   101,   134,   108,   101,   104,   169,
     171,   175,    98,    98,   136,    69,   189,   101,   101,    99,
      96,    98,    99,    96,   104,   101,   101,   101,   134,   134,
     101,   169,   184,   175,    98,    97,   180,   134,   116,   134,
     104,   101,   101,   175,   187,   136,   190,    67,   181,   175,
      98,   136,   182,   108,    98,   175,   175
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   110,   110,   110,   110,   111,   111,   111,
     112,   113,   114,   115,   115,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   121,   121,
     121,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   136,   136,   137,   138,   138,   138,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     140,   140,   141,   141,   142,   142,   142,   142,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   144,   144,   144,   145,
     145,   146,   146,   147,   147,   147,   148,   148,   148,   148,
     149,   149,   150,   150,   150,   151,   151,   151,   151,   151,
     152,   152,   153,   153,   154,   155,   155,   155,   156,   156,
     157,   157,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   160,   160,
     160,   160,   161,   161,   162,   162,   163,   163,   164,   164,
     164,   165,   165,   166,   166,   167,   167,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   169,
     169,   169,   170,   170,   170,   170,   171,   172,   172,   173,
     173,   174,   175,   175,   175,   175,   175,   175,   175,   176,
     176,   176,   177,   177,   178,   178,   179,   179,   180,   180,
     181,   182,   181,   184,   183,   183,   186,   187,   185,   188,
     185,   189,   190,   185,   191,   191,   191,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   195
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
       0,     0,     3,     0,     7,     5,     0,     0,     7,     0,
       8,     0,     0,     9,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     4,     3,     1,     2
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
#line 163 "yapl.y"
                              { (yyval.place) = (yyvsp[0].place); }
#line 2090 "yapl.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 166 "yapl.y"
                              { (yyval.place) = (yyvsp[-1].place); }
#line 2096 "yapl.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 171 "yapl.y"
                     {
		int_consts++;
		(yyval.place) = strdup(yytext);
	}
#line 2105 "yapl.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 175 "yapl.y"
                              { (yyval.place) = strdup(yytext); }
#line 2111 "yapl.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 176 "yapl.y"
                               { (yyval.place) = strdup(yytext); }
#line 2117 "yapl.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 184 "yapl.y"
                         { (yyval.place) = strdup(yytext); }
#line 2123 "yapl.tab.c"
    break;

  case 12: /* generic_selection: GENERIC '(' assignment_expression ',' generic_assoc_list ')'  */
#line 188 "yapl.y"
                                                                       { (yyval.place) = (yyvsp[-3].place); }
#line 2129 "yapl.tab.c"
    break;

  case 15: /* generic_association: type_name ':' assignment_expression  */
#line 197 "yapl.y"
                                               { (yyval.place) = (yyvsp[0].place); }
#line 2135 "yapl.tab.c"
    break;

  case 16: /* generic_association: DEFAULT ':' assignment_expression  */
#line 198 "yapl.y"
                                               { (yyval.place) = (yyvsp[0].place); }
#line 2141 "yapl.tab.c"
    break;

  case 17: /* postfix_expression: primary_expression  */
#line 202 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[0].place); }
#line 2147 "yapl.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 203 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-3].place); }
#line 2153 "yapl.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '(' argument_expression_list_opt ')'  */
#line 204 "yapl.y"
                                                                        { (yyval.place) = new_temp(); add_quad("call",(yyvsp[-3].place),"",(yyval.place)); }
#line 2159 "yapl.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 205 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-2].place); }
#line 2165 "yapl.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 206 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-2].place); }
#line 2171 "yapl.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression INC_OP  */
#line 207 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-1].place); }
#line 2177 "yapl.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression DEC_OP  */
#line 208 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-1].place); }
#line 2183 "yapl.tab.c"
    break;

  case 24: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 209 "yapl.y"
                                                                        { (yyval.place) = NULL; }
#line 2189 "yapl.tab.c"
    break;

  case 25: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 210 "yapl.y"
                                                                        { (yyval.place) = NULL; }
#line 2195 "yapl.tab.c"
    break;

  case 26: /* argument_expression_list_opt: %empty  */
#line 214 "yapl.y"
                      { (yyval.place)=NULL; }
#line 2201 "yapl.tab.c"
    break;

  case 27: /* argument_expression_list_opt: argument_expression_list  */
#line 215 "yapl.y"
                                   { (yyval.place) = (yyvsp[0].place); }
#line 2207 "yapl.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 220 "yapl.y"
        {
		(yyval.place) = (yyvsp[0].place);
	}
#line 2215 "yapl.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 224 "yapl.y"
        {
		(yyval.place)=(yyvsp[0].place);
	}
#line 2223 "yapl.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 230 "yapl.y"
                                                { (yyval.place) = (yyvsp[0].place); }
#line 2229 "yapl.tab.c"
    break;

  case 31: /* unary_expression: INC_OP unary_expression  */
#line 231 "yapl.y"
                                                { (yyval.place) = (yyvsp[0].place); }
#line 2235 "yapl.tab.c"
    break;

  case 32: /* unary_expression: DEC_OP unary_expression  */
#line 232 "yapl.y"
                                                { (yyval.place) = (yyvsp[0].place); }
#line 2241 "yapl.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 233 "yapl.y"
                                                { (yyval.place) = (yyvsp[0].place); }
#line 2247 "yapl.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 234 "yapl.y"
                                                { (yyval.place) = NULL; }
#line 2253 "yapl.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 235 "yapl.y"
                                               { (yyval.place) = NULL; }
#line 2259 "yapl.tab.c"
    break;

  case 36: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 236 "yapl.y"
                                               { (yyval.place) = NULL; }
#line 2265 "yapl.tab.c"
    break;

  case 37: /* unary_expression: '-' unary_expression  */
#line 237 "yapl.y"
                               {
		(yyval.place) = new_temp();
		add_quad("minus", (yyvsp[0].place), "", (yyval.place));
	}
#line 2274 "yapl.tab.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 248 "yapl.y"
                                                   { (yyval.place) = (yyvsp[0].place); }
#line 2280 "yapl.tab.c"
    break;

  case 44: /* cast_expression: '(' type_name ')' cast_expression  */
#line 249 "yapl.y"
                                                   { (yyval.place) = (yyvsp[0].place); }
#line 2286 "yapl.tab.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 253 "yapl.y"
                                                            { (yyval.place) = (yyvsp[0].place); }
#line 2292 "yapl.tab.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 254 "yapl.y"
                                                            {
		(yyval.place) = new_temp(); add_quad("*",  (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2299 "yapl.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 256 "yapl.y"
                                                            {
		(yyval.place) = new_temp(); add_quad("/",  (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2306 "yapl.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 258 "yapl.y"
                                                            {
		(yyval.place) = new_temp(); add_quad("%",  (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2313 "yapl.tab.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 263 "yapl.y"
                                                                 { (yyval.place) = (yyvsp[0].place); }
#line 2319 "yapl.tab.c"
    break;

  case 50: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 264 "yapl.y"
                                                                 {
		(yyval.place) = new_temp(); add_quad("+", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2326 "yapl.tab.c"
    break;

  case 51: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 266 "yapl.y"
                                                                 {
		(yyval.place) = new_temp(); add_quad("-", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2333 "yapl.tab.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 271 "yapl.y"
                                                           { (yyval.place) = (yyvsp[0].place); }
#line 2339 "yapl.tab.c"
    break;

  case 53: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 272 "yapl.y"
                                                           {
		(yyval.place) = new_temp(); add_quad("<<", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2346 "yapl.tab.c"
    break;

  case 54: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 274 "yapl.y"
                                                           {
		(yyval.place) = new_temp(); add_quad(">>", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2353 "yapl.tab.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 279 "yapl.y"
                                                          { (yyval.place) = (yyvsp[0].place); }
#line 2359 "yapl.tab.c"
    break;

  case 56: /* relational_expression: relational_expression '<' shift_expression  */
#line 280 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad("<",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2366 "yapl.tab.c"
    break;

  case 57: /* relational_expression: relational_expression '>' shift_expression  */
#line 282 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad(">",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2373 "yapl.tab.c"
    break;

  case 58: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 284 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad("<=",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2380 "yapl.tab.c"
    break;

  case 59: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 286 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad(">=",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2387 "yapl.tab.c"
    break;

  case 60: /* relational_expression: relational_expression TH_OP shift_expression  */
#line 288 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad("<=>",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2394 "yapl.tab.c"
    break;

  case 61: /* equality_expression: relational_expression  */
#line 293 "yapl.y"
                                                              { (yyval.place) = (yyvsp[0].place); }
#line 2400 "yapl.tab.c"
    break;

  case 62: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 294 "yapl.y"
                                                              {
		(yyval.place) = new_temp(); add_quad("==", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2407 "yapl.tab.c"
    break;

  case 63: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 296 "yapl.y"
                                                              {
		(yyval.place) = new_temp(); add_quad("!=", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2414 "yapl.tab.c"
    break;

  case 64: /* and_expression: equality_expression  */
#line 301 "yapl.y"
                                                       { (yyval.place) = (yyvsp[0].place); }
#line 2420 "yapl.tab.c"
    break;

  case 65: /* and_expression: and_expression '&' equality_expression  */
#line 302 "yapl.y"
                                                       {
		(yyval.place) = new_temp(); add_quad("&", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2427 "yapl.tab.c"
    break;

  case 66: /* exclusive_or_expression: and_expression  */
#line 307 "yapl.y"
                                                       { (yyval.place) = (yyvsp[0].place); }
#line 2433 "yapl.tab.c"
    break;

  case 67: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 308 "yapl.y"
                                                       {
		(yyval.place) = new_temp(); add_quad("^", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2440 "yapl.tab.c"
    break;

  case 68: /* inclusive_or_expression: exclusive_or_expression  */
#line 313 "yapl.y"
                                                               { (yyval.place) = (yyvsp[0].place); }
#line 2446 "yapl.tab.c"
    break;

  case 69: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 314 "yapl.y"
                                                               {
		(yyval.place) = new_temp(); add_quad("|", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2453 "yapl.tab.c"
    break;

  case 70: /* logical_and_expression: inclusive_or_expression  */
#line 319 "yapl.y"
                                                                   { (yyval.place) = (yyvsp[0].place); }
#line 2459 "yapl.tab.c"
    break;

  case 71: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 320 "yapl.y"
                                                                   {
		(yyval.place) = new_temp(); add_quad("&&", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2466 "yapl.tab.c"
    break;

  case 72: /* logical_or_expression: logical_and_expression  */
#line 325 "yapl.y"
                                                                { (yyval.place) = (yyvsp[0].place); }
#line 2472 "yapl.tab.c"
    break;

  case 73: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 326 "yapl.y"
                                                                {
		(yyval.place) = new_temp(); add_quad("||", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2479 "yapl.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression  */
#line 331 "yapl.y"
                                { (yyval.place) = (yyvsp[0].place); }
#line 2485 "yapl.tab.c"
    break;

  case 75: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 332 "yapl.y"
                                                                          { (yyval.place) = (yyvsp[-4].place); }
#line 2491 "yapl.tab.c"
    break;

  case 76: /* assignment_expression: conditional_expression  */
#line 336 "yapl.y"
                                 {
		(yyval.place) = (yyvsp[0].place);
		sprintf(derivations[dtop++], "assignment_expression -> conditional_expression");
	}
#line 2500 "yapl.tab.c"
    break;

  case 77: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 340 "yapl.y"
                                                                     {
		if (strcmp((yyvsp[-1].op), "=") == 0) {
			add_quad("=", (yyvsp[0].place), "", (yyvsp[-2].place));
		} else {
			char *tmp = new_temp();
			add_quad((yyvsp[-1].op), (yyvsp[-2].place), (yyvsp[0].place), tmp);
			add_quad("=", tmp, "", (yyvsp[-2].place));
		}
		(yyval.place) = (yyvsp[-2].place);
		sprintf(derivations[dtop++], "assignment_expression -> unary_expression assignment_operator assignment_expression");
	}
#line 2516 "yapl.tab.c"
    break;

  case 78: /* assignment_operator: '='  */
#line 354 "yapl.y"
                       { (yyval.op) = strdup("=");  }
#line 2522 "yapl.tab.c"
    break;

  case 79: /* assignment_operator: MUL_ASSIGN  */
#line 355 "yapl.y"
                       { (yyval.op) = strdup("*");  }
#line 2528 "yapl.tab.c"
    break;

  case 80: /* assignment_operator: DIV_ASSIGN  */
#line 356 "yapl.y"
                       { (yyval.op) = strdup("/");  }
#line 2534 "yapl.tab.c"
    break;

  case 81: /* assignment_operator: MOD_ASSIGN  */
#line 357 "yapl.y"
                       { (yyval.op) = strdup("%");  }
#line 2540 "yapl.tab.c"
    break;

  case 82: /* assignment_operator: ADD_ASSIGN  */
#line 358 "yapl.y"
                       { (yyval.op) = strdup("+");  }
#line 2546 "yapl.tab.c"
    break;

  case 83: /* assignment_operator: SUB_ASSIGN  */
#line 359 "yapl.y"
                       { (yyval.op) = strdup("-");  }
#line 2552 "yapl.tab.c"
    break;

  case 84: /* assignment_operator: LEFT_ASSIGN  */
#line 360 "yapl.y"
                       { (yyval.op) = strdup("<<"); }
#line 2558 "yapl.tab.c"
    break;

  case 85: /* assignment_operator: RIGHT_ASSIGN  */
#line 361 "yapl.y"
                       { (yyval.op) = strdup(">>"); }
#line 2564 "yapl.tab.c"
    break;

  case 86: /* assignment_operator: AND_ASSIGN  */
#line 362 "yapl.y"
                       { (yyval.op) = strdup("&");  }
#line 2570 "yapl.tab.c"
    break;

  case 87: /* assignment_operator: XOR_ASSIGN  */
#line 363 "yapl.y"
                       { (yyval.op) = strdup("^");  }
#line 2576 "yapl.tab.c"
    break;

  case 88: /* assignment_operator: OR_ASSIGN  */
#line 364 "yapl.y"
                       { (yyval.op) = strdup("|");  }
#line 2582 "yapl.tab.c"
    break;

  case 89: /* assignment_operator: PEQ_OP  */
#line 365 "yapl.y"
                       { (yyval.op) = strdup("+");  }
#line 2588 "yapl.tab.c"
    break;

  case 90: /* assignment_operator: MEQ_OP  */
#line 366 "yapl.y"
                       { (yyval.op) = strdup("-");  }
#line 2594 "yapl.tab.c"
    break;

  case 91: /* assignment_operator: STREQ_OP  */
#line 367 "yapl.y"
                       { (yyval.op) = strdup("*");  }
#line 2600 "yapl.tab.c"
    break;

  case 92: /* assignment_operator: DEQ_OP  */
#line 368 "yapl.y"
                       { (yyval.op) = strdup("/");  }
#line 2606 "yapl.tab.c"
    break;

  case 93: /* assignment_operator: MODEQ_OP  */
#line 369 "yapl.y"
                       { (yyval.op) = strdup("%");  }
#line 2612 "yapl.tab.c"
    break;

  case 94: /* expression: assignment_expression  */
#line 373 "yapl.y"
                                {
		(yyval.place) = (yyvsp[0].place);
		sprintf(derivations[dtop++], "expression -> assignment_expression");
	}
#line 2621 "yapl.tab.c"
    break;

  case 95: /* expression: expression ',' assignment_expression  */
#line 377 "yapl.y"
                                               {
		(yyval.place) = (yyvsp[0].place);
		sprintf(derivations[dtop++], "expression -> expression , assignment_expression");
	}
#line 2630 "yapl.tab.c"
    break;

  case 97: /* declaration: declaration_specifiers ';'  */
#line 388 "yapl.y"
                                     {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers ;");
	}
#line 2638 "yapl.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 391 "yapl.y"
                                                          {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers init_declarator_list ;");
	}
#line 2646 "yapl.tab.c"
    break;

  case 99: /* declaration: static_assert_declaration  */
#line 394 "yapl.y"
                                    {
		sprintf(derivations[dtop++], "declaration -> static_assert_declaration");
	}
#line 2654 "yapl.tab.c"
    break;

  case 172: /* declarator: pointer direct_declarator  */
#line 510 "yapl.y"
                                    { pointer_decls++; }
#line 2660 "yapl.tab.c"
    break;

  case 242: /* statement: error ';'  */
#line 631 "yapl.y"
                    {
		printf("Recovered from error at line %d near token '%s'\n", line_no, yytext);
		yyerrok;
	}
#line 2669 "yapl.tab.c"
    break;

  case 243: /* statement: labeled_statement  */
#line 635 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> labeled_statement");   }
#line 2675 "yapl.tab.c"
    break;

  case 244: /* statement: compound_statement  */
#line 636 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> compound_statement");  }
#line 2681 "yapl.tab.c"
    break;

  case 245: /* statement: expression_statement  */
#line 637 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> expression_statement");}
#line 2687 "yapl.tab.c"
    break;

  case 246: /* statement: selection_statement  */
#line 638 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> selection_statement"); }
#line 2693 "yapl.tab.c"
    break;

  case 247: /* statement: iteration_statement  */
#line 639 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> iteration_statement"); }
#line 2699 "yapl.tab.c"
    break;

  case 248: /* statement: jump_statement  */
#line 640 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> jump_statement");      }
#line 2705 "yapl.tab.c"
    break;

  case 252: /* compound_statement: '{' '}'  */
#line 650 "yapl.y"
                  {
		sprintf(derivations[dtop++], "compound_statement -> { }");
	}
#line 2713 "yapl.tab.c"
    break;

  case 253: /* compound_statement: '{' block_item_list '}'  */
#line 653 "yapl.y"
                                  {
		sprintf(derivations[dtop++], "compound_statement -> { block_item_list }");
	}
#line 2721 "yapl.tab.c"
    break;

  case 254: /* block_item_list: block_item  */
#line 659 "yapl.y"
                                      { sprintf(derivations[dtop++], "block_item_list -> block_item"); }
#line 2727 "yapl.tab.c"
    break;

  case 255: /* block_item_list: block_item_list block_item  */
#line 660 "yapl.y"
                                      { sprintf(derivations[dtop++], "block_item_list -> block_item_list block_item"); }
#line 2733 "yapl.tab.c"
    break;

  case 256: /* block_item: declaration  */
#line 664 "yapl.y"
                      { sprintf(derivations[dtop++], "block_item -> declaration"); }
#line 2739 "yapl.tab.c"
    break;

  case 257: /* block_item: statement  */
#line 665 "yapl.y"
                      { sprintf(derivations[dtop++], "block_item -> statement");   }
#line 2745 "yapl.tab.c"
    break;

  case 258: /* expression_statement: ';'  */
#line 669 "yapl.y"
          {
        (yyval.place) = NULL;
        sprintf(derivations[dtop++], "expression_statement -> ;");
    }
#line 2754 "yapl.tab.c"
    break;

  case 259: /* expression_statement: expression ';'  */
#line 673 "yapl.y"
                     {
        (yyval.place) = (yyvsp[-1].place);
        sprintf(derivations[dtop++], "expression_statement -> expression ;");
    }
#line 2763 "yapl.tab.c"
    break;

  case 260: /* else_part: %empty  */
#line 681 "yapl.y"
      {
          char *lf = pop_false();
          add_quad("label", "", "", lf);
          ifs_wo_else++;
		  if(ladder_len > max) max=ladder_len;
		  ladder_len=0;
      }
#line 2775 "yapl.tab.c"
    break;

  case 261: /* $@1: %empty  */
#line 689 "yapl.y"
      {
          char *le = new_label();
          char *lf = pop_false();
          add_quad("goto",  "", "", le);
          add_quad("label", "", "", lf);
          push_end(le);
		  ladder_len++;
		  if(ladder_len > max) max= ladder_len;
      }
#line 2789 "yapl.tab.c"
    break;

  case 262: /* else_part: ELSE $@1 statement  */
#line 699 "yapl.y"
      {
          char *le = pop_end();
          if (le) add_quad("label", "", "", le);
      }
#line 2798 "yapl.tab.c"
    break;

  case 263: /* $@2: %empty  */
#line 707 "yapl.y"
      {
          char *lf = new_label();
          if ((yyvsp[-1].place)) add_quad("iffalse", (yyvsp[-1].place), "", lf);
          push_false(lf);
		  if_depth++;
      }
#line 2809 "yapl.tab.c"
    break;

  case 264: /* selection_statement: IF '(' expression ')' $@2 statement else_part  */
#line 714 "yapl.y"
      {
          if_depth--;
		  (yyval.place) = NULL;
      }
#line 2818 "yapl.tab.c"
    break;

  case 265: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 719 "yapl.y"
          {
		/* Switch: just parse and pass through, no quad needed for basic support */
		(yyval.place)=NULL;
	  }
#line 2827 "yapl.tab.c"
    break;

  case 266: /* $@3: %empty  */
#line 727 "yapl.y"
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
#line 2837 "yapl.tab.c"
    break;

  case 267: /* $@4: %empty  */
#line 733 "yapl.y"
      {
          char *Lend = new_label();
          add_quad("iffalse", (yyvsp[-1].place), "", Lend);
          push_end(Lend);
      }
#line 2847 "yapl.tab.c"
    break;

  case 268: /* iteration_statement: WHILE $@3 '(' expression ')' $@4 statement  */
#line 739 "yapl.y"
      {
          char *Lend   = pop_end();
          char *Lstart = pop_false();
          add_quad("goto",  "", "", Lstart);
          add_quad("label", "", "", Lend);
          (yyval.place) = NULL;
      }
#line 2859 "yapl.tab.c"
    break;

  case 269: /* $@5: %empty  */
#line 748 "yapl.y"
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
#line 2869 "yapl.tab.c"
    break;

  case 270: /* iteration_statement: DO $@5 statement WHILE '(' expression ')' ';'  */
#line 755 "yapl.y"
      {
          char *Lstart = pop_false();
          add_quad("ifgoto", (yyvsp[-2].place), "", Lstart);
          (yyval.place) = NULL;
      }
#line 2879 "yapl.tab.c"
    break;

  case 271: /* $@6: %empty  */
#line 762 "yapl.y"
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
#line 2889 "yapl.tab.c"
    break;

  case 272: /* $@7: %empty  */
#line 768 "yapl.y"
      {
          char *Lend = new_label();
          add_quad("iffalse", (yyvsp[0].place), "", Lend);
          push_end(Lend);
      }
#line 2899 "yapl.tab.c"
    break;

  case 273: /* iteration_statement: FOR '(' expression_statement $@6 expression_statement $@7 expression ')' statement  */
#line 775 "yapl.y"
      {
          add_quad("eval", (yyvsp[-2].place), "", "");
          char *Lend   = pop_end();
          char *Lstart = pop_false();
          add_quad("goto",  "", "", Lstart);
          add_quad("label", "", "", Lend);
          (yyval.place) = NULL;
      }
#line 2912 "yapl.tab.c"
    break;

  case 279: /* translation_unit: external_declaration  */
#line 794 "yapl.y"
                               {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> external_declaration");
	}
#line 2921 "yapl.tab.c"
    break;

  case 280: /* translation_unit: translation_unit external_declaration  */
#line 798 "yapl.y"
                                                {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> translation_unit external_declaration");
	}
#line 2930 "yapl.tab.c"
    break;

  case 281: /* external_declaration: function_definition  */
#line 805 "yapl.y"
                              { func_definitions++; }
#line 2936 "yapl.tab.c"
    break;

  case 283: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 810 "yapl.y"
                                                                                {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator declaration_list compound_statement");
	}
#line 2944 "yapl.tab.c"
    break;

  case 284: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 813 "yapl.y"
                                                               {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator compound_statement");
	}
#line 2952 "yapl.tab.c"
    break;


#line 2956 "yapl.tab.c"

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

#line 823 "yapl.y"


/* =====================================================================
   C CODE SECTION
   ===================================================================== */

char buff[2048];
int yylex(void);
int mode = -1;

void export_parsing_table_to_csv() {
    FILE *fp = fopen("parsing_table.csv", "w");
    if (fp == NULL) { printf("Error opening file for CSV export!\n"); return; }

    fprintf(fp, "State");
    for (int i = 0; i < NUM_TERMS; i++)     fprintf(fp, ",%s", terminals[i]);
    for (int i = 0; i < NUM_NON_TERMS; i++) fprintf(fp, ",%s", non_terminals[i]);
    fprintf(fp, "\n");

    for (int i = 0; i < NUM_STATES; i++) {
        fprintf(fp, "%d", i);
        for (int j = 0; j < (NUM_TERMS + NUM_NON_TERMS); j++) {
            if (parsing_table[i][j] && strlen(parsing_table[i][j]) > 0)
                fprintf(fp, ",%s", parsing_table[i][j]);
            else
                fprintf(fp, ",-");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Successfully exported LALR(1) table to 'parsing_table.csv'\n");
}

/* ---- pretty-print helpers ---- */
#define LINE "================================================================="
#define DASH "-----------------------------------------------------------------"

void print_source(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { printf("(could not reopen source for display)\n"); return; }
    printf("\n%s\n", LINE);
    printf("  SOURCE PROGRAM : %s\n", filename);
    printf("%s\n", LINE);
    char buf[512];
    int ln = 1;
    while (fgets(buf, sizeof(buf), fp))
        printf("%4d | %s", ln++, buf);
    if (buf[strlen(buf)-1] != '\n') printf("\n");
    fclose(fp);
    printf("%s\n\n", LINE);
}

void print_quad_table() {
    printf("\n%s\n", LINE);
    printf("          INTERMEDIATE CODE  —  3-Address Code (Quadruples)\n");
    printf("%s\n", LINE);
    printf("%-5s  %-10s  %-14s  %-14s  %-14s\n",
           "No.", "Op", "Arg1", "Arg2", "Result");
    printf("%s\n", DASH);

    for (int i = 0; i < quad_index; i++) {
        const char *a1 = quads[i].arg1[0]   ? quads[i].arg1   : "-";
        const char *a2 = quads[i].arg2[0]   ? quads[i].arg2   : "-";
        const char *r  = quads[i].result[0] ? quads[i].result : "-";
        printf("%-5d  %-10s  %-14s  %-14s  %-14s\n",
               i, quads[i].op, a1, a2, r);
    }

    printf("%s\n", LINE);
    printf("  Total quadruples generated : %d\n", quad_index);
    printf("%s\n\n", LINE);
}

/* ---- main ---- */
int main(int argc, char **argv)
{
    extern FILE *yyin;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        exit(1);
    }

    /* Print source first */
    print_source(argv[1]);

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
        exit(1);
    }

    do { yyparse(); } while (!feof(yyin));
    fclose(yyin);

    /* Parsing stats */
    printf("%s\n", LINE);
    printf("  PARSING RESULTS\n");
    printf("%s\n", LINE);
    printf("  ***parsing successful***\n");
    printf("  #global_declarations  = %d\n", global_declarations);
    printf("  #function_definitions = %d\n", func_definitions);
    printf("  #integer_constants    = %d\n", int_consts);
    printf("  #pointer_declarations = %d\n", pointer_decls);
    printf("  #ifs_without_else     = %d\n", ifs_wo_else);
    printf("  if-else max-depth     = %d\n", (max < 0) ? 0 : max);
    printf("%s\n\n", LINE);

    /* Export parsing table */
    export_parsing_table_to_csv();

    /* Quadruple table — Part 3 requirement */
    print_quad_table();

    return 0;
}

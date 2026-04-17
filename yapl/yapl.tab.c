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

/*Adding switch cases:*/
char *switch_expr_stack[STACK_SIZE];
int switch_top = 0;

void push_switch_expr(char *e) {
    switch_expr_stack[switch_top++] = e;
}
char* pop_switch_expr() {
    return switch_expr_stack[--switch_top];
}
char* top_switch_expr() {
    return switch_expr_stack[switch_top - 1];
}

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
int  for_inc_start = 0;
quad for_inc_buf[200];
int  for_inc_cnt   = 0;
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

#line 190 "yapl.tab.c"

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
  YYSYMBOL_185_3 = 185,                    /* $@3  */
  YYSYMBOL_iteration_statement = 186,      /* iteration_statement  */
  YYSYMBOL_187_4 = 187,                    /* $@4  */
  YYSYMBOL_188_5 = 188,                    /* $@5  */
  YYSYMBOL_189_6 = 189,                    /* $@6  */
  YYSYMBOL_190_7 = 190,                    /* $@7  */
  YYSYMBOL_191_8 = 191,                    /* $@8  */
  YYSYMBOL_192_9 = 192,                    /* $@9  */
  YYSYMBOL_jump_statement = 193,           /* jump_statement  */
  YYSYMBOL_translation_unit = 194,         /* translation_unit  */
  YYSYMBOL_external_declaration = 195,     /* external_declaration  */
  YYSYMBOL_function_definition = 196,      /* function_definition  */
  YYSYMBOL_declaration_list = 197,         /* declaration_list  */
  YYSYMBOL_switch_body = 198,              /* switch_body  */
  YYSYMBOL_case_list = 199,                /* case_list  */
  YYSYMBOL_case_statement = 200,           /* case_statement  */
  YYSYMBOL_201_10 = 201,                   /* $@10  */
  YYSYMBOL_default_statement = 202,        /* default_statement  */
  YYSYMBOL_203_11 = 203                    /* $@11  */
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
#define YYLAST   2270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  295
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  498

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
       0,   183,   183,   184,   185,   186,   187,   191,   195,   196,
     200,   204,   208,   212,   213,   217,   218,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   234,   235,   239,   243,
     250,   251,   252,   253,   254,   255,   256,   257,   264,   264,
     264,   264,   264,   268,   269,   273,   274,   276,   278,   283,
     284,   286,   291,   292,   294,   299,   300,   302,   304,   306,
     308,   313,   314,   316,   321,   322,   327,   328,   333,   334,
     339,   340,   345,   346,   351,   352,   356,   360,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   393,   397,   404,   408,   411,   414,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     433,   434,   438,   439,   443,   443,   443,   443,   443,   443,
     447,   447,   447,   447,   447,   447,   447,   448,   448,   448,
     448,   448,   449,   450,   451,   452,   456,   457,   458,   462,
     462,   466,   467,   471,   472,   473,   477,   478,   479,   480,
     484,   485,   489,   490,   491,   495,   496,   497,   498,   499,
     503,   504,   508,   509,   513,   517,   517,   517,   521,   521,
     525,   526,   530,   531,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   552,   553,
     554,   555,   559,   560,   564,   565,   569,   570,   574,   575,
     576,   580,   581,   585,   586,   590,   591,   592,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   620,
     621,   622,   626,   627,   628,   629,   633,   637,   638,   642,
     643,   647,   651,   655,   656,   657,   658,   659,   660,   664,
     668,   671,   677,   678,   682,   683,   687,   691,   698,   707,
     706,   725,   724,   737,   736,   766,   772,   765,   787,   786,
     801,   807,   816,   800,   842,   843,   844,   849,   850,   854,
     858,   865,   866,   870,   873,   879,   880,   909,   910,   911,
     915,   916,   921,   920,   952,   951
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
  "$@3", "iteration_statement", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", "switch_body", "case_list",
  "case_statement", "$@10", "default_statement", "$@11", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-361)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1993,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,    62,   -26,   -16,  -361,    -9,
    -361,  -361,    48,  2083,  2083,  -361,    64,  -361,  -361,  2083,
    2083,  2083,  -361,  1600,  -361,  -361,    -3,   101,   753,  2192,
    1367,  -361,   185,    79,  -361,   -75,  -361,  1741,   -73,    94,
    -361,  -361,    68,  2121,  -361,  -361,  -361,  -361,  -361,   101,
    -361,    82,   -88,  -361,  -361,  -361,  -361,  -361,  1386,  1405,
    1405,  -361,    93,    95,  -361,  -361,  1405,  -361,   753,  -361,
    -361,  -361,  -361,  -361,  -361,   214,  -361,  1367,  -361,   154,
     174,   275,   204,   277,   126,   132,   155,   202,    -6,  -361,
     158,  2192,   -45,  2192,   201,   208,   146,  -361,  -361,   185,
     215,    79,  -361,  1260,   441,  -361,    48,  -361,  1806,  1537,
     778,   -73,  2121,  1638,  -361,    58,  -361,   -36,  1367,    39,
    -361,   753,  -361,   753,  -361,  -361,  2192,  1367,  -361,   338,
    -361,  -361,   -50,   217,   249,  -361,  -361,  1367,  1367,   309,
    -361,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,
    1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,
    1367,  -361,  -361,  1871,   866,    89,  -361,   117,  -361,  -361,
    -361,   311,  -361,  -361,  -361,  -361,   224,  1205,  -361,  -361,
     216,   226,   232,   234,  -361,  -361,   235,   320,   220,   225,
     643,  -361,  -361,   -74,  -361,  -361,  -361,  -361,   531,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,    84,   236,
     240,  -361,   152,  1241,   239,  -361,   242,   885,  1675,  -361,
    -361,  1367,  -361,   -55,  -361,   238,    55,  -361,  -361,  -361,
    -361,   243,   246,   247,   251,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  1367,  1367,  -361,  1348,  -361,   253,   256,  -361,    72,
    -361,  -361,  -361,  -361,   154,   154,   174,   174,   275,   275,
     275,   275,   275,   204,   204,   277,   126,   132,   155,   202,
     144,  -361,   255,   257,  1241,   248,  -361,   261,   973,   117,
    1933,   992,   258,  1367,   351,  -361,   102,  1260,   110,  -361,
    -361,   621,  1367,  1367,   266,   621,   665,   268,  -361,  -361,
    -361,   -49,  -361,  -361,  -361,  1475,  -361,    75,  -361,  -361,
    2039,   374,  -361,   278,  1241,  -361,  -361,  1367,   279,  -361,
     280,  -361,  -361,   179,  -361,  1367,  -361,   281,   281,  -361,
    2158,  -361,  -361,  1205,  -361,  -361,  1367,  -361,  1367,  -361,
    -361,   282,  1241,  -361,  -361,  1367,  -361,   284,  -361,   288,
    1241,   286,  -361,   287,  1080,   274,   290,  -361,  1099,  -361,
    -361,  -361,  -361,  -361,   153,   163,  1367,   323,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,   292,   294,  -361,  -361,  -361,
    -361,   297,   175,  -361,   299,   125,  -361,  -361,  -361,   298,
     301,  -361,  -361,   303,  1241,  -361,  -361,  1367,  -361,   306,
    -361,  -361,  -361,  -361,  1260,  -361,  -361,   183,   313,   665,
    -361,  -361,  1367,  2158,  -361,  1367,  1135,  -361,  -361,  -361,
    -361,   307,   312,  -361,  -361,   621,   314,  -361,  1367,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,   333,   231,   621,   184,
    1367,  -361,  -361,  1367,   315,   308,   231,  -361,  -361,  -361,
     310,   188,   621,   317,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,   621,   621,   621,  -361,  -361,  -361
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
       0,     2,     0,     0,   265,   268,     0,     0,     0,     0,
       0,   250,   256,     0,   254,   255,   243,   244,     0,   252,
     245,   246,   247,   248,   286,   283,   201,   186,   200,     0,
     195,   196,     0,     0,    39,   176,     0,     0,     0,   136,
     142,     0,   143,     0,   150,   154,     0,   157,   162,   156,
     161,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      78,     0,     0,     5,     0,    21,     0,    27,    28,     0,
      20,    46,    47,    48,    50,    51,    53,    54,    58,    59,
      60,    56,    57,    62,    63,    65,    67,    69,    71,    73,
       0,   225,     0,     0,     0,    39,   209,     0,     0,   205,
       0,     0,     0,     0,     0,   233,     0,     0,     0,   237,
     242,     0,     0,     0,     0,     0,     0,     0,   275,   276,
     277,     0,   257,   251,   253,     0,   198,   206,   199,   185,
       0,     0,   187,     0,     0,   177,   184,     0,    39,   183,
       0,   137,   152,     0,   144,     0,   158,    35,     0,    36,
       0,    77,    95,     0,    44,    19,     0,    18,     0,   226,
     208,     0,     0,   210,   216,     0,   215,     0,   227,     0,
       0,    39,   217,     0,     0,     0,     0,   240,     0,   229,
     232,   236,   238,   249,     0,     0,     0,     0,   270,   274,
     278,   194,   197,   202,   179,     0,     0,   180,   182,   151,
     153,     0,     0,    13,     0,     0,    29,    75,   212,     0,
       0,   214,   228,     0,     0,   218,   224,     0,   223,     0,
     241,   239,   230,   235,     0,   261,   263,     0,     0,     0,
     178,   181,     0,     0,    12,     0,     0,    24,   211,   213,
     220,     0,     0,   221,   234,     0,     0,   266,     0,   271,
      16,    14,    15,    25,   219,   222,   258,     0,     0,     0,
       0,   259,   262,     0,     0,     0,   288,   290,   289,   267,
       0,     0,     0,     0,   294,   264,   291,   287,   269,   272,
     260,   292,     0,     0,     0,   295,   273,   293
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -361,  -361,  -361,  -361,  -361,  -361,  -361,   -23,  -361,  -361,
    -361,   -48,  -361,   -27,   133,   134,    65,   131,   254,   245,
     259,   244,   252,  -361,   -47,    31,  -361,   -69,   -46,   -22,
      23,  -361,   302,  -361,   -38,  -361,  -361,   296,   -89,    47,
    -361,    71,  -361,   361,  -102,  -361,   -34,  -361,  -361,    11,
     -54,   -43,   -91,  -123,  -361,    92,  -361,   114,   -95,  -173,
    -116,    74,  -360,  -361,   116,    20,  -285,  -361,   -44,  -361,
     221,  -300,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,   392,  -361,  -361,  -361,
    -361,   -35,  -361,   -33,  -361
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    91,    92,    71,    93,    94,   412,   413,    95,   276,
     277,   149,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   150,   151,   271,   213,   110,    31,
     228,    55,    56,    33,    34,    35,    36,   133,   134,   112,
     243,   244,    37,    72,    73,    38,    39,    40,    41,   120,
      58,    59,   119,   302,   230,   231,   232,   414,   303,   187,
     315,   316,   317,   318,   319,    42,   215,   216,   217,   218,
     219,   220,   472,   482,   221,   455,   456,   222,   324,   468,
     325,   439,   470,   493,   223,    43,    44,    45,   128,   475,
     476,   477,   494,   478,   492
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,   109,    96,   109,   116,   131,   229,   199,   139,   118,
     111,   111,   309,   127,   113,   113,   140,   186,   117,   152,
     179,   121,   272,    32,   129,   111,   398,   130,   434,   113,
     142,   144,   145,   122,   332,   125,   393,   250,   148,   237,
     397,   353,    70,    57,   240,    52,   272,   272,   273,    96,
     111,    51,   183,   354,   113,   184,    60,    61,    70,   400,
     246,    51,    64,    65,    66,    46,    32,    62,   247,   185,
     160,    48,   152,   111,   152,   111,   193,   113,    51,   113,
     126,    49,    51,   136,   225,   192,   434,    51,    50,   279,
      96,   109,   248,   308,   111,   111,   117,    51,   113,   113,
      69,   180,   214,   111,    70,   111,   224,   113,   111,   113,
     135,   300,   113,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,   196,   338,   281,   282,   283,   196,    52,   459,
     185,   331,   344,   249,   250,    53,   245,   126,    52,   240,
     117,   126,   136,   136,   198,    53,    54,   241,   182,   356,
     188,   236,   114,   115,   309,    47,   242,    63,   272,    52,
     466,   132,   335,   367,    52,   184,    53,   138,   254,   135,
     135,   335,    51,   479,   184,   337,   183,   379,   278,   184,
     146,    53,   147,    96,   109,   352,   214,   490,   388,   117,
     111,   390,   153,   192,   113,   391,   389,   495,   496,   497,
     313,   175,   314,   372,   310,   307,   176,   311,   168,   169,
     384,   446,   170,   154,   155,   156,    96,   178,   198,   447,
       8,     9,    10,   288,   289,   290,   291,   292,   177,   336,
     272,   126,   191,   368,   161,   162,   163,   364,   341,   272,
     342,   435,   275,   394,   395,   251,   181,   252,   136,   272,
     253,   436,   164,   165,   343,    96,   109,   386,   350,    52,
     117,   443,   433,   444,   192,    52,    53,   117,   241,   272,
     272,   457,   480,   131,   272,   135,   489,   166,   167,   424,
     171,   172,   337,   173,   174,   473,   474,   284,   285,   189,
     286,   287,   361,   362,   293,   294,   190,    96,   109,   410,
     192,   157,   280,   194,   158,   274,   159,   312,   454,   123,
      96,   417,   111,   327,   320,   321,   113,   437,   328,   322,
     433,   323,   326,   329,   339,   371,   340,   355,   192,   377,
     345,   357,   383,   346,   358,   359,   117,   360,   198,   373,
     192,   365,   366,   369,   387,   370,   385,   255,   256,   257,
     258,   259,   374,   396,   245,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   405,   399,   403,   406,   404,
     407,   408,   430,   418,   363,   421,   422,   425,   426,   469,
     192,   431,   438,   440,   198,   441,   442,   416,   445,   448,
     471,   481,   449,   419,   450,   111,   420,   453,   464,   113,
     458,   423,   485,   465,   484,   429,   491,   467,   488,   198,
     461,   296,   298,   195,   409,    96,   109,   483,   238,   295,
     137,   299,   402,   270,   392,    68,   297,   415,     0,   334,
       0,   486,   200,   487,   201,    75,    76,    77,     0,    78,
       0,    79,    80,     0,     0,   451,     0,     0,   452,     0,
       0,     0,     0,     0,     0,   198,     0,     0,     0,     0,
       0,     0,     0,   460,     0,     0,   462,   198,     1,    81,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,    26,    82,    27,
      83,    28,    29,    30,     0,     0,    84,     0,     0,    85,
      86,    87,   200,     0,   201,    75,    76,    77,    88,    78,
       0,    79,    80,     0,   124,   211,    89,    90,     0,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    81,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,    26,    82,    27,
      83,    28,    29,    30,     0,     0,    84,     0,     0,    85,
      86,    87,   200,     0,   201,    75,    76,    77,    88,    78,
       0,    79,    80,     0,   124,   333,    89,    90,     0,   212,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
       0,    78,     0,    79,    80,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,    78,     0,    79,    80,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,     0,    82,     0,
      83,     0,     0,    81,     0,     0,    84,     0,     0,    85,
      86,    87,     0,     0,     0,     0,     0,     0,    88,     0,
      82,     0,    83,     0,   124,     0,    89,    90,    84,   212,
       0,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,     0,    82,     0,    83,     0,     0,     0,    89,    90,
      84,   330,     0,    85,    86,    87,    74,    75,    76,    77,
       0,    78,    88,    79,    80,     0,     0,     0,     0,     0,
      89,    90,     0,   212,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,     0,    78,     0,    79,    80,
       1,    81,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    81,     0,     0,   233,
       0,     0,     0,     8,     9,    10,     0,     0,     0,     0,
      82,    27,    83,     0,     0,     0,     0,     0,    84,     0,
       0,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,    82,     0,    83,    89,    90,
       0,     0,     0,    84,     0,     0,    85,    86,   234,    74,
      75,    76,    77,     0,    78,    88,    79,    80,     0,   235,
       0,     0,     0,    89,    90,     0,     0,     0,    74,    75,
      76,    77,     0,    78,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,   304,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,   347,     0,     0,     0,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,    83,     0,     0,     0,     0,
       0,    84,     0,     0,    85,    86,   305,     0,     0,     0,
       0,     0,    82,    88,    83,     0,     0,   306,     0,     0,
      84,    89,    90,    85,    86,   348,    74,    75,    76,    77,
       0,    78,    88,    79,    80,     0,   349,     0,     0,     0,
      89,    90,     0,     0,     0,    74,    75,    76,    77,     0,
      78,     0,    79,    80,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,   375,     0,     0,     0,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,   380,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,    83,     0,     0,     0,     0,     0,    84,     0,
       0,    85,    86,    87,     0,     0,     0,     0,     0,    82,
      88,    83,     0,     0,   376,     0,     0,    84,    89,    90,
      85,    86,   381,    74,    75,    76,    77,     0,    78,    88,
      79,    80,     0,   382,     0,     0,     0,    89,    90,     0,
       0,     0,    74,    75,    76,    77,     0,    78,     0,    79,
      80,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,   427,     0,     0,     0,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    74,    75,
      76,    77,     0,    78,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    83,
       0,     0,     0,     0,     0,    84,     0,     0,    85,    86,
      87,     0,     0,    81,     0,     0,    82,    88,    83,     0,
       0,   428,     0,     0,    84,    89,    90,    85,    86,    87,
       0,     0,     0,     0,     0,     0,    88,     0,     0,   313,
       0,   314,   197,   432,    89,    90,     0,     0,    74,    75,
      76,    77,    82,    78,    83,    79,    80,     0,     0,     0,
      84,     0,     0,    85,    86,    87,     0,     0,     0,     0,
       0,     0,    88,     0,     0,   313,     0,   314,   197,   463,
      89,    90,     0,    81,    74,    75,    76,    77,     0,    78,
       0,    79,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,     0,    78,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,    82,     0,    83,     0,     8,     9,    10,     0,
      84,     0,     0,    85,    86,    87,     0,     0,    81,     0,
       0,     0,    88,     0,     0,   313,     0,   314,   197,     0,
      89,    90,     0,     0,     0,     0,     0,     0,    82,     0,
      83,     0,     0,     0,     0,     0,    84,     0,     0,    85,
      86,    87,     0,     0,     0,     0,     0,    82,    88,    83,
       0,     0,     0,     0,     0,    84,    89,    90,    85,    86,
      87,    74,    75,    76,    77,     0,    78,    88,    79,    80,
       0,     0,     0,   197,     0,    89,    90,     0,     0,     0,
      74,    75,    76,    77,     0,    78,     0,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,    74,
      75,    76,    77,     0,    78,     0,    79,    80,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    74,    75,
      76,    77,     0,    78,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,    83,     0,     0,
       0,     0,     0,    84,     0,     0,    85,    86,    87,     0,
       0,     0,     0,    81,    82,    88,    83,     0,     0,     0,
       0,   363,    84,    89,    90,    85,    86,    87,     0,     0,
       0,     0,     0,    82,    88,    83,     0,     0,     0,     0,
       0,    84,    89,    90,    85,    86,    87,     0,    51,     0,
       0,     0,    82,   141,    83,     0,     0,     0,     0,     0,
      84,    89,    90,    85,    86,    87,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
      89,    90,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,   335,   301,     1,   184,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,     0,     1,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,    26,     0,    27,     0,
      28,    29,    30,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,    27,     0,     0,    29,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   351,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
       0,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     1,   124,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   124,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
       0,    28,     0,    30,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,   183,   301,
       1,   184,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,   378,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,    29,    30,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
       1,    30,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    26,
       0,    27,     0,    28,     0,    30,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,    27,
       0,     0,    29,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,   411,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,    27,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27
};

static const yytype_int16 yycheck[] =
{
      48,    48,    50,    50,    50,    59,   129,   123,    96,    52,
      48,    49,   185,    57,    48,    49,   104,   112,    52,    88,
      26,    96,    96,     0,    97,    63,   326,   100,   388,    63,
      78,    79,    80,   108,   108,    57,   321,   139,    86,   130,
     325,    96,     3,    32,   133,    90,    96,    96,    98,    97,
      88,     3,    97,   108,    88,   100,    33,    34,     3,   108,
      96,     3,    39,    40,    41,     3,    43,     3,   104,   112,
      97,    97,   141,   111,   143,   113,   119,   111,     3,   113,
      57,    97,     3,    63,   128,   119,   446,     3,    97,   158,
     138,   138,   138,   184,   132,   133,   130,     3,   132,   133,
     103,   107,   124,   141,     3,   143,   128,   141,   146,   143,
      63,   180,   146,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   121,   228,   161,   162,   163,   126,    90,   439,
     183,   210,   233,   104,   246,    97,   135,   124,    90,   238,
     184,   128,   132,   133,   123,    97,   108,    99,   111,   104,
     113,   130,    48,    49,   337,   103,   108,   103,    96,    90,
     455,   103,    97,   101,    90,   100,    97,    95,   147,   132,
     133,    97,     3,   468,   100,   228,    97,   310,   157,   100,
      97,    97,    97,   241,   241,   241,   218,   482,    96,   233,
     238,   317,    88,   237,   238,    95,   104,   492,   493,   494,
     100,    85,   102,   304,    97,   184,    84,   100,    14,    15,
     311,    96,    18,     9,    10,    11,   274,    25,   197,   104,
      45,    46,    47,   168,   169,   170,   171,   172,    83,   228,
      96,   218,    96,    99,    90,    91,    92,   274,    96,    96,
      98,    98,     3,   322,   323,   141,    98,   143,   238,    96,
     146,    98,    88,    89,   233,   313,   313,   313,   237,    90,
     304,    96,   388,    98,   308,    90,    97,   311,    99,    96,
      96,    98,    98,   337,    96,   238,    98,    12,    13,   380,
      86,    87,   335,    16,    17,    64,    65,   164,   165,    98,
     166,   167,   271,   272,   173,   174,    98,   355,   355,   355,
     344,    97,     3,    98,   100,    98,   102,     6,   434,    95,
     368,   368,   360,     3,   108,    99,   360,   396,   108,    97,
     446,    97,    97,   108,    98,   304,    96,    99,   372,   308,
     101,    98,   311,   101,    98,    98,   380,    96,   317,   101,
     384,    98,    96,    98,     3,    98,    98,    19,    20,    21,
      22,    23,   101,    97,   353,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,   344,   108,     3,   347,   101,
     101,   101,   108,   101,   103,   101,    98,   101,   101,   458,
     424,   101,    69,   101,   363,   101,    99,   366,    99,   101,
      67,   470,   101,   372,   101,   443,   375,   101,   101,   443,
      97,   380,   104,   101,    99,   384,    99,   103,   108,   388,
     443,   176,   178,   121,   353,   473,   473,   473,   132,   175,
      69,   179,   340,    95,   318,    43,   177,   363,    -1,   218,
      -1,   476,     1,   476,     3,     4,     5,     6,    -1,     8,
      -1,    10,    11,    -1,    -1,   424,    -1,    -1,   427,    -1,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   442,    -1,    -1,   445,   446,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,     1,    -1,     3,     4,     5,     6,    97,     8,
      -1,    10,    11,    -1,   103,   104,   105,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,     1,    -1,     3,     4,     5,     6,    97,     8,
      -1,    10,    11,    -1,   103,   104,   105,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    -1,
      79,    -1,    -1,    38,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      77,    -1,    79,    -1,   103,    -1,   105,   106,    85,   108,
      -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    77,    -1,    79,    -1,    -1,    -1,   105,   106,
      85,   108,    -1,    88,    89,    90,     3,     4,     5,     6,
      -1,     8,    97,    10,    11,    -1,    -1,    -1,    -1,    -1,
     105,   106,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    10,    11,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    38,    -1,    -1,    41,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    77,    -1,    79,   105,   106,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    90,     3,
       4,     5,     6,    -1,     8,    97,    10,    11,    -1,   101,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,
      -1,    -1,    77,    97,    79,    -1,    -1,   101,    -1,    -1,
      85,   105,   106,    88,    89,    90,     3,     4,     5,     6,
      -1,     8,    97,    10,    11,    -1,   101,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    77,
      97,    79,    -1,    -1,   101,    -1,    -1,    85,   105,   106,
      88,    89,    90,     3,     4,     5,     6,    -1,     8,    97,
      10,    11,    -1,   101,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,
      90,    -1,    -1,    38,    -1,    -1,    77,    97,    79,    -1,
      -1,   101,    -1,    -1,    85,   105,   106,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,   102,   103,   104,   105,   106,    -1,    -1,     3,     4,
       5,     6,    77,     8,    79,    10,    11,    -1,    -1,    -1,
      85,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,   102,   103,   104,
     105,   106,    -1,    38,     3,     4,     5,     6,    -1,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    77,    -1,    79,    -1,    45,    46,    47,    -1,
      85,    -1,    -1,    88,    89,    90,    -1,    -1,    38,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,   102,   103,    -1,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    77,    97,    79,
      -1,    -1,    -1,    -1,    -1,    85,   105,   106,    88,    89,
      90,     3,     4,     5,     6,    -1,     8,    97,    10,    11,
      -1,    -1,    -1,   103,    -1,   105,   106,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    -1,    38,    77,    97,    79,    -1,    -1,    -1,
      -1,   103,    85,   105,   106,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    77,    97,    79,    -1,    -1,    -1,    -1,
      -1,    85,   105,   106,    88,    89,    90,    -1,     3,    -1,
      -1,    -1,    77,    97,    79,    -1,    -1,    -1,    -1,    -1,
      85,   105,   106,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    37,   100,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    76,    -1,    78,    -1,
      80,    81,    82,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    78,    -1,    -1,    81,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,   104,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,
      -1,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    37,   103,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    78,    -1,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,   103,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      37,   100,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    78,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    98,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    78,    -1,    80,    81,    82,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      37,    82,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    76,
      -1,    78,    -1,    80,    -1,    82,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    78,
      -1,    -1,    81,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    76,    78,    80,    81,
      82,   138,   139,   142,   143,   144,   145,   151,   154,   155,
     156,   157,   174,   194,   195,   196,     3,   103,    97,    97,
      97,     3,    90,    97,   108,   140,   141,   158,   159,   160,
     139,   139,     3,   103,   139,   139,   139,     0,   195,   103,
       3,   112,   152,   153,     3,     4,     5,     6,     8,    10,
      11,    38,    77,    79,    85,    88,    89,    90,    97,   105,
     106,   110,   111,   113,   114,   117,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     137,   143,   148,   155,   166,   166,   137,   155,   160,   161,
     158,    96,   108,    95,   103,   138,   139,   177,   197,    97,
     100,   159,   103,   146,   147,   148,   174,   152,    95,    96,
     104,    97,   120,    97,   120,   120,    97,    97,   120,   120,
     133,   134,   136,   166,     9,    10,    11,    97,   100,   102,
     122,    90,    91,    92,    88,    89,    12,    13,    14,    15,
      18,    86,    87,    16,    17,    85,    84,    83,    25,    26,
     107,    98,   148,    97,   100,   160,   167,   168,   148,    98,
      98,    96,   155,   160,    98,   141,   158,   103,   134,   169,
       1,     3,    66,    68,    69,    70,    71,    72,    73,    74,
      75,   104,   108,   136,   138,   175,   176,   177,   178,   179,
     180,   183,   186,   193,   138,   177,     3,    98,   139,   162,
     163,   164,   165,    41,    90,   101,   134,   161,   146,   104,
     147,    99,   108,   149,   150,   158,    96,   104,   137,   104,
     153,   166,   166,   166,   134,    19,    20,    21,    22,    23,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      95,   135,    96,    98,    98,     3,   118,   119,   134,   136,
       3,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     125,   125,   125,   126,   126,   127,   128,   129,   130,   131,
     136,    98,   162,   167,    41,    90,   101,   134,   161,   168,
      97,   100,     6,   100,   102,   169,   170,   171,   172,   173,
     108,    99,    97,    97,   187,   189,    97,     3,   108,   108,
     108,   136,   108,   104,   179,    97,   158,   160,   167,    98,
      96,    96,    98,   134,   161,   101,   101,    41,    90,   101,
     134,   104,   137,    96,   108,    99,   104,    98,    98,    98,
      96,   134,   134,   103,   122,    98,    96,   101,    99,    98,
      98,   134,   161,   101,   101,    41,   101,   134,    98,   162,
      41,    90,   101,   134,   161,    98,   137,     3,    96,   104,
     169,    95,   173,   175,   136,   136,    97,   175,   180,   108,
     108,    63,   164,     3,   101,   134,   134,   101,   101,   150,
     137,    65,   115,   116,   166,   170,   134,   133,   101,   134,
     134,   101,    98,   134,   161,   101,   101,    41,   101,   134,
     108,   101,   104,   169,   171,    98,    98,   136,    69,   190,
     101,   101,    99,    96,    98,    99,    96,   104,   101,   101,
     101,   134,   134,   101,   169,   184,   185,    98,    97,   180,
     134,   116,   134,   104,   101,   101,   175,   103,   188,   136,
     191,    67,   181,    64,    65,   198,   199,   200,   202,   175,
      98,   136,   182,   137,    99,   104,   200,   202,   108,    98,
     175,    99,   203,   192,   201,   175,   175,   175
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
     177,   177,   178,   178,   179,   179,   180,   180,   181,   182,
     181,   184,   183,   185,   183,   187,   188,   186,   189,   186,
     190,   191,   192,   186,   193,   193,   193,   193,   193,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   198,   198,
     199,   199,   201,   200,   203,   202
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
       2,     3,     1,     2,     1,     1,     1,     2,     0,     0,
       3,     0,     7,     0,     8,     0,     0,     7,     0,     8,
       0,     0,     0,    10,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     4,     3,     1,     2,     2,     1,     1,
       1,     2,     0,     5,     0,     4
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
#line 183 "yapl.y"
                              { (yyval.place) = (yyvsp[0].place); }
#line 2123 "yapl.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 186 "yapl.y"
                              { (yyval.place) = (yyvsp[-1].place); }
#line 2129 "yapl.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 191 "yapl.y"
                     {
		int_consts++;
		(yyval.place) = strdup(yytext);
	}
#line 2138 "yapl.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 195 "yapl.y"
                              { (yyval.place) = strdup(yytext); }
#line 2144 "yapl.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 196 "yapl.y"
                               { (yyval.place) = strdup(yytext); }
#line 2150 "yapl.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 204 "yapl.y"
                         { (yyval.place) = strdup(yytext); }
#line 2156 "yapl.tab.c"
    break;

  case 12: /* generic_selection: GENERIC '(' assignment_expression ',' generic_assoc_list ')'  */
#line 208 "yapl.y"
                                                                       { (yyval.place) = (yyvsp[-3].place); }
#line 2162 "yapl.tab.c"
    break;

  case 15: /* generic_association: type_name ':' assignment_expression  */
#line 217 "yapl.y"
                                               { (yyval.place) = (yyvsp[0].place); }
#line 2168 "yapl.tab.c"
    break;

  case 16: /* generic_association: DEFAULT ':' assignment_expression  */
#line 218 "yapl.y"
                                               { (yyval.place) = (yyvsp[0].place); }
#line 2174 "yapl.tab.c"
    break;

  case 17: /* postfix_expression: primary_expression  */
#line 222 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[0].place); }
#line 2180 "yapl.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 223 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-3].place); }
#line 2186 "yapl.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '(' argument_expression_list_opt ')'  */
#line 224 "yapl.y"
                                                                        { (yyval.place) = new_temp(); add_quad("call",(yyvsp[-3].place),"",(yyval.place)); }
#line 2192 "yapl.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 225 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-2].place); }
#line 2198 "yapl.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 226 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-2].place); }
#line 2204 "yapl.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression INC_OP  */
#line 227 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-1].place); }
#line 2210 "yapl.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression DEC_OP  */
#line 228 "yapl.y"
                                                                        { (yyval.place) = (yyvsp[-1].place); }
#line 2216 "yapl.tab.c"
    break;

  case 24: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 229 "yapl.y"
                                                                        { (yyval.place) = NULL; }
#line 2222 "yapl.tab.c"
    break;

  case 25: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 230 "yapl.y"
                                                                        { (yyval.place) = NULL; }
#line 2228 "yapl.tab.c"
    break;

  case 26: /* argument_expression_list_opt: %empty  */
#line 234 "yapl.y"
                      { (yyval.place)=NULL; }
#line 2234 "yapl.tab.c"
    break;

  case 27: /* argument_expression_list_opt: argument_expression_list  */
#line 235 "yapl.y"
                                   { (yyval.place) = (yyvsp[0].place); }
#line 2240 "yapl.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 240 "yapl.y"
        {
		(yyval.place) = (yyvsp[0].place);
	}
#line 2248 "yapl.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 244 "yapl.y"
        {
		(yyval.place)=(yyvsp[0].place);
	}
#line 2256 "yapl.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 250 "yapl.y"
                                                { (yyval.place) = (yyvsp[0].place); }
#line 2262 "yapl.tab.c"
    break;

  case 31: /* unary_expression: INC_OP unary_expression  */
#line 251 "yapl.y"
                                                { (yyval.place) = (yyvsp[0].place); }
#line 2268 "yapl.tab.c"
    break;

  case 32: /* unary_expression: DEC_OP unary_expression  */
#line 252 "yapl.y"
                                                { (yyval.place) = (yyvsp[0].place); }
#line 2274 "yapl.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 253 "yapl.y"
                                                { (yyval.place) = (yyvsp[0].place); }
#line 2280 "yapl.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 254 "yapl.y"
                                                { (yyval.place) = NULL; }
#line 2286 "yapl.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 255 "yapl.y"
                                               { (yyval.place) = NULL; }
#line 2292 "yapl.tab.c"
    break;

  case 36: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 256 "yapl.y"
                                               { (yyval.place) = NULL; }
#line 2298 "yapl.tab.c"
    break;

  case 37: /* unary_expression: '-' unary_expression  */
#line 257 "yapl.y"
                               {
		(yyval.place) = new_temp();
		add_quad("minus", (yyvsp[0].place), "", (yyval.place));
	}
#line 2307 "yapl.tab.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 268 "yapl.y"
                                                   { (yyval.place) = (yyvsp[0].place); }
#line 2313 "yapl.tab.c"
    break;

  case 44: /* cast_expression: '(' type_name ')' cast_expression  */
#line 269 "yapl.y"
                                                   { (yyval.place) = (yyvsp[0].place); }
#line 2319 "yapl.tab.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 273 "yapl.y"
                                                            { (yyval.place) = (yyvsp[0].place); }
#line 2325 "yapl.tab.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 274 "yapl.y"
                                                            {
		(yyval.place) = new_temp(); add_quad("*",  (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2332 "yapl.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 276 "yapl.y"
                                                            {
		(yyval.place) = new_temp(); add_quad("/",  (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2339 "yapl.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 278 "yapl.y"
                                                            {
		(yyval.place) = new_temp(); add_quad("%",  (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2346 "yapl.tab.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 283 "yapl.y"
                                                                 { (yyval.place) = (yyvsp[0].place); }
#line 2352 "yapl.tab.c"
    break;

  case 50: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 284 "yapl.y"
                                                                 {
		(yyval.place) = new_temp(); add_quad("+", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2359 "yapl.tab.c"
    break;

  case 51: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 286 "yapl.y"
                                                                 {
		(yyval.place) = new_temp(); add_quad("-", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2366 "yapl.tab.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 291 "yapl.y"
                                                           { (yyval.place) = (yyvsp[0].place); }
#line 2372 "yapl.tab.c"
    break;

  case 53: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 292 "yapl.y"
                                                           {
		(yyval.place) = new_temp(); add_quad("<<", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2379 "yapl.tab.c"
    break;

  case 54: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 294 "yapl.y"
                                                           {
		(yyval.place) = new_temp(); add_quad(">>", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2386 "yapl.tab.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 299 "yapl.y"
                                                          { (yyval.place) = (yyvsp[0].place); }
#line 2392 "yapl.tab.c"
    break;

  case 56: /* relational_expression: relational_expression '<' shift_expression  */
#line 300 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad("<",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2399 "yapl.tab.c"
    break;

  case 57: /* relational_expression: relational_expression '>' shift_expression  */
#line 302 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad(">",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2406 "yapl.tab.c"
    break;

  case 58: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 304 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad("<=",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2413 "yapl.tab.c"
    break;

  case 59: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 306 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad(">=",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2420 "yapl.tab.c"
    break;

  case 60: /* relational_expression: relational_expression TH_OP shift_expression  */
#line 308 "yapl.y"
                                                          {
		(yyval.place) = new_temp(); add_quad("<=>",   (yyvsp[-2].place), (yyvsp[0].place), (yyval.place));  }
#line 2427 "yapl.tab.c"
    break;

  case 61: /* equality_expression: relational_expression  */
#line 313 "yapl.y"
                                                              { (yyval.place) = (yyvsp[0].place); }
#line 2433 "yapl.tab.c"
    break;

  case 62: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 314 "yapl.y"
                                                              {
		(yyval.place) = new_temp(); add_quad("==", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2440 "yapl.tab.c"
    break;

  case 63: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 316 "yapl.y"
                                                              {
		(yyval.place) = new_temp(); add_quad("!=", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2447 "yapl.tab.c"
    break;

  case 64: /* and_expression: equality_expression  */
#line 321 "yapl.y"
                                                       { (yyval.place) = (yyvsp[0].place); }
#line 2453 "yapl.tab.c"
    break;

  case 65: /* and_expression: and_expression '&' equality_expression  */
#line 322 "yapl.y"
                                                       {
		(yyval.place) = new_temp(); add_quad("&", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2460 "yapl.tab.c"
    break;

  case 66: /* exclusive_or_expression: and_expression  */
#line 327 "yapl.y"
                                                       { (yyval.place) = (yyvsp[0].place); }
#line 2466 "yapl.tab.c"
    break;

  case 67: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 328 "yapl.y"
                                                       {
		(yyval.place) = new_temp(); add_quad("^", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2473 "yapl.tab.c"
    break;

  case 68: /* inclusive_or_expression: exclusive_or_expression  */
#line 333 "yapl.y"
                                                               { (yyval.place) = (yyvsp[0].place); }
#line 2479 "yapl.tab.c"
    break;

  case 69: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 334 "yapl.y"
                                                               {
		(yyval.place) = new_temp(); add_quad("|", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2486 "yapl.tab.c"
    break;

  case 70: /* logical_and_expression: inclusive_or_expression  */
#line 339 "yapl.y"
                                                                   { (yyval.place) = (yyvsp[0].place); }
#line 2492 "yapl.tab.c"
    break;

  case 71: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 340 "yapl.y"
                                                                   {
		(yyval.place) = new_temp(); add_quad("&&", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2499 "yapl.tab.c"
    break;

  case 72: /* logical_or_expression: logical_and_expression  */
#line 345 "yapl.y"
                                                                { (yyval.place) = (yyvsp[0].place); }
#line 2505 "yapl.tab.c"
    break;

  case 73: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 346 "yapl.y"
                                                                {
		(yyval.place) = new_temp(); add_quad("||", (yyvsp[-2].place), (yyvsp[0].place), (yyval.place)); }
#line 2512 "yapl.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression  */
#line 351 "yapl.y"
                                { (yyval.place) = (yyvsp[0].place); }
#line 2518 "yapl.tab.c"
    break;

  case 75: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 352 "yapl.y"
                                                                          { (yyval.place) = (yyvsp[-4].place); }
#line 2524 "yapl.tab.c"
    break;

  case 76: /* assignment_expression: conditional_expression  */
#line 356 "yapl.y"
                                 {
		(yyval.place) = (yyvsp[0].place);
		sprintf(derivations[dtop++], "assignment_expression -> conditional_expression");
	}
#line 2533 "yapl.tab.c"
    break;

  case 77: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 360 "yapl.y"
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
#line 2549 "yapl.tab.c"
    break;

  case 78: /* assignment_operator: '='  */
#line 374 "yapl.y"
                       { (yyval.op) = strdup("=");  }
#line 2555 "yapl.tab.c"
    break;

  case 79: /* assignment_operator: MUL_ASSIGN  */
#line 375 "yapl.y"
                       { (yyval.op) = strdup("*");  }
#line 2561 "yapl.tab.c"
    break;

  case 80: /* assignment_operator: DIV_ASSIGN  */
#line 376 "yapl.y"
                       { (yyval.op) = strdup("/");  }
#line 2567 "yapl.tab.c"
    break;

  case 81: /* assignment_operator: MOD_ASSIGN  */
#line 377 "yapl.y"
                       { (yyval.op) = strdup("%");  }
#line 2573 "yapl.tab.c"
    break;

  case 82: /* assignment_operator: ADD_ASSIGN  */
#line 378 "yapl.y"
                       { (yyval.op) = strdup("+");  }
#line 2579 "yapl.tab.c"
    break;

  case 83: /* assignment_operator: SUB_ASSIGN  */
#line 379 "yapl.y"
                       { (yyval.op) = strdup("-");  }
#line 2585 "yapl.tab.c"
    break;

  case 84: /* assignment_operator: LEFT_ASSIGN  */
#line 380 "yapl.y"
                       { (yyval.op) = strdup("<<"); }
#line 2591 "yapl.tab.c"
    break;

  case 85: /* assignment_operator: RIGHT_ASSIGN  */
#line 381 "yapl.y"
                       { (yyval.op) = strdup(">>"); }
#line 2597 "yapl.tab.c"
    break;

  case 86: /* assignment_operator: AND_ASSIGN  */
#line 382 "yapl.y"
                       { (yyval.op) = strdup("&");  }
#line 2603 "yapl.tab.c"
    break;

  case 87: /* assignment_operator: XOR_ASSIGN  */
#line 383 "yapl.y"
                       { (yyval.op) = strdup("^");  }
#line 2609 "yapl.tab.c"
    break;

  case 88: /* assignment_operator: OR_ASSIGN  */
#line 384 "yapl.y"
                       { (yyval.op) = strdup("|");  }
#line 2615 "yapl.tab.c"
    break;

  case 89: /* assignment_operator: PEQ_OP  */
#line 385 "yapl.y"
                       { (yyval.op) = strdup("+");  }
#line 2621 "yapl.tab.c"
    break;

  case 90: /* assignment_operator: MEQ_OP  */
#line 386 "yapl.y"
                       { (yyval.op) = strdup("-");  }
#line 2627 "yapl.tab.c"
    break;

  case 91: /* assignment_operator: STREQ_OP  */
#line 387 "yapl.y"
                       { (yyval.op) = strdup("*");  }
#line 2633 "yapl.tab.c"
    break;

  case 92: /* assignment_operator: DEQ_OP  */
#line 388 "yapl.y"
                       { (yyval.op) = strdup("/");  }
#line 2639 "yapl.tab.c"
    break;

  case 93: /* assignment_operator: MODEQ_OP  */
#line 389 "yapl.y"
                       { (yyval.op) = strdup("%");  }
#line 2645 "yapl.tab.c"
    break;

  case 94: /* expression: assignment_expression  */
#line 393 "yapl.y"
                                {
		(yyval.place) = (yyvsp[0].place);
		sprintf(derivations[dtop++], "expression -> assignment_expression");
	}
#line 2654 "yapl.tab.c"
    break;

  case 95: /* expression: expression ',' assignment_expression  */
#line 397 "yapl.y"
                                               {
		(yyval.place) = (yyvsp[0].place);
		sprintf(derivations[dtop++], "expression -> expression , assignment_expression");
	}
#line 2663 "yapl.tab.c"
    break;

  case 97: /* declaration: declaration_specifiers ';'  */
#line 408 "yapl.y"
                                     {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers ;");
	}
#line 2671 "yapl.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 411 "yapl.y"
                                                          {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers init_declarator_list ;");
	}
#line 2679 "yapl.tab.c"
    break;

  case 99: /* declaration: static_assert_declaration  */
#line 414 "yapl.y"
                                    {
		sprintf(derivations[dtop++], "declaration -> static_assert_declaration");
	}
#line 2687 "yapl.tab.c"
    break;

  case 172: /* declarator: pointer direct_declarator  */
#line 530 "yapl.y"
                                    { pointer_decls++; }
#line 2693 "yapl.tab.c"
    break;

  case 242: /* statement: error ';'  */
#line 651 "yapl.y"
                    {
		printf("Recovered from error at line %d near token '%s'\n", line_no, yytext);
		yyerrok;
	}
#line 2702 "yapl.tab.c"
    break;

  case 243: /* statement: labeled_statement  */
#line 655 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> labeled_statement");   }
#line 2708 "yapl.tab.c"
    break;

  case 244: /* statement: compound_statement  */
#line 656 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> compound_statement");  }
#line 2714 "yapl.tab.c"
    break;

  case 245: /* statement: expression_statement  */
#line 657 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> expression_statement");}
#line 2720 "yapl.tab.c"
    break;

  case 246: /* statement: selection_statement  */
#line 658 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> selection_statement"); }
#line 2726 "yapl.tab.c"
    break;

  case 247: /* statement: iteration_statement  */
#line 659 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> iteration_statement"); }
#line 2732 "yapl.tab.c"
    break;

  case 248: /* statement: jump_statement  */
#line 660 "yapl.y"
                              { sprintf(derivations[dtop++], "statement -> jump_statement");      }
#line 2738 "yapl.tab.c"
    break;

  case 250: /* compound_statement: '{' '}'  */
#line 668 "yapl.y"
                  {
		sprintf(derivations[dtop++], "compound_statement -> { }");
	}
#line 2746 "yapl.tab.c"
    break;

  case 251: /* compound_statement: '{' block_item_list '}'  */
#line 671 "yapl.y"
                                  {
		sprintf(derivations[dtop++], "compound_statement -> { block_item_list }");
	}
#line 2754 "yapl.tab.c"
    break;

  case 252: /* block_item_list: block_item  */
#line 677 "yapl.y"
                                      { sprintf(derivations[dtop++], "block_item_list -> block_item"); }
#line 2760 "yapl.tab.c"
    break;

  case 253: /* block_item_list: block_item_list block_item  */
#line 678 "yapl.y"
                                      { sprintf(derivations[dtop++], "block_item_list -> block_item_list block_item"); }
#line 2766 "yapl.tab.c"
    break;

  case 254: /* block_item: declaration  */
#line 682 "yapl.y"
                      { sprintf(derivations[dtop++], "block_item -> declaration"); }
#line 2772 "yapl.tab.c"
    break;

  case 255: /* block_item: statement  */
#line 683 "yapl.y"
                      { sprintf(derivations[dtop++], "block_item -> statement");   }
#line 2778 "yapl.tab.c"
    break;

  case 256: /* expression_statement: ';'  */
#line 687 "yapl.y"
          {
        (yyval.place) = NULL;
        sprintf(derivations[dtop++], "expression_statement -> ;");
    }
#line 2787 "yapl.tab.c"
    break;

  case 257: /* expression_statement: expression ';'  */
#line 691 "yapl.y"
                     {
        (yyval.place) = (yyvsp[-1].place);
        sprintf(derivations[dtop++], "expression_statement -> expression ;");
    }
#line 2796 "yapl.tab.c"
    break;

  case 258: /* else_part: %empty  */
#line 699 "yapl.y"
      {
          char *lf = pop_false();
          add_quad("label", "", "", lf);
          ifs_wo_else++;
		  if(ladder_len > max) max=ladder_len;
		  ladder_len=0;
      }
#line 2808 "yapl.tab.c"
    break;

  case 259: /* $@1: %empty  */
#line 707 "yapl.y"
      {
          char *le = new_label();
          char *lf = pop_false();
          add_quad("goto",  "", "", le);
          add_quad("label", "", "", lf);
          push_end(le);
		  ladder_len++;
		  if(ladder_len > max) max= ladder_len;
      }
#line 2822 "yapl.tab.c"
    break;

  case 260: /* else_part: ELSE $@1 statement  */
#line 717 "yapl.y"
      {
          char *le = pop_end();
          if (le) add_quad("label", "", "", le);
      }
#line 2831 "yapl.tab.c"
    break;

  case 261: /* $@2: %empty  */
#line 725 "yapl.y"
      {
          char *lf = new_label();
          if ((yyvsp[-1].place)) add_quad("iffalse", (yyvsp[-1].place), "", lf);
          push_false(lf);
		  if_depth++;
      }
#line 2842 "yapl.tab.c"
    break;

  case 262: /* selection_statement: IF '(' expression ')' $@2 statement else_part  */
#line 732 "yapl.y"
      {
          if_depth--;
		  (yyval.place) = NULL;
      }
#line 2851 "yapl.tab.c"
    break;

  case 263: /* $@3: %empty  */
#line 737 "yapl.y"
      {
         char *Lend = new_label();
         push_end(Lend);

         push_switch_expr((yyvsp[-1].place));

         char *Ldefault = new_label();
         push_false(Ldefault);
      }
#line 2865 "yapl.tab.c"
    break;

  case 264: /* selection_statement: SWITCH '(' expression ')' $@3 '{' switch_body '}'  */
#line 747 "yapl.y"
      {
      char *Ldefault = pop_false();

      // jump to default if no case matched
      add_quad("goto", "", "", Ldefault);

      add_quad("label", "", "", Ldefault);

      char *Lend = pop_end();
      pop_switch_expr();

      add_quad("label", "", "", Lend);

      (yyval.place) = NULL;
    }
#line 2885 "yapl.tab.c"
    break;

  case 265: /* $@4: %empty  */
#line 766 "yapl.y"
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
#line 2895 "yapl.tab.c"
    break;

  case 266: /* $@5: %empty  */
#line 772 "yapl.y"
      {
          char *Lend = new_label();
          add_quad("iffalse", (yyvsp[-1].place), "", Lend);
          push_end(Lend);
      }
#line 2905 "yapl.tab.c"
    break;

  case 267: /* iteration_statement: WHILE $@4 '(' expression ')' $@5 statement  */
#line 778 "yapl.y"
      {
          char *Lend   = pop_end();
          char *Lstart = pop_false();
          add_quad("goto",  "", "", Lstart);
          add_quad("label", "", "", Lend);
          (yyval.place) = NULL;
      }
#line 2917 "yapl.tab.c"
    break;

  case 268: /* $@6: %empty  */
#line 787 "yapl.y"
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
#line 2927 "yapl.tab.c"
    break;

  case 269: /* iteration_statement: DO $@6 statement WHILE '(' expression ')' ';'  */
#line 794 "yapl.y"
      {
          char *Lstart = pop_false();
          add_quad("ifgoto", (yyvsp[-2].place), "", Lstart);
          (yyval.place) = NULL;
      }
#line 2937 "yapl.tab.c"
    break;

  case 270: /* $@7: %empty  */
#line 801 "yapl.y"
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
#line 2947 "yapl.tab.c"
    break;

  case 271: /* $@8: %empty  */
#line 807 "yapl.y"
      {
          char *Lend = new_label();
          add_quad("iffalse", (yyvsp[0].place), "", Lend);
          push_end(Lend);
          /* Snapshot quad_index BEFORE the increment expression is parsed.
             for_inc_start is a dedicated global — no aliasing with the count. */
          for_inc_start = quad_index;
      }
#line 2960 "yapl.tab.c"
    break;

  case 272: /* $@9: %empty  */
#line 816 "yapl.y"
      {
          /* Increment quads are now at [for_inc_start .. quad_index-1].
             Cut them out: copy to buffer, roll back the stream. */
          for_inc_cnt = quad_index - for_inc_start;
          if (for_inc_cnt > 0) {
              memcpy(for_inc_buf, quads + for_inc_start, sizeof(quad) * for_inc_cnt);
              quad_index = for_inc_start;   /* roll back — body comes next */
          }
      }
#line 2974 "yapl.tab.c"
    break;

  case 273: /* iteration_statement: FOR '(' expression_statement $@7 expression_statement $@8 expression ')' $@9 statement  */
#line 826 "yapl.y"
      {
          /* Body is done.  Replay the saved increment quads NOW. */
          if (for_inc_cnt > 0) {
              memcpy(quads + quad_index, for_inc_buf, sizeof(quad) * for_inc_cnt);
              quad_index  += for_inc_cnt;
              for_inc_cnt  = 0;
          }
          char *Lend   = pop_end();
          char *Lstart = pop_false();
          add_quad("goto",  "", "", Lstart);
          add_quad("label", "", "", Lend);
          (yyval.place) = NULL;
      }
#line 2992 "yapl.tab.c"
    break;

  case 276: /* jump_statement: BREAK ';'  */
#line 845 "yapl.y"
    {
      char *Lend = end_label_stack[end_stack_top - 1];
      add_quad("goto", "", "", Lend);
    }
#line 3001 "yapl.tab.c"
    break;

  case 279: /* translation_unit: external_declaration  */
#line 854 "yapl.y"
                               {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> external_declaration");
	}
#line 3010 "yapl.tab.c"
    break;

  case 280: /* translation_unit: translation_unit external_declaration  */
#line 858 "yapl.y"
                                                {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> translation_unit external_declaration");
	}
#line 3019 "yapl.tab.c"
    break;

  case 281: /* external_declaration: function_definition  */
#line 865 "yapl.y"
                              { func_definitions++; }
#line 3025 "yapl.tab.c"
    break;

  case 283: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 870 "yapl.y"
                                                                                {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator declaration_list compound_statement");
	}
#line 3033 "yapl.tab.c"
    break;

  case 284: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 873 "yapl.y"
                                                               {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator compound_statement");
	}
#line 3041 "yapl.tab.c"
    break;

  case 290: /* case_list: case_statement  */
#line 915 "yapl.y"
                                   { (yyval.place) = NULL; }
#line 3047 "yapl.tab.c"
    break;

  case 291: /* case_list: case_list case_statement  */
#line 916 "yapl.y"
                                   { (yyval.place) = NULL; }
#line 3053 "yapl.tab.c"
    break;

  case 292: /* $@10: %empty  */
#line 921 "yapl.y"
    {
        char *t = new_temp();
        char *Lcase = new_label();

        // evaluate condition
        add_quad("==", top_switch_expr(), (yyvsp[-1].place), t);
        add_quad("ifgoto", t, "", Lcase);

        // if not matched → skip
        char *Lnext = new_label();
        add_quad("goto", "", "", Lnext);

        // matched case
        add_quad("label", "", "", Lcase);

        push_false(Lnext);
    }
#line 3075 "yapl.tab.c"
    break;

  case 293: /* case_statement: CASE constant_expression ':' $@10 statement  */
#line 939 "yapl.y"
    {
        char *Lnext = pop_false();

        // after executing case → exit switch
        char *Lend = end_label_stack[end_stack_top - 1];
        add_quad("goto", "", "", Lend);

        add_quad("label", "", "", Lnext);
    }
#line 3089 "yapl.tab.c"
    break;

  case 294: /* $@11: %empty  */
#line 952 "yapl.y"
    {
        char *Ldefault = pop_false();
        add_quad("label", "", "", Ldefault);
    }
#line 3098 "yapl.tab.c"
    break;


#line 3102 "yapl.tab.c"

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

#line 959 "yapl.y"


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

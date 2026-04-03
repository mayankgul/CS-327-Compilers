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

#line 97 "yapl.tab.c"

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
  YYSYMBOL_94_ = 94,                       /* '&'  */
  YYSYMBOL_95_ = 95,                       /* '*'  */
  YYSYMBOL_96_ = 96,                       /* '+'  */
  YYSYMBOL_97_ = 97,                       /* '-'  */
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
#define YYLAST   2332

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  282
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  488

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
       2,     2,     2,    99,     2,     2,     2,   101,    94,     2,
      86,    87,    95,    96,    85,    97,    91,   100,     2,     2,
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
       0,    63,    63,    64,    65,    66,    67,    71,    72,    73,
      77,    81,    82,    86,    90,    91,    95,    96,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   112,   113,   117,
     118,   122,   123,   124,   125,   126,   127,   128,   132,   133,
     134,   135,   136,   137,   141,   142,   146,   147,   148,   149,
     153,   154,   155,   159,   160,   161,   165,   166,   167,   168,
     169,   170,   174,   175,   176,   180,   181,   185,   186,   190,
     191,   195,   196,   200,   201,   205,   206,   210,   213,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   238,   241,   247,   251,   254,
     257,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   276,   277,   281,   282,   286,   287,   288,   289,   290,
     291,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   314,   315,   316,
     320,   321,   325,   326,   330,   331,   332,   336,   337,   338,
     339,   343,   344,   348,   349,   350,   354,   355,   356,   357,
     358,   362,   363,   367,   368,   372,   376,   377,   378,   383,
     384,   388,   389,   393,   394,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   415,
     416,   417,   418,   422,   423,   428,   429,   433,   434,   438,
     439,   440,   444,   445,   449,   450,   454,   455,   456,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     484,   485,   486,   490,   491,   492,   493,   497,   501,   502,
     506,   507,   511,   515,   519,   522,   525,   528,   531,   534,
     540,   541,   542,   546,   549,   555,   558,   564,   567,   573,
     576,   582,   586,   589,   595,   596,   597,   598,   599,   600,
     604,   605,   606,   607,   608,   612,   616,   623,   624,   628,
     631,   637,   638
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
  "')'", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
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
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-355)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2092,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,
    -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,
    -355,  -355,  -355,  -355,  -355,    23,   -67,    -8,  -355,     2,
    -355,  -355,    37,  2182,  2182,  -355,    43,  -355,  -355,  2182,
    2182,  2182,  -355,  1783,  -355,  -355,   -64,    92,   939,  2254,
    1560,  -355,    21,   128,  -355,   -58,  -355,  1935,   -24,    52,
    -355,  -355,    12,   878,  -355,  -355,  -355,  -355,  -355,    92,
    -355,    58,   -37,  -355,  -355,  -355,  -355,  -355,  -355,  1574,
    1597,  1597,  -355,   102,   111,   939,  -355,  -355,  -355,  -355,
    -355,  -355,  -355,  -355,  -355,  -355,   139,  -355,  1560,  -355,
     132,   -62,   158,    75,   190,    62,    96,   119,   178,    31,
    -355,   167,  2254,   -56,  2254,   173,   183,   141,   193,  -355,
    -355,   128,    21,  -355,  1363,   505,  -355,    37,  -355,  1989,
    1720,   751,   -24,   878,  1569,  -355,    57,  -355,    70,  1560,
      26,  -355,   939,  -355,   939,  -355,  -355,  2254,  1560,   419,
    -355,  -355,   125,   195,   274,  -355,  -355,  1560,  1560,   280,
    -355,  1560,  1560,  1560,  1560,  1560,  1560,  1560,  1560,  1560,
    1560,  1560,  1560,  1560,  1560,  1560,  1560,  1560,  1560,  1560,
    1560,  -355,  -355,  1829,  1001,   -12,  -355,    95,  -355,  -355,
    -355,   281,  -355,  -355,  -355,  -355,   207,  1314,  -355,  -355,
     186,   206,  1560,   208,   211,   212,   213,   737,   216,   300,
     203,   210,   301,  -355,  -355,   -54,  -355,  -355,  -355,  -355,
     632,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,
      65,   226,   229,  -355,   144,  1339,  -355,   230,   234,  1047,
    1880,  -355,  -355,  1560,  -355,   -49,  -355,   231,    29,  -355,
    -355,  -355,  -355,   238,   239,   240,   246,  -355,  -355,  -355,
    -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,
    -355,  -355,  -355,  1560,  1560,  -355,  1416,  -355,   245,   249,
    -355,    68,  -355,  -355,  -355,  -355,   132,   132,   -62,   -62,
     158,   158,   158,   158,   158,    75,    75,   190,    62,    96,
     119,   178,    98,  -355,   250,   254,  1339,  -355,   253,   255,
    1109,    95,  2043,  1155,   260,  1560,   345,  -355,    97,  1363,
     131,  -355,  -355,   737,   263,   737,  1560,  1560,  1560,   284,
     814,   247,  -355,  -355,  -355,   -38,  -355,  -355,  -355,  1660,
    -355,    76,  -355,  -355,  2138,   353,  -355,   267,  1339,  -355,
    -355,  1560,  -355,   269,   270,  -355,  -355,    81,  -355,  1560,
    -355,   275,   275,  -355,  2220,  -355,  -355,  1314,  -355,  -355,
    1560,  -355,  1560,  -355,  -355,   272,  1339,  -355,  -355,  1560,
    -355,   278,  -355,   282,  1339,  -355,   283,   289,  1217,   264,
     291,  -355,   530,  -355,  -355,  -355,  -355,  -355,   737,  -355,
     154,   155,   164,   286,   876,   876,  -355,  -355,  -355,  -355,
    -355,  -355,   292,   294,  -355,  -355,  -355,  -355,   297,   165,
    -355,   298,   100,  -355,  -355,  -355,   299,   302,  -355,  -355,
     303,  1339,  -355,  -355,  1560,  -355,   311,  -355,  -355,  -355,
    -355,  1363,  -355,   737,   737,   737,  1560,  1440,  1463,  -355,
    -355,  1560,  2220,  -355,  1560,  1262,  -355,  -355,  -355,  -355,
     312,   313,  -355,  -355,   321,  -355,  -355,   172,   737,   176,
     737,   179,  -355,  -355,  -355,  -355,  -355,  -355,   737,   304,
    -355,   737,  -355,   737,  -355,  -355,  -355,  -355
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   136,   115,   116,   117,   119,   120,   169,   166,   167,
     168,   130,   122,   123,   124,   125,   128,   129,   126,   127,
     121,   131,   132,   140,   141,     0,     0,     0,   170,     0,
     118,   278,     0,   102,   104,   134,     0,   135,   133,   106,
     108,   110,   100,     0,   275,   277,   160,     0,     0,     0,
       0,   175,     0,   192,    98,     0,   111,   114,   174,     0,
     101,   103,   139,     0,   105,   107,   109,     1,   276,     0,
      10,   164,     0,   161,     2,     7,     8,    11,    12,     0,
       0,     0,     9,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    18,     3,     4,     6,    31,    44,     0,    46,
      50,    53,    56,    62,    65,    67,    69,    71,    73,    75,
      97,     0,   148,   205,   150,     0,     0,     0,     0,   193,
     191,   190,     0,    99,     0,     0,   281,     0,   280,     0,
       0,     0,   173,     0,     0,   142,     0,   146,     0,     0,
       0,   156,     0,    35,     0,    32,    33,     0,     0,    44,
      77,    95,     0,     0,     0,    23,    24,    27,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,   147,     0,     0,   207,   204,   208,   149,   171,
     165,     0,   176,   194,   189,   112,   114,     0,   232,   113,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   259,     0,   257,   258,   244,   245,
       0,   255,   246,   247,   248,   249,   282,   279,   202,   187,
     201,     0,   196,   197,     0,     0,   177,    39,     0,     0,
       0,   137,   143,     0,   144,     0,   151,   155,     0,   158,
     163,   157,   162,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    79,     0,     0,     5,     0,    22,     0,    28,
      29,     0,    21,    47,    48,    49,    51,    52,    54,    55,
      59,    60,    61,    57,    58,    63,    64,    66,    68,    70,
      72,    74,     0,   226,     0,     0,     0,   210,    39,     0,
       0,   206,     0,     0,     0,     0,     0,   234,     0,     0,
       0,   238,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   272,   273,     0,   260,   254,   256,     0,
     199,   207,   200,   186,     0,     0,   188,     0,     0,   178,
     185,     0,   184,    39,     0,   138,   153,     0,   145,     0,
     159,    36,     0,    37,     0,    78,    96,     0,    45,    20,
       0,    19,     0,   227,   209,     0,     0,   211,   217,     0,
     216,     0,   228,     0,     0,   218,    39,     0,     0,     0,
       0,   241,     0,   230,   233,   237,   239,   250,     0,   252,
       0,     0,     0,     0,     0,     0,   270,   274,   195,   198,
     203,   180,     0,     0,   181,   183,   152,   154,     0,     0,
      14,     0,     0,    30,    76,   213,     0,     0,   215,   229,
       0,     0,   219,   225,     0,   224,     0,   242,   240,   231,
     236,     0,   251,     0,     0,     0,     0,     0,     0,   179,
     182,     0,     0,    13,     0,     0,    25,   212,   214,   221,
       0,     0,   222,   235,   261,   263,   264,     0,     0,     0,
       0,     0,    17,    15,    16,    26,   220,   223,     0,     0,
     268,     0,   266,     0,   262,   265,   269,   267
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -355,  -355,  -355,  -355,  -355,  -355,  -355,   -61,  -355,  -355,
    -355,   296,  -355,   -81,   104,   109,    66,   105,   215,   233,
     228,   236,   227,  -355,   -30,   -18,  -355,   -83,   -41,   -15,
      11,  -355,   285,  -355,   -42,  -355,  -355,   279,  -109,    13,
    -355,    60,  -355,   346,  -124,  -355,   -48,  -355,  -355,   -19,
     -51,   -50,  -117,  -108,  -355,    74,  -355,    72,   -90,  -173,
    -120,    53,  -354,  -355,    99,   -22,  -197,  -355,    30,  -355,
     201,  -196,  -355,  -355,  -355,  -355,   379,  -355,  -355
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    71,    94,    95,   419,   420,    96,   278,
     279,   149,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   150,   151,   273,   215,   111,    31,
     127,    55,    56,    33,    34,    35,    36,   134,   135,   113,
     245,   246,    37,    72,    73,    38,    39,    40,    41,   118,
      58,    59,   121,   304,   232,   233,   234,   421,   305,   187,
     317,   318,   319,   320,   321,    42,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    43,    44,    45,   129
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   114,   152,   120,   199,   119,   112,   112,   132,   117,
     329,    32,   311,    57,   239,   114,   252,   160,   110,    48,
     110,   112,   231,   186,    51,   242,    46,   122,    69,    70,
     183,   274,    70,   184,   164,   165,   357,   114,   441,    53,
      51,   137,   126,   112,    60,    61,    62,   274,   140,   123,
      64,    65,    66,   336,    32,    51,   141,   179,   358,   152,
      51,   152,   130,   185,   114,   131,   114,   310,    51,   407,
     112,   194,   112,   193,   183,   281,   136,   184,    49,    51,
     283,   284,   285,   119,    51,   114,   114,   128,    50,   168,
     169,   112,   112,   170,   114,    70,   114,   302,   250,   114,
     112,   441,   112,   196,   133,   112,   198,    52,   196,   110,
     216,   137,   137,   238,   226,    47,    53,   247,   348,   251,
     115,   116,   360,    52,   252,   182,   397,   188,   399,   335,
     256,   242,    53,   185,   405,    63,   119,   180,    52,   280,
     342,   230,   139,    52,    54,   243,   136,   136,   154,   155,
     156,   339,    53,   274,   184,   248,   175,   153,   371,   227,
      53,   324,   339,   249,   244,   184,   309,    52,   311,   243,
     166,   167,   110,     8,     9,    10,    53,   171,   172,   198,
     341,   312,   392,   274,   313,   455,   372,   119,   147,   376,
     393,   193,   114,   456,   230,   368,   388,   148,   112,   394,
     176,   442,   356,   178,   383,   216,   173,   174,   447,   448,
     274,   340,   275,   110,   253,   395,   254,   347,   137,   255,
     315,   354,   316,    53,   177,   157,   191,   161,   158,   345,
     159,   346,   162,   163,   290,   291,   292,   293,   294,   274,
     274,   443,   444,   400,   401,   402,   464,   465,   466,   274,
     452,   445,   453,   136,   181,   365,   366,   274,   119,   479,
     189,   274,   193,   481,   274,   119,   483,   431,   286,   287,
     190,   480,   440,   482,   390,   288,   289,   277,   295,   296,
     192,   484,   276,   282,   486,   110,   487,   314,   375,   341,
     132,   124,   381,   322,   323,   387,   325,   326,   327,   328,
     193,   198,   330,   331,    74,    75,    76,    77,    78,    79,
     332,    80,    81,   343,   344,   404,   114,   333,   417,   359,
     349,   463,   112,   230,   350,   361,   362,   363,   193,   110,
     412,   364,   369,   413,   370,   440,   119,   373,   247,    82,
     193,   374,   424,   377,    97,   378,    97,   389,   391,   198,
     230,   398,   423,   403,   406,   230,   410,   411,   426,   414,
     415,   427,   425,   467,   469,   471,   430,   367,   428,   429,
     436,   437,   446,   432,   198,   143,   145,   146,    83,   433,
      84,   438,   449,   193,   450,   451,   454,    85,   478,   457,
     297,   473,   458,   459,    97,    86,    87,    88,    89,    90,
      91,   462,   476,   477,   114,   299,   301,   195,   334,   298,
     112,   485,   240,   460,   300,   138,   461,   416,   409,   396,
     422,   338,    68,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   472,     0,    97,   474,   198,   257,   258,
     259,   260,   261,     0,     0,     0,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,     0,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,   272,     0,     0,   200,     0,   201,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    97,
      80,    81,     1,    82,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    82,   202,
     203,   204,    97,   205,   206,   207,   208,   209,   210,   211,
     212,    26,    83,    27,    84,    28,    29,    30,     0,     0,
       0,    85,     0,     0,     0,     0,     0,   125,   213,    86,
      87,    88,    89,    90,    91,     0,     0,    83,     0,    84,
       0,    97,   214,     0,     0,     0,    85,     0,     0,   315,
       0,   316,   197,   439,    86,    87,    88,    89,    90,    91,
       0,     0,     0,   200,     0,   201,    75,    76,    77,    78,
      79,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     1,
      82,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,    26,    83,
      27,    84,    28,    29,    30,     0,     0,     0,    85,     0,
       0,     0,     0,     0,   125,   337,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,   200,   214,
     201,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,   235,     0,     0,     0,     8,     9,    10,     0,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,     0,    83,     0,    84,    74,    75,    76,
      77,    78,    79,    85,    80,    81,     0,     0,    83,   125,
      84,    86,    87,    88,    89,    90,    91,    85,     0,     0,
       0,   236,     0,     0,   214,    86,   237,    88,    89,    90,
      91,     1,    82,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,    74,
      75,    76,    77,    78,    79,     0,    80,    81,     0,     0,
      26,    83,    27,    84,    28,    29,    30,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    82,     1,     0,     0,     0,     0,
       0,   214,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,    83,     0,    84,    27,     0,     0,    29,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     1,    82,     0,     0,
       0,     0,     0,   214,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,    74,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,     0,    83,    27,    84,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,    82,
       0,     0,   306,     0,     0,     0,     8,     9,    10,     0,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
      84,     0,     0,     0,     0,    82,     0,    85,   351,     0,
       0,   307,     8,     9,    10,    86,   308,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,    83,     0,    84,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,   352,     0,     0,
       0,    86,   353,    88,    89,    90,    91,    82,     0,     0,
     379,     0,     0,     0,     8,     9,    10,     0,    74,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,    84,     0,
       0,     0,     0,    82,     0,    85,   384,     0,     0,   380,
       8,     9,    10,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,    83,     0,    84,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,   385,     0,     0,     0,    86,
     386,    88,    89,    90,    91,    82,     0,     0,   434,     0,
       0,     0,     8,     9,    10,    74,    75,    76,    77,    78,
      79,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,    84,     0,     0,     0,
      82,     0,     0,    85,     0,     0,     0,   435,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,    84,    74,    75,    76,    77,    78,    79,    85,    80,
      81,   315,    82,   316,   197,   475,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     8,     9,    10,     0,     0,     0,
       0,    83,     0,    84,     0,     0,     0,     0,     0,     0,
      85,    82,     0,   315,     0,   316,   197,     0,    86,    87,
      88,    89,    90,    91,     0,     0,    83,     0,    84,    74,
      75,    76,    77,    78,    79,    85,    80,    81,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,     0,
      83,     0,    84,    74,    75,    76,    77,    78,    79,    85,
      80,    81,     0,     0,    82,   197,     0,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,    84,     0,     0,     0,     0,
       0,    82,    85,     0,     0,     0,     0,     0,   367,     0,
      86,    87,    88,    89,    90,    91,     0,    83,     0,    84,
       0,     0,     0,     0,     0,     0,    85,   468,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      83,     0,    84,     0,     0,     0,     0,     0,     0,    85,
     470,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    74,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
      74,    75,    76,    77,    78,    79,     1,    80,    81,     0,
       0,     0,    82,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,    82,     0,    83,     0,    84,
       0,     0,     0,     0,     0,     0,    85,    27,     0,     0,
      29,    83,     0,    84,    86,    87,    88,    89,    90,    91,
     142,     0,   241,    51,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    83,     0,    84,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     1,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,     0,
      28,     0,    30,     0,     0,     0,   339,   303,     0,   184,
       0,     0,     0,     0,     0,    53,     0,     1,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,     0,
      28,     0,    30,     0,     0,     0,     0,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,    29,    30,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
       0,    30,     0,     0,     0,   183,   303,     1,   184,     0,
       0,     0,     0,     0,    53,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   355,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,    29,    30,     0,   124,
       0,     0,     0,     0,     0,     0,     1,   125,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       1,   125,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,     0,    30,     0,     0,     0,     1,
     382,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,    29,    30,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   408,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,     1,
      30,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,    26,     0,
      27,     0,    28,     0,    30,     8,     9,    10,    11,    12,
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
      48,    49,    85,    53,   124,    53,    48,    49,    59,    50,
     207,     0,   185,    32,   131,    63,   140,    98,    48,    86,
      50,    63,   130,   113,     3,   134,     3,    85,    92,     3,
      86,    85,     3,    89,    96,    97,    85,    85,   392,    95,
       3,    63,    57,    85,    33,    34,     3,    85,    85,   107,
      39,    40,    41,   107,    43,     3,    93,    26,   107,   142,
       3,   144,    86,   113,   112,    89,   114,   184,     3,   107,
     112,   121,   114,   121,    86,   158,    63,    89,    86,     3,
     161,   162,   163,   131,     3,   133,   134,    57,    86,    14,
      15,   133,   134,    18,   142,     3,   144,   180,   139,   147,
     142,   455,   144,   122,    92,   147,   124,    86,   127,   139,
     125,   133,   134,   131,   129,    92,    95,   136,   235,    93,
      48,    49,    93,    86,   248,   112,   323,   114,   325,   212,
     148,   240,    95,   183,   330,    92,   184,   106,    86,   157,
     230,   130,    84,    86,   107,    88,   133,   134,     9,    10,
      11,    86,    95,    85,    89,    85,    94,    85,    90,   129,
      95,   202,    86,    93,   107,    89,   184,    86,   341,    88,
      12,    13,   202,    45,    46,    47,    95,   102,   103,   197,
     230,    86,    85,    85,    89,    85,    88,   235,    86,   306,
      93,   239,   240,    93,   183,   276,   313,    86,   240,   319,
     104,   398,   243,    25,   312,   220,    16,    17,   404,   405,
      85,   230,    87,   243,   142,    84,   144,   235,   240,   147,
      89,   239,    91,    95,   105,    86,    85,    95,    89,    85,
      91,    87,   100,   101,   168,   169,   170,   171,   172,    85,
      85,    87,    87,   326,   327,   328,   443,   444,   445,    85,
      85,    87,    87,   240,    87,   273,   274,    85,   306,    87,
      87,    85,   310,    87,    85,   313,    87,   384,   164,   165,
      87,   468,   392,   470,   315,   166,   167,     3,   173,   174,
      87,   478,    87,     3,   481,   315,   483,     6,   306,   339,
     341,    84,   310,   107,    88,   313,    88,    86,    86,    86,
     348,   319,    86,     3,     3,     4,     5,     6,     7,     8,
     107,    10,    11,    87,    85,   330,   364,   107,   359,    88,
      90,   441,   364,   312,    90,    87,    87,    87,   376,   359,
     348,    85,    87,   351,    85,   455,   384,    87,   357,    38,
     388,    87,   372,    90,    48,    90,    50,    87,     3,   367,
     339,    88,   370,    69,   107,   344,     3,    90,   376,    90,
      90,   379,    90,   446,   447,   448,   384,    92,    90,    87,
     388,   107,    86,    90,   392,    79,    80,    81,    77,    90,
      79,    90,    90,   431,    90,    88,    88,    86,    67,    90,
     175,   452,    90,    90,    98,    94,    95,    96,    97,    98,
      99,    90,    90,    90,   452,   177,   179,   122,   107,   176,
     452,   107,   133,   431,   178,    69,   434,   357,   344,   320,
     367,   220,    43,   441,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,    -1,   139,   454,   455,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    -1,    -1,    84,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,   243,
      10,    11,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    38,    64,
      65,    66,   276,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    77,    -1,    79,
      -1,   315,   107,    -1,    -1,    -1,    86,    -1,    -1,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   359,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,     1,   107,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    -1,    79,     3,     4,     5,
       6,     7,     8,    86,    10,    11,    -1,    -1,    77,    92,
      79,    94,    95,    96,    97,    98,    99,    86,    -1,    -1,
      -1,    90,    -1,    -1,   107,    94,    95,    96,    97,    98,
      99,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    38,    37,    -1,    -1,    -1,    -1,
      -1,   107,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    77,    -1,    79,    78,    -1,    -1,    81,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,    37,    38,    -1,    -1,
      -1,    -1,    -1,   107,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    38,    -1,    86,    41,    -1,
      -1,    90,    45,    46,    47,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    -1,    38,    -1,    86,    41,    -1,    -1,    90,
      45,    46,    47,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,    38,    -1,    -1,    41,    -1,
      -1,    -1,    45,    46,    47,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      38,    -1,    -1,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,     3,     4,     5,     6,     7,     8,    86,    10,
      11,    89,    38,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    38,    -1,    89,    -1,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,    -1,    -1,    77,    -1,    79,     3,
       4,     5,     6,     7,     8,    86,    10,    11,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    -1,
      77,    -1,    79,     3,     4,     5,     6,     7,     8,    86,
      10,    11,    -1,    -1,    38,    92,    -1,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    38,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      94,    95,    96,    97,    98,    99,    -1,    77,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
       3,     4,     5,     6,     7,     8,    37,    10,    11,    -1,
      -1,    -1,    38,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    38,    -1,    77,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    78,    -1,    -1,
      81,    77,    -1,    79,    94,    95,    96,    97,    98,    99,
      86,    -1,    93,     3,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,
      80,    -1,    82,    -1,    -1,    -1,    86,    87,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    37,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    78,    -1,    80,    81,    82,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      -1,    82,    -1,    -1,    -1,    86,    87,    37,    89,    -1,
      -1,    -1,    -1,    -1,    95,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    93,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    81,    82,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    92,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    92,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    78,    -1,    80,    -1,    82,    -1,    -1,    -1,    37,
      87,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      78,    -1,    80,    81,    82,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    37,
      82,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    76,    -1,
      78,    -1,    80,    -1,    82,    45,    46,    47,    48,    49,
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
      82,   137,   138,   141,   142,   143,   144,   150,   153,   154,
     155,   156,   173,   183,   184,   185,     3,    92,    86,    86,
      86,     3,    86,    95,   107,   139,   140,   157,   158,   159,
     138,   138,     3,    92,   138,   138,   138,     0,   184,    92,
       3,   111,   151,   152,     3,     4,     5,     6,     7,     8,
      10,    11,    38,    77,    79,    86,    94,    95,    96,    97,
      98,    99,   109,   110,   112,   113,   116,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   136,   142,   147,   154,   165,   165,   136,   157,   154,
     159,   160,    85,   107,    84,    92,   137,   138,   176,   186,
      86,    89,   158,    92,   145,   146,   147,   173,   151,    84,
      85,    93,    86,   119,    86,   119,   119,    86,    86,   119,
     132,   133,   135,   165,     9,    10,    11,    86,    89,    91,
     121,    95,   100,   101,    96,    97,    12,    13,    14,    15,
      18,   102,   103,    16,    17,    94,   104,   105,    25,    26,
     106,    87,   147,    86,    89,   159,   166,   167,   147,    87,
      87,    85,    87,   154,   159,   140,   157,    92,   133,   168,
       1,     3,    64,    65,    66,    68,    69,    70,    71,    72,
      73,    74,    75,    93,   107,   135,   137,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   137,   176,     3,    87,
     138,   161,   162,   163,   164,    41,    90,    95,   133,   160,
     145,    93,   146,    88,   107,   148,   149,   157,    85,    93,
     136,    93,   152,   165,   165,   165,   133,    19,    20,    21,
      22,    23,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    84,   134,    85,    87,    87,     3,   117,   118,
     133,   135,     3,   121,   121,   121,   122,   122,   123,   123,
     124,   124,   124,   124,   124,   125,   125,   126,   127,   128,
     129,   130,   135,    87,   161,   166,    41,    90,    95,   133,
     160,   167,    86,    89,     6,    89,    91,   168,   169,   170,
     171,   172,   107,    88,   136,    88,    86,    86,    86,   174,
      86,     3,   107,   107,   107,   135,   107,    93,   178,    86,
     157,   159,   166,    87,    85,    85,    87,   133,   160,    90,
      90,    41,    90,    95,   133,    93,   136,    85,   107,    88,
      93,    87,    87,    87,    85,   133,   133,    92,   121,    87,
      85,    90,    88,    87,    87,   133,   160,    90,    90,    41,
      90,   133,    87,   161,    41,    90,    95,   133,   160,    87,
     136,     3,    85,    93,   168,    84,   172,   174,    88,   174,
     135,   135,   135,    69,   137,   179,   107,   107,    63,   163,
       3,    90,   133,   133,    90,    90,   149,   136,    65,   114,
     115,   165,   169,   133,   132,    90,   133,   133,    90,    87,
     133,   160,    90,    90,    41,    90,   133,   107,    90,    93,
     168,   170,   174,    87,    87,    87,    86,   179,   179,    90,
      90,    88,    85,    87,    88,    85,    93,    90,    90,    90,
     133,   133,    90,   168,   174,   174,   174,   135,    87,   135,
      87,   135,   133,   115,   133,    93,    90,    90,    67,    87,
     174,    87,   174,    87,   174,   107,   174,   174
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   110,   110,   110,
     111,   112,   112,   113,   114,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     120,   120,   120,   120,   121,   121,   122,   122,   122,   122,
     123,   123,   123,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   126,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   136,   137,   137,
     137,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   139,   139,   140,   140,   141,   141,   141,   141,   141,
     141,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   143,   143,   143,
     144,   144,   145,   145,   146,   146,   146,   147,   147,   147,
     147,   148,   148,   149,   149,   149,   150,   150,   150,   150,
     150,   151,   151,   152,   152,   153,   154,   154,   154,   155,
     155,   156,   156,   157,   157,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   159,
     159,   159,   159,   160,   160,   161,   161,   162,   162,   163,
     163,   163,   164,   164,   165,   165,   166,   166,   166,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     168,   168,   168,   169,   169,   169,   169,   170,   171,   171,
     172,   172,   173,   174,   174,   174,   174,   174,   174,   174,
     175,   175,   175,   176,   176,   177,   177,   178,   178,   179,
     179,   180,   180,   180,   181,   181,   181,   181,   181,   181,
     182,   182,   182,   182,   182,   183,   183,   184,   184,   185,
     185,   186,   186
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       4,     3,     3,     2,     2,     6,     7,     0,     1,     1,
       3,     1,     2,     2,     2,     2,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     2,
       1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
       1,     1,     3,     2,     3,     1,     4,     5,     5,     6,
       2,     1,     3,     3,     1,     4,     1,     1,     1,     1,
       1,     4,     4,     2,     1,     1,     3,     3,     4,     6,
       5,     5,     6,     5,     4,     4,     4,     3,     4,     3,
       2,     2,     1,     1,     2,     3,     1,     1,     3,     2,
       2,     1,     1,     3,     2,     1,     2,     1,     1,     3,
       2,     3,     5,     4,     5,     4,     3,     3,     3,     4,
       6,     5,     5,     6,     4,     4,     2,     3,     3,     4,
       3,     4,     1,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     7,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     1,     2,     1,     1,     1,
       2,     5,     7,     5,     5,     7,     6,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     1,     2
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
#line 71 "yapl.y"
                     {int_consts++;}
#line 2013 "yapl.tab.c"
    break;

  case 77: /* assignment_expression: conditional_expression  */
#line 210 "yapl.y"
                                 {
		sprintf(derivations[dtop++], "assignment_expression -> conditional_expression");
	}
#line 2021 "yapl.tab.c"
    break;

  case 78: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 213 "yapl.y"
                                                                     {
		sprintf(derivations[dtop++], "assignment_expression -> unary_expression assignment_operator assignment_expression");
	}
#line 2029 "yapl.tab.c"
    break;

  case 95: /* expression: assignment_expression  */
#line 238 "yapl.y"
                                {
		sprintf(derivations[dtop++], "expression -> assignment_expression");
	}
#line 2037 "yapl.tab.c"
    break;

  case 96: /* expression: expression ',' assignment_expression  */
#line 241 "yapl.y"
                                               {
		sprintf(derivations[dtop++], "expression -> expression , assignment_expression");
	}
#line 2045 "yapl.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers ';'  */
#line 251 "yapl.y"
                                     {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers ;");
	}
#line 2053 "yapl.tab.c"
    break;

  case 99: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 254 "yapl.y"
                                                          {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers init_declarator_list ;");
	}
#line 2061 "yapl.tab.c"
    break;

  case 100: /* declaration: static_assert_declaration  */
#line 257 "yapl.y"
                                    {
		sprintf(derivations[dtop++], "declaration -> static_assert_declaration");
	}
#line 2069 "yapl.tab.c"
    break;

  case 173: /* declarator: pointer direct_declarator  */
#line 393 "yapl.y"
                                    {pointer_decls++;}
#line 2075 "yapl.tab.c"
    break;

  case 243: /* statement: error ';'  */
#line 515 "yapl.y"
                    {
        printf("Recovered from error at line %d near token '%s'\n", line_no, yytext);
        yyerrok;
    }
#line 2084 "yapl.tab.c"
    break;

  case 244: /* statement: labeled_statement  */
#line 519 "yapl.y"
                            {
		sprintf(derivations[dtop++], "statement -> labeled_statement");
	}
#line 2092 "yapl.tab.c"
    break;

  case 245: /* statement: compound_statement  */
#line 522 "yapl.y"
                             {
		sprintf(derivations[dtop++], "statement -> compound_statement");
	}
#line 2100 "yapl.tab.c"
    break;

  case 246: /* statement: expression_statement  */
#line 525 "yapl.y"
                               {
		sprintf(derivations[dtop++], "statement -> expression_statement");
	}
#line 2108 "yapl.tab.c"
    break;

  case 247: /* statement: selection_statement  */
#line 528 "yapl.y"
                              {
		sprintf(derivations[dtop++], "statement -> selection_statement");
	}
#line 2116 "yapl.tab.c"
    break;

  case 248: /* statement: iteration_statement  */
#line 531 "yapl.y"
                              {
		sprintf(derivations[dtop++], "statement -> iteration_statement");
	}
#line 2124 "yapl.tab.c"
    break;

  case 249: /* statement: jump_statement  */
#line 534 "yapl.y"
                         {
		sprintf(derivations[dtop++], "statement -> jump_statement");
	}
#line 2132 "yapl.tab.c"
    break;

  case 253: /* compound_statement: '{' '}'  */
#line 546 "yapl.y"
                  {
		sprintf(derivations[dtop++], "compound_statement -> { }");
	}
#line 2140 "yapl.tab.c"
    break;

  case 254: /* compound_statement: '{' block_item_list '}'  */
#line 549 "yapl.y"
                                  {
		sprintf(derivations[dtop++], "compound_statement -> { block_item_list }");
	}
#line 2148 "yapl.tab.c"
    break;

  case 255: /* block_item_list: block_item  */
#line 555 "yapl.y"
                     {
		sprintf(derivations[dtop++], "block_item_list -> block_item");
	}
#line 2156 "yapl.tab.c"
    break;

  case 256: /* block_item_list: block_item_list block_item  */
#line 558 "yapl.y"
                                     {
		sprintf(derivations[dtop++], "block_item_list -> block_item_list block_item");
	}
#line 2164 "yapl.tab.c"
    break;

  case 257: /* block_item: declaration  */
#line 564 "yapl.y"
                      {
		sprintf(derivations[dtop++], "block_item -> declaration");
	}
#line 2172 "yapl.tab.c"
    break;

  case 258: /* block_item: statement  */
#line 567 "yapl.y"
                    {
		sprintf(derivations[dtop++], "block_item -> statement");
	}
#line 2180 "yapl.tab.c"
    break;

  case 259: /* expression_statement: ';'  */
#line 573 "yapl.y"
              {
		sprintf(derivations[dtop++], "expression_statement -> ;");
	}
#line 2188 "yapl.tab.c"
    break;

  case 260: /* expression_statement: expression ';'  */
#line 576 "yapl.y"
                         {
		sprintf(derivations[dtop++], "expression_statement -> expression ;");
	}
#line 2196 "yapl.tab.c"
    break;

  case 261: /* selection_statement: IF '(' expression ')' statement  */
#line 582 "yapl.y"
                                                    {
		sprintf(derivations[dtop++], "selection_statement -> IF ( expression ) statement");
		ifs_wo_else++;
	}
#line 2205 "yapl.tab.c"
    break;

  case 262: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 586 "yapl.y"
                                                         {
		sprintf(derivations[dtop++], "selection_statement -> IF ( expression ) statement ELSE statement");
	}
#line 2213 "yapl.tab.c"
    break;

  case 263: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 589 "yapl.y"
                                              {
		sprintf(derivations[dtop++], "selection_statement -> SWITCH ( expression ) statement");
	}
#line 2221 "yapl.tab.c"
    break;

  case 275: /* translation_unit: external_declaration  */
#line 612 "yapl.y"
                               {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> external_declaration");
	}
#line 2230 "yapl.tab.c"
    break;

  case 276: /* translation_unit: translation_unit external_declaration  */
#line 616 "yapl.y"
                                                {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> translation_unit external_declaration");
	}
#line 2239 "yapl.tab.c"
    break;

  case 277: /* external_declaration: function_definition  */
#line 623 "yapl.y"
                              {func_definitions++;}
#line 2245 "yapl.tab.c"
    break;

  case 279: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 628 "yapl.y"
                                                                                {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator declaration_list compound_statement");
	}
#line 2253 "yapl.tab.c"
    break;

  case 280: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 631 "yapl.y"
                                                               {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator compound_statement");
	}
#line 2261 "yapl.tab.c"
    break;


#line 2265 "yapl.tab.c"

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

#line 641 "yapl.y"

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

	return(0);
}



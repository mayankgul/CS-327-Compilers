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

char derivations[1000][200];
int dtop = 0;

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

#line 91 "yapl.tab.c"

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
  YYSYMBOL_158_1 = 158,                    /* $@1  */
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
  YYSYMBOL_selection_statement = 181,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 182,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 183,           /* jump_statement  */
  YYSYMBOL_translation_unit = 184,         /* translation_unit  */
  YYSYMBOL_external_declaration = 185,     /* external_declaration  */
  YYSYMBOL_function_definition = 186,      /* function_definition  */
  YYSYMBOL_declaration_list = 187          /* declaration_list  */
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
#define YYLAST   2403

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  283
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
       0,    57,    57,    58,    59,    60,    61,    65,    66,    67,
      71,    75,    76,    80,    84,    85,    89,    90,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   106,   107,   111,
     112,   116,   117,   118,   119,   120,   121,   122,   126,   127,
     128,   129,   130,   131,   135,   136,   140,   141,   142,   143,
     147,   148,   149,   153,   154,   155,   159,   160,   161,   162,
     163,   164,   168,   169,   170,   174,   175,   179,   180,   184,
     185,   189,   190,   194,   195,   199,   200,   204,   207,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   232,   235,   241,   245,   248,
     251,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   270,   271,   275,   276,   280,   281,   282,   283,   284,
     285,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   308,   309,   310,
     314,   315,   319,   320,   324,   325,   326,   330,   331,   332,
     333,   337,   338,   342,   343,   344,   348,   349,   350,   351,
     352,   356,   357,   361,   362,   366,   370,   371,   372,   373,
     377,   378,   382,   383,   387,   387,   388,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   409,   410,   411,   412,   416,   417,   422,   423,   427,
     428,   432,   433,   434,   438,   439,   443,   444,   448,   449,
     450,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   478,   479,   480,   484,   485,   486,   487,   491,
     495,   496,   500,   501,   505,   509,   512,   515,   518,   521,
     524,   530,   531,   532,   536,   539,   545,   548,   554,   557,
     563,   566,   572,   575,   579,   585,   586,   587,   588,   589,
     590,   594,   595,   596,   597,   598,   602,   606,   613,   614,
     618,   621,   627,   628
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
  "alignment_specifier", "declarator", "$@1", "direct_declarator",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "static_assert_declaration", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-313)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-175)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2126,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,    22,   -32,   -21,  -313,   -15,
    -313,  -313,    37,  2216,  2216,  -313,    32,  -313,  -313,  2216,
    2216,  2216,  -313,  1768,  -313,  -313,   -58,   124,   881,  2325,
    1519,  -313,    33,   129,  -313,   -46,  -313,  1969,   -36,  -313,
    -313,  -313,    39,  2254,  -313,  -313,  -313,  -313,  -313,   124,
    -313,    61,   -62,  -313,  -313,  -313,  -313,  -313,  -313,  1533,
    1582,  1582,  -313,    91,   104,   881,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,   300,  -313,  1519,  -313,
     116,   -64,   172,   154,   185,   119,   118,   128,   200,    30,
    -313,   142,  2325,    93,  2325,   164,   174,   180,   189,  -313,
    -313,  -313,   129,    33,  -313,  1382,   489,  -313,    37,  -313,
    2023,  1705,   943,    25,  2254,  1865,  -313,    27,  -313,   -47,
    1519,    11,  -313,   881,  -313,   881,  -313,  -313,  2325,  1519,
     614,  -313,  -313,    79,   192,   264,  -313,  -313,  1519,  1519,
     280,  -313,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  -313,  -313,  1814,   989,    97,  -313,   120,  -313,
    -313,  -313,   278,  -313,  -313,  -313,  -313,   201,  1357,  -313,
    -313,   198,  1519,   206,   203,   209,   211,   775,   212,   298,
     195,   196,   391,  -313,  -313,   -26,  -313,  -313,  -313,  -313,
     615,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
      52,   219,   222,  -313,   134,  1260,  -313,   223,   224,  1051,
     -36,  1914,  -313,  -313,  1519,  -313,   -18,  -313,   227,    24,
    -313,  -313,  -313,  -313,   230,   233,   236,   239,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  1519,  1519,  -313,  1406,  -313,   238,
     241,  -313,     0,  -313,  -313,  -313,  -313,   116,   116,   -64,
     -64,   172,   172,   172,   172,   172,   154,   154,   185,   119,
     118,   128,   200,   130,  -313,   243,   244,  1260,  -313,   242,
     247,  1097,   120,  2077,  1159,   251,  1519,   331,  -313,    63,
    1382,   121,  -313,   775,   254,   775,  1519,  1519,  1519,   270,
     713,   237,  -313,  -313,  -313,    73,  -313,  -313,  -313,  1645,
    -313,    60,  -313,  -313,  2172,   340,  -313,   255,  1260,  -313,
    -313,  1519,  -313,   256,   259,  -313,  -313,    65,  -313,  1519,
    -313,   258,   258,  -313,  2291,  -313,  -313,  1357,  -313,  -313,
    1519,  -313,  1519,  -313,  -313,   263,  1260,  -313,  -313,  1519,
    -313,   265,  -313,   269,  1260,  -313,   267,   272,  1205,   260,
     276,  -313,   514,  -313,  -313,  -313,  -313,  -313,   775,  -313,
     141,   145,   161,   282,   818,   818,  -313,  -313,  -313,  -313,
    -313,  -313,   283,   286,  -313,  -313,  -313,  -313,   281,   162,
    -313,   284,    88,  -313,  -313,  -313,   288,   289,  -313,  -313,
     290,  1260,  -313,  -313,  1519,  -313,   291,  -313,  -313,  -313,
    -313,  1382,  -313,   775,   775,   775,  1519,  1420,  1483,  -313,
    -313,  1519,  2291,  -313,  1519,  1305,  -313,  -313,  -313,  -313,
     292,   294,  -313,  -313,   303,  -313,  -313,   165,   775,   173,
     775,   177,  -313,  -313,  -313,  -313,  -313,  -313,   775,   285,
    -313,   775,  -313,   775,  -313,  -313,  -313,  -313
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   136,   115,   116,   117,   119,   120,   170,   166,   167,
     168,   130,   122,   123,   124,   125,   128,   129,   126,   127,
     121,   131,   132,   140,   141,     0,     0,   169,   171,     0,
     118,   279,     0,   102,   104,   134,     0,   135,   133,   106,
     108,   110,   100,     0,   276,   278,   160,     0,     0,     0,
       0,   177,     0,   194,    98,     0,   111,   114,   176,   174,
     101,   103,   139,     0,   105,   107,   109,     1,   277,     0,
      10,   164,     0,   161,     2,     7,     8,    11,    12,     0,
       0,     0,     9,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    18,     3,     4,     6,    31,    44,     0,    46,
      50,    53,    56,    62,    65,    67,    69,    71,    73,    75,
      97,     0,   148,   207,   150,     0,     0,     0,     0,   169,
     195,   193,   192,     0,    99,     0,     0,   282,     0,   281,
       0,     0,     0,     0,     0,     0,   142,     0,   146,     0,
       0,     0,   156,     0,    35,     0,    32,    33,     0,     0,
      44,    77,    95,     0,     0,     0,    23,    24,    27,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,   147,     0,     0,   209,   206,   210,   149,
     172,   165,     0,   178,   196,   191,   112,   114,     0,   234,
     113,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   260,     0,   258,   259,   245,   246,
       0,   256,   247,   248,   249,   250,   283,   280,   204,   189,
     203,     0,   198,   199,     0,     0,   179,    39,     0,     0,
     175,     0,   137,   143,     0,   144,     0,   151,   155,     0,
     158,   163,   157,   162,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    79,     0,     0,     5,     0,    22,     0,
      28,    29,     0,    21,    47,    48,    49,    51,    52,    54,
      55,    59,    60,    61,    57,    58,    63,    64,    66,    68,
      70,    72,    74,     0,   228,     0,     0,     0,   212,    39,
       0,     0,   208,     0,     0,     0,     0,     0,   236,     0,
       0,     0,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,   273,   274,     0,   261,   255,   257,     0,
     201,   209,   202,   188,     0,     0,   190,     0,     0,   180,
     187,     0,   186,    39,     0,   138,   153,     0,   145,     0,
     159,    36,     0,    37,     0,    78,    96,     0,    45,    20,
       0,    19,     0,   229,   211,     0,     0,   213,   219,     0,
     218,     0,   230,     0,     0,   220,    39,     0,     0,     0,
       0,   243,     0,   232,   235,   239,   241,   251,     0,   253,
       0,     0,     0,     0,     0,     0,   271,   275,   197,   200,
     205,   182,     0,     0,   183,   185,   152,   154,     0,     0,
      14,     0,     0,    30,    76,   215,     0,     0,   217,   231,
       0,     0,   221,   227,     0,   226,     0,   244,   242,   233,
     238,     0,   252,     0,     0,     0,     0,     0,     0,   181,
     184,     0,     0,    13,     0,     0,    25,   214,   216,   223,
       0,     0,   224,   237,   263,   264,   265,     0,     0,     0,
       0,     0,    17,    15,    16,    26,   222,   225,     0,     0,
     269,     0,   267,     0,   262,   266,   270,   268
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -313,  -313,  -313,  -313,  -313,  -313,  -313,   -67,  -313,  -313,
    -313,   279,  -313,   -54,    76,   105,    66,   107,   214,   210,
     215,   221,   208,  -313,   -24,   -80,  -313,   -83,   -41,   -53,
       8,  -313,   293,  -313,   -42,  -313,  -313,   271,  -115,    28,
    -313,    46,  -313,   337,  -129,  -313,   -48,  -313,  -313,   -16,
    -313,   274,   -34,  -110,  -113,  -313,    64,  -313,     9,  -100,
    -176,  -122,    42,  -312,  -313,    90,   -52,  -190,  -313,   -28,
    -313,   193,  -234,  -313,  -313,  -313,  -313,   369,  -313,  -313
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    71,    94,    95,   419,   420,    96,   279,
     280,   150,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   151,   152,   274,   215,   111,    31,
     128,    55,    56,    33,    34,    35,    36,   135,   136,   113,
     246,   247,    37,    72,    73,    38,    39,    40,    41,   118,
     133,    58,    59,   122,   305,   232,   233,   234,   421,   306,
     188,   318,   319,   320,   321,   322,    42,   217,   218,   219,
     220,   221,   222,   223,   224,   225,    43,    44,    45,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   114,   153,   200,   127,   120,   112,   112,    32,   117,
     312,   138,   253,   187,    70,   114,    57,   329,   231,   121,
     243,   112,   239,   141,   110,    46,   110,    70,    51,   129,
      51,   142,   165,   166,    69,    62,    51,   114,   249,   123,
      51,    60,    61,   112,   161,   199,   250,    64,    65,    66,
     131,    32,   238,   132,    48,    51,   180,   115,   116,   275,
     153,   124,   153,  -174,   114,    49,   114,   357,    51,   257,
     112,    50,   112,   216,   194,   311,   282,   226,   281,   186,
     441,   336,   138,   138,   120,   275,   114,   114,   195,   358,
     371,   137,   112,   112,   154,   114,   405,   114,   303,   251,
     114,   112,   227,   112,   252,   310,   112,   197,   284,   285,
     286,    52,   197,    52,    47,   244,   110,   360,   199,    52,
     253,   248,    53,    52,    63,   348,   243,    70,    53,   335,
     342,   134,    53,   397,   245,   399,   181,   120,   339,   230,
     183,   185,   189,   441,    54,   140,   184,    53,   392,   185,
     186,    52,   254,   244,   255,   347,   393,   256,   275,   354,
      53,   324,   137,   137,   275,   312,   276,   216,   169,   170,
     447,   448,   171,   455,     8,     9,    10,   148,   110,   184,
     407,   456,   185,   184,   167,   168,   185,   120,    53,   138,
     149,   194,   230,   114,   365,   366,   341,   376,   394,   112,
     383,   174,   175,   356,   388,   395,   313,   119,   442,   314,
     316,   162,   317,   176,   340,   275,   163,   164,   372,   345,
     110,   346,   177,   368,    53,   179,   275,   375,   443,   182,
     275,   381,   444,   178,   387,   291,   292,   293,   294,   295,
     199,   287,   288,   400,   401,   402,   275,   452,   445,   453,
     275,   190,   479,   464,   465,   466,   172,   173,   275,   120,
     481,   191,   275,   194,   483,   192,   120,   278,   412,   137,
     440,   413,   289,   290,   431,   390,   193,   404,   480,   277,
     482,   296,   297,   283,   315,   125,   323,   199,   484,   326,
     423,   486,   110,   487,   325,   327,   426,   328,   330,   427,
     194,   331,   332,   333,   430,   341,   343,   344,   436,   155,
     156,   157,   199,   349,   350,   359,   114,   361,   417,   463,
     362,   230,   112,   363,   364,   369,   370,    97,   194,    97,
     373,   374,   377,   440,   391,   110,   120,   378,   389,   403,
     194,   248,   398,   410,   406,   411,   414,   230,   424,   415,
     367,   460,   230,   425,   461,   428,   429,   432,   144,   146,
     147,   199,   433,   467,   469,   471,   438,   437,   446,   451,
     478,   472,   454,   449,   474,   199,   450,    97,   457,   458,
     459,   462,   476,   194,   477,   473,   158,   299,   302,   159,
     298,   160,   485,   300,    74,    75,    76,    77,    78,    79,
     301,    80,    81,   416,   114,   241,   139,   240,   409,   422,
     112,   396,    68,   338,     0,     0,   196,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
      84,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,    97,     0,     0,     0,    86,    87,    88,    89,    90,
      91,     0,   201,    75,    76,    77,    78,    79,   334,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    97,    80,    81,     1,    82,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    82,   202,   203,   204,    97,   205,   206,   207,
     208,   209,   210,   211,   212,    26,    83,    27,    84,    28,
      29,    30,     0,     0,     0,    85,     0,     0,     0,     0,
       0,   126,   213,    86,    87,    88,    89,    90,    91,     0,
       0,    83,     0,    84,     0,    97,   214,     0,     0,     0,
      85,     0,     0,   316,     0,   317,   198,   439,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,   201,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,     0,   258,   259,   260,   261,   262,    97,     0,
       0,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,    97,     1,    82,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,    26,    83,    27,    84,    28,    29,    30,   273,     0,
       0,    85,     0,     0,     0,     0,     0,   126,   337,    86,
      87,    88,    89,    90,    91,     0,    74,    75,    76,    77,
      78,    79,   214,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    82,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,   201,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,    26,
      83,    27,    84,    28,    29,    30,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    82,     0,     0,     0,     0,     0,     0,
     214,    74,    75,    76,    77,    78,    79,     0,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,     0,    83,     0,    84,     0,    82,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,   126,     0,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,   214,     0,    74,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,    83,     0,    84,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,     1,    82,
       0,     0,     0,     0,     0,   214,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,     0,    83,    27,
      84,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    82,     0,     0,   235,     0,     0,     0,     8,     9,
      10,     0,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,   119,    84,     0,     0,     0,     0,    82,     0,    85,
     307,     0,     0,   236,     8,     9,    10,    86,   237,    88,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,     0,    83,   119,    84,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,   308,
       0,     0,     0,    86,   309,    88,    89,    90,    91,    82,
       0,     0,   351,     0,     0,     0,     8,     9,    10,     0,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,   119,
      84,     0,     0,     0,     0,    82,     0,    85,   379,     0,
       0,   352,     8,     9,    10,    86,   353,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,    83,   119,    84,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,   380,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    82,     0,     0,
     384,     0,     0,     0,     8,     9,    10,     0,    74,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,   119,    84,     0,
       0,     0,     0,    82,     0,    85,   434,     0,     0,   385,
       8,     9,    10,    86,   386,    88,    89,    90,    91,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,   119,    84,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,   435,     0,     0,    82,    86,
      87,    88,    89,    90,    91,     8,     9,    10,    74,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,   119,    84,
       0,     0,     0,    82,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,    84,    74,    75,    76,    77,    78,
      79,    85,    80,    81,   316,    82,   317,   198,   475,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,     0,    80,    81,     0,     0,
      82,     0,     0,    74,    75,    76,    77,    78,    79,     0,
      80,    81,     0,     0,    83,     0,    84,     0,     0,     0,
       0,     0,     0,    85,    82,     0,   316,     0,   317,   198,
       0,    86,    87,    88,    89,    90,    91,     0,    82,    83,
       0,    84,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,   198,     0,    86,    87,    88,    89,
      90,    91,     0,    83,     0,    84,    74,    75,    76,    77,
      78,    79,    85,    80,    81,     0,     0,    83,   367,    84,
      86,    87,    88,    89,    90,    91,    85,   468,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
       0,    82,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
      83,     0,    84,     0,     0,     0,     0,     0,     0,    85,
     470,    82,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,    74,    75,    76,    77,    78,
      79,     0,    80,    81,     0,     0,    83,     0,    84,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
      83,     0,    84,    86,    87,    88,    89,    90,    91,   143,
      82,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,    84,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,     0,
       0,   339,   304,     0,   185,     0,     0,     0,     0,     0,
      53,     0,     1,     0,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,     0,     0,
       0,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,    29,
      30,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,     0,    28,     0,    30,     0,     0,     0,
     184,   304,     1,   185,     0,     0,     0,     0,     0,    53,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,    29,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,   242,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,   355,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
      29,    30,     0,   125,     0,     0,     0,     0,     0,     0,
       1,   126,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     1,   126,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,     0,    30,
       0,     0,     0,     1,   382,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,    29,    30,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   408,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     1,    30,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,    26,     0,    27,     0,    28,     0,    30,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,    27,     0,     0,    29,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,   418,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,    27,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      48,    49,    85,   125,    57,    53,    48,    49,     0,    50,
     186,    63,   141,   113,     3,    63,    32,   207,   131,    53,
     135,    63,   132,    85,    48,     3,    50,     3,     3,    57,
       3,    93,    96,    97,    92,     3,     3,    85,    85,    85,
       3,    33,    34,    85,    98,   125,    93,    39,    40,    41,
      86,    43,   132,    89,    86,     3,    26,    48,    49,    85,
     143,   107,   145,     3,   112,    86,   114,    85,     3,   149,
     112,    86,   114,   126,   122,   185,   159,   130,   158,   113,
     392,   107,   134,   135,   132,    85,   134,   135,   122,   107,
      90,    63,   134,   135,    85,   143,   330,   145,   181,   140,
     148,   143,   130,   145,    93,   185,   148,   123,   162,   163,
     164,    86,   128,    86,    92,    88,   140,    93,   198,    86,
     249,   137,    95,    86,    92,   235,   241,     3,    95,   212,
     230,    92,    95,   323,   107,   325,   106,   185,    86,   131,
     112,    89,   114,   455,   107,    84,    86,    95,    85,    89,
     184,    86,   143,    88,   145,   235,    93,   148,    85,   239,
      95,   202,   134,   135,    85,   341,    87,   220,    14,    15,
     404,   405,    18,    85,    45,    46,    47,    86,   202,    86,
     107,    93,    89,    86,    12,    13,    89,   235,    95,   241,
      86,   239,   184,   241,   274,   275,   230,   307,   320,   241,
     313,    16,    17,   244,   314,    84,    86,    78,   398,    89,
      89,    95,    91,    94,   230,    85,   100,   101,    88,    85,
     244,    87,   104,   277,    95,    25,    85,   307,    87,    87,
      85,   311,    87,   105,   314,   169,   170,   171,   172,   173,
     320,   165,   166,   326,   327,   328,    85,    85,    87,    87,
      85,    87,    87,   443,   444,   445,   102,   103,    85,   307,
      87,    87,    85,   311,    87,    85,   314,     3,   348,   241,
     392,   351,   167,   168,   384,   316,    87,   330,   468,    87,
     470,   174,   175,     3,     6,    84,    88,   367,   478,    86,
     370,   481,   316,   483,    88,    86,   376,    86,    86,   379,
     348,     3,   107,   107,   384,   339,    87,    85,   388,     9,
      10,    11,   392,    90,    90,    88,   364,    87,   359,   441,
      87,   313,   364,    87,    85,    87,    85,    48,   376,    50,
      87,    87,    90,   455,     3,   359,   384,    90,    87,    69,
     388,   357,    88,     3,   107,    90,    90,   339,   372,    90,
      92,   431,   344,    90,   434,    90,    87,    90,    79,    80,
      81,   441,    90,   446,   447,   448,    90,   107,    86,    88,
      67,   451,    88,    90,   454,   455,    90,    98,    90,    90,
      90,    90,    90,   431,    90,   452,    86,   177,   180,    89,
     176,    91,   107,   178,     3,     4,     5,     6,     7,     8,
     179,    10,    11,   357,   452,   134,    69,   133,   344,   367,
     452,   321,    43,   220,    -1,    -1,   123,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,   202,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,    -1,     3,     4,     5,     6,     7,     8,   107,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,   244,    10,    11,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    38,    64,    65,    66,   277,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    77,    -1,    79,    -1,   316,   107,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,   359,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,   372,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    84,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,     3,     4,     5,     6,
       7,     8,   107,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,    38,    -1,    -1,    -1,    -1,    -1,    -1,
     107,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    -1,    79,    -1,    38,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,    37,    38,
      -1,    -1,    -1,    -1,    -1,   107,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      47,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    38,    -1,    86,
      41,    -1,    -1,    90,    45,    46,    47,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    38,    -1,    86,    41,    -1,
      -1,    90,    45,    46,    47,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    38,    -1,    86,    41,    -1,    -1,    90,
      45,    46,    47,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    -1,    -1,    38,    94,
      95,    96,    97,    98,    99,    45,    46,    47,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    38,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    79,     3,     4,     5,     6,     7,
       8,    86,    10,    11,    89,    38,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      38,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    38,    -1,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,    -1,    38,    77,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    94,    95,    96,    97,
      98,    99,    -1,    77,    -1,    79,     3,     4,     5,     6,
       7,     8,    86,    10,    11,    -1,    -1,    77,    92,    79,
      94,    95,    96,    97,    98,    99,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
      -1,    38,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    38,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      77,    -1,    79,    94,    95,    96,    97,    98,    99,    86,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    -1,    82,    -1,    -1,
      -1,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    37,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    81,
      82,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    78,    -1,    80,    -1,    82,    -1,    -1,    -1,
      86,    87,    37,    89,    -1,    -1,    -1,    -1,    -1,    95,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    93,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    93,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      81,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    92,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    78,    -1,    80,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    92,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,    82,
      -1,    -1,    -1,    37,    87,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    78,    -1,    80,    81,    82,    37,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      78,    -1,    80,    37,    82,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    76,    -1,    78,    -1,    80,    -1,    82,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    78,    -1,    -1,    81,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    76,    78,    80,    81,
      82,   137,   138,   141,   142,   143,   144,   150,   153,   154,
     155,   156,   174,   184,   185,   186,     3,    92,    86,    86,
      86,     3,    86,    95,   107,   139,   140,   157,   159,   160,
     138,   138,     3,    92,   138,   138,   138,     0,   185,    92,
       3,   111,   151,   152,     3,     4,     5,     6,     7,     8,
      10,    11,    38,    77,    79,    86,    94,    95,    96,    97,
      98,    99,   109,   110,   112,   113,   116,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   136,   142,   147,   154,   166,   166,   136,   157,    78,
     154,   160,   161,    85,   107,    84,    92,   137,   138,   177,
     187,    86,    89,   158,    92,   145,   146,   147,   174,   151,
      84,    85,    93,    86,   119,    86,   119,   119,    86,    86,
     119,   132,   133,   135,   166,     9,    10,    11,    86,    89,
      91,   121,    95,   100,   101,    96,    97,    12,    13,    14,
      15,    18,   102,   103,    16,    17,    94,   104,   105,    25,
      26,   106,    87,   147,    86,    89,   160,   167,   168,   147,
      87,    87,    85,    87,   154,   160,   140,   157,    92,   133,
     169,     3,    64,    65,    66,    68,    69,    70,    71,    72,
      73,    74,    75,    93,   107,   135,   137,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   137,   177,     3,    87,
     138,   162,   163,   164,   165,    41,    90,    95,   133,   161,
     159,   145,    93,   146,    88,   107,   148,   149,   157,    85,
      93,   136,    93,   152,   166,   166,   166,   133,    19,    20,
      21,    22,    23,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    84,   134,    85,    87,    87,     3,   117,
     118,   133,   135,     3,   121,   121,   121,   122,   122,   123,
     123,   124,   124,   124,   124,   124,   125,   125,   126,   127,
     128,   129,   130,   135,    87,   162,   167,    41,    90,    95,
     133,   161,   168,    86,    89,     6,    89,    91,   169,   170,
     171,   172,   173,    88,   136,    88,    86,    86,    86,   175,
      86,     3,   107,   107,   107,   135,   107,    93,   179,    86,
     157,   160,   167,    87,    85,    85,    87,   133,   161,    90,
      90,    41,    90,    95,   133,    93,   136,    85,   107,    88,
      93,    87,    87,    87,    85,   133,   133,    92,   121,    87,
      85,    90,    88,    87,    87,   133,   161,    90,    90,    41,
      90,   133,    87,   162,    41,    90,    95,   133,   161,    87,
     136,     3,    85,    93,   169,    84,   173,   175,    88,   175,
     135,   135,   135,    69,   137,   180,   107,   107,    63,   164,
       3,    90,   133,   133,    90,    90,   149,   136,    65,   114,
     115,   166,   170,   133,   132,    90,   133,   133,    90,    87,
     133,   161,    90,    90,    41,    90,   133,   107,    90,    93,
     169,   171,   175,    87,    87,    87,    86,   180,   180,    90,
      90,    88,    85,    87,    88,    85,    93,    90,    90,    90,
     133,   133,    90,   169,   175,   175,   175,   135,    87,   135,
      87,   135,   133,   115,   133,    93,    90,    90,    67,    87,
     175,    87,   175,    87,   175,   107,   175,   175
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
     150,   151,   151,   152,   152,   153,   154,   154,   154,   154,
     155,   155,   156,   156,   158,   157,   157,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   160,   160,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   164,   164,   165,   165,   166,   166,   167,   167,
     167,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   169,   169,   169,   170,   170,   170,   170,   171,
     172,   172,   173,   173,   174,   175,   175,   175,   175,   175,
     175,   176,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   180,   181,   181,   181,   182,   182,   182,   182,   182,
     182,   183,   183,   183,   183,   183,   184,   184,   185,   185,
     186,   186,   187,   187
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
       1,     1,     4,     4,     0,     3,     1,     1,     3,     3,
       4,     6,     5,     5,     6,     5,     4,     4,     4,     3,
       4,     3,     2,     2,     1,     1,     2,     3,     1,     1,
       3,     2,     2,     1,     1,     3,     2,     1,     2,     1,
       1,     3,     2,     3,     5,     4,     5,     4,     3,     3,
       3,     4,     6,     5,     5,     6,     4,     4,     2,     3,
       3,     4,     3,     4,     1,     2,     1,     4,     3,     2,
       1,     2,     3,     2,     7,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     1,     2,     1,     1,
       1,     2,     7,     5,     5,     5,     7,     6,     7,     6,
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
#line 65 "yapl.y"
                     {int_consts++;}
#line 2022 "yapl.tab.c"
    break;

  case 77: /* assignment_expression: conditional_expression  */
#line 204 "yapl.y"
                                 {
		sprintf(derivations[dtop++], "assignment_expression -> conditional_expression");
	}
#line 2030 "yapl.tab.c"
    break;

  case 78: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 207 "yapl.y"
                                                                     {
		sprintf(derivations[dtop++], "assignment_expression -> unary_expression assignment_operator assignment_expression");
	}
#line 2038 "yapl.tab.c"
    break;

  case 95: /* expression: assignment_expression  */
#line 232 "yapl.y"
                                {
		sprintf(derivations[dtop++], "expression -> assignment_expression");
	}
#line 2046 "yapl.tab.c"
    break;

  case 96: /* expression: expression ',' assignment_expression  */
#line 235 "yapl.y"
                                               {
		sprintf(derivations[dtop++], "expression -> expression , assignment_expression");
	}
#line 2054 "yapl.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers ';'  */
#line 245 "yapl.y"
                                     {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers ;");
	}
#line 2062 "yapl.tab.c"
    break;

  case 99: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 248 "yapl.y"
                                                          {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers init_declarator_list ;");
	}
#line 2070 "yapl.tab.c"
    break;

  case 100: /* declaration: static_assert_declaration  */
#line 251 "yapl.y"
                                    {
		sprintf(derivations[dtop++], "declaration -> static_assert_declaration");
	}
#line 2078 "yapl.tab.c"
    break;

  case 174: /* $@1: %empty  */
#line 387 "yapl.y"
                  {pointer_decls++;}
#line 2084 "yapl.tab.c"
    break;

  case 245: /* statement: labeled_statement  */
#line 509 "yapl.y"
                            {
		sprintf(derivations[dtop++], "statement -> labeled_statement");
	}
#line 2092 "yapl.tab.c"
    break;

  case 246: /* statement: compound_statement  */
#line 512 "yapl.y"
                             {
		sprintf(derivations[dtop++], "statement -> compound_statement");
	}
#line 2100 "yapl.tab.c"
    break;

  case 247: /* statement: expression_statement  */
#line 515 "yapl.y"
                               {
		sprintf(derivations[dtop++], "statement -> expression_statement");
	}
#line 2108 "yapl.tab.c"
    break;

  case 248: /* statement: selection_statement  */
#line 518 "yapl.y"
                              {
		sprintf(derivations[dtop++], "statement -> selection_statement");
	}
#line 2116 "yapl.tab.c"
    break;

  case 249: /* statement: iteration_statement  */
#line 521 "yapl.y"
                              {
		sprintf(derivations[dtop++], "statement -> iteration_statement");
	}
#line 2124 "yapl.tab.c"
    break;

  case 250: /* statement: jump_statement  */
#line 524 "yapl.y"
                         {
		sprintf(derivations[dtop++], "statement -> jump_statement");
	}
#line 2132 "yapl.tab.c"
    break;

  case 254: /* compound_statement: '{' '}'  */
#line 536 "yapl.y"
                  {
		sprintf(derivations[dtop++], "compound_statement -> { }");
	}
#line 2140 "yapl.tab.c"
    break;

  case 255: /* compound_statement: '{' block_item_list '}'  */
#line 539 "yapl.y"
                                  {
		sprintf(derivations[dtop++], "compound_statement -> { block_item_list }");
	}
#line 2148 "yapl.tab.c"
    break;

  case 256: /* block_item_list: block_item  */
#line 545 "yapl.y"
                     {
		sprintf(derivations[dtop++], "block_item_list -> block_item");
	}
#line 2156 "yapl.tab.c"
    break;

  case 257: /* block_item_list: block_item_list block_item  */
#line 548 "yapl.y"
                                     {
		sprintf(derivations[dtop++], "block_item_list -> block_item_list block_item");
	}
#line 2164 "yapl.tab.c"
    break;

  case 258: /* block_item: declaration  */
#line 554 "yapl.y"
                      {
		sprintf(derivations[dtop++], "block_item -> declaration");
	}
#line 2172 "yapl.tab.c"
    break;

  case 259: /* block_item: statement  */
#line 557 "yapl.y"
                    {
		sprintf(derivations[dtop++], "block_item -> statement");
	}
#line 2180 "yapl.tab.c"
    break;

  case 260: /* expression_statement: ';'  */
#line 563 "yapl.y"
              {
		sprintf(derivations[dtop++], "expression_statement -> ;");
	}
#line 2188 "yapl.tab.c"
    break;

  case 261: /* expression_statement: expression ';'  */
#line 566 "yapl.y"
                         {
		sprintf(derivations[dtop++], "expression_statement -> expression ;");
	}
#line 2196 "yapl.tab.c"
    break;

  case 262: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 572 "yapl.y"
                                                         {
		sprintf(derivations[dtop++], "selection_statement -> IF ( expression ) statement ELSE statement");
	}
#line 2204 "yapl.tab.c"
    break;

  case 263: /* selection_statement: IF '(' expression ')' statement  */
#line 575 "yapl.y"
                                                    {
		sprintf(derivations[dtop++], "selection_statement -> IF ( expression ) statement");
		ifs_wo_else++;
	}
#line 2213 "yapl.tab.c"
    break;

  case 264: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 579 "yapl.y"
                                              {
		sprintf(derivations[dtop++], "selection_statement -> SWITCH ( expression ) statement");
	}
#line 2221 "yapl.tab.c"
    break;

  case 276: /* translation_unit: external_declaration  */
#line 602 "yapl.y"
                               {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> external_declaration");
	}
#line 2230 "yapl.tab.c"
    break;

  case 277: /* translation_unit: translation_unit external_declaration  */
#line 606 "yapl.y"
                                                {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> translation_unit external_declaration");
	}
#line 2239 "yapl.tab.c"
    break;

  case 278: /* external_declaration: function_definition  */
#line 613 "yapl.y"
                              {func_definitions++;}
#line 2245 "yapl.tab.c"
    break;

  case 280: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 618 "yapl.y"
                                                                                {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator declaration_list compound_statement");
	}
#line 2253 "yapl.tab.c"
    break;

  case 281: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 621 "yapl.y"
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

#line 631 "yapl.y"

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

void print_parsing_table()
{
    printf("\nLALR(1) Parsing Table (Partial):\n\n");

    printf("%-6s %-15s %-10s %-10s %-6s %-12s %-12s %-12s\n",
           "State", "TYPEDEF_NAME", "TYPEDEF", "EXTERN", "$",
           "decl", "decl_spec", "func_def");

    // State 0
    printf("%-6d %-15s %-10s %-10s %-6s %-12d %-12d %-12d\n",
           0, "S1", "S2", "S3", "",
           31, 32, 45);

    // State 1
    printf("%-6d %-15s %-10s %-10s %-6s %-12s %-12s %-12s\n",
           1, "", "", "", "R135",
           "", "", "");

    // State 2
    printf("%-6d %-15s %-10s %-10s %-6s %-12s %-12s %-12s\n",
           2, "", "", "", "R114",
           "", "", "");

    // State 3
    printf("%-6d %-15s %-10s %-10s %-6s %-12s %-12s %-12s\n",
           3, "", "", "", "R115",
           "", "", "");
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

    print_parsing_table();

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



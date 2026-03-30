/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YAPL_TAB_H_INCLUDED
# define YY_YY_YAPL_TAB_H_INCLUDED
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
    THREAD_LOCAL = 337,            /* THREAD_LOCAL  */
    IFX = 338                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "yapl.y"

	int val;
	struct symtab *symp;

#line 152 "yapl.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_YAPL_TAB_H_INCLUDED  */

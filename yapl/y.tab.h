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

#line 236 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

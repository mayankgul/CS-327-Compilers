#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20100216

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
#ifdef YYPARSE_PARAM_TYPE
#define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
#else
#define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
#endif
#else
#define YYPARSE_DECL() yyparse(void)
#endif /* YYPARSE_PARAM */

extern int YYPARSE_DECL();

#line 47 "sm.y"
typedef union
{
	int val;
	struct symtab *symp;
} YYSTYPE;
#line 53 "sm.y"
#include "symbol.h"
#include<stdio.h>
#include<string.h>
#line 44 "y.tab.c"
#define NUMBER 257
#define DISP 258
#define NAME 259
#define LEFT_SHIFT 260
#define POWER 261
#define RIGHT_SHIFT 262
#define LE 263
#define GE 264
#define EEQ 265
#define NE 266
#define AND_AND 267
#define OR_OR 268
#define UMINUS 269
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    2,    3,    3,
    4,    4,    5,    5,    6,    6,    7,    7,    8,    8,
    8,    9,    9,    9,    9,    9,   10,   10,   10,   11,
   11,   11,   12,   12,   12,   12,   13,   13,   14,   14,
   14,   15,   15,   15,   16,   16,   16,
};
static const short yylen[] = {                            2,
    3,    2,    0,    8,    3,    4,    3,    7,    3,    1,
    3,    1,    3,    1,    3,    1,    3,    1,    3,    3,
    1,    3,    3,    3,    3,    1,    3,    3,    1,    3,
    3,    1,    3,    3,    3,    1,    3,    1,    2,    2,
    1,    2,    2,    1,    3,    1,    2,
};
static const short yydefred[] = {                         0,
    3,    0,    0,    0,    0,    1,    2,    0,    0,    7,
    0,    5,    0,    0,    6,    0,   46,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   38,   41,   44,    0,   43,   42,
   39,   40,   47,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   45,    0,    8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   37,    0,    4,
};
static const short yydgoto[] = {                          2,
    3,    7,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,
};
static const short yysindex[] = {                       -51,
    0,    0,  -46,   17,  -12,    0,    0,  -16,  -22,    0,
   22,    0,   25,  377,    0,   36,    0,  161,  161,  377,
  377, -219,  377,    6, -208,  -58,   -4,   56, -263,  -53,
 -169,   54,   35, -165,    0,    0,    0,  377,    0,    0,
    0,    0,    0,   14,  377,   60,  377,  377,  377,  377,
  377,  377,  377,  377,  377,  377,  377,  377,  377,  377,
  377,  377,  377,  377,   19,    0, -208,    0,  -58,   -4,
   56, -263,  -53,  -53, -169, -169, -169, -169,   54,   54,
   35,   35, -165, -165, -165,    0,   63,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   29,  -19,  -21,   69,  285,   83,
   92,   51,   13,  -37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   33,    0,  102,    4,
  100,  287,  258,  283,   98,  121,  127,  138,   67,   78,
   26,   40,  -26,  -10,    1,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    3,   61,   62,   64,   73,   65,   66,   93,
  -28,   72,   94,   59,  148,    0,
};
#define YYTABLESIZE 634
static const short yytable[] = {                         36,
   36,   51,   52,   36,   36,   36,   55,   36,   56,   36,
   33,   33,    1,   13,   33,   33,   33,    6,   33,   14,
   33,   12,   36,   11,   36,   44,   34,   34,   79,   80,
   34,   34,   34,   33,   34,   33,   34,   35,   35,   43,
   65,   35,   35,   35,   13,   35,   46,   35,    9,   34,
   32,   34,    8,   32,   66,   32,   36,   32,   47,   87,
   35,   14,   35,   30,   16,   48,   30,   33,   30,   10,
   30,   63,   32,    9,   32,   38,   61,   31,   41,   42,
   31,   62,   31,   34,   31,   30,   36,   30,   29,   49,
   57,   29,   58,   50,   35,   64,   59,   33,   60,   31,
   68,   31,   14,   88,   27,   67,   32,   27,   69,   16,
   29,   70,   29,   34,   72,   28,   73,   74,   28,   30,
   21,   71,   86,   21,   35,    0,   27,   13,   27,   26,
   81,   82,   26,   31,    0,   22,   32,   28,   22,   28,
   15,    0,   11,    0,   29,   75,   76,   77,   78,   30,
    0,   26,    0,   26,   83,   84,   85,   22,   23,   22,
   27,   23,   16,   31,   24,   39,   40,   24,    0,    0,
    0,   28,    0,    0,   29,   25,   21,    0,   25,    0,
   23,    0,   23,    0,    0,   26,   24,    0,   24,    0,
   27,   22,   16,   15,    0,    0,   22,   25,    0,   25,
   23,   28,    0,   18,    0,   19,   21,    0,    0,   53,
   54,    4,    5,    0,   23,   26,    0,    0,    0,    0,
   24,   22,   36,   15,   36,   36,   36,   36,   36,   36,
   36,   25,    0,   33,   12,   33,   33,   33,   33,   33,
   33,   33,   10,    0,   23,   14,   14,   12,   12,   34,
   24,   34,   34,   34,   34,   34,   34,   34,    0,    0,
   35,   25,   35,   35,   35,   35,   35,   35,   35,    0,
   13,   13,   32,   45,   32,   32,   32,   32,   32,   32,
   32,   45,    0,   15,    0,   30,   45,   30,   30,   30,
   30,   30,   30,   30,    0,   19,   10,    0,   19,   31,
    9,   31,   31,   31,   31,   31,   31,   31,    0,    0,
   29,    0,   29,   29,   29,   29,   29,   29,   29,    0,
   20,    0,   18,   20,   17,   18,   27,   17,   27,   27,
   27,   27,   27,   27,   27,   16,   16,   28,    0,   28,
   28,   28,   28,   28,   28,   28,    0,   21,   21,   21,
   21,   19,    0,    0,   26,   26,   26,   26,   26,   26,
   22,   22,   22,   22,   22,   22,   15,   15,   11,   11,
    0,    0,    0,    0,    0,    0,   20,    0,   18,    0,
   17,   19,    0,   23,   23,   23,   23,   23,   23,   24,
   24,   24,   24,   24,   24,    0,    0,    0,    0,    0,
   25,   25,   25,   25,   25,   25,   20,    0,   18,   20,
   17,    0,   22,    0,    0,    0,   23,   17,    0,   18,
    0,   19,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   21,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   19,   19,   19,   19,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   20,   20,   20,
   20,   18,   18,   17,   17,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,
};
static const short yycheck[] = {                         37,
   38,  265,  266,   41,   42,   43,   60,   45,   62,   47,
   37,   38,   64,   36,   41,   42,   43,   64,   45,   41,
   47,   41,   60,   40,   62,   23,   37,   38,   57,   58,
   41,   42,   43,   60,   45,   62,   47,   37,   38,  259,
   38,   41,   42,   43,   41,   45,   41,   47,   61,   60,
   38,   62,   36,   41,   41,   43,   94,   45,  267,   41,
   60,   40,   62,   38,   40,  124,   41,   94,   43,   41,
   45,   37,   60,   41,   62,   40,   42,   38,   20,   21,
   41,   47,   43,   94,   45,   60,  124,   62,   38,   94,
  260,   41,  262,   38,   94,  261,   43,  124,   45,   60,
   41,   62,  124,   41,   38,   45,   94,   41,   47,   41,
   60,   48,   62,  124,   50,   38,   51,   52,   41,   94,
   38,   49,   64,   41,  124,   -1,   60,  124,   62,   38,
   59,   60,   41,   94,   -1,   38,  124,   60,   41,   62,
   41,   -1,   41,   -1,   94,   53,   54,   55,   56,  124,
   -1,   60,   -1,   62,   61,   62,   63,   60,   38,   62,
   94,   41,   94,  124,   38,   18,   19,   41,   -1,   -1,
   -1,   94,   -1,   -1,  124,   38,   94,   -1,   41,   -1,
   60,   -1,   62,   -1,   -1,   94,   60,   -1,   62,   -1,
  124,   94,  124,   94,   -1,   -1,   36,   60,   -1,   62,
   40,  124,   -1,   43,   -1,   45,  124,   -1,   -1,  263,
  264,  258,  259,   -1,   94,  124,   -1,   -1,   -1,   -1,
   94,  124,  260,  124,  262,  263,  264,  265,  266,  267,
  268,   94,   -1,  260,  257,  262,  263,  264,  265,  266,
  267,  268,  259,   -1,  124,  267,  268,  267,  268,  260,
  124,  262,  263,  264,  265,  266,  267,  268,   -1,   -1,
  260,  124,  262,  263,  264,  265,  266,  267,  268,   -1,
  267,  268,  260,  268,  262,  263,  264,  265,  266,  267,
  268,  268,   -1,  259,   -1,  260,  268,  262,  263,  264,
  265,  266,  267,  268,   -1,   38,  268,   -1,   41,  260,
  268,  262,  263,  264,  265,  266,  267,  268,   -1,   -1,
  260,   -1,  262,  263,  264,  265,  266,  267,  268,   -1,
   38,   -1,   38,   41,   38,   41,  260,   41,  262,  263,
  264,  265,  266,  267,  268,  267,  268,  260,   -1,  262,
  263,  264,  265,  266,  267,  268,   -1,  265,  266,  267,
  268,   94,   -1,   -1,  263,  264,  265,  266,  267,  268,
  263,  264,  265,  266,  267,  268,  267,  268,  267,  268,
   -1,   -1,   -1,   -1,   -1,   -1,   94,   -1,   94,   -1,
   94,  124,   -1,  263,  264,  265,  266,  267,  268,  263,
  264,  265,  266,  267,  268,   -1,   -1,   -1,   -1,   -1,
  263,  264,  265,  266,  267,  268,  124,   -1,  124,   33,
  124,   -1,   36,   -1,   -1,   -1,   40,  257,   -1,   43,
   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  265,  266,  267,  268,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  265,  266,  267,
  268,  267,  268,  267,  268,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,"'$'","'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,0,0,"'<'","'='","'>'",0,"'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUMBER","DISP","NAME","LEFT_SHIFT","POWER",
"RIGHT_SHIFT","LE","GE","EEQ","NE","AND_AND","OR_OR","UMINUS",
};
static const char *yyrule[] = {
"$accept : structure",
"structure : '@' program '@'",
"program : program statement",
"program :",
"statement : NAME '=' '$' '(' '(' expression1 ')' ')'",
"statement : NAME '=' NUMBER",
"statement : NAME '=' '$' NAME",
"statement : DISP '$' NAME",
"statement : DISP '$' '(' '(' expression1 ')' ')'",
"expression1 : expression1 OR_OR expression2",
"expression1 : expression2",
"expression2 : expression2 AND_AND expression3",
"expression2 : expression3",
"expression3 : expression3 '|' expression4",
"expression3 : expression4",
"expression4 : expression4 '^' expression5",
"expression4 : expression5",
"expression5 : expression5 '&' expression6",
"expression5 : expression6",
"expression6 : expression6 EEQ expression7",
"expression6 : expression6 NE expression7",
"expression6 : expression7",
"expression7 : expression7 LE expression8",
"expression7 : expression7 GE expression8",
"expression7 : expression7 '<' expression8",
"expression7 : expression7 '>' expression8",
"expression7 : expression8",
"expression8 : expression8 LEFT_SHIFT expression9",
"expression8 : expression8 RIGHT_SHIFT expression9",
"expression8 : expression9",
"expression9 : expression9 '+' expression10",
"expression9 : expression9 '-' expression10",
"expression9 : expression10",
"expression10 : expression10 '*' expression11",
"expression10 : expression10 '/' expression11",
"expression10 : expression10 '%' expression11",
"expression10 : expression11",
"expression11 : expression11 POWER expression12",
"expression11 : expression12",
"expression12 : '!' expression12",
"expression12 : '~' expression12",
"expression12 : expression13",
"expression13 : '-' expression13",
"expression13 : '+' expression13",
"expression13 : expression14",
"expression14 : '(' expression1 ')'",
"expression14 : NUMBER",
"expression14 : '$' NAME",

};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;

#define YYPURE 0

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 180 "sm.y"
main(int argc,char **argv)
{
	extern FILE *yyin;

	yyin=fopen(argv[1],"r");

	if(yyin==NULL)
	{
		yyerror("No such file exists!!");
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
	
}
yyerror(char *s)
{
	printf("Error:%s\nResult=%d(garbage) , Return Status=-1(failure)\n\n",s);
}
struct symtab *symlook(char *s)
{
	char *p;
	struct symtab *sp;

	for(sp=symbol_table;sp<&symbol_table[MAX];sp++)
	{
		if(sp->name && !strcmp(sp->name,s))
			return sp;
		if(!sp->name)
		{
			sp->name=strdup(s);
			return(sp);
		}
	}
	yyerror("Symbol table overflow!!");
	exit(1);
}
int expo(int a,int b)
{
	int i,res=1;
	
	for(i=1;i<=b;i++)
		res*=a;
	return(res);
}
#line 409 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (data->s_base != 0)
          ? (short *)realloc(data->s_base, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base  = newss;
    data->s_mark = newss + i;

    newvs = (data->l_base != 0)
          ? (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 59 "sm.y"
	{yyval.val=0; printf("Result=%d, Return status=%d(success)\n\n",yystack.l_mark[-1].val,yyval.val); return(0);}
break;
case 2:
#line 63 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 4:
#line 68 "sm.y"
	{yyval.val=yystack.l_mark[-2].val; yystack.l_mark[-7].symp->value=yystack.l_mark[-2].val;}
break;
case 5:
#line 69 "sm.y"
	{yyval.val=yystack.l_mark[0].val; yystack.l_mark[-2].symp->value=yystack.l_mark[0].val;}
break;
case 6:
#line 70 "sm.y"
	{yystack.l_mark[-3].symp->value=yystack.l_mark[0].symp->value; yyval.val=yystack.l_mark[-3].symp->value;}
break;
case 7:
#line 71 "sm.y"
	{yyval.val=printf("%s=%d\n",yystack.l_mark[0].symp->name,yystack.l_mark[0].symp->value);}
break;
case 8:
#line 72 "sm.y"
	{yyval.val=printf("%d\n",yystack.l_mark[-2].val);}
break;
case 9:
#line 76 "sm.y"
	{yyval.val=yystack.l_mark[-2].val||yystack.l_mark[0].val;}
break;
case 10:
#line 77 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 11:
#line 81 "sm.y"
	{yyval.val=yystack.l_mark[-2].val&&yystack.l_mark[0].val;}
break;
case 12:
#line 82 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 13:
#line 86 "sm.y"
	{yyval.val=yystack.l_mark[-2].val|yystack.l_mark[0].val;}
break;
case 14:
#line 87 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 15:
#line 91 "sm.y"
	{yyval.val=yystack.l_mark[-2].val^yystack.l_mark[0].val;}
break;
case 16:
#line 92 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 17:
#line 96 "sm.y"
	{yyval.val=yystack.l_mark[-2].val&yystack.l_mark[0].val;}
break;
case 18:
#line 97 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 19:
#line 101 "sm.y"
	{yyval.val=(yystack.l_mark[-2].val==yystack.l_mark[0].val);}
break;
case 20:
#line 102 "sm.y"
	{yyval.val=(yystack.l_mark[-2].val!=yystack.l_mark[0].val);}
break;
case 21:
#line 103 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 22:
#line 107 "sm.y"
	{yyval.val=(yystack.l_mark[-2].val<=yystack.l_mark[0].val);}
break;
case 23:
#line 108 "sm.y"
	{yyval.val=(yystack.l_mark[-2].val>=yystack.l_mark[0].val);}
break;
case 24:
#line 109 "sm.y"
	{yyval.val=(yystack.l_mark[-2].val<yystack.l_mark[0].val);}
break;
case 25:
#line 110 "sm.y"
	{yyval.val=(yystack.l_mark[-2].val>yystack.l_mark[0].val);}
break;
case 26:
#line 111 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 27:
#line 115 "sm.y"
	{yyval.val=yystack.l_mark[-2].val<<yystack.l_mark[0].val;}
break;
case 28:
#line 116 "sm.y"
	{yyval.val=yystack.l_mark[-2].val>>yystack.l_mark[0].val;}
break;
case 29:
#line 117 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 30:
#line 121 "sm.y"
	{yyval.val=yystack.l_mark[-2].val+yystack.l_mark[0].val;}
break;
case 31:
#line 122 "sm.y"
	{yyval.val=yystack.l_mark[-2].val-yystack.l_mark[0].val;}
break;
case 32:
#line 123 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 33:
#line 127 "sm.y"
	{yyval.val=yystack.l_mark[-2].val*yystack.l_mark[0].val;}
break;
case 34:
#line 128 "sm.y"
	{
						if(yystack.l_mark[0].val==0)
						{
							yyerror("division by zero error");
							exit(1);
						}
						else
							yyval.val=yystack.l_mark[-2].val/yystack.l_mark[0].val;
					    }
break;
case 35:
#line 137 "sm.y"
	{
						if(yystack.l_mark[0].val==0)
						{
							yyerror("division by zero error");
							exit(1);
						}
						else
							yyval.val=yystack.l_mark[-2].val%yystack.l_mark[0].val;
					    }
break;
case 36:
#line 146 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 37:
#line 150 "sm.y"
	{
						if(yystack.l_mark[0].val<0)
						{
							yyerror("negative exponent");
							exit(1);
						}
						else
							yyval.val=expo(yystack.l_mark[-2].val,yystack.l_mark[0].val);
					     }
break;
case 38:
#line 159 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 39:
#line 163 "sm.y"
	{yyval.val=!yystack.l_mark[0].val;}
break;
case 40:
#line 164 "sm.y"
	{yyval.val=~yystack.l_mark[0].val;}
break;
case 41:
#line 165 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 42:
#line 169 "sm.y"
	{yyval.val=-yystack.l_mark[0].val;}
break;
case 43:
#line 170 "sm.y"
	{yyval.val=+yystack.l_mark[0].val;}
break;
case 44:
#line 171 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 45:
#line 175 "sm.y"
	{yyval.val=yystack.l_mark[-1].val;}
break;
case 46:
#line 176 "sm.y"
	{yyval.val=yystack.l_mark[0].val;}
break;
case 47:
#line 177 "sm.y"
	{yyval.val=yystack.l_mark[0].symp->value;}
break;
#line 819 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

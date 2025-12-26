%token <val> NUMBER DISP
%token <symp> NAME
%token <val> LEFT_SHIFT
%token <val> POWER
%token <val> RIGHT_SHIFT
%token <val> LE
%token <val> GE
%token <val> EEQ
%token <val> NE
%token <val> AND_AND
%token <val> OR_OR
%start structure

%type <val> structure
%type <val> program
%type <val> statement
%type <val> expression1
%type <val> expression2
%type <val> expression3
%type <val> expression4
%type <val> expression5
%type <val> expression6
%type <val> expression7
%type <val> expression8
%type <val> expression9
%type <val> expression10
%type <val> expression11
%type <val> expression12
%type <val> expression13
%type <val> expression14

%right <val> '='
%left <val> OR_OR
%left <val> AND_AND
%left <val> '|'
%left <val> '^'
%left <val> '&'
%left <val> EEQ NE
%left <val> LE GE '<' '>'
%left <val> LEFT_SHIFT RIGHT_SHIFT
%left <val> '+' '-'
%left <val> '*' '/' '%'
%right <val > POWER
%right <val> '!' '~'
%nonassoc <val> UMINUS

%union
{
	int val;
	struct symtab *symp;
}
%{
#include "symbol.h"
#include<stdio.h>
#include<string.h>
%}
%%
structure:
	  '@' program '@' {$$=0; printf("Result=%d, Return status=%d(success)\n\n",$2,$$); return(0);}
	  ;

program:
	program statement {$$=$2;}
	|
	;

statement:
	  NAME '=' '$' '(' '(' expression1 ')' ')' {$$=$6; $1->value=$6;}
	  |NAME '=' NUMBER {$$=$3; $1->value=$3;}
	  |NAME '=' '$' NAME {$1->value=$4->value; $$=$1->value;}
	  |DISP '$' NAME {$$=printf("%s=%d\n",$3->name,$3->value);}
	  |DISP '$' '(' '(' expression1 ')' ')' {$$=printf("%d\n",$5);}
   	  ;

expression1:
	    expression1 OR_OR expression2 {$$=$1||$3;}
	    |expression2 {$$=$1;}
	    ;

expression2:
	    expression2 AND_AND expression3 {$$=$1&&$3;}
	    |expression3 {$$=$1;}
	    ;

expression3:
	    expression3 '|' expression4 {$$=$1|$3;}
	    |expression4 {$$=$1;}
	    ;

expression4:
	    expression4 '^' expression5 {$$=$1^$3;}
	    |expression5 {$$=$1;}
	    ;

expression5:
	    expression5 '&' expression6 {$$=$1&$3;}
	    |expression6 {$$=$1;}
	    ;

expression6:
	    expression6 EEQ expression7 {$$=($1==$3);}
	    |expression6 NE expression7 {$$=($1!=$3);}
	    |expression7 {$$=$1;}
	    ;

expression7:
	    expression7 LE expression8 {$$=($1<=$3);}
	    |expression7 GE expression8 {$$=($1>=$3);}
	    |expression7 '<' expression8 {$$=($1<$3);}
	    |expression7 '>' expression8 {$$=($1>$3);}
	    |expression8 {$$=$1;}
	    ;

expression8:
	    expression8 LEFT_SHIFT expression9 {$$=$1<<$3;}
	    |expression8 RIGHT_SHIFT expression9 {$$=$1>>$3;}
	    |expression9 {$$=$1;}
	    ;

expression9:
	    expression9 '+' expression10 {$$=$1+$3;}
	    |expression9 '-' expression10 {$$=$1-$3;}
	    |expression10 {$$=$1;}
	    ;

expression10:
	     expression10 '*' expression11 {$$=$1*$3;}
	     |expression10 '/' expression11 {
						if($3==0)
						{
							yyerror("division by zero error");
							exit(1);
						}
						else
							$$=$1/$3;
					    }
	     |expression10 '%' expression11 {
						if($3==0)
						{
							yyerror("division by zero error");
							exit(1);
						}
						else
							$$=$1%$3;
					    }
	     |expression11 {$$=$1;}
	     ;

expression11:
	     expression11 POWER expression12 {
						if($3<0)
						{
							yyerror("negative exponent");
							exit(1);
						}
						else
							$$=expo($1,$3);
					     }
	     |expression12 {$$=$1;}
	     ;

expression12: 
	     '!' expression12 {$$=!$2;}
	     |'~' expression12 {$$=~$2;}
	     |expression13 {$$=$1;}
	     ;

expression13:
	     '-' expression13 %prec UMINUS {$$=-$2;}
	     |'+' expression13 %prec UMINUS {$$=+$2;}
	     |expression14 {$$=$1;}
	     ;

expression14:
	     '(' expression1 ')' {$$=$2;}
	     |NUMBER {$$=$1;}
	     |'$' NAME {$$=$2->value;}
	     ;
%%
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

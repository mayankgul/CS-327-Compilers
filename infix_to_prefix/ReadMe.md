# Infix to Prefix Translation (representation only)

## ``if2prf.l``
```
%{
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

"+"		  			{return ADD;}
"-"  	  			{return SUB;}
"*"		  			{return MUL;}
"/"		  			{return DIV;}
"("		  			{return LPAR;}
")"		  			{return RPAR;}
([0-9]+|[a-zA-Z]+)	{strcpy(yylval.buff,yytext); return NUM;}
.|\n	  			{;}

%%

int yywrap(void) {
    return 1;
}
```
## ``if2prf.y``
```
%union
{
	int val;
	char buff[1024];
}

%token <buff> ADD SUB MUL DIV LPAR RPAR
%token <buff> NUM
%type  <buff> S Expr Term Factor

%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	void yyerror(char *);
	int yylex(void);
	char aux[256];
	extern char *yytext;
%}
%start S

%%

S:	    Expr {strcpy($$,$1);printf("S: %s\n\n%s\n",$$,$$);}
	    ;
	
Expr:   Expr ADD Term {strcpy(aux,"\0");strcat(aux,"+");strcat(aux,$1);strcat(aux,$3);strcpy($$,aux);printf("Expr: %s\n",$$);}
  	    | Expr SUB Term {strcpy(aux,"\0");strcat(aux,"-");strcat(aux,$1);strcat(aux,$3);strcpy($$,aux);printf("Expr: %s\n",$$);}
  	    | Term {strcpy($$,$1);printf("Expr: %s\n",$$);}
	    ;

Term:   Term MUL Factor {strcpy(aux,"\0");strcat(aux,"*");strcat(aux,$1);strcat(aux,$3);strcpy($$,aux);printf("Term: %s\n",$$);}
  	    | Term DIV Factor {strcpy(aux,"\0");strcat(aux,"/");strcat(aux,$1);strcat(aux,$3);strcpy($$,aux);printf("Term: %s\n",$$);}
  	    | Factor {strcpy($$,$1);printf("Term: %s\n",$$);}
  	    ;

Factor:	LPAR Expr RPAR {strcpy($$,$2);printf("Factor: %s\n",$$);}
	    | NUM {strcpy($$,$1);printf("Factor: %s\n",$$);}
	    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
```
## Makefile
```
a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o if2prf
	@echo "Run the program as ./if2prf < input.txt"

y.tab.c: if2prf.y 
	yacc -d --report=itemsets,states,lookaheads -g if2prf.y

lex.yy.c: if2prf.l y.tab.h
	lex if2prf.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c if2prf *.output *.gv *.svg
```
## y.output
```
Grammar

    0 $accept: S $end

    1 S: Expr

    2 Expr: Expr ADD Term
    3     | Expr SUB Term
    4     | Term

    5 Term: Term MUL Factor
    6     | Term DIV Factor
    7     | Factor

    8 Factor: LPAR Expr RPAR
    9       | NUM


Terminals, with rules where they appear

    $end (0) 0
    error (256)
    ADD <buff> (258) 2
    SUB <buff> (259) 3
    MUL <buff> (260) 5
    DIV <buff> (261) 6
    LPAR <buff> (262) 8
    RPAR <buff> (263) 8
    NUM <buff> (264) 9


Nonterminals, with rules where they appear

    $accept (10)
        on left: 0
    S <buff> (11)
        on left: 1
        on right: 0
    Expr <buff> (12)
        on left: 2 3 4
        on right: 1 2 3 8
    Term <buff> (13)
        on left: 5 6 7
        on right: 2 3 4 5 6
    Factor <buff> (14)
        on left: 8 9
        on right: 5 6 7


State 0

    0 $accept: . S $end
    1 S: . Expr
    2 Expr: . Expr ADD Term
    3     | . Expr SUB Term
    4     | . Term
    5 Term: . Term MUL Factor
    6     | . Term DIV Factor
    7     | . Factor
    8 Factor: . LPAR Expr RPAR
    9       | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    S       go to state 3
    Expr    go to state 4
    Term    go to state 5
    Factor  go to state 6


State 1

    2 Expr: . Expr ADD Term
    3     | . Expr SUB Term
    4     | . Term
    5 Term: . Term MUL Factor
    6     | . Term DIV Factor
    7     | . Factor
    8 Factor: . LPAR Expr RPAR
    8       | LPAR . Expr RPAR
    9       | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    Expr    go to state 7
    Term    go to state 5
    Factor  go to state 6


State 2

    9 Factor: NUM .

    $default  reduce using rule 9 (Factor)


State 3

    0 $accept: S . $end

    $end  shift, and go to state 8


State 4

    1 S: Expr .  [$end]
    2 Expr: Expr . ADD Term
    3     | Expr . SUB Term

    ADD  shift, and go to state 9
    SUB  shift, and go to state 10

    $default  reduce using rule 1 (S)


State 5

    4 Expr: Term .  [$end, ADD, SUB, RPAR]
    5 Term: Term . MUL Factor
    6     | Term . DIV Factor

    MUL  shift, and go to state 11
    DIV  shift, and go to state 12

    $default  reduce using rule 4 (Expr)


State 6

    7 Term: Factor .

    $default  reduce using rule 7 (Term)


State 7

    2 Expr: Expr . ADD Term
    3     | Expr . SUB Term
    8 Factor: LPAR Expr . RPAR

    ADD   shift, and go to state 9
    SUB   shift, and go to state 10
    RPAR  shift, and go to state 13


State 8

    0 $accept: S $end .

    $default  accept


State 9

    2 Expr: Expr ADD . Term
    5 Term: . Term MUL Factor
    6     | . Term DIV Factor
    7     | . Factor
    8 Factor: . LPAR Expr RPAR
    9       | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    Term    go to state 14
    Factor  go to state 6


State 10

    3 Expr: Expr SUB . Term
    5 Term: . Term MUL Factor
    6     | . Term DIV Factor
    7     | . Factor
    8 Factor: . LPAR Expr RPAR
    9       | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    Term    go to state 15
    Factor  go to state 6


State 11

    5 Term: Term MUL . Factor
    8 Factor: . LPAR Expr RPAR
    9       | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    Factor  go to state 16


State 12

    6 Term: Term DIV . Factor
    8 Factor: . LPAR Expr RPAR
    9       | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    Factor  go to state 17


State 13

    8 Factor: LPAR Expr RPAR .

    $default  reduce using rule 8 (Factor)


State 14

    2 Expr: Expr ADD Term .  [$end, ADD, SUB, RPAR]
    5 Term: Term . MUL Factor
    6     | Term . DIV Factor

    MUL  shift, and go to state 11
    DIV  shift, and go to state 12

    $default  reduce using rule 2 (Expr)


State 15

    3 Expr: Expr SUB Term .  [$end, ADD, SUB, RPAR]
    5 Term: Term . MUL Factor
    6     | Term . DIV Factor

    MUL  shift, and go to state 11
    DIV  shift, and go to state 12

    $default  reduce using rule 3 (Expr)


State 16

    5 Term: Term MUL Factor .

    $default  reduce using rule 5 (Term)


State 17

    6 Term: Term DIV Factor .

    $default  reduce using rule 6 (Term)
```
![TBD](TBD)

## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/infix_to_prefix$ ./if2prf
1+4*6
Factor: 1
Term: 1
Expr: 1
Factor: 4
Term: 4
Factor: 6
Term: *46
Expr: +1*46
S: +1*46

+1*46
```

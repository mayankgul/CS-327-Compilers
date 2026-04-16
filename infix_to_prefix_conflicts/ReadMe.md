# Infix to Prefix Translation (representation only) CONFLICTS

## ``if2prfc.l``
```
%{
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

"+"		  			{return ADD;}
"*"		  			{return MUL;}
"("		  			{return LPAR;}
")"		  			{return RPAR;}
([0-9]+|[a-zA-Z]+)	{yylval=atoi(yytext);return NUM;}
.|\n	  			{;}

%%

int yywrap(void) {
    return 1;
}
```
## ``if2prfc.y``
```
%token ADD MUL LPAR RPAR NUM

%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	extern char *yytext;
%}
%start S

%%

S:	E
	;
		
E:	{printf("+");} E ADD T
	| T
	;

T:	{printf("*");} T MUL F
	| F
	;
	
F:	LPAR E RPAR
	| NUM {printf("%d",$1);}

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
	gcc lex.yy.c y.tab.c -o if2prfc
	@echo "Run the program as ./if2prfc < input.txt"

y.tab.c: if2prfc.y 
	yacc -d --report=itemsets,states,lookaheads -g if2prfc.y

lex.yy.c: if2prfc.l y.tab.h
	lex if2prfc.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c if2prfc *.output *.gv *.svg
```
## y.output
```
Rules useless in parser due to conflicts

    2 $@1: %empty

    5 $@2: %empty


State 0 conflicts: 2 shift/reduce, 2 reduce/reduce
State 1 conflicts: 2 shift/reduce, 2 reduce/reduce
State 5 conflicts: 2 shift/reduce, 2 reduce/reduce
State 7 conflicts: 2 shift/reduce
State 14 conflicts: 2 shift/reduce


Grammar

    0 $accept: S $end

    1 S: E

    2 $@1: %empty

    3 E: $@1 E ADD T
    4  | T

    5 $@2: %empty

    6 T: $@2 T MUL F
    7  | F

    8 F: LPAR E RPAR
    9  | NUM


Terminals, with rules where they appear

    $end (0) 0
    error (256)
    ADD (258) 3
    MUL (259) 6
    LPAR (260) 8
    RPAR (261) 8
    NUM (262) 9


Nonterminals, with rules where they appear

    $accept (8)
        on left: 0
    S (9)
        on left: 1
        on right: 0
    E (10)
        on left: 3 4
        on right: 1 3 8
    $@1 (11)
        on left: 2
        on right: 3
    T (12)
        on left: 6 7
        on right: 3 4 6
    $@2 (13)
        on left: 5
        on right: 6
    F (14)
        on left: 8 9
        on right: 6 7


State 0

    0 $accept: . S $end
    1 S: . E
    2 $@1: %empty .  [LPAR, NUM]
    3 E: . $@1 E ADD T
    4  | . T
    5 $@2: %empty .  [LPAR, NUM]
    6 T: . $@2 T MUL F
    7  | . F
    8 F: . LPAR E RPAR
    9  | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    LPAR  [reduce using rule 2 ($@1)]
    LPAR  [reduce using rule 5 ($@2)]
    NUM   [reduce using rule 2 ($@1)]
    NUM   [reduce using rule 5 ($@2)]

    S    go to state 3
    E    go to state 4
    $@1  go to state 5
    T    go to state 6
    $@2  go to state 7
    F    go to state 8


State 1

    2 $@1: %empty .  [LPAR, NUM]
    3 E: . $@1 E ADD T
    4  | . T
    5 $@2: %empty .  [LPAR, NUM]
    6 T: . $@2 T MUL F
    7  | . F
    8 F: . LPAR E RPAR
    8  | LPAR . E RPAR
    9  | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    LPAR  [reduce using rule 2 ($@1)]
    LPAR  [reduce using rule 5 ($@2)]
    NUM   [reduce using rule 2 ($@1)]
    NUM   [reduce using rule 5 ($@2)]

    E    go to state 9
    $@1  go to state 5
    T    go to state 6
    $@2  go to state 7
    F    go to state 8


State 2

    9 F: NUM .

    $default  reduce using rule 9 (F)


State 3

    0 $accept: S . $end

    $end  shift, and go to state 10


State 4

    1 S: E .

    $default  reduce using rule 1 (S)


State 5

    2 $@1: %empty .  [LPAR, NUM]
    3 E: . $@1 E ADD T
    3  | $@1 . E ADD T
    4  | . T
    5 $@2: %empty .  [LPAR, NUM]
    6 T: . $@2 T MUL F
    7  | . F
    8 F: . LPAR E RPAR
    9  | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    LPAR  [reduce using rule 2 ($@1)]
    LPAR  [reduce using rule 5 ($@2)]
    NUM   [reduce using rule 2 ($@1)]
    NUM   [reduce using rule 5 ($@2)]

    E    go to state 11
    $@1  go to state 5
    T    go to state 6
    $@2  go to state 7
    F    go to state 8


State 6

    4 E: T .

    $default  reduce using rule 4 (E)


State 7

    5 $@2: %empty .  [LPAR, NUM]
    6 T: . $@2 T MUL F
    6  | $@2 . T MUL F
    7  | . F
    8 F: . LPAR E RPAR
    9  | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    LPAR  [reduce using rule 5 ($@2)]
    NUM   [reduce using rule 5 ($@2)]

    T    go to state 12
    $@2  go to state 7
    F    go to state 8


State 8

    7 T: F .

    $default  reduce using rule 7 (T)


State 9

    8 F: LPAR E . RPAR

    RPAR  shift, and go to state 13


State 10

    0 $accept: S $end .

    $default  accept


State 11

    3 E: $@1 E . ADD T

    ADD  shift, and go to state 14


State 12

    6 T: $@2 T . MUL F

    MUL  shift, and go to state 15


State 13

    8 F: LPAR E RPAR .

    $default  reduce using rule 8 (F)


State 14

    3 E: $@1 E ADD . T
    5 $@2: %empty .  [LPAR, NUM]
    6 T: . $@2 T MUL F
    7  | . F
    8 F: . LPAR E RPAR
    9  | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    LPAR  [reduce using rule 5 ($@2)]
    NUM   [reduce using rule 5 ($@2)]

    T    go to state 16
    $@2  go to state 7
    F    go to state 8


State 15

    6 T: $@2 T MUL . F
    8 F: . LPAR E RPAR
    9  | . NUM

    LPAR  shift, and go to state 1
    NUM   shift, and go to state 2

    F  go to state 17


State 16

    3 E: $@1 E ADD T .

    $default  reduce using rule 3 (E)


State 17

    6 T: $@2 T MUL F .

    $default  reduce using rule 6 (T)
```
![Automaton](https://github.com/SET-IITGN/CS-327-Compilers/blob/main/infix_to_prefix_conflicts/y.svg)

## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/infix_to_prefix_conflicts$ ./if2prfc 
4+7
syntax error
4
```

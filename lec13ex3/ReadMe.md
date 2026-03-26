# Bottom-Up parsing: LR(1) automaton
### Grammar
```
S'→ S
S → C C
C → c C | d
```

## ``lec13ex3.l``
```
%{
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

c|d		{return(*yytext);}
.|\n	{;}

%%

int yywrap(void) {
    return 1;
}
```
## ``lec13ex3.y``
```
%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	extern char *yytext;
%}
%start Start

%%

Start: 	S {printf("Rule used: Start -> S\n");}
		;

S:		C C {printf("Rule used: S -> C C\n");}
		;

C:		'c' C {printf("Rule used: C -> c C\n");}
		| 'd' {printf("Rule used: C -> d\n");}
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
## ``Makefile``
```
a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o lec13ex3
	@echo "Run the program as ./lec13ex3 < input.txt"

y.tab.c: lec13ex3.y 
	yacc -d --report=itemsets,states,lookaheads -g lec13ex3.y

lex.yy.c: lec13ex3.l y.tab.h
	lex lec13ex3.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c lec13ex3 *.output *.gv
```
## ``y.output``
```
Grammar

    0 $accept: Start $end

    1 Start: S

    2 S: C C

    3 C: 'c' C
    4  | 'd'


Terminals, with rules where they appear

    $end (0) 0
    'c' (99) 3
    'd' (100) 4
    error (256)


Nonterminals, with rules where they appear

    $accept (5)
        on left: 0
    Start (6)
        on left: 1
        on right: 0
    S (7)
        on left: 2
        on right: 1
    C (8)
        on left: 3 4
        on right: 2 3


State 0

    0 $accept: . Start $end
    1 Start: . S
    2 S: . C C
    3 C: . 'c' C
    4  | . 'd'

    'c'  shift, and go to state 1
    'd'  shift, and go to state 2

    Start  go to state 3
    S      go to state 4
    C      go to state 5


State 1

    3 C: . 'c' C
    3  | 'c' . C
    4  | . 'd'

    'c'  shift, and go to state 1
    'd'  shift, and go to state 2

    C  go to state 6


State 2

    4 C: 'd' .

    $default  reduce using rule 4 (C)


State 3

    0 $accept: Start . $end

    $end  shift, and go to state 7


State 4

    1 Start: S .

    $default  reduce using rule 1 (Start)


State 5

    2 S: C . C
    3 C: . 'c' C
    4  | . 'd'

    'c'  shift, and go to state 1
    'd'  shift, and go to state 2

    C  go to state 8


State 6

    3 C: 'c' C .

    $default  reduce using rule 3 (C)


State 7

    0 $accept: Start $end .

    $default  accept


State 8

    2 S: C C .

    $default  reduce using rule 2 (S)
```
![LR(0) Automaton](https://github.com/SET-IITGN/CS-327-Compilers/blob/main/lec13ex3/y.svg)

## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/lec13ex3$ ./lec13ex3 
cdd
Rule used: C -> d
Rule used: C -> c C
Rule used: C -> d
Rule used: S -> C C
Rule used: Start -> S
```

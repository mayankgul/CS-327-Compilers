# Bottom-Up parsing: LR(1) automaton, State Merging in LALR with conflicts
### Grammar
```
S'→ S
S → a A d | b B d | a B e | b A e
A → c
B → c
```

## ``lec13ex4.l``
```
%{
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

[a-e]		{return(*yytext);}
.|\n	{;}

%%

int yywrap(void) {
    return 1;
}
```
## ``lec13ex4.y``
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

S:		'a' A 'd' {printf("Rule used: S -> a A d\n");}
		| 'b' B 'd' {printf("Rule used: S -> b B d\n");}
		| 'a' B 'e' {printf("Rule used: S -> a B e\n");}
		| 'b' A 'e' {printf("Rule used: S -> b A e\n");}
		;
		
A:		'c' {printf("Rule used: A -> c\n");}
		;
		
B: 		'c' {printf("Rule used: B -> c\n");}
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
	gcc lex.yy.c y.tab.c -o lec13ex4
	@echo "Run the program as ./lec13ex4 < input.txt"

y.tab.c: lec13ex4.y 
	yacc -d --report=itemsets,states,lookaheads -g lec13ex4.y

lex.yy.c: lec13ex4.l y.tab.h
	lex lec13ex4.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c lec13ex4 *.output *.gv
```
## ``y.output``
```
Rules useless in parser due to conflicts

    7 B: 'c'


State 5 conflicts: 2 reduce/reduce


Grammar

    0 $accept: Start $end

    1 Start: S

    2 S: 'a' A 'd'
    3  | 'b' B 'd'
    4  | 'a' B 'e'
    5  | 'b' A 'e'

    6 A: 'c'

    7 B: 'c'


Terminals, with rules where they appear

    $end (0) 0
    'a' (97) 2 4
    'b' (98) 3 5
    'c' (99) 6 7
    'd' (100) 2 3
    'e' (101) 4 5
    error (256)


Nonterminals, with rules where they appear

    $accept (8)
        on left: 0
    Start (9)
        on left: 1
        on right: 0
    S (10)
        on left: 2 3 4 5
        on right: 1
    A (11)
        on left: 6
        on right: 2 5
    B (12)
        on left: 7
        on right: 3 4


State 0

    0 $accept: . Start $end
    1 Start: . S
    2 S: . 'a' A 'd'
    3  | . 'b' B 'd'
    4  | . 'a' B 'e'
    5  | . 'b' A 'e'

    'a'  shift, and go to state 1
    'b'  shift, and go to state 2

    Start  go to state 3
    S      go to state 4


State 1

    2 S: 'a' . A 'd'
    4  | 'a' . B 'e'
    6 A: . 'c'
    7 B: . 'c'

    'c'  shift, and go to state 5

    A  go to state 6
    B  go to state 7


State 2

    3 S: 'b' . B 'd'
    5  | 'b' . A 'e'
    6 A: . 'c'
    7 B: . 'c'

    'c'  shift, and go to state 5

    A  go to state 8
    B  go to state 9


State 3

    0 $accept: Start . $end

    $end  shift, and go to state 10


State 4

    1 Start: S .

    $default  reduce using rule 1 (Start)


State 5

    6 A: 'c' .  ['d', 'e']
    7 B: 'c' .  ['d', 'e']

    'd'       reduce using rule 6 (A)
    'd'       [reduce using rule 7 (B)]
    'e'       reduce using rule 6 (A)
    'e'       [reduce using rule 7 (B)]
    $default  reduce using rule 6 (A)


State 6

    2 S: 'a' A . 'd'

    'd'  shift, and go to state 11


State 7

    4 S: 'a' B . 'e'

    'e'  shift, and go to state 12


State 8

    5 S: 'b' A . 'e'

    'e'  shift, and go to state 13


State 9

    3 S: 'b' B . 'd'

    'd'  shift, and go to state 14


State 10

    0 $accept: Start $end .

    $default  accept


State 11

    2 S: 'a' A 'd' .

    $default  reduce using rule 2 (S)


State 12

    4 S: 'a' B 'e' .

    $default  reduce using rule 4 (S)


State 13

    5 S: 'b' A 'e' .

    $default  reduce using rule 5 (S)


State 14

    3 S: 'b' B 'd' .

    $default  reduce using rule 3 (S)
```
![LR(0) Automaton](https://github.com/SET-IITGN/CS-327-Compilers/blob/main/lec13ex4/y.svg)

## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/lec13ex4$ ./lec13ex4
bce
Rule used: A -> c
Rule used: S -> b A e
Rule used: Start -> S
```

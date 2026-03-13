%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
%}
%start Start

%%

Start: 	S {printf("Rule used: Start -> S\n");}
		;

S:		A S {printf("Rule used: S -> A S\n");}
		| 'b' {printf("Rule used: S -> b\n");}
		;
		
A:		S A {printf("Rule used: A -> S A\n");}
		| 'a' {printf("Rule used: A -> a\n");}
		;
		
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
    return 0;
}

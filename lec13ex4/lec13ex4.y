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

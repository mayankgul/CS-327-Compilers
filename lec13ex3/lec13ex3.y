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

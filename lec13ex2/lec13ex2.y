%token ID
%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	extern char *yytext;
%}
%start Start

%%

Start: 	S {printf("Rule used: Start -> S\n");}
		;

S:		L '=' R {printf("Rule used: S -> L = R\n");}
		| R	{printf("Rule used: S -> R\n");}
		;

L:		'*' R {printf("Rule used: L -> * R\n");}
		| ID {printf("Rule used: L -> ID\n");}
		;

R:		L {printf("Rule used: R -> L\n");}
		;
				

		
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
    return 0;
}

%token ADD MUL NUM
%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	extern char *yytext;
%}
%start S

%%

S:	E {$$=$1;printf("%d\n",$$);}
	;
	
E:	E MUL T {$$=$1*$3;}
  	| T {$$=$1;}
	;

T:	T ADD F {$$=$1+$3;}
  	| F {$$=$1;}	
  	;

F:	NUM {$$=atoi(yytext);}
	;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}


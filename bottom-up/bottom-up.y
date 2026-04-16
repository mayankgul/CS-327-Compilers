%token ADD MUL NUM LPAR RPAR
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

Start: 	E 
		{
			$$=$1;
			printf("rule used: Start -> E\n");
			printf("The final output is %d\n",$$);
		}
		;

E:		E ADD T 
		{
			$$=$1+$3;
			printf("rule used: E -> E + T\n");
		}
  		| T 
  		{
  			$$=$1;
  			printf("rule used: E -> T\n");
  		}
		;

T:		T MUL F 
		{
			$$=$1*$3;
			printf("rule used: T -> T * F\n");
		}
  		| F 
  		{
  			$$=$1;
  			printf("rule used: T -> F\n");
  		}	
  		;

F:		LPAR E RPAR 
		{
			$$=$2;
			printf("rule used: F -> ( E )\n");
		}		
		| NUM 
		{
			$$=atoi(yytext);
			printf("rule used: F -> id [%d]\n",$$);
		}
		;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
    return 0;
}

%{
#include<stdio.h>
#include<string.h>
void yyerror(char *);
int s=0,h=0,time=0;
%}

%%

she		{
			s++;
			time++;
			printf("t=%d, line %d: lexeme (%s) of length %d, --> regex \"she\" matched\n",time,yylineno,yytext,yyleng);
		}
		
he		{
			h++;
			time++;
			printf("t=%d, line %d: lexeme (%s) of length %d, --> regex \"he\" matched\n",time,yylineno,yytext,yyleng);
		}

. 		{
			char buff[1024]={'\0'}; 
			sprintf(buff,"t=%d, line %d: lexeme (%s) of length %d, --> none matched\n",time,yylineno,yytext,yyleng);
			yyerror(buff);
		}
		
\n 		{
			yylineno++;
		}

%%

void yyerror(char *msg)
{
	printf("lexical error: %s",msg);
}

int main()
{
	yylex();
	printf("he=%d,she=%d\n",h,s);
	return(0);
}

%{
#include<stdio.h>
%}

%%

a(a|b)*a {printf("lexeme (%s) matches the regex for strings over alphabet {a, b} that start and end with a\n",yytext);REJECT;}

(a|b)*a(a|b)(a|b) {printf("lexeme (%s) matches the regex for strings over alphabet {a, b} with third last letter as a\n",yytext);REJECT;}

a*ba*ba*ba* {printf("lexeme (%s) matches the regex for strings over alphabet {a, b} with exactly three bs\n",yytext);REJECT;}

((a|b)(a|b))* {printf("lexeme (%s) matches the regex for strings over alphabet {a, b} with even length\n",yytext);REJECT;}

. {printf("lexeme (%s) does not match any regex of our interest\n",yytext);}

%%

int main()
{
	yylex();
	return(0);
}

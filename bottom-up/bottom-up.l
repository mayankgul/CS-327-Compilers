%{
	#include <stdlib.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

"+"			{return ADD;}
"*" 		{return MUL;}
"(" 		{return LPAR;}
")" 		{return RPAR;}
[0-9]+		{strcpy(mytext, yytext); return NUM;}
.|\n		{;}

%%

int yywrap(void) {
    return 1;
}



%{
	#include <stdlib.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

"+"		{return ADD;}
"*"  	{return MUL;}
[0-9]+	{strcpy(mytext, yytext); return NUM;}
.|\n	{;}

%%

int yywrap(void) {
    return 1;
}



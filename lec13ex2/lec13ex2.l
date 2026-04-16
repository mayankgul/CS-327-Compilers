%{
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

[a-z A-Z]	{strcpy(mytext, yytext); return ID;}
'='|'*'		{return(*yytext);}
.|\n		{;}

%%

int yywrap(void) {
    return 1;
}



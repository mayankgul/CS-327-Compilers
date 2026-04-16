%{
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

[a-e]		{return(*yytext);}
.|\n	{;}

%%

int yywrap(void) {
    return 1;
}



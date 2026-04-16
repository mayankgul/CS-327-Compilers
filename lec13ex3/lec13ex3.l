%{
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

c|d		{return(*yytext);}
.|\n	{;}

%%

int yywrap(void) {
    return 1;
}



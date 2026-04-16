%{
	#include <stdlib.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

a|b		{return(*yytext);}
.|\n		{;}

%%

int yywrap(void) {
    return 1;
}



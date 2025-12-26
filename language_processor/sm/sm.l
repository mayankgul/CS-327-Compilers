%{
#include "y.tab.h"
#include "symbol.h"
%}
%%
echo {return DISP;}

[\n\t ] {;}

"-" {return *yytext;}

"<<" {return LEFT_SHIFT;}

"**" {return POWER;}

">>" {return RIGHT_SHIFT;}

"<=" {return LE;}

">=" {return GE;}

"==" {return EEQ;}

"!=" {return NE;}

"&&" {return AND_AND;}

"||" {return OR_OR;}

[%!~<>&|?^+*$:,/=()@] {return *yytext;}

-?[0-9][0-9]* {
		yylval.val=atoi(yytext);
		return(NUMBER);
	    }
[a-zA-Z_][_a-zA-Z0-9]* {
				yylval.symp=symlook(yytext);
				return(NAME);
			}
"#".*\n {BEGIN INITIAL;}
%%
yywrap()
{}



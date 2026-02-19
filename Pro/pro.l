%{
#include "y.tab.h"
char saux;
%}
%%
"<->" {return BICOND; }

"->" {return IMP;}

"~" {return NOT;}

"&" {return AND;}

"#" {return OR;}

"(" {saux='('; return LEFT_PAR;}

")" {return RIGHT_PAR;}

"T" {return TRUE;}

"F" {return FALSE;}

[A-Z] {return(ATOM);}

. {return(ERROR);}
%%
yywrap()
{}

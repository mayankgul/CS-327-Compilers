%token ADD MUL NUM SUB DIV THEN SEM IF ELSE LPAR RPAR LBRACE RBRACE
%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	extern char *yytext;
	int time;
	FILE *fp;
%}
%start Start

%%

Start: 	S {$$=$1;printf("rule used: Start -> S\n");fprintf(fp,"\"(%d) Start\" -> \"(%d) S\"",time+1,time);printf("The final output is %d\n",$$);time++;}
		;

S:		MS {$$=$1;printf("rule used: S -> MS\n");fprintf(fp,"\"(%d) S\" -> \"(%d) MS\"",time+1,time);time++;}
		| OS {$$=$1;printf("rule used: S -> OS\n");fprintf(fp,"\"(%d) S\" -> \"(%d) OS\"",time+1,time);time++;}
		;

MS: 	IF E THEN MS ELSE MS {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: MS -> if E then MS else MS\n");fprintf(fp,"\"(%d) MS\" -> \"(%d) if E then MS else MS\"",time+1,time);time++;}
		| SEM {$$=1;printf("rule used: MS -> ;\n");fprintf(fp,"\"(%d) MS\" -> \"(%d) ;\"",time+1,time);time++;}
		| SEM MS {$$=$2;printf("rule used: MS -> ; MS\n");fprintf(fp,"\"(%d) MS\" -> \"(%d) ; MS\"",time+1,time);time++;}
		| LBRACE MS RBRACE {$$=$2;printf("rule used: MS -> { MS }\n");fprintf(fp,"\"(%d) MS\" -> \"(%d) { MS }\"",time+1,time);time++;}
		;
		
OS:		IF E THEN S {$$=($2!=0)?$4:0;$$*=$2;printf("rule used: OS -> if E then S\n");fprintf(fp,"\"(%d) OS\" -> \"(%d) if E then S\"",time+1,time);time++;}
		| IF E THEN MS ELSE OS {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: OS -> if E then MS else OS\n");fprintf(fp,"\"(%d) OS\" -> \"(%d) if E then MS else OS\"",time+1,time);time++;}
		| LBRACE OS RBRACE {$$=$2;printf("rule used: OS -> { OS }\n");fprintf(fp,"\"(%d) OS\" -> \"(%d) { OS }\"",time+1,time);time++;}
		;
		
E:		E ADD T {$$=$1+$3;printf("rule used: E -> E + T\n");fprintf(fp,"\"(%d) E\" -> \"(%d) E + T\"",time+1,time);time++;}
		| E SUB T {$$=$1-$3;printf("rule used: E -> E - T\n");fprintf(fp,"\"(%d) E\" -> \"(%d) E - T\"",time+1,time);time++;}
  		| T {$$=$1;printf("rule used: E -> T\n");fprintf(fp,"\"(%d) E\" -> \"(%d) T\"",time+1,time);time++;}
		;

T:		T MUL F {$$=$1*$3;printf("rule used: T -> T * F\n");fprintf(fp,"\"(%d) T\" -> \"(%d) T * F\"",time+1,time);time++;}
		| T DIV F {$$=$1/$3;printf("rule used: T -> T / F\n");fprintf(fp,"\"(%d) T\" -> \"(%d) T / F\"",time+1,time);time++;}
  		| F {$$=$1;printf("rule used: T -> F\n");fprintf(fp,"\"(%d) T\" -> \"(%d) F\"",time+1,time);time++;}	
  		;

F:		LPAR E RPAR {$$=$2;printf("rule used: F -> ( E )\n");fprintf(fp,"\"(%d) F\" -> \"(%d) ( E )\"",time+1,time);time++;}		
		| NUM {$$=atoi(yytext); printf("rule used: F -> num -> %d\n",$$);fprintf(fp,"\"(%d) F\" -> \"(%d) num \'%d\'\"",time+1,time,$$);time++;}
		;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
	time=1;
	fp=fopen("parse_forest.dot","wt");
	if(fp==NULL)
	{
		printf("Error opening file [parse_forest.dot]\n");
		exit(-1);
	}
	
	fprintf(fp,"digraph parse_forest {\n");
	yyparse();
	fprintf(fp,"\n}\n");
	fclose(fp);
	fp=NULL;
    return 0;
}

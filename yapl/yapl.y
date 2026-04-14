
%{

//  TAC (Quadruple) structure
int temp_count = 0;

typedef struct {
    char op[10];
    char arg1[20];
    char arg2[20];
    char result[20];
} quad;

quad quads[1000];
int quad_index = 0;
int label_count = 0;
char *last_false_label;
char *last_start_label;
char *last_end_label;

//  Generate temporary variables (t1, t2, ...)
char* new_temp() {
    char *temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

//  Generate labels (L0, L1, ...)
char* new_label() {
    char *label = (char*)malloc(20);
    sprintf(label, "L%d", label_count++);
    return label;
}

//  Add a quadruple
void add_quad(char *op, char *arg1, char *arg2, char *result) {
    strcpy(quads[quad_index].op, op);
    strcpy(quads[quad_index].arg1, arg1);
    strcpy(quads[quad_index].arg2, arg2);
    strcpy(quads[quad_index].result, result);
    quad_index++;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "table_data.h"

char derivations[1000][200];
int dtop = 0;

extern int line_no;
extern char *yytext;
int yylex(void);
void yyerror(const char *s)
{
    fprintf(stderr, "\nSyntax Error at line %d near token '%s'\n", line_no, yytext);
    exit(1);
}
int global_declarations=0;
int func_definitions=0;
int int_consts=0;
int pointer_decls=0;
int ifs_wo_else=0;
int ladder_len=0,hold=0;
int max=-1;
%}

%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP TH_OP PEQ_OP MEQ_OP STREQ_OP DEQ_OP MODEQ_OP TER_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL
%type <place> expression assignment_expression additive_expression multiplicative_expression primary_expression constant string generic_selection generic_assoc_list generic_association postfix_expression unary_expression cast_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression expression_statement selection_statement iteration_statement statement

%type <op> assignment_operator


%nonassoc IFX
%nonassoc ELSE
%right '='
%left ','

%start translation_unit

%type <val> IF
%type <val> ELSE

%union
{
	int val;
	char* place;
	char* op;
	struct symtab *symp;
}

%%

primary_expression
	: IDENTIFIER {
		$$ = strdup(yytext);
	}
	| constant
	| string
| '(' expression ')' { $$ = $2; }
	| generic_selection
	;

constant
	: I_CONSTANT {
		int_consts++;
		$$ = strdup(yytext);
	}
	| F_CONSTANT {
		$$ = strdup(yytext);
	}
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER
	;

string
	: STRING_LITERAL {
		$$ = strdup(yytext);
	}
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')' { $$ = $3; }
	;

generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	;

generic_association
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '[' expression ']' { $$ = $1; }
	| postfix_expression '(' argument_expression_list_opt ')' { $$ = $1; }
	| postfix_expression '.' IDENTIFIER { $$ = $1; }
	| postfix_expression PTR_OP IDENTIFIER { $$ = $1; }
	| postfix_expression INC_OP { $$ = $1; }
	| postfix_expression DEC_OP { $$ = $1; }
	| '(' type_name ')' '{' initializer_list '}' { $$ = NULL; }
	| '(' type_name ')' '{' initializer_list ',' '}' { $$ = NULL; }
	;
	
argument_expression_list_opt
	: /* empty */          
	| argument_expression_list   
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression { $$ = $1; }
	| INC_OP unary_expression { $$ = $2; }
	| DEC_OP unary_expression { $$ = $2; }
	| unary_operator cast_expression { $$ = $2; }
	| SIZEOF unary_expression { $$ = NULL; }
	| SIZEOF '(' type_name ')' { $$ = NULL; }
	| ALIGNOF '(' type_name ')' { $$ = NULL; }
	| '-' unary_expression {
		$$ = new_temp();
		add_quad("uminus", $2, "", $$);}
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression { $$ = $1; }
	| '(' type_name ')' cast_expression { $$ = $4; }
	;

multiplicative_expression
	: cast_expression { $$ = $1; }
	| multiplicative_expression '*' cast_expression {
		$$ = new_temp();
		add_quad("*", $1, $3, $$);
	}
	| multiplicative_expression '/' cast_expression {
		$$ = new_temp();
		add_quad("/", $1, $3, $$);
	}
	| multiplicative_expression '%' cast_expression {
		$$ = new_temp();
		add_quad("%", $1, $3, $$);
	}
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression {
		$$ = new_temp();
		add_quad("+", $1, $3, $$);
	}
	| additive_expression '-' multiplicative_expression {
		$$ = new_temp();
		add_quad("-", $1, $3, $$);
	}
	;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression LEFT_OP additive_expression {
		$$ = new_temp();
		add_quad("<<", $1, $3, $$);
	}
	| shift_expression RIGHT_OP additive_expression {
		$$ = new_temp();
		add_quad(">>", $1, $3, $$);
	}
	;

relational_expression
	: shift_expression { $$ = $1; }
    | relational_expression '<' shift_expression {
        $$ = new_temp();
        add_quad("<", $1, $3, $$);
    }
    | relational_expression '>' shift_expression {
        $$ = new_temp();
        add_quad(">", $1, $3, $$);
    }
    | relational_expression LE_OP shift_expression {
        $$ = new_temp();
        add_quad("<=", $1, $3, $$);
    }
    | relational_expression GE_OP shift_expression {
        $$ = new_temp();
        add_quad(">=", $1, $3, $$);
    }
    | relational_expression TH_OP shift_expression {
        $$ = new_temp();
        add_quad("<=>", $1, $3, $$);
    }
    ;

equality_expression
	: relational_expression { $$ = $1; }
    | equality_expression EQ_OP relational_expression {
        $$ = new_temp();
        add_quad("==", $1, $3, $$);
    }
    | equality_expression NE_OP relational_expression {
        $$ = new_temp();
        add_quad("!=", $1, $3, $$);
    }
    ;

and_expression
	: equality_expression { $$ = $1; }
	| and_expression '&' equality_expression {
		$$ = new_temp();
		add_quad("&", $1, $3, $$);
	}
	;

exclusive_or_expression
	: and_expression { $$ = $1; }
	| exclusive_or_expression '^' and_expression {
		$$ = new_temp();
		add_quad("^", $1, $3, $$);
	}
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression {
		$$ = new_temp();
		add_quad("|", $1, $3, $$);
	}
	;

logical_and_expression
	: inclusive_or_expression { $$ = $1; }
    | logical_and_expression AND_OP inclusive_or_expression {
        $$ = new_temp();
        add_quad("&&", $1, $3, $$);
    }
    ;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression {
        $$ = new_temp();
        add_quad("||", $1, $3, $$);
    }
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression { $$ = $1; }
	;

assignment_expression
	: conditional_expression {
		$$ = $1;
		sprintf(derivations[dtop++], "assignment_expression -> conditional_expression");
	}
	| unary_expression assignment_operator assignment_expression {
		if (strcmp($2, "=") == 0) {
			add_quad("=", $3, "", $1);
		} else {
			char *tmp = new_temp();
			add_quad($2, $1, $3, tmp);
			add_quad("=", tmp, "", $1);
		}
		$$ = $1;
		sprintf(derivations[dtop++], "assignment_expression -> unary_expression assignment_operator assignment_expression");
	}
	;

assignment_operator
	: '=' { $$ = strdup("="); }
	| MUL_ASSIGN { $$ = strdup("*"); }
	| DIV_ASSIGN { $$ = strdup("/"); }
	| MOD_ASSIGN { $$ = strdup("%"); }
	| ADD_ASSIGN { $$ = strdup("+"); }
	| SUB_ASSIGN { $$ = strdup("-"); }
	| LEFT_ASSIGN { $$ = strdup("<<"); }
	| RIGHT_ASSIGN { $$ = strdup(">>"); }
	| AND_ASSIGN { $$ = strdup("&"); }
	| XOR_ASSIGN { $$ = strdup("^"); }
	| OR_ASSIGN { $$ = strdup("|"); }
	| PEQ_OP { $$ = strdup("+"); }
	| MEQ_OP { $$ = strdup("-"); }
	| STREQ_OP { $$ = strdup("*"); }
	| DEQ_OP { $$ = strdup("/"); }
	| MODEQ_OP { $$ = strdup("%"); }
	;

expression
	: assignment_expression {
		$$ = $1;
		sprintf(derivations[dtop++], "expression -> assignment_expression");
	}
	| expression ',' assignment_expression {
		$$ = $3;
		sprintf(derivations[dtop++], "expression -> expression , assignment_expression");
	}
	;

constant_expression
	: conditional_expression	/* with constraints */
	;

declaration
	: declaration_specifiers ';' {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers ;");
	}
	| declaration_specifiers init_declarator_list ';' {
		sprintf(derivations[dtop++], "declaration -> declaration_specifiers init_declarator_list ;");
	}
	| static_assert_declaration {
		sprintf(derivations[dtop++], "declaration -> static_assert_declaration");
	}
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
	| storage_class_specifier
	| type_specifier declaration_specifiers
	| type_specifier
	| type_qualifier declaration_specifiers
	| type_qualifier
	| function_specifier declaration_specifiers
	| function_specifier
	| alignment_specifier declaration_specifiers
	| alignment_specifier
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator '=' initializer
	| declarator
	;

storage_class_specifier
	: TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
	| EXTERN
	| STATIC
	| THREAD_LOCAL
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY	  	/* non-mandated extension */
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME		/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list ';'	/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'
	| static_assert_declaration
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: ':' constant_expression
	| declarator ':' constant_expression
	| declarator
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression
	| enumeration_constant
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'
	;

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	  //| ATOMIC
	;

function_specifier
	: INLINE
	| NORETURN
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;

declarator
	: pointer direct_declarator {pointer_decls++;}
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	| direct_declarator '(' parameter_type_list ')' 
	| direct_declarator '(' ')'
	| direct_declarator '(' identifier_list ')'
	;

pointer
	: '*' type_qualifier_list pointer
	| '*' type_qualifier_list
	| '*' pointer
	| '*'
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS
	| parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' '*' ']'
	| '[' STATIC type_qualifier_list assignment_expression ']'
	| '[' STATIC assignment_expression ']'
	| '[' type_qualifier_list STATIC assignment_expression ']'
	| '[' type_qualifier_list assignment_expression ']'
	| '[' type_qualifier_list ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' '*' ']'
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| assignment_expression
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	;

statement
	: error ';' {
        printf("Recovered from error at line %d near token '%s'\n", line_no, yytext);
        yyerrok;
    }
	| labeled_statement {
		sprintf(derivations[dtop++], "statement -> labeled_statement");
	}
	| compound_statement {
		sprintf(derivations[dtop++], "statement -> compound_statement");
	}
	| expression_statement {
		sprintf(derivations[dtop++], "statement -> expression_statement");
	}
	| selection_statement {
		sprintf(derivations[dtop++], "statement -> selection_statement");
	}
	| iteration_statement {
		sprintf(derivations[dtop++], "statement -> iteration_statement");
	}
	| jump_statement {
		sprintf(derivations[dtop++], "statement -> jump_statement");
	}
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}' {
		sprintf(derivations[dtop++], "compound_statement -> { }");
	}
	| '{' block_item_list '}' {
		sprintf(derivations[dtop++], "compound_statement -> { block_item_list }");
	}
	;

block_item_list
	: block_item {
		sprintf(derivations[dtop++], "block_item_list -> block_item");
	}
	| block_item_list block_item {
		sprintf(derivations[dtop++], "block_item_list -> block_item_list block_item");
	}
	;

block_item
	: declaration {
		sprintf(derivations[dtop++], "block_item -> declaration");
	}
	| statement {
		sprintf(derivations[dtop++], "block_item -> statement");
	}
	;

expression_statement
	: ';' {
		$$ = NULL;
		sprintf(derivations[dtop++], "expression_statement -> ;");
	}
	| expression ';' {
		$$ = $1;
		sprintf(derivations[dtop++], "expression_statement -> expression ;");
	}
	;

selection_statement
	: IF '(' expression ')'
	{
		last_false_label = new_label();
		add_quad("iffalse", $3, "", last_false_label);
	}
	statement %prec IFX
	{
		add_quad("label", "", "", last_false_label);
	}

	| IF '(' expression ')'
	{
		last_false_label = new_label();
		add_quad("iffalse", $3, "", last_false_label);
	}
	statement
	{
		last_end_label = new_label();
		add_quad("goto", "", "", last_end_label);
		add_quad("label", "", "", last_false_label);
	}
	ELSE
	statement
	{
		add_quad("label", "", "", last_end_label);
	}
    ;

iteration_statement
	: WHILE '(' expression ')'
		{
			last_start_label = new_label();
			last_end_label = new_label();

			add_quad("label", "", "", last_start_label);
			add_quad("iffalse", $3, "", last_end_label);
		}
	statement
		{
			add_quad("goto", "", "", last_start_label);
			add_quad("label", "", "", last_end_label);
		}
	|DO
	{
		last_start_label = new_label();
		add_quad("label", "", "", last_start_label);
	}
	statement
	WHILE '(' expression ')' ';'
	{
		add_quad("ifgoto", $6, "", last_start_label);
	}
	|FOR '(' expression_statement expression_statement expression ')' 
	{
		last_start_label = new_label();
		last_end_label = new_label();

		add_quad("label", "", "", last_start_label);
		add_quad("iffalse", $4, "", last_end_label);
	}
	statement
	{
		// update expression (3rd expression)
		add_quad("eval", $5, "", "");

		add_quad("goto", "", "", last_start_label);
		add_quad("label", "", "", last_end_label);
	}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> external_declaration");
	}
	| translation_unit external_declaration {
		global_declarations++;
		sprintf(derivations[dtop++], "translation_unit -> translation_unit external_declaration");
	}
	;

external_declaration
	: function_definition {func_definitions++;}
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator declaration_list compound_statement");
	}
	| declaration_specifiers declarator compound_statement {
		sprintf(derivations[dtop++], "function_definition -> declaration_specifiers declarator compound_statement");
	}
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

%%
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buff[2048];

int yylex(void);
int mode=-1;

/*
void yyerror(const char *s)
{
	fflush(stdout);
	
	if(mode==-1)
		printf("***parsing terminated*** [syntax error]\n");
	else if(mode==0 || mode==1)
		printf("%s\n",s);
		
	exit(-1);
}
*/

void print_parsing_table() {
    printf("\nLALR(1) PARSING TABLE (Sparse Format)\n");
    printf("======================================\n");
    printf("%-10s | %-s\n", "State", "Actions / Transitions");
    printf("-----------|----------------------------------\n");

    for (int i = 0; i < NUM_STATES; i++) {
        printf("State %-4d | ", i);
        int transitions_found = 0;
        for (int j = 0; j < (NUM_TERMS + NUM_NON_TERMS); j++) {
            if (strlen(parsing_table[i][j]) > 0) {
                const char* sym_name = (j < NUM_TERMS) ? terminals[j] : non_terminals[j - NUM_TERMS];
                printf("[%s: %s] ", sym_name, parsing_table[i][j]);
                transitions_found = 1;
            }
        }
        if (!transitions_found) printf("-");
        printf("\n");
    }
}

void export_parsing_table_to_csv() {
    FILE *fp = fopen("parsing_table.csv", "w");
    if (fp == NULL) {
        printf("Error opening file for CSV export!\n");
        return;
    }

    // Write Header: State, then all terminal names, then all non-terminal names
    fprintf(fp, "State");
    for (int i = 0; i < NUM_TERMS; i++) {
        fprintf(fp, ",%s", terminals[i]);
    }
    for (int i = 0; i < NUM_NON_TERMS; i++) {
        fprintf(fp, ",%s", non_terminals[i]);
    }
    fprintf(fp, "\n");

    // Write Data Rows
    for (int i = 0; i < NUM_STATES; i++) {
        fprintf(fp, "%d", i); // State number
        for (int j = 0; j < (NUM_TERMS + NUM_NON_TERMS); j++) {
            // Check if the cell has an action
            if (parsing_table[i][j] && strlen(parsing_table[i][j]) > 0) {
                fprintf(fp, ",%s", parsing_table[i][j]);
            } else {
                fprintf(fp, ",-"); // Empty cell
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("\nSuccessfully exported LALR(1) table to 'parsing_table.csv'\n");
}


int main(int argc, char **argv)
{
    extern FILE *yyin;

	if(argc<2)
	{
		sprintf(buff,"***process terminated*** [input error]: invalid number of command-line arguments");
		mode=1;
		yyerror(buff);
		exit(1);
	}

	yyin=fopen(argv[1],"r");

	if(yyin==NULL)
	{
		sprintf(buff,"***process terminated*** [input error]: no such file \"%s\" exists",argv[1]);
		mode=1;
		yyerror(buff);
		exit(1);
	}
	else
	{
		do
		{
			yyparse();
		}
		while(!feof(yyin));
	}

	printf("***parsing successful***\n");
	printf("#global_declarations = %d\n",global_declarations);
	printf("#function_definitions = %d\n",func_definitions);
	printf("#integer_constants = %d\n",int_consts);
	printf("#pointers_declarations = %d\n",pointer_decls);
	printf("#ifs_without_else = %d\n",ifs_wo_else);
	printf("if-else max-depth = %d\n",((max<0)?0:max));


    export_parsing_table_to_csv();

    printf("\nReverse Derivation:\n");
	for(int i = dtop - 1; i >= 0; i--)
	{
		printf("%s\n", derivations[i]);
	}

    int indent = 0;

    printf("\nTree-like Reverse Derivation:\n");

    for(int i = dtop - 1; i >= 0; i--)
    {
        // print indentation
        for(int j = 0; j < indent; j++)
            printf("  ");

        printf("%s\n", derivations[i]);

        // increase indent for deeper levels
        if (strstr(derivations[i], "translation_unit") ||
            strstr(derivations[i], "function_definition") ||
            strstr(derivations[i], "compound_statement") ||
            strstr(derivations[i], "statement") ||
            strstr(derivations[i], "expression"))
        {
            indent++;
        }

        // limit indent (avoid going too deep)
        if(indent > 10) indent = 10;
    }

	printf("\nQuadruple Table:\n");
	printf("Op\tArg1\tArg2\tResult\n");

	for(int i = 0; i < quad_index; i++) {
		printf("%s\t%s\t%s\t%s\n",
			quads[i].op,
			quads[i].arg1,
			quads[i].arg2,
			quads[i].result);
	}

	return(0);
}



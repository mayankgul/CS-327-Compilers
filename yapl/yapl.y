
%{

/* ===== INCLUDES MUST COME FIRST (before any function that uses them) ===== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_data.h"

char *last_false_label;
char *last_start_label;
char *last_end_label;

/* Label stack for nested if-else */
#define STACK_SIZE 10000
char *false_label_stack[STACK_SIZE];
char *end_label_stack[STACK_SIZE];
int false_stack_top = 0;   /* separate counter */
int end_stack_top   = 0;   /* separate counter */

void push_false(char *l) {
    if (false_stack_top < STACK_SIZE)
        false_label_stack[false_stack_top++] = l;
    else { fprintf(stderr, "FATAL: false_label_stack overflow\n"); exit(1); }
}
char* pop_false() {
    if (false_stack_top > 0) return false_label_stack[--false_stack_top];
    fprintf(stderr, "FATAL: false_label_stack underflow\n"); return NULL;
}
void push_end(char *l) {
    if (end_stack_top < STACK_SIZE)
        end_label_stack[end_stack_top++] = l;
    else { fprintf(stderr, "FATAL: end_label_stack overflow\n"); exit(1); }
}
char* pop_end() {
    if (end_stack_top > 0) return end_label_stack[--end_stack_top];
    fprintf(stderr, "FATAL: end_label_stack underflow\n"); return NULL;
}

/* ===== TAC (Quadruple) structure ===== */
int temp_count = 1;

typedef struct {
    char op[20];
    char arg1[50];
    char arg2[50];
    char result[50];
} quad;

quad quads[1000];
int quad_index = 0;
int label_count = 1;


/* Generate temporary variables (t0, t1, t2, ...) */
char* new_temp() {
    char *temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

/* Generate labels (L0, L1, ...) */
char* new_label() {
    char *label = (char*)malloc(20);
    sprintf(label, "L%d", label_count++);
    return label;
}

/* Add a quadruple entry */
void add_quad(char *op, char *arg1, char *arg2, char *result) {
    strcpy(quads[quad_index].op,     op);
    strcpy(quads[quad_index].arg1,   arg1);
    strcpy(quads[quad_index].arg2,   arg2);
    strcpy(quads[quad_index].result, result);
    quad_index++;
}

/* ===== Parser support variables ===== */
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

int global_declarations = 0;
int func_definitions    = 0;
int int_consts          = 0;
int pointer_decls       = 0;
int ifs_wo_else         = 0;
int ladder_len = 0;
int  hold = 0;
int max = -1;
int if_depth =0;
%}

%token	<place> IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
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

%type <place> expression assignment_expression additive_expression multiplicative_expression
%type <place> primary_expression constant string generic_selection generic_assoc_list generic_association
%type <place> postfix_expression unary_expression cast_expression shift_expression
%type <place> relational_expression equality_expression and_expression exclusive_or_expression
%type <place> inclusive_or_expression logical_and_expression logical_or_expression
%type <place> conditional_expression expression_statement selection_statement iteration_statement statement
%type <place> else_part
%type <op> assignment_operator
%type <place> argument_expression_list argument_expression_list_opt

%left OR_OP
%left AND_OP
%left '|'
%left '^'
%left '&'
%left EQ_OP NE_OP
%left '<' '>' LE_OP GE_OP
%left LEFT_OP RIGHT_OP
%left '+' '-'
%left '*' '/' '%'
%right UMINUS

%nonassoc IFX
%nonassoc ELSE
%right '='
%left ','

%start translation_unit

%type <val> IF
%type <val> ELSE

%union
{
	int   val;
	char* place;
	char* op;
	struct symtab *symp;
}

%%

primary_expression
	: IDENTIFIER          { $$ = $1; }
	| constant
	| string
	| '(' expression ')'  { $$ = $2; }
	| generic_selection
	;

constant
	: I_CONSTANT {
		int_consts++;
		$$ = strdup(yytext);
	}
	| F_CONSTANT          { $$ = strdup(yytext); }
	| ENUMERATION_CONSTANT { $$ = strdup(yytext); }
	;

enumeration_constant
	: IDENTIFIER
	;

string
	: STRING_LITERAL { $$ = strdup(yytext); }
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')' { $$ = $3; }
	;

generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	;

generic_association
	: type_name ':' assignment_expression  { $$ = $3; }
	| DEFAULT   ':' assignment_expression  { $$ = $3; }
	;

postfix_expression
	: primary_expression                                            { $$ = $1; }
	| postfix_expression '[' expression ']'                         { $$ = $1; }
	| postfix_expression '(' argument_expression_list_opt ')'       { $$ = new_temp(); add_quad("call",$1,"",$$); }
	| postfix_expression '.' IDENTIFIER                             { $$ = $1; }
	| postfix_expression PTR_OP IDENTIFIER                          { $$ = $1; }
	| postfix_expression INC_OP                                     { $$ = $1; }
	| postfix_expression DEC_OP                                     { $$ = $1; }
	| '(' type_name ')' '{' initializer_list '}'                    { $$ = NULL; }
	| '(' type_name ')' '{' initializer_list ',' '}'                { $$ = NULL; }
	;

argument_expression_list_opt
	: /* empty */ { $$=NULL; }
	| argument_expression_list { $$ = $1; }
	;

argument_expression_list
	: assignment_expression
	{
		$$ = $1;
	}
	| argument_expression_list ',' assignment_expression
	{
		$$=$3;
	}
	;

unary_expression
	: postfix_expression                    { $$ = $1; }
	| INC_OP unary_expression               { $$ = $2; }
	| DEC_OP unary_expression               { $$ = $2; }
	| unary_operator cast_expression        { $$ = $2; }
	| SIZEOF unary_expression               { $$ = NULL; }
	| SIZEOF '(' type_name ')'             { $$ = NULL; }
	| ALIGNOF '(' type_name ')'            { $$ = NULL; }
	| '-' unary_expression {
		$$ = new_temp();
		add_quad("minus", $2, "", $$);
	}
	;

unary_operator
	: '&' | '*' | '+' | '~' | '!'
	;

cast_expression
	: unary_expression                         { $$ = $1; }
	| '(' type_name ')' cast_expression        { $$ = $4; }
	;

multiplicative_expression
	: cast_expression                                   { $$ = $1; }
	| multiplicative_expression '*' cast_expression     {
		$$ = new_temp(); add_quad("*",  $1, $3, $$); }
	| multiplicative_expression '/' cast_expression     {
		$$ = new_temp(); add_quad("/",  $1, $3, $$); }
	| multiplicative_expression '%' cast_expression     {
		$$ = new_temp(); add_quad("%",  $1, $3, $$); }
	;

additive_expression
	: multiplicative_expression                              { $$ = $1; }
	| additive_expression '+' multiplicative_expression      {
		$$ = new_temp(); add_quad("+", $1, $3, $$); }
	| additive_expression '-' multiplicative_expression      {
		$$ = new_temp(); add_quad("-", $1, $3, $$); }
	;

shift_expression
	: additive_expression                              { $$ = $1; }
	| shift_expression LEFT_OP  additive_expression    {
		$$ = new_temp(); add_quad("<<", $1, $3, $$); }
	| shift_expression RIGHT_OP additive_expression    {
		$$ = new_temp(); add_quad(">>", $1, $3, $$); }
	;

relational_expression
	: shift_expression                                { $$ = $1; }
	| relational_expression '<'   shift_expression    {
		$$ = new_temp(); add_quad("<",   $1, $3, $$);  }
	| relational_expression '>'   shift_expression    {
		$$ = new_temp(); add_quad(">",   $1, $3, $$);  }
	| relational_expression LE_OP shift_expression    {
		$$ = new_temp(); add_quad("<=",   $1, $3, $$);  }
	| relational_expression GE_OP shift_expression    {
		$$ = new_temp(); add_quad(">=",   $1, $3, $$);  }
	| relational_expression TH_OP shift_expression    {
		$$ = new_temp(); add_quad("<=>",   $1, $3, $$);  }
	;

equality_expression
	: relational_expression                               { $$ = $1; }
	| equality_expression EQ_OP relational_expression     {
		$$ = new_temp(); add_quad("==", $1, $3, $$); }
	| equality_expression NE_OP relational_expression     {
		$$ = new_temp(); add_quad("!=", $1, $3, $$); }
	;

and_expression
	: equality_expression                          { $$ = $1; }
	| and_expression '&' equality_expression       {
		$$ = new_temp(); add_quad("&", $1, $3, $$); }
	;

exclusive_or_expression
	: and_expression                               { $$ = $1; }
	| exclusive_or_expression '^' and_expression   {
		$$ = new_temp(); add_quad("^", $1, $3, $$); }
	;

inclusive_or_expression
	: exclusive_or_expression                              { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression  {
		$$ = new_temp(); add_quad("|", $1, $3, $$); }
	;

logical_and_expression
	: inclusive_or_expression                                  { $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression    {
		$$ = new_temp(); add_quad("&&", $1, $3, $$); }
	;

logical_or_expression
	: logical_and_expression                                { $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression    {
		$$ = new_temp(); add_quad("||", $1, $3, $$); }
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
	: '='          { $$ = strdup("=");  }
	| MUL_ASSIGN   { $$ = strdup("*");  }
	| DIV_ASSIGN   { $$ = strdup("/");  }
	| MOD_ASSIGN   { $$ = strdup("%");  }
	| ADD_ASSIGN   { $$ = strdup("+");  }
	| SUB_ASSIGN   { $$ = strdup("-");  }
	| LEFT_ASSIGN  { $$ = strdup("<<"); }
	| RIGHT_ASSIGN { $$ = strdup(">>"); }
	| AND_ASSIGN   { $$ = strdup("&");  }
	| XOR_ASSIGN   { $$ = strdup("^");  }
	| OR_ASSIGN    { $$ = strdup("|");  }
	| PEQ_OP       { $$ = strdup("+");  }
	| MEQ_OP       { $$ = strdup("-");  }
	| STREQ_OP     { $$ = strdup("*");  }
	| DEQ_OP       { $$ = strdup("/");  }
	| MODEQ_OP     { $$ = strdup("%");  }
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
	: conditional_expression
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
	: TYPEDEF | EXTERN | STATIC | THREAD_LOCAL | AUTO | REGISTER
	;

type_specifier
	: VOID | CHAR | SHORT | INT | LONG | FLOAT | DOUBLE
	| SIGNED | UNSIGNED | BOOL | COMPLEX | IMAGINARY
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT | UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list ';'
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

enumerator
	: enumeration_constant '=' constant_expression
	| enumeration_constant
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'
	;

type_qualifier
	: CONST | RESTRICT | VOLATILE
	;

function_specifier
	: INLINE | NORETURN
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	| ALIGNAS '(' constant_expression ')'
	;

declarator
	: pointer direct_declarator { pointer_decls++; }
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
	| labeled_statement   { sprintf(derivations[dtop++], "statement -> labeled_statement");   }
	| compound_statement  { sprintf(derivations[dtop++], "statement -> compound_statement");  }
	| expression_statement{ sprintf(derivations[dtop++], "statement -> expression_statement");}
	| selection_statement { sprintf(derivations[dtop++], "statement -> selection_statement"); }
	| iteration_statement { sprintf(derivations[dtop++], "statement -> iteration_statement"); }
	| jump_statement      { sprintf(derivations[dtop++], "statement -> jump_statement");      }
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
	: block_item                  { sprintf(derivations[dtop++], "block_item_list -> block_item"); }
	| block_item_list block_item  { sprintf(derivations[dtop++], "block_item_list -> block_item_list block_item"); }
	;

block_item
	: declaration { sprintf(derivations[dtop++], "block_item -> declaration"); }
	| statement   { sprintf(derivations[dtop++], "block_item -> statement");   }
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

else_part
    : /* empty */ %prec IFX
      {
          char *lf = pop_false();
          add_quad("label", "", "", lf);
          ifs_wo_else++;
		  if(ladder_len > max) max=ladder_len;
		  ladder_len=0;
      }
    | ELSE
      {
          char *le = new_label();
          char *lf = pop_false();
          add_quad("goto",  "", "", le);
          add_quad("label", "", "", lf);
          push_end(le);
		  ladder_len++;
		  if(ladder_len > max) max= ladder_len;
      }
      statement
      {
          char *le = pop_end();
          if (le) add_quad("label", "", "", le);
      }
    ;

selection_statement
    : IF '(' expression ')'
      {
          char *lf = new_label();
          if ($3) add_quad("iffalse", $3, "", lf);
          push_false(lf);
		  if_depth++;
      }
      statement else_part
      {
          if_depth--;
		  $$ = NULL;
      }
	  | SWITCH '('expression')' statement
	  {
		/* Switch: just parse and pass through, no quad needed for basic support */
		$$=NULL;
	  }
    ;

iteration_statement
    : WHILE
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
      '(' expression ')'
      {
          char *Lend = new_label();
          add_quad("iffalse", $4, "", Lend);
          push_end(Lend);
      }
      statement
      {
          char *Lend   = pop_end();
          char *Lstart = pop_false();
          add_quad("goto",  "", "", Lstart);
          add_quad("label", "", "", Lend);
          $$ = NULL;
      }

    | DO
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
      statement
      WHILE '(' expression ')' ';'
      {
          char *Lstart = pop_false();
          add_quad("ifgoto", $6, "", Lstart);
          $$ = NULL;
      }

    | FOR '(' expression_statement
      {
          char *Lstart = new_label();
          add_quad("label", "", "", Lstart);
          push_false(Lstart);
      }
      expression_statement
      {
          char *Lend = new_label();
          add_quad("iffalse", $5, "", Lend);
          push_end(Lend);
      }
      expression ')'
      statement
      {
          add_quad("eval", $7, "", "");
          char *Lend   = pop_end();
          char *Lstart = pop_false();
          add_quad("goto",  "", "", Lstart);
          add_quad("label", "", "", Lend);
          $$ = NULL;
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
	: function_definition { func_definitions++; }
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

/* =====================================================================
   C CODE SECTION
   ===================================================================== */

char buff[2048];
int yylex(void);
int mode = -1;

void export_parsing_table_to_csv() {
    FILE *fp = fopen("parsing_table.csv", "w");
    if (fp == NULL) { printf("Error opening file for CSV export!\n"); return; }

    fprintf(fp, "State");
    for (int i = 0; i < NUM_TERMS; i++)     fprintf(fp, ",%s", terminals[i]);
    for (int i = 0; i < NUM_NON_TERMS; i++) fprintf(fp, ",%s", non_terminals[i]);
    fprintf(fp, "\n");

    for (int i = 0; i < NUM_STATES; i++) {
        fprintf(fp, "%d", i);
        for (int j = 0; j < (NUM_TERMS + NUM_NON_TERMS); j++) {
            if (parsing_table[i][j] && strlen(parsing_table[i][j]) > 0)
                fprintf(fp, ",%s", parsing_table[i][j]);
            else
                fprintf(fp, ",-");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Successfully exported LALR(1) table to 'parsing_table.csv'\n");
}

/* ---- pretty-print helpers ---- */
#define LINE "================================================================="
#define DASH "-----------------------------------------------------------------"

void print_source(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { printf("(could not reopen source for display)\n"); return; }
    printf("\n%s\n", LINE);
    printf("  SOURCE PROGRAM : %s\n", filename);
    printf("%s\n", LINE);
    char buf[512];
    int ln = 1;
    while (fgets(buf, sizeof(buf), fp))
        printf("%4d | %s", ln++, buf);
    if (buf[strlen(buf)-1] != '\n') printf("\n");
    fclose(fp);
    printf("%s\n\n", LINE);
}

void print_quad_table() {
    printf("\n%s\n", LINE);
    printf("          INTERMEDIATE CODE  —  3-Address Code (Quadruples)\n");
    printf("%s\n", LINE);
    printf("%-5s  %-10s  %-14s  %-14s  %-14s\n",
           "No.", "Op", "Arg1", "Arg2", "Result");
    printf("%s\n", DASH);

    for (int i = 0; i < quad_index; i++) {
        const char *a1 = quads[i].arg1[0]   ? quads[i].arg1   : "-";
        const char *a2 = quads[i].arg2[0]   ? quads[i].arg2   : "-";
        const char *r  = quads[i].result[0] ? quads[i].result : "-";
        printf("%-5d  %-10s  %-14s  %-14s  %-14s\n",
               i, quads[i].op, a1, a2, r);
    }

    printf("%s\n", LINE);
    printf("  Total quadruples generated : %d\n", quad_index);
    printf("%s\n\n", LINE);
}

/* ---- main ---- */
int main(int argc, char **argv)
{
    extern FILE *yyin;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        exit(1);
    }

    /* Print source first */
    print_source(argv[1]);

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
        exit(1);
    }

    do { yyparse(); } while (!feof(yyin));
    fclose(yyin);

    /* Parsing stats */
    printf("%s\n", LINE);
    printf("  PARSING RESULTS\n");
    printf("%s\n", LINE);
    printf("  ***parsing successful***\n");
    printf("  #global_declarations  = %d\n", global_declarations);
    printf("  #function_definitions = %d\n", func_definitions);
    printf("  #integer_constants    = %d\n", int_consts);
    printf("  #pointer_declarations = %d\n", pointer_decls);
    printf("  #ifs_without_else     = %d\n", ifs_wo_else);
    printf("  if-else max-depth     = %d\n", (max < 0) ? 0 : max);
    printf("%s\n\n", LINE);

    /* Export parsing table */
    export_parsing_table_to_csv();

    /* Quadruple table — Part 3 requirement */
    print_quad_table();

    return 0;
}

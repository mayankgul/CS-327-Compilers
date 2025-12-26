#define MAX 50 //maximum limit of symbols

struct symtab
{
	char *name;
	int value;
}symbol_table[MAX];

struct symtab *symlook();

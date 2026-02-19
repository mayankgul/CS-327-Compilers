#define NUMBER 257
#define DISP 258
#define NAME 259
#define LEFT_SHIFT 260
#define POWER 261
#define RIGHT_SHIFT 262
#define LE 263
#define GE 264
#define EEQ 265
#define NE 266
#define AND_AND 267
#define OR_OR 268
#define UMINUS 269
typedef union
{
	int val;
	struct symtab *symp;
} YYSTYPE;
extern YYSTYPE yylval;

#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20100216

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
#ifdef YYPARSE_PARAM_TYPE
#define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
#else
#define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
#endif
#else
#define YYPARSE_DECL() yyparse(void)
#endif /* YYPARSE_PARAM */

extern int YYPARSE_DECL();

#line 14 "pro.y"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACK_LIMIT 512

extern char *yytext;
extern char saux;
extern int yylineno;
static int atoms[512],atom_counter=0,label=0; /*lookup table for variables and their occurences,atom counter and lab */
static int **truth_table; /*the truth table*/
static char buff[1024],last[512]; /*buffer*/
int pointer=0,narrow_top=-1,wide_top=-1; /*buffer pointer and stack pointers */
static char narrow_stack[512]; /*narrow_stack elememts are of type char [will be used for postfix evaluation]*/
static char wide_stack[512][512]; /*wide_stack elememts are of type char* [will be used to generate labels for truth table columns]*/
#line 49 "y.tab.c"
#define BICOND 257
#define IMP 258
#define OR 259
#define AND 260
#define NOT 261
#define TRUE 262
#define FALSE 263
#define ATOM 264
#define LEFT_PAR 265
#define RIGHT_PAR 266
#define ERROR 267
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    3,    3,    4,    4,    5,
    5,    6,    6,    6,    6,
};
static const short yylen[] = {                            2,
    1,    3,    1,    3,    1,    3,    1,    3,    1,    2,
    1,    3,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,   13,   14,   15,    0,    0,    0,    0,    0,    0,
    9,   11,   10,    0,    0,    0,    0,    0,   12,    0,
    0,    0,    8,
};
static const short yydgoto[] = {                          6,
    7,    8,    9,   10,   11,   12,
};
static const short yysindex[] = {                      -243,
 -243,    0,    0,    0, -243,    0, -255, -253, -251, -250,
    0,    0,    0, -254, -243, -243, -243, -243,    0, -253,
 -251, -250,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    6,    9,    7,    1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   14,
   11,    4,    0,
};
static const short yygindex[] = {                         0,
    8,   10,   12,   -2,   -1,    0,
};
#define YYTABLESIZE 280
static const short yytable[] = {                         13,
    7,   15,   15,    6,   16,    1,    5,   17,    3,   18,
    4,   19,   14,    2,   22,    0,   23,    1,    2,    3,
    4,    5,    0,    0,   20,    0,    0,   21,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    7,    7,    7,
    6,    6,    6,    5,    5,    3,    7,    4,    4,    6,
    2,    0,    5,    0,    3,    0,    4,    0,    0,    2,
};
static const short yycheck[] = {                          1,
    0,  257,  257,    0,  258,    0,    0,  259,    0,  260,
    0,  266,    5,    0,   17,   -1,   18,  261,  262,  263,
  264,  265,   -1,   -1,   15,   -1,   -1,   16,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  257,  258,  259,  257,  258,  257,  266,  257,  258,  266,
  257,   -1,  266,   -1,  266,   -1,  266,   -1,   -1,  266,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"BICOND","IMP","OR","AND","NOT",
"TRUE","FALSE","ATOM","LEFT_PAR","RIGHT_PAR","ERROR",
};
static const char *yyrule[] = {
"$accept : structure",
"structure : sentence",
"sentence : sentence BICOND sentence1",
"sentence : sentence1",
"sentence1 : sentence1 IMP sentence2",
"sentence1 : sentence2",
"sentence2 : sentence2 OR sentence3",
"sentence2 : sentence3",
"sentence3 : sentence3 AND sentence4",
"sentence3 : sentence4",
"sentence4 : NOT sentence4",
"sentence4 : sentence5",
"sentence5 : LEFT_PAR sentence RIGHT_PAR",
"sentence5 : TRUE",
"sentence5 : FALSE",
"sentence5 : ATOM",

};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;

#define YYPURE 0

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 65 "pro.y"
int get_val_and(int a,int b) //compute a AND b which is denoted here as [a & b]
{
	return(a&&b);
}

int get_val_or(int a,int b) //compute a OR b which is denoted here as [a # b]
{
	return(a||b);
}

int get_val_not(int a) //compute NOT a which is denoted here as [~a]
{
	if(a==0)
		return(1);
	else if(a==1)
		return(0);
}

int get_val_implication(int a,int b) //compute a IMPLIES b which is denoted here as [a->b]
{
	return(get_val_not(a)||b);
}

int get_val_bi_conditional(int a,int b) //compute a BICONDITIONAL b which is denoted here as [a<->b]
{
	return(get_val_implication(a,b)&&get_val_implication(b,a));
}
int expo(int a,int b) //my implementation of a raised to b [equivalent to pow(a,b)]
{
	int i,res=1;
	
	for(i=1;i<=b;i++)
		res*=a;
	return(res);
}
void xbits(int n,int *ar,int width) //generates all the 2^n  n-bit vectors 
{
	int ct=0,c=0,i,temp=0;

	for(i=0;i<width;i++)
		ar[i]=0;	
	if(n==0||n==1)
	{
		ar[0]=n;
	}
	else
	{
		while(1)
		{
			c=n%2;
			ar[ct++]=c;
			n=n/2;	
			
			if(n==1)
			{
				ar[ct++]=1;
				break;
			}
		}
	}
	
	for(i=0;i<width/2;i++) //reverse in one shot [this is necessary!!]
	{
		temp=ar[i];
		ar[i]=ar[width-i-1];
		ar[width-i-1]=temp;
	}
		
}
void narrow_push(char ch) //narrow_stack push()
{
	if(narrow_top==STACK_LIMIT-1)
		printf("\nNarrow Stack Overflow!!\n");
	else
		narrow_stack[++narrow_top]=ch;
}
char narrow_pop() //narrow_stack pop()
{
	if(narrow_top==-1)
		printf("\nNarrow Stack Underflow!!\n");
	else
		return(narrow_stack[narrow_top--]);
}
void wide_push(char ch[512]) //wide_stack push()
{
	if(wide_top==STACK_LIMIT-1)
		printf("\nWide Stack Overflow!!\n");
	else
		strcpy(wide_stack[++wide_top],ch);
}
char *wide_pop() //short stack lpop()
{
	if(wide_top==-1)
		printf("\nUnderflow!!\n");
	else
		return(wide_stack[wide_top--]);
}
main(int argc,char **argv) //begin main()
{
	int i,j,k,ctr=0,num,val=0,aux=0;	
	extern FILE *yyin; //source file pointer
	FILE *fp=NULL; //temporary file
	char str[512],ch,a,b,c,temp[512]; //temporary storage
	static int local_table[512]; //local table
	static int value[256]; //ascii table
	static char label_table[512][512]; //truth table column labels
	int label_counter=0,*col_sep; //label counter of truth table and column width/seperator holder
	
	yyin=fopen(argv[1],"r"); //open logic file having (.prl) extension in read mode
	
	if(yyin==NULL) //error checking
	{
		printf("\nError: No such file exists!!\n\n");
		exit(1);
	}
	else
	{
		fgets(last,512,yyin); 
		rewind(yyin);
		
		buff[0]='\0'; //clear to avoid garbage value

		do
		{
			yyparse();
		}
		while(!feof(yyin));

		fclose(yyin);

		buff[pointer]=')';
		buff[pointer+1]='\0'; //null terminate strings
		last[strlen(last)]='\0';

		char *temp1,*temp2; //local string for storing the popped value from stack

		for(j=0;buff[j]!=')';j++) //postfix evaluation for generating truth table column labels
		{
			ch=buff[j];
						
			if(ch>='A'&&ch<='Z') //if an opreand push on stack
			{
				sprintf(temp,"%c",ch);
				wide_push(temp);
				temp[0]='\0';				
			}
			else //operator [a=pop(),b=pop() c=b#a where # is any operator finally push(c)]
			{
				switch(ch)
				{
					case 'n' :      
							//unary not ~
							temp1=wide_pop();
							sprintf(temp,"~(%s)",temp1);
							wide_push(temp);
							strcpy(label_table[label_counter++],temp);
							temp[0]='\0';
							break;

					case 'i' :
							//binary implication ->
							temp1=wide_pop();
							temp2=wide_pop();
							sprintf(temp,"(%s->%s)",temp2,temp1);
							wide_push(temp);
							strcpy(label_table[label_counter++],temp);
							temp[0]='\0';
							break;

					case 'b' :
							//binary biconditional <->
							temp1=wide_pop();
							temp2=wide_pop();
							sprintf(temp,"(%s<->%s)",temp2,temp1);
							wide_push(temp);
							strcpy(label_table[label_counter++],temp);
							temp[0]='\0';
							break;
						
					case 'a' :
							//binary and &
							temp1=wide_pop();
							temp2=wide_pop();
							sprintf(temp,"(%s&%s)",temp2,temp1);
							wide_push(temp);
							strcpy(label_table[label_counter++],temp);
							temp[0]='\0';
							break;							

					case 'o' :
							//binary or #
							temp1=wide_pop();
							temp2=wide_pop();
							sprintf(temp,"(%s#%s)",temp2,temp1);
							wide_push(temp);
							strcpy(label_table[label_counter++],temp);
							temp[0]='\0';
							break;	
				}
			}
		}					
				
		for(i=0;i<256;i++)
		{
			if(atoms[i]>0)
			{
				atom_counter++;
				local_table[ctr++]=i; //recording names of variables
			}
		}

		aux=expo(2,atom_counter); //calculate 2^n where n is number of variables

		int a,*ar=(int*)calloc(atom_counter,sizeof(int)); //vector ar such that dim(ar)=number of variables and contains bit representation of a decimal no.

		truth_table=(int**)malloc((aux-1)*sizeof(int*)); //truth table      

		    		
		for(i=0;i<aux;i++)
    			truth_table[i]=(int*)malloc((atom_counter+label_counter)*sizeof(int)); //dynamically create space for truth table
		
		for(i=0;i<=aux-1;i++) //movement in iteration space through all the interpretations
		{
			for(j=0;j<256;j++)
				value[j]=0; //clear ascii table to avoid garbage value
			
			val=0; //clear val
			
			strcpy(str,buff); //make a copy of what has been read
			
			xbits(i,ar,atom_counter); //get the n-bit binary equivalent of decimal number i, n being the no of distinct variables 	

			for(a=0;a<ctr;a++)
				truth_table[i][a]=ar[a]; //set truth table values according to recieved n-bit bit pattern
			label=a; //set new base [later will be used for indexing into the label holder]

			for(a=0;a<ctr;a++)
				value[local_table[a]]=ar[a]; //get value
					
			for(j=0;j<strlen(str);j++)
			{
				ch=str[j]; //extract character
				
				for(k=0;k<ctr;k++)
				{
					if(local_table[k]==ch) //set the value of variable read with the value of bit position in the bit vector 
					{
						if(value[local_table[k]]==0)
							str[j]='F';
						else if(value[local_table[k]]==1)
							str[j]='T';
					}
					
				}
			}
			
			narrow_stack[0]='\0'; //clear stack
			narrow_top=-1; //reset stack pointer 

			int par1=0,par2=0; //local parameters [later will be used to invoke logic functions]
			
			for(j=0;str[j]!=')';j++) //postfix evaluation for calculating the value of the wff at current interpretation
			{
				ch=str[j]; //pick up character from postfix expression

				if(ch=='F'||ch=='T') //opreand encountered
					narrow_push(ch); 
				else //operator encountered
				{ 
					switch(ch)
					{
						case 'n' :
								//unary not ~
								a=narrow_pop(); //remove only the top element as this is ~
								
								if(a=='F')
									val=get_val_not(0); //perform ~a 
								else if(a=='T')
									val=get_val_not(1);
																	
								if(val==0)
								{
									narrow_push('F');
									truth_table[i][label++]=0;
								}
								else if(val==1)
								{
									narrow_push('T');
									truth_table[i][label++]=1;
								}

								break;
	
						case 'i' :
								//binary implication ->
								a=narrow_pop(); //a corresponds to par2
								b=narrow_pop(); //b corresponds to par1
								
								if(b=='F')
									par1=0;
								else if(b=='T')
									par1=1;

								if(a=='F')
									par2=0;
								else if(a=='T')
									par2=1; 
									
								val=get_val_implication(par1,par2); //perform par1 -> par2

								if(val==0)
								{
									narrow_push('F');
									truth_table[i][label++]=0;
								}
								else if(val==1)
								{
									narrow_push('T');
									truth_table[i][label++]=1;
								}

								break;								
					
						case 'b' :	
								//binary biconditional <->
								a=narrow_pop(); //a corresponds to par2
								b=narrow_pop(); //b corresponds to par1
								
								if(b=='F')
									par1=0;
								else if(b=='T')
									par1=1;

								if(a=='F')
									par2=0;
								else if(a=='T')
									par2=1; 
									
								val=get_val_bi_conditional(par1,par2); //perform par1 <-> par2

								if(val==0)
								{
									narrow_push('F');
									truth_table[i][label++]=0;
								}
								else if(val==1)
								{
									narrow_push('T');
									truth_table[i][label++]=1;
								}

								break;			
	
						case 'a' :	
								//binary and &
								a=narrow_pop(); //a corresponds to par2
								b=narrow_pop(); //b corresponds to par1
								
								if(b=='F')
									par1=0;
								else if(b=='T')
									par1=1;

								if(a=='F')
									par2=0;
								else if(a=='T')
									par2=1; 
									
								val=get_val_and(par1,par2); //paeform par1 & par2

								if(val==0)
								{
									narrow_push('F');
									truth_table[i][label++]=0;
								}
								else if(val==1)
								{
									narrow_push('T');
									truth_table[i][label++]=1;
								}

								break;		
						
						case 'o' :	
								//binary or #
								a=narrow_pop(); //a corresponds to par2
								b=narrow_pop(); //b corresponds to par1
								
								if(b=='F')
									par1=0;
								else if(b=='T')
									par1=1;

								if(a=='F')
									par2=0;
								else if(a=='T')
									par2=1; 
									
								val=get_val_or(par1,par2);

								if(val==0)
								{
									narrow_push('F');
									truth_table[i][label++]=0;
								}
								else if(val==1)
								{
									narrow_push('T');
									truth_table[i][label++]=1;
								}

								break;		
					}	
				}
			}			
			str[0]='\0'; //clear string for reuse
		}
	}
	
	col_sep=(int*)calloc(atom_counter+label_counter,sizeof(int)); //column seperator for truth table
	
   	ctr=0; //set dash(margin) counter to 0

	for(i=0;i<atom_counter;i++)
		col_sep[ctr++]=4; //calculate distance of eperation of truth table column labels  
	for(i=0;i<label_counter;i++)
		col_sep[ctr++]=strlen(label_table[i]);
	
	int main_header_sep=0; //main header ["Truth table for X"] seperation holder

	for(i=0;i<ctr;i++)
		main_header_sep+=col_sep[i];

	main_header_sep=(main_header_sep/2)+10; //calculate main header seperation

	printf("\n\n%*s",main_header_sep,"Truth table for "); //write main header
	printf("%s\n\n",last);	
	
	ctr=0; //clear dash counter
	
	int sep=0; //determines the seperation between truth table column labels entries 

	for(i=0;i<atom_counter;i++)
	{
		sep+=printf(" %*c ",col_sep[ctr++],local_table[i]); //useful for drawing the margins no of dashes '-' proportional to no of distinct variables
	}
	for(i=0;i<label_counter-1;i++)
	{
		sep+=printf("  %*s ",col_sep[ctr++],label_table[i]); 
	}
	if(strlen(last)>2)
		sep+=printf("  %*s ",col_sep[ctr++],last);
	
	printf("\n");

	for(i=1;i<=sep+15;i++)
		printf("-"); //draw margins with dashes '-------'
	
	printf("\n");
	
	for(i=0;i<aux;i++)
	{
		for(j=0;j<label;j++)
		{
			if(truth_table[i][j]==0)
				printf(" %*c ",col_sep[j],'F'); //display final truth table with seperations between entries and labels
			else
				printf(" %*c ",col_sep[j],'T');
		}
		printf("\n\n");
	}

	int true_count=0,false_count=0; 

	for(i=0;i<aux;i++)
	{
		if(truth_table[i][label-1]==1) //no of interpretations having value T
			true_count++; 
		if(truth_table[i][label-1]==0) //no of interpretations having value F
			false_count++;
	}
	
	// determination of whether the wff is valid,invalid,consistent or inconsistent

	last[strlen(last)-1]='\0'; //clear trailing '\n'

	printf("The wff %s is...\n\n",last);

	//display combinations appropriately

	if(true_count==aux)
		printf("Valid\n");
	if(true_count!=aux)
		printf("Invalid\n");
	if(false_count==aux)
		printf("Inconsistent\n");
	if(false_count!=aux)
		printf("Consistent\n");
				
	printf("\n\n");

} //end main()
yyerror(char *s) //error routine for syntax error(ill formed formula!!) 
{
	printf("\nError class: %s\n",s);

	if((saux=='(')&&(strlen(yytext)==0))
		printf("\nError : error in line %d caused by '(' [unmatched left paranthesis or it has invalid placement]\n",yylineno);
	else if(!strcmp(yytext,"<->"))
		printf("\nError : error in line %d caused by '<->' [illegal use of '<->' operator,expecting operand]\n",yylineno);
	else if(!strcmp(yytext,"->"))
		printf("\nError : error in line %d caused by '->' [illegal use of '->' operator,expecting operand]\n",yylineno);
	else
	{ 
		switch(*yytext)
		{
			case ')' :  printf("\nError : error in line %d caused by ')' [unmatched right paranthesis or it has invalid placement]\n",yylineno);
				    break;
			case '#' :  printf("\nError : error in line %d caused by '#' [illegal use of '#' operator,expecting operand]\n",yylineno);
				    break;
			case '&' :  printf("\nError : error in line %d caused by '&' [illegal use of '&' operator,expecting operand]\n",yylineno);
				    break;
			case '~' :  printf("\nError : error in line %d caused by '~' [illegal use of '~' operator,expecting operand]\n",yylineno);
				    break;
			default :   printf("\nError : error in line %d caused by '%s' [invalid placement of known entity",yylineno,yytext);
				    printf(" or possibly some unrecognized entity]\n");	
		}
	}
				
	printf("\nError string: %s\n",last);
	exit(-1);
}
#line 765 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (data->s_base != 0)
          ? (short *)realloc(data->s_base, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base  = newss;
    data->s_mark = newss + i;

    newvs = (data->l_base != 0)
          ? (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 34 "pro.y"
	{buff[pointer++]='b';}
break;
case 4:
#line 39 "pro.y"
	{buff[pointer++]='i';}
break;
case 6:
#line 44 "pro.y"
	{buff[pointer++]='o';}
break;
case 8:
#line 49 "pro.y"
	{buff[pointer++]='a';}
break;
case 10:
#line 54 "pro.y"
	{buff[pointer++]='n';}
break;
case 13:
#line 60 "pro.y"
	{buff[pointer++]='T';}
break;
case 14:
#line 61 "pro.y"
	{buff[pointer++]='F';}
break;
case 15:
#line 62 "pro.y"
	{atoms[*yytext]++; buff[pointer++]=*yytext;}
break;
#line 999 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

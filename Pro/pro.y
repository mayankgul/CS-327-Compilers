%start structure
%token BICOND
%token IMP
%token OR
%token AND
%token NOT
%token TRUE
%token FALSE
%token ATOM
%token LEFT_PAR
%token RIGHT_PAR
%token ERROR
%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACK_LIMIT 512

extern char *yytext;
extern char saux;
extern int yylineno;
static int atoms[512],atom_counter=0,label=0; //lookup table for variables and their occurences,atom counter and lab 
static int **truth_table; //the truth table
static char buff[1024],last[512]; //buffer
int pointer=0,narrow_top=-1,wide_top=-1; //buffer pointer and stack pointers 
static char narrow_stack[512]; //narrow_stack elememts are of type char [will be used for postfix evaluation]
static char wide_stack[512][512]; //wide_stack elememts are of type char* [will be used to generate labels for truth table columns]
%}
%%
structure:
	  sentence
	  ;
sentence:
	 sentence BICOND sentence1 {buff[pointer++]='b';}
	|sentence1
	;

sentence1:
	  sentence1 IMP sentence2 {buff[pointer++]='i';}
	 |sentence2
	 ;

sentence2:
	  sentence2 OR sentence3 {buff[pointer++]='o';}
	 |sentence3
	 ;

sentence3:
	  sentence3 AND sentence4 {buff[pointer++]='a';}
	 |sentence4
	 ;

sentence4:
	  NOT sentence4 {buff[pointer++]='n';}
	 |sentence5
	 ;

sentence5:
	  LEFT_PAR sentence RIGHT_PAR
	 |TRUE {buff[pointer++]='T';}
	 |FALSE {buff[pointer++]='F';}
	 |ATOM {atoms[*yytext]++; buff[pointer++]=*yytext;}
	 ;
%%
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

## Scanning & Parsing for ```yapl```: a C-like Language

The ```yapl``` specification is available [here](https://github.com/SET-IITGN/CS-327-Compilers/blob/main/yapl/lang_spec.pdf).

### ```yapl``` in action...
**testcase_1.c**
```
int *var=6;
struct mystruct *ms=&var;

int auto, static, inline;

extern void *k;
int p;
int p;
int p;

int *hh(char *p);

int main(int b)
{
	int auto=2,b=3,c;
	c=auto+b;
	printf("%d",c);

	struct player
	{
		int a;
		double c;
	};

	int *jj=&auto;

	System.out.print("java here");
	char echo[3]="bash here";
	myprintf("CS3300 here");
	printf(echo);

	/*
		mixing things here a bit
	*/

	if(a==9)
	{
		//NO-OP
	}
	
	if(a==1)
		hh(++jj);
	else if(a==2)
		hh(jj++);
	else if(a==3)
		hh(*jj++);
	else
	{
		//NO-OP
	}
			
	struct player *p;
	p=(struct player *)malloc(sizeof(struct player));
	
	p->a=1;
	p->b=2.4;

	//#pragma omp parallel for
	for(a=1;a<=5;a++)
		static(a);

	int *p;
	float *j;
	p=&auto;
	j=0x1234;
	printf("*j=%p",(char *)j);

	void *static=&c;

	int a=5,b=8,c;
	c=a<=>b;

	hh(p);
	
	return(0);
}	

int *hh(char *p)
{
	int n=7;

	scanf("%d",&n);
	
	if(n==0)
		printf("%d\n",n+1);
	else if(n==1)
		printf("%d\n",n+2);
	
	return(NULL);
}	
```
---
```
***parsing successful***
#global_declarations = 10
#function_definitions = 2
#integer_constants = 20
#pointers_declarations = 12
#ifs_without_else = 2
if-else max-depth = 3
```
**testcase_14.c**
```
/*int factorial(int n){
	int i = 1;
	int fact = 1;

	while(1>0){

		if(i>n){
			break;
		}

		fact = (*n <= 9);

		fact = fact ^ 1;

		i++;

		if(2<0){
			continue;
		}

	}
}*/

int factorial(int n){
	int i = 1;
	int fact = 1;

	while(1>0){

		if(i>n){
			break;
		}

		fact = (*n <= 9);

		fact = fact ^ 1;

		i++;

		if(2<0){
			continue;
		}

	}
}

void main(){
	int x = factorial(5);
	printf("%d", x);

	if(a <=> b)
	{
		/*
			do nothing
		*/
	}
}

void main(){
	int x = factorial(5);
	printf("%d", x);

	if(a <=> b)
	{
		/*
			do nothing
		*/
	}
}

void main(){
	int x = factorial(5);
	printf("%d", x);

	if(a <=> b)
	{
		/*
			do nothing
		*/
	}
}

/*int factorial(int n){
	int i = 1;
	int fact = 1;

	while(1>0){

		if(i>n){
			break;
		}

		fact = (*n <= 9);

		fact = fact ^ 1;

		i++;

		if(2<0){
			continue;
		}

	}
}*/

void main(){
	int x = factorial(5);
	printf("%d", x);

	if(a <=> b)
	{
		/*
			do nothing
		*/
	}
}

void main(){
	int x = factorial(5);
	printf("%d", x);

	if(a <=> b)
	{
		/*
			do nothing
		*/
	}
}

void main(){
	int x = factorial(5);
	printf("%d", x);

	if(a <=> b)
	{
		/*
			do nothing
		*/
	}
}
```
---
```
***parsing successful***
#global_declarations = 7
#function_definitions = 7
#integer_constants = 14
#pointers_declarations = 0
#ifs_without_else = 8
if-else max-depth = 0
```
**testcase_9.c**
```

void fibonacci(int n, int *enum){

	enum[0] = 0;
	enum[1] = 1;

	int i = 2;

	while((i<n) && !(1<0)){
		enum[i] = enum[i-1] + enum[i-2];
		i = i + 1;
	}

}

void main(){
	
	int x, *struct, y;

	printf("Enter a number:");
	scanf("%d", &x);

	y = x;

	struct = malloc(4*x);

	fibonacci(fibonacci(fibonacci(x, struct), struct), struct);

	printf("%d", (struct + (x-1)));

}
```
---
```
***parsing terminated*** [syntax error]
```

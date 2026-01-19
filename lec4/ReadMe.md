## `kmp.cpp`
```
int *pi;

void failure_function(const char *P)
{
	int m,k,q;

	m=strlen(P);
	pi=(int*)calloc(m,sizeof(int));
	pi[0]=-1;
	k=-1;
	int itr=0;

	for(q=1;q<m;q++)
	{
		itr=0;
		while((k>-1) && (P[k+1]!=P[q]))
			{itr++; printf("Iteration %d\n",itr); k=pi[k];}
		if(P[k+1]==P[q])
			k++;
		pi[q]=k;
	}	
	
	printf("\nfailure function for (%s) after %d iterations...\n",P,itr);
	
	for(q=0;q<m;q++)
		printf("f(%d)=%d\n",q,pi[q]+1);
}

int mystrstr(const char *T,const char *P) //returns 0 on failure, >0 on success
{
	int n,m,q,i,flag=0;
	
	n=strlen(T);
	m=strlen(P);
	failure_function(P);	
	q=-1; 

	for(i=0;i<n;i++) 
	{
		while((q>-1) && (P[q+1]!=T[i]))
			q=pi[q];
		if(P[q+1]==T[i])
			q++;
		if(q==(m-1))
		{
			flag++;
			printf("\n(%s) occurs with shift %d in (%s)\n",P,i-q,T);
			q=pi[q];
		}
	}

	free(pi);	

	return(flag);
}
```
## `main.cpp`
```
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include "kmp.cpp"

using namespace std;

#define B_SIZE 1024

int main()
{
	char T[B_SIZE]="\0";
	char s[B_SIZE/4]="\0";
	cin>>T;
	cin>>s;
	int res=mystrstr(T,s);
	if(res==0)
		printf("\n(%s) does not occur in (%s)\n",s,T);
	
	return(0);
}
```
## `input.txt`
```
abababaababbbabbababb
ababaa
```
## Command-line
```
shouvick@shouvick:~/CS327/lec4$ ./kmp < input.txt 
Iteration 1
Iteration 2

failure function for (ababaa) after 2 iterations...
f(0)=0
f(1)=0
f(2)=1
f(3)=2
f(4)=3
f(5)=1

(ababaa) occurs with shift 2 in (abababaababbbabbababb)
```

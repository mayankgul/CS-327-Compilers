
/*
	Implementation of Knuth-Morris-Pratt algorithm in C/C++.
	Author: Shouvick Mondal
	Date: 20/01/2026
*/


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

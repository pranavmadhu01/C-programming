//this is the grammer we use to implement this program
//E->E+T | T
//T->T*F | F
//F->(E) |id

//After eliminating left recursion the grammer becomes

//E->TE'
//E'->+TE' | e
//T->FT'
//T'->*FT' | e
//F->(E)
//F->id

//we use this productions for implementing the program, ie, productions converted to functions;

#include<stdio.h>
#include<stdlib.h>
char s[20];
int p=0;
//defining the function prototypes
void E();
void ED();
void T();
void TD();
void F();

void E()
{
	T();
	ED();	
}
void ED()
{
	if(s[p]=='+')
	{
		p++;
		T();
		ED();
	}
	else
	{
		return;
	}	
}
void T()
{
	F();
	TD();
}
void TD()
{
	if(s[p]=='*')
	{
		p++;
		F();
		TD();
	}
	else
	{
		return;
	}
}
void F()
{
	if(s[p]=='(')
	{
		p++;
		E();
		if(s[p]==')')
		{
			p++;
		}
		else
		{
			printf("Parsing error.\n");
			exit(0);
		}
	}
	else
	{
		if(s[p]>='a' && s[p]<='z' || s[p]>='A' && s[p]<='Z')
		{
			p++;
		}
		else
		{
			printf("Parsing error.\n");
			exit(0);
		}
	}
	
}
int main()
{
	printf("Enter the string to parse.\n");
	scanf("%s",s);
	E();
	if(s[p]=='$')
	{
		printf("Successfully parsed\n");
		exit(0);
	}
	else
	{
		printf("Parsing error\n");
	}
	
}

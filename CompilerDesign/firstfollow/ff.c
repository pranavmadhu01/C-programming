#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char p[20][20];
char f[20];
int m,n;
void first(char c);
void follow(char c);
int main()
{
	printf("Enter the number of productions.\n");	
	scanf("%d",&n);
	printf("Enter the productions in (LHS=RHS) format\n");
	for(int i=0;i<n;i++)
	{
		scanf("%s",p[i]);
	}
	int _continue = 1;
	do
	{
		char c;
		printf("Enter the character to find the first and follow.\n");
		scanf(" %c",&c);
		first(c);
		printf("First of %c is : {",c);
		for(int i =0;i<m;i++)
		{
			printf("%c",f[i]);
		}
		printf("}\n");
		strcpy(f," ");
		m=0;
		follow(c);
		printf("Follow of %c is : {",c);
		for(int i =0;i<m;i++)
		{
			printf("%c",f[i]);
		}
		printf("}\n");
		printf("Continue? Enter 1\n");
		scanf("%d",&_continue);
	}
	while(_continue ==1);
	
}
void first(char c)
{
	if(!isupper(c))
	{
		f[m] = c;
		m++;
	}
	for(int i=0;i<n;i++)
	{
		if(c==p[i][0])
		{
			if(p[i][2]=='$')
			{
				follow(p[i][2]);
			}
			else
			{
				first(p[i][2]);
			}
		}
	}
	
}
void follow(char c)
{	
	if(p[0][0] == c)
	{
		f[m] = '$';
		m++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=2;j<strlen(p[i]);j++)
		{
			if(c==p[i][j])
			{
				if(p[i][j+1]!='\0')
				{
					first(p[i][j+1]);
				}
				else if(p[i][0]!=c)
				{
					follow(p[i][0]);
				}
			}
		}
	}	
}


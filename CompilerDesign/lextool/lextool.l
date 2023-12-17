%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cc=0,ws=0,nl=0,nw=0;
%}

%%

[a-zA-Z0-9]+ {nw++;cc+=yyleng;}
[ \t] {ws++;cc++;}
[\n] {nl++;}

%%

int yywrap()
{
	return 1;
}
void main()
{
	printf("Enter the string for lexical analysys.\n");
	yylex();
	printf("The number of characters are %d\n",cc);
	printf("The number of words are %d\n",nw);
	printf("The number of whitespaces are %d\n",ws);
	printf("The number of lines are %d\n",nl);
	
}

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cc=0,wc=0,wsc=0,lc=0;
%}

%%
[a-zA-Z0-9]+ {wc++;cc+=yyleng;}
[ \t] {wsc++;cc++;}
[\n] {lc++;}
%%

int yywrap()
{
	return 1;
}

void main()
{
	yyin = fopen("input.txt","r");
	yylex();
	printf("The number of charaters are %d: \n",cc);
	printf("The number of whitespaces are %d: \n",wsc);
	printf("The number of words are %d: \n",wc);
	printf("The number of lines are %d: \n",lc);
}

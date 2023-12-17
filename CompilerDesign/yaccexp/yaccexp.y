%{
#include<stdio.h>
#include<stdlib.h>
int flag=0;
%}

%token NUMBER
%token IDENTIFIER
%token OPERATOR

%left OPERATOR

%%
E:E OPERATOR E
|'('E')'
|NUMBER
|IDENTIFIER
;
%%

void main()
{
	printf("Enter the expression to check the validity.\n");
	yyparse();
	if(flag==0)
	{
		printf("The experssion is valid.\n");
	}
}

void yyerror()
{
	flag=1;
	printf("Error occured while parsing, Invalid identifier.\n");
}

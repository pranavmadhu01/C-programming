%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag=0;
%}

%token LETTER
%token DIGIT

%%
E:LETTER S
S:LETTER S
|DIGIT S
|
;
%%

void main()
{
	printf("Enter the identifier.\n");
	yyparse();
	if(flag==0)
	{
		printf("Valid Identifier.\n");
	}
}

void yyerror()
{
	flag=1;
	printf("Invalid identifier.\n");
}



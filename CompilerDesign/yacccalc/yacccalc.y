%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag=0;
%}

%token NUMBER
%left '+''-'
%left '*''/''%'
%left '('')'

%%
Calculate:E{
	printf("The calculated value is %d\n",$$);
}
E:E'+'E {$$ = $1+$3;}
|E'-'E {$$ = $1-$3;}
|E'*'E {$$ = $1*$3;}
|E'/'E {$$ = $1/$3;}
|E'%'E {$$ = $1%$3;}
|'('E')' {$$ = $2;}
|NUMBER {$$ = $1;}
;
%%

void main()
{
	printf("Enter the expression to calculate the value.\n");
	yyparse();
	if(flag==1)
	{
		printf("Successful evaluation done.\n");
	}
}

void yyerror()
{
flag=1;
printf("Invalid expression to calculate, unable to parse\n");
}

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lc=0,vc=0,cc=0;
%}

%%
[ \t] ;
[aeiou] {lc++;vc++;printf("%c",yytext[0]-32);}
[AEIOU] {lc++;vc++;printf("%c",yytext[0]+32);}
[0-9] ;
[a-z] {lc++;cc++;printf("%c",yytext[0]-32);}
[A-Z] {lc++;cc++;printf("%c",yytext[0]+32);}

%%

int yywrap()
{
	return 1;
}
void main ()
{
	printf("Enter the string for analysis.\n");
	yylex();
	printf("The vowel count is %d\n",vc);
	printf("The consonent count is %d\n",cc);
	printf("Total letter count is %d\n",lc);
}

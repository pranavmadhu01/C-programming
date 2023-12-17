%{
#include"y.tab.h"
%}
%%
[0-9]+ {return NUMBER;}
[a-zA-Z_][a-zA-Z_0-9]* {return IDENTIFIER;}
[+-/*] {return OPERATOR;}
%%

int yywrap()
{
	return 1;
}

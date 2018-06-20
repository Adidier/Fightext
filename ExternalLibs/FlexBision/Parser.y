%{
#include <stdio.h>
#include "Parser.flex.h"
#include "ManagerAction.h"
	int yywrap(void)
	{
	return 0;
	}
	void yyerror(const char *)
	{
	}
%}

%union
{
	char	*sval;
};
%token <sval> IDENTIFIER

%token EQUAL
%token ATTACK
%token EOL

%%
action: 
| ATTACK EQUAL IDENTIFIER {  ManagerAction::getPtr()->SetAttack(yytext); }
;

%%
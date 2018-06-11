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

%token ATTACK
%token PARAMETER
%token EOL

%%
action: 
| ATTACK { ManagerAction::getPtr()->SetAttack("sad"); }
;

%%
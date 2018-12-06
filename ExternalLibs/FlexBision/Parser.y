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
%token AYUDARLA
%token ALEJARTE
%token VAMOS
%token SOLA
%token CONTINUAR
%token ADELANTARSE
%token ATTACK
%token EOL

%%
action: 
| AYUDARLA EOL {  }
| ALEJARTE EOL {  }
| VAMOS EOL { }
| SOLA EOL { }
| CONTINUAR EOL { }
| ADELANTARSE EOL {  }
;

%%
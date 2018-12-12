%{
#include <stdio.h>
#include <iostream>
#include "Parser.flex.h"
#include "ManagerAction.h"
#include "PlayState.h"
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
| AYUDARLA{ std::cout<<"ayudarla"; 
	PlayState::getSingletonPtr()->ChangeState("introduccion");
}
| ALEJARTE { PlayState::getSingletonPtr()->ChangeState("alejarte") }
| VAMOS  { PlayState::getSingletonPtr()->ChangeState("vamos")}
| SOLA  {PlayState::getSingletonPtr()->ChangeState("sola") }
| CONTINUAR  { PlayState::getSingletonPtr()->ChangeState("continuar")}
| ADELANTARSE  { PlayState::getSingletonPtr()->ChangeState("adelantarse") }
;

%%
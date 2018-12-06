%{
#include "Parser.tab.h"
#include <string>
#include "ManagerAction.h"

%}

identifier		[_a-zA-Z0-9]+

%%
"ayudarla"			{ return AYUDARLA; }
"alejarte"			{ return ALEJARTE; }
"vamos"			{ return VAMOS; }
"sola"			{ return SOLA; }
"continuar"			{ return CONTINUAR; }
"adelantarse"			{ return ADELANTARSE; }
"attack"			{ return ATTACK; }
\n		  {return EOL;}

{identifier}	{return(IDENTIFIER);}



%{
#include "Parser.tab.h"
#include <string>
#include "ManagerAction.h"

%}

identifier		[_a-zA-Z0-9]+

%%
"="			{ return EQUAL; }
"ataque"  { return ATTACK; }
\n		  {return EOL;}

{identifier}	{return(IDENTIFIER);}



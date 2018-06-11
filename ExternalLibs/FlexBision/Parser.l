%{
#include "Parser.tab.h"
#include <string>
#include "ManagerAction.h"

%}

%%
		                 
"ataque"  { return ATTACK; }
\n		  {return EOL;}

%%
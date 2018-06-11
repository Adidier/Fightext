#include "Parser.flex.h"
#include "Parser.tab.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void readFlex()
{
	yyparse();
}

void main()
{
	readFlex();
}
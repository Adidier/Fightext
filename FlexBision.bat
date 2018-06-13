
cd ./ExternalLibs/FlexBision
win_flex.exe --outfile="..\..\src\Parser.flex.cpp" --header-file="..\..\src\Parser.flex.h" --wincompat  "Parser.l"
win_bison.exe --output="..\..\src\Parser.tab.cpp" --defines="..\..\src\Parser.tab.h"  "Parser.y"
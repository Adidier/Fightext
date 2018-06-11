
cd ./ExternalLibs/FlexBision
win_flex.exe --outfile="..\..\Parser.flex.cpp" --header-file="..\..\Parser.flex.h" --wincompat  "Parser.l"
win_bison.exe --output="..\..\Parser.tab.cpp" --defines="..\..\Parser.tab.h"  "Parser.y"
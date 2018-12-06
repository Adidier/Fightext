#pragma once
#include "lua.hpp"
#include<map>
#include<string>
#include "Moves.h"

using namespace std;

class History;

class LuaManager
{
	static map<string,string> history;
public:
	static int SetScene(lua_State *L);
	static map<string, string> LoadPlayer(string nameFile);
};


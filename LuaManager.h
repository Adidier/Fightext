#pragma once
#include "lua.hpp"
#include<vector>
#include<string>
#include "Moves.h"

using namespace std;

class Player;

class LuaManager
{
	static vector<Move> moves;
public:
	static void SetDefence(lua_State *L);
	static void SetAttack(lua_State *L);
	static vector<Move> LoadPlayer(string nameFile);
};


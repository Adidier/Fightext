#include "LuaManager.h"

vector<Move> LuaManager::moves;

void LuaManager::SetDefence(lua_State *L)
{
	Move m;
	moves.push_back(m);
}

void LuaManager::SetAttack(lua_State *L)
{
	Move m;
	moves.push_back(m);
}

vector<Move> LuaManager::LoadPlayer(string nameFile)
{
	moves.clear();

	return moves;
}
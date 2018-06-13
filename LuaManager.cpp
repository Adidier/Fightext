#include "LuaManager.h"

vector<Move> LuaManager::moves;

int LuaManager::SetDefence(lua_State *L)
{
	Move m;
	const char* str = lua_tostring(L, 1);
	const int value = (int)lua_tonumber(L, 2);
	m.name = str;
	m.type = 2;
	m.value = value;
	moves.push_back(m);
	return 0;
}

int LuaManager::SetAttack(lua_State *L)
{
	Move m;
	const char* str = lua_tostring(L, 1);
	const int value = (int)lua_tonumber(L, 2);
	m.name = str;
	m.type = 1;
	m.value = value;
	moves.push_back(m);
	return 0;
}

vector<Move> LuaManager::LoadPlayer(string nameFile)
{
	moves.clear();
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_base(L);
	luaopen_string(L);
	luaopen_math(L);

	lua_pushcfunction(L, SetDefence);
	lua_setglobal(L, "write");
	lua_pushcfunction(L, SetAttack);
	lua_setglobal(L, "write");

	if (luaL_loadfile(L, nameFile.c_str()) || lua_pcall(L, 0, 0, 0))
	{
		printf("cannot run configuration file: %s", lua_tostring(L, -1));
	}

	return moves;
}
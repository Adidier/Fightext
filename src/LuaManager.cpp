#include "LuaManager.h"
#include <map>
std::map<string,string> LuaManager::history;

int LuaManager::SetScene(lua_State *L)
{
	const char* str = lua_tostring(L, 1);
	const char* str2 = lua_tostring(L, 2);
	history[str] = str2;
	return 0;
}


map<string, string> LuaManager::LoadPlayer(string nameFile)
{
	history.clear();
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_base(L);
	luaopen_string(L);
	luaopen_math(L);

	lua_pushcfunction(L, SetScene);
	lua_setglobal(L, "setScene");

	if (luaL_loadfile(L, nameFile.c_str()) || lua_pcall(L, 0, 0, 0))
	{
		printf("cannot run configuration file: %s", lua_tostring(L, -1));
	}

	return history;
}
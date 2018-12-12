#include "LuaManager.h"
#include <map>
std::map<string, Scene> LuaManager::history;

int LuaManager::SetScene(lua_State *L)
{
	const char* str1 = lua_tostring(L, 1);
	const char* str2 = lua_tostring(L, 2);
	const char* str3 = lua_tostring(L, 3);
	const char* str4 = lua_tostring(L, 4);
	const char* str5 = lua_tostring(L, 5);
	const char* str6 = lua_tostring(L, 6);
	Scene scene;
	scene.history = str6;
	scene.background = str2;
	scene.image = str3;
	scene.jumps.push_back(str4);
	scene.jumps.push_back(str5);
	history[str1] = scene;
	return 0;
}


map<string, Scene> LuaManager::LoadPlayer(string nameFile)
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
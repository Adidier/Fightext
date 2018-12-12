#pragma once
#include "lua.hpp"
#include<map>
#include<string>
#include "Moves.h"
#include<vector>
#include"KImage.h"
using namespace std;

class Scene
{
public:
	KImage * menuBackground;
	KImage * waifu;
	std::string background;
	std::string image;
	std::vector<std::string> jumps;
	std::string history;
};

class History;
class LuaManager
{
	static map<string, Scene> history;
public:
	static int SetScene(lua_State *L);
	static map<string, Scene> LoadPlayer(string nameFile);
};


#pragma once

#include "Moves.h"
#include <map>
#include "LuaManager.h"
#include "KImage.h"
#include "KPlatform.h"


using namespace std;

class History
{
private:
	KImage * img;
	
public:
	History(string nameFile, KPlatform *oContext);
	KImage *getImage();
	~History();
	map<string, Scene> history;
};
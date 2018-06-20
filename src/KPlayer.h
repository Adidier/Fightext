#pragma once

#include "Moves.h"
#include <vector>
#include "LuaManager.h"
#include "KImage.h"
#include "KPlatform.h"


using namespace std;

class Player
{
private:
	KImage * img;
	vector<Move> moves;
public:
	Player(string nameFile);
	KImage *getImage();
	~Player();
};
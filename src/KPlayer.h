#pragma once

#include "Moves.h"
#include <vector>
#include "LuaManager.h"
using namespace std;

class Player
{
private:
	vector<Move> moves;


public:
	Player(string nameFile);
	~Player();

};
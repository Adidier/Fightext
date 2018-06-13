#include "LuaManager.h"
#include "KPlayer.h"




Player::Player(string nameFile)
{

	vector<Move> moves = LuaManager::LoadPlayer(nameFile+".lua");

}


Player::~Player()
{
}

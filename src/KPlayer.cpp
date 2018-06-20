#include "LuaManager.h"
#include "KPlayer.h"




Player::Player(string nameFile)
{
	vector<Move> moves = LuaManager::LoadPlayer(nameFile+".lua");
	img = KPlatform::CreateImage(nameFile+".png");
}

KImage *Player::getImage()
{
	return img;
}

Player::~Player()
{
}

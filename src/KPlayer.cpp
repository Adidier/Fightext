#include "LuaManager.h"
#include "KPlayer.h"




History::History(string nameFile)
{
	history = LuaManager::LoadPlayer(nameFile+".lua");
	img = KPlatform::CreateImage(nameFile+".png");
}

KImage *History::getImage()
{
	return img;
}

History::~History()
{
}

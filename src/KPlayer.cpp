#include "LuaManager.h"
#include "KPlayer.h"




History::History(string nameFile, KPlatform *oContext)
{
	history = LuaManager::LoadPlayer(nameFile+".lua");
	img = KPlatform::CreateImage(nameFile+".png");


	for (auto &obj : history)
	{
		obj.second.menuBackground =  oContext->CreateImage("./Assets/backgrounds/"+ obj.second.background);
		obj.second.waifu = oContext->CreateImage("./Assets/mona/" + obj.second.image);
	}
}

KImage *History::getImage()
{
	return img;
}

History::~History()
{
}

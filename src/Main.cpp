#include <string>
#include <iostream>
#include "KPlayer.h"
#include "KGameManager.h"
#include "MenuState.h"
#include "PlayState.h"


int main(int, char**) {

	KGameManager * kGameManager = KGameManager::getSingletonPtr();
	try
	{
		kGameManager->PushState(MenuState::getSingletonPtr())
		kGameManager->UpdateState);
	}
	catch (...)
	{
		return 0;
	}
}

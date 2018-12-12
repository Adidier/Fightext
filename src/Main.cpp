#define AUDIO_DEF
#include <string>
#include <iostream>
#include "KPlayer.h"
#include "KGameManager.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AudioClass.h"
#include <thread>


void LilAudio() {
	AudioClass a;
	a.Init();
	while (!a.isDone) {
		a.Update();
	}
}

int main(int, char**) {

	std::thread aud(LilAudio);

	KGameManager * kGameManager = KGameManager::getSingletonPtr();
	try
	{
		kGameManager->PushState(MenuState::getSingletonPtr());
		kGameManager->UpdateState();
	}
	catch (...)
	{
		return 0;
	}
}

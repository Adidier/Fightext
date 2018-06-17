#include "KGameManager.h"


KGameManager* KGameManager::kGameManager;

KGameManager::KGameManager(void) :bShutdown(false) {
	configureGame();
	kPlataform = new KPlatform();
}

KGameManager::~KGameManager(void) {
	while (!kStates.empty()) {
		kStates.back()->Exit();
		kStates.pop_back();
	}
}

void KGameManager::StartGame(KGameState * kGameState) {
	this->ChangeState(kGameState);
}

bool KGameManager::configureGame(void) {
	config();


	return true;
}

void KGameManager::ChangeState(KGameState *kGameState) {
	if (!kStates.empty()) {
		kStates.back()->Exit();
		kStates.pop_back();
	}
	kStates.push_back(kGameState);
	kStates.back()->Enter(kPlataform);
}

void KGameManager::UpdateState(void)
{
	while (!kStates.empty()) {
		kStates.back()->Update(1);
	}
}



void KGameManager::PushState(KGameState *kGameState) {
	if (!kStates.empty()) {
		kStates.back()->Pause();
	}
	kStates.push_back(kGameState);
	kStates.back()->Enter(kPlataform);
}

void KGameManager::PopState() {
	if (!kStates.empty()) {
		kStates.back()->Exit();
		kStates.pop_back();
	}
	if (!kStates.empty()) {
		kStates.back()->Resume();
	}

}

void KGameManager::RequestShutdown(void) {
	bShutdown = true;
}

KGameManager* KGameManager::getSingletonPtr(void) {
	if (!kGameManager) {
		kGameManager = new KGameManager();
	}
	return kGameManager;
}


void KGameManager::config() {
}



/*
ValueMap *KGameManager::getListLevels(){
return &cHistoryDict;
}



#include "KGameManager.h"
bool getIsDebug();

KGameManager* KGameManager::kGameManager;

KGameManager::KGameManager( void ):bShutdown( false ) {
kPlataform = new KPlatform();
}

KGameManager::~KGameManager( void ) {
while( !kStates.empty() ) {
kStates.back()->Exit();
kStates.pop_back();
}
}

void KGameManager::StartGame( KGameState * kGameState ) {
this->ChangeState( kGameState );

}

bool KGameManager::ConfigureGame( void ) {
return true;
}

void KGameManager::SetupResources( void ) {

}

void KGameManager::ChangeState( KGameState *kGameState ) {
if( !kStates.empty() ) {
kStates.back()->Exit();
kStates.pop_back();
}z
kStates.push_back( kGameState );
kStates.back()->Enter(kPlataform);
}

void KGameManager::PushState( KGameState *kGameState ) {
if( !kStates.empty() ) {
kStates.back()->Pause();
}
kStates.push_back( kGameState );
kStates.back()->Enter(kPlataform);
}

void KGameManager::PopState() {
if( !kStates.empty() ) {
kStates.back()->Exit();
kStates.pop_back();
}
if( !kStates.empty() ) {
kStates.back()->Resume();
}
}

void KGameManager::RequestShutdown( void ) {
bShutdown = true;
}

KGameManager* KGameManager::GetSingletonPtr( void ) {
if( !kGameManager ) {
kGameManager = new KGameManager();
}
return kGameManager;
}

*/

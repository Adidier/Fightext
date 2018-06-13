#include "KGameState.h"
#include "KGameManager.h"


void KGameState::Enter( KPlatform *oContext ){
}

void KGameState::SetScaleFactor(float fScaleFactor){
}


void KGameState::ChangeState( KGameState * kState ) { 
    KGameManager::getSingletonPtr()->ChangeState( kState );
}

void KGameState::PushState( KGameState * kState ) { 
    KGameManager::getSingletonPtr()->PushState( kState );
}

void KGameState::PopState( void ) { 
    KGameManager::getSingletonPtr()->PopState();
}

void KGameState::RequestShutdown( void ) {
    KGameManager::getSingletonPtr()->RequestShutdown();
}

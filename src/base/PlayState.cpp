#include "PlayState.h"



PlayState* PlayState::oPlayState;

PlayState* PlayState::getSingletonPtr( void ){
    if( !oPlayState ) {
        oPlayState = new PlayState();
    if (oPlayState)
   	{
		
		return oPlayState;
  	}
    	else
    	{
        	return nullptr;
    	}
    }
}

void PlayState::Pause( void ) { 

}

void PlayState::Resume( void ) {

}

void PlayState::Update( double dTimeElapsed ) {
	
	
}

void PlayState::Exit( void ) {

}

PlayState::PlayState( void ){

}

PlayState::~PlayState( void ){
	
}

void PlayState::loadResources( std::string level){ //hacer una clase especial para esto
	
}

void PlayState::loadMapSize(){

}

bool PlayState::init( void ){
	KGameManager * kGameManager = KGameManager::getSingletonPtr();
	this->dDoubleTapTime   =  DOUBLE_TAP_TIME;

	this->iNumberOfTaps=0;
	return true;
}

long PlayState::millisecondNow(){
     return 0;
}


void PlayState::tapHandler(float dt){
 }

 void PlayState::configUserEvents(){
 }

 void PlayState::initBackGroundSound(std::string oSound){
 }

void PlayState::Enter(KPlatform *_oViewer) {

}


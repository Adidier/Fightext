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
	
	oContext->checkEvent(this, &KGameState::Press, SDLK_0);

	oContext->RenderClear();

	oContext->RenderImage(menuBackground, 0, 0);
	oContext->RenderPresent();
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

	menuBackground = oContext->CreateImage("background.png");

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
	oContext = _oViewer;
	init();

}


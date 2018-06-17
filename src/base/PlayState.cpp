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

bool PlayState::Press(int key)
{
	if(key>= '0' && key <= 'z')
		consoleBuffer += (char)key;
	else if(key == '\r')
	{
		std::cout << "do";
	}
	else if (key == '\b')
	{
		consoleBuffer = consoleBuffer.substr(0, consoleBuffer.size() - 1);
	}

	return false;
}

void PlayState::Update( double dTimeElapsed ) {
	
	oContext->checkEvent(this, &KGameState::Press);

	oContext->RenderClear();

	oContext->RenderImage(menuBackground, 0, 0);
	oContext->renderText(consoleBuffer.c_str(), "sample.ttf");
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


#include "MenuState.h"

MenuState* MenuState::oMenuState;


MenuState* MenuState::getSingletonPtr( void ){
   if( !oMenuState ) {
        oMenuState = new MenuState();
    if (oMenuState)
   	{
		return oMenuState;
  	}
    	else
    	{
        	return nullptr;
    	}
    }
}

void MenuState::Pause( void ) {

}

void MenuState::Resume( void ) {

}

void MenuState::Exit( void ) {

}

MenuState::MenuState( void )
{
}

MenuState::~MenuState( void )
{
}

bool MenuState::init( void ){
	return true;
}

void MenuState::Enter(KPlatform *oViewer) {
	oViewer->setSizeResourceBackgruound(480,800);
    KGameState::Enter(oViewer);
    init();
}



void MenuState::Update( double dTimeElapsed )
{

}














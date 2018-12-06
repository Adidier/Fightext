#include "MenuState.h"
#include "KPlatform.h"


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

	menuBackground = oContext->CreateImage("./Assets/backgrounds/Menu.jpg");
	return true;
}

void MenuState::Enter(KPlatform *oViewer) {
	oViewer->setSizeResourceBackgruound(480,800);
    KGameState::Enter(oViewer);
    init();
}

bool MenuState::Press(int key)
{
	KGameManager * kGameManager = KGameManager::getSingletonPtr();
	kGameManager->ChangeState(PlayState::getSingletonPtr());;

	return false;
}

void MenuState::Update( double dTimeElapsed )
{
	oContext->checkEvent(this, &KGameState::Press);

	oContext->RenderClear();

	oContext->RenderImage(menuBackground,0,0);
	oContext->RenderPresent();
}














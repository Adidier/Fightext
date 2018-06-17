#include "IntroState.h"


IntroState* IntroState::oIntroState;

IntroState* IntroState::getSingletonPtr( void ){
    if( !oIntroState ) {
        oIntroState = new IntroState();
		if (oIntroState)
		{
		
			return oIntroState;
		}
    	else
    	{
        	return nullptr;
    	}
    }
}

void IntroState::Pause( void ) {

}

void IntroState::Resume( void ) {




}

void IntroState::Update( double dTimeElapsed ) {
	

	
}

void IntroState::Exit( void ) {

}

IntroState::IntroState( void )
{
	

}

IntroState::~IntroState( void )
{
	
}


void IntroState::Enter(KPlatform *oViewer) {
	oViewer->setSizeResourceBackgruound(480,800);
    KGameState::Enter(oViewer);


}

IntervalLayer::IntervalLayer()
{

}

void IntroState::step1(float dt)
{
	KGameManager * kGameManager = KGameManager::getSingletonPtr();
	try
	{
		kGameManager->PushState( MenuState::getSingletonPtr() );
	}
	catch (...)
	{
		return ;
	}

}

bool IntroState::init( void ){

	return true;
}


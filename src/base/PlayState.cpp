#include "PlayState.h"
#include "Parser.flex.h"
#include "Parser.tab.h"


//PlayState* PlayState::oPlayState; descomentar

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

bool PlayState::Parser(string command)
{
	command = "ataque=aa\n";
	yy_scan_string((char *)command.c_str());
	yyparse();
	return false;
}

bool PlayState::Press(int key)
{
	if(key>= '0' && key <= 'z' || key == ' ')
		consoleBuffer += (char)key;
	else if(key == '\r')
	{
		Parser(consoleBuffer+"\n");
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
	oContext->RenderImage(player1->getImage(), 700, 0);
	oContext->RenderImage(player2->getImage(), 0, 300);
	oContext->renderText(consoleBuffer.c_str(), "sample.ttf");


	oContext->RenderPresent();
}

void PlayState::Exit( void ) {

}

PlayState::PlayState( void ){

}

PlayState::~PlayState( void ){
	
}

bool PlayState::init( void ){

	menuBackground = oContext->CreateImage("background.png");

	return true;
}

void PlayState::Enter(KPlatform *_oViewer) {
	oContext = _oViewer;
	player1 = new Player("mexican");
	player2 = new Player("american");
	init();

}


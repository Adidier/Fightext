#include "PlayState.h"
#include "Parser.flex.h"
#include "Parser.tab.h"


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

bool PlayState::Parser(string command)
{
	command = "ataque=pega\n";
	yy_scan_string((char *)command.c_str());
	yyparse();
	return false;
}

bool PlayState::Press(int key)
{
	if(key>= '0' && key <= 'z' || key == ' ')
		consoleBuffer += (char)key;
	else if (key == '\r')
	{
		Parser(consoleBuffer + "\n");
	}
	else if (key == '\b')
	{
		consoleBuffer = consoleBuffer.substr(0, consoleBuffer.size() - 1);
	}

	return false;
}

void PlayState::Update(double dTimeElapsed) {

	oContext->checkEvent(this, &KGameState::Press);

	oContext->RenderClear();

	oContext->RenderImage(menuBackground, 0, 0);
	oContext->RenderImage(waifu, 700, 0);
	oContext->renderTextByCharacter(history->history["Introduccion"].c_str(), "Arial.ttf", currentTextIndex);
	if (currentTextIndex < history->history["Introduccion"].length())
	{
		SDL_Delay(100);
		currentTextIndex++;
	}
	else
	{

	}


	oContext->RenderPresent();
}

void PlayState::Exit( void ) {

}

PlayState::PlayState( void ): currentText("Adidier es cool") {

}

PlayState::~PlayState( void ){
	
}

bool PlayState::init( void ){

	menuBackground = oContext->CreateImage("./Assets/backgrounds/Parque.png");
	waifu = oContext->CreateImage("./Assets/LoveLive/Maki2.png");
	return true;
}

void PlayState::Enter(KPlatform *_oViewer) {
	oContext = _oViewer;
	history = new History("mexican");
	init();

}


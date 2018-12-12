#include "PlayState.h"
#include "Parser.flex.h"
#include "Parser.tab.h"


PlayState* PlayState::oPlayState;

std::string PlayState::state="introduccion";

PlayState* PlayState::getSingletonPtr( void ){
	if (!oPlayState) {
		oPlayState = new PlayState();
	}
	return oPlayState;
}

void PlayState::Pause( void ) { 

}

void PlayState::Resume( void ) {

}


void PlayState::ChangeState(std::string _state)
{
	for (auto &x :history->history[state].jumps)
	{
		if (x==_state)
		{
			state = _state;
		}
	}
}

bool PlayState::Parser(string command)
{
	yy_scan_string((char *)command.c_str());
	yyparse();
	return false;
}

bool PlayState::Press(int key,int x,int y)
{
	if(!isKeyboardEnable)
		return false;

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
	oContext->RenderImage(history->history[state].menuBackground, 0, 0);
	oContext->RenderImage(history->history[state].waifu, 0, 300);
	oContext->renderTextByCharacter(history->history[state].history.c_str(), "comici.ttf", currentTextIndex,posy);
	if (currentTextIndex < history->history[state].history.length())
	{
		SDL_Delay(100);
		currentTextIndex++;
		aiudaa++;
	}
	else
	{
		isKeyboardEnable = true;
	}
	if (isKeyboardEnable)
	{
		oContext->renderText(consoleBuffer, "comici.ttf");
	}
	if (aiudaa > 40)
	{
		posy -= 60;
		aiudaa = 0;
	}
	oContext->RenderPresent();
	std::cout << aiudaa<<endl;	
}

void PlayState::Exit( void ) {

}

PlayState::PlayState( void ): isKeyboardEnable(false){

}

PlayState::~PlayState( void ){
	
}

bool PlayState::init( void ){



	return true;
}

void PlayState::Enter(KPlatform *_oViewer) {
	oContext = _oViewer;
	history = new History("./Assets/rescatado", oContext);

	init();


}


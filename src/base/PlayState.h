#ifndef _PLAYER_STATE_H_
#define _PLAYER_STATE_H_

#include "string"
#include "KGameState.h"
#include "MenuState.h"
#include "KGameManager.h"
#include "KMacros.h"
#include "KPlayer.h"

class PlayState : public KGameState 
{
public:
    ~PlayState( void );
    bool init( void );
    void Enter(KPlatform *oViewer);
    void Exit( void );
    void Pause( void );
    void Resume( void );
	void ChangeState(std::string state);
    void Update( double lTimeElapsed );
    static PlayState* getSingletonPtr( void );

	bool Press(int key, int x, int y);
	bool Parser(string command);
private:
	PlayState( void );
	PlayState( const PlayState& ) { }
	PlayState & operator = ( const PlayState& );
	static PlayState *oPlayState;
	std::string currentText;
	int currentTextIndex = 0;
	int aiudaa = 0;
	int posy = 0;
	
protected:


	std::string consoleBuffer;
	History *history;
    KPlatform *oViewer;
	bool isKeyboardEnable;
	static std::string state;

    
   
};

#endif

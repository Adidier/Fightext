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
    void Update( double lTimeElapsed );
    static PlayState* getSingletonPtr( void );

	bool Press(int key);
	bool Parser(string command);
private:
	PlayState( void );
	PlayState( const PlayState& ) { }
	PlayState & operator = ( const PlayState& );
	static PlayState *oPlayState;
	std::string currentText;
	int currentTextIndex = 0;
protected:
	KImage * menuBackground;
	KImage * waifu;

	std::string consoleBuffer;
	History *history;
    KPlatform *oViewer;

    
   
};

#endif

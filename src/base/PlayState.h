#ifndef _INTRO_STATE_H_
#define _INTRO_STATE_H_

#include "string"
#include "KGameState.h"
#include "MenuState.h"
#include "KGameManager.h"
#include "KMacros.h"

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
    void loadResources(std::string level);

    
private:
	PlayState( void );
	PlayState( const PlayState& ) { }
	PlayState & operator = ( const PlayState& );
	static PlayState *oPlayState;
private:

	KImage * menuBackground;

    std::string sMapName;

    bool bTouchHasMoved;
    double dTouchStart;
    double dDoubleTapTime;
    int iNumberOfTaps;
    KPlatform *oViewer;

    bool bPlayerSelected;

    long millisecondNow();
    void tapHandler(float dt);
    void loadMapSize();
    void configUserEvents();
    void initBackGroundSound(std::string oSound);
};

#endif

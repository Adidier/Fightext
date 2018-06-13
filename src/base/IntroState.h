#ifndef _INTRO_STATE_H_
#define _INTRO_STATE_H_

#include "KGameState.h"
#include "MenuState.h"
#include "KGameManager.h"

class IntervalLayer 
{
public:
    IntervalLayer(void);
public:




};

class IntroState : public KGameState 
{
public:
    ~IntroState( void );
    bool init( void );
    void Enter(KPlatform *oViewer);
    void Exit( void );
    void Pause( void );
    void Resume( void );
    void Update( double lTimeElapsed );
    static IntroState* getSingletonPtr( void );
    void step1(float dt);
private:
	IntroState( void );
	IntroState( const IntroState& ) { }
	IntroState & operator = ( const IntroState& );
	static IntroState *oIntroState;
private:


};

#endif


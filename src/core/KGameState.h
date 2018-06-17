#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include "KPlatform.h"

class KPlatform;

class KGameState {
public:
    ~KGameState( void ) { }

    virtual bool init( void ) = 0;
    virtual void Enter( KPlatform *oContext )  ;
    virtual void Exit( void )   = 0;
    virtual void Pause( void )  = 0;
    virtual void Resume( void ) = 0;
    virtual void Update( double lTimeElapsed ) = 0;
    void ChangeState( KGameState *state );
    void PushState( KGameState *state );
    void PopState( void );
    void RequestShutdown( void );
	virtual bool Press(int key) { return false; };
    void SetScaleFactor(float fScaleFactor);
protected:
    KGameState( void ) { }
	KPlatform *oContext;
private:
    KGameState( const KGameState& ) { }
    KGameState & operator = ( const KGameState& );

	
};
#endif


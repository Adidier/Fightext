#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_
#include "KGameState.h"
#include "PlayState.h"

class MenuState : public KGameState 
{
public: 
    ~MenuState( void );
    bool init( void );
    void Enter(KPlatform *oViewer);
    void Exit( void );
    void Pause( void );
    void Resume( void );
    void Update( double lTimeElapsed );
    static MenuState* getSingletonPtr( void );
private: 
    MenuState( void );
    MenuState( const MenuState& ) { }
    MenuState & operator = ( const MenuState& );
    static MenuState *oMenuState;
private:
};

#endif


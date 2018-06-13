#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "vector"
#include "string"
#include "KGameState.h"
#include "KPlatform.h"
#include <queue>


class KGameManager;

class KGameManager 
{
public:
    ~KGameManager( void );
    void StartGame( KGameState * kGameState );
    void ChangeState( KGameState * kGameState );
    void PushState( KGameState * kGameState );
    void PopState( void );
    void RequestShutdown( void );    
    static KGameManager* getSingletonPtr( void );

private:
    KGameManager( void );
    KGameManager( const KGameManager& ) { }
    KGameManager & operator = ( const KGameManager& );
    bool configureGame( void );
    void configDebugMode(void );
    void configHistory( void );
    static KGameManager *kGameManager;
private: 
    bool 		bShutdown;
    bool 		bDebug;
    KPlatform * kPlataform;
    std::string	sHistoryFile;
	std::vector<KGameState *> kStates;
};
#endif	

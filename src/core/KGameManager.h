#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "vector"
#include "string"
#include "KGameState.h"
#include "KPlatform.h"


class KGameManager;

class KGameManager
{
public:
	~KGameManager(void);
	void StartGame(KGameState * kGameState);
	void ChangeState(KGameState * kGameState);
	void PushState(KGameState * kGameState);
	void PopState(void);
	void UpdateState(void);
	void RequestShutdown(void);
	static KGameManager* getSingletonPtr(void);
public:
	// ValueMap *getListLevels();

private:
	KGameManager(void);
	KGameManager(const KGameManager&) { }
	KGameManager & operator = (const KGameManager&);
	bool configureGame(void);
	void config(void);

	static KGameManager *kGameManager;
private:
	bool 		bShutdown;
	bool 		bDebug;
	KPlatform * kPlataform;
	std::string	sHistoryFile;
	std::vector<KGameState *> kStates;

};
#endif	

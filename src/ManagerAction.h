#pragma once
#include<string>
class ManagerAction
{
private:
	ManagerAction();
	~ManagerAction();
	static ManagerAction * ptr;
	
public:
	void SetAttack(std::string name);
	static ManagerAction *getPtr();
};


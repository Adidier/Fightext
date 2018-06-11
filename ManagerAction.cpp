#include "ManagerAction.h"
#include<iostream>

ManagerAction* ManagerAction::ptr = nullptr;

ManagerAction::ManagerAction()
{
}
ManagerAction::~ManagerAction()
{
}
void ManagerAction::SetAttack(std::string name)
{
	std::cout << name;
}
ManagerAction *ManagerAction::getPtr()
{
	if (ptr != nullptr)
		return ptr;
	ptr = new ManagerAction();
	return ptr;
}
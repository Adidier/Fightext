#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <string>

enum ObjectType
{
	Player,
	Enemie
};


enum ObjectState
{
	Active,
	Death
};

class KObject
{
private:
	std::string 	sName;
	int 	iId;
	int 	iType;
	int		iState;
public:
	~KObject();
	KObject();
	KObject(int _iType,const std::string &_sName,int _iState);

	std::string getName();
	int getId();
	int getType();
	int getState();

	void setState(const int &_iState);
	

};


#endif

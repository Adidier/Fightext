#include "KObject.h"

KObject::~KObject(){
}

KObject::KObject(){ //quitar este constructor

}

KObject::KObject(int _iType,const std::string &_sName,int _iState){
	sName=_sName;
	iType=_iType;
	iId= 0;// gameManager debe dar el Id unico
	iState=_iState;

}


std::string KObject::getName(){
	return sName;
}
int KObject::getId(){
	return iId;

}
int KObject::getType(){
	return iType;
}
int KObject::getState(){
	return iState;
}

void KObject::setState(const int &_iState){
	iState=_iState;
}

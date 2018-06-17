#include "KImage.h"
#include "KPlatform.h"

KImage::~KImage(){
}

KImage::KImage(){ //quitar este constructor

}

std::string KImage::getName(){
	return sName;
}

SDL_Texture *KImage::getTexture()
{
	return texture;
}


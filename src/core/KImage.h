#ifndef _KIMAGE_H_
#define _KIMAGE_H_

#include <string>
#include <SDL.h>
#include "SDL_ttf.h"
#include "SDL_image.h"

class KImage 
{
private:
	std::string 	sName;
	
public:
	~KImage();
	KImage();

	std::string getName();
	SDL_Texture *texture;
	SDL_Texture *getTexture();	


};


#endif

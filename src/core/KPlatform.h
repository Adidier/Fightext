#ifndef  _PLATFORM_H_
#define  _PLATFORM_H_

#include <SDL.h>
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "KImage.h"
#include "KGameState.h"

class KGameState;

class KPlatform 
{
public:
	KPlatform();
	virtual ~KPlatform();
    virtual bool applicationDidFinishLaunching();
    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();

  

    int getHeightScreen();
    int getWidthScreen();

    float getHeightScale();
    float getWidthScale();
	
	
	
	void checkEvent(KGameState *obj,bool (KGameState::*f)(int ), int event);
    void setSizeResourceBackgruound(int fHeight,int fWidth);

	void RenderClear();
	void RenderImage(KImage *image, int x, int y);
	void RenderPresent();

	KImage* CreateImage(std::string name);

private:
	SDL_Texture * renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);
	void renderTexture(KImage *tex, int x, int y);
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst);
	
	bool bFullScreen;
	int iHeightScreen;
	int iWidthScreen;

	int iResourceHeight;
	int iResourceWidth;
	SDL_Window *window;
	SDL_Renderer *renderer;
}; 
#endif 

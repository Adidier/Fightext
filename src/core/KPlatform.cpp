#include "KMacros.h"
#include "KPlatform.h"

using namespace std;

#define  LOG_TAG    "main"

SDL_Renderer *KPlatform::renderer;
KPlatform::KPlatform() {

	iResourceHeight=700;
	iResourceWidth=950; 

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init";
		return;
	}

	if (TTF_Init() != 0) {
		std::cout << "TTF_Init";
		SDL_Quit();
		return;
	}

	window = SDL_CreateWindow("Fightext", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, iResourceWidth, iResourceHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "CreateWindow";
		SDL_Quit();
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "CreateRenderer";
		SDL_Quit();
		return;
	}
}

KPlatform::~KPlatform() 
{
}

bool KPlatform::applicationDidFinishLaunching() {

    return true;
}


int KPlatform::getHeightScreen(){
	return 1;
}

void KPlatform::setSizeResourceBackgruound(int fHeight,int fWidth){
	iResourceHeight=fHeight;
	iResourceWidth=fWidth;
}

int getWidthScreen(){
	return 1;
}

float KPlatform::getHeightScale(){
	return 1;
}

float KPlatform::getWidthScale(){
	return 1;

}

void KPlatform::applicationDidEnterBackground() {
  //  SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}


void KPlatform::applicationWillEnterForeground() {
    //SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void KPlatform::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst ) {
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void KPlatform::renderTexture(KImage *tex, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(tex->getTexture(), NULL, NULL, &dst.w, &dst.h);
	renderTexture(tex->getTexture(), renderer, dst);
}

void KPlatform::renderText(const std::string &message, const std::string &fontFile)
{
	if (message.size() == 0)
		return;

	SDL_Color color = { 0, 0, 0, 255 };
	SDL_Texture *image = renderText(message.c_str(),"sample.ttf",color, 64, renderer);
	SDL_Rect dst;
	dst.x = 0;
	dst.y = 0;
	SDL_QueryTexture(image, NULL, NULL, &dst.w, &dst.h);
	renderTexture(image, renderer, dst);
}


SDL_Texture* KPlatform::renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr) {
		std::cout << "TTF_OpenFont";
		return nullptr;
	}
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr) {
		TTF_CloseFont(font);
		std::cout << "TTF_RenderText";
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr) {
		std::cout << "CreateTexture";
	}
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}

void KPlatform::checkEvent(KGameState *obj, bool (KGameState::*f)(int))
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_KEYDOWN) {
				(obj->*f)(e.key.keysym.sym);
		}
	}
}
void KPlatform::RenderClear()
{
	SDL_RenderClear(renderer);
}

void KPlatform::RenderImage(KImage *image,int x,int y)
{
	renderTexture(image, x, y);
}


void KPlatform::RenderPresent()
{
	SDL_RenderPresent(renderer);
}

KImage* KPlatform::CreateImage(std::string name)
{
	KImage* image = new KImage();
	SDL_Surface* loadedSurface = IMG_Load(name.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", name.c_str(), IMG_GetError());
	}
	else
	{
	
		image->texture = SDL_CreateTextureFromSurface(KPlatform::renderer, loadedSurface);
		if (image->texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", name.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}
	return image;
}



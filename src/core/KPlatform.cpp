#include "KMacros.h"
#include "KPlatform.h"

using namespace std;

#define  LOG_TAG    "main"

KPlatform::KPlatform() {

	iResourceHeight=480;
	iResourceWidth=600; //resolution by default

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init";
		return;
	}

	if (TTF_Init() != 0) {
		std::cout << "TTF_Init";
		SDL_Quit();
		return;
	}

	window = SDL_CreateWindow("Lesson 5", SDL_WINDOWPOS_CENTERED,
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


// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
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

void KPlatform::checkEvent(KGameState *obj, bool (KGameState::*f)(int), int event)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_KEYDOWN) {
			if(e.key.keysym.sym == event)
				(obj->*f)(event);
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
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(name.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", name.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		
		image->texture = SDL_CreateTextureFromSurface(KPlatform::renderer, loadedSurface);
		if (image->texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", name.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return image;
}




//		renderTexture(image, renderer, x, y);
//		SDL_RenderPresent(renderer);

//
//int main1(int, char**) {
//
//
//
//
//
//	SDL_Color color = { 255, 255, 255, 255 };
//	SDL_Texture *image = renderText("Adidier", "sample.ttf", color, 64, renderer);
//	int iW = 100, iH = 100;
//	int x = SCREEN_WIDTH / 2 - iW / 2;
//	int y = SCREEN_HEIGHT / 2 - iH / 2;
//
//	SDL_Event e;
//	bool quit = false;
//	while (!quit) {
//		//Event Polling
//		while (SDL_PollEvent(&e)) {
//			if (e.type == SDL_QUIT) {
//				quit = true;
//			}
//			//Use number input to select which clip should be drawn
//			if (e.type == SDL_KEYDOWN) {
//				switch (e.key.keysym.sym) {
//				case SDLK_1:
//				case SDLK_KP_1:
//					break;
//				default:
//					break;
//				}
//			}
//		}
//		SDL_RenderClear(renderer);
//		renderTexture(image, renderer, x, y);
//		SDL_RenderPresent(renderer);
//	}
//	SDL_Quit();
//	return 0;
//}
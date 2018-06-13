#include <string>
#include <iostream>
#include <SDL.h>
#include "SDL_ttf.h"
#include "KPlayer.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect *clip = nullptr) {
	SDL_RenderCopy(ren, tex, clip, &dst);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip = nullptr) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if (clip != nullptr) {
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}
	renderTexture(tex, ren, dst, clip);
}

SDL_Texture* renderText(const std::string &message, const std::string &fontFile,SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr) {
		std::cout<<"TTF_OpenFont";
		return nullptr;
	}
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr) {
		TTF_CloseFont(font);
		std::cout<<"TTF_RenderText";
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr) {
		std::cout<<"CreateTexture";
	}
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}

int main(int, char**) {
	Player axel("Mex");

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout<<"SDL_Init";
		return 1;
	}

	if (TTF_Init() != 0) {
		std::cout<<"TTF_Init";
		SDL_Quit();
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Lesson 5", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout<<"CreateWindow";
		SDL_Quit();
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout<<"CreateRenderer";
		SDL_Quit();
		return 1;
	}
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Texture *image = renderText("Adidier","sample.ttf",color, 64, renderer);
	int iW = 100, iH = 100;
	int x = SCREEN_WIDTH / 2 - iW / 2;
	int y = SCREEN_HEIGHT / 2 - iH / 2;

	SDL_Event e;
	bool quit = false;
	while (!quit) {
		//Event Polling
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			//Use number input to select which clip should be drawn
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_1:
				case SDLK_KP_1:
					break;
				default:
					break;
				}
			}
		}
		SDL_RenderClear(renderer);
		renderTexture(image, renderer, x, y);
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();
	return 0;
}
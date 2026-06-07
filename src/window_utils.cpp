#include "window_utils.h"

namespace WindowUtils
{
	SDL_Window* initMainWindow(int width, int height) {
		// Create window
		SDL_Window* window = SDL_CreateWindow(
			"My First Game",
			width, height,
			0
		);

		if (!window) {
			std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
			SDL_Quit();
			std::exit(1);
		}
		return window;
	}

	SDL_Renderer* initRenderer(SDL_Window* window) {
		SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

		if (!renderer) {
			std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
			SDL_DestroyWindow(window);
			SDL_Quit();
			std::exit(1);
		}

		return renderer;
	}

	SDL_Texture* createTexture(SDL_Renderer* renderer, const char* path) {
		SDL_Surface* surface = IMG_Load(path);
		if (!surface) {
			std::cerr << "IMG_Load Error: " << SDL_GetError() << "\n";
			std::exit(1);
		}

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_DestroySurface(surface);
		if (!texture) {
			std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << "\n";
			std::exit(1);
		}

		return texture;
	}
}
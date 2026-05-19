
#include "window_utils.h"

namespace Window
{
	SDL_Window* initMainWindow() {
		// Create window
		SDL_Window* window = SDL_CreateWindow(
			"My First Game",
			800, 600,
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
}
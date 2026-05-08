// game.cpp : Defines the entry point for the application.
//

#include "main.h"
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
	// Initialize SDL
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
		return 1;
	}

	// Create window
	SDL_Window* window = SDL_CreateWindow(
		"My First Game",
		800, 600,
		0
	);

	if (!window) {
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
		SDL_Quit();
		return 1;
	}

	bool running { true };
	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}
	}

	// Clean up
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}

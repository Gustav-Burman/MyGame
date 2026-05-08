// game.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <SDL3/SDL.h>
#include "windows.h"

int main(int argc, char* argv[]) {
	// Init SDL
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
		return 1;
	}
	// Create window
	SDL_Window* window = initMainWindow();






	// For main loop
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

// game.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <SDL3/SDL.h>
#include "window_utils.h"

int main(int argc, char* argv[]) {
	// Init SDL
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
		return 1;
	}

	SDL_Window* window = Window::initMainWindow();
	SDL_Renderer* renderer = Window::initRenderer(window);

	// For main loop
	bool running { true };
	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		// Render
		SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); // Dark grey
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255); // Orange
		SDL_FRect rect = { 300.0f, 200.0f, 200.0f, 150.0f };
		SDL_RenderFillRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 200, 255, 255); // cyan
		SDL_RenderLine(renderer, 0, 0, 800, 600);

		SDL_RenderPresent(renderer);

	}

	// --- Clean up ---
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}

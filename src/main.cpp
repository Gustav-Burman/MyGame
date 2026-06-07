// game.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "window_utils.h"

int main(int argc, char* argv[]) {
	// Init SDL
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
		return 1;
	}

	int windowWidth{ 1200 };
	int windowHeight{ 800 };

	SDL_Window* window = WindowUtils::initMainWindow(windowWidth, windowHeight);
	SDL_Renderer* renderer = WindowUtils::initRenderer(window);

	SDL_Texture* backgroundWithTrees = WindowUtils::createTexture(renderer, "assets/background_with_trees.png");
	SDL_FRect destRect = { 0, 0, windowWidth, windowHeight };

	// For main loop
	bool running { true };
	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}

			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.scancode == SDL_SCANCODE_ESCAPE)
					running = false;
			}
		}

		SDL_RenderTexture(renderer, backgroundWithTrees, NULL, &destRect);
		SDL_RenderPresent(renderer);

	} // End main loop

	// --- Clean up ---
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

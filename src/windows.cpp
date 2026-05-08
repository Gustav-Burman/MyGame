
#include "windows.h"

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
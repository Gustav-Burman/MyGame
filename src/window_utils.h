#ifndef WINDOW_UTILS
#define WINDOW_UTILS

#include <iostream>
#include <SDL3/SDL.h>

namespace Window
{
	// Initialize the main window that will run the game
	SDL_Window* initMainWindow();

	// Initialize the renderer
	SDL_Renderer* initRenderer(SDL_Window* window);
}

#endif
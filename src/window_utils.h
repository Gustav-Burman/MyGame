#ifndef WINDOW_UTILS
#define WINDOW_UTILS

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace WindowUtils
{
	// Initialize the main window that will run the game
	SDL_Window* initMainWindow(int width, int height);

	// Initialize the renderer
	SDL_Renderer* initRenderer(SDL_Window* window);

	// Create texture from surface from image at path
	SDL_Texture* createTexture(SDL_Renderer* renderer, const char* path);
}

#endif
#include "game_state.h"

GameState* GameState::instance = nullptr;

GameState* GameState::getInstance()
{
	if (instance == nullptr)
	{
		// Need to populate initial values
		instance = new GameState();
	}
	return instance;
}
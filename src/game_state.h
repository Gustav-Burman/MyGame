#pragma once
#include <vector>
#include "card.h"
#include "player.h"
#include "monster.h"

enum class TurnPhase {
	PLAYER_PHASE,
    ENEMY_PHASE
};

class GameState {
	Player player;
	Monster monster;
	
	std::vector<Card> drawPile;
	std::vector<Card> hand;
	std::vector<Card> discardPile;

	TurnPhase phase;
	int turn;
};
#pragma once
#include "battle_state.h"
#include "../deck.h"


class GameState {
public:
	static GameState* getInstance();

	GameState(GameState&) = delete;
	GameState& operator=(GameState&) = delete;

	GameState(GameState&&) = delete;
	GameState& operator=(GameState&&) = delete;

	Player& getPlayer() { return m_player; }
	void    reset() { m_player = Player();  m_deck = buildStarterDeck(); }

	friend class BattleState;

private:
	GameState() = default;

	static GameState* instance;
	
	Player m_player{ Player() };
	Deck   m_deck  { buildStarterDeck() };
};
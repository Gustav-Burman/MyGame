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
	void    reset() { m_player = Player();  m_cardDefs = buildStarterDeck(); }

	friend class BattleState;
	friend Deck buildDrawPile();

private:
	GameState() = default;

	static GameState* instance;
	
	Player m_player             { Player() };
	std::vector<CardDef> m_cardDefs { buildStarterDeck() };
};
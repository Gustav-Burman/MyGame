#pragma once
#include <vector>
#include "../deck.h"
#include "../player.h"
#include "../monster/monster.h"
#include "../constants.h"
#include "game_state.h"

class BattleState {
public:
	enum Phase {
		PLAYER_PHASE,
		ENEMY_PHASE
	};
	// Constructor for making testing simpler
	BattleState(Deck deck)
		: m_drawPile{ std::move(deck) }
	{
	}
	BattleState()
	{ }

	void init();
	void draw(int nCards);
	void discardHand();
	int getDrawPileSize() const { return m_drawPile.size(); }
	int getHandSize() const { return m_hand.size(); }
	int getDiscardPileSize() const { return m_discardPile.size(); }

	void addMonster(Monster&& monster);
	Monster& getMonster() { return m_monster; }

	void damagePlayer(int amount);
	void blockPlayer (int baseAmount);

private:
	Monster m_monster{};
	
	Deck m_drawPile{};
	Deck m_hand{};
	Deck m_discardPile{};

	//TurnPhase m_phase;
	//int m_turn;
};

// Non-member functions
Deck buildDrawPile();

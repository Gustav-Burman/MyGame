#pragma once
#include <vector>
#include "deck.h"
#include "player.h"
#include "monster.h"
#include "constants.h"

class BattleState {
public:
	enum Phase {
		PLAYER_PHASE,
		ENEMY_PHASE
	};
	BattleState(Deck deck)
		: m_drawPile{ std::move(deck) }
	{
	}
	void init();
	void draw(int nCards);
	void discardHand();
	void addMonster(Monster monster);
	int getDrawPileSize() const { return m_drawPile.size(); }
	int getHandSize() const { return m_hand.size(); }
	int getDiscardPileSize() const { return m_discardPile.size(); }
	Monster& getMonster() { return m_monster; }

private:
	Player::Player m_player{ Player::Player() };
	Monster m_monster{};
	
	Deck m_drawPile{};
	Deck m_hand{};
	Deck m_discardPile{};

	//TurnPhase m_phase;
	//int m_turn;
};

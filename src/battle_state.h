#pragma once
#include <vector>
#include "deck.h"
#include "player.h"
#include "monster.h"

class BattleState {
public:
	enum Phase {
		PLAYER_PHASE,
		ENEMY_PHASE
	};
	BattleState(const Deck& deck)
		: m_drawPile{ deck }
	{
	}
	void init();
	void draw(int nCards);
	void discardHand();
	int getDrawPileSize() const { return m_drawPile.size(); }
	int getHandSize() const { return m_hand.size(); }
	int getDiscardPileSize() const { return m_discardPile.size(); };

private:
	Player::Player m_player{ Player::Player() };
	Monster::Monster m_monster{ "Goblin" };
	
	Deck m_drawPile{};
	Deck m_hand{};
	Deck m_discardPile{};

	//TurnPhase m_phase;
	//int m_turn;
};

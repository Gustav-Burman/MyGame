#pragma once
#include <vector>
#include "card.h"
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
		m_drawPile.shuffle();
		// Draw cards
	}

private:
	Player::Player m_player{ Player::Player() };
	Monster::Monster m_monster{ "Goblin" };
	
	Deck m_drawPile;
	/*std::vector<Card::Card> m_hand;
	std::vector<Card::Card> m_discardPile;

	TurnPhase m_phase;
	int m_turn;*/
};

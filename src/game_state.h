#pragma once
#include <vector>
#include "card.h"
#include "player.h"
#include "monster.h"

namespace GameState {
	enum class TurnPhase {
		PLAYER_PHASE,
		ENEMY_PHASE
	};

	class GameState {
	public:
		GameState()
		{
			
		}
	private:
	};

	class BattleState {
	public:
		BattleState(const Card::Deck& deck)
		{
			m_drawPile = deck;
			m_drawPile.shuffle();
			// Draw cards
		}

	private:
		Player::Player m_player{ Player::Player() };
		Monster::Monster m_monster{ "Goblin" };
	
		Card::Deck m_drawPile;
		/*std::vector<Card::Card> m_hand;
		std::vector<Card::Card> m_discardPile;

		TurnPhase m_phase;
		int m_turn;*/
	};
}
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
		void addToDeck(Card::Card card)
		{
			m_deck.emplace_back(card);
		}
	private:
		std::vector < Card::Card> m_deck{};
	};

	class BattleState {
	public:
		BattleState()
		{
			// Shuffle deck into draw pile
			// Draw cards
		}

	private:
		Player::Player m_player{ Player::Player() };
		Monster::Monster m_monster{ "Goblin" };
	
		/*std::vector<Card::Card> m_drawPile;
		std::vector<Card::Card> m_hand;
		std::vector<Card::Card> m_discardPile;

		TurnPhase m_phase;
		int m_turn;*/
	};
}
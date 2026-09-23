#include "battle_state.h"

void BattleState::init()
{
	GameState* gameState = GameState::getInstance();
	// Spawn monster
	m_drawPile = buildDrawPile();
	m_drawPile.shuffle();
}

void BattleState::draw(int nCards)
{
	for (size_t i = 0; i < nCards; i++)
	{
		if (m_hand.size() == MAX_HAND_SIZE) return;
		if (m_drawPile.isEmpty()) // Need to shuffle more cards in
		{
			if (m_discardPile.isEmpty()) return; // Can't shuffle more cards into draw pile

			m_drawPile = std::move(m_discardPile);
			m_discardPile.clear();
			m_drawPile.shuffle();
		}
		m_hand.addCard(std::move(m_drawPile.pop()));
	}
}

void BattleState::discardHand()
{
	for (auto& card : m_hand)
	{
		m_discardPile.addCard(std::move(card));
	}
	m_hand.clear();
}

void BattleState::addMonster(Monster&& monster)
{
	m_monster = std::move(monster);
}

void BattleState::damagePlayer(int baseAmount)
{
	GameState* gameState = GameState::getInstance();
	gameState->m_player.takeDamage(baseAmount);
}

void BattleState::blockPlayer(int baseAmount)
{
	GameState* gameState = GameState::getInstance();
	gameState->m_player.addBlock(baseAmount);
}


// Non-member functions
Deck buildDrawPile()
{
	GameState* gameState = GameState::getInstance();
	Deck drawPile{};
	for (auto def : gameState->m_cardDefs)
		drawPile.addCard(buildCard(def));
	return drawPile;
}
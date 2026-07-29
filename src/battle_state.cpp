#include "battle_state.h"

void BattleState::init()
{
	m_drawPile.shuffle();
}

void BattleState::draw(int nCards)
{
	//std::move(m_drawPile.begin(), m_drawPile.begin() + nCards, std::back_inserter(m_hand));
	for (size_t i = 0; i < nCards; i++)
	{
		if (m_drawPile.size() == 0)
		{
			continue;
		}
		Card card{ m_drawPile.pop() };
		m_hand.addCard(card);
	}
}

void BattleState::discardHand()
{
	//std::move(m_hand.begin(), m_hand.end(), std::back_inserter(m_discardPile));
	//m_hand.clear();
	for (auto& card : m_hand)
	{
		m_discardPile.addCard(std::move(card));
	}
	m_hand.clear();
}
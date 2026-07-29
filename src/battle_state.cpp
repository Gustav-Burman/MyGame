#include "battle_state.h"

void BattleState::init()
{
	m_drawPile.shuffle();
	draw(5);
}

void BattleState::draw(int nCards)
{
	Card card{ m_drawPile.pop() };
	m_hand.addCard(card);
	std::cout << "Card drawn\n";
}
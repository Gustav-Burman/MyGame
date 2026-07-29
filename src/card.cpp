#include "card.h"

bool Deck::shuffle()
{
	if (m_cards.empty()) return false;
	std::ranges::shuffle(m_cards, G_RNG_SEED);
	return true;
}
Card Deck::pop()
{
	Card card{ m_cards.back() };
	m_cards.pop_back();
	return card;
}
#include "deck.h"

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

Deck buildStarterDeck()
{
	Deck deck{};
	Card strike{ "strike", Card::Type::ATTACK, 1 };
	Card defend{ "defend", Card::Type::SKILL, 1 };
	Card bonk{ "bonk", Card::Type::ATTACK, 2 };
	for (int i = 0; i < 4; i++)
	{
		deck.addCard(strike);
		deck.addCard(defend);
	}
	deck.addCard(bonk);
	return deck;
}
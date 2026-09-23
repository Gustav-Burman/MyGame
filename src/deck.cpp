#include "deck.h"
#include "card/card_library.h"

// Member functions
bool Deck::shuffle()
{
	if (m_cards.empty()) return false;
	std::ranges::shuffle(m_cards, G_RNG_SEED);
	return true;
}
Card Deck::pop()
{
	Card card = std::move(m_cards.back());
	m_cards.pop_back();
	return card;
}


// Non-member functions
std::vector<CardDef> buildStarterDeck()
{
	const libMap& lib = CARD_LIBRARY;
	std::vector<CardDef> deck{};
	for (int i = 0; i < 4; i++)
	{
		CardDef strike{ lib.at("Strike") };
		CardDef defend{ lib.at("Defend") };
		deck.emplace_back(std::move(strike));
		deck.emplace_back(std::move(defend));
	}
	return deck;
}
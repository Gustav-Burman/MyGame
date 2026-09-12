#include "deck.h"
#include "card_library.h"

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
Deck buildStarterDeck()
{
	libMap lib = CardLibrary::getInstance()->getLib();
	Deck deck{};
	for (int i = 0; i < 4; i++)
	{
		Card strike{ lib["Strike"] };
		Card defend{ lib["Defend"] };
		deck.addCard(std::move(strike));
		deck.addCard(std::move(defend));
	}
	return deck;
}
#pragma once
#include "card.h"
#include <vector>
#include <algorithm>
#include <random>
#include "constants.h"

class Deck {
public:
	Deck()
	{
	}
	void addCard(Card card) { m_cards.emplace_back(card); }
	bool shuffle();
	Card pop();
	int size() { return m_cards.size(); }

private:
	std::vector<Card> m_cards{};
};

Deck buildStarterDeck();
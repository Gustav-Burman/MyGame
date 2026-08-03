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
	int size()	   const { return m_cards.size(); }
	auto begin()	     { return m_cards.begin(); }
	auto end()		     { return m_cards.end(); }
	auto begin()   const { return m_cards.begin(); }
	auto end()     const { return m_cards.end(); }
	void clear()         { m_cards.clear(); }
	bool isEmpty() const { return m_cards.empty(); }

private:
	std::vector<Card> m_cards{};
};

// Non-member functions
Deck buildStarterDeck();
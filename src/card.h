#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "constants.h"


class Card {
public:
	enum Type {
		ATTACK,
		SKILL
	};
	Card(std::string name, Type type, int cost)
		: m_name{ name }, m_type{ type }, m_cost{ cost }
	{
	}
private:
	std::string m_name;
	Type m_type;
	int m_cost;
};

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
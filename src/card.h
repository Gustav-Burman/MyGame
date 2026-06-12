#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <random>

namespace Card {
	enum class CardType {
		ATTACK,
		SKILL
	};

	class Card {
	public:
		Card(std::string name, CardType type, int cost)
			: m_name{name}, m_type{type}, m_cost{cost}
		{

		}
	private:
		std::string m_name;
		CardType m_type;
		int m_cost;
	};

	class Deck {
	public:
		Deck()
		{

		}

		void addCard(Card card) { m_cards.emplace_back(card); }

		bool shuffle()
		{
			if (m_cards.empty()) return false;
			auto rng = std::default_random_engine{};
			std::ranges::shuffle(m_cards, rng);
			return true;
		}

	private:
		std::vector<Card> m_cards{};
	};
}
#pragma once
#include <string>
#include "card_effects.h"
#include <memory>

class Card {
public:
	enum Type {
		ATTACK,
		SKILL
	};
	Card(std::string name, Type type, int cost)
		: m_name{ std::move(name) }, m_type{ type }, m_cost{ cost }
	{
	}

	Card(const Card&) = delete;
	Card& operator=(const Card&) = delete;

	Card(Card&&) noexcept = default;
	Card& operator=(Card&& card) noexcept = default;

	// Public member variables
	std::unique_ptr<CardEffect> m_effect{};

private:
	std::string m_name;
	Type m_type;
	int m_cost;
	std::string description{ "" };
};
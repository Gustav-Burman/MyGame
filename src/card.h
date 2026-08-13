#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "card_effects.h"
#include "utils.h"

class Card {
public:
	enum Type {
		ATTACK,
		SKILL,
		POWER
	};
	enum Rarity {
		COMMON,
		UNCOMMON,
		RARE
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
	std::string m_description{ "" };
};


class CardDefinition {
public:
	enum Effect {
		DAMAGE,
		BLOCK,
		DRAW
	};
	CardDefinition() {}
	CardDefinition(std::string name, Card::Type type, int cost, std::unordered_map<Effect, int, EnumHash> effects, std::string description, Card::Rarity rarity)
		: m_name{ std::move(name) }, m_type{ type }, m_cost{ cost }, m_effects{ effects },
		m_description { std::move(description) }, m_rarity{ rarity }
	{
	}
	std::string getName() const { return m_name; }
private:
	std::string m_name;
	Card::Type m_type;
	std::unordered_map<Effect, int, EnumHash> m_effects;
	int m_cost;
	std::string m_description{ "" };
	Card::Rarity m_rarity;
};

// Card builder function
namespace CardLibrary {
	std::unordered_map<std::string, CardDefinition> buildCardLibrary();
}
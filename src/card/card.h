#pragma once
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include "card_effects.h"
#include "../utils.h"

struct CardDef {
public:
	enum Effect {
		DAMAGE,
		BLOCK,
		DRAW
	};
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

	std::string name{ "" };
	Type        type{ ATTACK };
	int         cost{ 0 };
	Rarity      rarity{ COMMON };
	std::string description{ "" };
	std::unordered_map<Effect, int, EnumHash> effects{};
};

class Card {
public:
	Card(std::string name, CardDef::Type type, int cost) // Remove
		: m_name{ std::move(name) }, m_type{ type }, m_cost{ cost }
	{
	}

	Card(CardDef def)
		: m_name{ def.name }, m_type{ def.type }, m_cost{ def.cost }, m_description{ def.description }, m_rarity{ def.rarity }
	{
	}

	Card(const Card&) = delete;
	Card& operator=(const Card&) = delete;

	Card(Card&&) noexcept = default;
	Card& operator=(Card&& card) noexcept = default;

	void addEffect(std::unique_ptr<CardEffect> effect) { m_effects.push_back(std::move(effect)); }
	void execute(BattleState& battle) { for (auto& effect : m_effects) effect->execute(battle); }

private:
	std::string                              m_name        { "" };
	CardDef::Type                            m_type        { CardDef::ATTACK };
	int                                      m_cost        { 0 };
	std::string                              m_description { "" };
	CardDef::Rarity                          m_rarity      { CardDef::COMMON };
	std::vector<std::unique_ptr<CardEffect>> m_effects     {};
};


// Non-member functions
Card buildCard(CardDef def);
#include "card.h"

namespace CardLibrary
{
	std::unordered_map<CardDefinition::Effect, int, EnumHash> strikeEffects = {
		{CardDefinition::Effect::DAMAGE, 6}
	};
	CardDefinition strike
	{
		"Strike",
		Card::Type::ATTACK,
		1, // Cost
		strikeEffects,
		"Deal 6 damage",
		Card::Rarity::COMMON
	};
	std::unordered_map<CardDefinition::Effect, int, EnumHash> defendEffects = {
		{CardDefinition::Effect::BLOCK, 5}
	};
	CardDefinition defend
	{
		"Defend",
		Card::Type::SKILL,
		1, // Cost
		defendEffects,
		"Gain 5 block",
		Card::Rarity::COMMON
	};

	std::unordered_map<std::string, CardDefinition> buildCardLibrary()
	{
		std::unordered_map<std::string, CardDefinition> cardLibrary;
		cardLibrary["Strike"] = strike;
		cardLibrary["Defend"] = defend;
		return cardLibrary;
	}
}
#include "card.h"

namespace CardLibrary
{
	std::unordered_map<std::string, CardDefinition> buildCardLibrary()
	{
		std::unordered_map<CardDefinition::Effect, int, EnumHash> strikeEffects = {
			{CardDefinition::Effect::DAMAGE, 6}
		};
		CardDefinition strike
		{
			.name = "Strike",
			.type = CardDefinition::Type::ATTACK,
			.cost = 1,
			.rarity = CardDefinition::Rarity::COMMON,
			.description = "Deal 6 damage",
			.effects = strikeEffects
		};

		std::unordered_map<CardDefinition::Effect, int, EnumHash> defendEffects = {
			{CardDefinition::Effect::BLOCK, 5}
		};
		CardDefinition defend
		{
			.name = "Defend",
			.type = CardDefinition::Type::SKILL,
			.cost = 1,
			.rarity = CardDefinition::Rarity::COMMON,
			.description = "Gain 5 block",
			.effects = defendEffects
		};

		std::unordered_map<std::string, CardDefinition> cardLibrary;
		cardLibrary["Strike"] = strike;
		cardLibrary["Defend"] = defend;
		return cardLibrary;
	}
}
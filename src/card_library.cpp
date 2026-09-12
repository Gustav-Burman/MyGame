#include "card_library.h"

CardLibrary* CardLibrary::instance = nullptr;

CardLibrary* CardLibrary::getInstance()
{
	if (instance == nullptr)
	{
		instance = new CardLibrary( buildCardLibrary() );
	}
	return instance;
}

libMap buildCardLibrary()
{
	effectMap strikeEffects = {
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

	effectMap defendEffects = {
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

	libMap cardLibrary;
	cardLibrary["Strike"] = strike;
	cardLibrary["Defend"] = defend;
	return cardLibrary;
}

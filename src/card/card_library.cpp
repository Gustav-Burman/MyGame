#include "card_library.h"

extern const libMap CARD_LIBRARY = buildCardLibrary();

libMap buildCardLibrary()
{
	effectMap strikeEffects = {
		{CardDef::Effect::DAMAGE, 6}
	};
	CardDef strike
	{
		.name = "Strike",
		.type = CardDef::Type::ATTACK,
		.cost = 1,
		.rarity = CardDef::Rarity::COMMON,
		.description = "Deal 6 damage",
		.effects = strikeEffects
	};

	effectMap defendEffects = {
		{CardDef::Effect::BLOCK, 5}
	};
	CardDef defend
	{
		.name = "Defend",
		.type = CardDef::Type::SKILL,
		.cost = 1,
		.rarity = CardDef::Rarity::COMMON,
		.description = "Gain 5 block",
		.effects = defendEffects
	};

	libMap cardLibrary;
	cardLibrary["Strike"] = strike;
	cardLibrary["Defend"] = defend;
	return cardLibrary;
}
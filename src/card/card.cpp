#include "card.h"

Card buildCard(CardDef def)
{
	Card card{ def };
	for (const auto& [effect, value] : def.effects)
	{
		switch (effect)
		{
		case CardDef::DAMAGE:
			card.addEffect(std::make_unique<DamageEffect>(value));
			break;

		case CardDef::BLOCK:
			card.addEffect(std::make_unique<BlockEffect>(value));
			break;

		default:
			break;
		}
	}

	return card;
}
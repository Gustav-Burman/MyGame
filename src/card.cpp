#include "card.h"

Card buildCard(CardDefinition def)
{
	Card card{ def };
	for (const auto& effect, value] : def.effects)
	{
		switch (effect)
		{
		case CardDefinition::DAMAGE:
			card.addEffect(std::make_unique<DamageEffect>(effect));
		}
	}
}
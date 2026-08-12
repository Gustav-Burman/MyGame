#include <gtest/gtest.h>
#include "battle_state.h"

TEST(cardsTest, MonsterTakingDamageOnDamageEffect)
{
	Card strike{ "Strike", Card::ATTACK, 1 };
	//strike.effect = std::make_unique<DamageEffect>(5);
	Deck deck{};
	BattleState battle{ std::move(deck) };
	Monster goblin{ "Goblin", Monster::Type::BASIC, 25 };
	battle.addMonster( std::move(goblin) );
	EXPECT_EQ(battle.getMonster().getHealth(), 25);
git	//strike.effect->execute(battle);
	//EXPECT_EQ(battle.getMonster().getHealth(), 17);
}
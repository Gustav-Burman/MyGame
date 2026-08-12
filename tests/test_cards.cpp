#include <gtest/gtest.h>
#include "battle_state.h"

TEST(cardsTest, MonsterTakingDamageOnDamageEffect)
{
	int damage{ 5 };
	Card strike{ "Strike", Card::ATTACK, 1 };
	strike.m_effect = std::make_unique<DamageEffect>(damage);
	Deck deck{};
	BattleState battle{ std::move(deck) };
	int health{ 25 };
	Monster goblin{ "Goblin", Monster::Type::BASIC, health };
	battle.addMonster( std::move(goblin) );

	EXPECT_EQ(battle.getMonster().getHealth(), health);
	EXPECT_EQ(battle.getMonster().getName(), "Goblin");
	EXPECT_EQ(battle.getMonster().getMaxHealth(), health);
	EXPECT_EQ(battle.getMonster().getType(), Monster::Type::BASIC);
	
	strike.m_effect->execute(battle);
	EXPECT_EQ(battle.getMonster().getHealth(), health - damage);
}
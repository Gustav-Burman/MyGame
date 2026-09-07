#include <gtest/gtest.h>
#include "battle_state.h"


TEST(cardsTest, buildCardLibrary)
{
	std::unordered_map<std::string, CardDefinition> library = CardLibrary::buildCardLibrary();
	EXPECT_EQ(library["Strike"].name, "Strike");
	EXPECT_EQ(library["Defend"].name, "Defend");
}

TEST(cardsTest, MonsterTakingDamageOnDamageEffect)
{
	// Create strike
	int damage{ 6 };
	Card strike{ "Strike", CardDefinition::ATTACK, 1 };
	strike.addEffect( std::make_unique<DamageEffect>(damage) );

	// Init deck
	Deck deck{};
	BattleState battle{ std::move(deck) };
	int health{ 25 };
	Monster goblin{ "Goblin", Monster::Type::BASIC, health };
	battle.addMonster( std::move(goblin) );

	EXPECT_EQ(battle.getMonster().getHealth(), health);
	EXPECT_EQ(battle.getMonster().getName(), "Goblin");
	EXPECT_EQ(battle.getMonster().getMaxHealth(), health);
	EXPECT_EQ(battle.getMonster().getType(), Monster::Type::BASIC);
	
	strike.execute(battle);
	EXPECT_EQ(battle.getMonster().getHealth(), health - damage);
}
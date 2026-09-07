#include <gtest/gtest.h>
#include "battle_state.h"


std::unordered_map<std::string, CardDefinition> CARD_LIBRARY = CardLibrary::buildCardLibrary();

TEST(cardsTest, cardLibrary)
{
	EXPECT_EQ(CARD_LIBRARY["Strike"].name, "Strike");
	EXPECT_EQ(CARD_LIBRARY["Defend"].name, "Defend");
}

TEST(cardsTest, MonsterTakingDamageOnDamageEffect)
{
	Card strike{ buildCard(CARD_LIBRARY["Strike"]) };

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
	EXPECT_EQ(battle.getMonster().getHealth(), health - 6);
}
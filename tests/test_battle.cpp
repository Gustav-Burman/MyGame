#include <gtest/gtest.h>
#include "battle_state.h"
#include "card_library.h"
#include "monsters/goblin.h"

libMap CARD_LIBRARY = CardLibrary::getInstance()->getLib();

TEST(battleTest, cardLibrary)
{
	EXPECT_EQ(CARD_LIBRARY["Strike"].name, "Strike");
	EXPECT_EQ(CARD_LIBRARY["Defend"].name, "Defend");
}

TEST(battleTest, MonsterTakingDamageOnDamageEffect)
{
	Card strike{ buildCard(CARD_LIBRARY["Strike"]) };

	// Init deck
	Deck deck{};
	BattleState battle{ std::move(deck) };
	int health{ 25 };
	Monster goblin{ "Goblin", Monster::Type::BASIC, health };
	battle.addMonster( goblin );

	EXPECT_EQ(battle.getMonster().getHealth(), health);
	EXPECT_EQ(battle.getMonster().getName(), "Goblin");
	EXPECT_EQ(battle.getMonster().getMaxHealth(), health);
	EXPECT_EQ(battle.getMonster().getType(), Monster::Type::BASIC);

	strike.execute(battle);
	EXPECT_EQ(battle.getMonster().getHealth(), health - 6);
}

TEST(battleTest, PlayerTakingDamageOnGoblinAttack)
{
	Player player{};
	Goblin goblin{};
	BattleState battle{ std::move(Deck{}) };
	battle.addMonster(goblin);
	battle.addPlayer(player);

	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth());

	goblin.action(battle);

	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth() - 5);
}
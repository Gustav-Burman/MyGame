#include <gtest/gtest.h>
#include "battle_state.h"
#include "card/card_library.h"
#include "monster/goblin.h"
#include "monster/monster_library.h"

//libMap CARD_LIBRARY = CardLibrary::getInstance()->getLib();

TEST(battleTest, cardLibrary)
{
	EXPECT_EQ(CARD_LIBRARY.at("Strike").name, "Strike");
	EXPECT_EQ(CARD_LIBRARY.at("Defend").name, "Defend");
}

TEST(battleTest, MonsterTakingDamageOnDamageEffect)
{
	Card strike{ buildCard(CARD_LIBRARY.at("Strike")) };

	// Init deck
	Deck deck{};
	BattleState battle{ std::move(deck) };
	MonsterDef goblinDef = MONSTER_LIBRARY.at("Goblin");
	Monster goblin{ buildMonster(goblinDef) };
	battle.addMonster( std::move(goblin) );

	EXPECT_EQ(battle.getMonster().getHealth(), goblinDef.maxHealth);
	strike.execute(battle);
	EXPECT_EQ(battle.getMonster().getHealth(), goblinDef.maxHealth - 6);
}

TEST(battleTest, PlayerTakingDamageOnGoblinAttack)
{
	Player player{};
	BattleState battle{ std::move(Deck{}) };
	MonsterDef goblinDef = MONSTER_LIBRARY.at("Goblin");
	Monster goblin{ buildMonster(goblinDef) };
	battle.addMonster(std::move(goblin));
	battle.addPlayer(player);

	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth());
	battle.getMonster().execute(battle);
	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth() - goblinDef.actions.at(0));
}

//TEST(battleTest)
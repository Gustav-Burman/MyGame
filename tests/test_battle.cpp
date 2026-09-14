#include <gtest/gtest.h>
#include "test_utils.h"
#include "battle_state.h"
#include "card/card_library.h"
#include "card/card.h"
#include "monster/monster_library.h"

TEST(battleTest, MonsterTakingDamageOnDamageEffect)
{
	CardDef strikeDef = CARD_LIBRARY.at("Strike");
	Card strike{ buildCard(strikeDef) };

	BattleState battle = TestUtils::initBattleGoblin();

	EXPECT_EQ(battle.getMonster().getHealth(), MONSTER_LIBRARY.at("Goblin").maxHealth);
	strike.execute(battle);
	EXPECT_EQ(battle.getMonster().getHealth(), MONSTER_LIBRARY.at("Goblin").maxHealth - strikeDef.effects.at(CardDef::Effect::DAMAGE));
}

TEST(battleTest, PlayerTakingDamageOnGoblinAttack)
{
	BattleState battle = TestUtils::initBattleGoblin();

	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth());
	battle.getMonster().execute(battle);
	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth() - MONSTER_LIBRARY.at("Goblin").actions.at(0));
}

TEST(battleTest, PlayerBlockingFullDamageFromMonster)
{
	BattleState battle = TestUtils::initBattleGoblin();
	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth());

	Card defend          = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	for (int i = 0; i < 3; i++)
		defend.execute(battle);

	EXPECT_EQ(battle.getPlayer().getBlock(), blockFromDefend * 3);

	battle.getMonster().execute(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at("Goblin").actions.at(0);

	EXPECT_EQ(battle.getPlayer().getBlock(),  blockFromDefend * 3 - damageFromGoblin);
	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth());
}

TEST(battleTest, PlayerBlockingExactDamageFromMonster)
{
	BattleState battle = TestUtils::initBattleGoblin();
	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth());

	Card defend = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	for (int i = 0; i < 2; i++)
		defend.execute(battle);

	EXPECT_EQ(battle.getPlayer().getBlock(), blockFromDefend * 2);

	battle.getMonster().execute(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at("Goblin").actions.at(0);

	EXPECT_EQ(battle.getPlayer().getBlock(), 0);
	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth());
}

TEST(battleTest, PlayerBlockingPartOfDamageFromMonster)
{
	BattleState battle = TestUtils::initBattleGoblin();
	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth());

	Card defend = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	defend.execute(battle);

	EXPECT_EQ(battle.getPlayer().getBlock(), blockFromDefend);

	battle.getMonster().execute(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at("Goblin").actions.at(0);

	EXPECT_EQ(battle.getPlayer().getBlock(), 0);
	EXPECT_EQ(battle.getPlayer().getHealth(), battle.getPlayer().getMaxHealth() - (damageFromGoblin - blockFromDefend));
}
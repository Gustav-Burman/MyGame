#include <gtest/gtest.h>
#include "test_utils.h"
#include "game_state/battle_state.h"
#include "card/card_library.h"
#include "card/card.h"
#include "monster/monster_library.h"
#include "game_state/game_state.h"

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
	BattleState battle    = TestUtils::initBattleGoblin();
	GameState*  gameState = GameState::getInstance();

	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());
	battle.getMonster().execute(battle);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth() - MONSTER_LIBRARY.at("Goblin").actions.at(0));

	gameState->reset();
}

TEST(battleTest, PlayerBlockingFullDamageFromMonster)
{
	BattleState battle = TestUtils::initBattleGoblin();
	GameState* gameState = GameState::getInstance();
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	Card defend          = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	for (int i = 0; i < 3; i++)
		defend.execute(battle);

	EXPECT_EQ(gameState->getPlayer().getBlock(), blockFromDefend * 3);

	battle.getMonster().execute(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at("Goblin").actions.at(0);

	EXPECT_EQ(gameState->getPlayer().getBlock(),  blockFromDefend * 3 - damageFromGoblin);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	gameState->reset();
}

TEST(battleTest, PlayerBlockingExactDamageFromMonster)
{
	BattleState battle = TestUtils::initBattleGoblin();
	GameState* gameState = GameState::getInstance();
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	Card defend = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	for (int i = 0; i < 2; i++)
		defend.execute(battle);

	EXPECT_EQ(gameState->getPlayer().getBlock(), blockFromDefend * 2);

	battle.getMonster().execute(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at("Goblin").actions.at(0);

	EXPECT_EQ(gameState->getPlayer().getBlock(), 0);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	gameState->reset();
}

TEST(battleTest, PlayerBlockingPartOfDamageFromMonster)
{
	BattleState battle = TestUtils::initBattleGoblin();
	GameState* gameState = GameState::getInstance();
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	Card defend = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	defend.execute(battle);

	EXPECT_EQ(gameState->getPlayer().getBlock(), blockFromDefend);

	battle.getMonster().execute(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at("Goblin").actions.at(0);

	EXPECT_EQ(gameState->getPlayer().getBlock(), 0);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth() - (damageFromGoblin - blockFromDefend));

	gameState->reset();
}
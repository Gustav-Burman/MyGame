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

	std::string monsterName{ "Goblin" };
	BattleState battle = TestUtils::initBattleWithMonster(monsterName);

	EXPECT_EQ(battle.getMonster().getHealth(), MONSTER_LIBRARY.at(monsterName).maxHealth);
	strike.execute(battle);
	EXPECT_EQ(battle.getMonster().getHealth(), MONSTER_LIBRARY.at(monsterName).maxHealth - strikeDef.effects.at(CardDef::Effect::DAMAGE));
}

TEST(battleTest, PlayerTakingDamageOnGoblinAttack)
{
	std::string monsterName{ "Goblin" };
	BattleState battle    = TestUtils::initBattleWithMonster(monsterName);
	GameState*  gameState = GameState::getInstance();

	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());
	battle.getMonster().takeTurn(battle);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth() - MONSTER_LIBRARY.at(monsterName).actions[0].value);
	
	gameState->reset();
}

TEST(battleTest, PlayerBlockingFullDamageFromMonster)
{
	std::string monsterName{ "Goblin" };
	BattleState battle = TestUtils::initBattleWithMonster(monsterName);
	GameState* gameState = GameState::getInstance();
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	Card defend          = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	for (int i = 0; i < 3; i++)
		defend.execute(battle);

	EXPECT_EQ(gameState->getPlayer().getBlock(), blockFromDefend * 3);

	battle.getMonster().takeTurn(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at(monsterName).actions[0].value;

	EXPECT_EQ(gameState->getPlayer().getBlock(),  blockFromDefend * 3 - damageFromGoblin);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	gameState->reset();
}

TEST(battleTest, PlayerBlockingExactDamageFromMonster)
{
	std::string monsterName{ "Goblin" };
	BattleState battle = TestUtils::initBattleWithMonster(monsterName);
	GameState* gameState = GameState::getInstance();
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	Card defend = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	for (int i = 0; i < 2; i++)
		defend.execute(battle);

	EXPECT_EQ(gameState->getPlayer().getBlock(), blockFromDefend * 2);

	battle.getMonster().takeTurn(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at(monsterName).actions[0].value;

	EXPECT_EQ(gameState->getPlayer().getBlock(), 0);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	gameState->reset();
}

TEST(battleTest, PlayerBlockingPartOfDamageFromMonster)
{
	std::string monsterName{ "Goblin" };
	BattleState battle = TestUtils::initBattleWithMonster(monsterName);
	GameState* gameState = GameState::getInstance();
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());

	Card defend = buildCard(CARD_LIBRARY.at("Defend"));
	int  blockFromDefend = CARD_LIBRARY.at("Defend").effects.at(CardDef::BLOCK);
	defend.execute(battle);

	EXPECT_EQ(gameState->getPlayer().getBlock(), blockFromDefend);

	battle.getMonster().takeTurn(battle);
	int damageFromGoblin = MONSTER_LIBRARY.at(monsterName).actions[0].value;

	EXPECT_EQ(gameState->getPlayer().getBlock(), 0);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth() - (damageFromGoblin - blockFromDefend));

	gameState->reset();
}
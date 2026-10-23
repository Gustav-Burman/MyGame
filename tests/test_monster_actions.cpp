#include <gtest/gtest.h>
#include "deck.h"
#include "card/card_library.h"
#include "test_utils.h"

TEST(monsterActionsTest, AttackAction)
{
	int damage = 10;
	ActionEntry monsterAction = {
		MonsterActionE::ATTACK, damage
	};
	MonsterDef monsterDef = {
		.name = "Test",
		.type = MonsterDef::Type::BASIC,
		.maxHealth = 30,
		.actions = ActionEntryVec{ monsterAction },
		.strategy = MonsterDef::Strategy::SingleAction
	};
	Monster monster{ buildMonster(monsterDef) };

	BattleState battle = TestUtils::initBattleNoEnemy();
	GameState * gameState = GameState::getInstance();
	battle.addMonster(std::move(monster));

	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth());
	battle.getMonster().takeTurn(battle);
	EXPECT_EQ(gameState->getPlayer().getHealth(), gameState->getPlayer().getMaxHealth() - damage);
}
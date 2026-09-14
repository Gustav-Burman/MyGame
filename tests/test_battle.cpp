#include <gtest/gtest.h>
#include "test_utils.h"
#include "battle_state.h"
#include "card/card_library.h"
#include "card/card.h"
#include "monster/monster_library.h"

TEST(battleTest, cardLibrary)
{
	EXPECT_EQ(CARD_LIBRARY.at("Strike").name, "Strike");
	EXPECT_EQ(CARD_LIBRARY.at("Defend").name, "Defend");
}

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
//
//TEST(battleTest, PlayerBlockingFullDamageFromMonster)
//{
//
//}
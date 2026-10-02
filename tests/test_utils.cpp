#include "test_utils.h"

namespace TestUtils {
	BattleState initBattleNoEnemy()
	{
		Deck deck{};
		BattleState battle{ std::move(deck) };
		return battle;
	}

	BattleState initBattleWithMonster(std::string& monsterName)
	{
		Player player{};
		BattleState battle{ std::move(Deck{}) };
		MonsterDef monsterDef = MONSTER_LIBRARY.at(monsterName);
		Monster monster{ buildMonster(monsterDef) };
		battle.addMonster(std::move(monster));
		return battle;
	}

	BattleState initBattleWithStarterDeckAndDrawCards(const int nCardsToDraw)
	{
		BattleState battle{};
		battle.init();
		battle.draw(nCardsToDraw);
		return battle;
	}

	void addStrikes(Deck& deck, const int nCardsToAdd)
	{
		for (int i = 0; i < nCardsToAdd; i++)
		{
			Card strike{ buildCard(CARD_LIBRARY.at("Strike")) };
			deck.addCard(std::move(strike));
		}
	}
}
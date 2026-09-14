#include "test_utils.h"

namespace TestUtils {
	BattleState initBattleNoEnemy()
	{
		Deck deck{};
		BattleState battle{ std::move(deck) };
		battle.addPlayer(Player{});
		return battle;
	}

	BattleState initBattleGoblin()
	{
		Player player{};
		BattleState battle{ std::move(Deck{}) };
		MonsterDef goblinDef = MONSTER_LIBRARY.at("Goblin");
		Monster goblin{ buildMonster(goblinDef) };
		battle.addMonster(std::move(goblin));
		battle.addPlayer(player);
		return battle;
	}

	BattleState initBattleWithStarterDeckAndDrawCards(const int nCardsToDraw)
	{
		Deck deck{ buildStarterDeck() };
		BattleState battle{ std::move(deck) };
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
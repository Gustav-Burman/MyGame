#include "test_utils.h"

namespace TestUtils {
	BattleState initBattleEmpty()
	{
		Deck deck{};
		BattleState battle{ std::move(deck) };
		//Player player{};
		battle.addPlayer(Player{});
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
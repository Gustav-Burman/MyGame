#include "test_utils.h"

namespace TestUtils {
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
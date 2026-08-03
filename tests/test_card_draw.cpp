#include <gtest/gtest.h>
#include "battle_state.h"
#include "deck.h"
#include "constants.h"

BattleState initBattleWithStarterDeckAndDrawCards(const int nCardsToDraw)
{
	const Deck deck{ buildStarterDeck() };
	BattleState battle{ deck };
	battle.init();
	battle.draw(nCardsToDraw);
	return battle;
}

void addCards(Deck& deck, const int nCardsToAdd)
{
	Card strike{ "strike", Card::Type::ATTACK, 1 };
	for (int i = 0; i < nCardsToAdd; i++)
	{
		deck.addCard(strike);
	}
}

TEST(CardDrawTest, InitDrawPile)
{
	const Deck deck{ buildStarterDeck() };
	int deckSize = deck.size();
	BattleState battle{ deck };
	battle.init();
	EXPECT_EQ(battle.getDrawPileSize(), deckSize);
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(CardDrawTest, InitDrawPileWithEmptyDeck)
{
	const Deck deck{};
	BattleState battle{ deck };
	battle.init();
	EXPECT_EQ(battle.getDrawPileSize(), 0);
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(CardDrawTest, DrawFiveCards)
{
	int nCardsToDraw{ 5 };
	const Deck deck{ buildStarterDeck() };
	int deckSize = deck.size();
	BattleState battle{ deck };
	battle.init();
	battle.draw(nCardsToDraw);
	EXPECT_EQ(battle.getDrawPileSize(), deckSize - nCardsToDraw);
	EXPECT_EQ(battle.getHandSize(), nCardsToDraw);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(CardDrawTest, TryToDrawWhenNoCardsAvailable)
{
	int nCardsToDraw{ 1 };
	const Deck deck{};
	BattleState battle{ deck };
	battle.init();
	battle.draw(nCardsToDraw);
	EXPECT_EQ(battle.getDrawPileSize(), 0);
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(CardDrawTest, DiscardHand)
{
	int nCardsToDraw{ 5 };
	BattleState battle{ initBattleWithStarterDeckAndDrawCards(nCardsToDraw) };
	EXPECT_EQ(battle.getHandSize(), nCardsToDraw);
	battle.discardHand();
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), nCardsToDraw);
}

TEST(CardDrawTest, ShuffleDrawpile)
{
	int nCardsInDeck{ 6 };
	int nCardsToDraw{ 5 };
	Deck deck{};
	addCards(deck, nCardsInDeck);

	BattleState battle{ deck };
	battle.init();
	battle.draw(nCardsToDraw);
	battle.discardHand();
	EXPECT_EQ(battle.getDrawPileSize(), nCardsInDeck - nCardsToDraw);
	EXPECT_EQ(battle.getDiscardPileSize(), nCardsToDraw);

	battle.draw(nCardsToDraw); // Will shuffle discard pile into drawpile
	EXPECT_EQ(battle.getDrawPileSize(), nCardsInDeck - nCardsToDraw);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
	EXPECT_EQ(battle.getHandSize(), nCardsToDraw);
}

TEST(CardDrawTest, DrawMoreThanMaxHandSize)
{
	int nCardsInDeck{ 11 };
	int nCardsToDraw{ 11 };
	Card strike{ "strike", Card::Type::ATTACK, 1 };
	Deck deck{};
	addCards(deck, nCardsInDeck);

	BattleState battle{ deck };
	battle.init();
	battle.draw(nCardsToDraw);
	EXPECT_EQ(battle.getDrawPileSize(), nCardsInDeck - MAX_HAND_SIZE);
	EXPECT_EQ(battle.getHandSize(), MAX_HAND_SIZE);
}
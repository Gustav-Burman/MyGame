#include <gtest/gtest.h>
#include "battle_state.h"
#include "deck.h"

BattleState initBattleWithStarterDeckAndDrawCards(const int nCardsToDraw)
{
	const Deck deck{ buildStarterDeck() };
	BattleState battle{ deck };
	battle.init();
	battle.draw(nCardsToDraw);
	return battle;
}

TEST(BattleTest, InitDrawPile)
{
	const Deck deck{ buildStarterDeck() };
	int deckSize = deck.size();
	BattleState battle{ deck };
	battle.init();
	EXPECT_EQ(battle.getDrawPileSize(), deckSize);
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(BattleTest, InitDrawPileWithEmptyDeck)
{
	const Deck deck{};
	BattleState battle{ deck };
	battle.init();
	EXPECT_EQ(battle.getDrawPileSize(), 0);
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(BattleTest, DrawFiveCards)
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

TEST(BattleTest, TryToDrawWhenNoCardsAvailable)
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

TEST(BattleTest, DiscardHand)
{
	int nCardsToDraw{ 5 };
	BattleState battle{ initBattleWithStarterDeckAndDrawCards(nCardsToDraw) };
	EXPECT_EQ(battle.getHandSize(), nCardsToDraw);
	battle.discardHand();
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), nCardsToDraw);
}
#include <gtest/gtest.h>
#include "test_utils.cpp"
#include "game_state/game_state.h"


TEST(CardDrawTest, InitDrawPile)
{
	BattleState battle{};
	battle.init();
	int deckSize = battle.getDrawPileSize();
	EXPECT_EQ(battle.getDrawPileSize(), deckSize);
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(CardDrawTest, DrawFiveCards)
{
	int nCardsToDraw{ 5 };
	BattleState battle{};
	battle.init();
	int deckSize = battle.getDrawPileSize();

	battle.draw(nCardsToDraw);
	EXPECT_EQ(battle.getDrawPileSize(), deckSize - nCardsToDraw);
	EXPECT_EQ(battle.getHandSize(), nCardsToDraw);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(CardDrawTest, TryToDrawWhenNoCardsAvailable)
{
	int nCardsToDraw{ 1 };
	BattleState battle{};

	// Battle not initialized. No cards in draw pile
	battle.draw(nCardsToDraw);
	EXPECT_EQ(battle.getDrawPileSize(), 0);
	EXPECT_EQ(battle.getHandSize(), 0);
	EXPECT_EQ(battle.getDiscardPileSize(), 0);
}

TEST(CardDrawTest, DiscardHand)
{
	int nCardsToDraw{ 5 };
	BattleState battle{ TestUtils::initBattleWithStarterDeckAndDrawCards(nCardsToDraw) };
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
	TestUtils::addStrikes(deck, nCardsInDeck);

	BattleState battle{ std::move(deck) };

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
	Deck deck{};
	TestUtils::addStrikes(deck, nCardsInDeck);

	BattleState battle{ std::move(deck) };
	battle.draw(nCardsToDraw);
	EXPECT_EQ(battle.getDrawPileSize(), nCardsInDeck - MAX_HAND_SIZE);
	EXPECT_EQ(battle.getHandSize(), MAX_HAND_SIZE);
}
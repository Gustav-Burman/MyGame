#include <gtest/gtest.h>
#include "deck.h"

TEST(DeckTest, AddCardToDeck) {
	auto deck{ Deck() };
	deck.addCard(Card{ "Name", Card::ATTACK, 2 });
	EXPECT_EQ(deck.size(), 1);
}

TEST(DeckTest, StarterDeckHasCorrectSize) {
	auto deck{ buildStarterDeck() };
	EXPECT_EQ(deck.size(), 9);
}
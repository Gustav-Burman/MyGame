#include <gtest/gtest.h>
#include "card.h"

TEST(DeckTest, AddCardToDeck) {
	auto deck{ Deck() };
	deck.addCard(Card{ "Name", Card::ATTACK, 2 });
	EXPECT_EQ(deck.size(), 1);
}
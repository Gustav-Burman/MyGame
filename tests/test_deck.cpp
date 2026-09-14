#include <gtest/gtest.h>
#include "deck.h"
#include "card/card_library.h"
#include "test_utils.h"

TEST(DeckTest, AddCardToDeck) {
	auto deck{ Deck() };
	deck.addCard(Card{ "Name", CardDef::ATTACK, 2 });
	EXPECT_EQ(deck.size(), 1);
}

TEST(DeckTest, StarterDeckHasCorrectSize) {
	auto deck{ buildStarterDeck() };
	EXPECT_EQ(deck.size(), 8);
}

TEST(DeckTest, defendBlocksCorrectAmount) {
	CardDef defendDef{ CARD_LIBRARY.at("Defend") };
	Card defend{ buildCard(defendDef) };
	BattleState battle = TestUtils::initBattleNoEnemy();

	EXPECT_EQ(battle.getPlayer().getBlock(), 0);
	defend.execute(battle);
	EXPECT_EQ(battle.getPlayer().getBlock(), defendDef.effects.at(CardDef::Effect::BLOCK));
}
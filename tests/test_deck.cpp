#include <gtest/gtest.h>
#include "deck.h"
#include "card/card_library.h"
#include "test_utils.h"

TEST(battleTest, cardLibrary)
{
	EXPECT_EQ(CARD_LIBRARY.at("Strike").name, "Strike");
	EXPECT_EQ(CARD_LIBRARY.at("Defend").name, "Defend");
}

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
	GameState* gameState = GameState::getInstance();
	CardDef defendDef{ CARD_LIBRARY.at("Defend") };
	Card defend{ buildCard(defendDef) };
	BattleState battle = TestUtils::initBattleNoEnemy();

	EXPECT_EQ(gameState->getPlayer().getBlock(), 0);
	defend.execute(battle);
	EXPECT_EQ(gameState->getPlayer().getBlock(), defendDef.effects.at(CardDef::Effect::BLOCK));

	gameState->reset();
}
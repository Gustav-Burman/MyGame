#pragma once
#include "battle_state.h"
#include "deck.h"
#include "constants.h"
#include "card/card_library.h"

namespace TestUtils {
	BattleState initBattleWithStarterDeckAndDrawCards(const int nCardsToDraw);
	void addStrikes(Deck& deck, const int nCardsToAdd);
}
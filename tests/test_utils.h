#pragma once
#include "game_state/battle_state.h"
#include "deck.h"
#include "constants.h"
#include "card/card_library.h"
#include "monster/monster_library.h"

namespace TestUtils {
	BattleState initBattleNoEnemy();
	BattleState initBattleGoblin();
	BattleState initBattleWithStarterDeckAndDrawCards(const int nCardsToDraw);
	void addStrikes(Deck& deck, const int nCardsToAdd);
}
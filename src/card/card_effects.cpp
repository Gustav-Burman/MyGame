#include "card_effects.h"
#include "../game_state/battle_state.h"

void DamageEffect::execute(BattleState& battle) {
	battle.getMonster().takeDamage(m_amount);
}

void BlockEffect::execute(BattleState& battle) {
	battle.getPlayer().addBlock(m_amount);
}
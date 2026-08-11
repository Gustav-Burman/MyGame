#include "card_effects.h"
#include "battle_state.h"

void DamageEffect::execute(BattleState& battle) {
	battle.getMonster().takeDamage(m_amount);
}
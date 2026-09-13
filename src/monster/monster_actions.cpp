#include "monster_actions.h"
#include "battle_state.h"

void AttackAction::execute(BattleState& battle)
{
	int amount = m_baseAmount;
	battle.getPlayer().takeDamage(amount);
}
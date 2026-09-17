#include "monster_actions.h"
#include "game_state/battle_state.h"

void AttackAction::execute(BattleState& battle)
{
	int amount = m_baseAmount;
	battle.damagePlayer(amount);
}
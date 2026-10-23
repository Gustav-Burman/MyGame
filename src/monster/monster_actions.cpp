#include "monster_actions.h"
#include "../game_state/battle_state.h"

void AttackAction::execute(BattleState& battle, Monster& self)
{
	int amount = m_baseAmount;
	battle.damagePlayer(amount);
}

void BlockAction::execute(BattleState& battle, Monster& self)
{
	int amount = m_baseAmount;
	
}
#include "monster_strategies.h"
#include "game_state/battle_state.h"

void SingleActionStrategy::performAction(BattleState& battle)
{
	m_action->execute(battle);
}
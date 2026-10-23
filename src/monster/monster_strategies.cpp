#include "monster_strategies.h"
#include "../game_state/battle_state.h"

MonsterAction* SingleActionStrategy::selectAction()
{
	return m_action.get();
}
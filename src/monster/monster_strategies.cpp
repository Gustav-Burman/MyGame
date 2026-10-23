#include "monster_strategies.h"
#include "../game_state/battle_state.h"

MonsterAction* SingleActionStrategy::selectAction()
{
	return m_action.get();
}

// Non-member functions
std::unique_ptr<MonsterStrategy> buildSingleActionStrategy(const MonsterDef& def)
{
	ActionEntry action = def.actions[0];
	switch (action.action)
	{
	case MonsterActionE::ATTACK:
	{
		std::unique_ptr<AttackAction> attackAction = std::make_unique<AttackAction>(action.value);
		std::unique_ptr<SingleActionStrategy> strategy = std::make_unique<SingleActionStrategy>(std::move(attackAction));
		return strategy;
	}

	default:
		// If no action specified, return 0 damage attack
		std::unique_ptr<AttackAction> attackAction = std::make_unique<AttackAction>(0);
		std::unique_ptr<SingleActionStrategy> strategy = std::make_unique<SingleActionStrategy>(std::move(attackAction));
		return strategy;
	}
}
#include "monster.h"

void Monster::takeDamage(int amount)
{
	m_health -= amount;
}

void Monster::takeTurn(BattleState& battle)
{
	MonsterAction* action = m_strategy->selectAction();
	action->execute(battle, *this);
}


// Non-member functions
Monster buildMonster(MonsterDef def)
{
	Monster monster{ def };

	switch (def.strategy)
	{
	case MonsterDef::SingleAction:
	{
		const int value = getActionValue(def);
		std::unique_ptr<AttackAction> attackAction = std::make_unique<AttackAction>(value);
		std::unique_ptr<SingleActionStrategy> strategy = std::make_unique<SingleActionStrategy>(std::move(attackAction));
		monster.setStrategy(std::move(strategy));
		break;
	}

	default:
		break;
	}

	return monster;
}

// Gets the value for the first action in the MonsterDef
int getActionValue(MonsterDef def)
{
	return def.actions.at(0)[0];
}
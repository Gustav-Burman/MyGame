#include "monster.h"

void Monster::takeDamage(int amount)
{
	m_health -= amount;
}

void Monster::execute(BattleState& battle)
{
	m_strategy->performAction(battle);
}


// Non-member functions
Monster buildMonster(MonsterDef def)
{
	Monster monster{ def };

	switch (def.strategy)
	{
	case MonsterDef::SingleAction:
		std::unique_ptr<AttackAction> ptr = std::make_unique<AttackAction>(def.actions.at(0));
		std::unique_ptr<SingleActionStrategy> strat = std::make_unique<SingleActionStrategy>(std::move(ptr));
		monster.addStrategy(std::move(strat));
	}

	return monster;
}
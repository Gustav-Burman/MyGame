#include "monster.h"

void Monster::takeDamage(int amount)
{
	m_health -= amount;
}

void Monster::addBlock(int amount)
{
	m_block += amount;
}

void Monster::takeTurn(BattleState& battle)
{
	// Having a dumb pointer for action is safe since MonsterAction lives until Monster is deleted
	if (m_strategy)
	{
		MonsterAction* action = m_strategy->selectAction();
		if (action) 
			action->execute(battle, *this);
	}
}


// Non-member functions
Monster buildMonster(MonsterDef def)
{
	Monster monster{ def };

	switch (def.strategy)
	{
	case MonsterDef::SingleAction:
	{
		monster.setStrategy(std::move(buildSingleActionStrategy(def)));
	}

	default:
		break;
	}

	return monster;
}

// Gets the value for the first action in the MonsterDef
//int getActionValue(MonsterDef def)
//{
//	return def.actions.at(0)[0];
//}
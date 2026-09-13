#include "monster.h"

void Monster::takeDamage(int amount)
{
	m_health -= amount;
}

void Monster::execute(BattleState& battle)
{
	m_actions[m_actionId]->execute(battle);
	if (++m_actionId >= m_actions.size())
		m_actionId = 0;
}


// Non-member functions
Monster buildMonster(MonsterDef def)
{
	Monster monster{ def };
	for (const auto& [action, value] : def.actions)
	{
		switch (action)
		{
		case MonsterDef::ATTACK:
			monster.addAction(std::make_unique<AttackAction>(value));
		}
	}
	return monster;
}
#pragma once
#include "monster.h"
#include "monster_actions.h"


class Goblin : public Monster
{
public:
	Goblin()
		: Monster(std::string("Goblin"), MonsterDef::BASIC, 30)
	{
	}
	void action(BattleState& battle) { m_action->execute(battle); }

private:
	int baseDamage = 5;
	std::unique_ptr<MonsterAction> m_action = std::make_unique<AttackAction>(baseDamage);
};
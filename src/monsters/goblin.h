#pragma once
#include "monster.h"
#include "monster_actions.h"


class Goblin : public Monster
{
public:
	Goblin()
		: Monster(std::string("Goblin"), BASIC, 30)
	{
	}
	void action(BattleState& battle) { m_action->execute(battle); }

private:
	std::unique_ptr<MonsterAction> m_action = std::make_unique<AttackAction>(5);
};
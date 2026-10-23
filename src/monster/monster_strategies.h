#pragma once
#include <memory>
#include "monster_actions.h"

// Forward declare BattleState to avoid circular dependency
class  BattleState;
struct MonsterDef;

// Defines what actions a monster can take and how those actions are chosen
class MonsterStrategy {
public:
	virtual ~MonsterStrategy() = default;
	virtual MonsterAction* selectAction() = 0;
};

class SingleActionStrategy : public MonsterStrategy
{
public:
	SingleActionStrategy(std::unique_ptr<MonsterAction> action)
		: m_action{ std::move(action) }
	{ }
	MonsterAction* selectAction() override;

private:
	std::unique_ptr<MonsterAction> m_action;
};

// Non-member functions
std::unique_ptr<MonsterStrategy> buildSingleActionStrategy(const MonsterDef& def);
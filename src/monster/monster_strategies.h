#pragma once
#include <memory>
#include "monster_actions.h"

// Forward declare BattleState to avoid circular dependency
class BattleState;

class MonsterStrategy {
public:
	virtual ~MonsterStrategy() = default;
	virtual void performAction(BattleState& battle) = 0;
};

class SingleActionStrategy : public MonsterStrategy
{
public:
	SingleActionStrategy(std::unique_ptr<MonsterAction> action)
		: m_action{ std::move(action) }
	{ }
	void performAction(BattleState& battle) override;

private:
	std::unique_ptr<MonsterAction> m_action;
};
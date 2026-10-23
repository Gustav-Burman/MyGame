#pragma once
#include "../utils.h"

// Forward declare BattleState to avoid circular dependency
class BattleState;
class Monster;

class MonsterAction {
public:
	virtual void execute(BattleState& battle, Monster& self) = 0;
	virtual ~MonsterAction() = default;
};

class AttackAction : public MonsterAction
{
public:
	explicit AttackAction(int baseAmount)
		: m_baseAmount{ baseAmount } { }
	void execute(BattleState& battle, Monster& self) override;

private:
	int m_baseAmount;
};

class BlockAction : public MonsterAction
{
public:
	explicit BlockAction(int baseAmount)
		: m_baseAmount{ baseAmount } { }
	void execute(BattleState& battle, Monster& self) override;

private:
	int m_baseAmount;
};
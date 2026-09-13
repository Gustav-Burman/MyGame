#pragma once

// Forward declare BattleState to avoid circular dependency
class BattleState;

class MonsterAction {
public:
	virtual void execute(BattleState& battle) = 0;
	virtual ~MonsterAction() = default;
};

class AttackAction : public MonsterAction
{
public:
	explicit AttackAction(int baseAmount)
		: m_baseAmount{ baseAmount } {}
	void execute(BattleState& battle) override;

private:
	int m_baseAmount;
};
#pragma once

// Forward declare BattleState to avoid circular dependency
class BattleState;

class CardEffect {
public:
	virtual void execute(BattleState& battle) = 0;
	virtual ~CardEffect() = default;
};

class DamageEffect : public CardEffect {
public:
	explicit DamageEffect(int amount)
		: m_amount{ amount } {}
	void execute(BattleState& battle) override;

private:
	int m_amount{};
};

class BlockEffect : public CardEffect {
public:
	explicit BlockEffect(int amount)
		: m_amount{ amount } {}
	void execute(BattleState& battle) override;

private:
	int m_amount{};
};
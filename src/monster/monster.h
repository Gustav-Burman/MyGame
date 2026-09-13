#pragma once
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include "monster_actions.h"
#include "../utils.h"

struct MonsterDef {
public:
	enum Type {
		NONE,
		BASIC,
		ELITE,
		BOSS
	};
	enum Action {
		ATTACK
	};

	std::string									name		{ "" };
	Type										type		{ NONE };
	int											maxHealth   { 0 };

	std::unordered_map<Action, int, EnumHash> actions{};
};

class Monster {
public:
	Monster(){}
	Monster(std::string name, MonsterDef::Type type, int maxHealth)
		: m_name{ std::move(name) }, m_type{ type }, m_maxHealth{ maxHealth }, m_health{ maxHealth }
	{
	}
	Monster(MonsterDef def)
		: m_name{ def.name }, m_type{ def.type }, m_maxHealth{ def.maxHealth }, m_health{ def.maxHealth }
	{
	}

	const std::string&		getName()       const { return m_name; }
	const int				getHealth()     const { return m_health; }
	const int				getMaxHealth()  const { return m_maxHealth; }
	const MonsterDef::Type  getType()       const { return m_type; }

	void takeDamage (int amount);

	void addAction  (std::unique_ptr<MonsterAction> action) { m_actions.push_back(std::move(action)); }
	void execute	(BattleState& battle);

private:
	std::string									m_name		{ "" };
	MonsterDef::Type							m_type		{ MonsterDef::NONE };
	int											m_maxHealth	{ 0 };
	int										    m_health	{ 0 };

	std::vector<std::unique_ptr<MonsterAction>> m_actions	{};
	int											m_actionId  { 0 };
};

// Non-member functions
Monster buildMonster(MonsterDef def);
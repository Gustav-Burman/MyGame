#pragma once
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <variant>
#include <utility>
#include "monster_actions.h"
#include "monster_strategies.h"
#include "../utils.h"


// Utility
enum class MonsterActionE {
	ATTACK,
	BLOCK
};

struct ActionEntry {
	MonsterActionE action;
	int			   value;
};

using ActionEntryVec = std::vector<ActionEntry>;

// Classes
struct MonsterDef {
public:
	enum Type {
		NONE,
		BASIC,
		ELITE,
		BOSS
	};

	enum Strategy {
		SingleAction
	};

	std::string	   name      { "" };
	Type	       type	     { NONE };
	int			   maxHealth { 0 };
	ActionEntryVec actions   {};
	Strategy	   strategy  {};
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
	void addBlock   (int amount);

	void setStrategy(std::unique_ptr<MonsterStrategy> strategy) { m_strategy = std::move(strategy); }
	void takeTurn	(BattleState& battle);

private:
	// Monster parameters
	std::string						    m_name		{ "" };
	MonsterDef::Type					m_type		{ MonsterDef::NONE };
	int									m_maxHealth	{ 0 };
	std::unique_ptr<MonsterStrategy>    m_strategy  {};
	int									m_actionId  { 0 };

	// Combat stats
	int m_health { 0 };
	int m_block  { 0 };
};

// Non-member functions
Monster buildMonster(MonsterDef def);

//int getActionValue(MonsterDef def);
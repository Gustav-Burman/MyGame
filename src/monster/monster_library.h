#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "monster.h"

std::unordered_map<MonsterDef::Action, int, EnumHash> goblinActions = {
	{ MonsterDef::Action::ATTACK, 8 }
};

const std::unordered_map<std::string, MonsterDef> MONSTER_LIBRARY =
{
	{ "Goblin", MonsterDef {
			.name = "Goblin",
			.type = MonsterDef::Type::BASIC,
			.maxHealth = 30,
			.actions = goblinActions
	}}
};
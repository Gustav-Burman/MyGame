#include "monster_library.h"

extern const monsterMap MONSTER_LIBRARY = buildMonsterLibrary();

monsterMap buildMonsterLibrary()
{
	std::unordered_map<int, int> goblinActions = {
		{ 0, 10 }
	};
	MonsterDef goblin =
	{
		.name = "Goblin",
		.type = MonsterDef::Type::BASIC,
		.maxHealth = 30,
		.actions = goblinActions
	};

	monsterMap monsterLibrary;
	monsterLibrary["Goblin"] = goblin;

	return monsterLibrary;
}
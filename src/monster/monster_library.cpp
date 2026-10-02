#include "monster_library.h"

extern const monsterMap MONSTER_LIBRARY = buildMonsterLibrary();



monsterMap buildMonsterLibrary()
{
	monsterActionMap goblinActions = {
		{ 0, std::vector<int>{ 10 } }
	};
	MonsterDef goblin =
	{
		.name = "Goblin",
		.type = MonsterDef::Type::BASIC,
		.maxHealth = 30,
		.actions = goblinActions,
		.strategy = MonsterDef::Strategy::SingleAction
	};

	monsterMap monsterLibrary;
	monsterLibrary["Goblin"] = goblin;

	return monsterLibrary;
}
#include "monster_library.h"

extern const monsterMap MONSTER_LIBRARY = buildMonsterLibrary();



monsterMap buildMonsterLibrary()
{
	ActionEntry goblinActions = {
		.action = MonsterActionE::ATTACK, .value  = 10
	};
	MonsterDef goblin =
	{
		.name = "Goblin",
		.type = MonsterDef::Type::BASIC,
		.maxHealth = 30,
		.actions = ActionEntryVec { goblinActions },
		.strategy = MonsterDef::Strategy::SingleAction
	};

	monsterMap monsterLibrary;
	monsterLibrary["Goblin"] = goblin;

	return monsterLibrary;
}
#pragma once
#include <string>

namespace Monster {
	enum class MonsterType {
		BASIC,
		ELITE,
		BOSS
	};
	class Monster {
		std::string name;
		MonsterType type;
		int maxHealth;
		int health;
	};
}
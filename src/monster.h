#pragma once
#include <string>

namespace Monster {
	enum class MonsterType {
		BASIC,
		ELITE,
		BOSS
	};
	class Monster {
	public:
		Monster(std::string name)
			: m_name { name }
		{
			std::cout << getName() << " monster constructed\n";
		}
		const std::string& getName() const { return m_name; }

	private:
		std::string m_name;
		MonsterType m_type{ MonsterType::BASIC };
		int m_maxHealth{ 20 };
		int m_health{ 20 };
	};
}
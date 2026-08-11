#pragma once
#include <string>
#include <iostream>

class Monster {
public:
	enum Type {
		BASIC,
		ELITE,
		BOSS
	};
	Monster(std::string name)
		: m_name { name }
	{
		std::cout << getName() << " monster constructed\n";
	}
	const std::string& getName()   const { return m_name; }
	const int          getHealth() const { return m_health; }
	void takeDamage(int damage);

private:
	std::string m_name;
	Type m_type{ Type::BASIC };
	int m_maxHealth{ 20 };
	int m_health{ 20 };
};
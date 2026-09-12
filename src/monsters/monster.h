#pragma once
#include <string>
#include <iostream>

class Monster {
public:
	enum Type {
		NONE,
		BASIC,
		ELITE,
		BOSS
	};
	Monster(){}
	Monster(std::string name, Type type, int maxHealth)
		: m_name{ std::move(name) }, m_type{ type }, m_maxHealth{ maxHealth }, m_health{ maxHealth }
	{
	}

	const std::string& getName()      const { return m_name; }
	const int          getHealth()    const { return m_health; }
	const int          getMaxHealth() const { return m_maxHealth; }
	const Type         getType()      const { return m_type; }
	void takeDamage(int amount);


private:
	std::string m_name{ "" };
	Type m_type{ NONE };
	int m_maxHealth{ 0 };
	int m_health{ 0 };
};
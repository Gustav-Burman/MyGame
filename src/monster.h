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
	~Monster() = default;

	Monster(const Monster&) = delete;
	Monster& operator=(const Monster&) = delete;

	Monster(Monster&& monster) noexcept
		: m_name{ std::move(monster.m_name) }, m_type{ monster.m_type }, m_maxHealth{ monster.m_maxHealth }, m_health{ monster.m_health }
	{
		monster.m_type = Monster::Type::NONE;
		monster.m_maxHealth = 0;
		monster.m_health = 0;
	}
	Monster& operator=(Monster&& monster) noexcept = default;


	const std::string& getName()   const { return m_name; }
	const int          getHealth() const { return m_health; }
	void takeDamage(int damage);

private:
	std::string m_name{ "" };
	Type m_type{ NONE };
	int m_maxHealth{ 0 };
	int m_health{ 0 };
};
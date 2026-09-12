#pragma once
#include <string>
#include <iostream>


class Player {
public:
	Player()
	{
		std::cout << "Player " << getName() << " constructed\n";
	}
	const std::string& getName()      const { return m_name; }
	const int          getMaxHealth() const { return m_maxHealth; }
	const int          getHealth()    const { return m_health; }
	void takeDamage(int amount);

private:
	std::string m_name{ "" };
	int m_maxHealth{ 100 };
	int m_health{ 100 };
	int m_maxEnergy{ 3 };
	int m_energy{ 3 };
	int	m_block{ 0 };
};
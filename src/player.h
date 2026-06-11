#pragma once
#include <string>
#include <iostream>

namespace Player {
	class Player {
	public:
		Player()
		{
			std::cout << "Player " << getName() << " constructed\n";
		}
		const std::string& getName() const { return m_name; }

	private:
		std::string m_name{ "Steven" };
		int m_maxHealth{ 100 };
		int m_health{ 100 };
		int m_maxEnergy{ 3 };
		int m_energy{ 3 };
		int	m_block{ 0 };
	};
}
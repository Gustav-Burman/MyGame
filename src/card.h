#pragma once
#include <string>

class Card {
public:
	enum Type {
		ATTACK,
		SKILL
	};
	Card(std::string name, Type type, int cost)
		: m_name{ name }, m_type{ type }, m_cost{ cost }
	{
	}
private:
	std::string m_name;
	Type m_type;
	int m_cost;
};
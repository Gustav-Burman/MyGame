#pragma once
#include <string>

namespace Card {
	enum class CardType {
		ATTACK,
		SKILL
	};

	class Card {
		std::string m_name;
		CardType m_type;
		int m_cost;
	};

}
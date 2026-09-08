#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "card.h"

typedef std::unordered_map<std::string, CardDefinition> libMap;
typedef std::unordered_map<CardDefinition::Effect, int, EnumHash> effectMap;

class CardLibrary {
public:
	static CardLibrary* getInstance();

	CardLibrary(CardLibrary&) = delete;
	CardLibrary& operator=(const CardLibrary&) = delete;
	CardLibrary(CardLibrary&&) = delete;
	CardLibrary& operator=(const CardLibrary&&) = delete;

	libMap getLib() { return m_library; }

private:
	CardLibrary(libMap library)
		: m_library {library}
	{};
	static CardLibrary* instance;
	libMap m_library;
};

// Non-member functions
libMap buildCardLibrary();

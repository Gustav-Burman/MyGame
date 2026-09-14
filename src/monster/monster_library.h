#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "monster.h"

// Typedef
using monsterMap = std::unordered_map<std::string, MonsterDef>;

// Global variables
extern const monsterMap MONSTER_LIBRARY;

// Functions
monsterMap buildMonsterLibrary();
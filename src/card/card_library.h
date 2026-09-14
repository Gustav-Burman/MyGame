#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "card.h"

// Typedef
using libMap = std::unordered_map<std::string, CardDef>;
using effectMap = std::unordered_map<CardDef::Effect, int, EnumHash>;

// Global variables
extern const libMap CARD_LIBRARY;

// functions
libMap buildCardLibrary();

#pragma once
#include <random>

static auto G_RNG_SEED{ std::default_random_engine{} };
static int MAX_HAND_SIZE{ 10 };
#pragma once

#include <random>

namespace engine
{

static std::random_device s_rd;
static std::mt19937 s_gen(s_rd());
static std::uniform_int_distribution<> s_dist(0, 255);

} // namespace engine

#include "monster_generator.h"
#include <array>

int MonsterGenerator::getRandomNumber(int min, int max)
{
	// static used for efficiency, so we only calculate this value once
	static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
	// evenly distribute the random number across our range
	return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}

Monster MonsterGenerator::generateMonster()
{
	static constexpr std::array s_names{ "James", "Igor", "Beto", "Perosvaldo", "Juca", "João" };
	static constexpr std::array s_roars{ "*aw aw*", "*psc psc*", "*row row*", "*rolf rolf*", "*ahu ahu*", "*hua hua*" };

	auto type{ static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1)) };
	int hitPoints{ getRandomNumber(1, 100) };

	// Without the cast, compilers with a high warning level complain about
	// an implicit cast from a signed to an unsigned integer
	auto name{ s_names[getRandomNumber(0, static_cast<int>(s_names.size() - 1))] };
	auto roar{ s_roars[getRandomNumber(0, static_cast<int>(s_roars.size() - 1))] };

	return Monster{ type, name, roar, hitPoints };
}

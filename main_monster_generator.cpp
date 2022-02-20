#include <iostream>
#include "monster_generator.h"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // If using Visual Studio, discard first random value

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}
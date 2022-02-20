#pragma once

#include "monster.h"

class MonsterGenerator
{
private:
	// Generate a random number between min and max (inclusive)
	static int getRandomNumber(int min, int max);

public:
	static Monster generateMonster();

};

#include <iostream>
#include "monster.h"

Monster::Monster(Type type, std::string name, std::string roar, int hitPoints)
	: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
{

}

void Monster::print() const
{
	std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
}

std::string_view Monster::getTypeString() const
{
	switch (m_type)
	{
		case Monster::Type::Dragon:		return "Dragon";
		case Monster::Type::Goblin:		return "Goblin";
		case Monster::Type::Ogre:		return "Ogre";
		case Monster::Type::Orc:		return "Orc";
		case Monster::Type::Skeleton:	return "Skeleton";
		case Monster::Type::Troll:		return "Troll";
		case Monster::Type::Vampire:	return "Vampire";
		case Monster::Type::Zombie:		return "Zombie";
		default: return "???";
	}
}
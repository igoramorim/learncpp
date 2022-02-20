#pragma once

#include <string>
#include <string_view>

class Monster
{
public:
	enum class Type
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		max_monster_types
	};

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

public:
	Monster(Type type, std::string name, std::string roar, int hitPoints);

	void print() const;

	// Returning string_view because the strings are known at compile-time
	std::string_view getTypeString() const;
};

#pragma once

#include <string>
#include "deck.h"

class Player
{
public:
	Player(std::string name);

	const Card& drawCard(Deck& deck);

	short getScore() const;

	bool isBust() const;

	std::string getName() const;

private:
	std::string m_name{};

	short m_score{};
};

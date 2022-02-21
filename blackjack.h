#pragma once

#include "deck.h"
#include "player.h"

class BlackJack
{
public:
	BlackJack();

	bool play();

	void printScore() const;

private:
	Deck m_deck{};

	Player m_player{ "Igor" };

	Player m_dealer{ "Dealer" };

	bool playerTurn();

	bool dealerTurn();

	char getPlayerInput() const;
};

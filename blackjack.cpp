#include <iostream>
#include "blackjack.h"
#include "constants.h"

BlackJack::BlackJack()
{
	m_deck.shuffle();
	m_deck.print();
}

// Returns true if player wins. false otherwise
bool BlackJack::play()
{
	// Dealer gets one card to start
	m_dealer.drawCard(m_deck);

	// Player gets two cards to start
	m_player.drawCard(m_deck);
	m_player.drawCard(m_deck);
	std::cout << '\n' << m_player.getName() << " now has score " << m_player.getScore() << '\n';

	if (playerTurn())
	{
		// player bust
		return false;
	}

	if (dealerTurn())
	{
		// dealer bust
		return true;
	}

	// player and dealer did not go bust. compare scores
	return (m_player.getScore() > m_dealer.getScore());
}

// Returns true if the player bust. false otherwise
bool BlackJack::playerTurn()
{
	// Checking because the player may start with 2 aces, so he losts before a hit
	if (m_player.isBust())
	{
		return true;
	}

	while (getPlayerInput() != bj::g_stand)
	{
		Card playerCard{ m_player.drawCard(m_deck) };
		std::cout << "The player drew card: ";
		playerCard.print();
		std::cout << " and now has score " << m_player.getScore() << '\n';

		if (m_player.isBust())
		{
			return true;
		}
	}
	return false;
}

// Returns true if the dealer bust. false otherwise
bool BlackJack::dealerTurn()
{
	// Draw card until the minimum value
	while (m_dealer.getScore() < bj::g_minimumDealerScore)
	{
		m_dealer.drawCard(m_deck);
	}

	if (m_dealer.isBust())
	{
		return true;
	}

	return false;
}

char BlackJack::getPlayerInput() const
{
	char choice{};

	do
	{
		std::cout << '\n';
		std::cout << m_player.getName() << ", what's your choice ?\n";
		std::cout << "(h)it or (s)tand ?\n";
		std::cin >> choice;
	} while (choice != bj::g_hit && choice != bj::g_stand);

	return choice;
}

void BlackJack::printScore() const
{
	std::cout << "*********************************\n";
	std::cout << "* " << m_player.getName() << "\t\tscore: " << m_player.getScore() << "\t*\n";
	std::cout << "* " << m_dealer.getName() << "\tscore: " << m_dealer.getScore() << "\t*\n";
	std::cout << "*********************************\n";
}
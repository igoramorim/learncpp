#include <iostream>

#include "player.h"
#include "deck.h"
#include "constants.h"

Player::Player(std::string name) : m_name{ name }
{

}

const Card& Player::drawCard(Deck& deck)
{
	std::cout << '\n' << m_name << " drawing card...\n";

	const Card& card = deck.dealCard();
	m_score += card.getValue();
	return card;
}

short Player::getScore() const
{
	return m_score;
}

bool Player::isBust() const
{
	return (m_score > bj::g_maximumScore);
}

std::string Player::getName() const
{
	return m_name;
}
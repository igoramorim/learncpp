#include <iostream>
#include <cassert>
#include "card.h"

Card::Card() = default;

Card::Card(Rank rank, Suit suit)
	: m_rank{ rank }, m_suit{ suit }
{

}

void Card::print() const
{
	switch (m_rank)
	{
	case Rank::Rank_2:		std::cout << '2'; break;
	case Rank::Rank_3:		std::cout << '3'; break;
	case Rank::Rank_4:		std::cout << '4'; break;
	case Rank::Rank_5:		std::cout << '5'; break;
	case Rank::Rank_6:		std::cout << '6'; break;
	case Rank::Rank_7:		std::cout << '7'; break;
	case Rank::Rank_8:		std::cout << '8'; break;
	case Rank::Rank_9:		std::cout << '9'; break;
	case Rank::Rank_10:		std::cout << 'T'; break;
	case Rank::Rank_Jack:	std::cout << 'J'; break;
	case Rank::Rank_Queen:	std::cout << 'Q'; break;
	case Rank::Rank_King:	std::cout << 'K'; break;
	case Rank::Rank_Ace:	std::cout << 'A'; break;
	default:
		std::cout << '?';
		break;
	}

	switch (m_suit)
	{
		case Suit::Clubs:		std::cout << 'C'; break;
		case Suit::Diamonds:	std::cout << 'D'; break;
		case Suit::Hearts:		std::cout << 'H'; break;
		case Suit::Spades:		std::cout << 'S'; break;
		default:				std::cout << '?'; break;
	}
}

short Card::getValue() const
{
	switch (m_rank)
	{
		case Rank::Rank_2:		return 2;
		case Rank::Rank_3:		return 3;
		case Rank::Rank_4:		return 4;
		case Rank::Rank_5:		return 5;
		case Rank::Rank_6:		return 6;
		case Rank::Rank_7:		return 7;
		case Rank::Rank_8:		return 8;
		case Rank::Rank_9:		return 9;
		case Rank::Rank_10:		return 10;
		case Rank::Rank_Jack:	return 10;
		case Rank::Rank_Queen:	return 10;
		case Rank::Rank_King:	return 10;
		case Rank::Rank_Ace:	return 11;
		default:
			assert(false && "every card must have a value!");
			return 0;
	}
}
#include <iostream>
#include <algorithm> // std::shuffle
#include <random> // std::mt19937
#include <cassert>

#include "deck.h"

Deck::Deck()
{
	index_t index{ 0 };

	for (int s{ 0 }; s < static_cast<int>(Card::Suit::MaxSuits); s++)
	{
		for (int r{ 0 }; r < static_cast<int>(Card::Rank::MaxRanks); r++)
		{
			m_deck[index] = { static_cast<Card::Rank>(r),  static_cast<Card::Suit>(s) };
			index++;
		}
	}
}

void Deck::print() const
{
	for (const auto& card : m_deck)
	{
		card.print();
		std::cout << ' ';
	}
	std::cout << '\n';
}

void Deck::shuffle()
{
	// mt static so it only gets seeded once
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(m_deck.begin(), m_deck.end(), mt);
	m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
	assert(m_cardIndex < m_deck.size());

	auto& card = m_deck[m_cardIndex];
	m_cardIndex++;
	return card;
}
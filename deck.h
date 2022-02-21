#pragma once

#include <array>
#include "card.h"

using deck_t = std::array<Card, 52>;
using index_t = deck_t::size_type;

class Deck
{
public:
	Deck();

	void print() const;

	void shuffle();

	const Card& dealCard();

private:
	deck_t m_deck{};

	index_t m_cardIndex{ 0 };
};

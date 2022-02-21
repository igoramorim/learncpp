#pragma once

class Card
{
public:
	enum class Rank
	{
		Rank_2,
		Rank_3,
		Rank_4,
		Rank_5,
		Rank_6,
		Rank_7,
		Rank_8,
		Rank_9,
		Rank_10,
		Rank_Jack,
		Rank_Queen,
		Rank_King,
		Rank_Ace,
		MaxRanks
	};

	enum class Suit
	{
		Clubs,
		Diamonds,
		Hearts,
		Spades,
		MaxSuits
	};

	Card();

	Card(Rank rank, Suit suit);

	void print() const;

	short getValue() const;

private:
	Rank m_rank{};

	Suit m_suit{};
};

#include <iostream>
#include <array>
#include <algorithm> // std::shuffle
#include <random> // std::mt19937
#include <ctime> // std::time
#include <cassert>
#include <string>

constexpr char  HIT                  = 'h';
constexpr char  STAND                = 's';
constexpr short LIMIT_SCORE          = 21;
constexpr short DEALER_MINIMUM_SCORE = 17;
constexpr bool  PLAYER_WIN           = true;
constexpr bool  PLAYER_LOST          = false;

enum class CardRank
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

enum class CardSuit
{
	Clubs,
	Diamonds,
	Hearts,
	Spades,

	MaxSuits
};

struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

struct Player
{
	std::string name{};
	short score{};
};

void printCard(const Card& card)
{
	switch (card.rank)
	{
		case CardRank::Rank_2:		std::cout << '2'; break;
		case CardRank::Rank_3:		std::cout << '3'; break;
		case CardRank::Rank_4:		std::cout << '4'; break;
		case CardRank::Rank_5:		std::cout << '5'; break;
		case CardRank::Rank_6:		std::cout << '6'; break;
		case CardRank::Rank_7:		std::cout << '7'; break;
		case CardRank::Rank_8:		std::cout << '8'; break;
		case CardRank::Rank_9:		std::cout << '9'; break;
		case CardRank::Rank_10:		std::cout << 'T'; break;
		case CardRank::Rank_Jack:	std::cout << 'J'; break;
		case CardRank::Rank_Queen:	std::cout << 'Q'; break;
		case CardRank::Rank_King:	std::cout << 'K'; break;
		case CardRank::Rank_Ace:	std::cout << 'A'; break;
		default:
			std::cout << '?';
			break;
	}

	switch (card.suit)
	{
		case CardSuit::Clubs:		std::cout << 'C'; break;
		case CardSuit::Diamonds:	std::cout << 'D'; break;
		case CardSuit::Hearts:		std::cout << 'H'; break;
		case CardSuit::Spades:		std::cout << 'S'; break;
		default:
			std::cout << '?';
			break;
	}
}

using deck_t = std::array<Card, 52>;
using index_t = deck_t::size_type;

deck_t createDeck()
{
	deck_t deck{};
	index_t index{ 0 };

	for (int s{ 0 }; s < static_cast<int>(CardSuit::MaxSuits); s++)
	{
		for (int r{ 0 }; r < static_cast<int>(CardRank::MaxRanks); r++)
		{
			deck[index].rank = static_cast<CardRank>(r);
			deck[index].suit = static_cast<CardSuit>(s);
			index++;
		}
	}

	return deck;
}

void printDeck(const deck_t& deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

void shuffleDeck(deck_t& deck)
{
	// mt static so it only gets seeded once
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

short getCardValue(const Card& card)
{
	switch (card.rank)
	{
		case CardRank::Rank_2:		return 2;
		case CardRank::Rank_3:		return 3;
		case CardRank::Rank_4:		return 4;
		case CardRank::Rank_5:		return 5;
		case CardRank::Rank_6:		return 6;
		case CardRank::Rank_7:		return 7;
		case CardRank::Rank_8:		return 8;
		case CardRank::Rank_9:		return 9;
		case CardRank::Rank_10:		return 10;
		case CardRank::Rank_Jack:	return 10;
		case CardRank::Rank_Queen:	return 10;
		case CardRank::Rank_King:	return 10;
		case CardRank::Rank_Ace:	return 11;
		default:
			assert(false && "every card must have a value!");
			return 0;
	}
}

char getPlayerInput()
{
	char choice{};

	do
	{
		std::cout << "\nPlayer, what's your choice ?\n";
		std::cout << "(h)it or (s)tand ?\n";
		std::cin >> choice;
	} while (choice != HIT && choice != STAND);

	return choice;
}

Card drawCard(const deck_t& deck)
{
	std::cout << "\nDrawing card...\n";
	static short index{ 0 };
	// TODO: check deck bounds?
	auto card = deck[index];
	printCard(card);
	index++;
	return card;
}

void printPlayerScore(const Player& player)
{
	std::cout << '\n' << player.name << " score: " << player.score << '\n';
}

bool isScoreOverLimit(const short& score)
{
	return (score > LIMIT_SCORE);
}

// returns true if the player bust. false otherwise
bool playerTurn(Player& player, const deck_t& deck)
{
	// checking because the player may start with 2 aces, so he losts before a hit
	if (isScoreOverLimit(player.score))
	{
		return true;
	}
	printPlayerScore(player);

	while (getPlayerInput() != STAND)
	{
		player.score += getCardValue(drawCard(deck));
		printPlayerScore(player);
		if (isScoreOverLimit(player.score))
		{
			return true;
		}
	}

	return false;
}

// returns true if the dealer bust. false otherwise
bool dealerTurn(Player& dealer, const deck_t& deck)
{
	// draw card until the minimum value
	while (dealer.score < DEALER_MINIMUM_SCORE)
	{
		dealer.score += getCardValue(drawCard(deck));
	}

	printPlayerScore(dealer);

	if (isScoreOverLimit(dealer.score))
	{
		return true;
	}

	return false;
}

// returns true if player wins. false otherwise
bool playBlackjack(const deck_t& deck)
{
	// dealer gets one card to start
	Player dealer{ "Dealer", getCardValue(drawCard(deck))};
	printPlayerScore(dealer);

	// player gets two cards to start
	Player player{ "Player", getCardValue(drawCard(deck)) + getCardValue(drawCard(deck)) };

	// player cycle
	if (playerTurn(player, deck))
	{
		// player bust
		return false;
	}

	// dealer cycle
	if (dealerTurn(dealer, deck))
	{
		// dealer bust
		return true;
	}

	// player and dealer did not go bust. compare scores
	return (player.score > dealer.score);
}

int main()
{
	auto deck{ createDeck() };
	shuffleDeck(deck);
	printDeck(deck);

	if (playBlackjack(deck))
		std::cout << "Player wins!" << '\n';
	else
		std::cout << "Oh no... You lost!" << '\n';

	/*for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ' << getCardValue(card);
		std::cout << '\n';
	}*/

	return 0;
}
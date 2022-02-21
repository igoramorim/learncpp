#include <iostream>
#include "blackjack.h"

int main()
{
    BlackJack blackjack{};

    if (blackjack.play())
        std::cout << "\You win!" << '\n';
    else
        std::cout << "\nOh no... You lost!" << '\n';

    blackjack.printScore();

	return 0;
}
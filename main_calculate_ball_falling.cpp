
#include <iostream>
#include "constants.h"

double getTowerHeight()
{
    std::cout << "Enter de height in towerHeight: ";
    double n{};
    std::cin >> n;
    return n;
}

double calculateHeight(double towerHeight, int seconds)
{
    double distFallen{ (constants::gravity * (seconds * seconds)) / 2 };
    return { towerHeight - distFallen };

}

void calculateAndPrint(double towerHeight, int seconds)
{
    double height{ calculateHeight(towerHeight, seconds) };

    if (height > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground\n";
}

int main()
{
    double towerHeight{ getTowerHeight() };

    calculateAndPrint(towerHeight, 0);
    calculateAndPrint(towerHeight, 1);
    calculateAndPrint(towerHeight, 2);
    calculateAndPrint(towerHeight, 3);
    calculateAndPrint(towerHeight, 4);
    calculateAndPrint(towerHeight, 5);

    return 0;
}


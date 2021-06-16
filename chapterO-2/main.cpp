#include <bitset>
#include <iostream>

int main()
{
    std::bitset<4> x{ 0b1100 };

    std::cout << "Init: " << x << "\n\n";
    std::cout << "SHIFT right by 1: " << (x >> 1) << '\n';
    std::cout << "SHIFT left by 2: " << (x << 2) << "\n\n";

    std::cout << "NOT operator. Flips every bit: " << (~x) << "\n\n";

    std::bitset<4> y{ 0b0101 };
    std::cout << "OR operator x:\t\t" << x << '\n';
    std::cout << "OR operator y:\t\t" << y << '\n';
    std::cout << "OR operator final:\t" << (x | y) << "\n\n";

    std::cout << "AND operator x:\t\t" << x << '\n';
    std::cout << "AND operator y:\t\t" << y << '\n';
    std::cout << "AND operator final:\t" << (x & y) << "\n\n";

    std::cout << "XOR operator x:\t\t" << x << '\n';
    std::cout << "XOR operator y:\t\t" << y << '\n';
    // When evaluating two operands, XOR evaluates to true (1) if one and only one of its operands is true (1).
    // If neither or both are true, it evaluates to 0
    std::cout << "XOR operator final:\t" << (x ^ y) << "\n\n";

    return 0;
}


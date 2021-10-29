#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> bits{ 0b0000'1010 };
    std::cout << "Init:\t\t" << bits << '\n';

    bits.set(2);
    std::cout << "Set 2:\t\t" << bits << '\n';

    bits.flip(4);
    std::cout << "Flip 4:\t\t" << bits << '\n';

    bits.reset(4);
    std::cout << "Reset 4:\t" << bits << '\n';

    std::cout << "Final:\t\t" << bits << '\n';

    std::cout << "Bit 3 value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 value: " << bits.test(4) << '\n';

    std::bitset<4> x{ 0b1100 };

    std::cout << "\nInit: " << x << "\n\n";
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

    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
    constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint_fast8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    // testing if a bit is on or off
    std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n\n");

    // setting a bit (turn on)
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    flags |= mask1; // turn on bit 1
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n\n");

    return 0;
}


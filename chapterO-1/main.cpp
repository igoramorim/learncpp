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

    return 0;
}


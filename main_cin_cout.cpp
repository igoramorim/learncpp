
#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>

int main()
{
    std::cout << "Hello World!\n";

    int x{ 14 };
    std::cout << x << "\n" << "teste" << "\n";

    std::cout << "Enter a number: ";
    int y{ };
    std::cin >> y;
    std::cout << "You entered " << y << "\n";

    int z{ };
    std::cout << "z: " << z << "\n\n";

    std::string name{};
    std::cout << "Enter your name: ";

    // read a full line of text. std::ws is a input manipulator that tells std::cin to ingnore leading whitespaces
    // so it can read the input as a string
    std::getline(std::cin >> std::ws, name);
    std::cout << "Your name is " << name << " and it has " << name.length() << " characters\n";

    std::cout << "w\tt\tf\v!\n";

    std::cout << "\x6F\n\n";

    int oc{ 012 }; // prefix 0 for octal. cout prints number in decimal, so 012 in octal is 10 in decimal
    std::cout << "octal value printed decimal:\t" << oc << '\n';
    std::cout << std::oct << "octal value printed octal:\t" << oc << '\n';

    int hex{ 0xF };
    std::cout << "hexa value printed decimal:\t" << hex << '\n';
    std::cout << std::hex << "hexa value printed hexa:\t" << hex << '\n';

    // std::bitset<8> means we want to store 8 bits
    // single quote ' as digit separator
    std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
    std::cout << "binary value printed:\t\t" << bin1 << '\n';
    std::cout << "binary value printed:\t\t" << std::bitset<4>{ 0b1010 } << "\n\n"; // we can also print from std::bitset directly

    return 0;
}

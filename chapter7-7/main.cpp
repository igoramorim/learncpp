#include <iostream>

int main()
{
    std::cout << "ascii\t" << "char\n";

    int i{ 65 };
    while (i <= 90)
    {
        std::cout << i << '\t' << static_cast<char>(i) << '\n';
        ++i;
    }

    return 0;
}


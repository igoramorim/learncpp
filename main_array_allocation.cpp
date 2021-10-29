#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

int main()
{
    int namesAmount{ };
    std::cout << "How many names would you like to enter?: ";
    std::cin >> namesAmount;

    auto* names{ new std::string[namesAmount]{} };

    // Ignore the line feed that was left by std::cin.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i{ 0 }; i < namesAmount; ++i)
    {
        std::cout << "Enter name #" << i+1 << ": ";
        std::getline(std::cin, names[i]);
    }

    std::sort(names, names + namesAmount);

    std::cout << '\n' << "Here is your sorted list:" << "\n\n";
    for (int i{ 0 }; i < namesAmount; ++i)
    {
        std::cout << "Name #" << i << ": " << names[i] << '\n';
    }

    delete[] names;
    names = nullptr;
    
    return 0;
}


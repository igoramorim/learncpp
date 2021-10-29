#include <iostream>

int getNumber()
{
    int number{ };
    while (number < 1 || number > 9)
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;

        // if the user entered something invalid
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }
    }
    return number;
}

int main()
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    int number{ getNumber() };
    int numberIdx{ };

    for (int i{ 0 }; i < std::size(array); i++)
    {
        std::cout << array[i] << ' ';
        if (number == array[i])
        {
            numberIdx = i;
        }
    }

    std::cout << "\nIndex for number " << number << " is " << numberIdx << '\n';

    return 0;
}


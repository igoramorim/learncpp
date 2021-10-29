#include <iostream>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    for (int i{ 0 }; i < length - 1; ++i)
    {
        bool swapped{ false };

        for (int ii{ 0 }; ii < (length - i) - 1; ++ii)
        {

            std::cout << "i:\t" << i << '\n';
            std::cout << "ii:\t" << ii << '\n';
            std::cout << "arr[ii]: " << array[ii] << '\n';
            std::cout << "arr[ii+1]: " << array[ii+1] << '\n';
            if (array[ii] > array[ii + 1])
            {
                std::cout << "swap: " << array[ii] << " for " << array[ii + 1] << '\n';
                std::swap(array[ii], array[ii + 1]);
                swapped = true;
            }
            std::cout << '\n';
        }
        if (!swapped)
        {
            // iteration is 0 based, but counting iterations is 1-based.  So add 1 here to adjust.
            std::cout << "Early termination on iteration: " << i + 1 << '\n';
            break;
        }
        std::cout << "-------------------------------\n\n";
    }

    std::cout << '\n';

    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    return 0;
}

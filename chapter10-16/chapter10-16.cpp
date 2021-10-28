#include <iostream>

void changeValue(int& ref) // ref is a reference to the argument passed in, not a copy
{
    ref = 99;
}

int main()
{
    int value{ 5 };     // normal integer
    int value2{ 10 };   // another normal integer
    int& ref1{ value }; // reference to variable value
    int& ref2{ value }; // reference to variable value

    // BE CAREFUL HERE!
    // Instead of changing ref1 to reference variable value2, it assigns the value of value2 to value1.
    ref1 = value2;
    std::cout << value << '\t' << &value << "\n\n";

    value = 6; // changing the 'original' value, changes the reference variable value
    ref1 = 7;  // and changing the reference variable value also changes the 'original' variable value

    std::cout << value << '\t' << &value << '\n'; // both 'original' variable and reference variable returns the same address
    std::cout << value2 << '\t' << &value2 << '\n';
    std::cout << ref1 << '\t' << &ref1<< '\n';
    std::cout << ref2 << '\t' << &ref2 << '\n';

    changeValue(value); // pass 'original' variable value
    std::cout << '\n' << value << '\t' << &value << '\n';

    auto* names{ new int[1000]{} };

    return 0;
}


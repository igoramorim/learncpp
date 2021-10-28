#include <iostream>

int main()
{
    short value{ 7 }; // short is 2 bytes
    short* ptr{ &value };

    // addition and subtraction can be performed on pointers
    // addition on a pointer returns the memory address of the next object of the type that ptr points to

    std::cout << ptr << '\n';       // 012FF7F4 (addition in hexadecimal)
    std::cout << ptr + 1 << '\n';   // 012FF7F6 = 012FF7F4 + 2 (2 bytes (because ptr is short) * 1, wich is the amount being add)
    std::cout << ptr + 2 << '\n';   // 012FF7F8 = 012FF7F4 + 4 (2 bytes * 2, wich is the amount being add)
    std::cout << ptr + 3 << '\n';   // 012FF7FA = 012FF7F4 + 6 (2 bytes * 3, wich is the amount being add)

    std::cout << "\n\n";


    int array[]{ 9, 7, 5, 3, 1 }; // int 4 bytes

    // arrays are laid out sequentially in memory, That is, elements 0, 1, 2, … are all adjacent to each other

    std::cout << "Element 0 is at address: " << &array[0] << '\n'; // 0096FC14
    std::cout << "Element 1 is at address: " << &array[1] << '\n'; // 0096FC18
    std::cout << "Element 2 is at address: " << &array[2] << '\n'; // 0096FC1C
    std::cout << "Element 3 is at address: " << &array[3] << '\n'; // 0096FC20

    std::cout << "\n\n";

    std::cout << &array[1] << '\n'; // print memory address of array element 1
    std::cout << array + 1 << '\n'; // print memory address of array pointer + 1 

    std::cout << array[1] << '\n'; // prints 7
    std::cout << *(array + 1) << '\n'; // prints 7 (note the parenthesis required here)

    std::cout << "\n\n";

    int nArray[5]{ 9, 7, 5, 3, 1 };
    char cArray[]{ "Hello!" };
    const char* name{ "Igor" };

    std::cout << nArray << '\n'; // print memory address of nArray
    std::cout << cArray << '\n'; // print Hello! because it is char array
    std::cout << name << '\n';   // print Igor because it is char

    char c{ 'X' };
    std::cout << &c; // print some weird stuff. Because c is char, std::cout tries to print the memory address as a string

    std::cout << "\n\n";

    int value2{ 5 };
    int* const ptr2{ &value2 };
    *ptr2 = 6;

    std::cout << "\n\n";
    return 0;
}


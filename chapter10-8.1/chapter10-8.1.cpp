#include <iostream>

int main()
{
    int var1{ 5 };
    std::cout << &var1 << '\n'; // prints address of var1
    std::cout << var1 << '\n'; // prints contents of var1

    int* ptr1{ &var1 }; // ptr1 points to var1
    std::cout << ptr1 << '\n'; // prints address held in ptr1, which is &var1
    std::cout << *ptr1 << '\n'; // Indirection through ptr1 (get the var1 that ptr1 is pointing to)

    *ptr1 = 7;
    std::cout << var1 << '\n'; // prints contents of var1 wich is now 7
    
    var1 = 10;
    std::cout << *ptr1 << '\n'; // prints 10

    std::cout << "size of a pointer is " << sizeof(ptr1) << '\n';

    std::cout << typeid(&var1).name() << "\n\n\n";

    short value{ 7 }; // &value = 0012FF60
    short otherValue{ 3 }; // &otherValue = 0012FF54

    short* ptr{ &value };

    std::cout << &value << '\n';	// 0012FF60
    std::cout << value << '\n';		// 7
    std::cout << ptr << '\n';		// 0012FF60
    std::cout << *ptr << '\n';		// 7
    std::cout << '\n';

    *ptr = 9;

    std::cout << &value << '\n';	// 0012FF60
    std::cout << value << '\n';		// 9
    std::cout << ptr << '\n';		// 0012FF60
    std::cout << *ptr << '\n';		// 9
    std::cout << '\n';

    ptr = &otherValue;

    std::cout << &otherValue << '\n';	// 0012FF54
    std::cout << otherValue << '\n';	// 3
    std::cout << ptr << '\n';			// 0012FF54
    std::cout << *ptr << '\n';			// 3
    std::cout << '\n';

    std::cout << sizeof(ptr) << '\n';	// 4
    std::cout << sizeof(*ptr) << '\n';	// 2

    return 0;
}


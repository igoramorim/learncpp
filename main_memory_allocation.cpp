#include <iostream>

void doSomething()
{
    int* ptr{ new int{} };
}

int main()
{
    int* ptr{ new int }; // dynamically allocate an integer
    *ptr = 7; // put a value in that memory location

    delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.
    ptr = nullptr;

    //std::cout << *ptr; // Indirection through a dangling pointer will cause undefined behavior
    // delete ptr; // trying to deallocate the memory again will also lead to undefined behavior.

    // if 'new' fails to allocate memory, value will be a nullptr because of the std::nothrow
    int* value{ new (std::nothrow) int{} }; // ask for an integer's worth of memory
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }


    // memory leak
    // This function allocates an integer dynamically, but never frees it using delete
    // Memory leaks happen when your program loses the address of some bit of dynamically allocated memory before giving it back to the operating system
    // doSomething();

    /*
    int value2 = 5;
    int* ptr2{ new int{} }; // allocate memory
    ptr2 = &value2; // old address lost, memory leak results
    
    // This can be fixed by deleting the pointer before reassigning it
    int value2{ 5 };
    int* ptr2{ new int{} }; // allocate memory
    delete ptr2; // return memory back to operating system
    ptr2 = &value2; // reassign pointer to address of value
    */


    return 0;
}


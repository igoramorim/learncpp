#include <iostream>
#include <vector>
#include <array>

struct Employee
{
	std::string name{};
};

// quizz prototypes
int sumTo(int value);
void printEmployeeName(const Employee& employee);
std::pair<int, int> minmax(int a, int b);
std::size_t getIndexOfLargestValue(const std::vector<int>& arr);
const std::string& getElement(const std::vector<std::string>& arr, std::size_t index);

/*
* Pass arguments by value
* 1. Does not change the variable from the caller
*/
void passByValue(int x)
{
	x = 99;
}

/*
* Return by value
* 1. No need to worry about scope issues
* 2. A copy of the value is returned
*/

int returnByValue(int x)
{
	int value{ x + 1 };
	return value; // a copy of value will be returned here
} // value goes out of scope here

/*
* Pass arguments by reference
* 1. It can change the variable value from the caller
* 2. Passing arguments by reference can be useful to 'return' multiple values
* 3. Passing const reference if you only need to read the variable
*/
void passByRef(int& ref)
{
	ref = ref + 1;
}

void getMultipleValues(int& aOut, int& bOut, int& cOut)
{
	aOut = 10;
	bOut = 11;
	cOut = 12;
}

void passByConstRef(const int& ref)
{
	// ref = 99; // compiler error. can not change const value
}

void passByRefPointer(int*& refPointer)
{
	refPointer = nullptr; // this changes the actual ptr argument passed in, not a copy
}

/*
* Pass arguments by address
*/
void passByAddress(int* ptr)
{
	*ptr = 99; // changes the value that ptr is pointing to
}

/* Return by reference
* 1. Just like return by address, dont return by reference a function local variable
*/
int& returnByReferenceLocalVariable(int x)
{
	int value{ x * 2 };
	return value;
}

int& returnByReference(std::array<int, 5>& array, int index)
{
	// Since array is a reference passed by the caller, we know that at the end of this function array will not be destroyed
	// So it is ok to return by reference
	return array[index];
}

/*
* Return by address
* 1. Dont return by address a local variable
* 2. It can be used to return dynamic allocated memory
*/
int* returnByAddressLocalVariable(int x)
{
	int value{ x + 1 };
	return &value;
}

int* returnByAddress(int size)
{
	// Return by address works here because the memory is dynamic allocated
	// It is not destroyed in this function scope
	return new int[size];
}


int main()
{
	// by value
	int x{ 10 };
	std::cout << "main x: " << x << '\n';
	passByValue(x);
	std::cout << "main x: " << x << '\n';
	std::cout << '\n';
	// ==============================================

	// by ref
	int y{ 5 };
	std::cout << "main y: " << y << '\n';
	passByRef(y);
	std::cout << "main y: " << y << '\n';

	int a{};
	int b{};
	int c{};
	getMultipleValues(a, b, c);
	std::cout << "'return' multiple values by reference: " << a << ' ' << b << ' ' << c << '\n';

	int v{ 5 };
	int* ptr{ &v };
	std::cout << "ptr is: " << (ptr ? "non-null" : "null") << '\n';
	passByRefPointer(ptr);
	std::cout << "ptr is: " << (ptr ? "non-null" : "null") << '\n';
	auto vv = returnByReferenceLocalVariable(10);
	vv += 5;
	std::cout << "return by reference local variable: " << vv << '\n';
	std::array<int, 5> arr;
	// Set the element with index 2 to the value 100
	returnByReference(arr, 2) = 100;
	std::cout << "return by reference: " << arr[2] << '\n';
	std::cout << '\n';
	// ==============================================
	
	// by address
	int xx{ 10 };
	std::cout << "main xx: " << xx << '\n';
	passByAddress(&xx);
	std::cout << "main xx: " << xx << '\n';
	auto yy = returnByAddressLocalVariable(1);
	std::cout << "return by address local variable: " << *yy << '\n';
	int* array{ returnByAddress(10) };
	array[0] = 100;
	array[1] = 101;
	array[2] = 102;
	delete[] array;
	
	return 0;
}
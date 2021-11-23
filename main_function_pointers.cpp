#include <iostream>
#include <functional>
#include "input.h" // getInteger

int foo()
{
	return 5;
}

float goo()
{
	return 1.0f;
}

int hoo(int x)
{
	return x + 1;
}

char getOperation()
{
	char op{};

	do
	{
		std::cout << "Enter an operation ('+', '-', '*', '/'): ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '*' && op != '/');

	return op;
}

int add2(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int division(int x, int y)
{
	return x / y;
}

// type alias to make it easy to use. A function that returns an int and has 2 int parameters
using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char& operation)
{
	switch (operation)
	{
		case '+': return &add2;
		case '-': return &subtract;
		case '*': return &multiply;
		case '/': return &division;
	}
	return nullptr;
}

int main()
{
	std::cout << foo << '\n'; // prints the memory address of the function

	// a pointer pointing to the function foo
	// the function pointer type must match the function return type
	int (*funcPtrFoo)() { &foo };
	float (*funcPtrGoo)() { &goo };
	int (*funcPtrHoo)(int) { &hoo }; // a pointer to a function that has parameters
	
	int (*anotherFuncPtr)() { nullptr }; // it is ok to assign a nullptr to a function pointer

	// calling a function using a function pointer
	std::cout << (*funcPtrFoo)() << '\n'; // this way works
	std::cout << funcPtrHoo(5) << '\n'; // this way also works and it is simple


	int n1{ getInteger() };
	int n2{ getInteger() };
	char oper{ getOperation() };

	// get the appropriate function as a function pointer
	ArithmeticFunction func{ getArithmeticFunction(oper) };
	if (func)
		// call the function using both user int inputs
		std::cout << "Result is: " << func(n1, n2) << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>
#include <functional>

// We dont know that fn will be. std::function works with regular and lambda functions
void repeat(int repetitions, const std::function<void(int)>& fn)
{
	for (int i = 0; i < repetitions; i++)
	{
		fn(i);
	}
}

int main()
{
	/*
	* Lambda syntax
	* [captureClause] (parameters) -> returnType
	* {
	*	statements;
	* }
	*/


	/*
	* std::find_if expects a function pointer as the last parameter
	* That means would need to declare a function in global scope that would be used only here
	* Instead of this we can use a lambda function
	*/
	constexpr std::array<std::string_view, 4> fruits{ "apple", "banana", "walnut", "lemon" };

	const auto fruitsFound{ std::find_if(fruits.begin(), fruits.end(),
		[](std::string_view lambdaParam) { return (lambdaParam.find("nut") != std::string_view::npos); }) };


	// We can also initialize a lambda variable with a lambda definition and then use it later
	auto isEven{
		[](int i)
		{
			return ((i % 2) == 0);
		}
	};

	constexpr std::array<int, 10> numbers{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	const auto allEven{std::all_of(numbers.begin(), numbers.end(), isEven)};


	/*
	* Some cases we cant use 'auto' for the lambda type because we may not know
	* what the lambda will be
	* In these cases we use std::function (See function 'repeat')
	*/
	repeat(3, [](int i) { std::cout << i << '\n'; });


	/*
	* Generic lambdas
	* Lambdas with one or more 'auto' parameter can potentially work with a wide variarity of types
	* Because all string types allow access to each character by [] operator we can pass std::string or a C-style string
	* that the lambda with 'auto' parameters will work just fine
	*/
	constexpr std::array months{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	constexpr std::array<const char*, 12> monthsC{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	
	// Search for two consecutive months that start with the same letter.
	const auto sameLetter{ std::adjacent_find(monthsC.begin(), monthsC.end(), [](const auto& a, const auto& b) { return (a[0] == b[0]); }) };

	if (sameLetter != monthsC.end())
	{
		// std::next returns the next iterator after sameLetter
		std::cout << *sameLetter << " and " << *std::next(sameLetter) << " start with the same letter\n";
	}


	/*
	* Generic lambda and static variables
	* A static variable will be created for each type of the lambda
	*/
	auto print{
		[](auto value) {
			static int callCount{ 0 };
			std::cout << callCount++ << ": " << value << '\n';
		}
	};

	print("hello"); // 0: hello   -> first time passing a string literal
	print("world"); // 1: world   -> second time passing a string literal
	print(100);     // 0: 100     -> first time passing an integer
	print(200);     // 1: 200     -> second time passing an integer
	print("igor");  // 2: igor    -> third time passing a string literal


	/*
	* Return type deduction
	*/
	auto divide{ [](int x, int y, bool bInteger) -> double { // explicitly specifying the return type
		if (bInteger)
			return x / y; // will do an inplicit conversion to double
		else
			return static_cast<double>(x) / y;
	} };

	std::cout << divide(3, 2, true) << '\n';
	std::cout << divide(3, 2, false) << '\n';


	/*
	* Standard library functions objects
	* The Standard library (<functional> header) comes with many basics operations
	*/
	std::array<int, 10> numbers2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::sort(numbers2.begin(), numbers2.end(), std::greater{}); // using standard library
	// std::sort(numbers2.begin(), numbers2.end(), [](int a, int b) { return (a > b); }); // using my own lambda

	for (int i : numbers2)
	{
		std::cout << i << ' ';
	}

	return 0;
}
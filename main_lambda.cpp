#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>
#include <functional>
#include <string>

// returns a lambda
auto makeDog(const std::string& name)
{
	// capture name by reference and return the lambda
	return [&]() {
		std::cout << "\n I am a dog, my name is " << name << '\n'; // undefined behavior
	};
}

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
	std::cout << '\n';
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
	std::cout << '\n';
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
	std::cout << '\n';
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
	std::cout << '\n';
	std::array<int, 10> numbers2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::sort(numbers2.begin(), numbers2.end(), std::greater{}); // using standard library
	// std::sort(numbers2.begin(), numbers2.end(), [](int a, int b) { return (a > b); }); // using my own lambda

	for (int i : numbers2)
	{
		std::cout << i << ' ';
	}


	/*
	* Exercise 1
	* Use std::max_element to find the student with the most points
	*/
	std::cout << '\n';
	struct Student
	{
		std::string name{};
		int points{};
	};

	std::array<Student, 8> students {
	  { { "Albert", 3 },
		{ "Ben", 5 },
		{ "Christine", 2 },
		{ "Dan", 8 }, // Dan has the most points (8).
		{ "Enchilada", 4 },
		{ "Francis", 1 },
		{ "Greg", 3 },
		{ "Hagrid", 5 } }
	};

	const auto bestStudent{ std::max_element(students.begin(), students.end(),
		[](const Student& s1, const Student& s2) { return (s1.points < s2.points); }) };

	std::cout << "\nBest student is: " << bestStudent->name << " with " << bestStudent->points << " points\n";


	/*
	* Exercise 2
	* Use std::sort to sort the seasons by ascending average temperature
	*/
	std::cout << '\n';
	struct Season
	{
		std::string_view name{};
		double averageTemperature{};
	};

	std::array<Season, 4> seasons{
	{ { "Spring", 285.0 },
	  { "Summer", 296.0 },
	  { "Fall", 288.0 },
	  { "Winter", 263.0 } }
	};

	std::sort(seasons.begin(), seasons.end(),
		[](const Season& s1, const Season& s2) { return (s1.averageTemperature < s2.averageTemperature); });

	for (const auto& season : seasons)
	{
		std::cout << season.name << "\t: " << season.averageTemperature << '\n';
	}


	/*
	* Capture clause
	* It is used to (indirectly) give a lambda access to a variable outside the lambda
	* 
	* Indirectly because the lambda will not access the variable outside
	* By default the variable will be passed as const value, so the labda can not modify it
	*/
	std::cout << '\n';

	// Use mutable keyword to 'remove' the const qualification.So the lambda can modify the capture
	std::cout << "Capture mutable\n";
	int ammo{ 10 };

	auto shootMutable{
		[ammo]() mutable {
			--ammo; // now we can modify the capture variable
			std::cout << "Pew! " << ammo << " shot(s) left\n";
		}
	};

	/*
	* Because capture variables are members of the lambda, their values are persisted across multiple calls
	* The lambda modify its own capture variable but not the original variable value!
	*/
	shootMutable(); // prints 9
	shootMutable(); // prints 8
	std::cout << ammo << " shot(s) left\n"; // prints 10

	// Using capture by reference allow us to modify the original value
	std::cout << "\nCapture reference\n";
	auto shootReference{
		[&ammo]() {
			--ammo;
			std::cout << "Pew! " << ammo << " shot(s) left\n";
		}
	};

	shootReference(); // prints 9
	std::cout << ammo << " shot(s) left\n"; // prints 9

	/*
	* Default captures help us to define how the variables used in the lambda will be passed in
	* so we don't need to list one by one in the capture clause
	* 
	* To capture all used variables by value, use a capture value of =
	* To capture all used variables by reference, use a capture value of &
	*/
	std::array areas{ 100, 25, 121, 40, 56 };

	// mock user input
	int width{ 10 };
	int height{ 10 };

	auto areaFoundByValue{ std::find_if(areas.begin(), areas.end(),
		[=](int knownArea) { // '=' used so the lambda will capture variables width and height by value
			return (width * height == knownArea); // because they are used here
		}) };

	/*
	* We also can declare a new variable that is only visible in the scope of the lambda
	* Here we calculate the area before we can search for it in the array
	*/
	auto areaFound{ std::find_if(areas.begin(), areas.end(),
		// userArea is a new variable declared only in the scope of the lambda
		// the type is automatically deduced to int
		[userArea{ width * height }](int knownArea) {
			return (userArea == knownArea);
		}) };


	/*
	* Dangling captured variables
	* It happens when a variable is captured by reference dies before the lambda
	* So the lembda will be left holding a dangling reference
	*/
	std::cout << "\nDangling captured variables\n";

	// std::string dogName{ "Amarelinho" };

	// sayDogName is the lambda returned by makeDog
	auto sayDogName{ makeDog("Amarelinho") };
	// because the name of the dog is a string literal, the call to makeDog creates a temporary std::string
	// this string dies when makeDog returns but the lambda still references it
	// then when we call sayDogName() the dangling reference is accessed, causing undefined behavior
	sayDogName();


	/*
	* Copies of mutable lambdas
	* Lambdas are objects so they can be copied and copies will have the same state as the originals
	* After the copy is done, each lambda will have its variables
	*/
	std::cout << "\nCopies of mutable lambdas\n";
	int i{ 0 };

	auto count{ [i]() mutable { std::cout << ++i << '\n'; } };

	// invoke the lambda count
	count(); // prints 1

	auto otherCount{ count }; // create a copy of lambda count

	count(); // prints 2
	otherCount(); // prints 2 because when otherCount was created the 'i' variable of count was 2

	return 0;
}
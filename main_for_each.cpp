#include <iostream>
#include <string>

int main()
{
	constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	// ideal case to use the 'auto' keyword
	for (auto elem : fibonacci)
	{
		std::cout << elem << ' ';
	}

	std::cout << '\n';

	std::string names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily" };
	// using reference is good here so we don't need to copy each element iterated
	// and we can modify the element
	for (auto& elem : names)
	{
		elem = "igor";
		std::cout << elem << ' ';
	}

	std::cout << '\n';

	// use const if only need to read
	for (const auto& elem : names)
	{
		std::cout << elem << ' ';
	}

	return 0;
}
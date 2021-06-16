#include <iostream>

int getInteger()
{
	std::cout << "Enter an integer: ";
	int n{};
	std::cin >> n;
	return n;
}
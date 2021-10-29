#include <iostream>

#include "add.h"
#include "input.h"
#include "constants.h"

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << "The sum is: " << add(x, y) << "\n\n";

	std::cout << "const gravity value from a header file: " << constants::gravity << '\n';
	std::cout << "const PI value from a header file: " << constants::pi << '\n';

	return 0;
}
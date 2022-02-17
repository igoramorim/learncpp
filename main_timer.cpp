#include <iostream>
#include <algorithm> // for std::sort
#include <array>
#include <cstddef> // for std::size_t
#include <numeric> // for std::iota

#include "timer.h"

int main()
{
	std::array<int, 10000> array;
	std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1
	
	Timer timer;

	std::sort(array.begin(), array.end());

	std::cout << "Time taken: " << timer.elapsed() << " seconds\n";

	return 0;
}
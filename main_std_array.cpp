#include <iostream>
#include <array>
#include <algorithm> // std::sort

template <typename T, std::size_t size>
void printArray(const std::array<T, size>& arr)
{
	for (auto element : arr)
		std::cout << element << ' ';
	std::cout << '\n';
}

int main()
{
	// std::array clean up itself when it goes out of scope. no need to clean it manually

	std::array<int, 2> arr = { 2, 3 };
	std::cout << arr[1] << '\n';

	std::array arr2 = { 1.0f, 2.0f }; // omit type and size -> C++ 20
	// at() checks bounding index
	arr2.at(0) = 10.5f;
	std::cout << arr2.at(0) << '\n';
	// arr.at(10) = 1.0f; // throw error. index does not exists

	std::array<int, 5> arr3;
	arr3 = { 0, 1, 2, 3, 4 };
	arr3 = { 10, 11, 12 }; // elements 3 and 4 are set to zero

	// because std::array doesn’t decay to a pointer when passed to a function,
	// the size() function will work even if you call it from within a function
	std::cout << "Array 3 has length: " << arr3.size() << '\n';

	// sorting using the algorith header
	std::sort(arr3.begin(), arr3.end()); // sort forwards
	std::sort(arr3.rbegin(), arr3.rend()); // sort backwards

	printArray(arr3);
	
	return 0;
}
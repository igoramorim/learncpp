#include <iostream>
#include <algorithm>
#include <array>
#include <functional> // std::greater

bool isEven(int num)
{
	std::cout << "calling isEvent(num) num: " << num << std::endl;
	return num % 2 == 0;
}

bool greater(int a, int b)
{
	std::cout << "calling greater(a, b) a: " << a << " b: " << b << std::endl;
	return (a > b);
}

void doubleNumber(int& num)
{
	std::cout << "calling doubleNumber(num) num: " << num << std::endl;
	num *= 2;
}

template <typename T, std::size_t size>
void printArray(const std::array<T, size>& arr)
{
	for (auto element : arr)
		std::cout << element << ' ';
	std::cout << "\n\n";
}

int main()
{

	std::array arr{ 15, 2, 93, 42, 157 };

	/*
	* std::find
	* searches for the first ocurrence of a value in a container
	* it returns an iterator pointing to the element (if it is found) or the end of the container (it its not found)
	*/
	int valueToFound{ 2 };
	auto foundValue{ std::find(arr.begin(), arr.end(), valueToFound) };

	if (foundValue == arr.end())
		std::cout << "element " << valueToFound << " not found" << std::endl;
	else
		std::cout << "element " << valueToFound << " found" << std::endl;

	printArray(arr);

	// =========================================================================

	/*
	* std::find_if
	* searches for an element that matches some condition
	* we pass in a callable object, such as a function pointer that will be called for every element in the container
	* until the first match
	*/
	auto foundEven{ std::find_if(arr.begin(), arr.end(), isEven) };

	if (foundEven == arr.end())
		std::cout << "array does not have even numbers" << std::endl;
	else
		std::cout << "even number found:  " << *foundEven << std::endl;

	printArray(arr);

	// =========================================================================

	/*
	* std::count and std::count_if
	* search for all occurrences of an element or an element fullfilling a condition
	*/
	auto countEven{ std::count_if(arr.begin(), arr.end(), isEven) };
	std::cout << "array has " << countEven << " even numbers" << std::endl;
	printArray(arr);

	// =========================================================================

	/*
	* std::sort
	* with a custom 'sorter'
	*/
	std::sort(arr.begin(), arr.end(), greater); // we can also replace greater by std::greater{}
	printArray(arr);

	// =========================================================================

	/*
	* std::for_each
	* it applies some function to every element in the container
	*/
	std::for_each(arr.begin(), arr.end(), doubleNumber);
	printArray(arr);

	// =========================================================================

	/*
	* std::ranges
	* since C++20, we don't have to use begin() and end().
	*/
	std::ranges::for_each(arr, doubleNumber);
	printArray(arr);

	// =========================================================================

	return 0;
}
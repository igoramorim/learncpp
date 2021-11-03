#include <iostream>
#include <vector>

// std::vector keeps track os its length
template <typename T>
void printLength(const std::vector<T>& arr)
{
	std::cout << "Vector has length: " << arr.size() << "\n\n";
}

template <typename T>
void printValues(const std::vector<T>& arr)
{
	for (const auto& elem : arr)
		std::cout << elem << ' ';
	
	std::cout << '\n';
}

int main()
{
	// std::vector deallocates memory automatically when the vector goes out of scope

	std::vector<int> arr1;
	arr1 = { 2, 4, 6, 8 };

	std::vector<int> arr2 = { 1, 2, 3, 4, 5 };
	printValues(arr2);
	printLength(arr2);
	// resizing a vector
	arr2.resize(10); // fill the new slots with default value of the type, wich is 0 for int
	printValues(arr2);
	printLength(arr2);
	arr2.resize(2);
	printValues(arr2);
	printLength(arr2);

	std::vector arr3 = { 1, 2, 3, 4, 5 };
	arr3[1];	 // no bounds checking
	arr3.at(1);  // bounds checking

	// initialize a vector with defaul values
	std::vector<int> arr4(5);
	printValues(arr4);
	printLength(arr4);

	// compacting booleans
	// std::vector will compact 8 booleans into one byte behind the scenes
	std::vector<bool> arr5 { true, false, true, false, false, true, true, false };
	printValues(arr5);
	printLength(arr5);

	return 0;
}
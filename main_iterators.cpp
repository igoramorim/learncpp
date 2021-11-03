#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>

int main()
{
	/*
	An iterator is an object designed to traverse through a container (e.g. the values in an array, or the characters in a string),
	providing access to each element along the way
	*/

	std::array arr{ 1, 2, 3, 4 };
	
	/*
		pointer as iterator
	*/
	// arr.end() is not the last element. it is the next memory 'spot' after que last element of the array
	
	for (auto ptr = &arr[0]; ptr != (&arr[0] + std::size(arr)); ptr++)
	// for (auto ptr = arr.begin(); ptr != arr.end(); ptr++)  // same as above
	{
		std::cout << *ptr << ' ';
	}

	std::cout << std::endl;
	
	// =====================================================================

	std::vector<int> vec{ 1, 2, 3, 4 };

	/*
	how a for ranged based loop works?

		for (int value : vec)
			...

	the types used in a ranged based loop provides a begin() and a end() function that return an iterator at a particular position
	*/

	// a for ranged based loop works like this
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	// =====================================================================

	/*
	example for an iterator on a data type that does not store the data 'side by side' so we cant use an index to traverse all data
	*/

	// unordered_map has the begin() and end() function iterators but how we access the data is different because it actually stores
	// two data. the Key and the Value
	std::unordered_map<std::string, int> map;
	map["Igor"] = 28;
	map["Joao"] = 89;

	using TestMap = std::unordered_map<std::string, int>;
	for (TestMap::const_iterator it = map.begin(); it != map.end(); it++)
	{
		// the iterator for unordered map uses a std::pair so thats why the first / second
		auto& key = it->first;
		auto& value = it->second;
		std::cout << key << " = " << value << std::endl;
	}

	// we can also write this cleaner version
	for (auto kv : map)
	{
		auto& key = kv.first;
		auto& value = kv.second;
		std::cout << key << " = " << value << std::endl;
	}

	// even better
	for (auto [key, value] : map)
	{
		std::cout << key << " = " << value << std::endl;
	}

	// =====================================================================

	return 0;
}
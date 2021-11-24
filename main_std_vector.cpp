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

void printStack(std::vector<int>& stack)
{
	for (auto element : stack)
		std::cout << element << ' ';
	std::cout << "(capacity: " << stack.capacity() << " length: " << stack.size() << ")\n";
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

	/*
	* size() vs capacity()
	* size (length) is how many elements are being used in the array
	* capacity is how many elements were allocated in memory
	* the capacity os guaranteed to be at least as large as the array length (but could me larger)
	*/
	std::vector<int> arr6{ 0, 1, 2, 3, 4 };
	// here the length and capacity are 5
	std::cout << "Length: " << arr6.size() << " Capacity: " << arr6.capacity() << '\n';
	arr6 = { 0, 1, 2 };
	// here the length is 3 and capacity is 5. it did not reallocate its memory (capacity is still 5)
	std::cout << "Length: " << arr6.size() << " Capacity: " << arr6.capacity() << "\n\n";
	// arr6[3]; // Error. [] operator is based on the length not capacity

	/*
	* stack behavior with std::vector
	* push_back() pushes an element on the stack.
	* back() returns the value of the top element on the stack.
	* pop_back() pops an element off the stack.
	*/
	std::vector<int> stack{};

	// reserve() is used to set up the capacity to (at least) 3
	// without reserve() the vector will be resized from a capacity of 0 to 1, 1 to 2 and 2 to 3
	// and resizing a vector is expensive
	stack.reserve(3);

	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(7);
	printStack(stack);

	std::cout << "top: " << stack.back() << '\n';

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.push_back(1);
	stack.push_back(2);
	stack.push_back(3);
	stack.push_back(4);
	stack.push_back(5);
	// when we use push_back to add a new element, our vector only needed room for 5 elements
	// but it was allocated room for 6. This was done so the vecthat if we were to push_back() another element,
	// it wouldn’t need to resize immediately.
	// will print capacity: 6 and length: 5
	printStack(stack);

	return 0;
}
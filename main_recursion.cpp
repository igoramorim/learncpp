#include <iostream>
#include <vector>

/*
* a recursive function without a termination condition will cause a stack overflow
* the computer will run out of stack memory because every function call causes data to be place on the call stack.
* because countDownToStackOverflow() never return (it just call itself again), the function is never being popped off the stack!
*/
void countDownToStackOverflow(int count)
{
	std::cout << "push " << count << '\n';
	countDownToStackOverflow(count - 1);
}

// recursive function with a termination condition
void countDown(int count)
{
	std::cout << "push " << count << '\n';

	// termination condition
	if (count > 1)
		countDown(count - 1);

	std::cout << "pop " << count << '\n';
}

// interesting to debug and see the call stack
int fibonacci(int count, int& timesCalled)
{
	timesCalled++;

	if (count == 0)
		return 0; // termination condition

	if (count == 1)
		return 1; // termination condition

	return fibonacci(count - 1, timesCalled) + fibonacci(count - 2, timesCalled);
}

/*
* A better version using memoization. Memoization caches the result of expensive function calls
* so the result can be returned when the same input occurs again
* That will reduce the amount of function calls
*/
int fibonacciMemoization(int count, int& timesCalled)
{
	// we already know that 0 and 1 will show up in the beginning
	static std::vector<int> results{ 0, 1 };
	timesCalled++;

	// if we've already seen this count, then use the cached result
	if (count < static_cast<int>(std::size(results)))
	{
		return results[count];
	}
	else
	{
		// otherwise calculate the new result and add it
		results.push_back(fibonacciMemoization(count - 1, timesCalled) + fibonacciMemoization(count - 2, timesCalled));
		return results[count];
	}
}

int factorial(int num)
{
	if (num <= 0)
	{
		return 1;
	}
	else
	{
		return factorial(num - 1) * num;
	}
}

int sumDigits(int num)
{
	if (num < 10)
		return num;
	else
	{
		int rest = num % 10;
		return sumDigits(num / 10) + rest;
	}
}

void printBin(unsigned int num)
{
	if (num > 1)
		printBin(num / 2);

	std::cout << num % 2;
}

int main()
{
	// countDownToStackOverflow(5); // run this to generate an stack overflow error

	countDown(3);

	std::cout << "\nFibonacci\n";
	int timesCalledFibonnaci{ 0 };
	for (int i{ 0 }; i < 13; ++i)
	{
		// fibonacci() will be called 1205 times
		std::cout << fibonacci(i, timesCalledFibonnaci) << ' ';
	}
	std::cout << "\nCalled: " << timesCalledFibonnaci << " times\n";


	std::cout << "\n\nFibonacci with memoization\n";
	int timesCalledFibonnaciMemoization{ 0 };
	for (int i{ 0 }; i < 13; ++i)
	{
		// fibonacci() will be called 35 times
		std::cout << fibonacciMemoization(i, timesCalledFibonnaciMemoization) << ' ';
	}
	std::cout << "\nCalled: " << timesCalledFibonnaciMemoization << " times\n";


	std::cout << "\n\nFactorial\n";
	for (int i{ 0 }; i < 7; ++i)
	{
		std::cout << "factorial of " << i << ": " << factorial(i) << '\n';
	}

	std::cout << "\n\Sum of digits\n";
	int num1 = 357;
	std::cout<< "Sum of the digits " << num1 << " is: " << sumDigits(num1);

	std::cout << "\n\n\Int to Bin\n";
	int num2 = -15;
	std::cout << "Integer " << num2 << " to binary is: ";
	printBin(static_cast<unsigned int>(num2));

	return 0;
}
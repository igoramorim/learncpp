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
int fibonacciNotEfficient(int count)
{
	if (count == 0)
		return 0; // termination condition

	if (count == 1)
		return 1; // termination condition

	return fibonacciNotEfficient(count - 1) + fibonacciNotEfficient(count - 2);
}

/*
* A better version using memoization. Memoization caches the result of expensive function calls
* so the result can be returned when the same input occurs again
* That will reduce the amount of function calls
*/
int fibonacciMoreEfficient(int count)
{
	// we already know that 0 and 1 will show up in the beginning
	static std::vector<int> results{ 0, 1 };

	// if we've already seen this count, then use the cached result
	if (count < static_cast<int>(std::size(results)))
	{
		return results[count];
	}
	else
	{
		// otherwise calculate the new result and add it
		results.push_back(fibonacciMoreEfficient(count - 1) + fibonacciMoreEfficient(count - 2));
		return results[count];
	}
}

int main()
{
	// countDownToStackOverflow(5); // run this to generate an stack overflow error

	countDown(3);

	for (int i{ 0 }; i < 13; ++i)
	{
		// fibonacciNotEfficient() will be called 1205 times
		std::cout << fibonacciNotEfficient(i) << ' ';
	}

	std::cout << '\n';

	for (int i{ 0 }; i < 13; ++i)
	{
		// fibonacciNotEfficient() will be called 35 times
		std::cout << fibonacciMoreEfficient(i) << ' ';
	}

	return 0;
}
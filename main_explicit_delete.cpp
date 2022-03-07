#include <iostream>
#include <cassert>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	// Default constructor
	/*explicit*/ Fraction(int numerator = 0, int denominator = 1)
		: m_numerator(numerator), m_denominator(denominator)
	{
		assert(denominator != 0);
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
	int getNumerator() { return m_numerator; }
	void setNumerator(int numerator) { m_numerator = numerator; }
};

void printFraction(const Fraction& f)
{
	std::cout << f;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}

class Foo
{
private:
	int m_int{};
	double m_double{};

public:
	Foo(int value) : m_int{ value } {}

	Foo(double) = delete; // 'delete' makes any use of this constructor a compiler error
};

int main()
{
	/*
	* printFraction() expects a Fraction but it works because C++ treats any constructor as an implicit conversion operator
	* And Fraction has a constructor that works with only one integer
	* 
	* If this implicit conversion is not desired we can use the keyword 'explicit' in the constructor
	*/
	printFraction(6);

	Foo fooInt{ 2 };

	// Foo fooDouble{ 2.0 }; // Gives compiler error because of the keyword 'delete' in the double constructor 

	return 0;
}
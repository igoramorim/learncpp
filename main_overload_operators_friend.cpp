#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents) : m_cents{ cents }	{}

	int getCents() const { return m_cents; }

	// Add two Cents using a friend functions
	friend Cents operator+(const Cents& c1, const Cents& c2);

	// Add Cents and an int value using a friend functions
	friend Cents operator+(const Cents& c1, int value);

	// Add an int value and Cents using a friend functions
	friend Cents operator+(int value, const Cents& c1);
};

Cents operator+(const Cents& c1, const Cents& c2)
{
	// Use the Cents constructor and operator+(int, int)
	// We can access m_cents directly because this is a friend function
	
	// Even there is no Cents(Cents cents) constructor we can return like this because
	// every class has a copy constructor that takes its own class as param
	return { c1.m_cents + c2.m_cents };
}

Cents operator+(const Cents& c1, int value)
{
	return { c1.m_cents + value };
}

Cents operator+(int value, const Cents& c1)
{
	return { c1.m_cents + value };
}

class MinMax
{
private:
	int m_min{}; // The min value seen so far
	int m_max{}; // The max value seen so far

public:
	MinMax(int min, int max)
	{
		m_min = min;
		m_max = max;
	}

	int getMin() const { return m_min; }
	int getMax() const { return m_max; }

	friend MinMax operator+(const MinMax& m1, const MinMax& m2);
	friend MinMax operator+(const MinMax& m, int value);
	friend MinMax operator+(int value, const MinMax& m);
};

MinMax operator+(const MinMax& m1, const MinMax& m2)
{
	// Get the minimum value seen in m1 and m2
	int min{ m1.m_min < m2.m_min ? m1.m_min : m2.m_min };

	// Get the maximum value seen in m1 and m2
	int max{ m1.m_max > m2.m_max ? m1.m_max : m2.m_max };

	return { min, max };
}

MinMax operator+(const MinMax& m, int value)
{
	// Get the minimum value seen in m and value
	int min{ m.m_min < value ? m.m_min : value };

	// Get the maximum value seen in m and value
	int max{ m.m_max > value ? m.m_max : value };

	return { min, max };
}

MinMax operator+(int value, const MinMax& m)
{
	// call operator+(MinMax, int)
	return { m + value };
}

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int num, int den = 1) : m_numerator{ num }, m_denominator{ den } {}

	void print()
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}

	//friend Fraction operator*(const Fraction& f, int value);
	//friend Fraction operator*(int value, const Fraction& f);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
};

//Fraction operator*(const Fraction& f, int value)
//{
//	return { f.m_numerator * value, f.m_denominator };
//}

//Fraction operator*(int value, const Fraction& f)
//{
//	return { f * value };
//}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

int main()
{
	// Simple overloading operator+
	Cents cents1{ 6 };
	Cents cents2{ 2 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	// Overloading operator+ with different types ( Cents, int )
	Cents centsSumValue{ cents1 + 2 };
	std::cout << "I have " << centsSumValue.getCents() << " cents.\n";

	Cents centsSumValue2{ 2 + cents1 };
	std::cout << "I have " << centsSumValue2.getCents() << " cents.\n";

	// ===============================================================================
	// Example implementing operators using other operators
	MinMax m1{ 10, 15 };
	MinMax m2{ 8, 11 };
	MinMax m3{ 3, 12 };

	// Evaluates to mFinal = (((((m1 + m2) + 5) + 8) + m3) + 16)
	MinMax mFinal{ m1 + m2 + 5 + 8 + m3 + 16 };

	std::cout << "Result: (" << mFinal.getMin() << ", " << mFinal.getMax() << ")\n";

	// ===============================================================================
	// Quizz
	Fraction f1{ 2, 5 };
	f1.print();

	Fraction f2{ 3, 8 };
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} *Fraction{2, 3} *Fraction{3, 4} };
	f6.print();

	return 0;
}
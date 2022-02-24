#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

	friend bool operator==(const Fraction& f1, const Fraction& f2);
	friend bool operator!=(const Fraction& f1, const Fraction& f2);

	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f1, const Fraction& f2);

	friend bool operator<=(const Fraction& f1, const Fraction& f2);
	friend bool operator>=(const Fraction& f1, const Fraction& f2);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

bool operator==(const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
	// We can reuse operators to make it simple
	// Reused operator ==
	return !(operator==(f1, f2));
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
	return (f1.m_numerator * f2.m_denominator < f2.m_numerator * f1.m_denominator);
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
	// Reused operator <
	return operator<(f2, f1);
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
	// Reused operator >
	return !(operator>(f1, f2));
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
	// Reused operator <
	return !(operator<(f1, f2));
}

/*
* ================================================================================================
*/

class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(const std::string& make, const std::string& model)
		: m_make{ make }, m_model{ model }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Car& car);

	friend bool operator==(const Car& c1, const Car& c2);
	friend bool operator!=(const Car& c1, const Car& c2);

	friend bool operator<(const Car& c1, const Car& c2);
};

std::ostream& operator<<(std::ostream& out, const Car& car)
{
	out << "(" << car.m_make << ", " << car.m_model << ")\n";
	return out;
}

bool operator==(const Car& c1, const Car& c2)
{
	return (c1.m_make == c2.m_make && c1.m_model == c2.m_model);
}

bool operator!=(const Car& c1, const Car& c2)
{
	return (c1.m_make != c2.m_make || c1.m_model != c2.m_model);
}

bool operator<(const Car& c1, const Car& c2)
{
	// If the car is the same
	if (c1.m_make == c2.m_make)
		// Compare the model
		return c1.m_model < c2.m_model;
	else
		return c1.m_make < c2.m_make;
}

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';

	std::vector<Car> cars{
		{ "Toyota", "Corolla" },
		{ "Honda", "Accord" },
		{ "Toyota", "Camry" },
		{ "Honda", "Civic" }
	};

	std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

	for (const auto& car : cars)
		std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;
}
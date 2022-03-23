#include <iostream>
#include <cassert>

class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	// Default constructor
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator(numerator), m_denominator(denominator)
	{
		assert(denominator != 0);
	}

	// Copy constructor
	Fraction(const Fraction& copy)
		: m_numerator{ copy.m_numerator }, m_denominator{ copy.m_denominator }
	{
		// no need to check for a denominator of 0 here since copy must already be a valid Fraction
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

	// Overloaded assignment
	Fraction& operator= (const Fraction& fraction);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}

// A simplistic implementation of operator= (see better implementation below)
Fraction& Fraction::operator= (const Fraction& fraction)
{
	// do the copy
	m_numerator = fraction.m_numerator;
	m_denominator = fraction.m_denominator;

	// return the existing object so we can chain this operator
	return *this;
}

// ================================================================================

class MyString
{
private:
	char* m_data{};
	int m_length{};

public:
	MyString(const char* data = nullptr, int length = 0)
		: m_length{ length }
	{
		if (length)
		{
			m_data = new char[length];

			for (int i{ 0 }; i < length; ++i)
				m_data[i] = data[i];
		}
	}
	~MyString()
	{
		delete[] m_data;
	}

	// Overloaded assignment
	MyString& operator= (const MyString& str);

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	out << s.m_data;
	return out;
}

// A simplistic implementation of operator= (do not use)
MyString& MyString::operator= (const MyString& str)
{
	// Self-assignment check (pointer comparison)
	// Remove it to self-assignment fails and prints garbage
	if (this == &str)
		return *this;

	// 1. if data exists in the current string, delete it
	if (m_data) delete[] m_data;

	m_length = str.m_length;

	// 2. copy the data from str to the implicit object
	m_data = new char[str.m_length];

	for (int i{ 0 }; i < str.m_length; ++i)
		m_data[i] = str.m_data[i];

	// return the existing object so we can chain this operator
	return *this;
}

/*
* The assignment operator (operator=) is used to copy values from one object to another already existing object
* 
* Assignment vs Copy constructor
* The purpose of the copy constructor and the assignment operator are almost equivalent -- both copy one object to another
* However, the copy constructor initializes new objects, whereas the assignment operator replaces the contents of existing objects
*/
int main()
{
	Fraction fiveThirds{ 5, 3 };
	Fraction f;
	f = fiveThirds; // calls overloaded assignment
	f = f; // self-assignment has no overall impact for Fraction
	std::cout << f;

	MyString alex{ "Alex", 5 }; // Meet Alex
	alex = alex; // Sel-assignment can be dangerours when the operator = needs to dynamically allocate memory
	/*
	* Prints garbage because the implicity object (alex) and the passed in parameter (also alex) both points to the same object
	* So when 'delete[] m_data' run we are deleting the string we wanted to copy (1)
	* Then, when we allocate new memory (2) we are copying garbage
	*/
	std::cout << alex;

	// MyString employee;
	// employee = alex; // Alex is our newest employee
	// std::cout << employee; // Say your name, employee

	MyString s{ s };

	return 0;
}
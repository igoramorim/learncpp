#include <iostream>
#include <cassert>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
        assert(denominator != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

class Something
{
private:
    int m_value{};

public:
    // Default constructor
    Something(int value) : m_value{ value }
    {
    }

    // Copy constructor
    Something(const Something& other) : m_value(other.m_value)
    {
        std::cout << "Something copy constructor!\n";
    }

    int getValue() { return m_value; }

    void setValue(int value) { m_value = value; }

    friend std::ostream& operator<<(std::ostream& out, const Something& some);
};

std::ostream& operator<<(std::ostream& out, const Something& some)
{
    out << some.m_value;
    return out;
}

Something makeNegative(Something some) // ideally we should do this by const reference
{
    some.setValue(-some.getValue());
    return some;
}

int main()
{
    int x(5); // Direct initialize an integer
    Fraction fiveThirds(5, 3); // Direct initialize a Fraction, calls Fraction(int, int) constructor

    int y{ 5 }; // Uniform initialization of an integer
    Fraction fiveThirds2{ 5, 3 }; // Uniform initialization of a Fraction, calls Fraction(int, int) constructor

    int z = 6; // Copy initialize an integer
    Fraction six = Fraction(6); // Copy initialize a Fraction, will call Fraction(6, 1)
    Fraction seven = 7; // Copy initialize a Fraction. The compiler will try to find a way to convert 7 to a Fraction, which will invoke the Fraction(7, 1) constructor.

    // Direct initialize -- with what constructor?
    /*
    * A copy constructor is a special type of constructor used to create a new object as a copy of an existing object. 
    * And much like a default constructor, if you do not provide a copy constructor for your classes, C++ will create a public copy constructor for you
    * 
    */
    Fraction fCopy{ fiveThirds };
    std::cout << fCopy << '\n';

    Something some{ 1 }; // Uniform initializtion. Calls default constructor

    // Did not call copy constructor. Compiler did elision
    Something some2{ Something{ 2 } };

    Something some3{ 10 };
    /*
    * The call to makeNegative uses the Somethings copy constructor two times;
    * 1. We are passing by value, so we are making a copying here
    * 2. We are returning by value, so we are making another copying there
    */
    std::cout << makeNegative(some3);

	return 0;
}
#include <iostream>

class MyCents
{
private:
    int m_cents{};

public:
    MyCents(int cents)
        : m_cents(cents)
    {
    }

    // Without overloading operator < the function template max doesn't know how to compare two Cents objects
    friend bool operator<(const MyCents& c1, const MyCents& c2)
    {
        return (c1.m_cents < c2.m_cents);
    }

    friend std::ostream& operator<<(std::ostream& ostr, const MyCents& c)
    {
        ostr << c.m_cents;
        return ostr;
    }

    // Without overloading operator += the function template average doesn't know what to do with something like Cents += Cents
    MyCents& operator+=(const MyCents& cents)
    {
        m_cents += cents.m_cents;
        return *this;
    }

    // Without overloading operator /= the function template average doesn't know what to do with something like Cents /= 5
    MyCents& operator/=(int x)
    {
        m_cents /= x;
        return *this;
    }
};

template <typename T>
const T& max(const T& x, const T& y)
{
    return (x < y) ? y : x;
}

template <typename T>
T average(const T* myArray, int numValues)
{
    T sum{ 0 };
    for (int count{ 0 }; count < numValues; ++count)
        sum += myArray[count];

    sum /= numValues;
    return sum;
}

int main()
{
    MyCents nickel{ 5 };
    MyCents dime{ 10 };

    MyCents bigger = max(nickel, dime);
    std::cout << "MyCents: " << bigger << " is bigger\n";


    // Function average works just fine for built-in types
    int intArray[]{ 5, 3, 2, 1, 4 };
    std::cout << average(intArray, 5) << '\n';

    double doubleArray[]{ 3.12, 3.45, 9.23, 6.34 };
    std::cout << average(doubleArray, 4) << '\n';

    // Function average works just fine with Cents after overloading operators += and /=
    MyCents centsArray[]{ MyCents { 5 }, MyCents { 10 }, MyCents { 15 }, MyCents { 14 } };
    std::cout << average(centsArray, 4) << '\n';


    // The great thing about these function tempaltes is that we didn't have to modify them to work with our custom types
    // We just had to define the operators in our custom types to make it work

	return 0;
}
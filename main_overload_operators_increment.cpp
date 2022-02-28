#include <iostream>

class Digit
{
private:
    int m_digit;

public:
    Digit(int digit = 0)
        : m_digit{ digit }
    {
    }

    // No parameter means this is prefix operator++
    Digit& operator++()
    {
        // If our number is already at 9, wrap around to 0
        if (m_digit == 9)
            m_digit = 0;
        // otherwise just increment to next number
        else
            ++m_digit;

        return *this;
    }

    // No parameter means this is prefix operator--
    Digit& operator--()
    {
        // If our number is already at 0, wrap around to 9
        if (m_digit == 0)
            m_digit = 9;
        // otherwise just decrement to next number
        else
            --m_digit;

        return *this;
    }

    /* The postfix operators need to return the state of the object before it is incremented or decremented
     * Note that this means the return value of the overloaded operator must be a non-reference, because we
     * can’t return a reference to a local variable that will be destroyed when the function exits
     * Also note that this means the postfix operators are typically less efficient than the prefix operators
     * because of the added overhead of instantiating a temporary variable and returning by value instead of reference
     * 
     * int (dummy) parameter means this is postfix operator++
     * because the dummy parameter is not used in the function implementation, we have not even given it a name
    */
    Digit operator++(int)
    {
        // Create a temporary variable with our current digit
        Digit temp{ *this };

        // Use prefix operator to increment this digit
        ++(*this); // apply operator

        // return temporary result
        return temp; // return saved state
    }

    // int parameter means this is postfix operator--
    Digit operator--(int)
    {
        // Create a temporary variable with our current digit
        Digit temp{ *this };

        // Use prefix operator to decrement this digit
        --(*this); // apply operator

        // return temporary result
        return temp; // return saved state
    }

    friend std::ostream& operator<< (std::ostream& out, const Digit& d);
};

std::ostream& operator<< (std::ostream& out, const Digit& d)
{
    out << d.m_digit;
    return out;
}

int main()
{
    Digit digit(5);

    std::cout << digit << '\n';
    std::cout << ++digit << '\n'; // calls Digit::operator++();
    std::cout << digit++ << '\n'; // calls Digit::operator++(int);
    std::cout << digit << '\n';
    std::cout << --digit << '\n'; // calls Digit::operator--();
    std::cout << digit-- << '\n'; // calls Digit::operator--(int);
    std::cout << digit << '\n';

    return 0;
}
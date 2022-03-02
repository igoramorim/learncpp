#include <iostream>

class MyDollars;

class MyCents
{
private:
    int m_cents;

public:
    MyCents(int cents = 0)
        : m_cents{ cents }
    {
    }

    // Overloaded int cast
    operator int() const { return m_cents; }

    // Convert Cents into Dollars
    operator MyDollars() const;

    int getCents() const { return m_cents; }

    friend std::ostream& operator<<(std::ostream& out, const MyCents& cents);
};

std::ostream& operator<<(std::ostream& out, const MyCents& cents)
{
    out << cents.getCents();
    return out;
}

class MyDollars
{
private:
    int m_dollars;

public:
    MyDollars(int dollars = 0)
        : m_dollars{ dollars }
    {
    }

    MyDollars(MyCents cents) : m_dollars{cents.getCents() / 100}
    {
    }

    // Convert Dollars into Cents
    operator MyCents() const { return MyCents{ m_dollars * 100 }; }

    int getDollars() const { return m_dollars; }

    friend std::ostream& operator<<(std::ostream& out, const MyDollars& dollars);
};

std::ostream& operator<<(std::ostream& out, const MyDollars& dollars)
{
    out << dollars.getDollars();
    return out;
}

// Defining here after the the MyDollars
/*MyCents::operator MyDollars() const
{
    return MyDollars{ m_cents / 100 };
}*/

int main()
{
    MyDollars dollars{ 5 };

    MyCents cents{ 900 };

    std::cout << "Cents: " << cents << " cast to int: " << static_cast<int>(cents) << '\n';

    std::cout << "Dollars: " << dollars << " cast to Cents: " << static_cast<MyCents>(dollars) << '\n';

    /*
    * It only worked because of the constructor MyDollars(MyCents cents)
    * So MyCents::operator MyDollars() const is not necessary
    * 
    * static_cast<MyDollars>(cents) should not work just like static_cast<int>(cents) ?
    * If I remove the constructor MyDollars(MyCents cents) and uncomment the MyCents::operator MyDollars() const
    * I get Error C2440 'static_cast': cannot convert from 'MyCents' to 'MyDollars'
    */
    std::cout << "Cents: " << cents << " cast to Dollars: " << static_cast<MyDollars>(cents) << '\n';

	return 0;
}

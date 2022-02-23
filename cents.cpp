#include "cents.h"

Cents::Cents(int cents) : m_cents{ cents }
{

}

int Cents::getCents() const
{
	return m_cents;
}

// This is not a member function nor a friend function!
Cents operator+(const Cents& c1, const Cents& c2)
{
	// use the Cents constructor and operator+(int, int)
	// we don't need direct access to private members here because we have getCents()
	return { c1.getCents() + c2.getCents() };
}
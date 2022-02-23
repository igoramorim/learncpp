#pragma once

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents);

	int getCents() const;
};

// Prototype for overloading operator+
Cents operator+(const Cents& c1, const Cents& c2);

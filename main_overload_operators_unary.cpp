#include <iostream>

class Point
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{

	}

	// Overloading operator -
	// Convert a point to its negative values
	Point operator-() const
	{
		return { -m_x, -m_y, -m_z };
	}

	// Overloading operator !
	// Return true if the point is set at the origin (0.0, 0.0, 0.0), false otherwise
	bool operator!() const
	{
		return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
	}

	friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
	// return std::ostream so we can chain calls to operator<<
	return out;
}

int main()
{
	Point point{}; // use default constructor to set to (0.0, 0.0, 0.0)

	std::cout << point << '\n';
	std::cout << -point << '\n';

	if (!point)
		std::cout << "point is set at the origin.\n";
	else
		std::cout << "point is not set at the origin.\n";

	return 0;
}
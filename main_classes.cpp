#include <iostream>
#include <assert.h>
#include <array>

class Point3D
{
private:
	int m_x {};
	int m_y {};
	int m_z {};

public:
	// Default constructor
	Point3D()
	{
		m_x = 1;
		m_y = 1;
		m_z = 1;
	}
	// Consctructor with parameters and one param having a default value
	Point3D(int x, int y, int z = 1)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void setValues(int x, int y, int z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void print()
	{
		std::cout << '<' << m_x << ", " << m_y << ", " << m_z << ">\n";
	}

	// Because the param is also a Point3D we can access the private properties directly
	bool isEqual(const Point3D& p)
	{
		return (m_x == p.m_x) && (m_y == p.m_y) && (m_z == p.m_z);
	}
};

class Stack
{
public:
	void reset()
	{
		m_idx = 0;
	}

	// Returns false if the array is already full. true otherwise
	bool push(int value)
	{
		if (m_array.size() == m_idx)
		{
			return false;
		}

		m_array[m_idx] = value;
		m_idx++;
		return true;
	}

	int pop()
	{
		// Must check if the array is empty via an assert
		assert(m_idx > 0 && "Can not pop an empty stack!");

		auto value{ m_array[m_idx - 1] };
		m_array[m_idx - 1] = 0;
		m_idx--;

		return value;
	}

	void print()
	{
		std::cout << "( ";
		for (size_type i{ 0 }; i < m_idx; i++)
		{
			std::cout << m_array[i] << ' ';
		}
		std::cout << " )\n";
	}

private:
	using array_type = std::array<int, 10>;
	using size_type = array_type::size_type;

	array_type m_array {};
	size_type m_idx { 0 };
};

class Something
{
private:
	int m_value1; // Note no {} initialization
	int m_value2;

public:
	// Create a default constructor that will zero initialize member variables
	// even if they not been initialized at their declaration
	Something() = default;

	void print()
	{
		std::cout << "Class Something value1: " << m_value1 << " value2: " << m_value2 << '\n';
	}
};

int main()
{
	Point3D point1;
	point1.setValues(1, 2, 3);
	point1.print();

	Point3D point2;
	point2.setValues(1, 2, 3);
	point2.print();

	std::cout << "point1 and point2 are equal: " <<  point1.isEqual(point2) << "\n";

	Point3D point3; // Calls default constructor
	point3.print();

	Point3D point4 {}; // Also calls default constructor
	point4.print();

	Point3D point5 { 10, 5, 0 }; // Calls constructor with parameters
	point5.print();

	Point3D point6{ 10, 5 }; // Calls constructor with parameters and using one default (z)
	point6.print();

	Point3D point7(10, 5); // Also calls constructor with parameters
	point7.print();

	Something something{}; // Calls default constructor
	something.print();

	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.push(5);

	stack.print();
	
	stack.push(3);
	stack.print();

	stack.reset();
	stack.push(99);
	stack.print();


	return 0;
}
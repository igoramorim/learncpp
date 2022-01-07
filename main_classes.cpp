#include <iostream>
#include <assert.h>
#include <array>
#include <string>
#include <cstdint> // for fixed-width integers

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

class Rectangle
{
private:
	double m_length{ 1.0 }; // default values
	double m_width{ 1.0 };

public:
	Rectangle(double length, double width) :
		m_length{ length },
		m_width{ width }
	{
		// m_length and m_width are initialized by the constructor (the default values aren't used)
	}

	Rectangle(double length) : m_length{ length }
	{
		// m_length is initialized by the constructor.
		// m_width's default value (1.0) is used.
	}

	void print()
	{
		std::cout << "length: " << m_length << " width: " << m_width << '\n';
	}
};

class Ball
{
private:
	std::string m_color{ "black" };
	double m_radius{ 10.0 };

public:
	
	// Default constructor with no parameters
	Ball() = default;

	// Constructor with only radius parameter (color will use default value)
	Ball(double radius) : m_radius{ radius }
	{

	}

	// Constructor with only color parameter (radius will use default value)
	Ball(const std::string& color) : m_color{ color }
	{

	}

	// Constructor with both color and radius parameters
	Ball(const std::string& color, double radius) : m_color{ color }, m_radius{ radius }
	{

	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

class RGBA
{
public:
	using comp_type = std::uint_fast8_t;

private:
	comp_type m_red{ 0 };
	comp_type m_green{ 0 };
	comp_type m_blue{ 0 };
	comp_type m_alpha{ 255 };

public:
	RGBA(comp_type red, comp_type green, comp_type blue, comp_type alpha) :
		m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
	{

	}

	RGBA(comp_type red, comp_type green, comp_type blue) :
		m_red{ red }, m_green{ green }, m_blue{ blue }
	{

	}

	void print()
	{
		std::cout <<   "R= " << static_cast<int>(m_red)
			      << "\tG= " << static_cast<int>(m_green)
			      << "\tB= " << static_cast<int>(m_blue)
			      << "\tA= " << static_cast<int>(m_alpha)
			      << '\n';
	}
};

class Foo
{
private:

public:
	// Constructor that does some default setup initialization
	Foo()
	{
		std::cout << "Constructor Foo()\n";
	}

	// Constructor that calls the default constructor from the member initializer list to do the 'default setup'
	// before doing another stuff
	Foo(int value) : Foo{}
	{
		std::cout << "Constructor Foo(int value)\n";
	}
};

class Bar
{
private:
	int m_value1{ 1 };
	int m_value2{ 2 };

public:
	Bar() = default;

	Bar(int val1, int val2) : m_value1{ val1 }, m_value2{ val2 }
	{

	}

	void print()
	{
		std::cout << "Class Bar value1: " << m_value1 << "\tvalue2: " << m_value2 << '\n';
	}

	void reset()
	{
		*this = Bar(); // create a new Bar object and then overwrite our implicit object (replace the object by a new instance of the same class)
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

	Rectangle rec1{ 2.0, 3.0 }; // Non-static member initialization
	rec1.print();

	Rectangle rec2{ 4.0 }; // Non-static member initialization
	rec2.print();

	Ball defaultBall;
	defaultBall.print();

	Ball blueBall{ "blue" };
	blueBall.print();

	Ball twentyRadiusBall{ 20.0 };
	twentyRadiusBall.print();

	Ball blueTwentyBall{ "blue", 20.0 };
	blueTwentyBall.print();

	RGBA purple{ 142, 52, 245, 255 };
	purple.print();

	RGBA alsoPurple{ 142, 52, 245 };
	alsoPurple.print();

	Foo foo{ 1 }; // Delegating constructors

	Bar bar1{ 50, 100 }; // Resetting a class to some default state
	bar1.print();
	bar1.reset();
	bar1.print();

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
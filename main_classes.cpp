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

	void setValue1(int value) { m_value1 = value; }
	int getValue1() { return m_value1; }

	void print()
	{
		std::cout << "Class Something value1: " << m_value1 << " value2: " << m_value2 << '\n';
	}
};

class SomethingElse
{
private:
	int m_value;
	static inline int s_idGenerator{ 1 };
	int m_id{ };

public:
	static int s_value; // non-const static member variable must be defined outside the class
	static const int s_value2{ 2 }; // static const can be defined in the class
	static constexpr int s_value3{ 3 }; // static constexpr can be defined in the class
	static inline int s_value4{ 4 }; // we can use inline to define a static non-const member

public:
	SomethingElse() : m_value{ 0 }, m_id{ s_idGenerator++ } {}

	void setValue(int value) { m_value = value; }
	int getValue() const { return m_value; }
	int getId() const { return m_id; }
	static int getIdGenerator() { return s_idGenerator; }
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

class Value
{
private:
	int m_value{};

public:
	Value(int value) : m_value{ value } {}

	// A friend function can access private member variables directly
	// Note that the function definition is outside the class
	friend bool isEqual(const Value& v1, const Value& v2);
};

class HelloWorld
{
private:
	char* m_data{};

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char* init{ "Hello, World!" };
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		// replace this comment with your destructor implementation
		delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data << '\n';
	}

};

bool isEqual(const Value& v1, const Value& v2)
{
	// Here we are access a private member variable of Value directly because isEqual is a friend function of the Value class
	return (v1.m_value == v2.m_value);
}

/*
* Because static member variables are not part of the individual class objects (like global variables)
* We define it outside the class, in global scope
*/
int SomethingElse::s_value{ 1 };

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

	const SomethingElse somethingConst; // Const class
	// somethingConst.setValue(2); // Does not compile because the function modifies a member value
	// somethingConst.getValue(); // Also does not compile even though the function does not modify the member value
	
	// This works because the function is marked const. It guarantees it will not modify the object or call any non-const member function
	somethingConst.getValue();


	SomethingElse somethingElse1;
	SomethingElse somethingElse2;
	// Because s_value is a static member value it is shared between all objects of the class
	// It is not associated with class objects
	somethingElse1.s_value = 2;

	std::cout << somethingElse1.s_value << '\n';
	std::cout << somethingElse2.s_value << '\n';
	std::cout << SomethingElse::s_value << '\n'; // Static members can be accessed directly like this. We don't need an instance of the class

	// An example of static member can be used to assign a unit ID to every instance of the class
	std::cout << "SomethingElse id: " << somethingElse1.getId() << '\n';
	std::cout << "SomethingElse id: " << somethingElse2.getId() << '\n';

	std::cout << "SomethingElse id generator: " << SomethingElse::getIdGenerator() << '\n';

	// Friend functions
	Value v1{ 1 };
	Value v2{ 1 };
	std::cout << "Friend functions | isEqual: " << std::boolalpha << isEqual(v1, v2) << '\n';

	HelloWorld hello{};
	hello.print();

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct StudentGrade
{
	std::string name{};
	char grade{};
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map{};

public:
	char& operator[](const std::string& name)
	{
		const auto studentFound{ std::find_if(m_map.begin(), m_map.end(),
			// & to pass the function param to the lambda via reference
			// const auto& student is the object the lambda will work on
			[&](const auto& student) { return student.name == name; }) };

		// if the student is found
		if (studentFound != m_map.end())
		{
			// use the -> operator because studentFound is an iterator and return the grade
			return studentFound->grade;
		}

		// otherwise push a new student
		m_map.push_back({ name });
		// std::vector::back() returns the last element
		// returns a reference to the grade of the student we just pushed back
		return m_map.back().grade;
	}
};

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::sort

struct Student
{
	std::string name;
	unsigned int grade;
};

bool compareGrades(Student& st1, Student& st2)
{
	return (st1.grade > st2.grade);
}

void printStudents(const std::vector<Student>& students)
{
	for (const auto& student : students)
		std::cout << student.name << "\tgot a grade of\t" << student.grade << std::endl;

	std::cout << std::endl;
}

unsigned int getNumberOfStudents()
{
	unsigned int numberOfStudents{};

	do
	{
		std::cout << "How many students would you like to enter? ";
		std::cin >> numberOfStudents;
	} while (numberOfStudents <= 0);
	
	std::cout << std::endl;
	return numberOfStudents;
}

std::vector<Student> getStudents()
{
	unsigned int studentsAmount{ getNumberOfStudents() };
	
	std::vector<Student> students(studentsAmount);

	for (int i{ 1 }; auto& student : students)
	{
		// Ignore the line feed that was left by std::cin.
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Enter students name" << "\t#" << i << ": ";
		std::getline(std::cin, student.name);

		std::cout << "Enter students grade" "\t#" << i << ": ";
		std::cin >> student.grade;
		i++;
		std::cout << std::endl;
	}

	return students;
}

int main()
{
	auto students{ getStudents() };

	std::sort(students.begin(), students.end(), compareGrades);

	printStudents(students);

	return 0;
}
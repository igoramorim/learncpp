#include <iostream>

struct Person
{
	unsigned int age{};
	double weight{};
};

int main()
{
	Person person{};
	person.age = 5; // 'normal' member selection with .

	Person& ref{ person };
	ref.age = 10; // also works for references

	Person* ptr{ &person };
	// same as (*ptr).age = 15
	ptr->age = 15; // for pointers member selection use -> (arrow) operator

	return 0;
}
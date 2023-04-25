#include "Person.h"

Person::Person(void)
{
	name = "";
	age = 0;
}

Person::Person(std::string N, int A)
{
	name = N;
	age = A;
}

Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}

void Person::set_name(std::string N)
{
	name = N;
}

void Person::set_age(int A)
{
	age = A;
}

Person& Person::operator=(const Person& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

void Person::Show()
{
	std::cout << "\nNAME: " << name;
	std::cout << "\nAGE: " << age;
	std::cout << "\n";
}

void Person::Input()
{
	std::cout << "\nName: "; std::cin >> name;
	std::cout << "\nAge: "; std::cin >> age;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			Show(); 
			break;
		}
	}
}
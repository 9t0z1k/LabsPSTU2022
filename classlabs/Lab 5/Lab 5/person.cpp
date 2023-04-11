#include <iostream>
#include "person.h"
#include <string>

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

Person::Person(const Person&p)
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

Person& Person::operator=(const Person&p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

std::istream& operator>>(std::istream& in, Person& t)
{ 
	std::cout << "\nName: "; in >> t.name;
	std::cout << "\nAge: "; in >> t.age;
	return in;
}

std::ostream& operator<<(std::ostream& out, Person& t)
{
	std::cout << "\nNAME: " << t.name;
	std::cout << "\nAGE: " << t.age;
	std::cout << "\n";
	return out;
}

void Person::Show()
{
	std::cout << "\nNAME: " << name;
	std::cout << "\nAGE: " << age;
	std::cout << "\n";
}
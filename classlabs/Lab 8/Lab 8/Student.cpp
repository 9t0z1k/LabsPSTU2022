#include "Student.h"
#include <iostream>

Student::Student(void) : Person()
{
	subject = "";
	grade = 0;
}

Student::Student(std::string N, int A, std::string S, int G) : Person(N, A)
{
	subject = S;
	grade = G;
}

Student::Student(const Student& c)
{
	name = c.name;
	age = c.age;
	subject = c.subject;
	grade = c.grade;
}

void Student::set_subject(std::string S)
{
	subject = S;
}

void Student::set_grade(int G)
{
	grade = G;
}

Student& Student::operator=(const Student& c)
{
	if (&c == this) return *this;
	name = c.name;
	age = c.age;
	subject = c.subject;
	grade = c.grade;
	return *this;
}

void Student::Show()
{
	std::cout << "\nName: " << name;
	std::cout << "\nAge: " << age;
	std::cout << "\nSubject: " << subject;
	std::cout << "\nGrade: " << grade;
	std::cout << "\n";
}

void Student::Input()
{
	std::cout << "\nName: "; std::cin >> name;
	std::cout << "\nAge: "; std::cin >> age;
	std::cout << "\nSubject: "; std::cin >> subject;
	std::cout << "\nGrade: "; std::cin >> grade;
}
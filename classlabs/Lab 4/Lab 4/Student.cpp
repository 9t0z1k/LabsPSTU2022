#include "Student.h"
#include <iostream>

Student::Student(void) : Person()
{
	subject = "";
	grade = 0;
}

Student::Student(std::string N, int A, std::string S, int G): Person(N,A)
{
	subject = S;
	grade = G;
}

Student::Student(const Student&c)
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

Student& Student::operator=(const Student&c)
{
	if (&c == this) return *this;
	name = c.name;
	age = c.age;
	subject = c.subject;
	grade = c.grade;
	return *this;
}

void Student::succsess(int G)
{
	if (G <= 2 && G >= 0)
		std::cout << "Your grade is bad!\n";
	else if (G > 2 && G <= 5)
		std::cout << "Your grade is good!\n";
	else
		std::cout << "Incorrect grade.\n";
}

std::istream& operator>>(std::istream& in, Student& s)
{
	std::cout << "\nName: "; in >> s.name;
	std::cout << "\nAge: "; in >> s.age;
	std::cout << "\nSubject: "; in >> s.subject;
	std::cout << "\nGrade: "; in >> s.grade;
	return in;
}

std::ostream& operator<<(std::ostream& out, Student& s)
{
	std::cout << "\nName: " << s.name;
	std::cout << "\nAge: " << s.age;
	std::cout << "\nSubject: " << s.subject;
	std::cout << "\nGrade: " << s.grade;
	std::cout << "\n";
	s.succsess(s.grade);
	return out;
}

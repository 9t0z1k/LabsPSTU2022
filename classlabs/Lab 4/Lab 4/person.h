#pragma once
#include <string>
#include <iostream>

class Person {
protected:
	std::string name;
	int age;
public:
	Person(void);
	Person(std::string, int);
	Person(const Person&);
	~Person() {};
	std::string get_name() { return name; }
	int get_age() { return age; }
	void set_name(std::string);
	void set_age(int);
	Person& operator=(const Person&);
	friend std::istream& operator>>(std::istream& in, Person& t);
	friend std::ostream& operator<<(std::ostream& out, Person& t);
};
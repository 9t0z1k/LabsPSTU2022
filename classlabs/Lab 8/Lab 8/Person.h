#pragma once

#include <string>
#include <iostream>
#include "Object.h"

class Person : public Object {
public:
	Person(void);
	Person(std::string, int);
	Person(const Person&);
	virtual ~Person() {};
	void Show();
	void Input();
	std::string get_name() { return name; }
	int get_age() { return age; }
	void set_name(std::string);
	void set_age(int);
	Person& operator=(const Person&);
	void HandleEvent(const TEvent& e);
	int AvgAge() { return age; }
protected:
	std::string name;
	int age;
};
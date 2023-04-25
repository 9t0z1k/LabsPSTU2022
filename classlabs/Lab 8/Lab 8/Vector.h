#pragma once
#include "Student.h"
#include <string>
#include <iostream>

class Vector
{
public:
	Vector(void);
	Vector(int);
	~Vector(void);
	void Add(Object* p);
	void Add_C();
	void Del();
	void Show();
	int operator ()();
	friend std::ostream& operator <<(std::ostream& out, const Vector&);
	virtual void HandleEvent(const TEvent& e);
	void AvgAge();
protected:
	Object** beg;
	int size;
	int cur;
};


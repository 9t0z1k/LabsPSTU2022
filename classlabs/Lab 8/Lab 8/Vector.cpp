#include "Vector.h"
#include <iostream>

Vector::Vector(void)
{
	beg = 0;
	size = 0;
	cur = 0;
}
Vector::~Vector()
{
	if (beg != 0) delete[] beg;
	beg = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

void Vector::Add_C()
{
	Object* a;
	std::cout << "Who u need to add?\n";
	std::cout << "1. Person\n";
	std::cout << "2. Student\n";
	
	int ch;
	std::cin >> ch;
	
	switch (ch)
	{
		case 1:
		{
			Person* p = new Person();
			p->Input();
			a = p;
			Add(a);
			break;
		}
		case 2:
		{
			Student* s = new Student();
			s->Input();
			a = s;
			Add(a);
			break;
		}
		default:
		{
			std::cout << "Wrong num\n";
			break;
		}
	}

}

void Vector::Show()
{
	if (size == 0)
		std::cout << "Empty\n";
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		++p;
	}
}

void Vector::Del()
{
	if (cur == 0)
		return;
	cur--;
}

int Vector::operator()()
{
	return size;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty\n";
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}

void Vector::AvgAge()
{
	int a = 0;
	if (cur == 0)
	{
		std::cout << "Empty!\n";
		return;
	}
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		a += (*p)->AvgAge();
		p++;
	}
	std::cout << "Average age is: " << a / cur << '\n';
}
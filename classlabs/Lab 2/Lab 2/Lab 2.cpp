#include <iostream>
#include "Salary.h"
using namespace std;

Salary make_Salary()
{
	string n;
	int r;
	double fs;
	cout << "Enter name: "; cin >> n;
	cout << "Enter reward: "; cin >> r;
	cout << "Enter first salary: "; cin >> fs;
	Salary t(n, r, fs);
	return t;
}

void print_salary(Salary t)
{
	t.show();
}

int main()
{
	Salary t1;
	t1.show();
	Salary t2("Ivan", 10, 10000);
	t2.show();
	Salary t3 = t2;
	t3.set_name("Petr");
	t3.set_reward(5);
	t3.set_f_salary(15000);
	print_salary(t3);
	t1 = make_Salary();
	t1.show();

	return 0;
}

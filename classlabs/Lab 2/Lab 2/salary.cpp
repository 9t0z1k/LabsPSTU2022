#include "salary.h"
#include <iostream>

Salary::Salary()
{
	name = "";
	reward = 0;
	f_salary = 0;
	std::cout << "Constructor without parameters: " << this << endl;
}

Salary::Salary(string N, int R, double FS)
{
	name = N;
	reward = R;
	f_salary = FS;
	std::cout << "Constructor with parameters:" << this << endl;
}

Salary::Salary(const Salary &s)
{
	name = s.name;
	reward = s.reward;
	f_salary = s.f_salary;
	std::cout << "Constructor's Copy: " << this << endl;
}

Salary::~Salary()
{
	cout << "Destructor: " << this << endl;
}

string Salary::get_name()
{
	return name;
}

int Salary::get_reward()
{
	return reward;
}

double Salary::get_f_salary()
{
	return f_salary;
}

void Salary::set_name(string N)
{
	name = N;
}

void Salary::set_reward(int R)
{
	reward = R;
}

void Salary::set_f_salary(double FS)
{
	f_salary = FS;
}

void Salary::show()
{
	std::cout << "\nName: " << name << endl;
	std::cout << "Reward: " << reward << endl;
	std::cout << "First Salary: " << f_salary << endl;

}
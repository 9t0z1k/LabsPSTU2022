#pragma once
#include <string>
using namespace std;

class Salary
{
	string name;
	int reward;
	double f_salary;
public:
	Salary();
	Salary(string, int, double);
	Salary(const Salary&);
	~Salary();
	string get_name();
	void set_name(string);
	int get_reward();
	void set_reward(int);
	double get_f_salary();
	void set_f_salary(double);
	void show();
};
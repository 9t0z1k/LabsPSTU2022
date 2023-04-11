#pragma once
#include <iostream>

class Pair
{
	int first;
	double second;
	double C;
public:
	Pair() { first = 0; second = 0; C = 0; }
	Pair(int f, int s, int c) { first = f; second = s; C = c; }
	Pair(const Pair& t) { first = t.first, second = t.second; C = t.C; }
	~Pair() {};
	int get_first() { return first; }
	double get_second() { return second; }
	double get_C() { return C; }
	void set_first(int f) { first = f; }
	void set_second(double s) { second = s; }
	double set_C(double c) { C = c; }
	Pair& operator=(const Pair&);
	Pair operator-(const Pair&);
	Pair operator+(double)const;
	friend std::istream& operator>>(std::istream& in, Pair& t);
	friend std::ostream& operator<<(std::ostream& out, Pair& t);
};
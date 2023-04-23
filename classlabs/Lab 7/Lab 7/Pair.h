#pragma once
#include <iostream>

class Pair
{
public:
	int fNum = 0;
	double sNum = 0;
	Pair() {}
	Pair(int first, double second) {
		fNum = first;
		sNum = second;
	}

	Pair& operator=(const Pair& t);
	Pair& operator=(const int &t);
	Pair operator*(Pair&t);
	friend std::ostream& operator<<(std::ostream &out, const Pair &t);
	friend std::istream& operator>>(std::istream& in, const Pair& t);
};
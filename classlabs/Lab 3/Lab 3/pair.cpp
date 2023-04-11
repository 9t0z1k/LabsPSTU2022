#include "pair.h"
#include <iostream>


Pair& Pair::operator=(const Pair&t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	C = t.C;
	return *this;
}

Pair Pair::operator-(const Pair&t)
{
	Pair s;
	s.first = first - t.first;
	s.second = second - t.second;
	return s;
}

Pair Pair::operator+(double C) const
{
	Pair s;
	if (C == (int)C) {
		s.first = first + (int)C;
		s.second = second;
	}
	else {
		s.second = second + C;
		s.first = first;
	}
	return s;
}

std::istream& operator>>(std::istream&in, Pair&t)
{
	std::cout << "First? "; in >> t.first;
	std::cout << "Second? "; in >> t.second;
	return in;
}

std::ostream& operator<<(std::ostream & out, Pair &t)
{
	return (out << t.first << " : " << t.second  << "\n");
}

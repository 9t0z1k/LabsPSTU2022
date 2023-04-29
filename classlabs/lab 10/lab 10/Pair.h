#pragma once
#include <iostream>
#include <string>
#include <fstream>

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
	Pair& operator=(const int& t);
	Pair operator+(double) const;
	Pair operator-(Pair& t) const;
	Pair operator+(const Pair& p) const;
	Pair operator*(Pair& t);
	friend std::ostream& operator<<(std::ostream& out, const Pair& t)
	{
		out << t.fNum << " : " << t.sNum;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Pair& t)
	{
		in >> t.fNum >> t.sNum;
		return in;
	}

	friend std::fstream& operator <<(std::fstream& fout, const Pair& t)
	{
		fout << t.fNum << " : " << t.sNum << "\n";
		return fout;
	}
	friend std::fstream& operator>>(std::fstream& fin, Pair& t)
	{
		fin >> t.fNum;
		fin >> t.sNum;
		return fin;
	}
	friend bool operator<(const Pair& lhs, const Pair& rhs) {
		return lhs.fNum < rhs.fNum || (lhs.fNum == rhs.fNum && lhs.sNum < rhs.sNum);
	}

	friend bool operator>(const Pair& lhs, const Pair& rhs) {
		return rhs < lhs;
	}

	friend bool operator<=(const Pair& lhs, const Pair& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>=(const Pair& lhs, const Pair& rhs) {
		return !(lhs < rhs);
	}

	friend bool operator==(const Pair& lhs, const Pair& rhs) {
		return lhs.fNum == rhs.fNum && lhs.sNum == rhs.sNum;
	}

	friend bool operator!=(const Pair& lhs, const Pair& rhs) {
		return !(lhs == rhs);
	}
};

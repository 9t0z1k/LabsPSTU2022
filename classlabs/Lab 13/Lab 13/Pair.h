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
	friend Pair& operator+=(Pair& p1, Pair& p2) { p1.fNum += p2.fNum; p1.sNum += p2.sNum; return p2; }
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
	friend bool operator<(const Pair& le, const Pair& re) {
		return le.fNum < re.fNum || (le.fNum == re.fNum && le.sNum < re.sNum);
	}

	friend bool operator>(const Pair& le, const Pair& re) {
		return re < le;
	}

	friend bool operator<=(const Pair& le, const Pair& re) {
		return !(re < le);
	}

	friend bool operator>=(const Pair& le, const Pair& re) {
		return !(le < re);
	}

	friend bool operator==(const Pair& le, const Pair& re) {
		return le.fNum == re.fNum && le.sNum == re.sNum;
	}

	friend bool operator!=(const Pair& le, const Pair& re) {
		return !(le == re);
	}
};

#include "Pair.h"


Pair& Pair::operator=(const Pair& pair) {
	this->fNum = pair.fNum;
	this->sNum = pair.sNum;
	return *this;
}

Pair& Pair::operator=(const int& t) {
	this->fNum = t;
	this->sNum = t;
	return *this;
}

Pair Pair::operator*(Pair& pair) {
	Pair new_pair;
	new_pair.fNum = this->fNum * pair.fNum;
	new_pair.sNum = this->sNum * pair.sNum;
	return new_pair;
}

Pair Pair::operator+(double C) const
{
	Pair s;
	if (C == (int)C) {
		s.fNum = fNum + (int)C;
		s.sNum = sNum;
	}
	else {
		s.sNum = sNum + C;
		s.fNum = fNum;
	}
	return s;
}

Pair Pair::operator-(Pair& t) const
{
	Pair temp = *this;
	temp.fNum -= t.fNum;
	temp.sNum -= t.sNum;
	return temp;
}

Pair Pair::operator+(const Pair& p) const {
	Pair result = *this;
	result.fNum += p.fNum;
	result.sNum += p.sNum;
	return result;
}
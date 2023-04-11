#include <iostream>
#include "fraction.h"

void fraction::Init(double F, int S, int J)
{
	first = F;
	second = S;
	j = J;
}

void fraction::Read()
{
	std::cout << "\nfirst?  "; std::cin >> first;
	std::cout << "\nsecond?  "; std::cin >> second;
	std::cout << "\nelem j?  "; std::cin >> j;
	std::cout << std::endl;
}

int fraction::Power()
{
	return pow(second,j);
}

double fraction::element()
{
	return first * Power();
}
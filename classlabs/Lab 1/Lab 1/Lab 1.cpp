#include <iostream>
#include "fraction.h"

using namespace std;

fraction make_fraction(double F, int S, int aj)
{
	fraction t;
	t.Init(F, S, aj);
	return t;
}

int main()
{
	fraction find;

	find.Read();
	cout << "element(R) j is: " << find.element() << endl;

	fraction F = make_fraction(1,2,3);
	cout << "element(MF) j is: " << find.element();


	return 0;
}

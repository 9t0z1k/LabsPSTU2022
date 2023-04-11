#include "Object.h"
#include "person.h"
#include "Student.h"
#include "Vector.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	Vector v(5);
	Person a;
	cin >> a;
	Student b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;

	return 0;
}

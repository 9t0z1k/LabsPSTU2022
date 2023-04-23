#include "List.h"
#include <iostream>
#include "Pair.h"

using namespace std;


int main()
{
	Pair p(2, 3.4);
	List<Pair> l;
	cout << "Made a empty list: ";
	l.print();
	cout << "List size: " << l.list_size() << "\n";
	cout << "Add pair to list: ";
	l.push_back(p);
	l.print();
	cout << "in index 0 elem is: " << l[0];
	cout << "\nList size: " << l.list_size();
	cout << "\n";
	Pair p1(3, 2.3);
	List<Pair> l1;
	l1.push_back(p1);
	cout << "Made a new list l1: "; l1.print();
	List<Pair> l3 = l * l1;
	cout << "List l After mult:  ";
	l3.print();

	return 0;
}

#include "List.h"
#include <iostream>

using namespace std;

int main()
{
	List l;
	cout << "Made a empty list: ";
	l.print();
	cout <<"List size: " << l.list_size() << "\n";
	cout << "Add 5 to list: ";
	l.push_back(5);
	l.print();
	cout << "in index 0 elem is: " << l[0];
	cout << "\nList size: " << l.list_size();
	cout << "\nAdding two elem in list: ";
	l.push_back(34);
	l.push_back(55);
	l.print();
	cout << "List size: " << l.list_size();
	cout << "\nFirst elem in list: " << *(l.beg());
	cout << "\nLast elem in list: " << *(l.end());
	cout << "\nDelete 5 from list: ";
	l.pop(5);
	l.print();
	List l1;
	l1.push_back(5); cout << "Made a new list l1: "; l1.print();
	l[2] = l[1] * l1[0];
	cout << "List l After mult:  ";
	l.print();
	List::Iterator i;

	cout << "Checking +n operation: " << *i;

	return 0;
}


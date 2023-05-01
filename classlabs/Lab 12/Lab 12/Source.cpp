#include <iostream>
#include <set>
#include "Pair.h"
#include "ListSet.h"

using namespace std;
template<typename T>
void printSet(multiset<T> S)
{
	for (T x : S)
		cout << x << " | ";
	cout << endl;
}

//Task 1
void task1() 
{
	multiset<double> set;
	for (int i = 0; i < 6; i++)
		set.insert((double)rand() / 1000.00);
	printSet(set);
	
	//find avg
	double sum = 0;
	for (auto it = set.begin(); it != set.end(); ++it)
		sum += *it;
	
	set.insert(sum/set.size());
	printSet(set);
	
	//find key
	int d1, d2;
	cout << "Enter range from: "; cin >> d1;
	cout << " to: "; cin >> d2;
	double key;
	cout << "Enter key to delete: "; cin >> key;
	
	auto s_it = set.begin();
	advance(s_it, d1);
	auto e_it = set.begin();
	advance(e_it, d2);
	
	for (auto it = s_it; it != e_it;)
	{
		if (*it == key) set.erase(it++);
		else ++it;
	}
	
	cout << "After deleting: \n";
	printSet(set);
	
	//sum max min
	cout << "Adding sum to elems: \n";
	double MMsum = *min_element(set.begin(), set.end())
		+ *max_element(set.begin(), set.end());
	multiset<double> newSet;
	
	for (auto it = set.begin(); it != set.end(); ++it) {
		newSet.insert(*it + MMsum);
	}
	printSet(newSet);
}

//Task 2
void task2() {
	multiset<Pair> set;
	set.insert(Pair(1, 1.1));
	set.insert(Pair(2, 2.2));
	set.insert(Pair(3, 3.3));
	set.insert(Pair(4, 4.4));
	printSet(set);

	//find avg
	Pair sum(0, 0.0);
	for (auto it = set.begin(); it != set.end(); ++it)
		sum = sum + *it;
	sum.fNum /= set.size(); sum.sNum /= set.size();
	set.insert(sum);
	printSet(set);

	//find key
	int d1, d2;
	cout << "Enter range from: "; cin >> d1;
	cout << " to: "; cin >> d2;
	Pair key;
	cout << "Enter key to delete: "; cin >> key;

	auto s_it = set.begin();
	advance(s_it, d1);
	auto e_it = set.begin();
	advance(e_it, d2);

	for (auto it = s_it; it != e_it;)
	{
		if (*it == key) set.erase(it++);
		else ++it;
	}

	cout << "After deleting: \n";
	printSet(set);

	//sum max min
	cout << "Adding sum to elems: \n";
	Pair MMsum = *min_element(set.begin(), set.end())
		+ *max_element(set.begin(), set.end());
	multiset<Pair> newSet;

	for (auto it = set.begin(); it != set.end(); ++it) {
		newSet.insert(*it + MMsum);
	}
	printSet(newSet);
}

//Task 3
void task3() {
	ListSet<double> List;
	List.push(1);
	List.push(2);
	List.push(3);
	List.push(4);
	List.print();
	List.push(List.average());
	List.print();
	
	int d1, d2;
	cout << "Range: "; cin >> d1 >> d2;
	double key;
	cout << "Key: "; cin >> key;
	List.remove_range(d1,d2,key);
	List.print();

	List.add_min_max();
	List.print();
}


int main()
{
	srand(time(0));
	cout << "Results: \n";
	cout << "===================\n\n";
	cout << "------TASK1------\n";
	task1();
	/*cout << "------TASK2------\n";
	task2();*/
	cout << "------TASK3------\n";
	task3();

	return 0;
}
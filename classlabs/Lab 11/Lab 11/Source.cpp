#include<iostream>
#include <list>
#include <queue>
#include <algorithm>
#include "List.h"
#include "Pair.h"

using namespace std;

template<typename T>
void showL(list<T>& L)
{
	for (T num : L)
		cout << num << " - ";
	cout << "\n";
}

// Задание 1
void task1()
{
	list<double> container;
	for (int i = 0; i < 5; ++i) {
		double a = (double)rand() / 100.00;
		container.push_back(a);
	}
	showL(container);
	//Find avg
	double sum = 0;
	for (double num : container)
		sum += num;
	container.push_back(sum / container.size());
	cout << "Find avg and push back to container: \n";
	showL(container);
	//find elems
	int d1, d2;
	cout << "Enter range from: "; cin >> d1; 
	cout << " to: "; cin >> d2;
	double key;
	cout << "Enter key to delete: "; cin >> key;
	auto s_it = container.begin();
	advance(s_it, d1);
	auto e_it = container.begin();
	advance(e_it, d2);
	for (auto it = s_it; it != e_it; ++it)
	{
		if (*it == key) {
			container.erase(it);
			break;
		}
	}
	cout << "After deleting: \n";
	showL(container);
	//sum max min
	cout << "Adding sum to elems: \n";
	double MMsum = *min_element(container.begin(), container.end())
		+ *max_element(container.begin(), container.end());
	for (double& num : container)
		num += MMsum;
	showL(container);
}

// Задание 2
void task2()
{
	list<Pair> PP;
	PP.push_back(Pair(1, 1.1));
	PP.push_back(Pair(2, 2.2));
	PP.push_back(Pair(3, 3.3));
	PP.push_back(Pair(4, 4.4));
	showL(PP);
	//Find avg
	Pair sum (0,0.0);
	for (Pair num : PP)
		sum = num + sum;
	sum.fNum /= PP.size();
	sum.sNum /= PP.size();
	PP.push_back(sum);
	cout << "Find avg and push back to container: \n";
	showL(PP);
	//find elems
	int d1, d2;
	cout << "Enter range from: "; cin >> d1;
	cout << " to: "; cin >> d2;
	Pair key;
	cout << "Enter key to delete: "; cin >> key;
	auto s_it = PP.begin();
	advance(s_it, d1);
	auto e_it = PP.begin();
	advance(e_it, d2);
	for (auto it = s_it; it != e_it; ++it)
	{
		if (*it == key) {
			PP.erase(it);
			break;
		}
	}
	cout << "After deleting: \n";
	showL(PP);
	//sum max min
	cout << "Adding sum to elems: \n";
	Pair MMSUM = *min_element(PP.begin(), PP.end()) 
		+ *max_element(PP.begin(), PP.end());
	for (Pair& num : PP)
		num = num + MMSUM;
	showL(PP);
}

// Задание 3
void task3()
{
	List<Pair> PP;
	PP.push_back(Pair(1, 1.1));
	PP.push_back(Pair(2, 2.2));
	PP.push_back(Pair(3, 3.3));
	PP.push_back(Pair(4, 4.4));
	PP.print();
	/*showLL(PP);*/
	//Find avg
	Pair sum(0, 0.0);
	for (Pair num : PP)
		sum = sum + num;
	sum.fNum /= PP.list_size();
	sum.sNum /= PP.list_size();
	PP.push_back(sum);
	cout << "Find avg and push back to container: \n";
	PP.print();
	//find elems
	int d1, d2;
	cout << "Enter range from: "; cin >> d1;
	cout << " to: "; cin >> d2;
	Pair key;
	cout << "Enter key to delete: "; cin >> key;
	auto s_it = PP.begin();
	s_it = s_it + d1;
	auto e_it = PP.begin();
	e_it = e_it + d2;
	for (auto it = s_it; it != e_it; ++it)
	{
		if (*it == key) {
			PP.pop(*it);
			break;
		}
	}
	cout << "After deleting: \n";
	PP.print();
	//sum max min
	cout << "Adding sum to elems: \n";
	Pair max = PP[0];
	Pair min = PP[0];
	for (auto it = PP.begin(); it != PP.end(); ++it)
	{
		if (*it > max) max = *it;
		if (*it < min) min = *it;
	}
	/*Pair MMSUM = min_element(PP.begin(), PP.end())
		+ max_element(PP.begin(), PP.end());*/
	for (Pair& num : PP)
		num = num + max + min;
	PP.print();
}

// Задание 4
void task4()
{
	priority_queue<Pair> QP;
	priority_queue<Pair> QPbuf;
	QP.push(Pair(1, 1.1));
	QP.push(Pair(2, 2.2));
	QP.push(Pair(3, 3.3));
	QP.push(Pair(4, 4.4));
	//Find avg
	Pair sum(0, 0.0);
	while (!QP.empty())
	{
		cout << QP.top() << " | ";
		sum = sum + QP.top();
		QPbuf.push(QP.top());
		QP.pop();
	}
	sum.fNum /= QPbuf.size();
	sum.sNum /= QPbuf.size();
	QPbuf.push(sum);
	cout << endl;
	cout << "Find avg and push back to container: \n";
	while (!QPbuf.empty())
	{
		cout << QPbuf.top() << " | ";
		QP.push(QPbuf.top());
		QPbuf.pop();
	}
	cout << endl;
	//find elems
	int ch = 1, d1, d2;
	cout << "Enter range from: "; cin >> d1;
	cout << " to: "; cin >> d2;
	Pair key;
	cout << "Enter key to delete: "; cin >> key;
	while (!QP.empty())
	{
		if ((ch < d1 || ch > d2) || key != QP.top())
			QPbuf.push(QP.top());
		QP.pop();
		ch++;
	}
	while (!QPbuf.empty())
	{
		cout << QPbuf.top() << " | ";
		QP.push(QPbuf.top());
		QPbuf.pop();
	}
	cout << endl;
	//sum max min
	cout << "Adding sum to elems: \n";
	Pair max = QP.top();
	Pair min = QP.top();
	while(!QP.empty())
	{
		if (QP.top() > max) max = QP.top();
		if (QP.top() < min) min = QP.top();
		QPbuf.push(QP.top());
		QP.pop();
	}
	while (!QPbuf.empty())
	{
		QP.push(max + min + QPbuf.top());
		QPbuf.pop();
	}
	while (!QP.empty())
	{
		QPbuf.push(QP.top());
		cout << QP.top() << " | ";
		QP.pop();
	}
	cout << endl;
}

// Задание 5
void task5()
{
	task3();

}

int main()
{
	srand(time(NULL));
	cout << "Results: \n";
	cout << "=================\n\n";
	cout << "-------TASK1-------\n";
	task1();
	cout << "-------TASK2-------\n";
	task2();
	cout << "-------TASK3-------\n";
	task3();
	cout << "-------TASK4-------\n";
	task4();
	cout << "-------TASK5-------\n";
	task5();
	
	return 0;
}
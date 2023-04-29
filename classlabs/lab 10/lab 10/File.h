#pragma once
#include "List.h"
#include "Pair.h"
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class File
{
public:
	File(std::string fName) : fName(fName) {}
	int writeFile(List<T>& L);
	int readFile(List<T>& L);
	void insertElem(List<T>& L, int pos, int K);
	void removeLess(const T& elem);
	void AddL(T L);
private:
	std::string fName; // main file
	std::string Tfile = "temp.txt"; // temp file
};

template<typename T>
int File<T>::writeFile(List<T>& L)
{
	std::fstream stream(fName, std::ios::out | std::ios::trunc /*| std::ios::app*/);
	if (!stream) return -1;
	int n = 0;
	for (auto it = L.beg(); it != L.end(); it++)
	{
		stream << *it << "\n";
		n++;
	}
	stream.close();
	return n;

}

template<typename T>
int File<T>::readFile(List<T>& L)
{
	std::fstream stream(fName, std::ios::in);
	if (!stream) return -1;
	int n = 0;
	L.clear();
	T value; 
	while (stream >> value)
	{
		L.push_back(value);
		n++;
	}
	stream.close();
	return n;
}

template<typename T>
void File<T>::insertElem(List<T>& L,int pos, int K)
{
	std::ifstream file(fName);

	T value;
	for (int i = 0; i < K; i++) {
		std::cin >> value;
		L.insert(pos, value);
	}
	writeFile(L);
}

template<typename T>
void File<T>::removeLess(const T& elem)
{
	std::ifstream inFile(fName);
	std::ofstream outFile(Tfile);

	T value;
	while (inFile >> value)
	{
		if (value >= elem)
			outFile << value << "\n";
	}
	inFile.close();
	outFile.close();

	remove(fName.c_str());
	rename(Tfile.c_str(), fName.c_str());
}

template<typename T>
void File<T>::AddL(T L)
{
	std::ifstream inFile(fName);
	std::ofstream outFile(Tfile);
	T k;

	while (inFile >> k)
	{
		outFile << k + L << "\n";
	}
	inFile.close();
	outFile.close();
	remove(fName.c_str());
	rename(Tfile.c_str(), fName.c_str());
} 
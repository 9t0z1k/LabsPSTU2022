#include "List.h"
#include "File.h"
#include "Pair.h"
#include <iostream>
#include <string>

using namespace std;
string FILE_NAME = "List.txt";

int main()
{
    List<Pair> list(3, Pair(0, 0));
    File<Pair> file(FILE_NAME);
    list.push_back(Pair(1, 1.1));
    list.push_back(Pair(2, 2.2));
    list.push_back(Pair(3, 3.3));

    cout << "\n" << FILE_NAME << " : " << endl;
    cout << list << endl;
    file.writeFile(list);

    Pair K(2, 0.1);
    cout << "\n" << FILE_NAME << "  Pair(2,2.1) " << endl;
    file.AddL(K);
    cout << list << endl;

    cout << "\n" << FILE_NAME << "  " << endl;
    file.removeLess(Pair(0, 1.1));
    cout << list << endl;

    int n, k;
    cout << "\n" << FILE_NAME << "  " << endl;
    cin >> n >> k;
    cout << list << endl;

	return 0;
}
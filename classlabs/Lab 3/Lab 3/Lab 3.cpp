#include <iostream>
#include "pair.h"

using namespace std;


int main()
{
	Pair pair;
	cin >> pair;
	cout << pair;
	Pair pair2;
	cin >> pair2;
	cout << pair2;
	Pair res = pair - pair2;
	cout << "After substruct " << res;
	Pair C = pair + 3;
	cout <<"After add Const " << C;
	return 0;
}

#include "List.h"
#include "Error.h"

int main()
{
	try
	{

		List<int> lst;
		lst.push_back(5);
		lst.push_back(5);
		lst.push_back(5);
		lst.print();

	}
	catch (Error& err)
	{
		err.what();
	}

	return 0;
}
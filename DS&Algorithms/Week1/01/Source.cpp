#include <iostream>
#include <list>
#include <vector>
#include "MyVector.h"

using namespace std;

int main()
{
	int(10);
	try
	{
		MyVector<int> vec;

		cout << vec.at(0) << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	
	return 0;
}
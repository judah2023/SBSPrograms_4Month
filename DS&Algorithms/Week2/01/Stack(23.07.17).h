#pragma once
#include <iostream>
#include <stack>
#include "MyStack.h"

using namespace std;

int main()
{
	try
	{
		CircleQueue<int> stk1;

		stk1.Push(10);
		stk1.Push(20);
		stk1.Push(30);
		stk1.Push(40);

		while (!stk1.Empty())
		{
			cout << stk1.Top();
			stk1.Pop();
			if (!stk1.Empty())
				cout << ' ';
		}
		cout << endl;

		stk1.Top();
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
	}

	return 0;
}
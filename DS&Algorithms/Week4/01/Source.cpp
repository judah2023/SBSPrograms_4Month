#include <iostream>
#include <vector>

using namespace std;

class A
{
public:

	void Print()
	{
		cout << "A Class" << endl;
	}

	virtual A* GetThis()
	{
		return this;
	}

	void Func() {}
};

class B : public A
{
public:
	void Print()
	{
		cout << "B Class" << endl;
	}

	virtual B* GetThis()
	{
		return this;
	}
};

int main()
{
	A* a = nullptr;
	a->Func();

#pragma region Covariant_Return

	A aClass;
	B bClass;
	A* myB = new B;

	A& refA = bClass;

	bClass.GetThis()->Print();
	refA.GetThis()->Print();

	cout << typeid(bClass.GetThis()).name() << endl;
	cout << typeid(refA.GetThis()).name() << endl;
	cout << typeid(myB->GetThis()).name() << endl;

#pragma endregion


	return 0;
}
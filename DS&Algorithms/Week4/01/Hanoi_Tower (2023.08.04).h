#pragma once
#include <iostream>
#include <vector>

using namespace std;

#pragma region Hanoi_Tower

// 큰 원반이 작은 원반 위로 올라가지 못하는 규칙하에서
// 원반을 하나만 옮기면서 탑(모든 원반의 정렬집합)이 다른 기동으로 옮기는 장난감

char cnt = 0;

void HanoiTower(int n, int curr, int waypoint, int next)
{
	cnt++;
	if (n == 1)
	{
		cout << "Disk " << n << " : [ " << curr << " -> " << next << " ]" << endl;
		return;
	}

	HanoiTower(n - 1, curr, next, waypoint);
	cout << "Disk " << n << " : [ " << curr << " -> " << next << " ]" << endl;
	HanoiTower(n - 1, waypoint, curr, next);
}


#pragma endregion

#pragma region Covariant_Return

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
#pragma endregion

int main()
{

	return 0;
}

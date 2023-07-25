#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void PrintVector(const vector<T>& vec)
{
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i != 0)
			cout << ", ";
		cout << vec[i];
	}
	cout << " ]" << endl;
}

#pragma region Insert_Sort

// 두번째 자료부터 시작하여 그 앞의
// 자료들과 비교하여 삽입할 위치를 지정한 후
// 자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여 정렬하는 알고리즘

template<typename T>
void InsertSort(vector<T>& vec)
{
	int temp, j;
	for (int i = 0; i < vec.size(); i++)
	{
		if (i > 0)
		{
			temp = vec[i];
			for (j = i - 1; j >= 0; j--)
			{
				if (temp >= vec[j])
					break;

				vec[j + 1] = vec[j];
			}
			if (j + 1 != i)
				vec[j + 1] = temp;
		}

		cout << "Case " << i << "\t:  ";
		PrintVector(vec);
	}
}

#pragma endregion

#pragma region Move_Constructor

// 기존 객체의 주소 및 값을 새로운 오브젝트에 소유권을 이전시키는 생성자

class Component
{
private:
	float x;
	float y;
	int* count;

public:
	// 기본 생성자
	Component() : x(0), y(0)
	{
		cout << "Call Constructor" << endl;
		count = new int(0);
	}

	Component(float&& x, float&& y) : x(x), y(y)
	{
		cout << "Call Parameter Constructor" << endl;
		count = new int(0);
	}

	// 복사 생성자
	Component(const Component& other) : x(other.x), y(other.y)
	{
		cout << "Call Copy Constructor" << endl;
		count = new int(*other.count);
	}

	// 이동 생성자
	Component(Component&& other) noexcept : x(other.x), y(other.y)
	{
		cout << "Call Move Constructor" << endl;
		count = new int(*other.count);
		other.count = nullptr;
	}

	~Component()
	{
		if (count != nullptr)
			delete count;
	}

	void IncreseCount()
	{
		(*count)++;
	}

	friend Component operator+(Component& lhs, Component& rhs)
	{
		Component newComponent(lhs.x + rhs.x, lhs.y + rhs.y);
		for (int i = 0; i < *lhs.count + *rhs.count; i++)
			newComponent.IncreseCount();
		return newComponent;
	}

	int GetCount() const
	{
		return *count;
	}

	pair<float, float> GetCoord() const
	{
		return { x, y };
	}

};

#pragma endregion

int main()
{
	// vector<int> vec = { 100, 5, 8, 6, 1, 2, 11, 21, 12, 19, 18, 17, 10, 99, 98 };

	Component comp1;
	Component comp2(comp1);

	comp1.IncreseCount();
	comp2.IncreseCount();
	comp2.IncreseCount();

	cout << comp1.GetCount() << " " << comp2.GetCount() << endl;

	Component comp3(comp1 + comp2);

	cout << comp3.GetCount() << endl;
	cout << comp3.GetCoord().first << " " << comp3.GetCoord().second << endl;

	return 0;
}
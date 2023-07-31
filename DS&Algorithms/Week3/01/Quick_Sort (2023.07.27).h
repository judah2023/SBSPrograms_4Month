#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#pragma region Counting_Sort

// 데이터의 값을 직접 비교하는 것이 아닌 값의 개수를 저장하여 정렬하는 알고리즘
enum Constants
{
	SIZE = 10000
};

vector<int> vec(SIZE, 0);

#pragma endregion

#pragma region Quick_Sort

// 기준점을 획득한 다음 해당 기준점을 기준으로 배열을 나누고
// 한 쪽에는 기준잠보다 작은 항목들이 위치하고 다른쪽에는 기준점보다 큰 항목들이 위치한다.

// 나뉘어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여,
// 모든 배열이 기본 배열이 될 때까지 반복하는 알고리즘

void MideanToHigh(vector<int>& vec, int low, int high)
{
	int mid = (low + high) / 2;
	if (vec[low] < vec[mid])
	{
		if (vec[mid] < vec[high])
			swap(vec[mid], vec[high]);
		else if (vec[high] < vec[low])
			swap(vec[low], vec[high]);
	}
	else
	{
		if (vec[mid] > vec[high])
			swap(vec[mid], vec[high]);
		else if (vec[high] > vec[low])
			swap(vec[low], vec[high]);
	}
}

int Partition(vector<int>& vec, int low, int high)
{
	if (high - low > 1)
		MideanToHigh(vec, low, high);

	int pivot = vec[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
		if (vec[j] < pivot)
			swap(vec[++i], vec[j]);
	swap(vec[++i], vec[high]);
	return i;
}

void QuickSort(vector<int>& vec, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(vec, low, high);

		QuickSort(vec, low, pivot - 1);
		QuickSort(vec, pivot + 1, high);
	}
}

#pragma endregion

void PrintVector(vector<int>& vec)
{
	cout << "[ ";
	for (auto& it : vec)
		cout << it << " ";
	cout << "]" << endl;
}

int main()
{
	vector<int> vec = { 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	PrintVector(vec);
	QuickSort(vec, 0, vec.size() - 1);
	PrintVector(vec);

	return 0;
}
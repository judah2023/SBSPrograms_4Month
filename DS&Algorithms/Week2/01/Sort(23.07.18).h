#pragma once
#include <iostream>
#include <vector>

using namespace std;

#pragma region Bubble_Sort

// 서로 인접한 두 원소를 검사하여 정렬하는 알고리즘
// O(n^2)

template<typename Key>
void BubbleSort(vector<Key>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
		for (int j = 1; j < vec.size() - i; j++)
			if (vec[j - 1] > vec[j])
				swap(vec[j - 1], vec[j]);
}

#pragma endregion

#pragma region Selection_Sort

// 정렬되지 않은 데이터들에 대해 가장 작은 데이터를
// 가장 앞에 있는 데이터와 교환하는 알고리즘
// O(n^2)

template<typename Key>
void SelectionSort(vector<Key>& vec)
{
	int idx;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		idx = i;
		for (int j = i + 1; j < vec.size(); j++)
			if (vec[idx] > vec[j])
				idx = j;

		if (idx != i)
			swap(vec[idx], vec[i]);
	}
}

#pragma endregion

#pragma region Time_Complexity

/*

// 컴퓨터 프로그램의 입력 값과 연산 수행 시간의 상관관계의 척도

// Big-O
// 연산 수행시간의 상한을 나타내는 척도
// f = O(g) ⇔ ∃ N, c > 0 s.t. ∀x > N, |f(x)| < c|g(x)|

// O(1) : 상수 시간 복잡도
// 입력 값의 크기에 관계없이 일정한 시간이 소모되는 시간 복잡도
// ex) 배열의 임의 원소 접근

// O(n) : 선형 시간 복잡도
// 입력 값 n에 대해서 시간이 n에 비례해서 증가하는 시간 복잡도
// ex) for(int i = 0; i < n; i++) { ... }

// O(log(n))
// 입력 값 n에 대해서 시간이 log(n)에 비례해서 증가하는 시간 복잡도
// ex) 이진탐색

// O(n^2) : 2차 시간 복잡도
// 입력 값 n에 대해서 시간이 n^2에 비례해서 증가하는 시간 복잡도
// ex) 선택정렬, 버블정렬

// O(2^n) : 지수함수적 시간 복잡도
// 입력 값 n에 대해서 시간이 2^n에 비례해서 증가하는 시간 복잡도
// ex) 재귀함수


// Big-Ω
// 연산 수행시간의 하한을 나타내는 척도
// f = Ω(g) ⇔ ∃ N, c > 0 s.t. ∀x > N, c|g(x)| < |f(x)|


// Big-Θ
// Big-Ω, Big-O를 모두 만족하는 척도
// f = Θ(g) ⇔ ∃ N, c, d > 0 s.t. ∀x > N, c|g(x)| < |f(x)| < d|g(x)|

*/

#pragma endregion

template<typename Key>
void PrintVector(const vector<Key>& vec)
{
	cout << "[ ";
	for (const auto& it : vec)
		cout << it << " ";
	cout << "]" << endl;
}

int main()
{

	vector<int> vec = { 6, 2, 2, 1, 1, 12, 3, 3 };

	cout << "\nBefore sorting \t: ";
	PrintVector(vec);

	// BubbleSort(vec);
	SelectionSort(vec);

	cout << "\nAfter sorting \t: ";
	PrintVector(vec);

	return 0;
}
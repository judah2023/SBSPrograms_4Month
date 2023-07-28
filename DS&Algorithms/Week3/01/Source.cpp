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

#pragma region Hash_Table

/*
* 
// (Key, Value)로 데이터를 저장하는 자료구조 중 하나
// 해시 함수를 통해 Key 값을 정수 인덱스 값으로 변환하는 자료구조

// 데이터 탐색 시간 복잡도가 O(1) 이다.

// 해시 충돌의 해결 방법

// 체이닝
// 해시 충돌 발생 시 동일한 해시 값 인덱스에 데이터를 연렬리스트에 저장하는 방법

// 개방 주소법
// 해시 충돌 발생 시 다른 빈 인덱스에 데이터를 저장하는 방법

// 빈 버킷(인덱스)를 어떻게 결정할 지에 따라 구현 방식이 달라짐

// 선형 탐사 : 해시 값을 1씩 증가 시켜 버킷을 찾는 방법

// 이차 탐사 : 해시 값을 i^2씩 증가 시켜 버킷을 찾는 방법

// 이중 해싱 : 해시 값을 다른 해시 값을 사용하여 버킷 증가값을 설정하는 방법

*/

struct Node
{
	int key;
	int value;
	Node* next;
};

struct Bucket
{
	Node* head;
	int count;
};

class HashTable
{
	enum Constants
	{
		SIZE = 1024
	};

private:
	Bucket bucket[SIZE];

	Node* CreateNode(int key, int value)
	{
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}

	void InsertNode(Bucket& curr, Node* newNode)
	{
		newNode->next = curr.head;
		curr.head = newNode;
	}

public:

	HashTable()
	{
		for (int i = 0; i < 5; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	size_t HashFunction(int key)
	{
		size_t hash = SIZE * fmod((key * 0.6180339887), 1);
		return hash;
	}

	void Insert(int key, int value)
	{
		size_t idx = HashFunction(key);
		Node* newNode = CreateNode(key, value);
		Bucket& currBucket = bucket[idx];
		if (currBucket.count == 0)
		{
			currBucket.head = newNode;
		}
		else
		{
			InsertNode(currBucket, newNode);
		}
		currBucket.count++;
	}

};

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
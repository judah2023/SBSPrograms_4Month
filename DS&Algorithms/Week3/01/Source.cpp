#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

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
	vector<Bucket> bucket;
	list<int> keyList;
	size_t size;

	Node* CreateNode(int key, int value)
	{
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}

	void InsertNode(size_t idx, Node* newNode)
	{
		Bucket& currBucket = bucket[idx];
		if (currBucket.count != 0)
		{
			newNode->next = currBucket.head;
		}
		currBucket.head = newNode;
		currBucket.count++;
	}

public:

	HashTable()
	{
		bucket.resize(SIZE);
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
		size = 0;
	}

	~HashTable()
	{
		Clear();
	}

	size_t HashFunction(int key)
	{
		return (size_t)(SIZE * fmod((key * 0.6180339887), 1));
	}

	void Insert(int key, int value)
	{
		size_t idx = HashFunction(key);
		Node* newNode = CreateNode(key, value);
		InsertNode(idx, newNode);
		keyList.push_back(key);
		size++;
	}

	Node* Find(int key)
	{
		size_t idx = HashFunction(key);
		Node* curr = bucket[idx].head;
		while (curr != nullptr)
		{
			if (curr->key == key)
				break;
			curr = curr->next;
		}
		return curr;
	}

	void Search(int key)
	{
		Node* node = Find(key);
		if (node == nullptr)
		{
			cout << "This key(" << key << ") is Invaild!" << endl;
		}
		else
		{
			cout << "[ Key, Value ] : " << "[ " << node->key << ", " << node->value << " ]" << endl;
		}
	}

	void Remove(int key)
	{
		Node* curr = Find(key);
		if (curr == nullptr)
			return;

		size_t idx = HashFunction(key);
		if (bucket[idx].count == 1)
		{
			bucket[idx].head = nullptr;
		}
		else
		{
			Node* prev = bucket[idx].head;
			while (prev->next == curr)
			{
				prev = prev->next;
			}

			prev->next = curr->next;
		}

		size--;
		bucket[idx].count--;
		keyList.remove(curr->key);
		delete curr;
	}

	int& operator[](int key)
	{
		Node* keyNode = Find(key);
		if (keyNode == nullptr)
		{
			Insert(key, 0);
			keyNode = Find(key);
		}
		return keyNode->value;
	}

	void Clear()
	{
		int key;
		while (!keyList.empty())
		{
			key = keyList.front();
			Remove(key);
		}
	}

};

#pragma endregion

int main()
{
	HashTable hashMap;
	hashMap.Insert(1, 11);
	hashMap.Insert(2, 12);
	hashMap.Insert(3, 13);
	hashMap.Insert(4, 14);
	hashMap.Insert(5, 15);
	hashMap.Insert(6, 16);

	hashMap[100] = 100;

	hashMap.Search(1);
	hashMap.Search(2);
	hashMap.Search(3);
	hashMap.Search(4);
	hashMap.Search(5);
	hashMap.Search(6);
	hashMap.Search(100);

	hashMap.Clear();

	hashMap.Search(1);
	hashMap.Search(2);
	hashMap.Search(3);
	hashMap.Search(4);
	hashMap.Search(5);
	hashMap.Search(6);
	hashMap.Search(100);

	return 0;
}
#pragma once
#include <iostream>
#include <vector>

using namespace std;

#pragma region Heap

// 여러 값 중에서 최대값 혹은 최소값을 빠르게 찾아내기 위한 자료구조

// 최대 힙
// 루트 노드에 항상 최대값이 있는 자료구조
// 부모 노드의 값이 자식 노드의 값보다 크거나 같다

class MaxHeap
{
private:
	vector<int> heap;
	int size;

	void InsertBalance(int curr)
	{
		if (curr == 1)
			return;

		int next = curr >> 1;
		if (heap[next] >= heap[curr])
			return;

		swap(heap[next], heap[curr]);
		InsertBalance(next);
	}

	void DeleteBalance(int curr)
	{
		int next = curr << 1;
		if (next > size)
			return;

		if (next < size)
			next = (heap[next] > heap[next + 1]) ? next : next + 1;

		if (heap[curr] >= heap[next])
			return;

		swap(heap[curr], heap[next]);
		DeleteBalance(next);
	}

public:
	MaxHeap() : size(0)
	{
		heap.reserve(1025);
		heap.push_back(-1);
	}

	void Insert(int data)
	{
		heap.push_back(data);
		int curr = ++size, next = curr >> 1;

		while (curr > 1)
		{
			if (heap[next] >= heap[curr])
				break;

			swap(heap[next], heap[curr]);
			curr = next;
			next >>= 1;
		}
	}

	int Delete()
	{
		int delNum = heap[1];
		swap(heap[size--], heap[1]);
		heap.pop_back();

		int curr = 1, next = curr << 1;
		while (next <= size)
		{
			if (next < size)
				next = (heap[next] > heap[next + 1]) ? next : next + 1;

			if (heap[curr] >= heap[next])
				break;

			swap(heap[curr], heap[next]);
			curr = next;
			next <<= 1;
		}

		return delNum;
	}

	void Push(int data)
	{
		heap.push_back(data);
		int curr = ++size;

		InsertBalance(curr);
	}

	int Pop()
	{
		int delNum = heap[1], curr = 1;
		swap(heap[size--], heap[1]);
		heap.pop_back();

		DeleteBalance(curr);

		return delNum;
	}

	bool Empty()
	{
		return size == 0;
	}

	int Size()
	{
		return size;
	}
};

#pragma endregion

int main()
{
	MaxHeap heap;

	heap.Push(0);

	while (!heap.Empty())
		cout << heap.Pop() << " ";

	return 0;
}
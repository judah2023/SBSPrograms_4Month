#include <iostream>
#include <vector>
#include <queue>
#include "LinearQueue.h"
#include "UnorderedMap.h"

using namespace std;

int main()
{
#pragma region Queue

	// 선입선출(FIFO)의 자료구조
	// 들어온 순서대로 데이터가 추출된다.

	LinearQueue<int> lineQue;
	lineQue.Push(10);
	lineQue.Push(20);
	lineQue.Push(30);
	lineQue.Push(40);
	lineQue.Push(50);

	lineQue.Pop();

	cout << lineQue.Size() << endl;
	cout << lineQue.Front() << endl;
	cout << lineQue.Back() << endl;

#pragma endregion

	UnorderedMap<int, int> maps;
	maps[10] = 2;
	maps[1034] = 4;

	auto iter = maps.Find(10);
	cout << iter->first << " " << iter->second << endl;

	iter = maps.Find(1034);
	cout << iter->first << " " << iter->second << endl;

	return 0;
}
#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

enum Constants
{
	SIZE = 6
};

#pragma region BFS

// 시작 노드에서 시작하여 인접한 노드들을 탐색하면서 모든 노드를 탐색하는 방법

// 모든 노드를 탐색할 때까지 방문하지 않은 노드에 대해 BFS를 사용한다.

std::list<int> bfsGraph[SIZE];

void DoSomething(int vertex)
{
	std::cout << vertex << " ";
}

void BFS(int start)
{
	int vertex;
	bool visited[SIZE] = { false };
	std::queue<int> que;
	// 시작 출력문
	std::cout << "BFS start " << start << " : ";

	// 시작 정점 방문 예약
	que.push(start);
	visited[start] = true;

	while (!que.empty())
	{
		// 예약된 정점 방문
		vertex = que.front();
		que.pop();
		DoSomething(vertex);

		// 인접 정점 방문 예약
		for (auto& near : bfsGraph[vertex])
		{
			if (!visited[near])
			{
				que.push(near);
				visited[near] = true;
			}
		}
	}
	// 종료 줄 바꿈
	std::cout << std::endl;
}

#pragma endregion

#pragma region DFS

// 시작 노드에서 시작하여 한 인접 노드를 먼처 타고 내려가면서 모든 노드를 탐색하는 방법

std::list<int> dfsGraph[SIZE];

void DFS(int start)
{
	int vertex;
	bool visited[SIZE] = { false };
	std::stack<int> stk;
	// 시작 출력문
	std::cout << "DFS start " << start << " : ";

	// 시작 정점 방문 예약
	stk.push(start);
	visited[start] = true;

	while (!stk.empty())
	{
		// 예약된 정점 방문
		vertex = stk.top();
		stk.pop();
		DoSomething(vertex);

		// 인접 정점 방문 예약
		for (auto& near : dfsGraph[vertex])
		{
			if (!visited[near])
			{
				stk.push(near);
				visited[near] = true;
			}
		}
	}
	// 종료 줄 바꿈
	std::cout << std::endl;
}


void DFS_visit(int vertex, bool* visited)
{
	DoSomething(vertex);

	for (auto& near : dfsGraph[vertex])
		if (!visited[near])
		{
			visited[near] = true;
			DFS_visit(near, visited);
		}
}

void DFS_recursive(int start)
{
	bool visited[SIZE] = { false };
	std::cout << "DFS_recursive start " << start << " : ";

	visited[start] = true;
	DFS_visit(start, visited);
	std::cout << std::endl;
}

#pragma endregion

int main()
{
#pragma region Full_Search

	// 무방향 DFS 그래프 연결들
	std::vector<std::pair<int, int>> edges1 = { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 2, 4 }, { 2, 5 } };

	for (auto& edge : edges1)
	{
		// 인접 정점 정보 저장
		bfsGraph[edge.first].push_back(edge.second);
		bfsGraph[edge.second].push_back(edge.first);
	}

	for (int i = 0; i < SIZE; i++)
	{
		// BFS 시작
		BFS(i);
	}
	std::cout << std::endl;

	// 무방향 BFS 그래프 연결들
	std::vector<std::pair<int, int>> edges2 = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 4 }, { 3, 5 } };

	for (auto& edge : edges2)
	{
		// 인접 정점 정보 저장
		dfsGraph[edge.first].push_back(edge.second);
		dfsGraph[edge.second].push_back(edge.first);
	}

	for (int i = 0; i < SIZE; i++)
	{
		// DFS 시작
		DFS(i);
	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		// DFS 시작
		DFS_recursive(i);
	}
	std::cout << std::endl;

#pragma endregion

	return 0;
}
#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#pragma region Tree(Data_Structure)

// 그래프의 한 형태로 정점과 간선을 이용하여
// 데이터의 배치 형태를 추상화한 자료구조

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(const int& data, Node* const leftChild, Node* const rightChild)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = leftChild;
	newNode->right = rightChild;
	return newNode;
}

void DoSomthing(Node* curr)
{
	cout << curr->data << " ";
}

void Preorder(Node* curr)
{
	if (curr == nullptr)
		return;

	DoSomthing(curr);
	Preorder(curr->left);
	Preorder(curr->right);
}

void Inorder(Node* curr)
{
	if (curr == nullptr)
		return;

	Inorder(curr->left);
	DoSomthing(curr);
	Inorder(curr->right);
}

void Postorder(Node* curr)
{
	if (curr == nullptr)
		return;

	Postorder(curr->left);
	Postorder(curr->right);
	DoSomthing(curr);
}

#pragma endregion

int main()
{
	Node* node7 = CreateNode(7, nullptr, nullptr);
	Node* node6 = CreateNode(6, nullptr, nullptr);
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);
	Node* node3 = CreateNode(3, node6, node7);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);

	Preorder(node1);
	cout << endl;

	Inorder(node1);
	cout << endl;

	Postorder(node1);
	cout << endl;

	return 0;
}
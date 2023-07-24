#pragma once
#include <iostream>
#include <list>

using namespace std;

// 1. 노드 만들기
struct NODE
{
	int data;
	NODE* nextNode;
};

NODE* AddNode(NODE* target, int data)
{
	NODE* newNode = new NODE{ data, nullptr };

	newNode->nextNode = target->nextNode;
	target->nextNode = newNode;
	return newNode;
}

void DeleteNode(NODE* target)
{
	delete target;
}

void RemoveNode(NODE* prevTarget)
{
	NODE* delNode = prevTarget->nextNode;
	prevTarget->nextNode = delNode->nextNode;
	DeleteNode(delNode);
}

NODE* MakeList()
{
	return new NODE{ 0,nullptr };
}

void DestroyList(NODE** list)
{
	while ((*list)->nextNode != nullptr)
		RemoveNode(*list);
	DeleteNode(*list);
	*list = nullptr;
}

void PrintAll(NODE* head)
{
	if (head == nullptr)
	{
		cout << "List is Nothing!\n";
		return;
	}

	while (head->nextNode != nullptr)
	{
		head = head->nextNode;

		cout << head->data;
		if (head->nextNode != nullptr)
			cout << " -> ";
	}
	cout << endl;
}

class LinkedList
{
private:
	NODE* head;
	NODE* tail;

	NODE* MakeNode(int data)
	{
		NODE* newNode = new NODE{ data, nullptr };
		return newNode;
	}

	void DeleteNode(NODE* node)
	{
		delete node;
	}

public:
	LinkedList() : head(nullptr), tail(nullptr) { cout << "LinkedList is Started!\n"; }
	~LinkedList()
	{
		while (head != nullptr)
			Pop_back();
		cout << "LinkedList is Ended!\n";
	}

	void Push_back(int data);
	void Pop_back();
	NODE* Insert(NODE* position, int data);
	NODE* Erase(NODE* position);
	void PrintList();
};

int main()
{
	// 단일 연결 리스트

	/*NODE* node1 = new NODE{ 10, nullptr };
	NODE* node2 = new NODE{ 20, nullptr };
	NODE* node3 = new NODE{ 30, nullptr };

	node1->nextNode = node2;
	node2->nextNode = node3;

	NODE* curr = node1;
	while (curr != nullptr)
	{
		cout << curr->data;
		if (curr->nextNode != nullptr)
			cout << " -> ";

		curr = curr->nextNode;
	}

	delete node1;
	delete node2;
	delete node3;
	*/

	/*LinkedList LList;

	LList.Push_back(10);
	LList.Push_back(20);
	LList.Push_back(30);
	LList.Push_back(40);
	LList.Push_back(50);

	LList.PrintList();

	LList.Pop_back();
	LList.Pop_back();

	LList.PrintList();
	*/

	NODE* head = MakeList();
	NODE* tail = head;

	tail = AddNode(tail, 10);
	tail = AddNode(tail, 20);
	tail = AddNode(tail, 30);
	tail = AddNode(tail, 40);
	tail = AddNode(tail, 50);

	PrintAll(head);
	DestroyList(&head);
	PrintAll(head);

	return 0;
}

void LinkedList::Push_back(int data)
{
	NODE* newNode = MakeNode(data);

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->nextNode = newNode;
		tail = newNode;
	}
}

void LinkedList::Pop_back()
{
	if (head == nullptr)
		return;

	if (head == tail)
	{
		DeleteNode(tail);
		head = tail = nullptr;
		return;
	}

	NODE* curr = head;
	while (curr->nextNode != tail)
		curr = curr->nextNode;

	DeleteNode(tail);
	tail = curr;
}

NODE* LinkedList::Insert(NODE* position, int data)
{

	return nullptr;
}

void LinkedList::PrintList()
{
	NODE* currNode = head;
	while (currNode != tail->nextNode)
	{
		cout << currNode->data;
		if (currNode != tail)
			cout << " -> ";
		currNode = currNode->nextNode;
	}
	cout << endl;
}

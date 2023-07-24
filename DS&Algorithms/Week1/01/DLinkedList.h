#pragma once
#include <iostream>
struct NODE
{
	int data;
	NODE* next;
	NODE* prev;
};

class DLinkedList
{

private:
	NODE* head;
	NODE* tail;
	size_t size;

	NODE* MakeNode(int data)
	{
		NODE* newNode = new NODE{ data, nullptr, nullptr };
		return newNode;
	}
	void DeleteNode(NODE* target)
	{
		delete target;
	}

public:
	DLinkedList() : head(new NODE{ 0, nullptr, nullptr }), tail(head), size() {}
	~DLinkedList() { Clear(); delete head; }

	void PushFront(int data);
	void PushBack(int data);

	void PopFront();
	void PopBack();

	NODE* Insert(NODE* target, int data);
	NODE* Erase(NODE* target);

	void Clear();

	size_t Size();
	bool Empty();

	void PrintList()
	{
		NODE* curr = head;
		while (curr != tail)
		{
			if (curr != head)
				std::cout << " -> ";
			std::cout << curr->data;
			curr = curr->next;
		}
		std::cout << std::endl;
	}
};
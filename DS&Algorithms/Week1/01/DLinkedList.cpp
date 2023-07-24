#include "DLinkedList.h"

void DLinkedList::PushFront(int data)
{
	NODE* newNode = MakeNode(data);
	
	newNode->next = head;
	head->prev = newNode;
	
	head = newNode;
	size++;
}

void DLinkedList::PushBack(int data)
{
	NODE* newNode = MakeNode(data);

	newNode->next = tail;
	newNode->prev = tail->prev;
	
	if (head != tail)
		tail->prev->next = newNode;
	else
		head = newNode;

	tail->prev = newNode;
	size++;
}

void DLinkedList::PopFront()
{
	NODE* delNode = head;

	head = head->next;
	head->prev = nullptr;

	DeleteNode(delNode);
	size--;
}

void DLinkedList::PopBack()
{
	NODE* delNode = tail->prev;

	delNode->prev->next = tail;
	tail->prev = delNode->prev;

	DeleteNode(delNode);
	size--;
}

NODE* DLinkedList::Insert(NODE* target, int data)
{
	NODE* newNode = MakeNode(data);

	newNode->next = target;
	newNode->prev = target->prev;

	target->prev->next = newNode;
	target->prev = newNode;

	size++;
	return target;
}

NODE* DLinkedList::Erase(NODE* target)
{
	NODE* nextNode = target->next;
	target->prev->next = nextNode;
	nextNode->prev = target->prev;

	DeleteNode(target);
	return nextNode;
}

void DLinkedList::Clear()
{
	NODE* curr = head;
	while (head != tail)
	{
		head = head->next;
		DeleteNode(curr);
		curr = head;
	}
	head->prev = nullptr;
	size = 0;
	std::cout << "Clear Completed!" << std::endl;
}

size_t DLinkedList::Size()
{
	return size;
}

bool DLinkedList::Empty()
{
	return head == tail;
}

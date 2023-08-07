#include <iostream>
#include <vector>

using namespace std;

#pragma region Circle_Linked_List

//
struct Node
{
	int data;
	Node* next;
	Node* prev;
};

class CircleLinkedList
{
private:
	Node* head;
	int size;

	Node* CreateNode(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = newNode;
		newNode->prev = newNode;

		return newNode;
	}

	void DeleteNode(Node* target)
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;

		delete target;
	}

public:
	CircleLinkedList() : size(0) 
	{
		head = new Node;
		head->next = head;
		head->prev = head;
	}

	~CircleLinkedList()
	{
		Clear();
		delete head;
	}

	Node* Push_Front(int data)
	{
		Node* newNode = CreateNode(data);

		newNode->next = head->next;
		newNode->prev = head;

		newNode->prev->next = newNode;
		newNode->next->prev = newNode;

		size++;
		return head;
	}

	Node* Push_back(int data)
	{
		Node* newNode = CreateNode(data);

		newNode->next = head;
		newNode->prev = head->prev;

		newNode->prev->next = newNode;
		newNode->next->prev = newNode;

		size++;
		return head;
	}

	void PrintList()
	{
		Node* curr = head->next;
		while (curr != head)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}

	void Clear()
	{
		Node* curr = head->next;
		while (curr != head)
		{
			DeleteNode(curr);
			curr = head->next;
		}
		size = 0;
	}

};


#pragma endregion


int main()
{
	CircleLinkedList cll;

	cll.PrintList();

	cll.Push_back(1);
	cll.Push_back(2);
	cll.Push_back(3);
	cll.Push_back(4);
	cll.Push_back(5);
	cll.Push_Front(-1);
	cll.Push_Front(-2);
	cll.Push_Front(-3);
	cll.Push_Front(-4);
	cll.Push_Front(-5);

	cll.PrintList();

	cll.Clear();

	return 0;
}
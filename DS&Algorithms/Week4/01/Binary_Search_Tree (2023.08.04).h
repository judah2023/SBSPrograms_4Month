#pragma once
#include <iostream>
#include <vector>

using namespace std;

#pragma region BST(Bineary_Search_Tree)

// 임의의 키를 가진 원소를 삽입, 삭제, 검색하는데 효율적인 트리

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class BSTree
{
private:

	Node* root;

	Node* FindNearValueNode(Node* root)
	{
		Node* near = root->right;
		while (near->left != nullptr)
			near = near->left;

		return near;
	}

	Node* CreateNode(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}

	Node* InsertChild(Node* curr, int data)
	{
		if (curr == nullptr)
			return CreateNode(data);

		if (data < curr->data)
			curr->left = InsertChild(curr->left, data);
		else if (data > curr->data)
			curr->right = InsertChild(curr->right, data);
		return curr;
	}

	Node* DeleteChild(Node* curr, int data)
	{
		if (curr == nullptr)
			return nullptr;

		if (data < curr->data)
		{
			curr->left = DeleteChild(curr->left, data);
			return curr;
		}
		else if (data > curr->data)
		{
			curr->right = DeleteChild(curr->right, data);
			return curr;
		}



		Node* temp;
		if (curr->left == nullptr)
		{
			temp = curr->right;
			delete curr;
			return temp;

		}
		else if (curr->right == nullptr)
		{
			temp = curr->left;
			delete curr;
			return temp;
		}

		temp = FindNearValueNode(curr);
		curr->data = temp->data;
		curr->right = DeleteChild(curr->right, curr->data);


		return curr;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

		cout << root->data << " ";
		_Inorder(root->left);
		_Inorder(root->right);

	}

public:

	BSTree() : root(nullptr) {}

	void Insert(int data)
	{
		Node* newNode = CreateNode(data);

		root = InsertChild(root, data);
	}

	void Delete(int data)
	{
		Node* delNode = DeleteChild(root, data);

	}

	int FindMax()
	{
		Node* curr = root;
		while (curr != nullptr && curr->right != nullptr)
		{
			curr = curr->right;
		}

		if (curr != nullptr)
			return curr->data;

		return -1;
	}

	void Inorder()
	{
		_Inorder(root);
	}

};


#pragma endregion


int main()
{

	BSTree bstree;

	bstree.Insert(5);
	bstree.Insert(1);
	bstree.Insert(9);
	bstree.Insert(2);
	bstree.Insert(8);
	bstree.Insert(3);
	bstree.Insert(7);
	bstree.Insert(4);
	bstree.Insert(6);

	bstree.Inorder();

	bstree.Delete(5);

	return 0;
}
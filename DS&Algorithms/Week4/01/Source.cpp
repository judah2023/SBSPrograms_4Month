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

	Node* InsertChild(Node* root, Node* target)
	{
		if (root == nullptr)
		{
			root = target;
		}
		else
		{
			if (target->data < root->data)
				root->left = InsertChild(root->left, target);
			else if (target->data > root->data)
				root->right = InsertChild(root->right, target);
		}
		return root;
	}

	Node* DeleteChild(Node* root, int data)
	{
		if (root == nullptr)
			return nullptr;

		if (root->data > data)
			root->left = DeleteChild(root->left, data);
		else if (root->data < data)
			root->right = DeleteChild(root->right, data);
		else
		{
			Node* temp;
			if (root->left == nullptr)
			{
				temp = root->right;
				delete root;
				return temp;

			}
			else if (root->right == nullptr)
			{
				temp = root->left;
				delete root;
				return temp;
			}
			else
			{
				temp = FindNearValueNode(root);
				root->data = temp->data;
				root->right = DeleteChild(root->right, root->data);
			}

		}

		return root;
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

		root = InsertChild(root, newNode);
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
#include "src/base.h"

struct Node
{
	Node(int val) : val(val)
	{
		next = nullptr;
		prev = nullptr;
	}

	int val;
	Node *next;
	Node *prev;
};

class MyLinkedList
{

public:
	MyLinkedList()
	{
		head = new Node(-1);
		tail = new Node(-1);
		head->next = tail;
		tail->prev = head;
	}

	int get(int index)
	{
		Node *node = getNodeAtIndex(index);
		if (!node || node == tail || node->next == tail)
		{
			return -1;
		}
		return node->next->val;
	}

	void addAtHead(int val)
	{
		Node *node = new Node(val);
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
		node->prev = head;
	}

	void addAtTail(int val)
	{
		Node *node = new Node(val);
		node->next = tail;
		node->prev = tail->prev;
		tail->prev->next = node;
		tail->prev = node;
	}

	Node *getNodeAtIndex(int index)
	{
		Node *node = head;
		for (int i = 0; i < index; i++)
		{
			if (node == tail)
			{
				return nullptr;
			}
			node = node->next;
		}
		return node;
	}

	void addAtIndex(int index, int val)
	{
		Node *node = getNodeAtIndex(index);
		if (!node || node == tail)
		{
			return;
		}
		auto nodeToAdd = new Node(val);
		nodeToAdd->next = node->next;
		nodeToAdd->prev = node;
		node->next = nodeToAdd;
		nodeToAdd->next->prev = nodeToAdd;
	}

	void deleteAtIndex(int index)
	{
		Node *node = getNodeAtIndex(index);
		if (!node || node == tail || node->next == tail)
		{
			return;
		}
		auto nodeToDelete = node->next;
		nodeToDelete->next->prev = nodeToDelete->prev;
		nodeToDelete->prev->next = nodeToDelete->next;
		delete nodeToDelete;
	}

protected:
	Node *head;
	Node *tail;
};

int main()
{
	std::cout << "no test" << std::endl;
}

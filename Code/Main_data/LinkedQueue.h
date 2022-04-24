#pragma once
using namespace std;
#include <iostream>
#include <cassert>
using namespace std;
template<class t>
class LinkedQueue
{
private:
	struct Node
	{
		t item;
		Node* next;
	};
	int length;
	Node* frontPtr, * rearPtr;

public:

	LinkedQueue() :frontPtr(NULL), rearPtr(NULL), length(0)
	{}
	bool isEmpty()
	{
		return (length == 0);
	}

	bool dequeue(t &item)
	{
		if (isEmpty())
			return false;
		else if (length == 1)
		{
			item = frontPtr->item;
			delete frontPtr;
			rearPtr = NULL;
			length = 0;
			return true;
		}
		else
		{
			Node* current = frontPtr;
			item = current->item;
			frontPtr = frontPtr->next;
			delete current;//free(current)
			length--;
			return true;
		}
	}

	void enqueue(t item)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (length == 0)
			rearPtr = frontPtr = newNode;
		else
		{
			rearPtr->next = newNode;
			rearPtr = newNode;
		}
		length++;
	}

	bool peek(t &item)
	{
		if (isEmpty())
		{
			return false;
		}
		assert(!isEmpty());
		item = frontPtr->item;
			return true;
	

	}
	t& peek2()
	{
		assert(!isEmpty());
		return (frontPtr->item);

	}

	t rear()
	{
		assert(!isEmpty());
		return rearPtr->item;
	}

	void clearQueue()
	{
		Node* current;

		while (frontPtr != NULL)
		{
			current = frontPtr;
			frontPtr = frontPtr->next;
			delete current;
		}
		rearPtr = NULL;
		length = 0;
	}
	void display()
	{
		Node* cur = frontPtr;
		cout << "Item in the queue :[ ";
		while (cur != NULL)
		{
			cout << cur->item << " ";
			cur = cur->next;
		}cout << "]" << endl;
	}

	LinkedQueue(const LinkedQueue<t>& LQ)
	{
		Node* NodePtr = LQ.frontPtr;

		if (!NodePtr) //LQ is empty
		{
			frontPtr = rearPtr = nullptr;
			return;
		}
		Node* ptr = new Node;
		ptr->item = NodePtr->item;
		frontPtr = rearPtr = ptr;
		NodePtr = NodePtr->next;
		while (NodePtr)
		{
			Node* ptr = new Node;
			ptr->item = NodePtr->item;
			rearPtr->next = ptr;
			rearPtr = ptr;
			NodePtr = NodePtr->next;
		}
		length = LQ.length;
	}

	int getlength()
	{
		return length;
	}
};

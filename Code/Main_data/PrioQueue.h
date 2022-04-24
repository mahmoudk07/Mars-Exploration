#pragma once
#include"iostream"
#include <cassert>
using namespace std;
template<class t>
class PrioQueue
{
	struct Node
	{
		t item;
		Node* next;
		float priority;
	};
	int length;
	Node* frontPtr, * rearPtr;
public:
	PrioQueue() :frontPtr(NULL), rearPtr(NULL), length(0)
	{};
	bool isEmpty()
	{
		return (length == 0);
	}

	bool dequeue(t& item)
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
	void arrange()
	{
		if (frontPtr == nullptr)
		{
			return;
		}
		if (frontPtr->next == nullptr)
		{
			return;
		}
		Node* ptr1 = frontPtr;
		Node* ptr2;
		while (ptr1->next)
		{
			ptr2 = ptr1->next;
			while (ptr2)
			{
				if (ptr1->priority < ptr2->priority)
				{
					Node* temp = new Node;
					temp->item = ptr1->item;
					temp->priority = ptr1->priority;
					ptr1->item = ptr2->item;
					ptr1->priority = ptr2->priority;
					ptr2->item = temp->item;
					ptr2->priority = temp->priority;
				}
				ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}
	}
	void enqueue(t item, float num)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->priority = num;
		newNode->next = NULL;

		if (length == 0)
			rearPtr = frontPtr = newNode;
		else
		{
			rearPtr->next = newNode;
			rearPtr = newNode;
		}
		arrange();
		length++;
	}
	bool peek(t& item)
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

	PrioQueue(const PrioQueue<t>& LQ)
	{
		Node* NodePtr = LQ.frontPtr;

		if (!NodePtr) //LQ is empty
		{
			frontPtr = rearPtr = nullptr;
			return;
		}
		Node* ptr = new Node;
		ptr->item = NodePtr->item;
		ptr->priority = NodePtr->priority;
		frontPtr = rearPtr = ptr;
		NodePtr = NodePtr->next;
		while (NodePtr)
		{
			Node* ptr = new Node;
			ptr->item = NodePtr->item;
			ptr->priority = NodePtr->priority;
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

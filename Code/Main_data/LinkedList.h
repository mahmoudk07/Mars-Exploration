#pragma once

#include "Node.h"
#include<iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;
	int length;
public:

	LinkedList()
	{
		Head = nullptr;
		length = 0;
	}

	~LinkedList()
	{
		DeleteAll();
	}

	Node<T>* gethead()
	{
		return Head;
	}
	// Prints the linked list in the required format
	void PrintList()	const
	{
		Node<T>* p = Head;
		while (p)
		{
			cout << p->getItem() << " ";
			p = p->getNext();
		}
		cout << endl;
	}

	// Insert at the end of the linked list
	void InsertEnd(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		if (!Head)
		{
			Head = R;
			length++;
			return;
		}
		Node<T>* p = Head;
		while (p->getNext())
			p = p->getNext();
		p->setNext(R);
		length++;
	}

	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		length = 0;
	}

	int getlength()
	{
		return length;
	}

	//Copy constructor 

	template <typename T>
	LinkedList(const LinkedList<T>& L)
	{
		Node<T>* NodePtr = L.Head;
		if (!NodePtr) //L is empty
		{
			Head= nullptr;
			length = 0;
			return;
		}

		//insert the first node
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		Head= ptr;
		NodePtr = NodePtr->getNext();
		Node<T>* p = Head;
		length++;

		//insert remaining nodes
		while (NodePtr)
		{
			InsertEnd(NodePtr->getItem());
	    length++;
			NodePtr = NodePtr->getNext();
		}
	}

	bool Isempty()
	{
		return (Head == nullptr);
	}

	bool deletefirst(T& data)
	{
		if (Head == nullptr)
			return false;
		else
		{
			Node<T>* ptr = Head;
			Head = Head->getNext();
			data = ptr->getItem();
			delete ptr;
			ptr = nullptr;
			length--;
			return true;
		}
	}
		
};

 // !Linked_List_


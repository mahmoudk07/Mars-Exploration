#ifndef Linked_Stack_
#define Linked_Stack_

#include "Node.h"
#include <vector>
using namespace std;


template <typename T>
class LinkedStack 
{
private:
	Node<T>* top;
public:
	//constructor
	LinkedStack()
	{
		top = NULL;
	}

	//check if empty
	bool isEmpty()
	{
		return(top == nullptr);
	}

	//push
	bool push(const T& newEntry)
	{
		Node<T>* new_node = new Node<T>;
		new_node->setItem(newEntry);
		new_node->setNext(top);
		top = new_node;
		return true;
	}

	//pop
	bool pop(T& TopEntry)
	{
		if (top)
		{
			Node<T>* current = top;
			top = top->getNext();
			delete(current);
			return true;
		}
		return false;
	}

	//peek
	bool peek(T& TopEntry)
	{
		if (top)
		{
			TopEntry= top->getItem();
			return true;
		}
		return false;
	}

	//displaying
	void Display()
	{
		if (top) 
		{
			Node<T>* current = top;
			while (current)
			{
				cout << current->getItem() << "  ";
				current = current->getNext();
			}
		}
		cout << endl;
	}

	//destructor
	~LinkedStack()
	{
		T item;
		while(pop(item))
	}

	//Copy constructor
	LinkedStack(const LinkedStack<T>& LP)
	{
		Node<T>* NodePtr = LP.top;
		if (!NodePtr) //LP is empty
		{
			top = nullptr;
			return;
		}
		LinkedStack L;

		//insert node
		while (NodePtr)
		{
			L.push(NodePtr->getItem());
			NodePtr = NodePtr->getNext();
		}
		T item;
		while (L.pop(item))
		{
			push(item);
		}
	}
};

#endif // !Linked_Stack_


#ifndef Prio_Node_
#define Prio_Node_
template < typename T>
class PrioNode
{
private:
	T item; // A data item
	PrioNode<T>* next; // Pointer to next PrioNode
	float priority; //priority of the PrioNode
public:
	PrioNode();
	PrioNode(const T& r_Item, float & num);
	PrioNode(const T& r_Item, PrioNode<T>* nextPrioNodePtr, float & num);
	void setItem(const T& r_Item);
	void setNext(PrioNode<T>* nextPrioNodePtr);
	void setpriority(float num);
	T getItem() const;
	PrioNode<T>* getNext() const;
	float getpriority() const;
}; // end Prio PrioNode
#endif

template < typename T>
PrioNode<T>::PrioNode()
{
	next = nullptr;
	priority = 0;
}

template < typename T>
PrioNode<T>::PrioNode(const T& r_Item, float& num)
{
	item = r_Item;
	next = nullptr;
	priority = num;
}

template < typename T>
PrioNode<T>::PrioNode(const T& r_Item, PrioNode<T>* nextPrioNodePtr, float& num)
{
	item = r_Item;
	next = nextPrioNodePtr;
	priority = num;
}
template < typename T>
void PrioNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void PrioNode<T>::setNext(PrioNode<T>* nextPrioNodePtr)
{
	next = nextPrioNodePtr;
}

template < typename T>
T PrioNode<T>::getItem() const
{
	return item;
}

template < typename T>
PrioNode<T>* PrioNode<T>::getNext() const
{
	return next;
}

template < typename T>
void PrioNode<T>::setpriority(float num)
{
	priority = num;
}

template < typename T>
float PrioNode<T>::getpriority() const
{
	return priority;
}
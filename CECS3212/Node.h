//#ifndef _NODE
//#define _NODE
//
//template<class ItemType>
//class Node
//{
//private:
//	ItemType item; // A data item
//	Node<ItemType>* next; // Pointer to next node
//public:
//	Node();
//	Node(const ItemType& anItem);
//	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
//	void setItem(const ItemType& anItem);
//	void setNext(Node<ItemType>* nextNodePtr);
//	ItemType getItem() const;
//	Node<ItemType>* getNext() const;
//}; // end Node
//#include "Node.cpp"
//#endif


/** @file Node.h */
#ifndef _NODE
#define _NODE
template <class ItemType>
class Node
{
private:
	ItemType item; // A data item
	Node<ItemType>* next; // Pointer to next node
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
}; // end Node

//***************** CONSTRUCTOR **********************
template < class ItemType>
Node<ItemType>::Node() : next(NULL)
{
} // end default constructor

template < class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(NULL)
{
} // end constructor

template < class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
item(anItem), next(nextNodePtr)
{
} // end constructor

//****************** FUNCTIONS ***********************
template <class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
} // end setItem
template < class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
} // end setNext
template < class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
} // end getItem
template < class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
} // end getNext
#endif
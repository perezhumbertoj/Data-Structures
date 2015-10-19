#ifndef _LIST_QUEUE
#define _LIST_QUEUE
#include "QueueInterface.h"
#include "LinkedList.h"


template <class ItemType>
class ListQueue : public QueueInterface<ItemType>
{
private:
	LinkedList<ItemType>* listPtr; // Pointer to list of queue items
public:
	ListQueue();
	ListQueue(const ListQueue& aQueue);
	~ListQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const;
	
	void print() const;
}; // end ListQueue

///////////////////////////////////////////////////////////////////////
//////////					DEFINITIONS						//////////
///////////////////////////////////////////////////////////////////////

template<class ItemType>
ListQueue<ItemType>::ListQueue()
{
	listPtr = new LinkedList<ItemType>();
} // end default constructor
template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue) :
listPtr(aQueue.listPtr)
{
} // end copy constructor
template<class ItemType>
ListQueue<ItemType>::~ListQueue()
{
} // end destructor
template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const
{
	return listPtr->isEmpty();
} // end isEmpty
template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return listPtr->insert(listPtr->getLength() + 1, newEntry);
} // end enqueue
template<class ItemType>
bool ListQueue<ItemType>::dequeue()
{
	return listPtr->remove(1);
} // end dequeue
template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const
{
	if (isEmpty())
	{
		cout << "Rettrieve index out of range \n";
		exit(EXIT_FAILURE);
	}
	else
	{
		return listPtr->getEntry(1);
	}
} // end peekFront

template<class ItemType>
void ListQueue<ItemType>::print() const
{
	listPtr->display();
}//end display

#endif
#include "ListInterface.h"
#include "Node.h"

template < class ItemType>
LinkList<ItemType>::LinkList(const LinkList<ItemType> &aList)
{
	itemCount = aList.itemCount;
	Node<ItemType> *origChainPtr;
	int i = 0;
	origChainPtr = aList.headPtr;
	if (origChainPtr == NULL)
		headPtr = NULL; // Original bag is empty; so is copy
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		// Copy remaining nodes
		Node<ItemType> *newChainPtr = headPtr; // Last-node pointer
		while (origChainPtr->getNext() != NULL)
		{
			origChainPtr = origChainPtr->getNext(); // Advance pointer
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();
			i++;
		} // end while
		newChainPtr->setNext(NULL); // Flag end of new chain
	} // end if
} // end copy constructor

template < class ItemType>
LinkList<ItemType>::~LinkList()
{
	//clear();
	recursiveClear(getHeadPtr());
} // end destructor

//*************************** FUNCTIONS *****************************
template < class ItemType>
void LinkList<ItemType>::clear()
{
	Node<ItemType> *nodeToDeletePtr;
	while (headPtr != NULL)
	{
		nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		// Return node to the system
		nodeToDeletePtr->setNext(NULL);
		delete nodeToDeletePtr;
	} // end while
	// headPtr is nullptr
	nodeToDeletePtr = NULL;
	itemCount = 0;
} // end clear

template <class ItemType>
void LinkList<ItemType>::recursiveClear(Node<ItemType>* newHeadPtr)
{
	if (newHeadPtr == NULL)
	{
		itemCount = 0;
	}
	else
	{
		Node<ItemType> *nodeToDeletePtr;
		nodeToDeletePtr = newHeadPtr;
		newHeadPtr = newHeadPtr->getNext();
		nodeToDeletePtr->setNext(NULL);
		delete nodeToDeletePtr;
		nodeToDeletePtr = NULL;
		recursiveClear(newHeadPtr);
	}


}

template <class ItemType>
Node<ItemType>* LinkList<ItemType>::getHeadPtr()
{
	return headPtr;
}

template < class ItemType>
bool LinkList<ItemType>::isEmpty() const
{
	return itemCount == 0;
} // end isEmpty
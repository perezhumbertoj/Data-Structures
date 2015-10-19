#ifndef _LINKED_LIST
#define _LINKED_LIST
#include "ListInterface.h"
#include "Node.h"

template < class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node
	int itemCount; // Current count of bag items
	Node<ItemType> *getPointerTo(const int &target) const;
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType> &aList); // Copy constructor
	virtual ~LinkedList(); // Destructor should be virtual
	bool isEmpty() const;
	int getLength() const;
	bool add(const ItemType& newEntry);
	bool insert(int newPosition, const ItemType& newEntry);
	bool insertLast(const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const;
	void setEntry(int position, const ItemType& newEntry);


	//******* Mias ******
	void display(void) const;
	bool myRemoveFirst();
	bool rotateShift(int repeats);
	void recursiveClear(Node<ItemType> *newHeadPtr);
	Node<ItemType>* getHeadPtr();
}; // end LinkedBag

///////////////////////////////////////////////////////////////////////
//////////					DEFINITIONS						//////////
///////////////////////////////////////////////////////////////////////

//********************** CONSTRUCTORS ****************************
template < class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(NULL), itemCount(0)
{ } // end default constructor

template < class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &aList)
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
LinkedList<ItemType>::~LinkedList()
{
	//clear();
	recursiveClear(getHeadPtr());
} // end destructor

//*************************** FUNCTIONS *****************************
template < class ItemType>
void LinkedList<ItemType>::clear()
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
void LinkedList<ItemType>::recursiveClear(Node<ItemType>* newHeadPtr)
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
Node<ItemType>* LinkedList<ItemType>::getHeadPtr()
{
	return headPtr;
}

template < class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
} // end isEmpty

template < class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
} // end getLength

// Returns either a pointer to the node containing a given the index
// or the null pointer if the entry is not in the list.

template < class ItemType>
Node<ItemType>* LinkedList<ItemType>::getPointerTo(const int &Position /*const ItemType &Position*/) const
{
	//bool found = false ;
	//Node<ItemType>* curPtr = headPtr;

	//while (!found && (curPtr != nullptr ))
	//{
	//	if (target == curPtr->getItem())
	//		found = true ;
	//	else
	//		curPtr = curPtr->getNext();
	//} // end while
	//return curPtr;

	if ((Position < 1) || (Position > getLength())){
		return NULL;
	}//end if
	else{
		Node<ItemType>* curPtr = headPtr;
		for (int i = 1; i<Position; i++)
		{
			curPtr = curPtr->getNext();
		} // end for
		return curPtr;
	}//end else
} // end getPointerTo

template < class ItemType>
bool LinkedList<ItemType>::add(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>();
	newNodePtr->setItem(newEntry);
	newNodePtr->setNext(headPtr); // New node points to chain
	headPtr = newNodePtr; // New node is now first node
	itemCount++;
	return true;
}

template < class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is nullptr if chain is empty)
	int newLength = getLength() + 1;
	//cout<<newLength<<endl;
	if ((newPosition < 1) || (newPosition > newLength)){
		cout << "Insert index out of range \n";
	}//end if
	else{
		Node<ItemType> *newNodePtr = new Node<ItemType>();
		if (newNodePtr == NULL){
			cout << "Insert can not allocate memory \n";
		} //end if
		else{
			itemCount = newLength;
			newNodePtr->setItem(newEntry);
			if (newPosition == 1){
				newNodePtr->setNext(headPtr); // New node points to chain
				headPtr = newNodePtr; // New node is now first node
			}//end if
			else {
				Node<ItemType> *prevNodePtr = getPointerTo(newPosition - 1);
				newNodePtr->setNext(prevNodePtr->getNext());
				prevNodePtr->setNext(newNodePtr);
			}//end else;
		}//end else
	}//end if
	return true;
} // end insert

//salon 109
template <class ItemType>
bool LinkedList<ItemType>::insertLast(const ItemType& newEntry)
{
	Node<ItemType> *newNodePtr = new Node<ItemType>();
	newNodePtr->setItem(newEntry);
	newNodePtr->setNext(NULL);

}


template < class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	if ((position < 1) || (position > getLength())){
		cout << "Remove index out of range \n";
		return false;
	}//end if
	else{
		Node<ItemType> *nodeToDeletePtr;
		itemCount--;
		if (position == 1){
			nodeToDeletePtr = headPtr;
			headPtr = headPtr->getNext();
		}//end if
		else {
			Node<ItemType> *prevNodePtr = getPointerTo(position - 1);
			nodeToDeletePtr = prevNodePtr->getNext();
			prevNodePtr->setNext(nodeToDeletePtr->getNext());
		} //end else
		// Return node to the system
		nodeToDeletePtr->setNext(NULL);
		delete nodeToDeletePtr;
		nodeToDeletePtr = NULL;
		return true;
	}//end else
} // end remove

template < class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const{
	if ((position < 1) || (position > getLength())){
		cout << "Rettrieve index out of range \n";
		exit(EXIT_FAILURE);
	}//end if
	else{
		Node<ItemType> *currNodePtr = getPointerTo(position);
		return (currNodePtr->getItem());
	}//end else
}//end getEntry

template < class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType &newEntry){
	if ((position < 1) || (position > getLength())){
		cout << "Rettrieve index out of range \n";
		exit(EXIT_FAILURE);
	}//end if
	else{
		Node<ItemType> *currNodePtr = getPointerTo(position);
		currNodePtr->setItem(newEntry);
	}//end else
}//end setEntry

template < class ItemType>
void LinkedList<ItemType>::display(void) const{
	ItemType dataItem;
	if (isEmpty()){
		cout << "List is Empty \n";
	}//end if
	else{
		cout << endl;
		for (int position = 1; position <= getLength(); position++){
			dataItem = getEntry(position);
			cout << dataItem << ",";
		}//end for
	}//end else
}//end display

template <class ItemType>
bool LinkedList<ItemType>::myRemoveFirst()
{
	Node<ItemType>* temp = headPtr;

	headPtr = headPtr->getNext();

	delete temp;

	itemCount--;

	return true;
}

template <class ItemType>
bool LinkedList<ItemType>::rotateShift(int repeats)
{

	Node<ItemType>* ptrToMove = headPtr;

	headPtr = headPtr->getNext();
	itemCount--;

	ptrToMove->setNext(NULL);


	Node<ItemType>* tempPtr = getPointerTo(getLength());

	cout << endl << "ptrToMove: " << ptrToMove->getItem() << endl;
	cout << endl << "tempPtr: " << tempPtr->getItem() << endl;
	tempPtr->setNext(ptrToMove);
	itemCount++;

	return true;
}

#endif
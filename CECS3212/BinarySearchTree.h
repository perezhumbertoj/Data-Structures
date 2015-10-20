#ifndef _BINARY_SEARCH
#define _BINARY_SEARCH
#include "TreeNode.h"

template <class ItemType>
class BinarySearchTree
{
private:
	TreeNode<ItemType>* rootPtr; // Pointer to first node
	int itemCount;
public:
	BinarySearchTree();
	~BinarySearchTree();
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const;
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData);
	bool remove(const ItemType& data);
	void clear();
	ItemType getEntry(const ItemType& anEntry) const;
	bool contains(const ItemType& anEntry) const;
	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;
};

//*********************************************************//
//                         CONSTRUCTORS                    //
//*********************************************************//

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(NULL), itemCount(0)
{
}


template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() //Destructor
{
}

//*********************************************************//
//                         METHODS                         //
//*********************************************************//

template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return itemCount == 0;
} // end isEmpty

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{

}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{

}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
{
	if (this->isEmpty())
	{
		cout << "Rettrieve index out of range \n";
		exit(EXIT_FAILURE);
	}//end if
	else
	{
		return rootPtr->getItem();
	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{

}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
	TreeNode<ItemType>* newNodePtr = new TreeNode<ItemType>();
	newNodePtr->setItem(newData);							//Assign ItemType value to new node
	TreeNode<ItemType>* tempPtr = new TreeNode<ItemType>();
	tempPtr = rootPtr;										//Temporary pointer
	if (this->isEmpty())
	{
		rootPtr = newNodePtr;								//If the tree is empty, make new node the root
		itemCount++; 
		return true;
	}
	else if (newNodePtr->getItem() == tempPtr->getItem())	//If the value is the same, it is not added
	{
		return false;
	}
	else if (newNodePtr->getItem() < tempPtr->getItem())	// If the value is lesser than the tempNode
	{
		tempPtr = tempPtr->getLeft();						//make tempPtr point towards the next node on left
		while (tempPtr->getItem() != NULL)					// while the value is null
		{													
		
			this->add(tempPtr->getItem());					// it recalls the function
		}

		tempPtr = newNodePtr;								//If it's null, add the item there
		itemCount++;
		delete tempPtr;
	}
	else													// If the value is greater than the tempNode
	{
		tempPtr = tempPtr->getRight();						//make tempPtr point towards the next node on right
		while (tempPtr->getItem() != NULL)					// while the value is null
		{													

			this->add(tempPtr->getItem());					// it recalls the function
		}

		tempPtr = newNodePtr;								//If it's null, add the item there
		itemCount++;
		delete tempPtr;
	}
}

template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& data)
{

}

template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{


}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& data) const
{

}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& data) const
{

}

#endif
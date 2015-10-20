#include "BinarySearchTree.h"


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
	newNodePtr->setItem(newData);
	if (this->isEmpty())
	{
		rootPtr = newNodePtr;
		itemCount++;
	}
	else if (newNodePtr->getItem() == rootPtr->getItem())
	{
		cout << "This item already exists. \n";
		exit(EXIT_FAILURE);
	}
	else if (newNodePtr->getItem() < rootPtr->getItem())
	{

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
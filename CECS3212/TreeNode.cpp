#include "TreeNode.h"

//*********************************************************//
//                         CONSTRUCTORS                    //
//*********************************************************//

template <class ItemType>
TreeNode<ItemType>::TreeNode() : next(NULL), leftChild(1), rightChild(1)
{
} // end default constructor

template <class ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& anItem) : item(anItem), left(NULL), right(NULL)
{
} // end constructor

template<class ItemType>
TreeNode<ItemType>::~TreeNode()
{
}

//*********************************************************//
//                         SETTERS                         //
//*********************************************************//

template<class ItemType>
void TreeNode<ItemType>::setItem(const ItemType& nodeItem)
{
	this->item = nodeItem;
}

template<class ItemType>
void TreeNode<ItemType>::setLeft(TreeNode<ItemType>* leftNodePtr)
{
	this->left = leftNodePtr;
} 

template<class ItemType>
void TreeNode<ItemType>::setRight(TreeNode<ItemType>* rightNodePtr)
{
	this->left = leftNodePtr;
}

//*********************************************************//
//                         GETTERS                            //
//*********************************************************//

template<class ItemType>
ItemType TreeNode<ItemType>::getItem() const
{
	return this->item;
}

template<class ItemType>
int TreeNode<ItemType>::getLeft() const
{
	return this->left;
}

template<class ItemType>
int TreeNode<ItemType>::getRight() const
{
	return this->right;
}
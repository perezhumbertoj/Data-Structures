#include "TreeNode.h"

//*********************************************************//
//                         CONSTRUCTORS                    //
//*********************************************************//

template<class ItemType>
TreeNode<ItemType>::TreeNode()
{

}

template<class ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& nodeItem)
{
	this->item = nodeItem.item;
	this->leftChild = nodeItem.leftChild;
	this->rightChild = nodeItem.rightChild;
}

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
void TreeNode<ItemType>::setLeft(int left)
{
	this->leftChild = left;
}

template<class ItemType>
void TreeNode<ItemType>::setRight(int right)
{
	this->leftChild = right;
}

//*********************************************************//
//                         GETTERS                            //
//*********************************************************//

template<class ItemType>
ItemType TreeNode<ItemType>::getItem(const Itemtype& nodeItem)
{
	return this->item;
}

template<class ItemType>
int TreeNode<ItemType>::getLeft(int left)
{
	return this->left;
}

template<class ItemType>
int TreeNode<ItemType>::getRight(int right)
{
	return this->right;
}
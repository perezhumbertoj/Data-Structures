#include "TreeNode.h"


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

template<class ItemType>

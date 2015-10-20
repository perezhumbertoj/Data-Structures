#pragma once
#include "TreeNode.h"

template <class ItemType>
class BinarySearchTree
{
private:
	TreeNode<ItemType>* headPtr; // Pointer to first node
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


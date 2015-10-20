#pragma once

template <class ItemType>
class TreeNode
{
private:
	ItemType item; // Data portion
	TreeNode<ItemType>* leftNodePtr;
	TreeNode<ItemType>* rightNodePtr;
	int leftChild; // Index to left child
	int rightChild; // Index to right child
public:
	TreeNode();
	TreeNode(const ItemType& anItem);
	//TreeNode(const ItemType& anItem, Node<ItemType>* nextNodePtr);


	void setItem(const ItemType& anItem);
	void setLeft(TreeNode<ItemType>* leftNodePtr);
	void setRight(TreeNode<ItemType>* rightNodePtr);


	ItemType getItem() const;
	Node<ItemType>* getRight() const;
	Node<ItemType>* getLeft() const;
}; // end TreeNode
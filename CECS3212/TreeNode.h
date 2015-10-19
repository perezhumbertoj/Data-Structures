#pragma once
template < class ItemType>
class TreeNode
{
private:
	ItemType item; // Data portion
	int leftChild; // Index to left child
	int rightChild; // Index to right child
public:
	TreeNode();
	TreeNode(const ItemType& nodeItem);
	void setItem(const Itemtype& nodeItem);
	ItemType getItem() const;
	void setLeft(int left);
	int getLeft() const;
	setRight(int right);
	getRight() const;
	. . .
}; // end TreeNode
//Test
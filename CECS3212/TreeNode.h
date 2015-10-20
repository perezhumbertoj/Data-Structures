#ifndef _TREE_NODE
#define _TREE_NODE

template <class ItemType>
class TreeNode
{
private:
	ItemType item; // Data portion
	TreeNode<ItemType>* leftNodePtr;
	TreeNode<ItemType>* rightNodePtr;
	//int leftChild; // Index to left child
	//int rightChild; // Index to right child
public:
	TreeNode();
	TreeNode(ItemType anItem);
	//TreeNode(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	~TreeNode();

	void setItem(const ItemType& anItem);
	void setLeft(TreeNode<ItemType>* leftNodePtr);
	void setRight(TreeNode<ItemType>* rightNodePtr);

	bool isLeaf();

	ItemType getItem() const;
	TreeNode<ItemType>* getRight() const;
	TreeNode<ItemType>* getLeft() const;
}; // end TreeNode



   //*********************************************************//
   //                         CONSTRUCTORS                    //
   //*********************************************************//

template <class ItemType>
TreeNode<ItemType>::TreeNode() : leftNodePtr(NULL), rightNodePtr(NULL)
{
}// end default constructor

template <class ItemType>
TreeNode<ItemType>::TreeNode(ItemType anItem)// item(anItem), leftNodePtr(NULL), rightNodePtr(NULL)
{
	this->item = anItem;
	this->leftNodePtr = NULL;
	this->rightNodePtr = NULL;
}// end constructor

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
	this->leftNodePtr = leftNodePtr;
}

template<class ItemType>
void TreeNode<ItemType>::setRight(TreeNode<ItemType>* rightNodePtr)
{
	this->rightNodePtr = rightNodePtr;
}

//*********************************************************//
//                         GETTERS                         //
//*********************************************************//

template<class ItemType>
ItemType TreeNode<ItemType>::getItem() const
{
	return this->item;
}

template<class ItemType>
TreeNode<ItemType>*TreeNode<ItemType>::getLeft() const
{
	return this->leftNodePtr;
}

template<class ItemType>
TreeNode<ItemType>* TreeNode<ItemType>::getRight() const
{
	return this->rightNodePtr;
}

template <class ItemType>
bool TreeNode<ItemType>::isLeaf()
{
	return (this->leftNodePtr == NULL && this->rightNodePtr == NULL);
}

#endif
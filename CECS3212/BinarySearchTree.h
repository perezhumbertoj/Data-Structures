#pragma once

#include<iostream>
using namespace std;
#include "TreeNode.h"
#include<minmax.h>
#include<string>

template <class ItemType>
class BinarySearchTree
{
private:
	TreeNode<ItemType>* rootPtr; // Pointer to first node
	int itemCount;
public:
	BinarySearchTree();
	~BinarySearchTree();
	bool isEmpty();
	TreeNode<ItemType>* getRoot();
	int getHeight(TreeNode<ItemType>*);
	int getNumberOfNodes();
	ItemType getRootData();
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData);
	void remove(const ItemType& data);
	void clear(TreeNode<ItemType>* root);
	bool contains(const ItemType& anEntry);
	void preorderTraverse(TreeNode<ItemType>* currPtr);
	void preorderTraversePrint();
	void inorderTraverse(TreeNode<ItemType>* currPtr);
	void inorderTraversePrint();
	void postorderTraverse(TreeNode<ItemType>* currPtr);
	void postorderTraversePrint();
	void displayNodeAndNext();
};


//*********************************************************//
//                         CONSTRUCTORS                    //
//*********************************************************//
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	this->rootPtr = NULL;
	itemCount = 0;
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{}

//*********************************************************//
//                         GETTERS/SETTERS                 //
//*********************************************************//
template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData)
{
	if (this->isEmpty())
	{
		this->rootPtr = new TreeNode<ItemType>;
	}

	this->rootPtr->setItem(newData);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData()
{
	if (this->isEmpty())
	{
		cout << "This tree is empty \n";
		exit(0);
	}
	else
	{
		return this->rootPtr->getItem();
	}
}


//*********************************************************//
//                         FUNCTIONS                       //
//*********************************************************//

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
	if (!this->isEmpty())
	{
		TreeNode<ItemType>* currPtr;
		currPtr = this->rootPtr;
		char side; // para cuando acabe el loop saber cual nodo set

		while (currPtr != NULL)
		{
			if (newData == currPtr->getItem())
			{
				cout << "Item already exists" << endl;
				return false;
			}

			else if (newData < currPtr->getItem())
			{
				side = 'l';
				if (currPtr->getLeft() == NULL)
				{
					break;
				}
				currPtr = currPtr->getLeft();
			}

			else if (newData > currPtr->getItem())
			{
				side = 'r';
				if (currPtr->getRight() == NULL)
				{
					break;
				}
				currPtr = currPtr->getRight();
				side = 'r';
			}
		}

		TreeNode<ItemType>* newNode = new TreeNode<ItemType>;
		newNode->setItem(newData);
		if (side == 'l')
		{

			currPtr->setLeft(newNode);
		}
		else if (side == 'r')
		{
			currPtr->setRight(newNode);
		}
		else
		{
			cout << "error setting left or right pointer" << endl;
			return false;
		}

		itemCount++;
		return true;
	}
	else
	{
		this->setRootData(newData);
		itemCount++;
		return true;
	}
}


template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty()
{
	return this->rootPtr == NULL;
}

template <class ItemType>
void  BinarySearchTree<ItemType>::displayNodeAndNext()
{
	TreeNode<ItemType>* leftPtr = this->rootPtr->getLeft();
	TreeNode<ItemType>* rightPtr = this->rootPtr->getRight();

	cout << "left null: " << (leftPtr == NULL) << "right null:" << (rightPtr == NULL) << endl;

	cout << "Root: " << this->getRootData() << endl;
	cout << "Left: " << leftPtr->getItem() << endl;
	cout << "Right: " << rightPtr->getItem() << endl;
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(TreeNode<ItemType>* currPtr)
{
	if (currPtr != NULL)
	{
		if (currPtr->getLeft() != NULL)
			inorderTraverse(currPtr->getLeft());

		//cout << " " << currPtr->getItem() << " ";
		cout << currPtr->getItem() << endl;

		if (currPtr->getRight() != NULL)
			inorderTraverse(currPtr->getRight());
	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::clear(TreeNode<ItemType>* temp)
{
	if (temp != NULL)
	{
		if (temp->getLeft() != NULL)
		{
			clear(temp->getLeft());
		}
		if(temp->getRight() != NULL)
		{
			clear(temp->getRight());
		}
		free(temp);
	}

	if (temp == this->rootPtr)
	{
		this->rootPtr = NULL;
	}
}

template <class ItemType>
TreeNode<ItemType>* BinarySearchTree<ItemType>::getRoot()
{
	return this->rootPtr;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight(TreeNode<ItemType>* temp)
{
	if (temp == NULL || (temp->getLeft() ==	NULL && temp->getRight() == NULL))
		return 0;
	return (max (getHeight(temp->getLeft()), getHeight(temp->getRight())) + 1);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraversePrint()
{
	inorderTraverse(rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(TreeNode<ItemType>* currPtr)
{
	if (currPtr != NULL)
	{
		cout << " " << currPtr->getItem() << " ";
		
		if (currPtr->getLeft() != NULL)
			preorderTraverse(currPtr->getLeft());

		if (currPtr->getRight() != NULL)
			preorderTraverse(currPtr->getRight());

	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraversePrint()
{
	preorderTraverse(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes()
{
	return this->itemCount;
}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains (const ItemType& anEntry) 
{
	TreeNode<ItemType>* currPtr;
	currPtr = this->rootPtr;

	while (currPtr != NULL)
	{
		if (anEntry == currPtr->getItem())
		{
			cout << "Item already exists" << endl;
			return true;
		}

		else if (anEntry < currPtr->getItem())
		{
			if (currPtr->getLeft() == NULL)
			{
				break;
			}
			currPtr = currPtr->getLeft();
		}

		else if (anEntry > currPtr->getItem())
		{
			if (currPtr->getRight() == NULL)
			{
				break;
			}
			currPtr = currPtr->getRight();
		}
		else
			return false;
	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(TreeNode<ItemType>* currPtr)
{
	if (currPtr != NULL)
	{
	
		if (currPtr->getLeft() != NULL)
			postorderTraverse(currPtr->getLeft());

		if (currPtr->getRight() != NULL)
			postorderTraverse(currPtr->getRight());

		//cout << " " << currPtr->getItem() << " ";
		cout << currPtr->getItem() << endl;
	}
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraversePrint()
{
	postorderTraverse(rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::remove(const ItemType& data)
{
	//Locate the element
	bool found = false;
	if (isEmpty())
	{
		cout << " This Tree is empty " << endl;
		return;
	}

	TreeNode<ItemType>* currPtr;
	TreeNode<ItemType>* parent = new TreeNode<ItemType>;
	currPtr = rootPtr;

	while (currPtr != NULL)
	{
		if (currPtr->getItem() == data)
		{
			found = true;
			break;
		}	
	
		else //si no es igual se asigna currPtr a parent y 
		{
			parent = currPtr;
			if (data > currPtr->getItem()) 
				currPtr = currPtr->getRight();
			else 
				currPtr = currPtr->getLeft();
		}
	}
	if (!found)
	{
		cout << " Data not found! " << endl;
		return;
	}


	//*********************************************************//
	//                    NODE CON UN CHILD                    //
	//*********************************************************//

	if ((currPtr->getLeft() == NULL && currPtr->getRight() != NULL) || (currPtr->getLeft() != NULL && currPtr->getRight() == NULL))
	{
		// Nodo de la Izquierda vacio, derecha no
		if (currPtr->getLeft() == NULL && currPtr->getRight() != NULL)
		{
			if ((parent->getRight() != NULL) && (parent->getRight())->getItem() == data)
			{
				parent->setRight(currPtr->getRight());
				delete currPtr;
			}
			else // si la data esta a la izquierda de item
			{
				parent->setLeft(currPtr->getRight());
				delete currPtr;
			}
		}
		else // // Nodo de la derecha vacio, izquierda no
		{
			if ((parent->getLeft() != NULL) && (parent->getLeft())->getItem() == data)
			{
				parent->setLeft(currPtr->getLeft());
				delete currPtr;
			}
			else
			{
				parent->setRight(currPtr->getRight());
				delete currPtr;
			}
		}
		return;
	}

	//*********************************************************//
	//                   NODE Q ES UN lEAF                     //
	//*********************************************************//
	if (currPtr->getLeft() == NULL && currPtr->getRight() == NULL)
	{
		if ((parent->getLeft() != NULL) && (parent->getLeft())->getItem() == data)
		{
			parent->setLeft(NULL);

		}
		else
		{
			parent->setRight(NULL);
		}
		delete currPtr;
		return;
	}


	//*********************************************************//
	//                   NODE CON DOS CHILD                    //
	//*********************************************************//
	// se reemplaza el nodo cn el valor mas pequeno del sub arbol de la derecha
	if (currPtr->getLeft() != NULL && currPtr->getRight() != NULL)
	{
		TreeNode<ItemType>* checkRight;
		checkRight = currPtr->getRight();

		//Si el nodo de la derecha es un leaf
		if ((checkRight->getLeft() == NULL) && (checkRight->getRight() == NULL))
		{
			currPtr->setItem(checkRight->getItem());
			currPtr->setRight(NULL);
			delete checkRight;
			//currPtr = NULL;
		}
		else // si el child de la derecha tiene hijos
		{
			//si el node de la derecha tiene un hijo en la izquierda
			// nos movemos lo mas que podamos a la izquierda para encontrar
			// el child mas pueque~o

			//si el child de la derecha tiene un child en la izquierda
			if ((currPtr->getRight())->getLeft() != NULL)
			{
				TreeNode<ItemType>* leftcurrPtrp;
				TreeNode<ItemType>* leftcurrPtr;

				leftcurrPtrp = currPtr->getRight(); //primer hijo
				leftcurrPtr = (currPtr->getRight())->getLeft(); //segundo hijo
				while (leftcurrPtr->getLeft() != NULL)
				{
					leftcurrPtrp = leftcurrPtr;
					leftcurrPtr = leftcurrPtr->getLeft();
				}
				currPtr->setItem(leftcurrPtr->getItem());
				leftcurrPtrp->setLeft(NULL);
				delete leftcurrPtr;
			}
			else
			{
				TreeNode<ItemType>* tmp;
				tmp = currPtr->getRight();
				currPtr->setItem((currPtr->getRight())->getItem());
				currPtr->setRight((currPtr->getRight())->getRight());
				delete tmp;
				/*TreeNode<ItemType>* tmp;
				int tmpInt;
				tmp = currPtr->getRight();
				tmpInt = tmp->getItem();
				currPtr->setItem(tmpInt);
				currPtr->getRight();
				currPtr = tmp->getRight();
				delete tmp;*/

			}

		}
		return;
	}

}
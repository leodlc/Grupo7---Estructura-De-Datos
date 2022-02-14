#pragma once
#include "Node.h"

using namespace std;

class AVL
{

private:
public:
	int balancing(Node*);
	int max(int, int);
	int measure(Node*);

	Node* createNode(int);

	Node* leftRotation(Node*);
	Node* rightRotation(Node*);

	bool search(Node*, int);

	Node* findMinimum(Node*);
	Node* insert(Node*, int);
	Node* deleteNode(Node*, int);
	void printTree(Node*);
};

int AVL::balancing(Node* tree)
{
	if (tree == NULL)
	{
		return 0;
	}

	return measure(tree->getLeft()) - measure(tree->getRight());
}

int AVL::max(int a, int b)
{
	return(a > b) ? a : b;
}

int AVL::measure(Node* tree)
{
	if (tree == NULL) return 0;
	return tree->getHeight();
}

Node* AVL::createNode(int data)
{
	Node* newNode = new Node();

	newNode->setData(data);
	newNode->setHeight(1);
	newNode->setLeft(NULL);
	newNode->setRight(NULL);

	return newNode;
}

Node* AVL::leftRotation(Node* tree)
{
	Node* x = tree->getRight();
	Node* y = tree->getLeft();

	x->setLeft(tree);
	tree->setRight(y);

	tree->setHeight(max(measure(tree->getLeft()), measure(tree->getRight())) + 1);
	x->setHeight(max(measure(x->getLeft()), measure(x->getRight())) + 1);

	return x;
}

Node* AVL::rightRotation(Node* tree)
{
	Node* y = tree->getLeft();
	Node* x = tree->getRight();

	y->setRight(tree);
	tree->setLeft(x);

	tree->setHeight(max(measure(tree->getLeft()), measure(tree->getRight())) + 1);
	y->setHeight(max(measure(y->getLeft()), measure(y->getRight())) + 1);

	return y;
}

bool AVL::search(Node* tree, int data)
{
	if (tree == NULL)
	{
		return false;
	}
	else if (data == tree->getData())
	{
		return true;
	}
	else if (data < tree->getData())
	{
		search(tree->getLeft(), data);
	}
	else
	{
		search(tree->getRight(), data);
	}
}

Node* AVL::findMinimum(Node* tree)
{
	while (tree->getLeft() != NULL)
	{
		tree = tree->getLeft();
	}

	return tree;
}

Node* AVL::insert(Node* tree, int data)
{
	if (tree == NULL)
	{
		Node* newNode = createNode(data);
		tree = newNode;
	}

	if (data < tree->getData())
	{
		tree->setLeft(insert(tree->getLeft(), data));
	}
	else if (data > tree->getData())
	{
		tree->setRight(insert(tree->getRight(), data));
	}
	else
	{
		return tree;
	}

	tree->setHeight(max(measure(tree->getLeft()), measure(tree->getRight())) + 1);

	int balance = balancing(tree);

	//left left case
	if (balance > 1 && data < tree->getLeft()->getData())
	{
		return rightRotation(tree);
	}

	//right right case
	if (balance < -1 && data > tree->getRight()->getData())
	{
		return leftRotation(tree);
	}

	//left right case
	if (balance > 1 && data > tree->getLeft()->getData())
	{
		tree->setLeft(leftRotation(tree->getLeft()));
		return rightRotation(tree);
	}

	//right left case
	if (balance < -1 && data < tree->getRight()->getData())
	{
		tree->setRight(rightRotation(tree->getRight()));
		return leftRotation(tree);
	}

	return tree;
}

Node* AVL::deleteNode(Node* tree, int data)
{
	if (tree == NULL)
	{
		return tree;
	}

	if (data < tree->getData())
	{
		tree->setLeft(deleteNode(tree->getLeft(), data));
	}
	else if (data > tree->getData())
	{
		tree->setRight(deleteNode(tree->getRight(), data));
	}
	else
	{
		if (tree->getRight() == NULL && tree->getLeft() == NULL)
		{
			free(tree);
			tree = NULL;
		}

		else if (tree->getLeft() != NULL && tree->getRight() == NULL)
		{
			Node* tmp = tree->getLeft();
			tree = tree->getLeft();
			free(tmp);
		}

		else if (tree->getRight() != NULL && tree->getLeft() == NULL)
		{
			Node* tmp = tree->getRight();
			tree = tree->getRight();
			free(tmp);
		}

		else
		{
			Node* tmp = findMinimum(tree->getRight());
			tree->setData(tmp->getData());
			tree->setRight(deleteNode(tree->getRight(), tmp->getData()));
		}
	}

	if (tree == NULL) return tree;

	tree->setHeight(1 + max(measure(tree->getLeft()), measure(tree->getRight())));

	int balance = balancing(tree);

	//left left case
	if (balance > 1 && balancing(tree->getLeft()) >= 0)
	{
		return rightRotation(tree);
	}

	//right right case
	if (balance < -1 && balancing(tree->getRight()) <= 0)
	{
		return leftRotation(tree);
	}

	//left right case
	if (balance > 1 && balancing(tree->getLeft()) < 0)
	{
		tree->setLeft(leftRotation(tree->getLeft()));
		return rightRotation(tree);
	}

	//right left case
	if (balance < -1 && balancing(tree->getRight()) > 0)
	{
		tree->setRight(rightRotation(tree->getRight()));
		return leftRotation(tree);
	}

	return tree;
}

void AVL::printTree(Node* tree)
{
	if (tree == NULL) return;
	cout << tree->getData() << endl;
	printTree(tree->getLeft());
	printTree(tree->getRight());
}
#pragma once
#include <iostream>
#include "Node.h"
#include "AVL.h"

using namespace std;

class TreeTools
{

private:
public:
	int returnHeight(Node*);
	int depth(Node*);
	int returnDepth(Node*, int, int);

};

int TreeTools::returnHeight(Node* tree)
{
	if (tree == NULL) return -1;

	int leftHeight = returnHeight(tree->getLeft());
	int rightHeight = returnHeight(tree->getRight());

	if (leftHeight >= rightHeight) return leftHeight + 1;
	else return rightHeight + 1;
}

int TreeTools::depth(Node* tree)
{
	AVL objTree;
	int dato;
	int depth = 0;
	if (tree == NULL) return -1;

	cout << "Profundidad del dato -> ";
	cin >> dato;

	if (objTree.search(tree, dato) == true)
	{
		depth = returnDepth(tree, dato, depth);
		cout << "La profundidad del dato " << dato << " es: " << depth << endl;
		cout << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "El elemento " << dato << " NO existe en el arbol" << endl;
		cout << endl;
		system("pause");
		system("cls");
	}

}

int TreeTools::returnDepth(Node* tree, int dato, int depth)
{
	if (tree == NULL)
	{
		return -1;
	}
	else if (tree->getData() == dato)
	{
		return depth;
	}
	else if (dato < tree->getData())
	{
		depth++;
		returnDepth(tree->getLeft(), dato, depth++);
	}
	else
	{
		depth++;
		returnDepth(tree->getRight(), dato, depth++);
	}
}
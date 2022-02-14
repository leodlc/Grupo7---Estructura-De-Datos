#pragma once
#include <iostream>
#include "Nodo.h"
#include "Arbol.h"

using namespace std;

class TreeTools
{

private:
public:
	int returnHeight(Nodo*);
	int depth(Nodo*);
	int returnDepth(Nodo*, int, int);
	//int returnWidth(Nodo*);

};

int TreeTools::returnHeight(Nodo* tree)
{
	if (tree == NULL) return -1;
	
	int leftHeight = returnHeight(tree->getIzq());
	int rightHeight = returnHeight(tree->getDer());
	
	if (leftHeight >= rightHeight) return leftHeight + 1;
	else return rightHeight + 1;
}

int TreeTools::depth(Nodo* tree)
{
	Arbol objArbol;
	int dato;
	int depth = 0;
	if (tree == NULL) return -1;

	cout << "Profundidad del dato -> ";
	cin >> dato;

	if (objArbol.buscar(tree, dato) == true)
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

int TreeTools::returnDepth(Nodo* tree, int dato, int depth)
{
	if (tree == NULL)
	{
		return -1;
	}
	else if (tree->getDato() == dato)
	{
		return depth;
	}
	else if (dato < tree->getDato())
	{
		depth++;
		returnDepth(tree->getIzq(), dato, depth++);
	}
	else
	{
		depth++;
		returnDepth(tree->getDer(), dato, depth++);
	}
}
#pragma once
#include <iostream>

using namespace std;

class Matriz {

private:
	int dimension;
	int** matrix;

public:

	Matriz();
	Matriz(int dim);

	int** getMatriz();
	void setMatriz(int**);

	int getDimension();
	void setDimension(int);

	int** segmentarMatriz(int);
	void encerarMatriz(int);
	void ingreso(int dimension);
	void imprimir(int dimension);

};

	Matriz::Matriz() = default;

	Matriz::Matriz(int dim)
	{
		this->matrix = segmentarMatriz(dim);
		this->dimension = dim;
	}

	int** Matriz::getMatriz()
	{
		return this->matrix;
	}

	void Matriz::setMatriz(int** mat)
	{
		this->matrix = mat;
	}

	int Matriz::getDimension()
	{
		return this->dimension;
	}

	void Matriz::setDimension(int dim)
	{
		this->dimension = dim;
	}

	int** Matriz::segmentarMatriz(int dimension)
	{
		int** matriz, i;

		//casting de una dimension a doble dimension para crear una matriz de n*n
		matriz = (int**)malloc(dimension * sizeof(int*));

		for (i = 0; i < dimension; i++)
		{
			//casting numero int a direccion unidimensional para ir partiendo la matriz
			*(matriz + i) = (int*)malloc(dimension * sizeof(int));
		}

		return matriz;
	}

	//ENCERAR: Llenar de ceros
	void Matriz::encerarMatriz(int dimension)
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				*(*(this->matrix + i) + j) = 0;
			}
		}

		return;
	}

	void Matriz::ingreso(int dimension)
	{
		int valor;
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				cout << "Fila " << i + 1 << " / " << "Columna " << j + 1 << ": ";
				cin >> valor;
				cout << "\n";
				*(*(this->matrix + i) + j) = valor;
			}
		}
	}

	void Matriz::imprimir(int dimension)
	{
		cout << endl;
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				cout << "   " << *(*(this->matrix + i) + j) << "   ";
			}
			cout << "\n";
		}

		cout << endl;
	}
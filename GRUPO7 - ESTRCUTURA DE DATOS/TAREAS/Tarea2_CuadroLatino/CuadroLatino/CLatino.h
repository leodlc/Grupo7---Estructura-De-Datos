#pragma once
#include "Matriz.h"

class CLatino
{

private:
public:
	void crearCuadro(Matriz);

};

void CLatino::crearCuadro(Matriz matrix)
{
	int** matA = matrix.getMatriz();
	for (int i = 0; i < matrix.getDimension(); i++)
	{
		for (int j = 0; j < matrix.getDimension(); j++)
		{
			if (i == 0)
			{
				matA[i][j] = j + 1;
			}
			else
			{
				if (matA[i - 1][j] < matrix.getDimension())
				{
					matA[i][j] = matA[i - 1][j] + 1;
				}
				else
				{
					matA[i][j] = 1;
				}
			}
		}
	}
}

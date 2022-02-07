#include <iostream>
#include "CLatino.h"
#include "Matriz.h"
#include "Tools.h"

using namespace std;

int main()
{
	Tools tls;
	int dimension;

	cout << "CUADRADO LATINO" << endl;

	do
	{
		dimension = tls.validate_int("\nIngrese la dimension del cuadro: ");
	} while (dimension < 1 || dimension % 2 == 0);

	Matriz mat(dimension);
	CLatino cuadroLatino;

	mat.segmentarMatriz(dimension);
	mat.encerarMatriz(dimension);

	cuadroLatino.crearCuadro(mat);

	mat.imprimir(dimension);

	return 0;

}
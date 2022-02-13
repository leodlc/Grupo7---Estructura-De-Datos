
/* UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES:
*Leonardo de la Cadena
*Edwin Paez
*TEMA: Sudoku
*FECHA DE CREACION : 13 DE FEBRERO DEL 2022
*FECHA DE MODIFICACION: 13 DE FEBRERO 2022
*/
#include <iostream>
#include "Sudoku.h"
using namespace std;

int main()
{
    int tablero[9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
    };
	
	imprimirSudoku(tablero);
	resolverSudoku(tablero, 0, 0);
	imprimirSudoku(tablero);
    return 0;
}


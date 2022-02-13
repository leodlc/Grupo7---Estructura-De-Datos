#pragma once
#include <iostream>
#include <vector>
using namespace std;
void imprimirSudoku(int arr[9][9])
{
	cout << "--------------------------------------" << endl;

	for (int fila=0; fila < 9; fila++) {
		for (int celda= 0; celda< 9; celda++)
			cout << arr[fila][celda] << " ";
		cout << endl;

		
		
	}
	cout << "---------------------------------------" << endl;
}
bool puedeColocar(int arr[9][9], int fila, int columna,int n) {
	if (arr[fila][columna] != 0) return false;
	bool estado = true;
	int cuadriculaX = (columna / 3) * 3;
	int cuadriculaY = (fila / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (arr[fila][i] == n) { estado = false; break; }
		if (arr[i][columna] == n) { estado = false; break; }
		if (arr[cuadriculaY + i / 3][cuadriculaX + i % 3] == n) {
			estado = false;
			break;
		}
		
	}
	return estado;
}
vector<int>encontrarColocables(int arr[9][9], int fila, int columna) {
	vector<int> cps = {};
	for (int i = 1; i <= 9; i++) {
		if (puedeColocar(arr, fila, columna, i))
			cps.push_back(i);
	}
	return cps;
}


//funcion que resuelve con backtracking
void copiarArreglo(int arr[9][9], int copiaArr[9][9]) {
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
			copiaArr[y][x] = arr[y][x];
}
void siguienteVacio(int arr[9][9], int fila, int columna, int &nFila, int &nColumna) {
	int indice = 9 * 9;
	for (int i = fila * 9 + columna + 1; i < 9 * 9; i++) {//explora todas las posibilidades
		if (arr[i / 9][i % 9] == 0) {
			indice = i;
			break;
		}
	} 
	nFila = indice / 9;
	nColumna = indice % 9;
	



}
bool resolverSudoku(int arr[9][9], int fila, int columna) {
	/*system("cls");
	imprimirSudoku(arr);*/ // muestra todo el proceso para imprimir todas las posibilidades
	if (fila > 8)return true;
	if(arr[fila][columna]!=0){
		int siguienteColumna, siguienteFila;
		siguienteVacio(arr, fila, columna, siguienteFila, siguienteColumna);
		return resolverSudoku(arr, siguienteFila, siguienteColumna);
	}
	vector<int> colocables = encontrarColocables(arr, fila, columna);
	if (colocables.size() == 0)return false;
	bool estado = false;
	//parte que busca todas las posibilidades
	for (int i = 0; i < colocables.size(); i++) {
		int n = colocables[i];
		int copiaArr[9][9];
		copiarArreglo(arr, copiaArr);
		copiaArr[fila][columna] = n;
		int siguienteColumna, siguienteFila;
		siguienteVacio(copiaArr, fila, columna, siguienteFila, siguienteColumna);
		if (resolverSudoku(copiaArr, siguienteFila, siguienteColumna)) {
			copiarArreglo(copiaArr, arr);
			estado = true;
			break;
		}
	}

	return estado;
}



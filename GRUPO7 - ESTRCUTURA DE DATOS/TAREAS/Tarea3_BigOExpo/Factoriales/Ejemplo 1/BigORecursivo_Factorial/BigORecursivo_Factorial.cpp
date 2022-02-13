/* UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES:
*Leonardo de la Cadena
*Edwin Paez
*TEMA: Analisis de funciones recursivas con notacion Big O - Factorial
*FECHA DE CREACION : 10 DE FEBRERO DEL 2022
*FECHA DE MODIFICACION: 10 DE FEBRERO 2022
*/
#include <iostream>
#include "FuncionRecursiva.h"
using namespace std;


int main()
{
    FuncionRecursiva<int>n;
    int input;
    cout << "Ingrese el numero para calcular su factorial: " ;

    while (!(cin >> input)) {
        system("cls");
        cout << "Valor Incorrecto!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el numero para calcular su factorial:  ";
    }
    n.setN(input);
    cout<<"El factorial de "<<input<<" es: " << n.factorial(input)<<endl;
    return 0;
    
}


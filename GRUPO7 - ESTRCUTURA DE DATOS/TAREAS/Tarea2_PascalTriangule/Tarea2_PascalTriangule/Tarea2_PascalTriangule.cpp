#include "PascalOperation.h"
#include "Validates.h"
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int nrows;
    PascalOperation triangule;
    cout << "Ingrese el numero de filas del triangulo: " ;
    cin >> nrows;
    /*while (nrows <= 0) {
        system("cls");
        cout << "Ingresa un numero positivo";
        
        cin >> nrows;
    }*/
    while (!(cin >> nrows)) {
        system("cls");
        cout << "Valor Incorrecto!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el numero de filas del triangulo: ";
    }
    triangule.generatePascalTriangule(nrows);
     
    
  
}


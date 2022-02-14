#pragma once
#include <iostream>
#include "Arbol.h"
#include "TreeTools.h"
#include "Nodo.h"

using namespace std;

class Menu
{

    private:
        Nodo* arbol = NULL;

    public:
        void yMenu();
        void xMenu();

};

void Menu::yMenu()
{
    Arbol objArbol;
    int subOpcion = 0;

    while(subOpcion != 4)
    {
        cout << "\n 1. PREORDEN";
        cout << "\n 2. INORDEN";
        cout << "\n 3. POSTORDEN";
        cout << "\n 4. REGRESAR";

        cout << "\n\n -> Digite una opcion: ";
        cin >> subOpcion;

        system("cls");

        if(subOpcion == 1)
        {
            objArbol.preOrden(this->arbol);
            cout << endl;

            system("pause");
            system("cls");
        }
        else if(subOpcion == 2)
        {
            objArbol.inOrden(this->arbol);
            cout << endl;

            system("pause");
            system("cls");
        }
        else if(subOpcion == 3)
        {
            objArbol.postOrden(this->arbol);
            cout << endl;

            system("pause");
            system("cls");
        }
    }
}

void Menu::xMenu()
{
    Arbol objArbol;
    TreeTools tool;
    int contador = 0;
    int opcion = 0;
    int dato = 0;

    while(opcion != 7)
    {
        cout << "\n 1. Insertar Nodo";
        cout << "\n 2. Mostrar Arbol";
        cout << "\n 3. Buscar en el arbol";
        cout << "\n 4. Recorridos de un arbol";
        cout << "\n 5. Altura";
        cout << "\n 6. Profundidad de un dato";
        cout << "\n 7. Salir";
        
        cout << "\n\n -> Digite una opcion: ";
        cin >> opcion;

        system("cls");

        switch(opcion)
        {
            case 1:
                cout << "\n Ingrese un dato: ";
                cin >> dato;
                objArbol.insertarNodo(this->arbol, dato);
                cout << endl;
                
                system("pause");
                system("cls");
            break;
            case 2:
                objArbol.mostrar(this->arbol);

                system("pause");
                system("cls");
            break;
            case 3:
                cout << "Digite un dato para buscar: ";
                cin >> dato;

                if(objArbol.buscar(this->arbol, dato) == true)
                {
                    cout << "El elemento " << dato << " existe en el arbol" << endl;
                }
                else
                {
                    cout << "El elemento " << dato << " NO existe en el arbol" << endl;
                }
                cout << endl;

                system("pause");
                system("cls");
            break;
            case 4:
                yMenu();
                cout << endl;

                system("pause");
                system("cls");
            break;
            case 5:
                cout << "La altura del arbol es: " << tool.returnHeight(this->arbol) << endl;
                cout << endl;
                system("pause");
                system("cls");
            break;
            case 6:
                tool.depth(this->arbol);
            break;
            case 7:
                system("pause");
                system("exit");
            break;
        }
    }
}
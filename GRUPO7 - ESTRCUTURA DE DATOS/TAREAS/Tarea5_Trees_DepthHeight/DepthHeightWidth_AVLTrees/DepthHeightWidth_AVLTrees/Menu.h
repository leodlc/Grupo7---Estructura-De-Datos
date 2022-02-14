#pragma once
#include <iostream>
#include "AVL.h"
#include "TreeTools.h"
#include "Node.h"

using namespace std;

class Menu
{

private:
    Node* tree = NULL;

public:
    void xMenu();

};

void Menu::xMenu()
{
    AVL objTree;
    TreeTools tool;
    int contador = 0;
    int opcion = 0;
    int data = 0;

    while (opcion != 7)
    {
        cout << "\n 1. Insertar Nodo";
        cout << "\n 2. Mostrar Arbol";
        cout << "\n 3. Buscar en el arbol";
        cout << "\n 4. Altura";
        cout << "\n 5. Profundidad de un dato";
        cout << "\n 6. Borrar nodo";
        cout << "\n 7. Salir";

        cout << "\n\n -> Digite una opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion)
        {
        case 1:
            cout << "\n Ingrese un dato: ";
            cin >> data;
            this->tree = objTree.insert(this->tree, data);
            cout << endl;

            system("pause");
            system("cls");
            break;
        case 2:
            objTree.printTree(this->tree);

            system("pause");
            system("cls");
            break;
        case 3:
            cout << "TODO implement" << endl;

            system("pause");
            system("cls");
            break;
        case 4:
            cout << "La altura del arbol es: " << tool.returnHeight(this->tree) << endl;
            cout << endl;
            system("pause");
            system("cls");
            break;
        case 5:
            tool.depth(this->tree);
            break;
        case 6:
            cout << "\n Dato a borrar: ";
            cin >> data;
            this->tree = objTree.deleteNode(this->tree, data);
            cout << endl;

            system("pause");
            system("cls");
            break;
        case 7:
            system("pause");
            system("exit");
            break;
        }
    }
}
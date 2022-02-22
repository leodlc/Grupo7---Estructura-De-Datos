#pragma once
#include <conio.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Tools.h"
#include "AsyncScrollDetect.h"
#include <string>
#include "BinaryTree.h"
#include "Node.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

using namespace std;

class MyMenu
{

private:
        Node* tree = NULL;
public:
	int showCaptureOp(string, vector<std::string>, int);
	void principalMenu();

};

int MyMenu::showCaptureOp(string name, vector<std::string> options, int count)
{
	Tools tool;
	int option = 1;
    int key;

	bool repeat = true;

	do {

		system("cls");
		
		cout << "\t" << name << endl;
		tool.gotoxy(5, 1 + option);
		cout << "=>";

		for (int i = 1; i <= count; i++)
		{
			tool.gotoxy(12, 1 + i);  cout << i << ". " << options[i - 1];
		}

		do {		
			
			key = _getch();

		} while (key != KEY_UP && key != KEY_DOWN && key != ENTER);

		switch(key)
        {
            case KEY_UP:
                option--;
                if (option == 0) option = count;
            break;
            case KEY_DOWN:
                option++;
                if (option > count) option = 1;
            break;
            case ENTER:
                repeat = false;
            break;
        }
		
	} while (repeat);

	return option;
}

void MyMenu::principalMenu()
{
	BinaryTree binary;
	vector<std::string> options = {"Buscar palabra", "Agregar palabra", "Ver diccionario completo", "Salir"};
	bool repeat = true;
	int option;
	string data, meaning;
	Tools tool;
	binary.initProgram(this->tree);
	do
	{
		system("cls");

		//Menu Title & Options
		option = showCaptureOp("Menu Diccionario", options, 4);

		//alternatives
		switch (option)
		{
		case 1:
			system("cls");
			data = tool.validate_char("Ingrese la palabra que quiere buscar: ");
			binary.search(this->tree, data);
			break;
		case 2:
			system("cls");
			data = tool.validate_char("Ingrese la palabra que quiere agregar: ");
			cout << "Ingrese el significado: " << endl;
			cout << "-> ";
			cin >> meaning;
			binary.insertNew(this->tree, data, meaning);
			break;
		case 3:
			system("cls");
			cout << "Saliendo... Presione una tecla para continuar" << endl;
			_getch();
			repeat = false;
			break;
		}

	} while (repeat);
}

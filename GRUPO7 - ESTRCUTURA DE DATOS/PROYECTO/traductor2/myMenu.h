#pragma once
#pragma once
#include <conio.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Tools.h"
#include "AsyncScrollDetect.h"
#include <string>
#include "DiccionarioG.h"
#include "ArbolBinario.h"
#include "NodoArbol.h"
#include "Ingreso.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

using namespace std;

class MyMenu
{

private:
public:
	//MyMenu();
	int showCaptureOp(string, vector<std::string>, int);
	void principalMenu();

};
//MyMenu::MyMenu() {
//
//}
int MyMenu::showCaptureOp(string name, vector<std::string> options, int count)
{
	Tools tool;
	int option = 1;
	COORD* ops = new COORD[count];

	bool repeat = true;

	do {

		system("cls");

		cout << "\t" << name << endl;
		tool.gotoxy(5, 1 + option);
		cout << ">>";

		for (int i = 1; i <= count; i++)
		{
			tool.gotoxy(12, 1 + i);  cout << i << ". " << options[i - 1];
		}

		bool rep = true;

		do {

			int d = GetScrollDelta();

			if (tool.keyPressed(VK_UP) || d == 1) {
				option--;
				if (option == 0) option = count;
				rep = false;
			}
			if (tool.keyPressed(VK_DOWN) || d == -1) {
				option++;
				if (option > count) option = 1;
				rep = false;
			}
			if (tool.keyPressed(ENTER) || tool.keyPressed(VK_RBUTTON)) {
				rep = false;
				repeat = false;
			}

		} while (rep);

	} while (repeat);

	return option;
}

void MyMenu::principalMenu()
{
	int choice;
	NodoArbol* aIngles = NULL;
	NodoArbol* aEspaniol = NULL;
	NodoArbol* aPronunciacion = NULL;
	ArbolBinario tree;
	tree.llenarDiccionario(aIngles, aEspaniol, aPronunciacion);
	Ingreso input;
	string translate;
	vector<std::string> options = { "Traducir a espaniol", "Translate word to english", "Salir" };
	bool repeat = true;
	int option;

	do
	{
		system("cls");

		//Menu Title & Options
		option = showCaptureOp("Menu Diccionario", options, 3);

		//alternatives
		switch (option)
		{
		case 1:
			
			system("cls");
			//cout << "  implement searchWord";
			DiccionarioG dictionary;
			dictionary.diccionario();
			_getch();
			break;
		case 2:
			system("cls");
			cout << "implement addWord" << endl;
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

#pragma once
//#include <winbgim.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stralign.h>
#include <windows.h>
#include "ArbolBinario.h"
#include "Ingreso.h"
#include "myMenu.h"

class DiccionarioG {
public:
	//void lineas();
	//void defaulto();
	void diccionario();
	string minuscula(string);
};
string DiccionarioG::minuscula(string palabra) {
	string aux;
	for (int i = 0; i < palabra.length(); i++) {
		aux = tolower(palabra.at(i));
		palabra.replace(i, 1, aux.c_str());
	}
	return palabra;
}



void DiccionarioG::diccionario() {
	
	NodoArbol* aIngles = NULL;
	NodoArbol* aEspaniol = NULL;
	NodoArbol* aPronunciacion = NULL;
	ArbolBinario tree;
	tree.llenarDiccionario(aIngles, aEspaniol, aPronunciacion);
	Ingreso input;
	string translate;
	
	fflush(stdin);
	cout << "Ingrese la palabra a traducir: ";
	getline(cin,translate);
	fflush(stdin);
	//translate = input.ingresarString("Ingrese la palabra a traducir"); //no vale est
	
	translate.c_str();
	cout << tree.Traduccion(aIngles, aEspaniol, minuscula(translate)).c_str() << endl;;
	

	//FUNCIONES DEL ANTERIOR PROGRAMA CON GRAPHICS

	/*initwindow(600, 600);
	defaulto();
	lineas();
	setcolor(15);
	settextstyle(8, 0, 4);
	outtextxy(65, 295, "Dictionary");
	outtextxy(95, 260, "English");
	outtextxy(330, 260, "Diccionario");
	outtextxy(355, 295, "Espaniol");*/
	/*char tecla;
	int i = 0;*/
	
	//do {
	//	
		/*tecla = getch();
		switch (tecla) {
		case 75:
			if (i != 1) {
				i = 1;
				setfillstyle(1, 15);
				floodfill(425, 170, 8);
				setcolor(15);
				outtextxy(330, 260, "Diccionario");
				outtextxy(355, 295, "Espaniol");
				lineas();
				setcolor(1);
				setfillstyle(1, 1);
				rectangle(150, 150, 180, 200);
				floodfill(165, 170, 1);
				line(140, 200, 166, 230);
				line(190, 200, 164, 230);
				line(140, 200, 190, 200);
				floodfill(165, 210, 1);
			}
			break;
		case 77:
			if (i != 2) {
				i = 2;
				setcolor(15);
				setfillstyle(1, 15);
				floodfill(165, 170, 8);
				outtextxy(65, 295, "Dictionary");
				outtextxy(95, 260, "English");
				lineas();
				setcolor(1);
				setfillstyle(1, 1);
				rectangle(410, 150, 440, 200);
				floodfill(425, 170, 1);
				line(400, 200, 426, 230);
				line(450, 200, 424, 230);
				line(400, 200, 450, 200);
				floodfill(425, 210, 1);
			}
			break;
		case 13:
			if (i == 1 || i == 2) {
				Ingreso ingresar;
				cleardevice();
				defaulto();
				lineas();
				string traducir;
				setcolor(15);
				settextstyle(8, 0, 3);
				if (i == 1) {
					outtextxy(105, 60, "Enter the word to translate");
					getch();
					traducir = ingresar.ingresarString("Enter the word to translate");
					cleardevice();
					defaulto();
					lineas();
					setcolor(15);
					outtextxy(50, 60, "Original word");
					outtextxy(315, 60, "Traduced word");
					outtextxy(50, 110, traducir.c_str());
					outtextxy(315, 110, tree.Traduccion(aIngles, aEspaniol, minuscula(traducir)).c_str());
					Sleep(3000);
				}
				else if (i == 2) {
					outtextxy(90, 60, "Ingrese la palabra a traducir");
					getch();
					traducir = ingresar.ingresarString("Ingrese la palabra a traducir");
					cleardevice();
					defaulto();
					lineas();
					setcolor(15);
					outtextxy(50, 60, "Palabra Original");
					outtextxy(315, 60, "Palabra Traducida");
					outtextxy(50, 110, traducir.c_str());
					outtextxy(315, 110, tree.Traduccion(aEspaniol, aIngles, minuscula(traducir)).c_str());
					outtextxy(315, 160, tree.Traduccion(aEspaniol, aPronunciacion, minuscula(traducir)).c_str());
					tree.voz(tree.Traduccion(aEspaniol, aIngles, minuscula(traducir)));
					Sleep(3000);
				}
				cleardevice();
				defaulto();
				lineas();
				setcolor(15);
				settextstyle(8, 0, 4);
				outtextxy(65, 295, "Dictionary");
				outtextxy(95, 260, "English");
				outtextxy(330, 260, "Diccionario");
				outtextxy(355, 295, "Espaniol");
			}
		}*/
	//} while (repeat);
}
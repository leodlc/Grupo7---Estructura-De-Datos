#pragma once
#include <conio.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Tools.h"
#include <string>
#include "BinaryTree.h"
#include "Node.h"
#include "marquee.h"
#include "auth.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

using namespace std;

class MyMenu
{

private:
        Node* tree = NULL;
		bool running = false;
public:
	int showCaptureOp(string, vector<std::string>, int);
	void principalMenu();
	void showAuthMenu();
	bool enterToMain();
	void stop();
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
	//showAuthMenu();
	BinaryTree binary;
	Marquee marquee("Universidad de las fuerzas armadas ESPE - Grupo 7", Console::get().get_console_size().X - 3);
	cout << "\n " << endl;
	cout << "\n " << endl;
	vector<std::string> options = {"Buscar palabra", "Agregar palabra", "Ver diccionario completo","Pixelar Imagen", "Salir"};
	bool repeat = true;
	int option;
	string data, meaning;
	Tools tool;
	binary.initProgram(this->tree);
	do
	{
		system("cls");

		//Menu Title & Options
		
		cout << "\n " << endl;
		cout << "\n " << endl;
		
		option = showCaptureOp("\n Menu Diccionario", options, 5);

		//alternatives
		switch (option)
		{
		case 1:
			system("cls");
			data = tool.validate_char("\nIngrese la palabra que quiere buscar: ");
			binary.search(this->tree, data);
			break;
		case 2:
			system("cls");
			data = tool.validate_char("\nIngrese la palabra que quiere agregar: ");
			cout << "Ingrese el significado: " << endl;
			cout << "-> ";
			cin >> meaning;
			binary.insertNew(this->tree, data, meaning, NULL);
			break;
		case 3:
			system("cls");
			binary.show(this->tree);
			_getch();
			break;
		case 4:

			break;
		case 5:
			system("cls");
			cout << "\nSaliendo... Presione una tecla para continuar" << endl;
			_getch();
			repeat = false;
			break;
		}
		
	} while (repeat);
	marquee.display();
	exit(0);
	
}
void MyMenu::showAuthMenu() {
	MyMenu menu;
	bool repeat2 = true;
	int option;
	vector<std::string> optionsAuth = { "Ingresar", "Registrarse", "Salir"};
	Auth auth;
	std::string username;
	std::string password;
	std::string usernameR;
	std::string passwordR;
	std::string password2;
	do {
		system("cls");
		option = showCaptureOp("\n Autentificacion", optionsAuth, 3);
		switch (option) {
		case 1:
			
			system("cls");
			do {
				username = utils::read_line("Ingrese el nombre de usuario: ");
			} while (username.empty());

			do {
				password = utils::read_password("Ingrese una contrasenia: ");
			} while (password.empty());

			if (!auth.userExists(username)) {
				std::cout << std::endl << "[usuario no existe]" << std::endl << std::endl;
				system("pause");
				return;
			}

			if (auth.login(username, password)) {
				menu.stop();
				principalMenu();
			}
			else {
				std::cout << std::endl << "[Credenciales incorrectas]" << std::endl << std::endl;
				system("pause");
			}
			break;
		case 2:
			system("cls");
			usernameR = utils::read_line("Ingrese el nombre de usuario: ");

			do {
				passwordR = utils::read_password("Ingrese una contrasenia: ");

				if (passwordR.length() < 4) {
					std::cout << std::endl << "[La contrasenia debe tener 4 caracteres minimo]" << std::endl;
					continue;
				}

				password2 = utils::read_password("Ingrese una contrasenia: ");

				if (passwordR != password2) {
					std::cout << std::endl << "[Las contrasenias no coinciden]" << std::endl;
					continue;
				}

				auth.registerUser(User(usernameR, passwordR));
				std::cout << std::endl << "[usuario registrado con exito]" << std::endl;
				
				break;
			} while (true);
			break;
		case 3:
			_getch();
			repeat2 = false;
			break;
			
		}

	} while (repeat2);
	system("cls");
}
bool MyMenu::enterToMain() {
	std::string username = utils::read_line("Ingrese el usuario: ");
	std::string password = utils::read_password("Ingrese la contrasenia: ");

	return false;
}
void MyMenu::stop() {
	running = false;
}

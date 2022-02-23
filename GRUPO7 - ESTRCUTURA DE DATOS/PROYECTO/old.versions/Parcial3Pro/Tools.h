#pragma once
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

class Tools
{
private:
public:
	int validate_int(const char*);
	string validate_char(const char*);
	void gotoxy(int, int);
	int keyPressed(int);
	int arrowPressed(int);
	COORD GetConsoleCursorPosition();
	COORD GetMouseClick();
};

int Tools::validate_int(const char* msg)
{
	int value;
	char data[5];
	char c;
	int i = 0;
	printf("%s", msg);
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			data[i++] = c;
		}
	}
	data[i] = '\0';
	value = atoi(data);
	return value;
}

string Tools::validate_char(const char* msg)
{
	string value;
	char data[30];
	char c;
	int i = 0;
	printf("%s", msg);
	while ((c = _getch()) != 13) {
		if (c >= 'a' && c <= 'z') {
			printf("%c", c);
			data[i++] = c;
		}
	}
	cout << endl;
	data[i] = '\0';
	value.assign(data, i);
	return value;
}

void Tools::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Tools::keyPressed(int key)
{
	return (GetAsyncKeyState(key) & 0x8000 != 0);
}

COORD Tools::GetConsoleCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleCursor;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tmp;
	POINT point;

	if (GetConsoleScreenBufferInfo(hConsoleOutput, &consoleCursor)) {
		tmp.X = consoleCursor.dwCursorPosition.X;
		tmp.Y = consoleCursor.dwCursorPosition.Y;
		point.x = tmp.X;
		point.y = tmp.Y;
		if (ClientToScreen(GetConsoleWindow(), &point) == 1) {
			tmp.X = point.x;
			tmp.Y = point.y;
			return tmp;
		}
		else
		{
			cout << "error" << endl;
			system("pause");
			system("exit");
		}
	}
	else
	{
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

COORD Tools::GetMouseClick()
{
	COORD coor{};
	POINT point;

	if (keyPressed(VK_RBUTTON))
	{
		GetCursorPos(&point);
		//if (ClientToScreen(GetConsoleWindow(), &point) == 1) {
		coor.X = point.x;
		coor.Y = point.y;
		return coor;
		//}

	}
	return coor;
}
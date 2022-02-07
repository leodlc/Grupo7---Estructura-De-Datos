#pragma once
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

class Tools
{
private:
public:
	int validate_int(const char*);
};

int Tools::validate_int(const char *msg)
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

#include <iostream>
#include <conio.h>
#include "menu.h"
#include "pixelatedImg.h"

using namespace std;

int main()
{

	MyMenu menu;
	//menu.principalMenu();
	menu.showAuthMenu();
    std::cout << "Patrocinado por:\n";
    pixel pix("espe.png", 48);
    //pix.gris_escala();
    pix.console_font_size(2, 2);
    //pix.tamaño(50,50); 
    pix.mostrar();
    pix.archivo("ascii_art.txt");

	return 0;

}
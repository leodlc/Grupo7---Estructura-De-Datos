#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

class Nodo
{

    private:
        int dato;
        Nodo* izq;
        Nodo* der;

    public:
        void setDato(int);
        int getDato();

        void setIzq(Nodo*);
        Nodo*& getIzq();

        void setDer(Nodo*);
        Nodo*& getDer();

};

void Nodo::setDato(int _dato)
{
    this->dato = _dato;
}

int Nodo::getDato()
{
    return this->dato;
}

void Nodo::setIzq(Nodo* izquierda)
{
    this->izq = izquierda;
}

Nodo*& Nodo::getIzq()
{
    return this->izq;
}

void Nodo::setDer(Nodo* derecha)
{
    this->der = derecha;
}

Nodo*& Nodo::getDer()
{
    return this->der;
}
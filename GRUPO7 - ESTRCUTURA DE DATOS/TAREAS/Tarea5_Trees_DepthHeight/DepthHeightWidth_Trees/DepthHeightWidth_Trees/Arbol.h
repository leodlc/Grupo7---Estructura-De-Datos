#pragma once
#include <iostream>
#include "Nodo.h"

using namespace std;

class Arbol
{

    private:
        Nodo* arbol = NULL;

    public:
        void setArbol(Nodo*);
        Nodo* getArbol();

        Nodo* crearNodo(int);

        void insertarNodo(Nodo*&, int);
        void mostrar(Nodo*);
        bool buscar(Nodo*, int);

        void preOrden(Nodo*);
        void inOrden(Nodo*);
        void postOrden(Nodo*);

};

void Arbol::setArbol(Nodo* _arbol)
{
    this->arbol = _arbol;
}

Nodo* Arbol::getArbol()
{
    return this->arbol;
}

Nodo* Arbol::crearNodo(int _dato)
{
    Nodo* nuevoNodo = new Nodo();

    nuevoNodo->setDato(_dato);
    nuevoNodo->setDer(NULL);
    nuevoNodo->setIzq(NULL);

    return nuevoNodo;
}

void Arbol::insertarNodo(Nodo*& arbol, int dato)
{
    if(arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else
    {
        int raiz = arbol->getDato();
        if(dato < raiz)
        {
            insertarNodo(arbol->getIzq(), dato);
        }
        else
        {
            insertarNodo(arbol->getDer(), dato);
        }
    }
}

void Arbol::mostrar(Nodo* arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        cout << arbol->getDato() << endl;
        mostrar(arbol->getIzq());
        mostrar(arbol->getDer());
    }
}

bool Arbol::buscar(Nodo* arbol, int dato)
{
    if(arbol == NULL)
    {
        return false;
    }
    else if(dato == arbol->getDato())
    {
        return true;
    }
    else if(dato < arbol->getDato())
    {
        buscar(arbol->getIzq(), dato);
    }
    else
    {
        buscar(arbol->getDer(), dato);
    }
}

void Arbol::preOrden(Nodo* arbol)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        cout << arbol->getDato() << " ";
        preOrden(arbol->getIzq());
        preOrden(arbol->getDer());
    }
}

void Arbol::inOrden(Nodo* arbol)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        inOrden(arbol->getIzq());
        cout << arbol->getDato() << " ";
        inOrden(arbol->getDer());
    }
}

void Arbol::postOrden(Nodo* arbol)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        postOrden(arbol->getIzq());
        postOrden(arbol->getDer());
        cout << arbol->getDato() << " ";
    }
}
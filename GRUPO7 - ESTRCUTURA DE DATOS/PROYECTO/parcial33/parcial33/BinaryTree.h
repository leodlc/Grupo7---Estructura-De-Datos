#pragma once
#include <iostream>
#include "Node.h"
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

class BinaryTree
{

    private:
        Node* tree = NULL;

    public:
        void setTree(Node*);
        Node* getTree();

        Node* createNew(string, string);

        void initProgram(Node*&);

        int compare(string, string);
        void insert(Node*&, string, string);
        void insertNew(Node*&, string, string);
        void show(Node*, int);
        void search(Node*, string);

        /* void preOrden(Node*);
        void inOrden(Node*);
        void postOrden(Node*); */

};

void BinaryTree::setTree(Node* _tree)
{
    this->tree = _tree;
}

Node* BinaryTree::getTree()
{
    return this->tree;
}

void BinaryTree::initProgram(Node*& tree)
{
    string line;
    fstream out;
    out.open("diccionario.txt", fstream::in);
	ifstream myfile("diccionario.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            string word = line.substr(0, line.find("/"));
            string meaning = line.substr(line.find("/") + 1, line.length());
            insert(tree, word, meaning);
        }
        myfile.close();
        out.close();
    }
    
}

Node* BinaryTree::createNew(string _data, string _meaning)
{
    Node* newNode = new Node();

    newNode->setData(_data);
    newNode->setMeaning(_meaning);
    newNode->setRight(NULL);
    newNode->setLeft(NULL);

    return newNode;
}

int BinaryTree::compare(string a, string b)
{
	const char* word1 = a.c_str();
	const char* word2 = b.c_str();
	int result = strcmp(word1, word2);
	return result;
}

void BinaryTree::insert(Node*& tree, string data, string meaning)
{
    if (tree == NULL)
    {
        Node* newNode = createNew(data, meaning);
        tree = newNode;
    }
    else
    {
        string root;
        int length = tree->getData().length();
        char* word1 = new char[length + 1];
        strcpy(word1, tree->getData().c_str());
        root.assign(word1, length + 1);

        if (compare(data, tree->getData()) < 0)
        {
            insert(tree->getLeft(), data, meaning);
        }
        else
        {
            insert(tree->getRight(), data, meaning);
        }
    }
}

void BinaryTree::insertNew(Node*& tree, string data, string meaning)
{   
    if(tree == NULL)
    {
        Node* newNode = createNew(data, meaning);
        tree = newNode;

        fstream out("diccionario.txt", fstream::app);
        if(out.is_open())
        {
            out  << data << "/" << meaning << "\n";
        }
        out.close();

    }   
    else
    {
        string root;
        int length = tree->getData().length();
        char *word1 = new char[length + 1];
        strcpy(word1, tree->getData().c_str());
        root.assign(word1, length + 1);

        if(compare(data, tree->getData()) < 0)
        {
            insertNew(tree->getLeft(), data, meaning);
        }
        else
        {
            insertNew(tree->getRight(), data, meaning);
        }
    }
}

void BinaryTree::show(Node* tree, int contador)
{
    /*if(tree == NULL)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << this->tree->getData() << endl;
        mostrar(this->tree->getRight(), contador + 1);
        for(int i = 0; i < contador; i++)
        {
            cout << "123 ";
        }

        cout << this->tree->getData() << endl;
        mostrar(this->tree->getLeft(), contador + 1);
    }*/
}

void BinaryTree::search(Node* tree, string data)
{
    if(tree == NULL)
    {
        cout << "Esa palabra no esta registrada en el diccionario" << endl;
        return;
    }
    else if(compare(data, tree->getData()) == 0)
    {
        cout << "La palabra " << data << "significa: " << endl;
        cout << tree->getMeaning() << endl;
        cout << endl;
        system("pause");
    }
    else if(compare(data, tree->getData()) < 0)
    {
        search(tree->getLeft(), data);
    }
    else
    {
        search(tree->getRight(), data);
    }
}

/* void BinaryTree::preOrden(Node* tree)
{
    if(tree == NULL)
    {
        return;
    }
    else
    {
        cout << tree->getData() << " ";
        preOrden(tree->getLeft());
        preOrden(tree->getRight());
    }
}

void BinaryTree::inOrden(Node* tree)
{
    if(tree == NULL)
    {
        return;
    }
    else
    {
        inOrden(tree->getLeft());
        cout << tree->getData() << " ";
        inOrden(tree->getRight());
    }
}

void BinaryTree::postOrden(Node* tree)
{
    if(tree == NULL)
    {
        return;
    }
    else
    {
        postOrden(tree->getLeft());
        postOrden(tree->getRight());
        cout << tree->getData() << " ";
    }
} */
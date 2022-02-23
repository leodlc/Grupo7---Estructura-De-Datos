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

    Node* createNew(string, string, Node*);

    void initProgram(Node*&);

    int compare(string, string);
    void insert(Node*&, string, string, Node*);
    void insertNew(Node*&, string, string, Node*);
    void show(Node*);
    void search(Node*, string);
    Node* minimum(Node*);
    void replace(Node*, Node*);
    void destroyNode(Node*);
    void deleteNode(Node*);
    void deletion(Node*, string);

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
            insert(tree, word, meaning, NULL);
        }
        myfile.close();
        out.close();
    }

}

Node* BinaryTree::createNew(string _data, string _meaning, Node* _father)
{
    Node* newNode = new Node();

    newNode->setData(_data);
    newNode->setMeaning(_meaning);
    newNode->setFather(_father);
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

void BinaryTree::insert(Node*& tree, string data, string meaning, Node* father)
{
    if (tree == NULL)
    {
        Node* newNode = createNew(data, meaning, father);
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
            insert(tree->getLeft(), data, meaning, tree);
        }
        else
        {
            insert(tree->getRight(), data, meaning, tree);
        }
    }
}

void BinaryTree::insertNew(Node*& tree, string data, string meaning, Node* father)
{
    if (tree == NULL)
    {
        Node* newNode = createNew(data, meaning, father);
        tree = newNode;

        fstream out("diccionario.txt", fstream::app);
        if (out.is_open())
        {
            out << data << "/" << meaning << "\n";
        }
        out.close();

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
            insertNew(tree->getLeft(), data, meaning, tree);
        }
        else
        {
            insertNew(tree->getRight(), data, meaning, tree);
        }
    }
}

void BinaryTree::show(Node* tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        cout << "Palabra: ";
        cout << tree->getData() << endl;
        cout << "Significado: " << endl;
        cout << tree->getMeaning() << endl;
        cout << endl;

        show(tree->getLeft());
        show(tree->getRight());
    }
}

void BinaryTree::search(Node* tree, string data)
{
    if (tree == NULL)
    {
        cout << "Esa palabra no esta registrada en el diccionario" << endl;
        _getch();
        return;
    }
    else if (data == tree->getData())
    {
        cout << "La palabra " << data << " significa: " << endl;
        cout << tree->getMeaning() << endl;
        cout << endl;
        system("pause");
    }
    else if (compare(data, tree->getData()) < 0)
    {
        search(tree->getLeft(), data);
    }
    else
    {
        search(tree->getRight(), data);
    }
}

Node* BinaryTree::minimum(Node* tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->getLeft())
    {
        minimum(tree->getLeft());
    }
    else
    {
        return tree;
    }
}

void BinaryTree::replace(Node* tree, Node* toReplace)
{
    if (tree->getFather())
    {
        if (tree->getData() == tree->getFather()->getLeft()->getData())
        {
            tree->getFather()->setLeft(toReplace);
        }
        else if (tree->getData() == tree->getFather()->getRight()->getData())
        {
            tree->getFather()->setRight(toReplace);
        }
    }
    if (toReplace)
    {
        toReplace->setFather(tree->getFather());
    }
}

void BinaryTree::destroyNode(Node* toDestruction)
{
    toDestruction->setLeft(NULL);
    toDestruction->setRight(NULL);

    delete toDestruction;
}

void BinaryTree::deleteNode(Node* toDeletion)
{
    if (toDeletion->getLeft() && toDeletion->getRight())
    {
        Node* minor = minimum(toDeletion->getRight());
        toDeletion->setData(minor->getData());
        deleteNode(minor);
    }
    else if (toDeletion->getLeft())
    {
        replace(toDeletion, toDeletion->getLeft());
        destroyNode(toDeletion);
    }
    else if (toDeletion->getRight())
    {
        replace(toDeletion, toDeletion->getRight());
        destroyNode(toDeletion);
    }
    else
    {
        //replace(toDeletion, NULL);
        destroyNode(toDeletion);
    }
}

void BinaryTree::deletion(Node* tree, string data)
{
    if (tree == NULL)
    {
        cout << "Esa palabra no esta registrada, por lo que no fue eliminada..." << endl;
        return;
    }
    else if (data == tree->getData())
    {
        deleteNode(tree);

        ifstream fin;

        fin.open("diccionario.txt");

        std::ofstream temp;
        temp.open("temp.txt");

        if (fin.is_open()) {
            string line;
            while (getline(fin, line)) {
                if (line.find(data) == string::npos)
                    temp << line << endl;
            }
        }

        temp.close();
        fin.close();

        remove("diccionario.txt");
        rename("temp.txt", "diccionario.txt");

    }
    else if (compare(data, tree->getData()) < 0)
    {
        deletion(tree->getLeft(), data);
    }
    else
    {
        deletion(tree->getRight(), data);
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
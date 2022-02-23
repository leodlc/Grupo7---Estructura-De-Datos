#pragma once
#include <iostream>
#include "Node.h"
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "Voice.h"

/**
* @file BinaryTree.h
* @author Adrian Paez
* @version 1.0
*/

using namespace std;

class BinaryTree
{

private:
    Node* tree = NULL;

public:

    /**
    * @brief setTree
    * @param Node*
    * @return void
    */
    void setTree(Node*);

    /**
    * @brief getTree
    * @param
    * @return Node*
    */
    Node* getTree();

    /**
    * @brief create new Node*
    * @param string, string, Node*
    * @return Node*
    */
    Node* createNew(string, string, Node*);

    /**
    * @brief copy data from txt to tree
    * @param Node*&
    * @return void
    */
    void initProgram(Node*&);

    /**
    * @brief compare 2 strings
    * @param string, string
    * @return int
    */
    int compare(string, string);

    /**
    * @brief insert from file to tree
    * @param Node*&, string, string, Node*
    * @reutrn void
    */
    void insert(Node*&, string, string, Node*);

    /**
    * @brief insert new node to tree
    * @param Node*&, string, string, Node*
    * @return void
    */
    void insertNew(Node*&, string, string, Node*);

    /**
    * @brief show tree
    * @param Node*
    * @return void
    */
    void show(Node*);

    /**
    * @brief search node
    * @param Node*, string
    * @return void
    */
    void search(Node*, string);

    /**
    * @brief find minimum node
    * @param Node*
    * @return Node*
    */
    Node* minimum(Node*);

    /**
    * @brief replace node with another
    * @param Node*, Node*
    * @return void
    */
    void replace(Node*, Node*);

    /**
    * @brief destroy or delete node
    * @param Node*
    * @return void
    */
    void destroyNode(Node*);

    /**
    * @brief delete a node
    * @param Node*
    * @return void
    */
    void deleteNode(Node*);

    /**
    * @brief deletion decision depending the case
    * #param Node*, string
    * @return void
    */
    void deletion(Node*, string);

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
        cout << "Traduccion en Ingles: ";
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
        cout << "Esa palabra no esta registrada. Revise el FAQ para mas informacion..." << endl;
        _getch();
        return;
    }
    else if (data == tree->getData())
    {
        Voice vox;
        Tools tool;
        cout << "La palabra " << data << " en ingles es: ";
        cout << tree->getMeaning() << endl;
        cout << endl;
        cout << "Sugerencia: Mantenga presionada la tecla V si quiere escuchar la traduccion" << endl;

        _getch();
        while (tool.keyPressed(86))
        {
            vox.voiceGen(data, tree->getMeaning());
        }

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
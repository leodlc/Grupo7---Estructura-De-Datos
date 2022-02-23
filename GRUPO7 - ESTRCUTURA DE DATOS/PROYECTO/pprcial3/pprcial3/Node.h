#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

class Node
{

private:
    string data;
    string meaning;
    Node* left;
    Node* right;
    Node* father;

public:
    void setData(string);
    string getData();

    void setMeaning(string);
    string getMeaning();

    void setLeft(Node*);
    Node*& getLeft();

    void setRight(Node*);
    Node*& getRight();

    void setFather(Node*);
    Node*& getFather();

};

void Node::setData(string _data)
{
    this->data = _data;
}

string Node::getData()
{
    return this->data;
}

void Node::setMeaning(string _meaning)
{
    this->meaning = _meaning;
}

string Node::getMeaning()
{
    return this->meaning;
}

void Node::setLeft(Node* izquierda)
{
    this->left = izquierda;
}

Node*& Node::getLeft()
{
    return this->left;
}

void Node::setRight(Node* derecha)
{
    this->right = derecha;
}

Node*& Node::getRight()
{
    return this->right;
}

void Node::setFather(Node* padre)
{
    this->father = padre;
}

Node*& Node::getFather()
{
    return this->father;
}
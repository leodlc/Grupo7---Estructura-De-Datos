#pragma once
#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    int height;
    Node* left;
    Node* right;

public:

    void setData(int);
    int getData();

    void setHeight(int);
    int getHeight();

    void setLeft(Node*);
    Node* getLeft();

    void setRight(Node*);
    Node* getRight();

};

void Node::setData(int d)
{
    this->data = d;
}

int Node::getData()
{
    return this->data;
}

void Node::setHeight(int h)
{
    this->height = h;
}

int Node::getHeight()
{
    return this->height;
}

void Node::setLeft(Node* _left)
{
    this->left = _left;
}

Node* Node::getLeft()
{
    return this->left;
}

void Node::setRight(Node* _right)
{
    this->right = _right;
}

Node* Node::getRight()
{
    return this->right;
}
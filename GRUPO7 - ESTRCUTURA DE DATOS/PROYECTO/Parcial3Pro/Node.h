#pragma once
#include <iostream>
#include <stdio.h>

/**
* @file Node.h
* @author Adrian Paez
* @version 1.0
*/

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

    /**
    * @brief setData
    * @param string
    * @return void
    */
    void setData(string);

    /**
    * @brief getData
    * @param
    * @return string
    */
    string getData();

    /**
    * @brief setMeaning
    * @param string
    * @return void
    */
    void setMeaning(string);

    /**
    * @brief getMeaning
    * @param
    * @return string
    */
    string getMeaning();

    /**
    * @brief setLeft
    * @param Node*
    * @return void
    */
    void setLeft(Node*);

    /**
    * @brief getLeft
    * @param
    * @return Node*&
    */
    Node*& getLeft();


    /**
    * @brief setRight
    * @param Node*
    * @return void
    */
    void setRight(Node*);

    /**
    * @brief getRight
    * @param
    * @return Node*&
    */
    Node*& getRight();


    /**
    * @brief setFather
    * @param Node*
    * @return void
    */
    void setFather(Node*);

    /**
    * @brief getFather
    * @param
    * @return Node*&
    */
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
#pragma once
using namespace std;

class PascalOperation
{
public:
	PascalOperation(int n, int k,int nrows);
	PascalOperation();
	int factorial(int n);
	int combinate(int n, int k);
	void generatePascalTriangule(int nrows);
	int getN();
	int getK();
private:
	int n;
	int k;
	int nrows;
};


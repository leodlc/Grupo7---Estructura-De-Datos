#include "PascalOperation.h"
#include <iostream>
using namespace std;

PascalOperation::PascalOperation(int n, int k, int nrows) {
	this->n = n;
	this->k = k;
	this->nrows = nrows;
}
PascalOperation::PascalOperation() {

}

int PascalOperation::factorial(int n) {
	int result = 1;
	for (int i=1; i <= n; i++) {
		result *= i;
		
	}
	return result;
}
int PascalOperation::combinate(int n, int k) {
	return(factorial(n)) / (factorial(k) * factorial(n - k));
}
void PascalOperation::generatePascalTriangule(int nrows) {
	for (int i = 0; i <= nrows; i++) {
		for (int j = 0; j <= i; j++) {
			cout << combinate(i, j) << " ";
		}
		cout << endl;
	}
}

int PascalOperation::getN() {
	return this->n;
}

int PascalOperation::getK() {
	return this->k;
}


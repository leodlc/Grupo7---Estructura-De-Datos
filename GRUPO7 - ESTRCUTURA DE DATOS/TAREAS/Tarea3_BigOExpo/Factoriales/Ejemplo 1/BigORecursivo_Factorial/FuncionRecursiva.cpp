#include "FuncionRecursiva.h"
using namespace std;
template <typename T>
FuncionRecursiva<T>::FuncionRecursiva()
{

}
template <typename T>
T FuncionRecursiva<T>::factorial(T n)
{
	if (n == 0) { return 1; } //n=0 es el caso base
	else { return n * factorial(n - 1); } //caso general n>0
}
/*
* - Talla del problema: representa el valor del parametro n
* - Caso Base (n =0 ). El tiempo de ejecución: T(n)=1 ( 1 comparacion y 1 retorno
* se ejecutan como secuencia en un intervalo de tiempo).
* -Caso general(n>0) . Tiempo de ejecucion:  T(n) = 1+ T(n-1)
* siendo el coste iterativo 1 represantando la secuencia de 4
* operaciones: la comparacion, la resta, el producto y el retorno
* mas el tiempo de hacer 1 llamada a la funcion factorial de
* talla n-1
*/

template <typename T>
void FuncionRecursiva<T>::setN(T newN)
{
	n = newN;
}

template class FuncionRecursiva<int>;



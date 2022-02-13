// Fibonacci.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int fibonacci(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else if(x == 0)
    {
        return 0;
    }
    else
    {
        return fibonacci(x - 1) + fibonacci(x - 2);
    }
}

int main()
{
    int n;

    cout << "Serie de: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }

    return 0;
}

//O(2^n)
//T(n) = T(n-1) + T(n-2)

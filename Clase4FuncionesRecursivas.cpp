#include <iostream>

using namespace std;

int FactorialRecursiva(int);
int FactorialIterativo(int);

int main()
{

    cout << "Solución Recursiva: " << FactorialRecursiva(3) << endl;
    cout << "Solución Iterativa: " << FactorialIterativo(3);
    return 0;
}

// Recursiva
int FactorialRecursiva(int n)
{ // cálculo de n!
    // Condición de salida
    if (n <= 1)
        return 1;
    else
        // Se realiza el llamado a la función nuevamente
        return n * FactorialRecursiva(n - 1);
}

// Iterativa
int FactorialIterativo(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}
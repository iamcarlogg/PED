#include <iostream>

using namespace std;

void miFuncion1(int *);
void miFuncion2(int &);
void miFuncion3(int *&);
void miFuncion4(int **);

int var = 45;

int main()
{
    // Declaración de una variable tipo entero y asignacion a una variable
    int a = 10;
    // Declaracion de puntero
    int *p, *c;
    // Asignando valor al puntero
    p = &a;
    // Un puntero puede apuntar a otro puntero
    c = p;
    *p = 25;
    // Imprimiendo la direccion de memoria de la variable a
    cout << p << endl;
    // Imprimiendo el valor de a
    cout << *p << endl;
    // Imprimiendo el valor de p
    cout << c << endl;

    // Llamando a la función
    miFuncion1(&a);
    miFuncion2(a);
    miFuncion3(p);
    miFuncion4(&p);
    cout << "Nuevo valor de a " << *p;

    // Aritmetica de punteros: Asignación, comparación, suma y resta.

    // Declaración de punteros
    int arreglo[] = {1, 2, 4};
    // Todo array es un puntero  --- Asignación
    int *ptr = arreglo;
    cout << "Direccion de memoria " << ptr << endl;
    // Accediendo a una posición
    // cout << ptr[2] << endl;
    // Accediendo a la posición con punteros
    cout << *(ptr + 0) << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;

    // Suma para navegar entre los elementos
    for (int i = 0; i < 3; i++)
    {
        cout << "Elemento de arreglo " << *(arreglo + i) << " dir memoria " << ptr++ << endl;
    }

    // Resta - Distancia entre punteros
    cout << "Distancia entre punteros ptr2 - ptr0 " << *(ptr + 2) - *(ptr + 0) << endl;

    // Comparación
    cout << "ptr0 > ptr2: " << (*(ptr + 0) > *(ptr + 1)) << endl;
    cout << "ptr0 == ptr0: " << (*(ptr + 0) == *(ptr + 0)) << endl;
    cout << "ptr0 < ptr1: " << (*(ptr + 0) < *(ptr + 1)) << endl;

    return 0;
}

// Paso de parametro por referencia
//  Puntero como argumento
void miFuncion1(int *b)
{
    cout << "El valor es: " << *b << endl;
    *b = 20;
    cout << "El valor es: " << *b << endl;
}

// Referencia
void miFuncion2(int &b)
{
    cout << "El valor es: " << b << endl;
    b = 20;
    cout << "El valor es: " << b << endl;
}

// Referencia  de Punteros
void miFuncion3(int *&b)
{
    b = &var;
}

void miFuncion4(int **b)
{
    *b = &var;
}
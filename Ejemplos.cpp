#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

struct Nodo *lista = NULL;

// Declaración de funciones
void Insertar(int n);
void Imprimir();
void EliminarInicio();
void EliminarFinal();
int SumarElementos();
double CalcularPromedio();
int ContarElementos();
int EncontrarMaximo();
int EncontrarMinimo();

int main()
{
    Insertar(10);
    Insertar(5);
    Insertar(40);
    Insertar(85);

    cout << "Lista inicial:" << endl;
    Imprimir();

    cout << "Suma de los elementos: " << SumarElementos() << endl;
    cout << "Promedio de los elementos: " << CalcularPromedio() << endl;
    cout << "Cantidad de elementos: " << ContarElementos() << endl;
    cout << "Valor máximo: " << EncontrarMaximo() << endl;
    cout << "Valor mínimo: " << EncontrarMinimo() << endl;

    EliminarInicio();
    cout << "\nLista después de eliminar el inicio:" << endl;
    Imprimir();

    EliminarFinal();
    cout << "\nLista después de eliminar el final:" << endl;
    Imprimir();

    return 0;
}

// Insertar nodos a la lista
void Insertar(int n)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    if (nuevoNodo != NULL)
    {
        nuevoNodo->dato = n;
        nuevoNodo->siguiente = NULL;
        if (lista == NULL)
        {
            lista = nuevoNodo;
        }
        else
        {
            while (temporal->siguiente != NULL)
            {
                temporal = temporal->siguiente;
            }
            temporal->siguiente = nuevoNodo;
        }
    }
    else
    {
        cout << "No se pueden agregar más nodos" << endl;
    }
}

// Eliminar el primer nodo
void EliminarInicio()
{
    struct Nodo *temporal = lista;
    if (lista != NULL)
    {
        lista = lista->siguiente;
        delete temporal;
    }
    else
    {
        cout << "Lista vacía" << endl;
    }
}

// Eliminar el último nodo
void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != NULL)
    {
        if (temporal->siguiente != NULL)
        {
            while (temporal->siguiente != NULL)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            temporal2->siguiente = NULL;
            delete temporal;
        }
        else
        {
            delete lista;
            lista = NULL;
        }
    }
    else
    {
        cout << "Lista vacía" << endl;
    }
}

// Imprimir la lista
void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != NULL)
    {
        while (temporal != NULL)
        {
            cout << temporal->dato << " -> ";
            temporal = temporal->siguiente;
        }
        cout << "NULL" << endl;
    }
    else
    {
        cout << "Lista vacía" << endl;
    }
}

// Sumar todos los elementos de la lista
int SumarElementos()
{
    int suma = 0;
    struct Nodo *temporal = lista;
    while (temporal != NULL)
    {
        suma += temporal->dato;
        temporal = temporal->siguiente;
    }
    return suma;
}

// Calcular el promedio de los elementos
double CalcularPromedio()
{
    int suma = SumarElementos();
    int cantidad = ContarElementos();
    return cantidad == 0 ? 0 : (double)suma / cantidad;
}

// Contar los elementos de la lista
int ContarElementos()
{
    int contador = 0;
    struct Nodo *temporal = lista;
    while (temporal != NULL)
    {
        contador++;
        temporal = temporal->siguiente;
    }
    return contador;
}

// Encontrar el valor máximo de la lista
int EncontrarMaximo()
{
    if (lista == NULL)
    {
        cout << "Lista vacía" << endl;
        return INT_MIN;
    }
    int maximo = lista->dato;
    struct Nodo *temporal = lista->siguiente;
    while (temporal != NULL)
    {
        if (temporal->dato > maximo)
        {
            maximo = temporal->dato;
        }
        temporal = temporal->siguiente;
    }
    return maximo;
}

// Encontrar el valor mínimo de la lista
int EncontrarMinimo()
{
    if (lista == NULL)
    {
        cout << "Lista vacía" << endl;
        return INT_MAX;
    }
    int minimo = lista->dato;
    struct Nodo *temporal = lista->siguiente;
    while (temporal != NULL)
    {
        if (temporal->dato < minimo)
        {
            minimo = temporal->dato;
        }
        temporal = temporal->siguiente;
    }
    return minimo;
}

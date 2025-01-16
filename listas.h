#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>
#include <climits> // Para INT_MIN y INT_MAX
using namespace std;

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

class ListaEnlazada
{
private:
    struct Nodo *lista;

public:
    ListaEnlazada() : lista(NULL) {}

    // Funciones básicas
    void Insertar(int n);
    void Imprimir();
    void EliminarInicio();
    void EliminarFinal();

    // Funciones adicionales
    int SumarElementos();
    double CalcularPromedio();
    int ContarElementos();
    int EncontrarMaximo();
    int EncontrarMinimo();
    bool BuscarElemento(int valor);
    void InsertarEnPosicion(int valor, int posicion);
    void InvertirLista();
    void EliminarEnPosicion(int posicion);
    void FusionarListas(ListaEnlazada &otraLista);
    void OrdenarLista();
    ListaEnlazada ClonarLista();
    bool EsPalindromo();
    int KDesdeElFinal(int k);
    void EliminarPorValor(int valor);
};

// Implementación de funciones
void ListaEnlazada::Insertar(int n)
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

void ListaEnlazada::Imprimir()
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

void ListaEnlazada::EliminarInicio()
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

void ListaEnlazada::EliminarFinal()
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

// Funciones adicionales
int ListaEnlazada::SumarElementos()
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

double ListaEnlazada::CalcularPromedio()
{
    int suma = SumarElementos();
    int cantidad = ContarElementos();
    return cantidad == 0 ? 0 : (double)suma / cantidad;
}

int ListaEnlazada::ContarElementos()
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

int ListaEnlazada::EncontrarMaximo()
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

int ListaEnlazada::EncontrarMinimo()
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

bool ListaEnlazada::BuscarElemento(int valor)
{
    struct Nodo *temporal = lista;
    while (temporal != NULL)
    {
        if (temporal->dato == valor)
        {
            return true;
        }
        temporal = temporal->siguiente;
    }
    return false;
}

void ListaEnlazada::InsertarEnPosicion(int valor, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;

    if (posicion == 0)
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
        return;
    }

    struct Nodo *temporal = lista;
    for (int i = 0; i < posicion - 1 && temporal != NULL; i++)
    {
        temporal = temporal->siguiente;
    }

    if (temporal != NULL)
    {
        nuevoNodo->siguiente = temporal->siguiente;
        temporal->siguiente = nuevoNodo;
    }
    else
    {
        cout << "Posición inválida." << endl;
    }
}

void ListaEnlazada::InvertirLista()
{
    struct Nodo *previo = NULL, *actual = lista, *siguiente = NULL;

    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        actual->siguiente = previo;
        previo = actual;
        actual = siguiente;
    }
    lista = previo;
}

void ListaEnlazada::EliminarEnPosicion(int posicion)
{
    if (lista == NULL)
    {
        cout << "Lista vacía." << endl;
        return;
    }

    if (posicion == 0)
    {
        EliminarInicio();
        return;
    }

    struct Nodo *temporal = lista;
    struct Nodo *anterior = NULL;

    for (int i = 0; i < posicion && temporal != NULL; i++)
    {
        anterior = temporal;
        temporal = temporal->siguiente;
    }

    if (temporal != NULL)
    {
        anterior->siguiente = temporal->siguiente;
        delete temporal;
    }
    else
    {
        cout << "Posición inválida." << endl;
    }
}

void ListaEnlazada::FusionarListas(ListaEnlazada &otraLista)
{
    if (lista == NULL)
    {
        lista = otraLista.lista;
        return;
    }

    struct Nodo *temporal = lista;
    while (temporal->siguiente != NULL)
    {
        temporal = temporal->siguiente;
    }
    temporal->siguiente = otraLista.lista;
    otraLista.lista = NULL;
}

void ListaEnlazada::OrdenarLista()
{
    if (lista == NULL || lista->siguiente == NULL)
    {
        return;
    }

    bool cambiado;
    do
    {
        cambiado = false;
        struct Nodo *actual = lista;
        struct Nodo *siguiente = lista->siguiente;

        while (siguiente != NULL)
        {
            if (actual->dato > siguiente->dato)
            {
                swap(actual->dato, siguiente->dato);
                cambiado = true;
            }
            actual = siguiente;
            siguiente = siguiente->siguiente;
        }
    } while (cambiado);
}

ListaEnlazada ListaEnlazada::ClonarLista()
{
    ListaEnlazada nuevaLista;
    struct Nodo *temporal = lista;

    while (temporal != NULL)
    {
        nuevaLista.Insertar(temporal->dato);
        temporal = temporal->siguiente;
    }

    return nuevaLista;
}

bool ListaEnlazada::EsPalindromo()
{
    if (lista == NULL || lista->siguiente == NULL)
    {
        return true;
    }

    struct Nodo *lento = lista, *rapido = lista;
    struct Nodo *previo = NULL, *siguiente = NULL;

    while (rapido != NULL && rapido->siguiente != NULL)
    {
        rapido = rapido->siguiente->siguiente;

        siguiente = lento->siguiente;
        lento->siguiente = previo;
        previo = lento;
        lento = siguiente;
    }

    if (rapido != NULL)
    {
        lento = lento->siguiente;
    }

    while (lento != NULL)
    {
        if (previo->dato != lento->dato)
        {
            return false;
        }
        previo = previo->siguiente;
        lento = lento->siguiente;
    }

    return true;
}

int ListaEnlazada::KDesdeElFinal(int k)
{
    struct Nodo *principal = lista;
    struct Nodo *secundario = lista;

    for (int i = 0; i < k; i++)
    {
        if (secundario == NULL)
        {
            cout << "Valor de k fuera de rango." << endl;
            return INT_MIN;
        }
        secundario = secundario->siguiente;
    }

    while (secundario != NULL)
    {
        principal = principal->siguiente;
        secundario = secundario->siguiente;
    }

    return principal->dato;
}

void ListaEnlazada::EliminarPorValor(int valor)
{
    struct Nodo *temporal = lista;
    struct Nodo *anterior = NULL;

    while (temporal != NULL && temporal->dato == valor)
    {
        lista = temporal->siguiente;
        delete temporal;
        temporal = lista;
    }

    while (temporal != NULL)
    {
        while (temporal != NULL && temporal->dato != valor)
        {
            anterior = temporal;
            temporal = temporal->siguiente;
        }

        if (temporal == NULL)
        {
            return;
        }

        anterior->siguiente = temporal->siguiente;
        delete temporal;
        temporal = anterior->siguiente;
    }
}

#endif // LISTAENLAZADA_H

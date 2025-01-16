#include <iostream>
#include "listas.h" // Incluir el archivo de encabezado

int main()
{
    ListaEnlazada lista;

    // Insertar elementos en la lista
    lista.Insertar(10);
    lista.Insertar(20);
    lista.Insertar(30);

    // Imprimir la lista
    lista.Imprimir();

    // Eliminar el primer elemento
    lista.EliminarInicio();
    lista.Imprimir();

    // Encontrar el máximo
    int maximo = lista.EncontrarMaximo();
    std::cout << "El máximo es: " << maximo << std::endl;

    // Calcular el promedio
    double promedio = lista.CalcularPromedio();
    std::cout << "El promedio es: " << promedio << std::endl;

    return 0;
}

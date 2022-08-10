//Estructura, tipos de datos, variables, ambito de variables, funciones
#include <iostream>

using namespace std;

//variables globales 
 int numero3 = 14;
 int numero4 = 5; 

//Declaración de las funciones

int main(){

    //variable local 
    int numero1 = 14;
    int numero2 = 5; 

    int suma1 = numero1 + numero2;
    cout<<suma1;
    //Ejercicio no evaluado
    //imprimir resultado de funcion sumar y restar 
    //solicitar al usuario los valores de la entrada de sumar y restar.

    //Falta llamar a la función
    return 0;
}

//Definición de las funciones 
//funciones sin parametros 
int sumar(){
    //variable local
   int suma2 = numero3 + numero4;
   return suma2;
}
//funciones sin parametros 
int restar(){
    //variable local
    int resta = numero3 - numero4;
    return resta;
}
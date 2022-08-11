#include <iostream>
#include <string.h>

using namespace std;

int main()
{

  // Cadena de caracteres c-Strings

  /*  char cadena [] = {'E','j','e','m','p','l','o'};
 char cadena [] = “Ejemplo”;*/

  // Ejemplo solicitando nombre
  char nombre[20];
  char nombreCopia[20];
  cout << "Digite su nombre";
  cin.getline(nombre, 20, '\n');
  cout << nombre << endl;

  // Operaciones con cadenas
   // Concatenar cadenas
  cout << strcat(nombre, nombreCopia);
  // Longitud de una cadena
  int longitud = 0;
  longitud = strlen(nombre);
  cout << longitud;
  // copiar el contenido de una cadena a otra
  strcpy(nombreCopia, nombre);
  cout << nombreCopia;
  // Comparar cadenas, indicar si una es mayor a otra en orden alfabeticamente
  if (strcmp(nombreCopia, nombre) == 0)
  {
    cout << "Cadenas iguales";
  }
  // Invertir cadena
  cout << strrev(nombre);
  //Pasar a mayúscula 
  cout<< strupr(nombre);
  //pasar a minúsculas
  cout<<strlwr(nombre);
  //Transfomar una cadena a numeros
  char numeroCadena[] = "1989";
  //convierte a numero entero
  cout<<atoi(numeroCadena);
  //convierte a numero float
  cout<<atof(numeroCadena);
  //Contar el numero de veces de las vocales en una cadena



  




/*   /// Solucion a ejercicio de palabra polindroma
  char nombre[20];
  char nombreCopia[20];
  cout << "Digite su nombre";
  cin.getline(nombre, 20, '\n');
  cout << nombre << endl;
  cout << strrev(nombreCopia);
  if (strcmp(nombre, nombreCopia) != 0)
  {
    cout << "La palabra no es polindroma";
  }
  else
  {
    cout << "La palabra es polindroma";
  } */

  // Libreria string

  /*   string apellido;
    cout << "Ingresa tu apellido";
    getline(cin, apellido);
    cout << apellido; */

  // Operaciones con string
  /*     string nombre = "Marlene";
      string apellido = "Aguilar";
      string apellidoSegundo = "Navarro";
      //Concatenando con operador +  y método append()
      string nombreCompleto = nombre + apellido.append(apellidoSegundo);
      cout << nombreCompleto<<endl;
      //Obteniendo el tamaño
      cout<<nombreCompleto.size()<<endl;
      //Accediendo a una posición
      cout<<nombreCompleto[5]<<endl; */

  /************************/
  // Ejercicio solicitar al usuario una palabra si es igual o menor a 1 no es valido.
  // Ejercicio al ejercicio anterior solicitar otra palabra y verificar cual de las 2 es mayor alfabeticamente
  // Ejercicio al anterior concatenar las dos cadenas
  // Ejercicio anterior pasar a mayusculas o minuscula dependiendo cual haya sido la entrada
  // Verificar si una palabra es polindroma es decir si es igual a la palabra invertida

  return 0;
}
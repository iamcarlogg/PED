#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    // apertura de archivo
    ofstream file("datos.txt", ios::app);
    if (file.is_open())
    {
        file << "Hola, mundo!";
        file.close();
        cout << "Fichero creado y escrito correctamente." << endl;
    }
    else
    {
        cerr << "Error al abrir el fichero." << endl;
    }
    return 0;
}

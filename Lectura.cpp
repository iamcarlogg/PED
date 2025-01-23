#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ifstream file("notas.txt", ios::in);
    vector<int> notas;
    double nota;
    if (file.is_open())
    {
        string line;
        while (file >> nota)
        {
            notas.push_back(nota);
        }
        file.close();
    }
    else
    {
        cerr << "Error al abrir el fichero." << endl;
    }
    // mostrar vector
    for (int i = 0; i < notas.size(); i++)
    {
        cout << notas[i] << endl;
    }

    return 0;
}
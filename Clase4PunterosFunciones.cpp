#include <iostream>

using namespace std;

void incrementoV (int);
void incrementoR (int &);


int main(){

	int num;
    //Declaraci�n de puntero
    int *ptr;
    //Asignaci�n al puntero
    ptr = &num;
    //Imprimir direcci�n de memoria
    cout<<ptr; 
    
    int i = 5;
    incrementoV(i);
    cout<<"Valor de i "<<i<<endl;
    incrementoR(i);
    cout<<"Valor de i "<<i<<endl;
    

return 0;
} 

//Paso por valor 
void incrementoV (int i){
    i+=1;
    cout<<"Valor incrementado "<<i<<endl;
}

//Paso por referencia
void incrementoR (int &i){
    i+=1;
    cout<<"Valor incrementado "<<i<<endl;
}




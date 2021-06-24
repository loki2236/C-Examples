/* Ingresar vector - No pueden haber valores duplicados */

#include <iostream>

#define TAMANIOVECTOR 8

using namespace std;

bool existeEnVector (int valor, int vector[], int tamanio);

int main ()
{
    int posicionesCompletas = 0;
    int valorIngresado;
    int miVector[TAMANIOVECTOR];
    
    
    while (posicionesCompletas < TAMANIOVECTOR){
        cout<<"Ingrese un valor: ";
        cin>>valorIngresado;
        if(!existeEnVector(valorIngresado, miVector, TAMANIOVECTOR)){
            miVector[posicionesCompletas] = valorIngresado;
            posicionesCompletas++;
        }
        else{
            cout<<"Che, ya existe, no lo puedo guardar"<<endl;
        }
        
    }

    return 0;
}

bool existeEnVector (int valor, int vector[], int tamanio){

    for (int i = 0; i< tamanio; i++){
        if(vector[i] == valor){
            return true;
        }
    }

    return false;
}
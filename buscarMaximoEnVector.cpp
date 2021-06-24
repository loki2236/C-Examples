/*En un vector de 10 elementos encontrar los dos valores máximos, o sea el más grande y el que 
le siga. Cargue el vector en la declaración. Si inicializa con los datos: 6, 1, 3, 7, 9, 4, 10, 2, 8, 5 
el máximo es 10 en la posición 6 y el segundo es 9 en la posición 4*/

#include <iostream>

#define TAMANIOVECTOR 10

using namespace std;

void imprimirVector (int vectorAImprimir[]);


int main ()
{
    //cout<< "Ingrese una cadena: ";
    //cin>>miCadena;
    int miVector[TAMANIOVECTOR] =       {6,1,3,7,9,4,10,2,8,5};
    
    int Max = 0;
    int SigMax = 0;
    int posMax=0, posSigMax=0;

    for(int i = 0; i<TAMANIOVECTOR;i++){

        if(miVector[i] > Max){
            SigMax = Max;
            posSigMax = posMax;
            Max = miVector[i];
            posMax = i;
        }
    }

    cout<<"Maximo: "<<Max<<endl;
    cout<<"Siguiente al Maximo: "<<SigMax<<endl;
  
    return 0;
}
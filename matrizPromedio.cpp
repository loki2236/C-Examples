/*
Defina y de valores a una matriz de doubles de 4 filas y 3 columnas. Llame a una función que 
acepte matrices de tipo double y con exactamente 4 filas y 3 columnas, que devuelva el 
promedio de los elementos en la matriz
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
double promedioMatriz4x3(double matrizInput[4][3]);

int main ()
{
    double matrizDouble[4][3];
    //Inicializo el rand
    srand(time(NULL));

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
         matrizDouble[i][j] = rand()%100/(rand()%7+1);
        }
    }
    
    cout<<"El promedio de la matriz es: "<<promedioMatriz4x3(matrizDouble)<<endl;
    
    return 0;
}

double promedioMatriz4x3(double matrizInput[4][3]){
    double suma=0;
    int cantidadElementos=0;

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            suma += matrizInput[i][j];
            cantidadElementos++;
        }
    }
    return (suma/cantidadElementos);
}
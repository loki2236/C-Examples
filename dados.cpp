/*
6) Escriba un programa que permita ingresar la tirada de un par de dados 50 veces 
y muestre una lista donde se vea cuántas veces se dio cada uno de los resultados posibles.
Por cada tirada se deberán ingresar 2 valores, cada uno representa el valor de un dado. 

El formato de la salida debe ser el siguiente:
2 salió ... veces
3 salió ... veces
.
.
12 salió ... veces

*/

#include <iostream>

using namespace std;
int imprimirArray(int arrayAImprimir[], int cantidadElementos, int arrayEtiquetas[]);


int main ()
{
    int resultados[11] = {0};
    int numerosQueSalen[11] = {7,8,4,22,56,120,267,456,0,1,22};

    int numero1, numero2,sumaDados;
    //1) Pedir entradas de datos al Usuario (2 valores por entrada)

    for(int i= 0; i<5;i++){
        cout<<"Ingrese el num1: ";
        cin>>numero1;
        cout<<"Ingrese el num2: ";
        cin>>numero2;

        sumaDados=(numero1+numero2);
        resultados[(sumaDados)-2]++;

        // resultados[0] = Cuantas veces salio el 2
        // resultados[1] = Cuantas veces salio el 3
        // resultados[2] = Cuantas veces salio el 4
        // resultados[3] = Cuantas veces salio el 5
        // ...
        // resultados[10] = Cuantas veces salio el 12

    }

    imprimirArray(resultados, 11, numerosQueSalen);
    
    return 0;
}

int imprimirArray(int arrayAImprimir[], int cantidadElementos, int arrayEtiquetas[]){
    cout<<"Imprimiendo array: "<<endl;

    for(int i=0;i<cantidadElementos;i++){
        cout<<"El numero "<<arrayEtiquetas[i]<<" salio "<<arrayAImprimir[i]<<" veces"<<endl;
    }
    return 0;
}
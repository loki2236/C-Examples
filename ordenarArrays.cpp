/* 
*5) Dado un conjunto desordenado de valores enteros comprendidos entre 1 y 500, sin repetición, que finaliza con cero, desarrollar un algoritmo que:
. Imprima un listado ordenado de aquellos valores enteros que se encuentran en el conjunto
. Imprima un listado ordenado de aquellos valores enteros que no se encuentran en el conjunto.
*/
#include <iostream>

using namespace std;

int imprimirArray(int arrayAImprimir[], int cantidadElementos);
int ordenarBurbuja(int arrayAOrdenar[], int cantidadElementos);
bool existeEnArray(int arrayABuscar[], int cantidadElementos, int elementoBuscado);
int imprimirFaltantes(int arrayAImprimir[], int cantidadElementos);

int main ()
{
    int arrayPrueba[10]= {0,1,2,3,5,4,8,9,6,7};
    int miArray[500];
    int numeroIngresado;
    int cantidadIngresados=0;
    // 1) Pedirle datos por teclado al usuario y guardarlos en un array de como maximo 500 posiciones. (finaliza con 0)
    cout<<"Ingrese un numero entero: "<<endl;
    cin>>numeroIngresado;

    while(numeroIngresado != 0){
        
        miArray[cantidadIngresados] = numeroIngresado;
        cantidadIngresados++;

        cout<<"Ingrese un numero entero: "<<endl;
        cin>>numeroIngresado;
    }

    // 2) Ordenar el array e imprimirlo por pantalla
    ordenarBurbuja(miArray, cantidadIngresados);
    imprimirArray(miArray, cantidadIngresados);

    // 3) Imprimir por pantalla todos los numeros que no se encuentren en el array.
    imprimirFaltantes(miArray, cantidadIngresados);

}

int ordenarBurbuja(int arrayAOrdenar[], int cantidadElementos){
    int aux;
    for(int i=1;i<cantidadElementos;i++){
        for(int j=0;j<cantidadElementos-i;j++){
            //si es mayor
            if(arrayAOrdenar[j]>arrayAOrdenar[j+1]){
                aux = arrayAOrdenar[j+1];
                arrayAOrdenar[j+1]=arrayAOrdenar[j];
                arrayAOrdenar[j] = aux;

            }
        }
    }
    return 0;
}

int imprimirArray(int arrayAImprimir[], int cantidadElementos){
    cout<<"Imprimiendo array: "<<endl;

    for(int i=0;i<cantidadElementos;i++){
        cout<<arrayAImprimir[i]<<endl;
    }
    return 0;
}

int imprimirFaltantes(int arrayAImprimir[], int cantidadElementos){
    cout<<"Imprimiendo Faltantes: "<<endl;

    for(int i=0;i<500;i++){
        if(!existeEnArray(arrayAImprimir,cantidadElementos, i)){
            cout<<i<<", ";
        }
    }
    return 0;
}

bool existeEnArray(int arrayABuscar[], int cantidadElementos, int elementoBuscado){
    for(int i=0;i<cantidadElementos;i++){
        if(arrayABuscar[i] == elementoBuscado){
            return true;
        }
    }
    return false;
}

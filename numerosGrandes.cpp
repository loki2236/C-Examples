/* 7) Dado un número N (<20), y dos vectores A y B de N elementos que contenga valores entre 0..9 que representan números naturales muy largos
a) genere e informe un tercer vector SUMA de N+1 elementos que sea el resultante de la suma de los dos números.
b) genere e informe un tercer vector RESTA de N elementos que sea el resultante de la resta de los dos números.
*/

// int miVector[20] = {2,3,4,6,7}
// int miOtroVector[20] = {1,2,0,6,7}


//int miTercerVector[unaVariable] 



#include <iostream>

using namespace std;

void imprimirVector (int vectorAImprimir[]);


int main ()
{
    //cout<< "Ingrese una cadena: ";
    //cin>>miCadena;
    int miVector[5] =       {9,3,4,6,7};
    int miOtroVector[5] =   {1,8,0,6,7};
    int vectorSuma[5] =     {0,0,0,0,0};
    int vectorResta[5] =     {0,0,0,0,0};

    // Suma
    

    for(int i = 4; i>=0;i--){

        
        vectorSuma[i] = miVector[i] + miOtroVector[i];
        cout<<"i: "<<i<<" / VectorSuma: "<<vectorSuma[i]<<endl;
        if (vectorSuma[i] >= 10){
            vectorSuma[i] = vectorSuma[i] - 10;
            if (i != 0){
                miVector[i-1] = miVector[i-1] + 1;
            }
            else{
                cout<<"Overflow!! ";
            }
        }

    }
    
    cout<<"Resultado Suma: ";
    imprimirVector(vectorSuma);
    cout<<endl;

    // Resta
    for(int i = 4; i>=0;i--){
        vectorResta[i] = miVector[i] - miOtroVector[i];
        if (vectorResta[i] < 0){
            if (i != 0){
                vectorResta[i] = vectorResta[i] + 10;
                miVector[i-1] = miVector[i-1] - 1;
            }
            else{
                cout<<"Negativo! ";
            }
        }

    }
    cout<<"Resultado Resta: ";
    imprimirVector(vectorResta);
    cout<<endl;


    return 0;
}

void imprimirVector (int vectorAImprimir[]){
     // Suma
    for(int i = 0;i<5;i++){
        cout<<vectorAImprimir[i];
       }
}
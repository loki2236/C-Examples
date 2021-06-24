#include <iostream>

void calcularvalores(int& num, int& suma,int& contp,int& contN,int& numerospares,int& total,float& porcentajepares,float&  porcentajeN,float& promedio);

using namespace std;
//Se ingresan varios valores enteros, finalizando con la llegada de un 0 (cero). Se pide:
//1. Cantidad positivos.
//2. Cantidad de negativos.
//3. Porcentaje de pares.
//4. Promedio de los positivos.
//5. Porcentaje de negativos


int main() {
    int num;
	int promedio;
	int porcentajepares;
	int porcentajeN;

    cout << " ingresar un valor " << endl;
	cin >> num;
	
	calcularvalores(int num, int suma,int cont,int cont1,int numerospares,int total);

	cout <<" la cantidad de numeros positivos son " << cont << endl;
	cout <<" la cantidad de numeros negativos son "<< cont1 <<endl;
	cout <<"el porcentaje de los numeros pares sera "<<porcentajedenumerospares << endl;
	cout <<" el promedio de los positivos es "<< promediopositivos <<endl;
	cout <<" el porcentaje d elos numeros negativos es "<< porcentajenegativos << endl;

	return 0;
}

// esto lo hice por que me dijeron que tenia que hacer un void para no devolver nada, 
// pero no se que diferencia hay entre un void y un int. capaz que convenia mejor con un int pero ni idea.
void calcularvalores(int& num, int& suma,int& contp,int& contN,int& numerospares,int& total,float& porcentajepares,float&  porcentajeN,float& promedio){

   while(num!=0){
        cout <<" ingresar otro valor "<<endl;
        cin >>num;
        
        if(num>0){
        suma=suma+num;
        contp=contp+1;
        }
        else{
        contN=contN+1;
        }
        // para saber el porcentaje, primero tenemos que saber el total de todos los numeros
        
        total = total+1; // esto es para ir contando la cantidad total de numeros ingresados.
        
        if(num%2==0){
        numerospares=numerospares+1;
        }
    }
    porcentajepares=numerospares*100/total;
    promedio=suma/contp;
    porcentajeN=contN*100/total;

}

/* 
15) Se tiene un vector con las notas de los exámenes rendidos por los alumnos (nombre y nota) 
ordenado por nombre con un elemento por cada examen rendido (un alumno puede haber rendido 1, 2, ó más exámenes). 

Se pide generar un vector con un elemento por alumno con el promedio de las notas de sus exámenes, ordenado por nombre.
*/

#include <iostream>
#include <string.h>

#define TAMANIOVECTOR 7

using namespace std;

typedef struct unExamen{
    char nombreAlumno[50];
    int resultadoExamen;
}Examen;


int main ()
{
    int sumaNotas=0;
    int cantidadNotas=0;
    int cantidadAlumnos=0;
    float promedios[TAMANIOVECTOR];


    Examen resultadosExamen[TAMANIOVECTOR] = {{"Pepe", 10}, {"Pepe",4}, {"Otro Alumno", 8},{"Otro Alumno", 7},{"Otro Alumno", 1},{"Otro Alumno", 1}, {"Loki", 2}};

    for(int i = 0; i < TAMANIOVECTOR; i++){
        sumaNotas += resultadosExamen[i].resultadoExamen;
        cantidadNotas++;

        if (strcmp(resultadosExamen[i].nombreAlumno, resultadosExamen[i+1].nombreAlumno) != 0){
            promedios[cantidadAlumnos] = sumaNotas*1.0f/cantidadNotas*1.0f;
            cantidadAlumnos++;
            sumaNotas = 0;
            cantidadNotas=0;
        }
    }
    

    cout<<"Notas:"<<endl;
    for(int i = 0; i < cantidadAlumnos; i++){
        cout<<promedios[i]<<endl;
    }    
    return 0;
}

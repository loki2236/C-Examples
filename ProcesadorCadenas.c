#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int grupoCaracter(char caracter);
int procesarCadena (char *cadena);
char* tipoDeToken (int);

int main()
{
    printf("Token: %s, Clasificacion: %d, Tipo: %s\n","0x2541f",procesarCadena("0x2541f"), tipoDeToken(procesarCadena("0x2541f")));
    printf("Token: %s, Clasificacion: %d, Tipo: %s\n","0299",procesarCadena("0299"), tipoDeToken(procesarCadena("0299")));
    printf("Token: %s, Clasificacion: %d, Tipo: %s\n","0270",procesarCadena("0270"), tipoDeToken(procesarCadena("0270")));
    printf("Token: %s, Clasificacion: %d, Tipo: %s\n","0x",procesarCadena("0x"), tipoDeToken(procesarCadena("0x")));
    printf("Token: %s, Clasificacion: %d, Tipo: %s\n","24",procesarCadena("24"), tipoDeToken(procesarCadena("24")));
    
    return 0;
}

int procesarCadena (char *cadena){
    //Estado 0 = Estado Inicial
    int estado = 0;
    //La matriz: 7 x 6
    int matriz[7][6] = {{1,2,2,6,6,6},{5,5,6,6,3,6},{2,2,2,6,6,6},{4,4,4,4,6,6},{4,4,4,4,6,6},{5,5,6,6,6,6},{6,6,6,6,6,6}};
    for(int i=0;i<strlen(cadena);i++){
        estado=matriz[estado][grupoCaracter(cadena[i])];
        //printf("Caracter: %c grupo: %d\n", cadena[i], grupoCaracter(cadena[i]));
        //printf("Estado: %d\n", estado);
        
    }
    return estado;
}

int grupoCaracter(char caracter){
    if(caracter == '0'){
        return 0;
    }else{
        if (caracter >= '1' && caracter <= '7'){
            return 1;
        }
        else{
            if (caracter >= '8' && caracter <='9'){
                return 2;
            }
            else{
                if((caracter >= 'a' && caracter<='f') || (caracter >= 'A' && caracter<='F')){
                    return 3;
                }
                else{
                    if (caracter == 'x' || caracter == 'X'){
                        return 4;
                    }
                }
            }
        }
    }
    return 5; //Error  
}

/**
 * Funcion Auxiliar: Clasifica el tipo de Token segun la matriz de transicion dada en el ejercicio
 * @author Nicolas Garcia
 * @param tipoToken Token a clasificar
 * @return Cadena correspondiente al estado en la matriz de transicion \n
 * (Recordar hacer FREE del parametro retornado)
 */
char* tipoDeToken (int tipoToken){
    char *cadena = malloc(14);
    switch(tipoToken){
        case 1:
        strcpy(cadena, "OCTAL");
        break;
        case 2:
        strcpy(cadena, "DECIMAL");
        break;
        case 3:
        strcpy(cadena, "NO RECONOCIDA");
        break;
        case 4:
        strcpy(cadena, "HEXADECIMAL");
        break;
        case 5:
        strcpy(cadena, "OCTAL");
        break;
        default:
        strcpy(cadena, "NO RECONOCIDA");
        break;
    }
    return cadena;
}
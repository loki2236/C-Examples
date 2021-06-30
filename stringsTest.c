/**
 * 
 * Ejercicio 20 SSL - Desarrolle funciones que realicen:
 *  (a) Calcula la longitud de una cadena;
 *  (b) Determina si una cadena dada es vacía.
 *  (c) Concatena dos cadenas.
 * Ejercicio 21 *
 *  Construya un programa de testeo para cada función del ejercicio anterior.
 * 
 * */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "./milibreria.h"

unsigned int myStrlen (char* input);
int test_myStrlen(void);
int myIsEmpty (char *input);
int test_myIsEmpty();
char* myStrcat (char *dest, char* source);
int test_myStrcat();


int main()
{
    hola();
    test_myStrlen();
    test_myIsEmpty();
    test_myStrcat();
}


int test_myStrlen (){
    printf("\nmyStrlen: \n");
    // Test a simple string:
    printf("Testing an arbitrary string: ");
    assert(myStrlen("Hola!") == 5);
    printf("Passed\n");
    
    // Test an empty string
    printf("Testing an empty string: ");
    assert(myStrlen("") == 0);
    printf("Passed\n");

    // Test a 1byte string starting with '\0'
    char *str = malloc(sizeof(char));
    // If malloc doesnt fail
    if (str){
        str[0]='\0';
        printf("Testing a 1-char string starting with '\\0': ");
        assert(myStrlen(str) == 0);
        printf("Passed\n");

        // Test a 1byte string starting with '(int)0'
        str[0]=0;
        printf("Testing a 1-char string starting with '(int)0': ");
        assert(myStrlen(str) == 0);
        printf("Passed\n");

        // I should have a case for non-null terminated strings
        // but even strlen has undefined behavior in such cases
        // (It will keep looking for a 0 until it finds one)
        // It may incur in memory access violations, int overflows? (since myStrlen is using Uint counter)
        // or return an unexpected number.
    }
    else{
        printf("Malloc failure\n");
        exit(1);
    }
    free(str);
    
}

unsigned int myStrlen (char* input){
    unsigned int count = 0; //Limited to UInt upper limit
    while (input[count] != '\0'){
        count++;
    }
    return count;
}

// Do I really have to test this?
// Is there any case that I could have missed?
int myIsEmpty (char *input){
    return (myStrlen(input)==0);
}

int test_myIsEmpty (){
    printf("\nmyIsEmpty: \n");
    printf("Testing an empty string: ");
    assert(myIsEmpty(""));
    printf("Passed\n");
    
}

int test_myStrcat(){

    printf("\nmyStrcat: \n");
    

    char *five = malloc(sizeof(char)*5);
    if(five){
        five[0]='\0';
        printf("Testing an arbitrary string: ");
        myStrcat(five, "Hola");
        assert(strcmp(five,"Hola")==0);
        printf("Passed\n");

        // Lets test adding an empty string
        printf("Testing concatenating an empty string: ");
        memset(five,0,5);
        myStrcat(five, "123");
        myStrcat(five, "");
        assert(strcmp(five,"123")==0);
        printf("Passed\n");

        // Lets test adding two empty strings
        printf("Testing concatenating two empty strings: ");
        memset(five,0,5);
        myStrcat(five, "");
        myStrcat(five, "");
        assert(strcmp(five,"")==0);
        printf("Passed\n");

        // Should I test undefined behavior? Neh
    }
    else{
        printf("Malloc Failed");
        exit(1);
    }
    free(five);

}


char* myStrcat (char *dest, char *source){
    
    //Pointer to the '\0' of dest
    char* ptr = dest + myStrlen(dest);
 
    // Not using count as I did in myStrlen

    while (*source != '\0'){
        *ptr++ = *source++;
    }
     
    *ptr = '\0';
 
    return dest;
}
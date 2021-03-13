/* Newton method for finding perfect squares */
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int isPerfectSquare(int a);

int main()
{
    int test;
    printf("Enter a number for square test: ");
    scanf("%d", &test);
    // Start the Clock
    clock_t tic = clock();

    if (!isPerfectSquare(test)){
        printf("Number is not perfect Square\n");   
    }
    else{
        printf("Number MAY be a perfect square\n");
    }

    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    
    return 0;
}

// Get perfect squares within 10^-10 precision
int isPerfectSquare(int a){
    
    double precision = pow(10,-10);
    double x = a;
    double root = 0.5 * (x + (a / x));
    
    while (fabs(root - x) > precision) { 
        // Update root
        x = root;
        // Calculate more closed x 
        root = (x + (a / x))/2; 
    } 
    return ((ceilf(root) == root));
}
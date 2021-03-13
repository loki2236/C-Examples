#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_TEST 50

int isPrime_fermat(int a, int runs);
int mcd(int a, int b);
int randCoprime(int a);
unsigned long int modPow(int b, int e, int m);

int main()
{
    int test;
    srand(time(0));
    printf("Enter a number for primality test: ");
    scanf("%d", &test);
    if (!isPrime_fermat(test, NUM_TEST)){
        printf("Number is composite\n");   
    }
    else{
        printf("Number MAY be prime, further testing required");
    }
    return 0;
}

// Returns a fast compositeness test result
// using Fermat little theorem
int isPrime_fermat(int a, int runs){
    for (int i=0;i<runs;i++){
        int r = randCoprime(a);
        if (modPow(r,a-1,a) != 1)
            return 0;
            
        printf("Passed test: %d (coprime: %d)\n", i, r);
    }
    return 1;
}

// Returns MCD between two numbers
// useful when testing for coprimes
int mcd(int a, int b){
    if (b==0)
        return a;
        
    return (mcd(b,a%b));
}

// Returns a random number coprime with a
int randCoprime(int a){
    // Random number between 2 and a-2
    int r = (rand() % (a-2+1))+2;
    while (mcd(a,r) != 1){
       r = (rand() % (a-2+1))+2; 
    }
    return r;
}

// Modular exponentiation implemented as bitshifts
// What is the actual tyype limit on this function?
unsigned long int modPow(int b, int e, int m){
    if(m==1)
        return 0;
    int r=1;
    b=b%m;
    while(e>0){
        if(e%2 ==1)
            r=(r*b)%m;
        e=e>>1;
        b=(b*b)%m;
    }
    return r;
}

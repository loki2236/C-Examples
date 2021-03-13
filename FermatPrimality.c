#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_TEST 50

int isPrime_fermat(unsigned long int a, int runs);
unsigned long int mcd(unsigned long int a, unsigned long int b);
unsigned long int randCoprime(unsigned long int a);
unsigned long long int modPow(unsigned long long int b, unsigned long long int e, unsigned long long int m);
long long int modexp_rl(long long  int b, long long  int e, long long int m);

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
int isPrime_fermat(unsigned long int a, int runs){
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
unsigned long int mcd(unsigned long int a, unsigned long int b){
    if (b==0)
        return a;
        
    return (mcd(b,a%b));
}

// Returns a random number coprime with a
unsigned long int randCoprime(unsigned long int a){
    // Random number between 2 and a-2
    int r = (rand() % (a-2+1))+2;
    while (mcd(a,r) != 1){
       r = (rand() % (a-2+1))+2; 
    }
    return r;
}

// Modular exponentiation implemented as bitshifts
// What is the actual type limit on this function?
unsigned long long int modPow(unsigned long long int b, unsigned long long int e, unsigned long long int m){
    printf("ModPow: %d,%d,%d\n", b,e,m);
    if(m==1)
        return 0;
    unsigned long long int r=1;
    b=b%m;
    while(e>0){
        if(e%2 ==1)
            r=(r*b)%m;
        e=e>>1;
        b=(b*b)%m;
    }
    return r;
}

// Alternative Version?
long long int modexp_rl(long long  int b, long long  int e, long long int m){
    long long r = 1;
    while (1){
        if (e % 2 == 1)
            r = (r * b) % m;

        e /= 2;
        if (e == 0)
            break;
        b = (b * b) % m;
    }
    return r;
}
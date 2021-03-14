#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_TEST 50

int isPrime_miller(unsigned long long int a, int runs);
unsigned long int mcd(unsigned long int a, unsigned long int b);
unsigned long int randCoprime(unsigned long int a);
long long int modPow(long long int b, long long int e, long long int m);
long long int modexp_rl(long long  int b, long long  int e, long long int m);

int main()
{
    unsigned long int test;
    srand(time(0));
    printf("Enter a number for primality test: ");
    scanf("%Ld", &test);
    if (!isPrime_miller(test, NUM_TEST)){
        printf("Number is composite\n");   
    }
    else{
        printf("Number MAY be prime, further testing required");
    }
    return 0;
}

// Returns a compositeness test result
// using Miller-Rabin theorem
int isPrime_miller(unsigned long long int n, int runs){
    // Corner cases
    if (n <= 1 || n == 4)  return 0;
    if (n <= 3) return 1;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    unsigned long long int d = n - 1;
    while (d % 2 == 0){
        d /= 2;
    }
    // Runs the test 'runs' times
    for (int i=0;i<runs;i++){

        unsigned long long int a = randCoprime(n);
        unsigned long long int x = modPow(a,d,n);
        if (x == 1  || x == n-1){
            return 1;
        }
        // Keep squaring x while one of the following doesn't happen
        // (i)   d does not reach n-1
        // (ii)  (x^2) % n is not 1
        // (iii) (x^2) % n is not n-1
        while (d != n-1)
        {
            x = (x%n * x%n) % n;
            d *= 2;
    
            if (x == 1)      return 0;
            if (x == n-1)    return 1;
        }
            
        printf("Test: %d (coprime: %d)\n", i, a);
    }
    return 0;
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
long long int modPow(long long int b, long long int e, long long int m){
    if(m==1)
        return 0;
    long long int r=1;
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
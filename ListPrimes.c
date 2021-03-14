/* Prime List Generator */
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define NUMBERS_TO_TEST 20000000
#define NUM_FERMAT_ITERATIONS 25
#define NUM_MILLER_ITERATIONS 15
#define NUMBERS_PRIME_QMT 25

struct primeNumberNode{
    unsigned long int number;
    struct primeNumberNode *next;
};

int isPrime_multiple(unsigned long long int a);
int isPrime_fermat(unsigned long int a, int runs);
int isPrime_miller(unsigned long long int n, int runs);
int isPerfectSquare(unsigned long long int a);

unsigned long int mcd(unsigned long int a, unsigned long int b);
unsigned long int randCoprime(unsigned long int a);
unsigned long long int modPow(unsigned long long int b, unsigned long long int e, unsigned long long int m);
int digitalRoot(unsigned long long n);

void insertInList(struct primeNumberNode **pHead, struct primeNumberNode **pActual,unsigned long long int i);
void checkList(struct primeNumberNode *pHead);

//Array containing the first prime numbers  to do a quick mod test
unsigned long int primes[NUMBERS_PRIME_QMT];
unsigned int cant_primes=0; //To check how many had been found - or if the array is full


int main()
{
    // Pointer to the start of the list
    struct primeNumberNode *primeList = NULL;
    struct primeNumberNode *pActual = NULL;

    srand(time(0));
    // Start the Clock
    clock_t tic = clock();
    //insert the basic numbers into the lists (2 not in the multiple-checking list, that's just for odd primes)
    insertInList(&primeList, &pActual, 2);

    // Start the big loop (just odd numbers // starting from 3)
    for(unsigned long int i = 3;i<NUMBERS_TO_TEST;i+=2){
        if(i%10 != 5 && i>5){
        if(digitalRoot(i)%3 != 0 ){ //Numbers which digital roots end in 3,6 or 9 are not primes
            // Check basic things (number must be odd was already checked, not a perfect square, not multiple of other prime)
            if(!isPrime_multiple(i)){
                if (!isPerfectSquare(i)){
                    // Was not a perfect square, lets run a few rounds of Fermat little theorem
                    if (isPrime_fermat(i, NUM_FERMAT_ITERATIONS)){
                        // So, passed the fermat tests, lets suppose it's a prime (Later we will have to run a Lucas test)

                        //if the small primes list is NOT full yet
                        if(cant_primes < NUMBERS_PRIME_QMT){
                            //We shouldn't fail here, maybe increase the number of iterations?
                            if(isPrime_miller(i, NUM_MILLER_ITERATIONS*2)){
                                primes[cant_primes] = i;
                                cant_primes++;
                                //Insert the possible prime in a List
                                insertInList(&primeList, &pActual,i);
                            }
                        }else{
                            //Insert the possible prime in a List
                            insertInList(&primeList, &pActual, i);
                        }
                    }
                }
            }
        }
        }
    }
    

    clock_t toc = clock();
    checkList(primeList);
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    return 0;
}

// Get perfect squares within 10^-10 precision
int isPerfectSquare(unsigned long long int a){
    
    double precision = pow(10,-10);
    double x = a*1.0;
    double root = 0.5 * (x + (a*1.0 / x));
    
    while (fabs(root - x) > precision) { 
        // Update root
        x = root;
        // Calculate more closed x 
        root = (x + (a*1.0 / x))/2; 
    } 
    return (ceilf(root) == root);
}

// Returns a fast compositeness test result
// using Fermat little theorem
int isPrime_fermat(unsigned long int a, int runs){
    for (int i=0;i<runs;i++){
        int r = randCoprime(a);
        if (modPow(r,a-1,a) != 1)
            return 0;         
        //printf("Passed test: %d (coprime: %d)\n", i, r);
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
    }
    return 0;
}

// Inserts a node into a Single-linked list
void insertInList(struct primeNumberNode **pHead, struct primeNumberNode **pActual,unsigned long long int i){

    // Allocate memory for new node 
    struct primeNumberNode* new_node = (struct primeNumberNode*)malloc(sizeof(struct primeNumberNode));
    // Let's be sure
    if (new_node==NULL)
    {
        printf("Malloc Failed, somehow, beware\n");
        exit(-1);
    }
    // Lets put the data in the struct
    new_node->number = i;
    new_node->next = NULL;

    if (*pHead == NULL){
        *pHead = new_node;
        *pActual = *pHead;
        return;
    }

    // Insert in the next pos
    if((*pActual)->next == NULL){
        (*pActual)->next = new_node;
        *pActual = new_node;
    }
    
}

// Travels along the list
void checkList(struct primeNumberNode *pHead){
    struct primeNumberNode *pActual;
    int m =0;
    if (pHead == NULL){
        return;
    }
    pActual = pHead;
    // Browse the list 'til the end
    while(pActual->next != NULL){
        
        if (!isPrime_miller(pActual->number, NUM_MILLER_ITERATIONS)){
            printf("We've found a pseudoprime: %Ld (DigitalRoot: %d)\n", pActual->number, digitalRoot(pActual->number));
            m++;
        }
        else{
            //printf("Possible Prime in list: %Ld\n", pActual->number);
        }
        pActual = pActual->next;
    }
    printf("Number of pseudoprimes found in list: %d\n", m);
}

int isPrime_multiple(unsigned long long int a){
    for(unsigned int i = 0;i<cant_primes;i++){
        if ((a % primes[i]) == 0){
            return 1;
        }
    }
    return 0;
}

// Returns digital root of num 
int digitalRoot(unsigned long long n)
{ 
    // n won't ever be 0, so, nada
    //if (n == 0) 
        //return 0; 
    unsigned int ans = 0; 
    while (n>0){
        ans += n%10;
        n /= 10;
    }

    // If digit sum is multiple of 9, answer 
    // 9, else remainder with 9. 
    return (ans%9 == 0)? 9 : ans % 9; 
    //return (ans>=10)? digitalRoot(ans): ans;
} 
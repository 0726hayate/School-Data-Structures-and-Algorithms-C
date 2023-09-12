#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hashtable size. You might want to redefine this.
#define SIZE 10000

// Function prototypes
int isPrime(int);
int nextPrime(int);
int insertLinearProbe(int, int hashTable[], int);
int insertQuadraticProbe(int, int hashTable[], int);

int main(void) {
    // Variable declarations
    double loadFactor;
    int probeType;
while(1){
    // Get load factor and probe type from user
    printf("Enter the load factor (between 0.1 and 0.9): ");
    scanf("%lf", &loadFactor);
    printf("Choose the probe type (1 for linear, 2 for quadratic): ");
    scanf("%d", &probeType);

    // Redefine size of hashtable
    int listSize = (int)(SIZE / loadFactor);
    int listSizePrime = nextPrime(listSize);

    // Allocate storage for hashtable and initialize all entries to -1
    int *hashTable = (int *)calloc(listSizePrime, sizeof(int));

    // Generate random numbers and insert into the hash table SIZE times,
    // keeping track of the total number of probes
    int numberOfProbes = 0;
    for(int i = 0; i< listSizePrime; i++) hashTable[i] = -1;
    srand(time(NULL)); // Seed the random number generator
    // Generate random numbers
    for (int i = 0; i < SIZE; i++) {
        int key = rand(); // Generate a random integer key
        if (probeType == 1) {
            numberOfProbes += insertLinearProbe(key, hashTable, listSizePrime);
        } else if (probeType == 2) {
            numberOfProbes += insertQuadraticProbe(key, hashTable, listSizePrime);
        } else {
            printf("Invalid probe type. Please choose 1 for linear or 2 for quadratic probing.\n");
            free(hashTable);
            return 1;
        }
    }

    // Print statistics
    printf("Number of probes: %d\n", numberOfProbes);
    printf("Average number of probes using %s probing: %.2f\n", probeType == 1 ? "linear" : "quadratic", (double)numberOfProbes / SIZE);
    if(probeType == 1)
        printf("Expected number of probes for linear probing: %.2f\n",(double)(1 + 1 / ( 1 - loadFactor ) ) / 2);

    // Free allocated memory for the hash table
    free(hashTable);

    printf("\n\n");
}
    return 0;
}

// This function counts the number of probes made to insert key into the hashtable using linear probing
int insertLinearProbe(int key, int hashTable[], int listSize) {
    int index = key % listSize;
    int probes = 0;

    while (hashTable[index] != -1) {
        probes++;
        index = (index + 1) % listSize;
    }

    hashTable[index] = key;
    return probes +1 ;
}

// This function counts the number of probes made to insert key into the hashtable using quadratic probing
int insertQuadraticProbe(int key, int hashTable[], int listSize) {
    int index = key % listSize;
    int probes = 0;

    while (hashTable[index] != -1) {
        probes++;
        index = (index + probes * probes) % listSize;
    }

    hashTable[index] = key;
    return probes +1;
}

// This function checks if a given positive integer is a prime
int isPrime(int n) {
    if (n == 2 || n == 3)
        return 1;
    if (n == 1 || n % 2 == 0)
        return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

// This function returns the next prime after n
int nextPrime(int n) {
    if (n % 2 == 0)
        n++;
    for (; !isPrime(n); n += 2)
        ;
    return n;
}

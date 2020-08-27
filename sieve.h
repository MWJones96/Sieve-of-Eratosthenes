#ifndef SIEVE_H
#define SIEVE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRINT_FANCY
#define PRINT_MEM_USAGE

#define BOOL uint8_t
#define TRUE 1
#define FALSE 0

#define NO_PRIME_ERROR -1
#define MIN(a,b) (((a)<(b))?(a):(b))

struct SieveArgs
{
    int maxNum;
    int numCols;
    BOOL fancy;
    BOOL mem;
};

struct SieveConfig
{
    struct SieveArgs args;

    const int NUM_BITS;
    const int NUM_BYTES;
    const int SEARCH_LIMIT;

    size_t SIZE;
    uint8_t* sieve;
};

void solveForPrimes(struct SieveConfig);
BOOL getBit(uint8_t*, int);
void setBit(uint8_t*, int);
void printPrimes(struct SieveConfig);
void printPrimesList(uint8_t*, size_t);
void printPrimesFancy(uint8_t*, size_t, uint8_t, int);
uint8_t numDigits(int);
void printRow(uint8_t, uint8_t);
int getHighestPrime(uint8_t*, size_t);
int getTotalNumberOfPrimes(uint8_t*, size_t);

#endif
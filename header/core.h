#ifndef CORE_H
#define CORE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STRING_MATCH 0

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

#endif
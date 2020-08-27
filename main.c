#include "sieve.h"
#include "args.h"

struct SieveConfig
{
    struct SieveArgs args;

    const int NUM_BITS;
    const int NUM_BYTES;
    const int SEARCH_LIMIT;

    size_t SIZE;
    uint8_t* sieve;
};

int main(int argc, char** argv)
{
    struct SieveArgs args = getSieveArgs(argc, argv);

    const int NUM_BITS = args.maxNum + 1;
    const int NUM_BYTES = ceil(NUM_BITS / 8.0);
    const int SEARCH_LIMIT = ceil(sqrt(args.maxNum));

    const size_t SIZE = NUM_BYTES * sizeof(uint8_t);
    uint8_t* sieve = (uint8_t*) malloc(SIZE);

    struct SieveConfig config = {args, NUM_BITS, NUM_BYTES, SEARCH_LIMIT, SIZE, sieve};

    solveForPrimes(sieve, SIZE, SEARCH_LIMIT, args.maxNum);
    
    if(args.fancy)
        printPrimesFancy(sieve, NUM_BITS, MIN(getTotalNumberOfPrimes(sieve, NUM_BITS), args.numCols), args.maxNum);
    else
        printPrimes(sieve, NUM_BITS);
    
    if (args.mem)
        printf("Memory used: %d Bytes\n", SIZE);

    free(sieve);
    return 0;
}
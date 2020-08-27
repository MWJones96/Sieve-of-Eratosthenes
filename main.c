#include "sieve.h"
#include "args.h"

int main(int argc, char** argv)
{
    struct SieveArgs args = getSieveArgs(argc, argv);

    const int SEARCH_LIMIT = ceil(sqrt(args.maxNum));

    //Range 0-MAX_NUM inclusive
    const int NUM_BITS = args.maxNum + 1;
    const int NUM_BYTES = ceil(NUM_BITS / 8.0);
    const size_t SIZE = NUM_BYTES * sizeof(uint8_t);

    uint8_t* sieve = (uint8_t*) malloc(SIZE);

    solve_for_primes(sieve, SIZE, SEARCH_LIMIT, args.maxNum);
    
    if(args.fancy)
        print_primes_fancy(sieve, NUM_BITS, MIN(getTotalNumberOfPrimes(sieve, NUM_BITS), args.numCols), args.maxNum);
    else
        print_primes(sieve, NUM_BITS);
    
    if (args.mem)
        printf("Memory used: %d Bytes\n", SIZE);

    free(sieve);
    return 0;
}
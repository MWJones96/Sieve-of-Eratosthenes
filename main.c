#include "sieve.h"

int main(int argc, char** argv)
{
    const int MAX_NUM = 100;
    const int NUM_COLS = 12;
    const int SEARCH_LIMIT = ceil(sqrt(MAX_NUM));

    //Range 0-MAX_NUM inclusive
    const int NUM_BITS = MAX_NUM + 1;
    const int NUM_BYTES = ceil(NUM_BITS / 8.0);
    const size_t SIZE = NUM_BYTES * sizeof(uint8_t);

    uint8_t* sieve = (uint8_t*) malloc(SIZE);

    solve_for_primes(sieve, SIZE, SEARCH_LIMIT, MAX_NUM);

    int num_primes = getTotalNumberOfPrimes(sieve, NUM_BITS);
    
    #ifdef PRINT_FANCY
        print_primes_fancy(sieve, NUM_BITS, MIN(num_primes, NUM_COLS), MAX_NUM);
    #else
        print_primes(sieve, NUM_BITS);
    #endif
    
    #ifdef PRINT_MEM_USAGE
        printf("Memory used: %d Bytes\n", SIZE);
    #endif

    free(sieve);
    return 0;
}
#include "../header/core.h"
#include "../header/sieve.h"
#include "../header/args.h"

int main(int argc, char** argv)
{
    struct SieveArgs args = getSieveArgs(argc, argv);

    const int NUM_BITS = args.maxNum + 1;
    const int NUM_BYTES = ceil(NUM_BITS / 8.0);
    const int SEARCH_LIMIT = ceil(sqrt(args.maxNum));

    const size_t SIZE = NUM_BYTES * sizeof(uint8_t);
    uint8_t* sieve = (uint8_t*) malloc(SIZE);

    struct SieveConfig config = {args, NUM_BITS, NUM_BYTES, SEARCH_LIMIT, SIZE, sieve};

    solveForPrimes(config);
    config.args.numCols = MIN(getTotalNumberOfPrimes(sieve, NUM_BITS), args.numCols);
    printPrimes(config);

    free(config.sieve);
    return 0;
}
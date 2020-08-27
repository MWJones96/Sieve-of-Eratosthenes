#include "sieve.h"
#include "args.h"

void solveForPrimes(struct SieveConfig config)
{
    setBit(config.sieve, 0);
    setBit(config.sieve, 1);
    
    int p;
    for (p = 2; p <= config.SEARCH_LIMIT; p++)
    {
        int q = 2 * p;
        while (q <= config.args.maxNum) {
            setBit(config.sieve, q);
            q += p;
        }
    }
}

BOOL getBit(uint8_t* sieve, int bit)
{
    int byte = bit / 8;
    int offset = bit % 8;

    uint8_t sieveByte = *(sieve + byte);

    uint8_t bitMask = 1 << offset;
    return (sieveByte & bitMask);
}

void setBit(uint8_t* sieve, int bit)
{
    int byte = bit / 8;
    int offset = bit % 8;

    uint8_t sieveByte = *(sieve + byte);
    uint8_t bitMask = 1 << offset;

    sieveByte |= bitMask;
    *(sieve + byte) = sieveByte;
}

void printPrimes(struct SieveConfig config)
{
    (config.args.fancy) ? 
        printPrimesFancy(config.sieve, config.num, config.args.numCols, config.args.maxNum) : 
        printPrimesList(config.sieve, config.NUM_BITS);

     if (config.args.mem)
        printf("Memory used: %d Bytes\n", config.SIZE);
    
}

void printPrimesList(uint8_t* sieve, size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (!getBit(sieve, i))
        {
            printf("%d\n", i);
        }
    }
}

void printPrimesFancy(uint8_t* sieve, size_t size, uint8_t cols, int max)
{
    const uint8_t NUM_DIGITS = numDigits(getHighestPrime(sieve, size));

    printf("All prime numbers <= %d\n\n", max);
    printRow(cols, NUM_DIGITS);

    int nums_placed = 0;

    int i;
    for (i = 0; i < size; i++)
    {
        if (!getBit(sieve, i))
        {
            printf("| ");

            uint8_t num_spaces = NUM_DIGITS - numDigits(i);
            while (num_spaces-- > 0) {
                printf(" ");
            }

            printf("%d", i);
            printf(" ");

            if (++nums_placed % cols == 0) 
            {
                printf("|\n");
                printRow(cols, NUM_DIGITS);
            }
        }

        if (i >= size - 1)
        {
            if (nums_placed % cols != 0) 
            {
                printf("|\n");
                printRow(nums_placed % cols, NUM_DIGITS);
            }
        }
    }
}

uint8_t numDigits(int n)
{
    return (n < 10) ? 1 : 1 + numDigits(n/10);
}

void printRow(uint8_t cols, uint8_t numDigits)
{
    printf("-");

    int col;
    for (col = 0; col < cols; col++)
    {
        printf("-");
        int digit;
        for (digit=0; digit < numDigits; digit++)
        {
            printf("-");
        }
        printf("--");
    }

    printf("\n");
}

int getHighestPrime(uint8_t* sieve, size_t size)
{
    int index = size - 1;

    while (index-- >= 0)
    {
        if (!getBit(sieve, index)) 
        {
            return index;
        }
    }

    return NO_PRIME_ERROR;
}

int getTotalNumberOfPrimes(uint8_t* sieve, size_t size)
{
    int total = 0;

    int i;
    for (i = 0; i < size; i++)
    {
        if (!getBit(sieve, i))
        {
            ++total;
        }
    }

    return total;
}
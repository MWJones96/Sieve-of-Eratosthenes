#include "sieve.h"

struct SieveArgs
{
    int maxNum;
    int numCols;
    BOOL fancy;
    BOOL mem;
};

#define STRING_MATCH 0

struct SieveArgs getSieveArgs(int argc, char** argv);
BOOL isInteger(char* string);
void printErrorAndExit(char* arg);

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

struct SieveArgs getSieveArgs(int argc, char** argv)
{
    struct SieveArgs sieveArgs = {100, 10, FALSE, FALSE};

    int argIndex;
    for (argIndex = 1; argIndex < argc; argIndex++) 
    {
        char* argString = argv[argIndex];
        if (strcmp(argString, "--fancy") == STRING_MATCH) 
        {
            sieveArgs.fancy = TRUE;
        }
        else if (strcmp(argString, "--mem") == STRING_MATCH)
        {
            sieveArgs.mem = TRUE;
        }
        else if (strcmp(argString, "--max") == STRING_MATCH)
        {
            if (++argIndex >= argc)
            {
                printErrorAndExit(argString);
            }

            char* numString = argv[argIndex];
            if (!isInteger(numString)) 
            {
                printErrorAndExit(numString);
            }

            sieveArgs.maxNum = atoi(numString);
        }
        else if (strcmp(argString, "--cols") == STRING_MATCH)
        {
            if (++argIndex >= argc)
            {
                printErrorAndExit(argString);
            }

            char* numString = argv[argIndex];
            if (!isInteger(numString))
            {
                printErrorAndExit(numString);
            }

            sieveArgs.numCols = atoi(numString);
        }
        else
        {
            printErrorAndExit(argString);
        }
        
    }

    return sieveArgs;
}

BOOL isInteger(char* string)
{
    int i;
    for (i = 0; i < strlen(string); i++)
    {
        char c = *(string + i);
        if (c < '0' || c > '9') 
        {
            return FALSE;
        }
    }

    return TRUE;
}

void printErrorAndExit(char* arg)
{
    printf("Invalid command line argument: %s\n", arg);
    printf("Valid usage: ./sieve [--max 100] [--cols 10] [--fancy] [--mem]\n");
    exit(-1);
}
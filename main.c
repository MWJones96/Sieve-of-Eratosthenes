#include "sieve.h"

struct SieveArgs
{
    int maxNum;
    int numCols;
    BOOL fancy;
};

struct SieveArgs getSieveArgs(int argc, char** argv);
BOOL isNumber(char* string);

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
    
    #ifdef PRINT_MEM_USAGE
        printf("Memory used: %d Bytes\n", SIZE);
    #endif

    free(sieve);
    return 0;
}

struct SieveArgs getSieveArgs(int argc, char** argv)
{
    struct SieveArgs sieveArgs = {100, 10, FALSE};

    int argIndex;
    for (argIndex=1; argIndex < argc; argIndex++) 
    {
        char* argString = argv[argIndex];
        if (strcmp(argString, "--fancy")) 
        {
            sieveArgs.fancy = TRUE;
        }
        else if (strcmp(argString, "--max"))
        {
            if (++argIndex >= argc)
            {
                printf("Invalid command line usage, no number given for --max\n");
                printf("Valid usage: ./sieve [--max 100] [--cols 10] [--fancy]\n");
                exit(-1);
            }

            char* numString = argv[argIndex];
            if (!isNumber) 
            {
                printf("Invalid command line usage, %s must be an integer\n", numString);
                printf("Valid usage: ./sieve [--max 100] [--cols 10] [--fancy]\n");
                exit(-1);
            }

            sieveArgs.maxNum = atoi(numString);
        }
        else if (strcmp(argString, "--cols"))
        {
            if (++argIndex >= argc)
            {
                printf("Invalid command line usage, no number given for --cols\n");
                printf("Valid usage: ./sieve [--max 100] [--cols 10] [--fancy]\n");
                exit(-1);
            }

            char* numString = argv[argIndex];
            if (!isNumber)
            {
                printf("Invalid command line usage, %s must be an integer\n", numString);
                printf("Valid usage: ./sieve [--max 100] [--cols 10] [--fancy]\n");
                exit(-1);
            }

            sieveArgs.numCols = atoi(numString);
        }
        else
        {
            printf("Invalid command line argument: %s\n", argString);
            printf("Valid usage: ./sieve [--max 100] [--cols 10] [--fancy]\n");
            exit(-1);
        }
        
    }

    return sieveArgs;
}

BOOL isNumber(char* string)
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
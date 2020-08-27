#include "args.h"

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
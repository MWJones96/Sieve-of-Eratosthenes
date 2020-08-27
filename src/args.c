#include "../header/core.h"
#include "../header/args.h"

struct SieveArgs getSieveArgs(int argc, char** argv)
{
    struct SieveArgs sieveArgs = {100, 10, FALSE, FALSE};

    int argIndex;
    for (argIndex = 1; argIndex < argc; argIndex++) 
    {
        char* argString = argv[argIndex];
        if (strcmp(argString, "--fancy") == STRING_MATCH) 
            sieveArgs.fancy = TRUE;
        else if (strcmp(argString, "--mem") == STRING_MATCH)
            sieveArgs.mem = TRUE;
        else if (strcmp(argString, "--max") == STRING_MATCH)
        {
            if (++argIndex >= argc)
                printErrorAndExit(argString, "There is no value after the --max flag");

            char* numString = argv[argIndex];
            if (!isInteger(numString)) 
                printErrorAndExit(numString, "--max is not a positive integer");

            int num = atoi(numString);
            if (num < 2)
                printErrorAndExit(numString, "--max must be >= 2");

            sieveArgs.maxNum = num;
        }
        else if (strcmp(argString, "--cols") == STRING_MATCH)
        {
            if (++argIndex >= argc)
                printErrorAndExit(argString, "There is no value after the --cols flag");

            char* numString = argv[argIndex];
            if (!isInteger(numString))
                printErrorAndExit(numString, "--cols is not a positive integer");

            int num = atoi(numString);
            if (num < 2)
                printErrorAndExit(numString, "--cols must be >= 2");

            sieveArgs.numCols = num;
        }
        else
            printErrorAndExit(argString, "Not a valid command, choose from [--max, --cols, --fancy, --mem]");
        
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

void printErrorAndExit(char* arg, char* msg)
{
    printf("BAD VALUE %s: %s\n", arg, msg);
    printf("Correct usage: ./sieve [--max 100] [--cols 10] [--fancy] [--mem]\n");
    exit(-1);
}
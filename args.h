#ifndef ARGS_H
#define ARGS_H

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

#endif
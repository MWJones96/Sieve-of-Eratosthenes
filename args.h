#ifndef ARGS_H
#define ARGS_H

#include "sieve.h"

#define STRING_MATCH 0

struct SieveArgs getSieveArgs(int argc, char** argv);
BOOL isInteger(char* string);
void printErrorAndExit(char* arg);

#endif
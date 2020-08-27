#ifndef ARGS_H
#define ARGS_H

struct SieveArgs getSieveArgs(int, char**);
BOOL isInteger(char*);
void printErrorAndExit(char*, char*);

#endif
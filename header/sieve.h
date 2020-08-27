#ifndef SIEVE_H
#define SIEVE_H

#include "core.h"

void solveForPrimes(struct SieveConfig);
BOOL getBit(uint8_t*, int);
void setBit(uint8_t*, int);
void printPrimes(struct SieveConfig);
void printPrimesList(uint8_t*, size_t);
void printPrimesFancy(uint8_t*, size_t, uint8_t, int);
uint8_t numDigits(int);
void printRow(uint8_t, uint8_t);
int getHighestPrime(uint8_t*, size_t);
int getTotalNumberOfPrimes(uint8_t*, size_t);

#endif
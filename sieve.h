#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRINT_FANCY
#define PRINT_MEM_USAGE

#define BOOL uint8_t
#define NO_PRIME_ERROR -1
#define MIN(a,b) (((a)<(b))?(a):(b))

BOOL get_bit(uint8_t* sieve, int bit);
void set_bit(uint8_t* sieve, int bit);
void print_primes(uint8_t* sieve, size_t size);
void print_primes_fancy(uint8_t* sieve, size_t size, uint8_t cols, int max);
uint8_t num_digits(int n);
void print_row(uint8_t cols, uint8_t numDigits);
int get_highest_prime(uint8_t* sieve, size_t size);
int getTotalNumberOfPrimes(uint8_t* sieve, size_t size);
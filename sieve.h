#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRINT_FANCY
#define PRINT_MEM_USAGE

#define BOOL uint8_t
#define NO_PRIME_ERROR -1
#define MIN(a,b) (((a)<(b))?(a):(b))

void solve_for_primes(uint8_t*, size_t, int, int);
BOOL get_bit(uint8_t*, int);
void set_bit(uint8_t*, int);
void print_primes(uint8_t*, size_t);
void print_primes_fancy(uint8_t*, size_t, uint8_t, int);
uint8_t num_digits(int);
void print_row(uint8_t, uint8_t);
int get_highest_prime(uint8_t*, size_t);
int getTotalNumberOfPrimes(uint8_t*, size_t);
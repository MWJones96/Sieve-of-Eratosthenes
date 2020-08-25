#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOOL uint8_t

BOOL get_bit(uint8_t* sieve, int bit);
void set_bit(uint8_t* sieve, int bit);
void print_primes(uint8_t* sieve, size_t size);
void print_primes_fancy(uint8_t* sieve, size_t size, uint8_t cols, int max);
uint8_t num_digits(int n);
void print_header(uint8_t cols, uint8_t numDigits);

int main(int argc, char** argv)
{
    const int MAX_NUM = 1000;
    const int NUM_COLS = 8;

    const int SEARCH_LIMIT = ceil(sqrt(MAX_NUM));

    //Range 0-MAX_NUM inclusive
    const int NUM_BITS = MAX_NUM + 1;
    const int NUM_BYTES = ceil(NUM_BITS / 8.0);

    const size_t SIZE = NUM_BYTES * sizeof(uint8_t);
    uint8_t* sieve = (uint8_t*) malloc(SIZE);

    set_bit(sieve, 0);
    set_bit(sieve, 1);
    
    int p;
    for (p = 2; p <= SEARCH_LIMIT; p++)
    {
        int q = 2 * p;
        while (q <= MAX_NUM) {
            set_bit(sieve, q);
            q += p;
        }
    }

    print_primes_fancy(sieve, NUM_BITS, NUM_COLS, MAX_NUM);
    //printf("Memory used: %d Bytes\n", SIZE);

    free(sieve);
    return 0;
}

BOOL get_bit(uint8_t* sieve, int bit)
{
    int byte = bit / 8;
    int offset = bit % 8;

    uint8_t sieveByte = *(sieve + byte);

    uint8_t bitMask = 1 << offset;
    return (sieveByte & bitMask);
}

void set_bit(uint8_t* sieve, int bit)
{
    int byte = bit / 8;
    int offset = bit % 8;

    uint8_t sieveByte = *(sieve + byte);
    uint8_t bitMask = 1 << offset;

    sieveByte |= bitMask;
    *(sieve + byte) = sieveByte;
}

void print_primes(uint8_t* sieve, size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (!get_bit(sieve, i))
        {
            printf("%d\n", i);
        }
    }
}

void print_primes_fancy(uint8_t* sieve, size_t size, uint8_t cols, int max)
{
    printf("All prime numbers <= %d\n", max);
    print_header(cols, num_digits(max));
}

uint8_t num_digits(int n)
{
    if (n < 10)
    {
        return 1;
    }
    else
    {
        return 1 + num_digits(n / 10);
    }
}

void print_header(uint8_t cols, uint8_t numDigits)
{
    printf("-");

    int col;
    for (col = 0; col < cols; col++)
    {
        printf("-");
        int digit;
        for (digit=0; digit < numDigits; digit++)
        {
            printf("-");
        }
        printf("--");
    }

    printf("\n");
}
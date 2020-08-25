#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOOL uint8_t

BOOL get_bit(uint8_t* sieve, int bit);
void set_bit(uint8_t* sieve, int bit);
void print_primes(uint8_t* sieve, size_t size);

int main(int argc, char** argv)
{
    const int MAX_NUM = 1000;
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

    print_primes(sieve, NUM_BITS);

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
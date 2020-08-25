#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOOL uint8_t

BOOL get_bit(uint8_t* sieve, int bit);
void set_bit(uint8_t* sieve, int bit);

int main(int argc, char** argv)
{
    const int MAX_NUM = 1000;

    //Range 0-MAX_NUM inclusive
    const int NUM_BITS = MAX_NUM + 1;
    const int NUM_BYTES = ceil(NUM_BITS / 8.0);

    uint8_t* sieve = (uint8_t*) malloc(NUM_BYTES * sizeof(uint8_t));

    int i;
    for (i = 0; i < NUM_BITS; i++)
    {
        set_bit(sieve, i);
        BOOL b = get_bit(sieve, i);
    }

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
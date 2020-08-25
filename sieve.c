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
int get_highest_prime(uint8_t* sieve, size_t size);

int main(int argc, char** argv)
{
    const int MAX_NUM = 20;
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
    const uint8_t NUM_DIGITS = num_digits(get_highest_prime(sieve, size));

    printf("All prime numbers <= %d\n", max);
    print_header(cols, NUM_DIGITS);

    int nums_placed = 0;

    int i;
    for (i = 0; i < size; i++)
    {
        if (!get_bit(sieve, i))
        {
            printf("| ");

            uint8_t num_spaces = NUM_DIGITS - num_digits(i);
            while (num_spaces-- > 0) {
                printf(" ");
            }

            printf("%d", i);

            printf(" ");
            ++nums_placed;
        }

        if ((nums_placed % cols == 0 && !get_bit(sieve, i)) || i >= size-1)
        {
            printf("|\n");
            print_header(cols, NUM_DIGITS);
        }
    }
}

uint8_t num_digits(int n)
{
    return (n < 10) ? 1 : 1 + num_digits(n/10);
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

int get_highest_prime(uint8_t* sieve, size_t size)
{
    int index = size - 1;

    while (index-- >= 0)
    {
        if (!get_bit(sieve, index)) 
        {
            return index;
        }
    }

    return -1;
}
#include "sieve.h"

void solve_for_primes(uint8_t* sieve, size_t size, int search_lim, int maxNum)
{
    set_bit(sieve, 0);
    set_bit(sieve, 1);
    
    int p;
    for (p = 2; p <= search_lim; p++)
    {
        int q = 2 * p;
        while (q <= maxNum) {
            set_bit(sieve, q);
            q += p;
        }
    }
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

    printf("All prime numbers <= %d\n\n", max);
    print_row(cols, NUM_DIGITS);

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

            if (++nums_placed % cols == 0) 
            {
                printf("|\n");
                print_row(cols, NUM_DIGITS);
            }
        }

        if (i >= size - 1)
        {
            if (nums_placed % cols != 0) 
            {
                printf("|\n");
                print_row(nums_placed % cols, NUM_DIGITS);
            }
        }
    }
}

uint8_t num_digits(int n)
{
    return (n < 10) ? 1 : 1 + num_digits(n/10);
}

void print_row(uint8_t cols, uint8_t numDigits)
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

    return NO_PRIME_ERROR;
}

int getTotalNumberOfPrimes(uint8_t* sieve, size_t size)
{
    int total = 0;

    int i;
    for (i = 0; i < size; i++)
    {
        if (!get_bit(sieve, i))
        {
            ++total;
        }
    }

    return total;
}
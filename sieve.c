#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
    const int MAX_NUM = 1000;

    //Range 0-MAX_NUM inclusive
    const int NUM_BITS = MAX_NUM + 1;
    const int NUM_BYTES = ceil(NUM_BITS / 8.0);

    uint8_t* sieve = (uint8_t*) malloc(NUM_BYTES * sizeof(uint8_t));



    free(sieve);

    return 0;
}

# Sieve of Eratosthenes

The classic Sieve of Eratosthenes written in C. It finds all prime numbers less than or equal to N and prints them, either as a list or as a table.

## Overview

The program allocates a bit array with one bit per integer from 0 to N, where a set bit marks a number as composite. 0 and 1 are marked first; then, for every p from 2 up to the ceiling of the square root of N, every multiple of p from 2p upwards is marked. The numbers whose bits remain clear are the primes.

Storing one bit per number, rather than one byte or integer, keeps memory use to roughly N / 8 bytes.

## Features

- Bit-packed sieve (`getBit` and `setBit` operate on individual bits of a `uint8_t` array)
- Configurable upper limit
- Two output formats: one prime per line, or a bordered table with a configurable number of columns and right-aligned numbers
- Optional report of the memory used by the sieve
- Validation of command-line arguments, with an error message and usage line on bad input

## Getting started

### Prerequisites

- GCC (the Makefile calls `gcc` directly)
- GNU Make
- The C standard library and maths library (`-lm`)

### Build

Either of the following builds the `sieve` executable:

```sh
make
```

```sh
make sieve
```

To build a single intermediate object file, name it as the target, for example:

```sh
make main.o
```

### Clean

```sh
make clean
```

This removes the object files and the `sieve` executable.

## Usage

Run the program with its defaults:

```sh
./sieve
```

Run the program with optional command-line arguments, in any order:

```sh
./sieve --max 100 --cols 10 --fancy --mem
```

### Arguments

| Argument     | Description                                          | Default  |
|--------------|------------------------------------------------------|----------|
| `--max N`    | The upper limit for prime numbers to be searched (N >= 2) | 100 |
| `--cols N`   | The number of columns displayed (fancy format only, N >= 1) | 10 |
| `--fancy`    | Prints the numbers in a tabular format               | false    |
| `--mem`      | Prints memory usage information                      | false    |

If `--cols` is larger than the number of primes found, the table is narrowed to fit. Any unrecognised argument, missing value or non-integer value prints an error and the correct usage, and exits with a non-zero status.

### Example

```
$ ./sieve --max 30 --cols 5 --fancy --mem
Prime numbers <= 30
--------------------------
|  2 |  3 |  5 |  7 | 11 |
--------------------------
| 13 | 17 | 19 | 23 | 29 |
--------------------------
Memory used: 4 Bytes
```

Without `--fancy`, each prime is printed on its own line beneath the `Prime numbers <= N` heading.

## Project structure

```
.
├── Makefile          # Builds the sieve executable and its object files
├── header/
│   ├── core.h        # Shared includes, BOOL/TRUE/FALSE and MIN macros, SieveArgs and SieveConfig structs
│   ├── args.h        # Argument-parsing declarations
│   └── sieve.h       # Sieve and printing declarations
└── src/
    ├── main.c        # Entry point: parses arguments, allocates the bit array, runs the sieve and prints
    ├── args.c        # Command-line parsing and validation
    └── sieve.c       # Bit operations, the sieve itself, and list and table output
```

## Limitations

- The bit array is allocated with `malloc` and not cleared before sieving, so results depend on the allocated memory starting as zero. Using `calloc` would guarantee it.
- `src/args.c` uses `strcmp` and `strlen` without including `<string.h>`. Older compilers accept this with a warning, but recent compilers (for example GCC 14 and later) treat implicit function declarations as errors, so the build may fail there until the include is added.
- The table's column width is taken from the highest prime below N, so when N is itself prime and has more digits than that prime (for example `--max 11`), the `--fancy` table is misaligned.
- The column count is passed to the table printer as an 8-bit value, so `--cols` values above 255 wrap around.

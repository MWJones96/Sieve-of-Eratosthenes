# Sieve of Eratosthenes
The classic Sieve of Eratosthenes written in C. Finds all prime numbers <= N and prints the output on the screen.

## Usage

Run the program as it is:

```
./sieve
```

Run the program with optional command-line arguments:

```
./sieve --max 100 --cols 10 --fancy --mem
```

## Arguments

| Argument | Description                                          | Default  |
|----------|------------------------------------------------------|----------|
| --max    | The upper limit for prime numbers to be searched     | 100      |
| --cols   | The number of columns displayed (fancy format only)  | 10       |
| --fancy  | Prints the numbers in a tabular format               | false    |
| --mem    | Prints memory usage information                      | false    |

## Make instructions

### Building the executable

```
make
```

```
make sieve
```

### Cleaning the project

```
make clean
```

### Building intermediate object files

```
make _.o
```
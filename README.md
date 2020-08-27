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

--max: The maximum value that the sieve will run up to
--cols: The number of columns displayed (applicable only with fancy printing)
--fancy: Print the numbers in a tabular view on the command line
--mem: Print memory usage information

| Argument      | Description   | Default  |
| ------------- |:-------------:| --------:|
| col 3 is      | right-aligned | $1600    |
| col 2 is      | centered      |   $12    |
| zebra stripes | are neat      |    $1    |
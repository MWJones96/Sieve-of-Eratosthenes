sieve: sieve.o
	gcc -o sieve -g -Wall sieve.o

sieve.o: sieve.c
	gcc -g -c -Wall sieve.c

clean:
	rm -rf *.o sieve
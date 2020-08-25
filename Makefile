sieve: sieve.o main.o
	gcc -o sieve -g -Wall main.o sieve.o -lm

sieve.o: sieve.c
	gcc -g -c -Wall sieve.c

main.o: main.c
	gcc -g -c -Wall main.c

clean:
	rm -rf *.o sieve
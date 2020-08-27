sieve: sieve.o main.o args.o
	gcc -o sieve -g -Wall main.o sieve.o args.o -lm

sieve.o: sieve.c
	gcc -g -c -Wall sieve.c

main.o: main.c
	gcc -g -c -Wall main.c

args.o: args.c
	gcc -g -c -Wall args.c

clean:
	rm -rf *.o sieve
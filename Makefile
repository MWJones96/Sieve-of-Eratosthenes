sieve: sieve.o main.o args.o
	gcc -o sieve -g -Wall main.o sieve.o args.o -lm

main.o: src/main.c
	gcc -g -c -Wall src/main.c

sieve.o: src/sieve.c
	gcc -g -c -Wall src/sieve.c

args.o: src/args.c
	gcc -g -c -Wall src/args.c

clean:
	rm -rf *.o sieve
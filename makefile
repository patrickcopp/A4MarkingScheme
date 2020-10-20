all:  tree.o

tree.o: tree.c tree.h
	gcc -std=c99 -Wall -pedantic -c tree.c -o tree.o
clean:
	rm *.o a.out *.gch


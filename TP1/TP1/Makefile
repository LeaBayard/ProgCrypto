CC = gcc -Wall -g 

all : exo1 exo2 exo3 clean

exo1.o : exo1.c
	$(CC) -o exo1.o -c exo1.c

exo1 : exo1.o
	$(CC) -o exo1 exo1.o

exo2.o : exo2.c
	$(CC) -o exo2.o -c exo2.c

exo2 : exo2.o
	$(CC) -o exo2 exo2.o

exo3.o : exo3.c
	$(CC) -o exo3.o -c exo3.c

exo3 : exo3.o
	$(CC) -o exo3 exo3.o

clean :
	rm *.o
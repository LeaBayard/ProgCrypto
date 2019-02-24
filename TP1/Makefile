CC = gcc
CFLAGS = -g -Wall -std=c11 -lm
ALL1 = table_to_anf.o fctsBooleennes.o
ALL2 = poids.o fctsBooleennes.o
ALL3 = degre.o fctsBooleennes.o

all: $(ALL1) $(ALL2) $(ALL3)
	$(CC) $(CFLAGS) -o ex1.o $(ALL1)
	$(CC) $(CFLAGS) -o ex2.o $(ALL2)
	$(CC) $(CFLAGS) -o ex3.o $(ALL3)

fctsBooleennes: fctsBooleennes.c fctsBooleennes.h
	$(CC) -c fctsBooleennes.c

table_to_anf: table_to_anf.c fctsBooleennes.h
	$(CC) -o table_to_anf.o -c table_to_anf.c

poids: poids.c fctsBooleennes.h
	$(CC) -o poids.o -c poids.c

degre: degre.c fctsBooleennes.h
	$(CC) -o degre.o -c degre.c

clean:
	rm *.o *~

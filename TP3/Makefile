CC = gcc
CFLAGS = -g -Wall -std=c11 -lm
ALL1 = hamming.o fctsBooleennes.o

all: $(ALL1)
	$(CC) $(CFLAGS) -o ex.o $(ALL1)

fctsBooleennes.o: ./../fctsBooleennes.c ./../fctsBooleennes.h
	$(CC) -c ./../fctsBooleennes.c
hamming: hamming.c ./../fctBooleennes.h
	$(CC) -o hamming.o -c hamming.c


clean:
	rm *.o *~

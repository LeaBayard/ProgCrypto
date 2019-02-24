CC = gcc
CFLAGS = -g -Wall -std=c11 -lm
ALL1 = autocorrelation.o fctsBooleennes.o

all: $(ALL1)
	$(CC) $(CFLAGS) -o ex1.o $(ALL1)

fctsBooleennes.o: ./../fctsBooleennes.c ./../fctsBooleennes.h
	$(CC) -c ./../fctsBooleennes.c
autocorrelation: autocorrelation.c ./../fctBooleennes.h
	$(CC) -o autocorrelation.o -c autocorrelation.c


clean:
	rm *.o *~

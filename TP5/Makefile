CC = gcc
CFLAGS = -g -Wall -std=c11 -lm
ALL1 = lfsr.o fctsBooleennes.o
ALL2 = lfsr2.o fctsBooleennes.o

all: $(ALL1) $(ALL2)
	$(CC) $(CFLAGS) -o ex1.o $(ALL1)
	$(CC) $(CFLAGS) -o ex2.o $(ALL2)

fctsBooleennes.o: ./../fctsBooleennes.c ./../fctsBooleennes.h
	$(CC) -c ./../fctsBooleennes.c
lfsr: lfsr.c ./../fctBooleennes.h
	$(CC) -o lfsr.o -c lfsr.c
lfsr2: lfsr2.c ./../fctBooleennes.h
	$(CC) -o lfsr2.o -c lfsr2.c

clean:
	rm *.o *~

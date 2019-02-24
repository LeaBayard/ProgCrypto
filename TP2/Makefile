CC = gcc
CFLAGS = -g -Wall -std=c11 -lm
ALL1 = fourier.o fctsBooleennes.o
ALL2 = walsh.o fctsBooleennes.o
ALL3 = resilience.c fctsBooleennes.o fct_pi_scal.o

all: $(ALL1) $(ALL2) $(ALL3)
	$(CC) $(CFLAGS) -o ex1.o $(ALL1)
	$(CC) $(CFLAGS) -o ex2.o $(ALL2)
	$(CC) $(CFLAGS) -o ex3.o $(ALL3)

fctsBooleennes.o: ./../fctsBooleennes.c ./../fctsBooleennes.h
	$(CC) -c ./../fctsBooleennes.c
fct_pi_scal.o: ./../fct_pi_scal.c ./../fct_pi_scal.h
	$(CC) -c ./../fct_pi_scal.c
fourier.o: fourier.c ./../fctsBooleennes.h
	$(CC) -o fourier.o -c fourier.c
walsh.o: walsh.c ./../fctsBooleennes.h
	$(CC) -o walsh.o -c walsh.c
resilience.o: resilience.c ./../fctsBooleennes.h ./../fct_pi_scal.h
	$(CC) -o resilience.o -c resilience.c

clean:
	rm *.o *~

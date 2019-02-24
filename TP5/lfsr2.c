#include <stdio.h>
#include "./../fctsBooleennes.h"

#define L 9
unsigned int Etat;
unsigned int Polynome = 0xc9; //polynome 1+X^3+X^6+X^7+X^9

//initialisation de l'etat initial avec une table d'entiers donnee
void Initialise(unsigned int e) {
  Etat = e;
}

//affichage de l'etat interne du LFSR 
void AfficheEtat() {
  for (int i = L-1; i >= 0; i--) {
    printf("%2d", (Etat >> i) & 1);
  }

  printf("\n");
}

unsigned int Rebouclage() {
  unsigned int x = Etat & Polynome;
  x ^= (x >> 8);
  x ^= (x >> 4);
  x ^= (x >> 2);
  return (x ^ (x >> 1)) & 1;
}

unsigned int sommeL_1() {
  unsigned int x = Etat & Polynome;
  unsigned int res = 0;

  for (int i = 0; i < L; i++) {
    res ^= ((x >> i) & 1);
  }

  return res;
}

void Avance() {
  unsigned int somme = Rebouclage();
  Etat = Etat >> 1;
  Etat ^= (somme << (L-1));
}

unsigned int periode(unsigned int init) {
  unsigned int p;
  Avance();

  for (p = 1; Etat != init; p++) {
    Avance();
  }

  return p;
}

int main() {

  Initialise(1);
  AfficheEtat();
  printf("rebouclage : %d\n", Rebouclage());
  printf("sommeL_1 : %d\n", sommeL_1());
  for (int i = 0; i < 20; i++) {
    Avance();
  }
  AfficheEtat();

  Initialise(1);

  printf("periode : %u\n", periode(1));
  
  return 0;
}

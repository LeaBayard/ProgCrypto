#include <stdio.h>
#include "./../fctsBooleennes.h"

#define L 9 //dimension du LFSR
int Etat[L]; //etat interne du LFSR
int Polynome[L] = {1, 0, 0, 1, 0, 0, 1, 1, 0}; //polynome 1+X^3+X^6+X^7+X^9

#define TRUE 1
#define FALSE 0

//initialisation de l'etat initial avec une table d'entiers donnee
void Initialise(int* e) {
  for (int i = 0; i < L; i++) {
    Etat[i] = e[i];
  }
}

//afichage de l'etat interne du LFSR
void AfficheEtat() {
  for (int i = L-1; i >= 0; i--) {
    printf("%2d", Etat[i]);
  }
  printf("\n");
}

int sommeL_1() {
  int res = 0;
  for (int i = 0; i < L; i++) {
    res ^= Polynome[i] & Etat[i];
  }
  
  return res;
}

void Avance() {
  int somme = sommeL_1();
  
  for (int i = 0; i < L-1; i++) {
    Etat[i] = Etat[i+1];
  }

  Etat[L-1] = somme;
}

int sontEgaux(int *a, int *b) {
  for (int i = 0; i < L; i++) {
    if (a[i] != b[i]) {
      return FALSE;
    }
  }

  return TRUE;
}

int periode(int *Init) {
  int ord;
  Avance();

  for (ord = 1; !sontEgaux(Etat, Init); ord++) {
    Avance();
  }

  return ord;
}

int main() {
  int EtatInitial[L] = {1, 0, 0, 0, 0, 0, 0, 0, 0};
  Initialise(EtatInitial);
  AfficheEtat();

  //20 iterations
  for (int i = 0; i < 20; i++) {
    Avance();
    AfficheEtat();
  }

  Initialise(EtatInitial);
  printf("periode : %d\n", periode(EtatInitial));

  return 0;
}

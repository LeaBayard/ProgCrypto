#include "../fctsBooleennes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void AutocorrelationNaif(int *r, int* f, int n) {
  int taille = 1 << n;
  int somme;
  
  for (int i = 0 ; i < taille; i++) {
    somme = 0;
    for (int j = 0; j < taille; j++) {
      somme += pow(-1, f[j] + f[j + i]);
    }
    r[i] = somme;
  }
}

void Autocorrelation(int *f, int n) {
  
}
  
int main() {
  int f[8] = {0, 1, 1, 1, 0, 1, 1, 0};
  int r[8];
  AutocorrelationNaif(r, f, 3);
  print_tab(r, 8);
  return 0;
}

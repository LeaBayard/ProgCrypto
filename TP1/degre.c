#include <stdio.h>
#include "fctsBooleennes.h"


int prodScal1(int* tab1, int* tab2, unsigned int taille) {
  int scal = 0;
  for (int i = 0; i < taille; i++) {
    scal ^= tab1[i] & tab2[i];
  }
  return scal;
}

void fct_pi(int* f) {
  f[0] = 0x0b;
  f[1] = 0x07;
  f[2] = 0x1e;
  f[3] = 0x1b;
  f[4] = 0x1d;
  f[5] = 0x0f;
  f[6] = 0xff;
  f[7] = 0x17;
}

void table_verite_fct(int *f, unsigned int taille_pi, unsigned int taille_reste) {
  int npi = 1 << taille_pi;
  int nreste = 1 << taille_reste;
  int pi[npi];
  
  fct_pi(pi);
  for (int i = 0; i < nreste; i++) {
    for (int j = 0; j < npi; j++) {
      f[i*npi+j] = prodScal(pi[j], i);
    }
  }
}

int main() {
  int x = 2, y = 3;
  printf("produit scalaire entre %d, %d: %d\n", x, y, prodScal(x,y));

  int taille_pi = 3, taille_y = 5;
  int taille_tab = 1 << taille_pi * 1 << taille_y;
  int f[taille_tab];
  table_verite_fct(f, taille_pi, taille_y);
  print_tab(f, taille_tab);
  printf("degre : %d\n", degre(f, taille_pi + taille_y));

  return 0;
}

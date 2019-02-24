#include "fct_pi_scal.h"
#include "fctsBooleennes.h"

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

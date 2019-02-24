#include "fctsBooleennes.h"
#include <errno.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

void print_tab(int* f, int taille) {
  printf("--------------------------TABLEAU--------------------------\n");
  for (int i = 0; i < taille; i++) {
    printf("%d ", f[i]);
  }
  printf("\n-----------------------------------------------------------\n");
}

int init_table_param(int *table, int nb, char* t[]) {
  int bool2 = nb;
  int n = log2(bool2);
  
  if (bool2 != 1 << n) {
    errno = EINVAL;
    perror("Pas le bon nombre d'arguments");
    return -1;
  }

  for (int i = 0; i < nb; i++) {
    if (strcmp("1", t[i]) == 0) {
      table[i] = 1;
    } else if (strcmp("0", t[i]) == 0) {
      table[i] = 0;
    } else {
      errno = EINVAL;
      perror("Argument différent de 0 et de 1");
      return -1;
    }
  }

  return n;
}

void anf(int* f, int n) {
  unsigned int n2 = 1 << n; //2^n

  //surfct taille de la surfonction
  //a chaque fois on le divise par 2
  //nbsstab nb de sous tableaux
  //a chaque fois on le multiplie par 2
  for (int surfct = n2 >> 1, nbsstab = 2; surfct > 0; surfct >>= 1, nbsstab <<= 1) {
    //pour chaque duo de sous tableaux
    for (int i = 0; i < n2; i += surfct << 1) {
      //pour chaque element
      for (int j = 0; j < surfct; j++) {
	f[i+surfct+j] ^= f[i+j];
      }
    }
  }
}

int poids(unsigned x) {
  int p = 0;
  do {
    p += (x & 1);//1 = 000000....01, & renvoie 0 ou 1
  } while((x >>= 1) != 0);
  return p;
}

int degre(int *f, int n) {
  anf(f, n);
  int deg = 0;
  int nn = 1 << n; //2^n
  for (int i = 0; i < nn; i++) {
    if (f[i] == 1) {
      int p = poids(i);
      deg = p > deg ? p : deg;
    }
  }

  return deg;
}

int parite(unsigned x) {
  return poids(x)%2;
}

int prodScal(unsigned x, unsigned y) {
  return parite(x&y);
}

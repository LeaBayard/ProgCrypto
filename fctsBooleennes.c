#include "fctsBooleennes.h"
#include <errno.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void print_tab(int* f, int taille) {
  printf("--------------------------TABLEAU--------------------------\n");
  for (int i = 0; i < taille; i++) {
    printf("%d ", f[i]);
  }
  printf("\n-----------------------------------------------------------\n");
}

void recopie(int *dest, int *src, int taille) {
  for (int i = 0; i < taille; i++) {
    dest[i] = src[i];
  }
}

void add_fcts(int* res, int* f, int* g, int taille) {
  for (int i = 0; i < taille; i++) {
    res[i] = f[i] ^ g[i];
  }
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

void Fourier(int *f, int n) {
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
	int haut = f[i+j];
	int bas = f[i+surfct+j];
	f[i+j] = haut + bas;
	f[i+surfct+j] = haut - bas;
      }
    }
  }
}

void Walsh(int *f, int n) {
  unsigned int n2 = 1 << n;

  //dans le tableau 0 -> 1 et 1 -> -1
  for (int i = 0; i < n2; i++) {
    f[i] = f[i] == 0 ? 1 : -1;
  }

  Fourier(f, n);
}

int resilience(int *f, int n) {
  unsigned int n2 = 1 << n;
  
  Walsh(f, n);

  int res1 = n;

  for (unsigned int i = 0; i < n2; i++) {
    if (f[i] != 0) {
      int p = poids(i);
      res1 = p < res1 ? p : res1;
    }
  }

  return res1 - 1;
}

int distFourier(int* f, int* g, int n) { 
  int taille = 1 << n;
  int tab[taille];

  add_fcts(tab, f, g, taille);

  Fourier(tab, n);

  return tab[0];
}

int distWalsh(int *f, int* g, int n) {
  int taille = 1 << n;
  int tab[taille];

  add_fcts(tab, f, g, taille);

  Walsh(tab, n);

  return (1 << (n-1)) - 0.5 * tab[0];
}

unsigned NL(int* f, int n) {
  int taille = 1 << n;
  int max = 0;

  int tab[taille];
  recopie(tab, f, taille);

  Walsh(tab, n);

  for (int i = 0; i < taille; i++) {
    unsigned int abs_fi = abs(tab[i]);
    max =  abs_fi > max ? abs_fi : max;
  }
  
  return (1 << (n-1)) - 0.5 * max;
}

int isCourbe(int* f, int n) {
  int taille = 1 << n;
  int tab[taille];
  recopie(tab, f, taille);

  Walsh(tab, n);

  int res = 1;

  for (int i = 0; i < taille; i++) {
    if (abs(tab[i]) != pow(2, 0.5 * n)) {
      res = 0;
      break;
    }
  }
  
  return n%2 == 0 && res;
}

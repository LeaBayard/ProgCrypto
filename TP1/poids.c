#include <stdio.h>
#include <errno.h>
#include "fctsBooleennes.h"

void cmds(unsigned x) {
  printf("Valeur de x : %u\n", x);
  x = (x&0x55555555)+((x>>1)&0x55555555);
  printf("x=(x&0x55555555)+((x>>1)&0x55555555)  : %u\n", x);
  x = (x&0x33333333)+((x>>2)&0x33333333);
  printf("x=(x&0x33333333)+((x>>2)&0x33333333)  : %u\n", x);
  x = (x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f);
  printf("x=(x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f)  : %u\n", x);
  x = (x&0x00ff00ff)+((x>>8)&0x00ff00ff);
  printf("x=(x&0x00ff00ff)+((x>>8)&0x00ff00ff)  : %u\n", x);
}

void print_poids(unsigned x) {
  printf("Poids de %u : %d\n", x, poids(x));
}

int main(int argc, char* argv[]) {

  errno = 0;
  
  cmds(64);
  for (int i = 0; i < 10; i++) {
    print_poids(i);
  }

  int table[argc-1];
  int n = init_table_param(table, argc-1, argv+1);

  if (errno) {
    return errno;
  }

  printf("degré de la fonction dont la table de vérité a été entrée"
	 " en paramètre: %d\n", degre(table, n));
  
  return 0;
}

#include "../fctsBooleennes.h"
#include "../fct_pi_scal.h"
#include <stdio.h>
#include <errno.h>


int main(int argc, char *argv[]) {
  
  errno = 0;
  int bool2 = argc-1;
  int table[bool2];

  int n = init_table_param(table, argc-1, argv+1);

  if (errno) {
    return errno;
  }

  printf("Table de vérité\n");
  print_tab(table, bool2);

  printf("resilience de la fonction : %d\n", resilience(table, n));

  int taille_pi = 3, taille_y = 5;
  int taille_tab = 1 << taille_pi * 1 << taille_y;
  int f[taille_tab];
  table_verite_fct(f, taille_pi, taille_y);
  
  print_tab(f, taille_tab);
  printf("resilience : %d\n", resilience(f, taille_pi + taille_y));

  
  return errno;
}

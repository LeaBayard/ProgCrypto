#include <errno.h>
#include <stdio.h>
#include <math.h>
#include "../fctsBooleennes.h"

int main(int argc, char* argv[]) {

  errno = 0;
  int bool2 = argc-1;
  int table[bool2];
  int table2[bool2];

  int n = init_table_param(table, argc-1, argv+1);
  
  if (errno) {
    return errno;
  }

  printf("Table de vérité\n");
  print_tab(table, bool2);
  
  Walsh(table, n);

  printf("Walsh\n");
  print_tab(table, bool2);

  for (int i = 0; i < bool2; i++) {
    table2[i] = table[i];
  }

  Fourier(table2, n);

  for (int i = 0; i < bool2; i++) {
    table2[i] = pow(2, n) * (i == 0 ? 1 : 0) - 2 * table2[i];
  }

  printf("2^n dirac - 2 fourier\n");
  print_tab(table, bool2);
  
  return errno;
}

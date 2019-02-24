#include "fctsBooleennes.h"
#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[]) {

  errno = 0;
  int bool2 = argc-1;
  int table[bool2];

  int n = init_table_param(table, argc-1, argv+1);

  if (errno) {
    return errno;
  }

  printf("Table de vérité\n");
  print_tab(table, bool2);

  anf(table, n);

  printf("ANF\n");
  print_tab(table, bool2);
  
  return errno;
}

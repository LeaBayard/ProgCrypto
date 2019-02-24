#include "../fctsBooleennes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
  errno = 0;

  int pos_v = 0;
  int taille = (argc-2)/2;
  int f[taille];
  int g[taille];
  
  for (int i = 0; i < argc; i++) {
    if (i > argc/2) {
      break;
    }
    if (!strcmp(argv[i], ",")) {
      pos_v = i;
      break;
    }
  }

  if (pos_v != argc/2) {
    errno = EINVAL;
    perror("Il faut deux fonctions de tailles égales");
    return errno;
  }

  int n = init_table_param(f, taille, argv+1);

  if (errno) {
    return errno;
  }
  
  if (init_table_param(g, taille, argv+1+taille+1) < 0) {
    return errno;
  }

  printf("f :\n");
  print_tab(f, taille);
  printf("g :\n");
  print_tab(g, taille);
  printf("distance de f et g : %d\n", distFourier(f, g, n));
  printf("distance de f et g : %d\n", distWalsh(f, g, n));

  int grosseNL [512] = {
		1,0,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,0,1,0,0,1,
		0,1,0,1,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,0,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,0,1,0,1,0,1,0,0,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,
		0,1,1,1,0,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,1,1,
		1,1,1,1,0,1,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,0,
		0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,1,1,1,1,1,1,1,0,0,1,1,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,
		1,1,1,0,1,0,1,0,1,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,1,1,0,1,0,1,1,1,1,0,
		1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,0,1,1,1,1,0,
		1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,1,0,1,1,0,1,0,0,1,0,1,1,1,0,0,0,1,0,1,1,0,0,1,1,1,0,1,1,0,1,1,1,0,1,0,0,1
	};

  printf("grosseNL :\n");
  print_tab(grosseNL, 512);
  printf("Non linearite de grosseNL : %d\n", NL(grosseNL, 9));

  int t_courbe = (1 << 8);

  int courbe[t_courbe];

  for (int i = 0; i < t_courbe; i++) {
    int x = i & ((1 << 4) - 1);
    int y = i >> 4;
    courbe[i] = prodScal(x,y);
  }

  printf("courbe :\n");
  print_tab(courbe, t_courbe);

  printf("courbe est-elle une fonction courbe ? %s\n",
	 isCourbe(courbe, 8) ? "true" : "false");

  return errno;
}

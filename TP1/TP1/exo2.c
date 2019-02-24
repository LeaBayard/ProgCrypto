#include <stdlib.h>
#include <stdio.h>


void anf (int *f, int n) {
	unsigned int nn; //taille du tableau 2^n
	unsigned int jj; //taille de la surfonction
	int i;
	nn = 1 << n; //2^n
	jj = nn >> 1; //premiere surfonction de taille 2^(n-1)

	do {
		i = 0;
		do {
			f[i+jj] ^= f[i];
			i++;
			if ((i & (jj-1)) == 0)
				i+=jj;
		} while (i<nn);

		jj = jj >> 1;
	} while (jj != 0);
}

int poids (unsigned int x) {
	int res = 0;
	for (int i = 0; i<16; i++) {
		res += x&1;
		x >>= 1;
	}
	return res;
}

int degre (int *f, int n) {
	unsigned int nn;
	nn = 1 << n;
	anf(f, n);

	unsigned int poid = 0;

	for (int i = nn-1; i>=0; i--) {
		if (f[i] != 0 && poids(i) > poid) 
			poid = poids(i);
	}
	return poid;
}

int main () {


	int f[8] = {0,1,1,0,0,1,0,1};
	int n = 3;
	anf(f, n);

	unsigned int x = 9;

	// unsigned int j = 0x55555555;

	// x = (x&j) + ((x>>1)&j);

	// printf("x = %d\n", x);
	for (x = 0; x<8; x++) {
		printf("x, poids(x) = %d, %d\n",x, poids(x));
	}
	printf("deg(f) = %d\n", degre(f, 3));
	return 0;
}
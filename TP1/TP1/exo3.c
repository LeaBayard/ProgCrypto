#include <stdlib.h>
#include <stdio.h>

const int m = 32;

int poids (unsigned int x) {
	int res = 0;
	for (int i = 0; i<16; i++) {
		res += x&1;
		x >>= 1;
	}
	return res;
}

int parite (unsigned int x) {
	return poids(x)%2;
}

int prodScal1 (unsigned int *x, unsigned int *y) {
	int res = 0;
	for (int i = 0; i<m; i++) {
		res += x[i] ^ y[i];
	}
	return res;
}

int prodScal2(unsigned int x, unsigned int y) {
	return parite(x&y);
}

int main () {

	/* parite(11) = 1; */
	return 0;
}
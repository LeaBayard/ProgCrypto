#ifndef FCTSBOOLEENNES
#define FCTSBOOLEENNES

//affiche un tableau d'entiers f de taille taille dans la sortie standard
void print_tab(int *f, int taille);

//recopie le tableau d'entiers src dans dest
//src et dest sont de taille taille
void recopie(int *dest, int *src, int taille);

//additionne (xor) f et g et met le resultat dans res
//tous les tableaux sont de taille taille
void add_fcts(int* res, int* f, int* g, int taille);

//remplit table un tableau d'entiers de taille nb
//avec les 0 et les 1 entres en parametres
//si nb n'est pas une puissance de 2 ou
//s'il existe i tq t[i] n'est pas "1" ou "0"
//alors erreur, errno mis a jour et renvoie -1
//sinon remplit table par la table de verite induite par t
//et renvoie log2(nb)
int init_table_param(int *table, int nb, char* t[]);

//f un tableau de 0 et de 1 representant une fonction booleenne
//de domaine F_2^n
//sous forme de sa table de verite
//remplit f par sa forme normale algebrique
void anf(int *f, int n);

//renvoie le poids du mot x
int poids(unsigned x);

//f fct booleenne de domaine F_2^n sous forme de table de verite
//renvoie son degre
int degre(int* f, int n);

//renvoie la parite du poids du mot x
int parite(unsigned x);

//renvoie le produit scalaire entre x et y
int prodScal(unsigned x, unsigned y);

//remplit f table de verite d'une fct de domaine F_2^n
//par sa transformee de Fourier
void Fourier(int *f, int n);

//remplit f table de verite d'une fct de domaine F_2^n
//par sa transformee de Walsh
void Walsh(int *f, int n);

//renvoie la resilience de la fonction
//dont la table de verite est f de domaine F_2^n
//si pas resiliente renvoie -1
int resilience(int *f, int n);

//retourne la distance de Hamming de f et g
//en utilisant la relation qui relie cette distance
//a la transformee de fourier
//f et g de domaine F_2^n
//dist = fourier(f+g)(0)
int distFourier(int* f, int* g, int n);

//retourne la distance de Hamming de f et g
//en utilisant la relation qui relie cette distance
//a la transformee de walsh
//f, g : F_2^n -> F_2
//dist = 2^(n-1) - 0.5 * walsh(f+g)
int distWalsh(int *f, int* g, int n);

//renvoie la non linearite de la fonction
//f : F_2^n -> F_2
unsigned NL(int* f, int n);

//soit f : F_2^n -> F_2
//renvoie different de 0 si f est une fonction courbe
//et 0 sinon
int isCourbe(int* f, int n);

#endif

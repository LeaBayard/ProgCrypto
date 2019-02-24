#ifndef FCTSBOOLEENNES
#define FCTSBOOLEENNES

//affiche un tableau d'entiers f de taille taille dans la sortie standard
void print_tab(int *f, int taille);

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

#endif

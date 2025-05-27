#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
} TABB;

TABB *insere(TABB *a, int elem);
void imprime_pre(TABB *a);
void libera(TABB *a);
int qtd_elems_menores_N(TABB *a, int N);
int *mN(TABB *a, int N);

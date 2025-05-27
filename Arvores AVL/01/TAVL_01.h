#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
    int info;
    int alt;
    struct avl *esq, *dir;
} TAVL;

void imprime_sim(TAVL *a);
void libera(TAVL *a);
TAVL *insere(TAVL *a, int elem);
TAVL *retira(TAVL *a, int elem);

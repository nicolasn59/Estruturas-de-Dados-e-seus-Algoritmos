#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    struct ab *esq, *dir;
    int info;
} TAB;

TAB *cria(int raiz, TAB *left, TAB *right);
void imprime_sim(TAB *a);
void libera(TAB *a);
int busca(TAB *a, int elem);
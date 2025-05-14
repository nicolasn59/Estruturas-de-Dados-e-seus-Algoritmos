#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
} TAB;

TAB *cria(int raiz, TAB *left, TAB *right);
void imprime_pos(TAB *a);
void libera(TAB *a);
int igual(TAB *a1, TAB *a2);

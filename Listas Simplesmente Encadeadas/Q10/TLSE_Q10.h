#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} TLSE;

void libera(TLSE *l);
TLSE *insereFinal(TLSE *l, int elem);
void imprimeLista(TLSE *l);
int Contrario(TLSE *l1, TLSE *l2);

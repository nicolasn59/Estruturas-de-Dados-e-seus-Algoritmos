#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} TLSE;

TLSE * alocaNo();
TLSE * insereFinal(TLSE *l, int elem);
void imprimeLista(TLSE *l);
TLSE * desloca(TLSE *l, int n);

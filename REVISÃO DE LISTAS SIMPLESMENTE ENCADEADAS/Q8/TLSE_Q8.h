#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} TLSE;

TLSE *alocaNo();
TLSE *insereFinal(TLSE *l, int elem);
void imprimeLista(TLSE *l);
int igual(TLSE *l1, TLSE *l2);
int lenght(TLSE *l);
TLSE *apagarLista(TLSE *l);
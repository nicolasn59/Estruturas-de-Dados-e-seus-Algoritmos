#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} TLSE;

TLSE *alocaNo();
TLSE *insereFinal(TLSE *l, int elem);
TLSE *insereInicio(TLSE *l, int elem);
void imprimeLista(TLSE *l);
TLSE *copia(TLSE *l1, TLSE *l2);
int lenght(TLSE *L);
TLSE *ordena(TLSE *l);

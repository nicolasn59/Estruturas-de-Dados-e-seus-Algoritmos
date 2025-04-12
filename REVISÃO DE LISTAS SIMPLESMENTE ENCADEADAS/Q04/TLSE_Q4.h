#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} TLSE;


TLSE * alocaNo();
TLSE *insereInicio(TLSE *l, int elem);
TLSE *insereFinal(TLSE *l, int elem);
void imprimeLista(TLSE * l);
TLSE * copia(TLSE *l);

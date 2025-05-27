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
TLSE *copia_inversa(TLSE *l);
int lenght(TLSE *l);
int igual(TLSE *l1, TLSE *L2);
int Contrario(TLSE *l1, TLSE *l2);

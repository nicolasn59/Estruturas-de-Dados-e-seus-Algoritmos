#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} TLSE;

void libera(TLSE *l);
TLSE *insereFinal(TLSE *l, int elem);
void imprimeLista(TLSE *l);
void i_p(TLSE **l); // Passagem por referência para alterar a lista na main

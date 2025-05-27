#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} TLSE;


TLSE * alocaNo();  // ALOCA UM NOVO NÓ DINAMICAMENTE
TLSE * insereFinal(TLSE *l, int elem);  // INSERE O NÓ ALOCADO AO FINAL DA TLSE
void imprimeLista(TLSE *l); // IMPRIME TODA A TLSE
TLSE * inverte(TLSE *l);  // IMPRIME A TLSE INVERTIDA
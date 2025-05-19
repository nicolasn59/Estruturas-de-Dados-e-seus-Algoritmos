#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int cor, info;
    struct ab *esq, *dir;
} TAB;

TAB *cria(int raiz, TAB *left, TAB *right);
void imprime_sim_info(TAB *a);
void libera(TAB *a);
void colore(TAB *a);
void imprime_sim_cor(TAB *a);

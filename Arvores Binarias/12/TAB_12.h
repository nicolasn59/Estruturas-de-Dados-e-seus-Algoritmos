#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
} TAB;

TAB *cria(int raiz, TAB *left, TAB *right);
void imprime_sim_info(TAB *a);
void libera(TAB *a);
int estritamente_binaria(TAB *a);

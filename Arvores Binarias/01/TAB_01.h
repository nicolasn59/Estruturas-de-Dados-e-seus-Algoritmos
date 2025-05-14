#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
} TAB;

TAB *inicializa_ab();
TAB *cria(int raiz, TAB *sae, TAB *sad);  //sae = sobe a esquerda; sad = sobe a direita
void imprime_pre(TAB *a); // pré ordem: raiz - esquerda - direita
void libera(TAB *a);
TAB *copia(TAB *a1);

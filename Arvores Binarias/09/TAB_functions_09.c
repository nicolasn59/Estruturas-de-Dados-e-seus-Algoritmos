#include "TAB_09.h"

TAB *cria(int raiz, TAB *left, TAB *right){
    TAB *novo = (TAB*) malloc(sizeof(TAB));
    novo->info = raiz;
    novo->esq = left;
    novo->dir = right;
}

void imprime_sim_info(TAB *a){
    if(a){
        imprime_sim_info(a->esq);
        printf("%d ", a->info);
        imprime_sim_info(a->dir);
    }
}

void libera(TAB *a){
    if (a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

int ni(TAB *a){
    if (!a){ // Se o nó é nulo, retorna 0
        return 0;
    }
    int ni_esq = ni(a->esq); // Conta os nós internos da subárvore esquerda
    int ni_dir = ni(a->dir); // Conta os nós internos da subárvore direita
    if ((a->esq) || (a->dir)){ // Verifica se existe pelo menos 1 filho
        return (ni_esq + ni_dir + 1); // Retorna a soma dos nós internos + 1
    }
    return 0;  // Se não for um nó interno
}

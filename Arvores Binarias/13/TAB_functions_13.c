#include "TAB_13.h"

TAB *cria(int raiz, TAB *left, TAB *right){
    TAB *novo = (TAB*) malloc(sizeof(TAB));
    novo->info = raiz;
    novo->esq = left;
    novo->dir = right;
    return novo;
}

void imprime_sim(TAB *a){
    if (a){
        imprime_sim(a->esq);
        printf("%d ", a->info);
        imprime_sim(a->dir);
    }
}

void libera(TAB *a){
    if (a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

int busca(TAB *a, int elem){
    if (!a){
        return 0;
    }
    if (a->info == elem){
        return 1;
    }
    return busca(a->esq, elem) || busca(a->dir, elem);
}

#include "TAB_11.h"

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

int soma(TAB *a){
    if (!a){
        return 0;
    }

    int soma_esq = soma(a->esq);
    int soma_dir = soma(a->dir);
    return (soma_esq + soma_dir + a->info);
}

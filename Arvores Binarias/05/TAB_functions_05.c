#include "TAB_05.h"

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

int altura(TAB *a){
    if (!a){ // Verificando a existência do nó
        return 0;
    }
    int altura_esq = altura(a->esq);
    int altura_dir = altura(a->dir);

    if (altura_esq > altura_dir){
        return 1 + altura_esq;
    }
    else{
        return 1 + altura_dir;
    }
}

#include "TAB_02.h"

TAB *cria(int raiz, TAB* left, TAB* right){  
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

TAB *espelho(TAB *a){
    if (!a){
        return NULL;  // Se encontrar um nó nulo
    }
    TAB *novaAb = (TAB*) malloc(sizeof(TAB));  // Aloca um novo nó
    novaAb->info = a->info;  // novaAb recebe o dado do nó da árvore original
    novaAb->esq = espelho(a->dir); // Arvóre espelho no lado esquerdo recebe as informações da árvore original no lado direito
    novaAb->dir = espelho(a->esq); // Arvóre espelho no lado direito recebe as informações da árvore original no lado esquerdo
    return novaAb;  
}

void libera(TAB *a){
    if (a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

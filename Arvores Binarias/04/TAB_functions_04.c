#include "TAB_04.h"

TAB *cria(int raiz, TAB *left, TAB *right){
    TAB *novo = (TAB*) malloc(sizeof(TAB));
    novo->info = raiz;
    novo->esq = left;
    novo->dir = right;
    return novo;
}

void imprime_pre(TAB *a){
    if (a){
        printf("%d ", a->info);
        imprime_pre(a->esq);
        imprime_pre(a->dir);
    }
}

void libera(TAB *a){
    if (a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

TAB *menor(TAB *a){
    if (!a){
        return NULL;
    }
    TAB *no_esq = menor(a->esq);  // Percorre a árvore pela esquerda até que um valor seja retornado
    TAB *no_dir = menor(a->dir);
    TAB *menor_no = a;  // Recebe nó atual da árvore

    // no_esq é o próximo nó da esquerda 
    // no_dir é o próximo nó da direita
    // maior_no é o atual nó
    if (no_esq && no_esq->info < menor_no->info){ // Verifica se no_esq existe e depois compara os dois nós
        menor_no = no_esq; // Se no_esq->info for maior que maior_no->info
    }
    if (no_dir && no_dir->info < menor_no->info){
        menor_no = no_dir;
    }
    return menor_no;
}

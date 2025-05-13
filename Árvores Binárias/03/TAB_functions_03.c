#include "TAB_03.h"

TAB *cria(int raiz, TAB *left, TAB *right){
    TAB *novo = (TAB*) malloc(sizeof(TAB));
    novo->info = raiz;
    novo->esq = left;
    novo->dir = right;
    return novo;
}

void imprime_pos(TAB *a){
    if (a){
        imprime_pos(a->esq);
        imprime_pos(a->dir);
        printf("%d ", a->info);
    }
}

void libera(TAB *a){
    if (a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

TAB *maior(TAB *a){
    if (!a){
        return NULL;
    }
    TAB *no_esq = maior(a->esq); // Percorre todos os nós da esquerda até retornar algum valor
    TAB *no_dir = maior(a->dir);
    TAB *maior_no = a; // maior_no recebe o nó atual

    // no_esq é o próximo nó da esquerda 
    // no_dir é o próximo nó da direita
    // maior_no é o atual nó

    if (no_esq && no_esq->info > maior_no->info){  // Verifica se no_esq existe e depois compara os dois nós
        maior_no = no_esq;  // Se no_esq->info for maior que maior_no->info
    }
    if (no_dir && no_dir->info > maior_no->info){  // Verifica se no_dir existe e depois compara os dois nós
        maior_no = no_dir;
    }
    return maior_no;
}

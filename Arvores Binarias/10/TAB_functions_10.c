#include "TAB_10.h"

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

int nf(TAB *a){
    if (!a){  // Se nó não existe
        return 0;
    }
    int nf_esq = nf(a->esq); // Conta os nós folha da subárvore esquerda
    int nf_dir = nf(a->dir); // Conta os nós folha da subárvore direita
    if ((!a->esq) && (!a->dir)){ // Verifica se o nó não tem nenhum filho
        return 1; // Retorna 1, o que aumenta a quantidade de nós folhas na contagem
    }
    return (nf_esq + nf_dir);  // Soma os nós folhas de ambos os lados e retorna a quantidade de nós folhas na árvore
}

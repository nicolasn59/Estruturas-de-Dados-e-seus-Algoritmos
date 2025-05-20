#include "TAB_12.h"

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

int estritamente_binaria(TAB *a){
    if (!a){
        return 1; // Árvore vazia é considerada estritamente binária
    }
    int no_esq = estritamente_binaria(a->esq);
    int no_dir = estritamente_binaria(a->dir);

    // Se o nó tem 0 filhos ou exatamente 2 filhos, é válido
    if (((!a->esq) && (!a->dir)) || ((a->esq) && (a->dir))){
        return (no_esq * no_dir); // Retorna 1 se ambos os lados também forem válidos
    }
    return 0; // Caso tenha apenas 1 filho, já não é estritamente binária
}

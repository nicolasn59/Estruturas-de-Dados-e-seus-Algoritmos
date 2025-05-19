#include "TAB_08.h"

TAB *cria(int raiz, TAB *left, TAB *right){
    TAB *novo = (TAB*) malloc(sizeof(TAB));
    novo->info = raiz;
    novo->cor = -1;
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

// Cor preta = 0
// Cor vermelha = 1
void colore(TAB *a){
    if (a){
        colore(a->esq);
        colore(a->dir);
        if ((a->esq) || (a->dir)){
            if ((a->esq->cor == 0) || (a->dir->cor == 0)){
                a->cor = 1;
                return;
            }
        }
        a->cor = 0;  // se a árvore não existe ou se o filho tiver a cor vermelha (1)
    }
}

void imprime_sim_cor(TAB *a){
    if (a){
        imprime_sim_cor(a->esq);
        if (a->cor == 0){
            printf("Preto %d ", a->cor);
        }
        else {
            printf("Vermelho %d ", a->cor);
        }
        imprime_sim_cor(a->dir);
    }
}

/*
void colore(TAB *a){
    if (a){
        colore(a->esq);
        colore(a->dir);
        if (a->esq){
            if (a->esq->cor == 0){
                a->cor = 1;
            } else {
                a->cor = 0;
            }
        } else if (a->dir) {
            if (a->dir->cor == 0){
                a->cor = 1;
            } else {
                a->cor = 0;
            }
        } else {
            a->cor = 0;
        }
    }
}
*/
#include "TAB_06.h"

TAB *cria(int raiz, TAB *left,  TAB *right){
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

int igual(TAB *a1, TAB *a2){
    // ambos são NULL
    if (!a1 && !a2) return 1;
    // Se apenas um é NULL, são diferentes
    if (!a1 || !a2) return 0;
    // Se ambos existem, compara os valores e depois as subárvores
    if (a1->info == a2->info) {
        return igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir);
    } else {
        return 0;
    }
}


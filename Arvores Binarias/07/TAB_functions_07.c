#include "TAB_07.h"

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

TAB* retira_pares(TAB* a) {
    if (!a) {
        return NULL;
    }
    
    a->esq = retira_pares(a->esq);
    a->dir = retira_pares(a->dir);

    if (a->info % 2 == 0) { // se for par
        TAB *temp;
        if (!a->esq) {
            temp = a->dir;
        } else if (!a->dir) {
            temp = a->esq;
        } else {
            // se tem os dois filhos, precisamos anexar a direita na esquerda
            TAB *aux = a->esq;
            while (aux->dir) {
                aux = aux->dir;
            }
            aux->dir = a->dir;
            temp = a->esq;
        }
        free(a);
        return temp;
    }
    return a;
}

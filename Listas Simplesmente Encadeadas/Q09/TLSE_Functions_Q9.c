#include "TLSE_Q9.h"

static TLSE *alocaNo(){
    TLSE *no = (TLSE*) malloc(sizeof(TLSE));
    no->prox = NULL;
    return no;
}

void libera(TLSE *l) {
    TLSE *tmp;
    while (l) {
        tmp = l;
        l = l->prox;
        free(tmp);
    }
}

TLSE * insereFinal(TLSE *l, int elem){
    TLSE *novoNo = alocaNo();
    novoNo->info = elem;
    if (l){
        TLSE *aux = l;
        while (aux != NULL){
            if (aux->prox == NULL){
                aux->prox = novoNo;
                return l;
            }
            aux = aux->prox;
        }
    }
    l = novoNo;
    return l;
}

void imprimeLista(TLSE *l){
    if (l){
        TLSE *aux = l;
        while (aux != NULL){
            printf("| %d |\t", aux->info);
            aux = aux->prox;
        }
        printf("\n");
        return;
    }
    printf("Lista Vazia!\n");
}

TLSE *junta_listas(TLSE *l1, TLSE *l2){
    if (l1){
        TLSE *aux = l1;
        while (aux != NULL){
            if (aux->prox == NULL){
                aux->prox = l2;
                return l1;
            }
            aux = aux->prox;
        }
    }
    // Retorna l2 caso l1 não exista (esteja vazia)
    return l2;
}

#include "TLSE_Q5.h"

static TLSE * alocaNo(){
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

TLSE *insereInicio(TLSE *l, int elem){
    TLSE *novoNo = alocaNo();
    novoNo->info = elem;
    if (l){
        TLSE *aux = l;
        l = novoNo;
        l->prox = aux;
        return l;
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
    printf("LISTA VAZIA!\n");
}


TLSE *rto(TLSE *l, int elem) {
    TLSE *atual = l;
    TLSE *anterior = NULL;
    TLSE *temp;

    while (atual != NULL) {
        if (atual->info == elem) {
            temp = atual;
            
            if (anterior == NULL) {
                // Remoção do primeiro nó
                l = atual->prox;
            } else {
                // Remoção de um nó no meio/fim
                anterior->prox = atual->prox;
            }
            
            atual = atual->prox;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return l;
}

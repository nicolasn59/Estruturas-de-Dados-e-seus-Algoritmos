#include "TLSE_Q7.h"

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


void i_p(TLSE **l){ // Passagem por referência para alterar a lista na main
    TLSE *atual = *l, *anterior = NULL, *aux;
    if (*l){
        while (atual != NULL){
            if ((atual->info % 2 != 0) && (anterior != NULL)){
                anterior->prox = atual->prox;
                aux = *l;
                *l = atual;
                (*l)->prox = aux;
                atual = anterior;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
    
}

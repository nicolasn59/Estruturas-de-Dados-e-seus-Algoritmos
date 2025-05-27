#include "TLSE_Q4.h"

static TLSE * alocaNo(){
    TLSE *no = (TLSE *) malloc(sizeof(TLSE));
    no->prox = NULL;
    return no;
}

TLSE * insereInicio(TLSE *l, int elem){
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

static TLSE *insereFinal(TLSE *l, int elem){
    TLSE * novoNo = alocaNo();
    novoNo->info = elem;
    if(l){
        TLSE *aux = l;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoNo;
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
    }
}

TLSE *copia(TLSE *l){
    if (l){
        TLSE *copiaDaLista = NULL, *aux = l;
        while (aux != NULL){
            copiaDaLista = insereFinal(copiaDaLista, aux->info);
            aux = aux->prox;
        }
        return copiaDaLista;
    }
    return l;
}
